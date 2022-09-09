#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "path.h"
#include "solver.h"

int main(int argc, char ** argv)
{
	//Make sure command line args are correct
	if (argc != 3)
	{
		printf(stderr, "Wrong number of comand line arguments\n");
		printf(stderr, "Usage: ./main <mazeFile> <pathFile>\n");
	}

	Maze * m = read_maze(argv[1]);
	
	if (m == NULL) 
	{
		return EXIT_FAILURE;
	}
	
	char * path = solve_maze(m);

	if (write_path(argv[2], path))
	{
		free_maze(m);
		free(m);
		free(path);
		return EXIT_FAILURE;
	}

	//Clean up memory
	free_maze(m);
	free(m);
	free(path);
	return EXIT_SUCCESS;
}
