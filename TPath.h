///////////////////////////////////////////////////////////////////////////////
///  TPath.h
///  <TODO: insert file description here>
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 5/30/2010
/// 
///  $Id$ 
///
///////////////////////////////////////////////////////////////////////////////

#pragma once

template<typename T>
class TPath
{
	int m_nLength; 
	double m_dWeight;
	std::vector<GVertex<T>*> m_vtVertexList;
	
public:
	TPath(const std::vector<GVertex<T>*> vertex_list, double weight):m_dWeight(weight)
	{
		m_vtVertexList.assign(vertex_list.begin(), vertex_list.end());
		m_nLength = m_vtVertexList.size();
	};
	~TPath(void){}

	double Weight() const { return m_dWeight; }
	void Weight(double val) { m_dWeight = val; }

	// display the content
	void PrintOut(std::ostream& out_stream) const
	{
		out_stream << "Cost: " << m_dWeight << " Length: " << m_vtVertexList.size() << std::endl;
		//std::copy(m_vtVertexList.begin(), m_vtVertexList.end(), std::ostream_iterator<int>(out_stream, " "));
		for(std::vector<GVertex<T>*>::const_iterator pos=m_vtVertexList.begin(); pos!=m_vtVertexList.end();++pos)
		{
			out_stream << (*pos)->getNode() << " ";
		}
		out_stream << std::endl <<  "*********************************************" << std::endl;	
	}
};