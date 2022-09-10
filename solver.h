#ifndef _SOLVER_H_
#define _SOLVER_H_
#include "maze.h"

char * solve_maze(Maze * m);

bool depth_first_search(Maze * m, char * path, int step);

#endif
