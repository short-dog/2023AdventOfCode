//
// Created by Ben Short on 12/16/23.
//

#include "Day4.h"

#include <fstream>
#include <iostream>
#include <sstream>
//winning numbers | numbers you have
//first match is one point, each next doubles points : per card

void Day4::getData() {
    std::ifstream file ("/Users/short/CLionProjects/2023AOC/src/Day4Data.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;
        std::getline(ss, cell, '\n');
        gameData.push_back(cell);
    }
    file.close();
}
void Day4::partOne() {
    for (int i = 0; i < size(gameData); i++) {
        std::string currentString = gameData[i];
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> parseList;
        std::vector<std::string> secondParseList;
        std::vector<int> myNumbers;
        std::vector<int> winningNumbers;

        while(std::getline(parseString, stringParse, ':')){
            parseList.push_back(stringParse);
        }
        std::string secondParse = parseList[1];
        std::stringstream secondParseStream(secondParse);
        std::string secondStringParse;
        while(std::getline(secondParseStream, secondStringParse, '|')){
            secondParseList.push_back(secondStringParse);
        }
        std::string thirdParse = secondParseList[1];
        std::stringstream thirdParseStream(thirdParse);
        std::string thirdStringParse;
        while(std::getline(thirdParseStream, thirdStringParse, ' ')){
            if (thirdStringParse != "") {
                myNumbers.push_back(std::stoi(thirdStringParse));
            }
        }
        std::string fourthParse = secondParseList[0];
        std::stringstream fourthParseStream(fourthParse);
        std::string fourthStringParse;
        while(std::getline(fourthParseStream, fourthStringParse, ' ')){
            if (fourthStringParse != "") {
                winningNumbers.push_back(std::stoi(fourthStringParse));
            }
        }
        int numbersMatched = 0;
        for (int ii = 0; ii < size(winningNumbers); ii++) {
            for (int iii = 0; iii < size(myNumbers); iii++) {
                if(myNumbers[iii] == winningNumbers[ii]) {
                    numbersMatched++;
                }
            }
        }
        if (numbersMatched > 0) {
            int additionTotal = 1;
            numbersMatched--;
            for (int ii = 0; ii < numbersMatched; ii++) {
                additionTotal *= 2;
            }
            day4Part1Total += additionTotal;
        }
        winningNumbers.clear();
        myNumbers.clear();
    }
    std::cout << "Day 4 Part 1 Total: " << day4Part1Total << std::endl;
}
void Day4::ticketCheck(int i) {
    winningNumbers.clear();
    myNumbers.clear();
    day4Part2Total++;
    std::string currentString = gameData[i];
    std::stringstream parseString(currentString);
    std::string stringParse;
    std::vector<std::string> parseList;
    std::vector<std::string> secondParseList;
    std::vector<int> myNumbers;
    std::vector<int> winningNumbers;

    while(std::getline(parseString, stringParse, ':')){
        parseList.push_back(stringParse);
    }
    std::string secondParse = parseList[1];
    std::stringstream secondParseStream(secondParse);
    std::string secondStringParse;
    while(std::getline(secondParseStream, secondStringParse, '|')){
        secondParseList.push_back(secondStringParse);
    }
    std::string thirdParse = secondParseList[1];
    std::stringstream thirdParseStream(thirdParse);
    std::string thirdStringParse;
    while(std::getline(thirdParseStream, thirdStringParse, ' ')){
        if (thirdStringParse != "") {
            myNumbers.push_back(std::stoi(thirdStringParse));
        }
    }
    std::string fourthParse = secondParseList[0];
    std::stringstream fourthParseStream(fourthParse);
    std::string fourthStringParse;
    while(std::getline(fourthParseStream, fourthStringParse, ' ')){
        if (fourthStringParse != "") {
            winningNumbers.push_back(std::stoi(fourthStringParse));
        }
    }
    int numbersMatched = 0;
    for (int ii = 0; ii < size(winningNumbers); ii++) {
        for (int iii = 0; iii < size(myNumbers); iii++) {
            if(myNumbers[iii] == winningNumbers[ii]) {
                numbersMatched++;
            }
        }
    }
    if (numbersMatched > 0) {
        for (int ii = 1; ii < numbersMatched + 1; ii++) {
               ticketCheck(i + ii);
        }
    }
}
void Day4::partTwo() {
    for (int i = 0; i < size(gameData); i++) {
        winningNumbers.clear();
        myNumbers.clear();
        day4Part2Total++;
        std::string currentString = gameData[i];
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> parseList;
        std::vector<std::string> secondParseList;

        while(std::getline(parseString, stringParse, ':')){
            parseList.push_back(stringParse);
        }
        std::string secondParse = parseList[1];
        std::stringstream secondParseStream(secondParse);
        std::string secondStringParse;
        while(std::getline(secondParseStream, secondStringParse, '|')){
            secondParseList.push_back(secondStringParse);
        }
        std::string thirdParse = secondParseList[1];
        std::stringstream thirdParseStream(thirdParse);
        std::string thirdStringParse;
        while(std::getline(thirdParseStream, thirdStringParse, ' ')){
            if (thirdStringParse != "") {
                myNumbers.push_back(std::stoi(thirdStringParse));
            }
        }
        std::string fourthParse = secondParseList[0];
        std::stringstream fourthParseStream(fourthParse);
        std::string fourthStringParse;
        while(std::getline(fourthParseStream, fourthStringParse, ' ')){
            if (fourthStringParse != "") {
                winningNumbers.push_back(std::stoi(fourthStringParse));
            }
        }
        int numbersMatched = 0;
        for (int ii = 0; ii < size(winningNumbers); ii++) {
            for (int iii = 0; iii < size(myNumbers); iii++) {
                if(myNumbers[iii] == winningNumbers[ii]) {
                    numbersMatched++;
                }
            }
        }
        if (numbersMatched > 0) {
           for (int ii = 1; ii < numbersMatched + 1; ii++) {
               ticketCheck(i + ii);
           }
        }
    }
    std::cout << "Day 4 Part 2 Total: " << day4Part2Total << std::endl;
}
void Day4::runDay4() {
    Day4 day4;
    day4.getData();
    day4.partOne();
    day4.partTwo();
}