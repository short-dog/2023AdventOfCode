#include "src/Day1.h"
#include "src/Day2.h"
#include "src/Day3.h"
#include "src/Day4.h"
#include "src/Day5.h"
#include "src/Day6.h"
#include <chrono>
#include <iostream>

#include "src/Day7.h"


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    //Day1::runDay1();
    // Day2::runDay2();
    //Day3::runDay3();
    //Day4::runDay4();
    //Day5::runDay5();
    //Day6::runDay6();
    Day7::runDay7();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl;

    return 0;
}
