#include "adjList.h"
#include <vector>
#include <utility>
#include <tuple>

namespace AlgLib {
	adjList::adjList(int numVertices) {
		std::vector<std::vector<std::tuple<int, double>>> list;
		list.reserve(numVertices);
		for (int i = 0; i < numVertices; i++) {
			std::vector<std::tuple<int, double>> adj;
			list.push_back(adj);
		}
	}

	adjList::~adjList() {

	}

	void adjList::addVertex() {
		std::vector<std::tuple<int, double>> adj;
		mlist.push_back(adj);
	}

	void adjList::addEdge(int nodeS, int nodeE, double weight)
	{
		mlist[nodeS].push_back(std::make_tuple(nodeE, weight));
	}

	void adjList::deleteEdge(int nodeS, int nodeE) {
		for (auto i = mlist[nodeS].begin(); i != mlist[nodeS].end(); i++) {
			if (std::get<0>(*i) == nodeE) {
				mlist[nodeS].erase(i);
			}
		}
	}

	void adjList::deleteVertex(int node) {
		mlist.erase(mlist.begin() + node);
		for (auto i = mlist.begin(); i != mlist.end(); i++) {
			for (auto j = i->begin(); j != i->end(); j++) {
				if (std::get<0>(*j) == node) {
					i->erase(j);
				}
			}
		}
	}

	int adjList::numVertex() const {
		return mlist.size();
	}

	int adjList::inDegree(int node) const{
		int degree = 0;
		for (auto i = mlist.begin(); i != mlist.end(); i++) {
			for (auto j = i->begin(); j != i->end(); j++) {
				if (std::get<0>(*j) ==  node && std::get<1>(*j) != 0) {
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

	double adjList::inWeight(int node) const {
		double weight = 0;
		for (auto i = mlist.begin(); i != mlist.end(); i++) {
			for (auto j = i->begin(); j != i->end(); j++) {
				if (j->first == node) {
					weight += j->second;
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

	bool adjList::inGraph(int node) const {
		return node < mlist.size();
	}

	std::vector< std::tuple <int, double> > adjList::outAdj(int node) const {
		return mlist[node];
	}

	std::vector< std::tuple <int, double> > adjList::inAdj(int node) const {
		std::vector< std::tuple <int, double> > in;
		for (auto i = mlist.begin(); i != mlist.end(); i++) {
			for (auto j = i->begin(); j != i->end(); j++) {
				if (std::get<0>(*j) == node) {
					in.push_back(*j);
				}
			}
		}
		return in;
	}

	double adjList::getWeight(int nodeS, int nodeE) const {
		for (auto i = mlist[nodeS].begin(); i != mlist[nodeS].end(); i++) {
			if (std::get<0>(*i) == nodeE) {
				return std::get<1>(*i);
			}
		}
	}
}
