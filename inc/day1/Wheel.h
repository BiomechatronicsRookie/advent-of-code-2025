#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Wheel{
    private:

    public:
        Wheel();
        ~Wheel();
        int rotate(int16_t init_pos, int16_t* pwd);
        std::ifstream inFile;
};