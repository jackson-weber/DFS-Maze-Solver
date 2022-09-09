#ifndef _MAZEHELPER_H_
#define _MAZEHELPER_H_
#include "maze.h"

bool at_end(MazePos cur, Maze * m);

bool in_bounds(MazePos cur, Maze * m);

bool hit_wall(MazePos cur, Maze * m);

bool is_visited(MazePos cur, Maze * m);

bool square_valid(MazePos cur, Maze * m);

#endif
