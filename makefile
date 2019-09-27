CC=g++
FLAGS=-D_GLIBCXX_DEBUG
EJECUTABLE=program.exe
EJECUTABLETEST=testProgram.exe
FILES=FONT/main.cc FONT/Graph.cc FONT/Graph.h FONT/RandomGeometricGraphGenerator.cc FONT/RandomGeometricGraphGenerator.h FONT/RandomBinomialGraphGenerator.cc FONT/RandomBinomialGraphGenerator.h FONT/ConnectedComponentsExperiment.cc FONT/ConnectedComponentsExperiment.h
FILESTEST=FONT/TEST/testMain.cc FONT/Graph.cc FONT/Graph.h FONT/RandomGeometricGraphGenerator.cc FONT/RandomGeometricGraphGenerator.h FONT/RandomBinomialGraphGenerator.cc FONT/RandomBinomialGraphGenerator.h FONT/ConnectedComponentsExperiment.cc FONT/ConnectedComponentsExperiment.h
OBJECTS=main.o Graph.o RandomGeometricGraphGenerator.o RandomBinomialGraphGenerator.o ConnectedComponentsExperiment.o
OBJECTSTEST=testMain.o Graph.o RandomGeometricGraphGenerator.o RandomBinomialGraphGenerator.o ConnectedComponentsExperiment.o

all: testProgram.exe program.exe

program.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS)  -o $(EJECUTABLE)

testProgram.exe: $(OBJECTSTEST)
	$(CC) $(FLAGS) $(OBJECTSTEST)  -o $(EJECUTABLETEST)

Graph.o: FONT/Graph.h FONT/Graph.cc
	$(CC) -c FONT/Graph.cc

RandomGeometricGraphGenerator.o : FONT/RandomGeometricGraphGenerator.h FONT/RandomGeometricGraphGenerator.cc FONT/Graph.h
	$(CC) -c FONT/RandomGeometricGraphGenerator.cc -I FONT/

RandomBinomialGraphGenerator.o : FONT/RandomBinomialGraphGenerator.h FONT/RandomBinomialGraphGenerator.cc FONT/Graph.h
	$(CC) -c FONT/RandomBinomialGraphGenerator.cc -I FONT/

ConnectedComponentsExperiment.o : FONT/ConnectedComponentsExperiment.h FONT/ConnectedComponentsExperiment.cc FONT/RandomGeometricGraphGenerator.h FONT/RandomBinomialGraphGenerator.h FONT/Graph.h
	$(CC) -c FONT/ConnectedComponentsExperiment.cc -I FONT/

main.o: FONT/main.cc FONT/Graph.h FONT/RandomGeometricGraphGenerator.h FONT/RandomBinomialGraphGenerator.h FONT/ConnectedComponentsExperiment.h
	$(CC) -c FONT/main.cc -I FONT/

testMain.o: FONT/TEST/testMain.cc FONT/Graph.h FONT/RandomGeometricGraphGenerator.h FONT/RandomBinomialGraphGenerator.h FONT/ConnectedComponentsExperiment.h
	$(CC) -c FONT/TEST/testMain.cc -I FONT/

clean:
	-rm *.o $(objects) program.exe testProgram.exe