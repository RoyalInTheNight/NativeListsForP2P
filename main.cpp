//
// Created by MikoG on 31.12.2022.
//
#include <stdio.h>
#include "maps.h"

int main() {
    list<char, short, int> lis;

    int debug = lis.test(43, 31, 1);

    if (debug == 0)
        fprintf(stdout, "Success.\n");

    else if (debug == -1)
        fprintf(stdout, "Alloc error.\n");

    else if (debug == -2)
        fprintf(stdout, "Size error.\n");


}