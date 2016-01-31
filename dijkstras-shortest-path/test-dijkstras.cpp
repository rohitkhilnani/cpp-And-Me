/*
	This program tests Dijkstras algorithm 
*/

#include<iostream>
#include "dijkstras.h"
#include<limits>	
#include<vector>


void test_dijkstrasA(){

	std::cout<<"Test A\n\n";

	int n = 9;    // number of vertices
	int m = 12;	  // number of edges
	int s = 1;     // source vertex name

	std::vector< std::vector<int> > edges = {
												{1,4,4},
												{1,2,10},
												{2,7,8},
												{3,7,2},
												{4,6,9},
												{4,2,2},
												{4,3,3},
												{5,3,3},
												{6,5,2},
												{7,5,1},
												{8,9,5},
												{9,8,5}
											};

	Dijkstras dj(n, m, edges, s);
	dj.find_paths();
	// path lenths / distances:
	std::cout<<"Distance of each vertex from source: \n";

	for(int i=1;i<=n;i++){
		int d = dj.get_length(i);
		if(d != std::numeric_limits<int>::max())
			std::cout<<i<<": "<<d<<"\n";
		else
			std::cout<<i<<": "<<"Path does not exist\n";			
	}


	// print all paths
	std::cout<<"Path from source to all vertices: \n";
	for(int i=1;i<=n;i++){

		std::cout<<i<<": ";
		if(dj.get_length(i) != std::numeric_limits<int>::max())
			dj.print_path(i);
		else
			std::cout<<"Path does not exist";	

		std::cout<<"\n";
	}


}


void test_dijkstrasB(){

	std::cout<<"Test B\n\n";

	int n = 9;    // number of vertices
	int m = 12;	  // number of edges
	int s = 1;     // source vertex name

	std::vector< std::vector<int> > edges = {	{1,2,10}, 		
												{2,3,1},
												{3,4,4},
												{4,3,6},
												{5,4,2},
												{1,5,5},
												{2,5,2},
												{5,2,3},
												{5,3,9},
												{4,1,7},
												{7,6,1},
												{6,7,5}
											};

	

	Dijkstras dj(n, m, edges, s);
	dj.find_paths();
	// path lenths / distances:
	std::cout<<"Distance of each vertex from source: \n";

	for(int i=1;i<=n;i++){
		int d = dj.get_length(i);
		if(d != std::numeric_limits<int>::max())
			std::cout<<i<<": "<<d<<"\n";
		else
			std::cout<<i<<": "<<"Path does not exist\n";			
	}


	// print all paths
	std::cout<<"Path from source to all vertices: \n";
	for(int i=1;i<=n;i++){

		std::cout<<i<<": ";
		if(dj.get_length(i) != std::numeric_limits<int>::max())
			dj.print_path(i);
		else
			std::cout<<"Path does not exist";	

		std::cout<<"\n";
	}
		 	
}



int main(){

	// test dijkstras A
	test_dijkstrasA();

	// test dijkstras B
	test_dijkstrasB();

	return 0;
}
