#include <cstdlib>
#include <vector>
#include "graph.h"
using namespace std;
#define SZ 100
#define MAX_POINTS 5

int main()
{
    GRAPH g(7);
    vector<int> data;
    vector<int> *ret_data;
    int i, points = 0;
    int distance;
    int min_tree[] = {0, 3, 1, 4, -1, 4, 7, 4};
    g.set_edge(1,2,2);
    g.set_edge(1,4,1);
    g.set_edge(2,4,3);
    g.set_edge(2,5,10);
    g.set_edge(3,1,5);
    g.set_edge(3,6,5);
    g.set_edge(4,3,2);
    g.set_edge(4,5,2);
    g.set_edge(4,6,8);
    g.set_edge(4,7,4);
    g.set_edge(5,7,6);
    g.set_edge(7,6,1);

    ret_data = g.primm(4);
    if(ret_data == NULL)
    {
        cout << "[-->] primm() should have returned a vector containing the tree\n";
        exit(points);
    }

    points+=2;
    if(ret_data->size() != 8)
    {
        cout << "[-->] The vector that was returned is not the right size\n";
        exit(points);
    }

    for(i=0;i<8;i++)
    {
        if(ret_data->at(i) != min_tree[i])
        {
            cout << "[-->] Expected "<<min_tree[i]<<" but got "<<ret_data->at(i)<<endl;
            exit(points);
        }
    }

    cout << "[-->] Test passed!\n";
    return MAX_POINTS;
}