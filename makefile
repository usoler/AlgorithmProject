CC=g++
FLAGS=-D_GLIBCXX_DEBUG
EJECUTABLE=program.exe
FILES=FONT/TEST/testMain.cc FONT/Graph.cc FONT/Graph.h
OBJECTS=testMain.o Graph.o

program.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS)  -o $(EJECUTABLE)

Graph.o: FONT/Graph.h FONT/Graph.cc
	$(CC) -c FONT/Graph.cc

testMain.o: FONT/TEST/testMain.cc FONT/Graph.h
	$(CC) -c FONT/TEST/testMain.cc -I FONT/

clean:
	-rm *.o $(objects) program.exe