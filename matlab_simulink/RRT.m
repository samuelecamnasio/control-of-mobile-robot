%% planning RRT

%% Load the map and create an occupancy grid
% Load the image
image = imread('./maze/maze.png');
image = rgb2gray(image);
% Transform the image to a binary map
imageNorm = double(image)/255;
imageOccupancy = 1 - imageNorm;

% Create the occupancy map object
occGrid = occupancyMap(imageOccupancy,1/0.5);

% Set the parameters according to the yaml file
occGrid.LocalOriginInWorld = [0,0];
occGrid.OccupiedThreshold = 0.2;
occGrid.FreeThreshold = 0.002;

% Show the map
show(occGrid)

%% Planning with a Dubins car
% Set the start and goal poses
start = [87.75, 181.25, -pi/2];
goal = [96.75, 5.25, -pi/2];

% Show the start and goal positions of the robot
hold on
plot(start(1), start(2), 'ro')
plot(goal(1), goal(2), 'mo')

% Show the start and goal headings
r = 0.5;
plot([start(1), start(1) + r*cos(start(3))], [start(2), start(2) + r*sin(start(3))], 'r-' )
plot([goal(1), goal(1) + r*cos(goal(3))], [goal(2), goal(2) + r*sin(goal(3))], 'm-' )
hold off

% Define state space
bounds = [occGrid.XWorldLimits; occGrid.YWorldLimits; [-pi pi]];

ss = stateSpaceDubins(bounds);
ss.MinTurningRadius = 2.5;     

% Create a state validator
stateValidator = validatorOccupancyMap(ss); 
stateValidator.Map = occGrid;
stateValidator.ValidationDistance = 1.0;   
% Create an RRT planner
planner = plannerRRT(ss, stateValidator);
planner.MaxConnectionDistance = 50;    
planner.MaxIterations = 850000;
planner.MaxNumTreeNodes = 800000;  

planner.GoalReachedFcn = @exampleHelperCheckIfGoal;
planner.GoalBias = 0.25;    %%default 0.05  
% Plan the path
rng(0,'twister')
[pthObj, solnInfo] = plan(planner, start, goal);

% Plot the path
show(occGrid)
hold on

% Search tree
plot(solnInfo.TreeData(:,1), solnInfo.TreeData(:,2), '.-');

% Interpolate and plot path
interpolate(pthObj,150)       
plot(pthObj.States(:,1), pthObj.States(:,2), 'r-', 'LineWidth', 2)

% Show the start and goal in the grid map
plot(start(1), start(2), 'ro')
plot(goal(1), goal(2), 'mo')
hold off

%% Generate a trajectory with constant linear and angular velocity with respect to the odom frame
v = 1.0;
w = 0.1;

desired_traj_RRT = zeros(size(pthObj.States,1),4);
desired_traj_RRT(1,1:2) = pthObj.States(1,1:2)';
desired_traj_RRT(1,3) = pthObj.States(1,3);
for k=2:size(desired_traj_RRT,1)
    desired_traj_RRT(k,1:2) = pthObj.States(k,1:2)';
    desired_traj_RRT(k,3) = pthObj.States(k,3);
    desired_traj_RRT(k,4) = desired_traj_RRT(k-1,4)+...
        sqrt((desired_traj_RRT(k,1)-desired_traj_RRT(k-1,1))^2+...
        (desired_traj_RRT(k,2)-desired_traj_RRT(k-1,2))^2)/v+...
        abs(desired_traj_RRT(k,3)-desired_traj_RRT(k-1,3))/w;
end

%% Function definition
function isReached = exampleHelperCheckIfGoal(planner, goalState, newState)
    isReached = false;
    threshold = 1;
    if planner.StateSpace.distance(newState, goalState) < threshold
        isReached = true;
    end
end