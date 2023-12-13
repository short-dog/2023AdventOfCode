//
// Created by Ben Short on 12/4/23.
//

#ifndef DAY1_H
#define DAY1_H
#include <map>
#include <string>
#include <vector>

class Day1 {
public:
    static void runDay1();

private:
    void storeData();

    void convertToNumber(std::string&word);

    void partOne();

    void partTwo();

    std::string minString = "min";
    std::string maxString = "max";
    std::string a = "empty";
    std::string calibrationString = "empty";

    int calibrationValue = 0;


    std::vector<std::string> calibrationData;
    std::vector<std::string> partOneKeys = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<std::string> partTwoKeys = {"1", "2", "3", "4", "5", "6", "7", "8", "9",
        "one", "two", "three", "four", "five", "six","seven", "eight", "nine"};

    std::map<size_t, std::string> stringMap;
    const std::map<std::string, std::string> wordToNumber = {
        {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
        {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

};



#endif //DAY1_H
