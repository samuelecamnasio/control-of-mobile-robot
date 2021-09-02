%% planning sPRM 

%% Load the map and create an occupancy grid
% Load the image
image = imread('./maze/maze.png');
image = rgb2gray(image);
% Transform the image to a binary map
imageNorm = double(image)/255;
imageOccupancy = 1 - imageNorm;

% Create the occupancy map object
occGrid = binaryOccupancyMap(imageOccupancy,1/0.5);    

% Set the parameters according to the yaml file
occGrid.LocalOriginInWorld = [0,0];

% Show the map
map = copy(occGrid);
inflate(map,1);

prmSimple = mobileRobotPRM(map,3000);   
show(prmSimple)


startLocation = [87.75 181.25];
endLocation = [95.3059 3.93688];

prmSimple.ConnectionDistance = 15; 
path = findpath(prmSimple,startLocation,endLocation);
show(prmSimple)

%% Generate a trajectory with constant linear and angular velocity with respect to the odom frame
v = 1.0;
w = 0.1;

desired_traj = zeros(size(path,1),4);
desired_traj(1,1:2) = path(1,1:2)';
desired_traj(1,3) = -pi/2;
for k=2:size(desired_traj,1)
    desired_traj(k,1:2) = path(k,1:2)';
    x0=desired_traj(k-1,1);
    y0=desired_traj(k-1,2);
    x1=desired_traj(k,1);
    y1=desired_traj(k,2);
    dist=sqrt((x1-x0)^2+(y1-y0)^2);
    if x1>=x0 && y1>=y0
        desired_traj(k,3) =acos(abs(x1-x0)/dist);
    elseif x1>=x0 && y1<y0
        desired_traj(k,3) =-acos(abs(x1-x0)/dist);
    elseif x1<x0 && y1>=y0
        desired_traj(k,3) =pi-acos(abs(x1-x0)/dist);
    else %x1<x0 && y1<y0
        desired_traj(k,3) =pi+acos(abs(x1-x0)/dist);
    end
    desired_traj(k,4) = desired_traj(k-1,4)+...
        sqrt((desired_traj(k,1)-desired_traj(k-1,1))^2+...
        (desired_traj(k,2)-desired_traj(k-1,2))^2)/v+...
        abs(desired_traj(k,3)-desired_traj(k-1,3))/w;
end

