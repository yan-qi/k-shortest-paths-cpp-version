///////////////////////////////////////////////////////////////////////////////
///  VariableGraph.cpp
///  <TODO: insert file description here>
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 6/13/2010
///
///  $Id$
///
///////////////////////////////////////////////////////////////////////////////

#include <set>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include "GraphElements.h"
#include "BasePath.h"
#include "BaseGraph.h"
#include "Graph.h"
#include "DynamicGraph.h"

using namespace std;

// DynamicGraph::DynamicGraph(void)
// {
// }

// DynamicGraph::~DynamicGraph(void)
// {
// }

double DynamicGraph::get_edge_weight(const BaseVertex* source, const BaseVertex* sink )
{
	int source_id = source->getID();
	int sink_id = sink->getID();

	if (m_stRemovedVertexIds.find(source_id) != m_stRemovedVertexIds.end()
	|| m_stRemovedVertexIds.find(sink_id) != m_stRemovedVertexIds.end()
	|| m_stRemovedEdge.find(make_pair(source_id, sink_id)) != m_stRemovedEdge.end())
	{
		return BaseGraph::DISCONNECT;
	}
	
	return Graph::get_edge_weight(source, sink);
}

void DynamicGraph::get_adjacent_vertices(BaseVertex* vertex, set<BaseVertex*>& vertex_set )
{
	int starting_vt_id = vertex->getID();

	if (m_stRemovedVertexIds.find(starting_vt_id) == m_stRemovedVertexIds.end())
	{
		set<BaseVertex*>* vertex_pt_set = get_adjacent_vertex_set(vertex);
		for(set<BaseVertex*>::const_iterator pos=(*vertex_pt_set).begin();
			pos != (*vertex_pt_set).end(); ++pos)
		{
			int ending_vt_id = (*pos)->getID();
			if (m_stRemovedVertexIds.find(ending_vt_id) != m_stRemovedVertexIds.end()
			|| m_stRemovedEdge.find(make_pair(starting_vt_id, ending_vt_id)) != m_stRemovedEdge.end())
			{
				continue;
			}
			//
			vertex_set.insert(*pos);
		}
	}
}

void DynamicGraph::get_precedent_vertices( BaseVertex* vertex, set<BaseVertex*>& vertex_set )
{
	if (m_stRemovedVertexIds.find(vertex->getID()) == m_stRemovedVertexIds.end())
	{
		int ending_vt_id = vertex->getID();
		set<BaseVertex*>* pre_vertex_set = Graph::get_precedent_vertex_set(vertex);
		for(set<BaseVertex*>::const_iterator pos=(*pre_vertex_set).begin(); 
			pos != (*pre_vertex_set).end(); ++pos)
		{
			int starting_vt_id = (*pos)->getID();
			if (m_stRemovedVertexIds.find(starting_vt_id) != m_stRemovedVertexIds.end()
				|| m_stRemovedEdge.find(make_pair(starting_vt_id, ending_vt_id)) != m_stRemovedEdge.end())
			{
				continue;
			}
			//
			vertex_set.insert(*pos);
		}
	}
}

void DynamicGraph::get_vertex_list( vector<BaseVertex*>& vertex_list )
{
	for (vector<BaseVertex*>::const_iterator pos = m_vtVertices.begin();
		pos != m_vtVertices.end(); ++pos)
	{
		if(m_stRemovedVertexIds.find((*pos)->getID()) != m_stRemovedVertexIds.end())
		{
			continue;
		}
		//
		vertex_list.push_back(*pos);
	}
}
