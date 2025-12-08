#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Wheel{
    private:

    public:
        Wheel();
        ~Wheel();
        int rotate(int init_pos, int* pwd);
        std::ifstream inFile;
};

void wrap(int* pos, std::vector<int> range);