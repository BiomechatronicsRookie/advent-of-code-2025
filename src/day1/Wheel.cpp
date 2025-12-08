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
    std::string c;
    std::string num = "0000";
    std::ios_base::iostate err = 0;
    std::vector<int> range {0,99};

    // Open the input file
    this->inFile.open("C:\\Users\\Carsten\\git\\vic\\advent-of-code\\src\\day1\\test.txt");
    std::cout << move << ' ' << dial << ' ' << *pwd <<  std::endl;

    // Read the file until rdstate returns end of file bit (returns 1)
    while(!this->inFile.rdstate()){
        this->inFile >> c;
        num = c.substr(1,3);
        temp = std::stoi(num);
        // If the command is L, rotation is negative, else is positive
        move = (c[0] == 'L') ? ~temp+1 : temp;
        *pwd = ((c[0] == 'L') && (dial == 0)) ? *pwd-1 : *pwd;
        dial += move;

        if (!dial){
            *pwd += 1;
        }else{
            while((dial > 99) || (dial < 0)){
                wrap(&dial, range);
                *pwd  += 1;
            }
        }
        std::cout << c << ' ' << dial  << ' ' << *pwd <<  std::endl;
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
        *pos += 100;
    } else if(*pos > range[1]){
        *pos -= 100;
    };
    return;
}