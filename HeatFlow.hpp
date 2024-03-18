#include <vector>
#include <map>
using namespace std;

class Heatflow {

public:

    Heatflow(float initialTemp, int numberOfSections, float K, map<int, float> sourcesAndSinks);
    float initialTemp;
    int numberOfSections;
    float K;
    map<int, float> sourcesAndSinks;
    vector<float> rod;
    vector<float> tempRod;
    void tick(map<int, float> sourcesAndSinks);
    void pretty_print();

};

