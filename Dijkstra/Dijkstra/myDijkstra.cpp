#include "stdafx.h"
#include "myDijkstra.h"

unsigned myDijkstra(vector<unsigned> first_out, vector<unsigned> head, vector<unsigned> weight, unsigned source, unsigned target, vector<int>& run, vector<unsigned>& distance, unsigned& i, MinIDQueue priority_queue)
{
	distance[source] = 0;
	IDKeyPair p; // <node,distance>
	p.id = source;
	p.key = 0;
	priority_queue.clear(); //clears the priority queue
	priority_queue.push(p);
	//run till the priority queue is empty <==> all minimal distance from source node are found
	while (!priority_queue.empty())
	{
		IDKeyPair x = priority_queue.pop(); //extracting the IDKey (node with key) with minimum key (tentative distance)
		int curr_node = x.id;
	
		//break the Dijkstra search if the target is already a settled node
		if (target == x.id)
			break;

		//goes through all neighbour nodes of the current node extracted from the Queue
		for (unsigned out_arc = first_out[curr_node]; out_arc < first_out[curr_node + 1].size(); out_arc++) 
		{
			unsigned int neighNode = head[out_arc];
			if (run[neighNode] != i) //checks if the node with index neighNode are used in this Dijkstra run ( not to to initialize all nodes of the graph with infinity weight eacht time)
			{
				run[neighNode] = i; 
				distance[neighNode] = inf_weight;
				distance[neighNode] = distance[curr_node] + weight[out_arc];
				IDKeyPair curr_q;
				curr_q.id = neighNode;
				curr_q.key = distance[neighNode];
				priority_queue.push(curr_q);
			}
			else
			{
				if (distance[curr_node] + weight[out_arc] < distance[neighNode]) //checks if new distance from source to neighNode is shorter then the current
				{
					distance[neighNode] = distance[curr_node] + weight[out_arc]; //sets with new shorter distance
					IDKeyPair curr_q;
					curr_q.id = neighNode;
					curr_q.key = distance[neighNode];
					priority_queue.decrease_key(curr_q); //updates the key value in the priority queue
				}
			}
		}
	}
	i++;
	return distance[target];
}
