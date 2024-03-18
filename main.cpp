#include "HeatFlow.hpp"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main () {

map<int, float> sourcesAndSinks;

// You can specify the location and temperature of the sources or sinks here
sourcesAndSinks[0] = 100.0;
sourcesAndSinks[9] = 100.0;
float initialTemp = 10.0;
int numberOfSections = 10;
float K = 0.1;

Heatflow h(initialTemp, numberOfSections, K, sourcesAndSinks);
h.pretty_print();


h.tick(sourcesAndSinks);
h.pretty_print();


h.tick(sourcesAndSinks);
h.pretty_print();

h.tick(sourcesAndSinks);
h.pretty_print();

}