//
// Created by Ben Short on 12/10/23.
//

#ifndef DAY3_H
#define DAY3_H
#include <string>
#include <vector>


class Day3 {
public:
    static void runDay3();
    void getData();
    void partOne();

    void partTwo();

    std::vector<std::string> engineParts;
    std::string engineSchematic;
    int partOneTotal = 0;
    int partTwoTotal = 0;
};


#endif //DAY3_H
