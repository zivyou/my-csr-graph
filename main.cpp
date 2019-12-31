#include <iostream>
#include <unistd.h>
#include <string>

#include <fstream>

#include "graph.h"
using namespace std;


int main(int argc, char **argv) {
    int argument;
    string inputFile;
    if ((argument = getopt(argc, argv, "f:")) != -1) {
        switch(argument) {
        case 'f':
            inputFile=string(optarg);
            break;
        default:
            cout<<"invalid argument"<<endl;
            exit(-1);
        }
    } else {
        cout<<"need file name"<<endl;
        exit(-1);
    }

    Graph g(inputFile);
    g.read();
    return 0;
}