#include "ConnectedComponentsExperiment.h"
#include "RandomBinomialGraphGenerator.h"
#include "RandomGeometricGraphGenerator.h"
#include <vector>

void startExperimentGeometric(){
    
     vector<int> enes(11);
    enes[0] = 10;
    enes[1] = 20;
    enes[2] = 40;
    enes[3] = 60;
    enes[4] = 80;
    enes[5] = 100;
    enes[6] = 150;
    enes[7] = 200;
    enes[8] = 250;
    enes[9] = 300;
    enes[10] = 400;
    
    RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();
        cout << "GEOMETRIC"<< endl;
      for (int i = 0; i < 11; ++i){//bucle que et fara per cada n
        for (float r = 0; r < 1; r = r + 0.1){ // per r
        int es_conex = 0;
            float numero_de_cops = 10000;
             int i = 1;
            for (int j = 0; j < numero_de_cops; ++j){ //bucle que et calcularà la mitjana de components conexes
                Graph A;
                A = generator.generateGraph(enes[i], r);
                es_conex  = es_conex + A.getNumOfConnectedComponents();
             }
            float prob_conex = es_conex/numero_de_cops;
            cout << "Para el primer valor de 'n': " << enes[i] << endl;
            cout << "Valor esperado de 'r': " << r << endl;
            cout << "Probabilitat : " << prob_conex << endl;
            cout << "------------------------" << endl;
            cout << endl;
        }
    }
}

void startExperimentBinomial(){
    vector<int> enes(11);
    enes[0] = 10;
    enes[1] = 20;
    enes[2] = 40;
    enes[3] = 60;
    enes[4] = 80;
    enes[5] = 100;
    enes[6] = 150;
    enes[7] = 200;
    enes[8] = 250;
    enes[9] = 300;
    enes[10] = 400;
    
    RandomBinomialGraphGenerator generator = RandomBinomialGraphGenerator();
        cout << "BINOMIAL"<< endl;
      for (int i = 0; i < 11; ++i){//bucle que et fara per cada n
        for (float p = 0; p < 1; p = p + 0.1){ // per p
        int es_conex = 0;
            float numero_de_cops = 10000;
             int i = 1;
            for (int j = 0; j < numero_de_cops; ++j){ //bucle que et calcularà la mitjana de components conexes
                Graph A;
                A = generator.generateGraph(enes[i], p);
                es_conex  = es_conex + A.getNumOfConnectedComponents();
             }
            float prob_conex = es_conex/numero_de_cops;
            cout << "Para el primer valor de 'n': " << enes[i] << endl;
            cout << "Valor esperado de 'p': " << p << endl;
            cout << "Probabilitat : " << prob_conex << endl;
            cout << "------------------------" << endl;
            cout << endl;
        }
      }
}


   
