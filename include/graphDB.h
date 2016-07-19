#ifndef GRAPHDB_H
#define GRAPHDB_H
#include <vector>
#include <tuple>
namespace AlgLib
{
    class graphDB
    {
        public:
            /** Default constructor */
            graphDB();
            /** Default destructor */
            virtual ~graphDB();

            virtual int inDegree(int node) const = 0;
            virtual int outDegree(int node) const = 0;
            virtual double getWeight(int nodeS, int nodeE) const = 0;
            virtual double inWeight(int node) const = 0;
            virtual double outWeight(int node) const = 0;
            virtual std::vector< std::tuple <int, double> > outAdj(int node) const = 0;
            virtual std::vector< std::tuple <int, double> > inAdj(int node) const = 0;
            virtual int numVertex() const = 0;
            virtual void deleteVertex(int node) = 0;
            virtual void deleteEdge(int nodeS, int nodeE) = 0;
            virtual void addVertex() = 0;
            virtual void addEdge(int nodeS, int nodeE, double weight = 1) = 0;
            virtual bool inGraph(int node) const = 0;


        protected:

        private:
    };
}

#endif // GRAPHDB_H
