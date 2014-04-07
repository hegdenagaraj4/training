#include <stdio.h>
#include "debug.h"

typedef struct _bin_tree_
{
	int data;
	struct _bin_tree_ *left;
	struct _bin_tree_ *right;
}BINTREE;

void query_nodes_reqd(int *ptr)
{
	int nodes;
	log_info("ENTRY");
	log_info("Enter the number of nodes required");
	scanf("%d",&nodes);
	*ptr = nodes;
	log_info("Number of nodes required are %d",nodes);
	log_info("EXIT");
}

void add_node(BINTREE *tree)
{
	int node;
	BINTREE *temp;
	log_info("ENTRY");
	log_info("Enter the node ");
	scanf("%d",&node);
	temp = (BINTREE *)malloc(sizeof(BINTREE));
	if(temp!=NULL&& temp->left==NULL && temp->right==NULL )
	{
		temp->data = node;
	}
	else
	{
		if(node >= tree->data)
		{

		}
	}
	log_info("EXIT");
}
void search_node(BINTREE *tree)
{

}

void delete_node(BINTREE *tree)
{

}

void node_traversal(BINTREE *tree)
{

}

int main()
{
	int nodes,choice;
	BINTREE * bin_tree;
	log_info("ENTRY");
	log_info("enter your choice\n1: add_node \n2:search_node\n3:delete_node\n4:Traversal\n5:EXIT");
	scanf("%d",&choice);
	while(1)
	{
		switch(choice)
		{
			case 1:
				add_node(bin_tree);
				break;

			case 2:
				search_node(bin_tree);
			break;

			case 3:
				delete_node(bin_tree);
			break;

			case 4:
				node_traversal(bin_tree);
			break;	

			case 5:
				exit(1);
			break;
		}
	}
	query_nodes_reqd(&nodes);
	bin_tree = (BINTREE *)malloc(nodes*(sizeof(BINTREE)));
	
	log_info("EXIT");
	return 0;
}