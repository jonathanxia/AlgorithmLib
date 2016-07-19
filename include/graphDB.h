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

            virtual int getDegree(int node) = 0;
            virtual int numVertex() = 0;
            virtual int deleteVertex(int node) = 0;
            virtual int deleteEdge(int nodeS, int nodeE) = 0;

        protected:

        private:
    };
}

#endif // GRAPHDB_H
