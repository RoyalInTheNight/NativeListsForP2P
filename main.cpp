//
// Created by MikoG on 31.12.2022.
//
#include <iostream>
#include "maps.h"

int main() {
    pet_map<core_maps::int32_t, std::string> map;

    map.insert(pet_map<int, std::string>::value_type(32, "ewqe"));

    std::string res = map.at(32);
}