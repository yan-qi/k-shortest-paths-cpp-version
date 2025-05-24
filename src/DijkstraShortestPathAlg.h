///////////////////////////////////////////////////////////////////////////////
///  DijkstraShortestPathAlg.h
///  The implementation of Dijkstra algorithm to get the shortest path of 
///  a pair of vertices in a graph. 
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 5/30/2010
/// 
///  $Id: DijkstraShortestPathAlg.h 65 2010-09-08 06:48:36Z yan.qi.asu $
///
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <queue>  // For std::priority_queue
#include <vector> // For std::vector (underlying container for std::priority_queue)
#include "GraphElements.h" // Should be after standard includes
#include "Graph.h"         // Should be after standard includes

using namespace std;

class DijkstraShortestPathAlg
{
private: // members

	Graph* m_pDirectGraph;

	std::map<BaseVertex*, double> m_mpStartDistanceIndex; 
	std::map<BaseVertex*, BaseVertex*> m_mpPredecessorVertex; 

	std::set<int> m_stDeterminedVertices;
	
	// Changed from std::multiset to std::priority_queue
	std::priority_queue<BaseVertex*, std::vector<BaseVertex*>, WeightLess<BaseVertex>> m_quCandidateVertices;
	
public:
	DijkstraShortestPathAlg(Graph* pGraph):m_pDirectGraph(pGraph){}
	~DijkstraShortestPathAlg(void){clear();}

	void clear();

	BasePath* get_shortest_path(BaseVertex* source, BaseVertex* sink);

	void set_predecessor_vertex(BaseVertex* vt1, BaseVertex* vt2)
	{
		m_mpPredecessorVertex[vt1] = vt2;
	}

	double get_start_distance_at(BaseVertex* vertex)
	{
		return m_mpStartDistanceIndex.find(vertex)->second;
	}

	void set_start_distance_at(BaseVertex* vertex, double weight)
	{
		m_mpStartDistanceIndex[vertex] = weight;
	}

	void get_shortest_path_flower(BaseVertex* root)
	{
		determine_shortest_paths(NULL, root, false);
	}

	// The following two methods are prepared for the top-k shortest paths algorithm
	BasePath* update_cost_forward(BaseVertex* vertex);
	void correct_cost_backward(BaseVertex* vertex);

protected:

	void determine_shortest_paths(BaseVertex* source, BaseVertex* sink, bool is_source2sink);

	void improve2vertex(BaseVertex* cur_vertex_pt, bool is_source2sink);

};
