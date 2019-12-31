#include <string>
#include <vector>
using namespace std;

class Graph {
private:
    string fileName;
    vector<double> values;
    vector<int> edges;
    vector<int> offsets;
public:
    Graph(string fileName);
    void read(void);
};