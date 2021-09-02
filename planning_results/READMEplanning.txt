the planning_results folder contains pictures and .mat files for the trajectories computed with sPRM and RRT that are actually used by the c++ generated nodes, the stored variables are called:
- 'desired_traj' for the sPRM trajectory
- 'desired_traj_RRT' for the RRT trajectory
The contents of the variables can be loaded in matlab from the files with command:
- load('trajectories_def', 'desired_traj','desired_traj_RRT') to load them both
- load('traj_sPRM_def', 'desired_traj') to load only sPRM
- load('traj_RRT_def', 'desired_traj_RRT') to load only RRT

parameters values of the above plans:
sPRM:
	- occupied location: 1
	- numnodes: 3000
	- connectionDistance: 15

RRT:
	- MinTurningRadius: 2.5
	- ValidationDistance: 1.0
	- MaxConnectionDistance: 50
	- MaxIterarions: 850000
	- MaxNumTreeNodes: 800000
	- GoalBias: 0.25 
	- number of states for interpolation: 150


For completeness, some of other obtained results are stored in the 'experiments' folder, with a small description for each of them.

