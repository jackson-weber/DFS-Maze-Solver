#ifndef _MAZE_H_
#define _MAZE_H_

#include <stdbool.h>

//Define types of maze squares
typedef enum SquareType 
{
	WALL = '#',
	SPACE = '.',
	START = 's',
	END = 'e',
} SquareType;

//Maze squares
typedef struct MazeSquare
{
	SquareType type;
	bool visited;
} MazeSquare;

//Positions in maze
typedef struct MazePos
{
	int xpos;
	int ypos;
} MazePos;

//Struct for maze
typedef struct Maze
{
	MazeSquare ** maze; //2D array
	int width;
	int height;
	MazePos start; //Location of 's'
	MazePos end; //Location of 'e'
} Maze;

Maze * read_maze(char * mazeFileName);

void free_maze(Maze * m);

#endif
