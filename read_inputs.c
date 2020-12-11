#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

	// //add edge from d to s
	// newNode = createNode(s);
	// newNode->next = graph->adjLists[d];
	// graph->adjLists[d] = newNode;
}

// print the graph
void printGraph(struct Graph* graph){
	for (int v = 0; v < graph->numVertices; v++){
		struct node* temp = graph->adjLists[v];
		printf("\n Vertex %d\n: ", v+1);
		while (temp){
			printf("%d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

// Check Euler Tour exists
int isEulerTour(struct Graph* graph){
	for (int v = 0; v < graph->numVertices; v++){
		struct node* temp = graph->adjLists[v];
		// printf("\n Vertex %d\n: ", v);
		int ctr = 0;

		// count no. of edges
		while (temp){
			ctr += 1;
			// printf("%d ", temp->vertex);
			temp = temp->next;
		}

		// check even edges
		if ((ctr % 2) != 0){
			// printf("No Euler Tour exists!!");
			return(0);
		}
	}
	return(1);
}

// main function
int main(int argc, char *argv[])
{
	FILE *ifp;

	if (argc < 2)
	{
		printf("too few arguments !");
		return 0;
	}
  clock_t begin = clock();

	// read input from file
	ifp = fopen(argv[1], "r");

	int num_v = 0; // number of vertices
	char l[256];
	while (fgets(l, sizeof l, ifp) != NULL) num_v++; // reads the lines
	rewind(ifp);  // setting the pointer back to the beginning of the file

	// creating a graph
	struct Graph* graph = createGraph(num_v);

  // TODO: please comment the following line
  // printf("Total number of vertices = %d\n", num_v);

	char line[1024];
	while (fgets(line, sizeof line, ifp) != NULL)
	{
    int src_vertex, dst_vertex;
		char * pch;
		pch = strtok(line, " \n\r"); // pointer at first element
		sscanf(pch, "%d", &src_vertex); // storing src_vertex
		pch = strtok(NULL, " \n\r"); // pointer at second element

		while (pch != NULL)  // until there is another node in the linked list
		{
			// there is an edge from src_vertex to dst_vertex
			sscanf(pch, "%d", &dst_vertex); // storing connect node in dst_vertex
      		
      		// adding edge in the graph
			addEdge(graph, src_vertex-1, dst_vertex);

		    // TODO : please comment the following line
		    // printf("Edge exists between (%d,%d)\n", src_vertex, dst_vertex);
			pch = strtok(NULL, " \n\r"); // pointer at next element
		}
	}

	// printGraph(graph);
	// printf("Adjacency List: %d \n", graph->adjLists[2]->vertex);
	printf("%d \n", isEulerTour(graph));

  clock_t end = clock();
  // printf("Time taken = %lf\n", ((double)end-begin)/CLOCKS_PER_SEC);

	fclose(ifp);
}
