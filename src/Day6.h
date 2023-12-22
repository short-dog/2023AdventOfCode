//
// Created by Ben Short on 12/20/23.
//
#ifndef DAY6_H
#define DAY6_H
#include <array>
#include <vector>
class Day6 {
public:
        std::array<int, 4> time = {41,77,70,96};
        std::array<int, 4> distance = {249,1362,1127,1011};

        int time2 = 41777096;
        long long distance2 = 249136211271011;

        //std::array<int, 4> timeS = {7,15,30};
        //std::array<int, 4> distanceS = {9,40,200};

        std::vector<int> results;
        std::vector<long long> results2;

        int totalP1 = 1;

        void runRaceP1();
        void runRaceP2();

        static void runDay6();
};



#endif //DAY6_H
