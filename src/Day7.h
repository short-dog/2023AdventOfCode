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
    void getData();
    void rankHand();
    static void runDay7();
};



#endif //DAY7_H
