#include <fstream>
#include <iostream>
#include <sstream>
#include "graph.h"

using namespace std;

Graph::Graph(string f) {
    fileName = f;
}

void Graph::read() {
    std::ifstream ifs;
    try {
        ifs.open(fileName.c_str(), ios::in | ios::out);
        if (!ifs.good()) {
            throw std::invalid_argument("file not existed!");
        }
    }catch(...) {
        cout<<"open "<<fileName<<" failed!"<<endl;
        exit(-1);
    }
    int vertex_count; int edge_count; bool directed;
    ifs>>vertex_count>>edge_count>>directed;
    cout<<"vertex_count="<<vertex_count<<", edge_count="<<edge_count<<", directed="<<directed<<endl;
    int start = 0;
    offsets.push_back(start);
    while (!ifs.eof()) {
        int end; double value;
        char buffer[100];
        ifs.getline(buffer, 100);
        stringstream ss(buffer);
        while (ss>>end>>value) {
            values.push_back(value);
            edges.push_back(end);
        }
        start++;
        offsets.push_back(start);
    }
    ifs.close();
}