#include <iostream>
#include <fstream>
#include <string>
#include "Wheel.h"

Wheel::Wheel(){};

Wheel::~Wheel(){};

int Wheel::rotate(int16_t init_pos, int16_t* pwd){
    // Declare variables to store password steps and errors
    int i = 4;
    int16_t temp =0;
    int16_t move = 0;
    int data = 0;
    char c[5] = "0000";
    std::ios_base::iostate err = 0;

    // Open the input file
    this->inFile.open("C:\\Users\\Carsten\\git\\vic\\advent-of-code\\src\\day1\\test.txt");

    // Read the file until rdstate returns end of file bit (returns 1)
    while(!this->inFile.rdstate()){
        this->inFile >> c;

        std::cout << c << std::endl;
        // If the command is L, rotation is negative, else is positive
        move = c[0] == 'L' ? ~temp+1 : temp;       
    }
    // If end of file reached return 0 else return 1
    if (this->inFile.rdstate()){
        *pwd = i;
        return 0;
    } else {
        return 1; 
    }
}