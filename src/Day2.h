//
// Created by Ben Short on 12/9/23.
//

#ifndef DAY2_H
#define DAY2_H
#include <map>
#include <vector>
#include <string>

class Day2 {
public:
    std::map<std::string, int> cubeBag = {
    {"red", 12}, {"green", 13}, {"blue", 14}
    };

    std::map<std::string, int> cubesNeeded = {{"red", 0}, {"green", 0}, {"blue", 0}};

    int total = 0;
    int total2 = 0;

    std::vector<std::string> gameData;
    std::vector<std::string> gamesSucceeded;
    std::vector<std::string> gameParseList;

    void getData();

    void parseDataPart1();

    void parseDataPart2();

    void processPart1();

    void clearData();

    void printTotal();

    void calcCubesNeeded();

    static void runDay2();
};
#endif //DAY2_H
