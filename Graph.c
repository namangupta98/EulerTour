#include <stdio.h>
#include <stdlib.h>

// creating linked list
struct node{
	int vertex;
	struct node *next;
};

struct node* createNode(int);

struct Graph{
	int numVertices;
	struct node** adjLists;
};

// create node
struct node* createNode(int v){
	struct node* newNode = malloc(sizeof(struct node)); //allocate memory using malloc
	newNode->vertex = v; // newNode's vertex is v
	newNode->next = NULL; // newNode's next is pointing to NULL
	return newNode; // new node
}

// create a graph
struct Graph* createGraph(int vertices){
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices; // no. of vertices in a graph
	graph->adjLists = malloc(vertices * sizeof(struct node*));

	for (int i = 0; i < vertices; i++)
		graph->adjLists[i] = NULL;

	return graph;
}

// add edge
void addEdge(struct Graph* graph, int s, int d){
	
	// add edge from s to d
	struct node* newNode = createNode(d);
	newNode->next = graph->adjLists[s];
	graph->adjLists[s] = newNode;

	//add edge from d to s
	newNode = createNode(s);
	newNode->next = graph->adjLists[d];
	graph->adjLists[d] = newNode;
}

// print the graph
void printGraph(struct Graph* graph){
	for (int v = 0; v < graph->numVertices; v++){
		struct node* temp = graph->adjLists[v];
		printf("\n Vertex %d\n: ", v);
		while (temp){
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	struct Graph* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);

	printGraph(graph);

	return 0;
}
