# Depth First Search Maze Solver
This program is an implementation of the recursive depth first search algorithm in C to solve a maze.
## Procedure
The maze is input as a text file that the program reads into a 2D character array. The format of the input maze is as follows: The first line has the height and the width of the maze, and all lines after represent the maze itself. 

The four possible characters in the maze input are `.` to represent a space, `#` to represent a wall, `s` to represent the starting point of the maze, and `e` to represent the end of the maze. 

An example input maze might look like this:
```
4 5
.##.s
#.##.
e.##.
#....
```

The program then allocates memory for the output path by taking the product `height * width` and subtracting the number of walls from it. This is more memory efficient then just allocating an element in the path array for every square in the maze. 

Then, the depth first search algorithm, implemented in `solver.c`, walks through the maze and returns once it has either found the first valid path or it has hit a wall or edge of the maze. An enumeration type is used to define the four cardinal directions, and for each iteration of the `depth_first_search` function the program takes a step in all four directions, and will recursively backtrack if it has it a wall or edge. Each time it travels to a square in the maze, that square is marked as 'visited' so the program knows not to take a new step there.

Once either the first valid path is found or there are no unvisited squares the program can go to, the function returns and prints either the path or a message saying the maze has no solution to an output file specified as a command line argument. 

## File descriptions
`maze.c`: Contains functions to read the input maze file and allocate memory to store the maze. It also initializes the maze structure. Finally, it has logic to free the memory associated with the maze once the program exits.

`mazehelper.c`: Contains helper functions to check certain conditions for each maze square. Checks if a square is the start, end, in bounds, or a wall. 

`path.c`: Contains funcitons to read the path from the input file into the maze structure, to verify the solution produced by the program is correct, and to write the solution to the output file.

`solver.c`: Contains the function to initialize memory for the solution path and also the depth first search implementation to solve the maze and return the solution. 

## Running the code
You can run the code with the provided input files by running `make test` on the command line. You can also run it with other inputs by typing `make` and then `./main <inputFile> <outputFile>`. `make memory` runs Valgrind with the provided inputs to ensure there are no memory leaks or errors with the program, and `make clean` will remove all of the generated object files, executables, output files, and log files. 

## Inspiration
This project was adapted from a project I did for ECE 264, Advanced C Programming, at Purdue. I was motivated to optimize the implementation of the project and further my understanding of the depth first search algorithm by rewriting it myself. 
