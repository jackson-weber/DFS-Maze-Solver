#ifndef _PATH_H_
#define _PATH_H_

#include <stdbool.h>
#include "maze.h"

typedef enum PathType
{
	NORTH = 'n';
	SOUTH = 's';
	EAST = 'e';
	WEST = 'w';
} PathType;

char read_path(char * pathFileName);

int write_path(char * pathFileName, char * path);

bool check_path(Maze * m, char * path);

#endif
