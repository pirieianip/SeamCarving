//
// Created by ian on 4/27/20.
//

#include "StringManip.h"

int getNum(const std::string& input){
    int base = 1, ret = 0;
    for(auto i : input){
        if(i > 47 && i < 58){
            ret *= 10;
            ret += (i - 48);
        }
        else
            return -1;
    }
    return ret;
}
