#ifndef GRAPHDB_H
#define GRAPHDB_H

namespace AlgLib
{
    class graphDB
    {
        public:
            /** Default constructor */
            graphDB();
            /** Default destructor */
            virtual ~graphDB();

            /** Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            virtual graphDB& operator=(const graphDB& other) = 0;

            virtual int inDegree(int node) = 0;
            virtual int outDegree(int node) = 0;
            virtual double inWeight(int node) = 0;
            virtual double outWeight(int node) = 0;
            virtual int numVertex() const = 0;
            virtual void deleteVertex(int node) = 0;
            virtual void deleteEdge(int nodeS, int nodeE) = 0;
            virtual void addVertex() = 0;
            virtual void addEdge(int nodeS, int nodeE, double weight = 1) = 0;

        protected:

        private:
    };
}

#endif // GRAPHDB_H
