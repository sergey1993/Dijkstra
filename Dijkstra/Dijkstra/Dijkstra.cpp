// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	
	vector<unsigned> first_out	= load_vector<unsigend>("first_out");
	vector<unsigned> head		= load_vector<unsigend>("head");
	vector<unsigned> weight		= load_vector<unsigend>("weight");	
	
	int size_of_graph = first_out.size() - 1;
	
	vector<int> run(size_of_graph, -1);
	vector<unsigned> priority_que (size_of_graph);
	vector<unsigned> distance(size_of_graph);
	
	unsigned source_node = 100;
	unsigned target_node = 400;
	myDijkstra(first_out, head, weight, source_node, target_node, run, distance, i, priority_que);

    return 0;
}
