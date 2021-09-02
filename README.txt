test components:
1 launch file to start the map_server and publish the map of the maze

launch with:
 roslaunch project launch_map_server.launch

4 launch files to test the simulation and visualize the results in rviz with:
	- kinematic model + sPRM (kin_planCont_test_sPRM)
	- kinematic model + RRT (kin_planCont_test_rrt)
	- dynamic model +sPRM (dyn_planCont_test_sPRM)
	- dynamyc model + RRT (dyn_planCont_test_rrt)
launch with:
 roslaunch project desired_file_name.launch

the launch files are in the package 'project', where there is also the robot.rviz file with the rviz configuration to visualize the simulation.

nodes name:
	kinematic simulator: bicycle_kin_sim
	dynamic simulator: bicycle_dyn_sim
	controller: bicycle_kin_planCont
	sPRM trajectory publisher: planPublisher_test
	RRT trajectory publisher: planPublisher_test_RRT

matlab scripts for trajectory generation:
	sPRM: sPRM.m
	RRT: RRT.m
