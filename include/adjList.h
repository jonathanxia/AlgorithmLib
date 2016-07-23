#pragma once
#ifndef ADJLIST_H
#define ADJLIST_H

#include "graphDB.h"
#include <list>
#include <utility>

namespace AlgLib {
	class adjList : public graphDB {
	public:
		/** Default constructor */
		adjList(int numVertices = 0);
		/** Default destructor */
		virtual ~adjList();

		virtual void addVertex() override;
		virtual void addEdge(int nodeS, int nodeE, double weight = 1) override;
		virtual void deleteEdge(int nodeS, int nodeE) override;
		virtual void deleteVertex(int node) override;

		virtual int inDegree(int node) const override;
		virtual int outDegree(int node) const override;
		virtual double inWeight(int node) const override;
		virtual double outWeight(int node) const override;
		virtual double getWeight(int nodeS, int nodeE) const override;
		virtual std::vector< std::tuple <int, double> > outAdj(int node) const override;
		virtual std::vector< std::tuple <int, double> > inAdj(int node) const override;
	private:
		std::vector<std::vector<std::tuple<int, double>>> mlist;
	};
}


#endif
