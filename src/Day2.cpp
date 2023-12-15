//
// Created by Ben Short on 12/9/23.
//

#include "Day2.h"

#include <fstream>
#include <iostream>
#include <sstream>

void Day2::getData() {
    std::ifstream file ("/Users/short/CLionProjects/2023AOC/src/Day2Data.txt");
    while(!file.is_open()) {
        std::cerr << "File error." << std::endl;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;
        std::getline(ss, cell, '\n');
        gameData.push_back(cell);
    }
    file.close();
}
void Day2::parseDataPart1() {
    for (int i = 0; i < size(gameData); i++) {
        std::string currentString = gameData[i];
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> successfulGames;
        std::vector<std::string> parseList;
        std::vector<std::string> secondParseList;
        std::vector<std::string> thirdParseList;
        std::vector<std::string> fourthParseList;

        while(std::getline(parseString, stringParse, ':')){
            parseList.push_back(stringParse);
        }
        std::string secondParse = parseList[1];
        std::stringstream secondParseStream(secondParse);
        std::string secondStringParse;
        while(std::getline(secondParseStream, secondStringParse, ';')){
            secondParseList.push_back(secondStringParse);
        }
        for (int ii = 0; ii < size(secondParseList); ii++){
            std::string thirdParse = secondParseList[ii];
            std::stringstream thirdParseStream(thirdParse);
            std::string thirdStringParse;
            while(std::getline(thirdParseStream, thirdStringParse, ',')){
                thirdParseList.push_back(thirdStringParse);
            }
        }
        for (int iii = 0; iii < size(thirdParseList); iii++){
            std::string fourthParse = thirdParseList[iii];
            std::stringstream fourthParseStream(fourthParse);
            std::string fourthStringParse;
            while(std::getline(fourthParseStream, fourthStringParse, ' ')){
                fourthParseList.push_back(fourthStringParse);
            }
            int numCubes = std::stoi(fourthParseList[1]);
            std::string cubeColor = fourthParseList[2];

            if(auto match = cubeBag.find(cubeColor); match->second >= numCubes){
                successfulGames.push_back(parseList[0]);
            }
            fourthParseList.clear();
        }
        if (size(successfulGames) == size(thirdParseList)) {
            gamesSucceeded.push_back(parseList[0]);
        }
    }
}
void Day2::parseDataPart2() {
    for (int i = 0; i < size(gameData); i++) {
        std::string currentString = gameData[i];
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> successfulGames;
        std::vector<std::string> parseList;
        std::vector<std::string> secondParseList;
        std::vector<std::string> thirdParseList;
        std::vector<std::string> fourthParseList;

        while(std::getline(parseString, stringParse, ':')){
            parseList.push_back(stringParse);
        }
        std::string secondParse = parseList[1];
        std::stringstream secondParseStream(secondParse);
        std::string secondStringParse;
        while(std::getline(secondParseStream, secondStringParse, ';')){
            secondParseList.push_back(secondStringParse);
        }
        for (int ii = 0; ii < size(secondParseList); ii++){
            std::string thirdParse = secondParseList[ii];
            std::stringstream thirdParseStream(thirdParse);
            std::string thirdStringParse;
            while(std::getline(thirdParseStream, thirdStringParse, ',')){
                thirdParseList.push_back(thirdStringParse);
            }
        }
        for (int iii = 0; iii < size(thirdParseList); iii++){
            std::string fourthParse = thirdParseList[iii];
            std::stringstream fourthParseStream(fourthParse);
            std::string fourthStringParse;
            while(std::getline(fourthParseStream, fourthStringParse, ' ')){
                fourthParseList.push_back(fourthStringParse);
            }

            int numCubes = std::stoi(fourthParseList[1]);
            std::string cubeColor = fourthParseList[2];
            auto currentHighNum = cubesNeeded.find(cubeColor);

            if(currentHighNum->second < numCubes) {
                cubesNeeded.erase(cubeColor);
                cubesNeeded.try_emplace(cubeColor, numCubes);
            }

            if(auto match = cubeBag.find(cubeColor); match->second >= numCubes){
                successfulGames.push_back(parseList[0]);
            }
            fourthParseList.clear();
        }
        if (size(successfulGames) == size(thirdParseList)) {
            gamesSucceeded.push_back(parseList[0]);
        }
        calcCubesNeeded();
    }
}
void Day2::processPart1() {
    for (int i = 0; i < size(gamesSucceeded); i++) {
        std::string gameParse = gamesSucceeded[i];
        std::stringstream gameParseStream(gameParse);
        std::string gameStringParse;
        while(std::getline(gameParseStream, gameStringParse, ' ')){
            gameParseList.push_back(gameStringParse);
        }
    }
    for (int i = 0; i < size(gameParseList); i++) {
        if (i % 2 != 0) {
            total += std::stoi(gameParseList[i]);
        }
    }
}
void Day2::clearData() {
    gamesSucceeded.clear();
    gameParseList.clear();
}
void Day2::printTotal() {
    std::cout << "Day 2 Part 1 Result: " << total << std::endl;
    std::cout << "Day 2 Part 2 Result: " << total2 << std::endl;
}
void Day2::calcCubesNeeded() {
    int redNeeded = (cubesNeeded.find("red")->second);
    int greenNeeded = (cubesNeeded.find("green")->second);
    int blueNeeded = (cubesNeeded.find("blue")->second);
    int cubePower = redNeeded * greenNeeded * blueNeeded;
    total2 += cubePower;
    cubesNeeded.clear();
    cubesNeeded = {{"red", 0}, {"green", 0}, {"blue", 0}};
}
void Day2::runDay2() {
    Day2 day2;
    day2.getData();
    day2.parseDataPart1();
    day2.processPart1();
    day2.clearData();
    day2.parseDataPart2();
    day2.printTotal();
}
