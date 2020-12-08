#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

	int num_v = 0;
	char l[256];
	while (fgets(l, sizeof l, ifp) != NULL) num_v++;
	rewind(ifp);

  // TODO: please comment the following line
  printf("Total number of vertices = %d\n", num_v);

	char line[1024];
	while (fgets(line, sizeof line, ifp) != NULL)
	{
    int src_vertex, dst_vertex;
		char * pch;
		pch = strtok(line, " \n\r");
		sscanf(pch, "%d", &src_vertex);
		pch = strtok(NULL, " \n\r");

		while (pch != NULL)
		{
			// there is an edge from src_vertex to dst_vertex
			sscanf(pch, "%d", &dst_vertex);
      // TODO : please comment the following line
      printf("Edge exists between (%d,%d)\n", src_vertex, dst_vertex);
			pch = strtok(NULL, " \n\r");
		}

	}
  clock_t end = clock();
  printf("Time taken = %lf\n", ((double)end-begin)/CLOCKS_PER_SEC);

	fclose(ifp);
}
