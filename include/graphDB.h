#ifndef GRAPHDB_H
#define GRAPHDB_H
#include <vector>
#include <tuple>
namespace AlgLib
{
    class graphDB
    {
        public:
            /** \brief constructor that takes in number of vertices
            * \param numVertices The number of vertices for the graph database to store
            */
            graphDB(int numVertices = 0);

            /** Default destructor */
            virtual ~graphDB();

            /** \brief see Graph::inGraph() */
            virtual bool inGraph(int node) const;
            /** \brief see Graph::numVertex() */
            virtual int numVertex() const;
            /** \brief see Graph::highestNode() */
            virtual int highestNode() const;

            /** \brief see Graph::inDegree(int node) const */
            virtual int inDegree(int node) const = 0;
            /** \brief see Graph::outDegree(int node) const */
            virtual int outDegree(int node) const = 0;
            /** \brief see Graph::getWeight(int nodeS, int nodeE) const */
            virtual double getWeight(int nodeS, int nodeE) const = 0;
            /** \brief see Graph::inWeight(int node) const */
            virtual double inWeight(int node) const = 0;
            /** \brief see Graph::outWeight(int node) const */
            virtual double outWeight(int node) const = 0;
            /** \brief see Graph::outAdj(int node) const */
            virtual std::vector< std::tuple <int, double> > outAdj(int node) const = 0;
            /** \brief see Graph::inAdj(int node) const */
            virtual std::vector< std::tuple <int, double> > inAdj(int node) const = 0;

            /** \brief see Graph::deleteVertex(int node) */
            virtual void deleteVertex(int node) = 0;
            /** \brief see Graph::deleteEdge(int nodeS, int nodeE) */
            virtual void deleteEdge(int nodeS, int nodeE) = 0;
            /** \brief see Graph::addVertex() */
            virtual void addVertex() = 0;
            /** \brief see Graph::addEdge(int nodeS, int nodeE, double weight = 1) */
            virtual void addEdge(int nodeS, int nodeE, double weight = 1) = 0;



        protected:
            std::vector<bool> isInGraph;

        private:

    };
}

#endif // GRAPHDB_H
