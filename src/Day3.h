//
// Created by Ben Short on 12/10/23.
//

#ifndef DAY3_H
#define DAY3_H
#include <map>
#include <string>
#include <vector>


class Day3 {
public:
    static void runDay3();
    void getData();
    void partOne();

    std::string engineSchematic;
    std::vector<std::string> gameData;

    int partOneTotal = 0;
};


#endif //DAY3_H
