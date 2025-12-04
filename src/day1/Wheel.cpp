#include <iostream>
#include <fstream>
#include <string>
#include "Wheel.h"

Wheel::Wheel(){};

Wheel::~Wheel(){};

int Wheel::rotate(int16_t init_pos, int16_t* pwd){
    // Declare variables to store password steps and errors
    int16_t i = 0;
    char c[4];
    bool temp = 0;
    std::ios_base::iostate err = 0;

    // Open the input file
    this->inFile.open("C:\\Users\\Carsten\\git\\vic\\advent-of-code\\src\\day1\\test.txt");

    // Read the file until rdstate returns end of file bit (returns 1)
    while(!this->inFile.rdstate()){
        this->inFile >> c;
        int16_t val = (c[1] - '0')*10 + (c[2] - '0');
    }
    // If end of file reached return 0 else return 1
    if (this->inFile.rdstate()){
        *pwd = i;
        return 0;
    } else {
        return 1; 
    }
}