//
// Created by Ben Short on 12/22/23.
//

#ifndef DAY7_H
#define DAY7_H
#include <map>
#include <string>
#include <vector>

class Day7 {
public:
    std::vector<std::string> gameData;
    std::vector<std::string> parseList;
    std::vector<int> bids;
    std::vector<std::string> hands;
    std::vector<long> ranks;
    std::vector<int> currentHandTotals;
    std::map<long, int> rankMap;

    std::map<char, int> cardPoints = {{'A',14},{'K',13},{'Q',12},{'J',11},{'T',10},{'9',9},
        {'8',8},{'7',7},{'6',6},{'5',5},{'4',4},{'3',3},{'2',2}};

    std::map<char, int> cardPoints2 = {{'A',14},{'K',13},{'Q',12},{'T',10},{'9',9},
        {'8',8},{'7',7},{'6',6},{'5',5},{'4',4},{'3',3},{'2',2},{'J',1}};

    void getData();

    void partOne();

    void partTwo();

    static void runDay7();
};



#endif //DAY7_H
