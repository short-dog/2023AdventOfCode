//
// Created by Ben Short on 1/3/24.
//
#include "Day8.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Day8::runDay8() {
    Day8 day8;
    day8.getData();
    day8.partOne();
    day8.partTwo();
}
void Day8::getData() {
    std::ifstream file ("/Users/short/CLionProjects/2023AOC/src/Day8Data.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;
        std::getline(ss, cell, '\n');
        gameData.push_back(cell);
    }
    std::string parse = gameData[0];
    for (int i = 0; i < size(parse); i++){
        char parseChar = parse[i];
        directions.push_back(parseChar);
    }
    for (int i = 2; i < size(gameData); i++) {
        std::string currentLine = gameData[i];
        std::istringstream ss(currentLine);
        std::string cell;
        std::getline(ss, cell, ' ');
        origin.push_back(cell);
        originMap.emplace(cell,i-2);
    }
    for (int i = 2; i < size(gameData); i++) {
        std::string currentLine = gameData[i];
        char firstNum = currentLine[7];
        std::string first;
        first = firstNum;
        char midNum = currentLine[8];
        std::string mid;
        mid = midNum;
        char lastNum = currentLine[9];
        std::string last;
        last = lastNum;
        std::string parseL = "";
        parseL += first += mid += last;
        destinationL.push_back(parseL);
    }
    for (int i = 2; i < size(gameData); i++) {
        std::string currentLine = gameData[i];
        char firstNum = currentLine[12];
        std::string first;
        first = firstNum;
        char midNum = currentLine[13];
        std::string mid;
        mid = midNum;
        char lastNum = currentLine[14];
        std::string last;
        last = lastNum;
        std::string parseR = "";
        parseR += first += mid += last;
        destinationR.push_back(parseR);
    }
    file.close();
    for (int i = 0; i < size(destinationL); i++) {
        std::pair destinationPair = {destinationL[i],destinationR[i]};
        destinationPairs.push_back(destinationPair);
    }
}
void Day8::partOne() {
    std::string currentOrigin = origin[0];
    for (int i = 0; i < size(directions); i++) {
        char currentDirection = directions[i];
        int destinationKey = originMap.find(currentOrigin)->second;
        if (currentDirection == 'L') {
            currentOrigin = destinationPairs[destinationKey].first;
        }else if (currentDirection == 'R') {
            currentOrigin = destinationPairs[destinationKey].second;
        }
        //std::cout << currentOrigin << std::endl;
        totalTravelPart1++;
        //std::cout << totalTravelPart1 << std::endl;
        if (currentOrigin == "ZZZ") {
            break;
        }
        if (i == size(directions) - 1){
            i = 0;
        }
    }
    std::cout << totalTravelPart1 << std::endl;
}
void Day8::partTwo(){}