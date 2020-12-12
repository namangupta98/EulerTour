#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int edge_num = 0;

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

// delete edge
void deleteEdge(struct Graph* graph, int head, int key){

	// storing head
	struct node* temp = graph->adjLists[head];
	struct node* prev = NULL;

	// if the head node is the key
	if (temp != NULL && temp->vertex == key){
		graph->adjLists[head] = temp->next;
		free(temp);
	}

	// if not head = key then search for the key
	else {

		// iterating over the list until key is found
		while (temp != NULL && temp->vertex != key){
			prev = temp;
			temp = temp->next;
		}

		// remove the node
		prev->next = temp->next;
		free(temp);
	}
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
			edge_num += 1;
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

// function to get euler circuit
void getEulerCircuit(struct Graph* graph){

	// creating a linked list for current path and euler tour.
	struct Graph* euler = createGraph(2);
	int curr_path = 0;	// the first element of adjacency list is curr_path list
	int eulerTour = 1;	// the second element of adjacency list is tour list.

	int curr_node = 0;
	int new_node, temp_node;

	addEdge(euler, curr_path, graph->adjLists[curr_node]->vertex); // curr_node = [0, next vertex in vertex 0 to make an edge]
	// addEdge(euler, curr_path, graph->adjLists[curr_node]->vertex);

	while (euler->adjLists[curr_path]){
		if (graph->adjLists[curr_node]){

			// storing random vertex which is neighbor of current vertex (popping)
			new_node = graph->adjLists[curr_node]->vertex;

			deleteEdge(graph, curr_node, new_node);
			deleteEdge(graph, new_node, curr_node);

			curr_node = new_node;

			// adding current node in the path
			addEdge(euler, curr_path, curr_node); 
		}

		else{
			temp_node = euler->adjLists[curr_path]->vertex;
			addEdge(euler, eulerTour, temp_node);
			deleteEdge(euler, curr_path, temp_node);
		}
	}

	printf("Euler Tour: ");
	while (euler->adjLists[eulerTour]){
		printf("%d ", euler->adjLists[eulerTour]->vertex+1);
		euler->adjLists[eulerTour] = euler->adjLists[eulerTour]->next;
	}
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
			addEdge(graph, src_vertex-1, dst_vertex-1);

		    // TODO : please comment the following line
		    // printf("Edge exists between (%d,%d)\n", src_vertex, dst_vertex);
			pch = strtok(NULL, " \n\r"); // pointer at next element
		}
	}

	if (isEulerTour(graph)){
		getEulerCircuit(graph);
	}

	// printGraph(graph);
	// printf("Adjacency List: %d \n", graph->adjLists[2]->vertex);
	// printf("%d \n", isEulerTour(graph));

  clock_t end = clock();
  // printf("Time taken = %lf\n", ((double)end-begin)/CLOCKS_PER_SEC);

	fclose(ifp);
}
