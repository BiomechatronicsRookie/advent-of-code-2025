#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "Wheel.h"

Wheel::Wheel(){};

Wheel::~Wheel(){};

int Wheel::rotate(int dial, int* pwd){
    // Declare variables to store password steps and errors
    int temp = 0;
    int move = 0;
    std::string c;
    std::string num = "0000";
    std::ios_base::iostate err;
    std::vector<int> range {0,99};
    std::filesystem::path path  = std::filesystem::current_path()/"src\\day1\\input.txt";

    // Open the input file
    std::cout << path << std::endl;
    this->inFile.open(path);
    std::cout << move << ' ' << dial << ' ' << *pwd <<  std::endl;

    // Read the file until rdstate returns end of file bit (returns 1)
    while(!this->inFile.rdstate()){
        this->inFile >> c;
        num = c.substr(1,3);
        temp = std::stoi(num);
        // If the command is L, rotation is negative, else is positive
        if (c[0] == 'L'){
            move = -temp;
            if (!dial){
                *pwd-=1;
            }
        } else{
            move = temp;
        }
        //move = (c[0] == 'L') ? -temp : temp;
        //*pwd = ((c[0] == 'L') && (dial == 0)) ? *pwd-1 : *pwd;
        std::cout << "Curr. Dial: " << dial << ' ';
        dial += move;
        std::cout << "Dial + Move " << dial << ' ' << "Password prewrap: " << *pwd;
        if (!dial){
            *pwd += 1;
        }else{
            while((dial > 99) || (dial < 0)){
                wrap(&dial, range);
                *pwd  += 1;
            }
        }
        std::cout << " Password postwrap:" << *pwd << std::endl;
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