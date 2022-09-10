#include "mazehelper.h"

//Functions to check the status of the current maze square
bool at_end(MazePos cur, Maze * m)
{
	return (cur.xpos == m -> end.xpos) && (cur.ypos == m -> end.ypos);
}

bool in_bounds(MazePos cur, Maze * m)
{
	return ((cur.xpos >= 0) && (cur.xpos < m -> width)) && ((cur.ypos >= 0) && cur.ypos < m -> height);
}

bool hit_wall(MazePos cur, Maze * m)
{
	return (m -> maze[cur.ypos][cur.xpos].type == WALL);
}

bool is_visited(MazePos cur, Maze * m)
{
	return (m -> maze[cur.ypos][cur.xpos].visited);
}

bool square_valid(MazePos cur, Maze * m)
{
	return (in_bounds(cur, m) && !hit_wall(cur, m) && !is_visited(cur, m));
}
