//
// Created by Ben Short on 12/4/23.
//

#include "Day1.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

    void Day1::storeData(){
        std::ifstream file("/Users/short/CLionProjects/2023AOC/src/Day1Data.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file." << std::endl;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string cell;
            std::getline(ss, cell, '\n');
            calibrationData.push_back(cell);
        }
        file.close();
    }
    void Day1::convertToNumber(std::string &word) {
        if (const auto number = wordToNumber.find(word); number != wordToNumber.end()) {
            word = number->second;
        }
    }
    void Day1::partOne() {
        int total = 0;
        for (const auto& i : calibrationData) {
            a = i;
            for (auto partOneKey : partOneKeys) {
                if (auto found = a.find(partOneKey); found!=std::string::npos)
                    stringMap.try_emplace(found, partOneKey);
            }
            for (auto partOneKey : partOneKeys) {
                if (auto found = a.rfind(partOneKey); found!=std::string::npos)
                    stringMap.try_emplace(found, partOneKey);
            }
            minString = stringMap.begin()->second;
            maxString = stringMap.rbegin()->second;
            calibrationString = minString + maxString;
            calibrationValue = std::stoi(calibrationString);
            total += calibrationValue;
            stringMap.clear();
        }
            std::cout << "Part One Total: " << total << std::endl;
    }
    void Day1::partTwo() {
        int total = 0;
        for (const auto& a : calibrationData) {
            for (auto partTwoKey : partTwoKeys) {
                if (const auto found = a.find(partTwoKey); found!=std::string::npos)
                    stringMap.try_emplace(found, partTwoKey);
            }
            for (auto partTwoKey : partTwoKeys) {
                if (const auto found = a.rfind(partTwoKey); found!=std::string::npos)
                    stringMap.try_emplace(found, partTwoKey);
            }
            minString = stringMap.begin()->second;
            maxString = stringMap.rbegin()->second;
            convertToNumber(minString);
            convertToNumber(maxString);
            calibrationString = minString + maxString;
            calibrationValue = std::stoi(calibrationString);
            total += calibrationValue;
            stringMap.clear();
        }
        std::cout << "Part Two Total: " << total << std::endl;
    }
    void Day1::runDay1(){
        Day1 day1;
        day1.storeData();
        day1.partOne();
        day1.partTwo();
    }

