///////////////////////////////////////////////////////////////////////////////
///  TGraph.cpp
///  <TODO: insert file description here>
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 5/29/2010
/// 
///  $Id$
///////////////////////////////////////////////////////////////////////////////


#include <limits>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "GraphElements.h"
#include "TGraph.h"

using namespace std;

// template<typename T>
// void TGraph<T>::clear()
// {
// 	m_nEdgeNum = 0;
// 	m_nVertexNum = 0;
// 	m_mpFanoutVertices.clear();
// 	m_mpFaninVertices.clear();
// 	m_mpEdgeWeight.clear();
// 	m_stVertices.clear();
// 
// 	//clear the list
// 	for_each(m_vtVertices.begin(), m_vtVertices.end(), DeleteFunc<GIntVertex>());
// 	m_vtVertices.clear();
// }