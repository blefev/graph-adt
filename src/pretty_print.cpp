// A cool ascii tree printing library found at http://www.randygaul.net/2015/06/15/printing-pretty-ascii-trees/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "pretty_print.h"
#define DEPTH 4
#define NUM_CHILDREN 6
 
char depth[ 2056 ];
int di;

typedef struct node
{
    struct node* child;
    struct node* next;
    int val;
} node;

void transform_mst(std::vector<int> *tree_data, int parent, node *tree)
{
	int i;
    node *child;
    tree->val = parent;
    tree->child = NULL;
	for(i=0;i<tree_data->size();i++)
	{
		if(tree_data->at(i) == parent)
		{
			child = (node*)malloc( sizeof( node ) );
            child->next = tree->child;
            tree->child = child;
			transform_mst(tree_data, i, child);
		}
	}
	return;
}
 
void Push( char c )
{
    depth[ di++ ] = ' ';
    depth[ di++ ] = c;
    depth[ di++ ] = ' ';
    depth[ di++ ] = ' ';
    depth[ di ] = 0;
}
 
void Pop( )
{
    depth[ di -= 4 ] = 0;
}
 
void Print( node* tree )
{
    printf( "(%d)\n", tree->val );
 
    node* child = tree->child;
 
    while ( child )
    {
        node* next = child->next;
        printf( "%s `--", depth );
        Push( next ? '|' : ' ' );
        Print( child );
        Pop( );
        child = next;
    }
}

void pretty_print_mst(std::vector<int> *tree_data, int root)
{
    node *tree = (node*)calloc(1, sizeof(node));
    transform_mst(tree_data, root, tree);
    Print(tree);
}
