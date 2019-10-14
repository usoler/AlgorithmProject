CC=g++
FLAGS=-D_GLIBCXX_DEBUG
EJECUTABLE=program.exe
EJECUTABLETEST=testProgram.exe
FILES=src/main.cc src/Graph.cc src/Graph.h src/RandomGeometricGraphGenerator.cc src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.cc src/RandomBinomialGraphGenerator.h src/ConnectedComponentsExperiment.cc src/ConnectedComponentsExperiment.h src/ConnectivityExperiment.cc src/ConnectivityExperiment.h src/LargestConnectedComponentExperiment.cc src/LargestConnectedComponentExperiment.h
FILESTEST=src/TEST/testMain.cc src/Graph.cc src/Graph.h src/RandomGeometricGraphGenerator.cc src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.cc src/RandomBinomialGraphGenerator.h src/ConnectedComponentsExperiment.cc src/ConnectedComponentsExperiment.h src/ConnectivityExperiment.cc src/ConnectivityExperiment.h
OBJECTS=main.o Graph.o RandomGeometricGraphGenerator.o RandomBinomialGraphGenerator.o ConnectedComponentsExperiment.o ConnectivityExperiment.o LargestConnectedComponentExperiment.o
OBJECTSTEST=testMain.o Graph.o RandomGeometricGraphGenerator.o RandomBinomialGraphGenerator.o ConnectedComponentsExperiment.o ConnectivityExperiment.o

all: testProgram.exe program.exe

program.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS)  -o $(EJECUTABLE)

testProgram.exe: $(OBJECTSTEST)
	$(CC) $(FLAGS) $(OBJECTSTEST)  -o $(EJECUTABLETEST)

Graph.o: src/Graph.h src/Graph.cc
	$(CC) -c src/Graph.cc

RandomGeometricGraphGenerator.o : src/RandomGeometricGraphGenerator.h src/RandomGeometricGraphGenerator.cc src/Graph.h
	$(CC) -c src/RandomGeometricGraphGenerator.cc -I src/

RandomBinomialGraphGenerator.o : src/RandomBinomialGraphGenerator.h src/RandomBinomialGraphGenerator.cc src/Graph.h
	$(CC) -c src/RandomBinomialGraphGenerator.cc -I src/

ConnectedComponentsExperiment.o : src/ConnectedComponentsExperiment.h src/ConnectedComponentsExperiment.cc src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.h src/Graph.h
	$(CC) -c src/ConnectedComponentsExperiment.cc -I src/

ConnectivityExperiment.o : src/ConnectivityExperiment.h src/ConnectivityExperiment.cc src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.h src/Graph.h
	$(CC) -c src/ConnectivityExperiment.cc -I src/

LargestConnectedComponentExperiment.o : src/LargestConnectedComponentExperiment.h src/LargestConnectedComponentExperiment.cc src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.h src/Graph.h
	$(CC) -c src/LargestConnectedComponentExperiment.cc -I src/	

main.o: src/main.cc src/Graph.h src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.h src/ConnectedComponentsExperiment.h src/LargestConnectedComponentExperiment.h
	$(CC) -c src/main.cc -I src/

testMain.o: src/TEST/testMain.cc src/Graph.h src/RandomGeometricGraphGenerator.h src/RandomBinomialGraphGenerator.h src/ConnectedComponentsExperiment.h
	$(CC) -c src/TEST/testMain.cc -I src/

clean:
	-rm *.o $(objects) program.exe testProgram.exe