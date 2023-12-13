#include "src/Day1.h"
#include "src/Day2.h"
#include "src/Day3.h"
#include <chrono>
#include <iostream>

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    Day1::runDay1();
    Day2::runDay2();
    Day3::runDay3();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << std::endl;

    return 1;
}