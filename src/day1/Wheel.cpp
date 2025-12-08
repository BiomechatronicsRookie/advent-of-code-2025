#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Wheel.h"

Wheel::Wheel(){};

Wheel::~Wheel(){};

int Wheel::rotate(int dial, int* pwd){
    // Declare variables to store password steps and errors
    int temp =0;
    int move = 0;
    int extra_0 = 0;
    std::string c;
    std::string num = "0000";
    std::ios_base::iostate err = 0;
    std::vector<int> range {0,99};

    // Open the input file
    this->inFile.open("C:\\Users\\Carsten\\git\\vic\\advent-of-code\\src\\day1\\test.txt");

    // Read the file until rdstate returns end of file bit (returns 1)
    while(!this->inFile.rdstate()){
        this->inFile >> c;
        num = c.substr(1,3);
        temp = std::stoi(num);
        // If the command is L, rotation is negative, else is positive
        move = c[0] == 'L' ? ~temp+1 : temp;
        dial += move;

        if (!dial){
            *pwd += 1;
        }else{
            extra_0 = 0;
            while(!((dial <= 99) && (dial >= 0))){
                wrap(&dial, range);
                extra_0 += 1;
                *pwd += 1;
            }
        }
        std::cout << "Move is: " << move << ' ' << "Curr Pos is: " << dial << ' ' << "Curr Pwd is: " << *pwd << ' ' << "Passed through 0: " << extra_0 <<  std::endl;
    }
    // If end of file reached return 0 else return 1
    if (this->inFile.rdstate()){
        return 0;
    } else {
        return 1; 
    }
}

void wrap(int* pos, std::vector<int> range){
    if (*pos < range[0]){
        *pos = 100 + *pos;
    } else if(*pos > range[1]){
        *pos -= 100;
    };
    return;
}