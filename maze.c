#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

Maze * read_maze(char * mazeFileName)
{
	FILE * inputMaze = fopen(mazeFileName, "r");
	
	if (inputMaze == NULL)
	{
		fprintf(stderr, "Could not open maze file\n");
		exit(1);
	}
	
	Maze * m = malloc(sizeof(Maze));
	
	//Make sure height and width are in the first line of the maze input
	if (fscanf(inputMaze, "%d %d\n", &(m -> height), &(m -> width)) != 2)
	{
		fprintf(stderr, "Wrongly formatted input: can't read maze dimensions\n");
		free(m);
		return NULL;	
	}
	
	m -> maze = malloc(m -> height * sizeof(MazeSquare *));
	
	//Initialize all squares of the maze
	for (int i = 0; i < m -> width; i++)
	{
		m -> maze[i] = malloc(m -> width * sizeof(MazeSquare));
	}
	
	for (int i = 0; i < m -> height; i++)
	{
		for (int j = 0; j < m -> width; j++)
		{
			int val = fgetc(inputMaze);
			m -> maze[i][j].type = val;
			m -> maze[i][j].visited = false;
			
			if (val == START)
			{
				m -> start.xpos = j;
				m -> start.ypos = i;
			}
			else if (val == END)
			{
				m -> end.xpos = j;
				m -> end.ypos = i;
			}
		}

		//Make sure we are at the end of the line
		int c = fgetc(inputMaze);
		if (c != '\n')
		{
			fprintf(stderr, "Incorrectly formatted maze file: %s\n", mazeFileName);
			free_maze(m);
			free(m);
			return NULL;
		}
	}

	if (fclose(inputMaze))
	{
		fprintf(stderr, "Error closing file %s\n", mazeFileName);
		free_maze(m);
		free(m);
		return NULL;
	}
	
	return m;
}

void free_maze(Maze * m)
{
	for (int i = 0; i < m -> height; i++)
	{
		free(m -> maze[i]);
	}
	
	free(m -> maze);
}
