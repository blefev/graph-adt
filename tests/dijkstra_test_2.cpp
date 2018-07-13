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

    g.set_edge(1,2,2);
    g.set_edge(1,4,1);
    g.set_edge(2,4,3);
    g.set_edge(2,5,10);
    g.set_edge(3,1,4);
    g.set_edge(3,6,5);
    g.set_edge(4,3,2);
    g.set_edge(4,5,2);
    g.set_edge(4,6,8);
    g.set_edge(4,7,4);
    g.set_edge(5,7,6);
    g.set_edge(7,6,1);

    distance = g.dijkstra(2, 1);
    if(distance == -1)
    {
        cout << "[-->] dijkstras failed\n";
        exit(points);
    }

    points+=2;

    if(distance != 9)
    {
        cout <<"[-->] distance from 2 to 1 should be 9\n";
        cout <<"[-->] "<<distance<<" was returned\n";
        exit(points);
    }

    cout << "[-->] Test passed!\n";
    return MAX_POINTS;
}