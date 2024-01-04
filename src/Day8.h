//
// Created by Ben Short on 1/3/24.
//

#ifndef DAY8_H
#define DAY8_H
#include <map>
#include <vector>


class Day8 {
public:
    std::vector<std::string> gameData;
    std::vector<char> directions;
    std::vector<std::string> origin;
    std::vector<std::string> destinationL;
    std::vector<std::string> destinationR;
    std::vector<std::pair<std::string,std::string>> destinationPairs;
    std::map<std::string,int> originMap;
    int totalTravelPart1 = 0;

    static void runDay8();

    void getData();

    void partOne();

    void partTwo();
};



#endif //DAY8_H
