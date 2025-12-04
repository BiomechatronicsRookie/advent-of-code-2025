#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Wheel{
    private:

    public:
        Wheel();
        ~Wheel();
        int rotate();
        std::ifstream inFile;
};