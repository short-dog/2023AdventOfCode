//
// Created by Ben Short on 12/20/23.
//
#include "Day6.h"
#include <iostream>
#include <__algorithm/ranges_sort.h>
//Race Time:        41     77     70     96
//Current Record Distance:   249   1362   1127   1011
//zero millimeters per millisecond
//for each millisecond held, speed increases by millimeter/millisecond
void Day6::runRaceP1() {
    for(int i = 0; i < size(time); i++) {
        int recordsBeat = 0;
        results.clear();
        for (int ii = 0; ii < time[i]; ii++) {
            int speed = ii;
            int distance = speed * (time[i] - ii);
            results.push_back(distance);
        }
        int minValue = distance[i];
        std::ranges::sort(results);
        for (auto& current : results) {
            if (current > minValue) {
                recordsBeat++;
            }
        }
        totalP1 *= recordsBeat;
    }
    std::cout << "Part One Total: " << totalP1 << std::endl;
}
void Day6::runRaceP2() {
    int recordsBeat = 0;
    for (int ii = 0; ii < time2; ii++) {
        long long speed = ii;
        long long distance = speed * (time2 - ii);
        results2.push_back(distance);
    }
    std::ranges::sort(results2);
    for (auto& current : results2) {
        if (current > distance2) {
            recordsBeat++;
        }
    }
    std::cout << "Part Two Total: " << recordsBeat << std::endl;
}
void Day6::runDay6() {
    Day6 day6;
    day6.runRaceP1();
    day6.runRaceP2();
}