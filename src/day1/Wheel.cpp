#include <iostream>
#include <fstream>
#include <string>
#include "Wheel.h"

Wheel::Wheel(){};

Wheel::~Wheel(){};

int Wheel::rotate(){
    // Declare variables to store password steps and errors
    char c[4];
    std::ios_base::iostate err = 0;

    // Open the input file
    this->inFile.open("C:\\Users\\Carsten\\git\\vic\\advent-of-code\\src\\day1\\test.txt");

    // Read the file until rdstate returns end of file bit (returns 1)
    while(!this->inFile.rdstate()){
        this->inFile >> c;
        std::cout << c << std::endl;
    }
    // If end of file reached return 0 else return 1
    if (this->inFile.rdstate()){
        return 0;
    } else {
        return 1; 
    }
}