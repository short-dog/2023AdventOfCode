//
// Created by Ben Short on 12/16/23.
//
#include "Day5.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
// destination source range

void Day5::getData() {
    std::ifstream file ("/Users/short/CLionProjects/2023AOC/src/Day5Data.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;
        std::getline(ss, cell, '\n');
        theAlmanac.push_back(cell);
    }
    file.close();
}
void Day5::parseOne() {
    for (const auto& currentString : theAlmanac) {
        std::stringstream parseString(currentString);
        std::string stringParse;
        while(std::getline(parseString, stringParse, '\n')){
            theAlmanacParsed.push_back(stringParse);
        }
    }
    seedList.push_back(theAlmanacParsed[1]);
    for (int i = 3; i < 29; i++ ) {
        seedToSoil.push_back(theAlmanacParsed[i]);
    }
    for (int i = 31; i < 50; i++ ) {
        soilToFertilizer.push_back(theAlmanacParsed[i]);
    }
    for (int i = 52; i < 99; i++ ) {
        fertilizerToWater.push_back(theAlmanacParsed[i]);
    }
    for (int i = 101; i < 142; i++ ) {
        waterToLight.push_back(theAlmanacParsed[i]);
    }
    for (int i = 144; i < 167; i++ ) {
        lightToTemperature.push_back(theAlmanacParsed[i]);
    }
    for (int i = 169; i < 193; i++ ) {
        temperatureToHumidity.push_back(theAlmanacParsed[i]);
    }
    for (int i = 195; i < 231; i++ ) {
        humidityToLocation.push_back(theAlmanacParsed[i]);
    }
/*
    for (int i = 3; i < 5; i++ ) {
        seedToSoil.push_back(theAlmanacParsed[i]);
    }
    for (int i = 6; i < 9; i++ ) {
        soilToFertilizer.push_back(theAlmanacParsed[i]);
    }
    for (int i = 10; i < 14; i++ ) {
        fertilizerToWater.push_back(theAlmanacParsed[i]);
    }
    for (int i = 15; i < 17; i++ ) {
        waterToLight.push_back(theAlmanacParsed[i]);
    }
    for (int i = 18; i < 21; i++ ) {
        lightToTemperature.push_back(theAlmanacParsed[i]);
    }
    for (int i = 22; i < 24; i++ ) {
        temperatureToHumidity.push_back(theAlmanacParsed[i]);
    }
    for (int i = 25; i < 27; i++ ) {
        humidityToLocation.push_back(theAlmanacParsed[i]);
    }*/
}
void Day5::matchNumbers(unsigned long int keyNumber, std::vector<std::string> inputConvert) {
    bool keyConfirm = false;
    for (const auto& currentString : inputConvert) {
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> destinationSourceRange;
        while(std::getline(parseString, stringParse, ' ')){
            if(!stringParse.empty()) {
                destinationSourceRange.push_back(stringParse);
            }
        }
        unsigned long int rangeBegin = std::stoul(destinationSourceRange[1]);
        unsigned long int rangeEnd = rangeBegin + std::stoul(destinationSourceRange[2]) - 1;
        if(rangeBegin <= keyNumber && keyNumber <= rangeEnd) {
            unsigned long int destinationKey = std::stoul(destinationSourceRange[0]) + (keyNumber -  rangeBegin);
            destinationKeys.push_back(destinationKey);
            amountOfKeys++;
            keyConfirm = true;
            break;
        }
    }
    if(keyConfirm == false){destinationKeys.push_back(keyNumber); amountOfKeys++;}
}
void Day5::reverseMatchNumbers(unsigned long int keyNumber, std::vector<std::string> inputConvert) {
    bool keyConfirm = false;
    for (const auto& currentString : inputConvert) {
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> destinationSourceRange;
        while(std::getline(parseString, stringParse, ' ')){
            if(!stringParse.empty()) {
                destinationSourceRange.push_back(stringParse);
            }
        }
        unsigned long int rangeBegin = std::stoul(destinationSourceRange[1]);
        unsigned long int sourceRangeBegin = std::stoul(destinationSourceRange[0]);
        unsigned long int rangeEnd = rangeBegin + std::stoul(destinationSourceRange[2]) - 1;
        unsigned long int sourceRangeEnd = sourceRangeBegin + std::stoul(destinationSourceRange[2]) - 1;
        auto sourceKey = keyNumber - std::stoul(destinationSourceRange[0]) - rangeBegin;
        if(sourceRangeBegin <= sourceKey && sourceKey <= sourceRangeEnd) {
            destinationKeys.push_back(sourceKey);
            amountOfKeys++;
            keyConfirm = true;
            break;
        }
    }
    if(keyConfirm == false){destinationKeys.push_back(keyNumber); amountOfKeys++;}
}
void Day5::matchLocation(unsigned long int keyNumber, std::vector<std::string> inputConvert) {
    bool keyConfirm = false;
    for (const auto& currentString : inputConvert) {
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<unsigned long int> destinationSourceRange;
        while(std::getline(parseString, stringParse, ' ')){
            if(!stringParse.empty()) {
                destinationSourceRange.push_back(std::stoul(stringParse));
            }
        }
        unsigned long int rangeBegin = destinationSourceRange[1];
        unsigned long int rangeEnd = rangeBegin + destinationSourceRange[2] - 1;
        if(rangeBegin <= keyNumber && keyNumber <= rangeEnd) {
            unsigned long int destinationKey = destinationSourceRange[0] + (keyNumber - rangeBegin);
            locationData.push_back(destinationKey);
            keyConfirm = true;
        }
    }
    if (keyConfirm == false){locationData.push_back(keyNumber);
    }
}
void Day5::reverseMatchLocation(unsigned long int keyNumber, std::vector<std::string> inputConvert) {
    bool keyConfirm = false;
    for (auto currentString : inputConvert) {
        std::stringstream parseString(currentString);
        std::string stringParse;
        std::vector<std::string> destinationSourceRange;
        while(std::getline(parseString, stringParse, ' ')){
            if(!stringParse.empty()) {
                destinationSourceRange.push_back(stringParse);
            }
        }
        unsigned long int rangeBegin = std::stoul(destinationSourceRange[1]);
        unsigned long int sourceRangeBegin = std::stoul(destinationSourceRange[0]);
        unsigned long int rangeEnd = rangeBegin + std::stoul(destinationSourceRange[2]) - 1;
        unsigned long int sourceRangeEnd = sourceRangeBegin + std::stoul(destinationSourceRange[2]) - 1;
        auto sourceKey = keyNumber - std::stoul(destinationSourceRange[0]) - rangeBegin;
        if(sourceRangeBegin <= sourceKey && sourceKey <= sourceRangeEnd) {
            destinationKeys.push_back(sourceKey);
            amountOfKeys++;
        }
    }
    if (keyConfirm == false){locationData.push_back(keyNumber);
    }
}
void Day5::parseSeeds() {
    // destination source range
    //parse seeds
    std::string currentString = seedList[0];
    std::stringstream parseString(currentString);
    std::string stringParse;
    while(std::getline(parseString, stringParse, ' ')){
        if(stringParse != " ") {
            seedsParsed.push_back(std::stoul(stringParse));
        }
    }
}
void Day5::findLocation() {
    for (int i = 0; i < size(seedsParsed); i++) {
        auto currentSeed = seedsParsed[i];
        matchNumbers(currentSeed, seedToSoil);
        matchNumbers(destinationKeys[amountOfKeys], soilToFertilizer);
        matchNumbers(destinationKeys[amountOfKeys], fertilizerToWater);
        matchNumbers(destinationKeys[amountOfKeys], waterToLight);
        matchNumbers(destinationKeys[amountOfKeys], lightToTemperature);
        matchNumbers(destinationKeys[amountOfKeys], temperatureToHumidity);
        matchLocation(destinationKeys[amountOfKeys], humidityToLocation);
    }
}
void Day5::parseSeeds2() {
    for (int i = 0; i < size(seedsParsed); i+=2) {
        unsigned long int rangeBegin = seedsParsed[i];
        unsigned long int rangeEnd = rangeBegin + seedsParsed[i+1];
        for (unsigned long int ii = rangeBegin; ii < rangeEnd; ii++){
            seedsParsed2.push_back(seedsParsed[ii]);
        }
    }
}
void Day5::findLocation2() {
    for (int i = 0; i < size(seedsParsed2); i++) {
            auto currentSeed = seedsParsed2[i];
            matchNumbers(currentSeed, seedToSoil);
            matchNumbers(destinationKeys[amountOfKeys], soilToFertilizer);
            matchNumbers(destinationKeys[amountOfKeys], fertilizerToWater);
            matchNumbers(destinationKeys[amountOfKeys], waterToLight);
            matchNumbers(destinationKeys[amountOfKeys], lightToTemperature);
            matchNumbers(destinationKeys[amountOfKeys], temperatureToHumidity);
            matchLocation(destinationKeys[amountOfKeys], humidityToLocation);
    }
}
void Day5::reverseFindLocation2() {
    for (int i = 0; i < size(seedsParsed2); i++) {
            auto currentSeed = i;
            reverseMatchLocation(destinationKeys[amountOfKeys], humidityToLocation);
            reverseMatchNumbers(destinationKeys[amountOfKeys], temperatureToHumidity);
            reverseMatchNumbers(destinationKeys[amountOfKeys], lightToTemperature);
            reverseMatchNumbers(destinationKeys[amountOfKeys], waterToLight);
            reverseMatchNumbers(destinationKeys[amountOfKeys], fertilizerToWater);
            reverseMatchNumbers(destinationKeys[amountOfKeys], soilToFertilizer);
            reverseMatchNumbers(currentSeed, seedToSoil);
    }
}
void Day5::lowestLocation() {
    std::ranges::sort(locationData);
    std::cout << "Part One Lowest location: " << std::fixed << std::setprecision(0) << locationData[0] << std::endl;
}
void Day5::lowestLocation2() {
    std::ranges::sort(locationData);
    std::cout << "Part Two Lowest location: " << std::fixed << std::setprecision(0) << locationData[0] << std::endl;
}
void Day5::clearData() {
    locationData.clear();
    destinationKeys.clear();
    amountOfKeys = -1;
}
void Day5::runDay5() {
    Day5 day5;
    day5.getData();
    day5.parseOne();
    day5.parseSeeds();
    day5.findLocation();
    day5.lowestLocation();
    day5.clearData();
    day5.parseSeeds2();
    day5.reverseFindLocation2();
    day5.lowestLocation2();
}
//564145194