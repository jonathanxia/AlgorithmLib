#include "adjList.h"
#include <vector>
#include <utility>
#include <tuple>
#include <stdexcept>
namespace AlgLib {
	adjList::adjList(int numVertices) :
	    isInGraph(numVertices, true)
	{
		mlist.reserve(numVertices);
		for (int i = 0; i < numVertices; i++)
        {
			std::vector< std::tuple<int, double> > adj; // contains the list of pairs that hold vertex with weight
			mlist.push_back(adj);
		}
	}

	adjList::~adjList()
	{
	    // no pointers used so far
	}

	void adjList::addVertex()
	{
		std::vector< std::tuple<int, double> > adj;
		mlist.push_back(adj);
	}

	void adjList::addEdge(int nodeS, int nodeE, double weight)
	{
	    if(nodeS >= (int) mlist.size() || nodeE >= (int) mlist.size() || nodeS < 0 || nodeE < 0)
            throw std::out_of_range("Node does not exist");
		mlist[nodeS].push_back(std::make_tuple(nodeE, weight));
	}

	void adjList::deleteEdge(int nodeS, int nodeE)
	{
		for (auto i = mlist[nodeS].begin(); i != mlist[nodeS].end(); i++)
        {
			if (std::get<0>(*i) == nodeE)
			{
				mlist[nodeS].erase(i);
			}
		}
	}

	void adjList::deleteVertex(int node)
	{
	    isInGraph[node] = false;
		// Do not remove the vertex from the list since that will mess up node numbering

		//Now we empty the tuples stored inside mlist[node]
		mlist[node].erase(mlist[node].begin(), mlist[node].end());
		for (auto i = mlist.begin(); i != mlist.end(); i++)
        {
			for (auto j = i->begin(); j != i->end(); j++)
			{
				if (std::get<0>(*j) == node)
				{
					i->erase(j);
				}
			}
		}
	}

	int adjList::numVertex() const
	{
		int numVertices = 0;
		for (auto i = isInGraph.begin(); i != isInGraph.end(); i++)
        {
            if(*i)
            {
                numVertices++;
            }
        }
        return numVertices;
	}

	int adjList::inDegree(int node) const{
		int degree = 0;
		for (auto i = mlist.begin(); i != mlist.end(); i++)
        {
			for (auto j = i->begin(); j != i->end(); j++)
			{
				if (std::get<0>(*j) ==  node && std::get<1>(*j) != 0)
				{
					degree++;
				}
			}
		}
		return degree;
	}

	int adjList::outDegree(int node) const {
		int degree = 0;
		for (auto i = mlist[node].begin(); i != mlist[node].end(); i++) {
			if (std::get<1>(*i) != 0) {
				degree++;
			}
		}
		return degree;
	}

	double adjList::inWeight(int node) const
	{
		double weight = 0;
		for (auto i = mlist.begin(); i != mlist.end(); i++)
        {
			for (auto j = i->begin(); j != i->end(); j++)
			{
				if (std::get<0>(*j) == node)
				{
					weight += std::get<1>(*j);
				}
			}
		}
		return weight;
	}

	double adjList::outWeight(int node) const {
		double weight = 0;
		for (auto i = mlist[node].begin(); i != mlist[node].end(); i++) {
			weight += std::get<1>(*i);
		}
		return weight;
	}

	bool adjList::inGraph(int node) const
	{
		return isInGraph[node];
	}

	std::vector< std::tuple <int, double> > adjList::outAdj(int node) const
	{
		return mlist[node];
	}

	std::vector< std::tuple <int, double> > adjList::inAdj(int node) const
	{
		std::vector< std::tuple <int, double> > in;
		for (auto i = mlist.begin(); i != mlist.end(); i++)
        {
			for (auto j = i->begin(); j != i->end(); j++)
			{
				if (std::get<0>(*j) == node)
				{
					in.push_back(*j);
				}
			}
		}
		return in;
	}

	double adjList::getWeight(int nodeS, int nodeE) const
	{
		for (auto i = mlist[nodeS].begin(); i != mlist[nodeS].end(); i++)
        {
			if (std::get<0>(*i) == nodeE)
			{
				return std::get<1>(*i);
			}
		}
		return 0;
	}
}
