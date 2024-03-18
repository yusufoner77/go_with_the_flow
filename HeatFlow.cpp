#include "HeatFlow.hpp"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

Heatflow::Heatflow(float initialTemp, int numberOfSections, float K, map<int, float> sourcesAndSinks) {

    this->initialTemp = initialTemp;
    this->numberOfSections = numberOfSections;
    this->K = K;

    for (int i = 0; i < numberOfSections; i++) {
        // If there is a key at index i, add its value to the vector
        if (sourcesAndSinks.count(i)) {
            rod.push_back(sourcesAndSinks[i]);
        }
        // Otherwise, add the initial temp to the vector
        else {
            rod.push_back(initialTemp);
        }
    }

}

void Heatflow::tick(map<int, float> sourcesAndSinks) {

    // Initialize tempVector with zeroes
    for (int i = 0; i < numberOfSections; i++) {
        tempRod.push_back(0);
    }

    if (sourcesAndSinks.count(0)) {
        tempRod[0] = sourcesAndSinks[0];
    }
    
    else {
        // Ignores the preceding section of this equation, and reduces factor from 2 to 1 for current position's temp
        tempRod[0] = rod[0] + K * (rod[1] - rod[0]);
    }

    for (int i = 1; i < (numberOfSections - 1); i++) {
        // If there is a key at index i, add its value to tempRod
        if (sourcesAndSinks.count(i)) {
            tempRod[i] = sourcesAndSinks[i];
        }

        // Otherwise, use the temperature equation
        else {
            tempRod[i] = rod[i] + K * (rod[i + 1] - 2 * rod[i] + rod[i - 1]);
        }
    }

    if (sourcesAndSinks.count(numberOfSections - 1)) {
        tempRod[numberOfSections - 1] = sourcesAndSinks[numberOfSections - 1];
    }

    else {
        // Ignores the next section of this equation and reduces the factor from 2 to 1 for the current position's temp
        tempRod[numberOfSections - 1] = rod[numberOfSections - 1] + K * (rod[numberOfSections - 2] - rod[numberOfSections - 1]);
    }

    for (int i = 0; i < numberOfSections; i++) {
        rod[i] = tempRod[i];
    }

    tempRod.clear();

}

void Heatflow::pretty_print() {

    for (int i = 0; i < numberOfSections; i++) {
        cout << "|  " << rod[i] << "  ";
    }

    cout << "|" << endl;

}

