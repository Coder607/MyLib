#include <iostream>
#include "ListGragh.h"
#include "MatrixGragh.h"

using namespace MyLib;
using namespace std;

template <typename V, typename E>
Gragh<V, E>& GraghEasy()
{
    static MatrixGragh<4, V, E> g;

    g.setEdge(0, 1, 1);
    g.setEdge(0, 2, 3);
    g.setEdge(1, 2, 1);
    g.setEdge(1, 3, 4);
    g.setEdge(2, 3, 1);

    return g;
}

template <typename V, typename E>
Gragh<V, E>& GraghComplex()
{
    static ListGragh<V, E> g(5);

    g.setEdge(0, 1, 10);
    g.setEdge(0, 3, 30);
    g.setEdge(0, 4, 100);

    g.setEdge(1, 2, 50);

    g.setEdge(2, 4, 10);

    g.setEdge(3, 2, 20);
    g.setEdge(3, 4, 60);

    return g;
}


template <typename V, typename E>
Gragh<V, E>& GraghSample()
{
    static ListGragh<V, E> g(3);

    g.setEdge(0, 1, 4);
    g.setEdge(0, 2, 11);

    g.setEdge(1, 2, 2);
    g.setEdge(1, 0, 6);

    g.setEdge(2, 0, 3);

    return g;
}



int main()
{
    Gragh<int, int>& g = GraghSample<int, int>();
    SharedPointer< Array<int> > r = g.floyd(0, 2, 65535);

    for (int i = 0; i < r->length(); i++)
    {
        cout << (*r)[i] << " ";
    }

    cout << endl;

    return 0;
}
