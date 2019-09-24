CC=g++
FLAGS=-D_GLIBCXX_DEBUG
EJECUTABLE=program.exe
FILES=FONT/TEST/testMain.cc FONT/Graph.cc FONT/Graph.h FONT/RandomGeometricGraphGenerator.cc FONT/RandomGeometricGraphGenerator.h
OBJECTS=testMain.o Graph.o RandomGeometricGraphGenerator.o

program.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS)  -o $(EJECUTABLE)

Graph.o: FONT/Graph.h FONT/Graph.cc
	$(CC) -c FONT/Graph.cc

RandomGeometricGraphGenerator.o : FONT/RandomGeometricGraphGenerator.h FONT/RandomGeometricGraphGenerator.cc FONT/Graph.h
	$(CC) -c FONT/RandomGeometricGraphGenerator.cc -I FONT/

testMain.o: FONT/TEST/testMain.cc FONT/Graph.h FONT/RandomGeometricGraphGenerator.h
	$(CC) -c FONT/TEST/testMain.cc -I FONT/

clean:
	-rm *.o $(objects) program.exe