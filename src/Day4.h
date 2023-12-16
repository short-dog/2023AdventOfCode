//
// Created by Ben Short on 12/16/23.
//

#ifndef DAY4_H
#define DAY4_H
#include <vector>


class Day4 {
public:
    void getData();
    void partOne();
    virtual void ticketCheck(int i);
    void partTwo();
    static void runDay4();

    std::vector<std::string> gameData;
    std::vector<int> myNumbers;
    std::vector<int> winningNumbers;

private:
    int day4Part1Total = 0;
    int day4Part2Total = 0;
};



#endif //DAY4_H
