#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "maze.h"
#include "mazehelper.h"

char * solve_maze(Maze * m) 
{
	//Start at 1 to account for '\0'
	int maxSolutionSize = 1;
 	for (int i = 0; i < m -> width; i++)
	{
		for (int j = 0; j < m -> height; j++)
		{
			if (m -> maze[i][j].type != WALL)
			{
				maxSolutionSize++;
			}
		}
	}
	
	char * mazeSolution = malloc(maxSolutionSize * sizeof(char));

	MazePos mpos = { .xpos = m -> start.xpos, .ypos = m -> start.ypos };

	if (!depth_first_search(m, mpos, mazeSolution, 0))
	{
		fprintf(stderr, "No solution found!\n");
	}
	else
	{
	printf("Solution found: %s\n", mazeSolution);
	}
	
	return mazeSolution;
}
	
bool depth_first_search(Maze * m, MazePos curpos, char * path, int step)
{
	//Mark square as visited
	m -> maze[curpos.ypos][curpos.xpos].visited = true;

	//Check if we are at the end 
	if (at_end(curpos, m))
	{
		path[step] = '\0';
		return true;
	}

	//Initialize each direction
	MazePos north;
	north.xpos = curpos.xpos;
	north.ypos = curpos.ypos - 1;

	MazePos south;
	south.xpos = curpos.xpos;
	south.ypos = curpos.ypos + 1;

	MazePos east;
	east.xpos = curpos.xpos + 1;
	east.ypos = curpos.ypos;

	MazePos west;
	west.xpos = curpos.xpos - 1;
	west.ypos = curpos.ypos;

	//Step north
	if (square_valid(north, m))
	{
		if (depth_first_search(m, north, path, step + 1))
		{
			path[step] = NORTH;
			return true;
		}
	}
	
	//Step south
	if (square_valid(south, m))
	{
		if (depth_first_search(m, south, path, step + 1))
		{
			path[step] = SOUTH;
			return true;
		}
	}

	//Step east
	if (square_valid(east, m))
	{
		if (depth_first_search(m, east, path, step + 1))
		{
			path[step] = EAST;
			return true;
		}
	}

	//Step west
	if (square_valid(west, m))
	{
		if (depth_first_search(m, west, path, step + 1))
		{
			path[step] = WEST;
			return true;
		}
	}
	
	//Go back
	return false;
}
