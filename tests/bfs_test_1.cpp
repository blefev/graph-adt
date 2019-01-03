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
    int bfs_traversal[] = {1,2,4,5,3,6,7};
    
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

    ret_data = g.bfs(1);
    if(ret_data == NULL)
    {
        cout << "[-->] bfs() returned NULL when it should have returned a vector\n";
        exit(points);
    }

    if(ret_data->size() != 7)
    {
        cout << "[-->] the vector returned from the function is not the right size\n";
        exit(points);
    }

    points+=2;

    i = 0;
    for (std::vector<int>::iterator it = ret_data->begin(); it != ret_data->end(); ++it)
    {
        if(*it != bfs_traversal[i])
        {
            cout << "[-->] Expected " << bfs_traversal[i] << " but got " << *it <<"\n";
            exit(points);          
        }
        i++;
    }

    cout << "[-->] Test passed!\n";
    return MAX_POINTS;
}
