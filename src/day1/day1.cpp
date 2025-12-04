#include <iostream>
#include <fstream>
#include "Wheel.h"

int err;

int main(){
    Wheel w;
    int16_t init_pos = 50;
    int16_t pwd = 0;
    err = w.rotate(init_pos, &pwd);
    return err;
};