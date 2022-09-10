#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "mazehelper.h"

bool check_path(Maze * m, char * path)
{
	MazePos cur = { .xpos = m -> start.xpos, .ypos = m -> start.ypos };
	
	while (path [pathPos])
	{
		printf("At position %d. Maze positionL (%d, %d), Square type: %c, Next step: %c\n", 
			pathPos, cur.xpos, cur.ypos, m -> maze[cur.ypos][cur.xpos].type, path[pathPos]);

		//Take a step
		switch(path[pathPos])
		{
			case NORTH: cur.ypos--; break;
			case SOUTH: cur.ypos++; break;
			case EAST:  cur.xpos++; break;
			case WEST: 	cur.xpos--; break;
			default: fprintf(stderr, "Incorrectly formatted path string\n"); exit(1);
		}
		
		//Make sure square is in bounds before we read it 
		if (!in_bounds(cur, m))
		{
			return false;
		}

		printf("Moved to square: (%d, %d), Square type: %c\n",
			cur.xpos, cur.ypos, m -> maze[cur.ypos][cur.xpos].type);
			
		//Check if square is valid
		if (!square_valid(cur, m))
		{
			return false;	
		}
	
		m -> maze[cur.ypos][cur.xpos].visited = true;

		if (at_end(cur, m))
		{
			return true;
		}
		
		pathPos++;
	
		//Will return false until we are at the end of the maze
		//Used as helper for recursive DFS implementation in solver.c
		return false;
	}
}

char * read_path(char * pathFileName)
{
	FILE * inputPath = fopen(pathFileName, 'r');
	
	if (inputPath == NULL)
	{
		fprintf(stderr, "Error opening input path file\n");
	}
	
	//Get length of file
	int len = 0;
	while (!feof(inputPath))
	{
		fgetc(inputPath);
		len++;
	}

	//Go back to start
	if (fseek(inputPath, 0L, SEEK_SET) == -1)
	{
		fprintf(stderr, "Problem seeking to beginning of file\n");
		return NULL;
	}

	char * path = malloc(len * sizeof(char));
	
	//Read each line into path
	fscanf(inputPath, "%s\n", path);

	if (fclose(inputPath))
	{
		fprintf(stderr, "Problem closing input file\n");
		return NULL;
	}
	
	return path;
}

int write_path(char * pathFileName, char * path)
{
	FILE * f = fopen(pathFileName, 'w');

	if (f == NULL)
	{
		fprintf(stderr, "Error opening output file");
		return EXIT_FAILURE;
	}
	
	//Print out final path
	fprintf(f, "%s", path);
	
	fclose(f);
	
	return EXIT_SUCCESS;
	
}
