#include <iostream>
#include <fstream>
#include "Wheel.h"

int err;

int main(){
    Wheel w;
    int init_pos = 50;
    int pwd = 0;
    err = w.rotate(init_pos, &pwd);
    std::cout << "Password number:" << pwd << std::endl;
    return err;
};