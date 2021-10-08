#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class TemporalsHandler {
    int temporalCounter;
    public:
    void reset(){
        temporalCounter = 0;
    }

    int getVariable(){
        temporalCounter++;
        return temporalCounter - 1;
    }

};
