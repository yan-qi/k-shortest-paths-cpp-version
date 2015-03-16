///////////////////////////////////////////////////////////////////////////////
///  BaseGraph.cpp
///  <TODO: insert file description here>
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 6/6/2010
///
///  $Id$
///
///////////////////////////////////////////////////////////////////////////////

#include <limits>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "GraphElements.h"
#include "BaseGraph.h"

using namespace std;

const double BaseGraph::DISCONNECT = (numeric_limits<double>::max)();

void BaseGraph::clear()
{
	m_nEdgeNum = 0;
	m_nVertexNum = 0;

	for(map<BaseVertex*, set<BaseVertex*>*>::const_iterator pos=m_mpFaninVertices.begin();
		pos!=m_mpFaninVertices.end(); ++pos)
	{
		delete pos->second;
	}
	m_mpFaninVertices.clear();

	for(map<BaseVertex*, set<BaseVertex*>*>::const_iterator pos=m_mpFanoutVertices.begin();
		pos!=m_mpFanoutVertices.end(); ++pos)
	{
		delete pos->second;
	}
	m_mpFanoutVertices.clear();


	m_mpEdgeCodeWeight.clear();

	/*m_stVertices.clear();*/
	/*m_mpVertexIndex.clear();*/

	//clear the list of vertices objects
	for_each(m_vtVertices.begin(), m_vtVertices.end(), DeleteFunc<BaseVertex>());
	m_vtVertices.clear();
}
