CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) 
EXEC = main
OBJS =  main.o path.o maze.o solver.o mazehelper.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose --track-origins=yes

$(EXEC): $(OBJS) maze.h mazehelper.h path.h solver.h
	$(GCC) $(OBJS) -o $(EXEC) 

test: $(EXEC)
	./$(EXEC) inputs/maze1 output1
	./$(EXEC) inputs/maze2 output2
	./$(EXEC) inputs/maze3 output3
	./$(EXEC) inputs/maze4 output4
	./$(EXEC) inputs/maze5 output5

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) inputs/maze1 output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) inputs/maze2 output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) inputs/maze3 output3
	$(VALGRIND) --log-file=log4 ./$(EXEC) inputs/maze4 output4
	$(VALGRIND) --log-file=log5 ./$(EXEC) inputs/maze5 output5

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f id? first? last? log?
