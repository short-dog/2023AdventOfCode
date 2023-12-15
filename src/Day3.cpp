//
// Created by Ben Short on 12/10/23.
//
#include "Day3.h"
#include <complex>
#include <fstream>
#include <iostream>
#include <sstream>

void Day3::runDay3() {
    Day3 day3;
    day3.getData();
    day3.partOne();
    day3.partTwo();
}
void Day3::getData() {
    std::ifstream file ("/Users/short/CLionProjects/2023AOC/src/Day3Data.txt");
    std::string line;
    std::stringstream fileStream;
    while (std::getline(file, line)) {
        fileStream << line;
    }
    file.close();
    engineSchematic = fileStream.str();
}
void Day3::partOne() {
    for (int i = 0; i < size(engineSchematic); i++) {
        int a = i;
        std::string enginePart;
        const char c = engineSchematic[a];
        if (c >= 48 && c <= 57) {
            enginePart += c;
            const char c = engineSchematic[a+1];
            if (c >= 48 && c <= 57) {
                i++;
                enginePart += c;
                const char c = engineSchematic[a+2];
                if (c >= 48 && c <= 57) {
                    i++;
                    enginePart += c;
                    //if part number is three digits
                    if(engineSchematic[a-141] >= 33 && engineSchematic[a-141] < 46 || engineSchematic[a-141] == 47 || engineSchematic[a-141] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-140] >= 33 && engineSchematic[a-140] < 46 || engineSchematic[a-140] == 47 || engineSchematic[a-140] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-139] >= 33 && engineSchematic[a-139] < 46 || engineSchematic[a-139] == 47 || engineSchematic[a-139] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-138] >= 33 && engineSchematic[a-138] < 46 || engineSchematic[a-138] == 47 || engineSchematic[a-138] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-137] >= 33 && engineSchematic[a-137] < 46 || engineSchematic[a-137] == 47 || engineSchematic[a-137] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-1] >= 33 && engineSchematic[a-1] < 46 || engineSchematic[a-1] == 47 || engineSchematic[a-1] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+3] >= 33 && engineSchematic[a+3] < 46 || engineSchematic[a+3] == 47 || engineSchematic[a+3] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+139] >= 33 && engineSchematic[a+139] < 46 || engineSchematic[a+139] == 47 || engineSchematic[a+139] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+140] >= 33 && engineSchematic[a+140] < 46 || engineSchematic[a+140] == 47 || engineSchematic[a+140] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+141] >= 33 && engineSchematic[a+141] < 46 || engineSchematic[a+141] == 47 || engineSchematic[a+141] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+142] >= 33 && engineSchematic[a+142] < 46 || engineSchematic[a+142] == 47 || engineSchematic[a+142] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+143] >= 33 && engineSchematic[a+143] < 46 || engineSchematic[a+143] == 47 || engineSchematic[a+143] >= 58) {
                        partOneTotal += std::stoi(enginePart);
                    }
                //if part number is two digits
                }else if(engineSchematic[a-141] >= 33 && engineSchematic[a-141] < 46 || engineSchematic[a-141] == 47 || engineSchematic[a-141] >= 58){
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-140] >= 33 && engineSchematic[a-140] < 46 || engineSchematic[a-140] == 47 || engineSchematic[a-140] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-139] >= 33 && engineSchematic[a-139] < 46 || engineSchematic[a-139] == 47 || engineSchematic[a-139] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-138] >= 33 && engineSchematic[a-138] < 46 || engineSchematic[a-138] == 47 || engineSchematic[a-138] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-1] >= 33 && engineSchematic[a-1] < 46 || engineSchematic[a-1] == 47 || engineSchematic[a-1] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+2] >= 33 && engineSchematic[a+2] < 46 || engineSchematic[a+2] == 47 || engineSchematic[a+2] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+139] >= 33 && engineSchematic[a+139] < 46 || engineSchematic[a+139] == 47 || engineSchematic[a+139] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+140] >= 33 && engineSchematic[a+140] < 46 || engineSchematic[a+140] == 47 || engineSchematic[a+140] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+141] >= 33 && engineSchematic[a+141] < 46 || engineSchematic[a+141] == 47 || engineSchematic[a+141] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+142] >= 33 && engineSchematic[a+142] < 46 || engineSchematic[a+142] == 47 || engineSchematic[a+142] >= 58) {
                    partOneTotal += std::stoi(enginePart);
                }
            //if part number is one digit
            }else if(engineSchematic[a-141] >= 33 && engineSchematic[a-141] < 46 || engineSchematic[a-141] == 47 || engineSchematic[a-141] >= 58){
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a-140] >= 33 && engineSchematic[a-140] < 46 || engineSchematic[a-140] == 47 || engineSchematic[a-140] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a-139] >= 33 && engineSchematic[a-139] < 46 || engineSchematic[a-139] == 47 || engineSchematic[a-139] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a-1] >= 33 && engineSchematic[a-1] < 46 || engineSchematic[a-1] == 47 || engineSchematic[a-1] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+1] >= 33 && engineSchematic[a+1] < 46 || engineSchematic[a+1] == 47 || engineSchematic[a+1] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+139] >= 33 && engineSchematic[a+139] < 46 || engineSchematic[a+139] == 47 || engineSchematic[a+139] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+140] >= 33 && engineSchematic[a+140] < 46 || engineSchematic[a+140] == 47 || engineSchematic[a+140] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+141] >= 33 && engineSchematic[a+141] < 46 || engineSchematic[a+141] == 47 || engineSchematic[a+141] >= 58) {
                partOneTotal += std::stoi(enginePart);
            }
        }
    }
    std::cout << "Day 3 Part 2 Total: " << partOneTotal << std::endl;
}
void Day3::partTwo() {
    for (int i = 0; i < size(engineSchematic); i++) {
        int a = i;
        const char c = engineSchematic[a];
        if (c == 42) {
            //char = 42
            std::string enginePart;
            std::string first;
            std::string second;
            std::string third;
            bool middleNumConfirm = false;
            //start
            //top row
            if(engineSchematic[a-141] >= 48 && engineSchematic[a-141] <= 57) {
                first = engineSchematic[a-141];
                //main
                if(engineSchematic[a-142] >= 48 && engineSchematic[a-142] <= 57) {
                    second = engineSchematic[a-142];
                    //left 1
                    if(engineSchematic[a-143] >= 48 && engineSchematic[a-143] <= 57) {
                        third = engineSchematic[a-143]; //left 2
                        enginePart = third + second + first;
                        engineParts.push_back(enginePart);
                    }else if(engineSchematic[a-140] >= 48 && engineSchematic[a-140] <= 57) {
                        third = engineSchematic[a-140];  //cross over to check for third number : right 1
                        middleNumConfirm = true;
                        enginePart = second + first + third;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = second + first;
                        engineParts.push_back(enginePart);
                    }
                }else if(engineSchematic[a-140] >= 48 && engineSchematic[a-140] <= 57) {
                    second = engineSchematic[a-140]; //right 1
                    middleNumConfirm = true;
                    if(engineSchematic[a-139] >= 48 && engineSchematic[a-139] <= 57){
                        third = engineSchematic[a-139]; //right 2
                        enginePart = first + second + third;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = first + second;
                        engineParts.push_back(enginePart);
                    }
                }else {
                    engineParts.push_back(first);
                }
            }
            if(middleNumConfirm == false && engineSchematic[a-139] >= 48 && engineSchematic[a-139] <= 57) {
                first = engineSchematic[a-139];
                //main
                if(engineSchematic[a-138] >= 48 && engineSchematic[a-138] <= 57) {
                    second = engineSchematic[a-138];
                    //right 1
                    if(engineSchematic[a-137] >= 48 && engineSchematic[a-137] <= 57) {
                        third = engineSchematic[a-137]; //right 2
                        enginePart = first + second + third;
                        engineParts.push_back(enginePart);
                    }else if(engineSchematic[a-140] >= 48 && engineSchematic[a-140] <= 57){
                        third = engineSchematic[a-140];
                        enginePart = third + first + second;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = first + second;
                        engineParts.push_back(enginePart);
                    }
                }else if(engineSchematic[a-140] >= 48 && engineSchematic[a-140] <= 57) {
                    second = engineSchematic[a-140];
                    enginePart = second + first;
                    engineParts.push_back(enginePart);
                }else {
                    engineParts.push_back(first);
                }
            }else if( middleNumConfirm == false && engineSchematic[a-140] >= 48 && engineSchematic[a-140] <= 57 ) {
                first = engineSchematic[a-140];
                engineParts.push_back(first);
            }
            //adjacent to the left
            if(engineSchematic[a-1] >= 48 && engineSchematic[a-1] <= 57) {
                first = engineSchematic[a-1];
                //main
                if(engineSchematic[a-2] >= 48 && engineSchematic[a-2] <= 57) {
                    second = engineSchematic[a-2];
                    //left 1
                    if(engineSchematic[a-3] >= 48 && engineSchematic[a-3] <= 57) {
                        third = engineSchematic[a-3]; //left 2
                        enginePart = third + second + first;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = second + first;
                        engineParts.push_back(enginePart);
                    }
                }else {
                    engineParts.push_back(first);
                }
            }
            //adjacent to the right
            if(engineSchematic[a+1] >= 48 && engineSchematic[a+1] <= 57) {
                first = engineSchematic[a+1];
                //main
                if(engineSchematic[a+2] >= 48 && engineSchematic[a+2] <= 57) {
                    second = engineSchematic[a+2];
                    //left 1
                    if(engineSchematic[a+3] >= 48 && engineSchematic[a+3] <= 57) {
                        third = engineSchematic[a+3]; //left 2
                        enginePart = first + second + third;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = first + second;
                        engineParts.push_back(enginePart);
                    }
                }else {
                    engineParts.push_back(first);
                }
            }
            //bottom row
            middleNumConfirm = false;
            if(engineSchematic[a+139] >= 48 && engineSchematic[a+139] <= 57) {
                first = engineSchematic[a+139];
                //main
                if(engineSchematic[a+138] >= 48 && engineSchematic[a+138] <= 57) {
                    second = engineSchematic[a+138];
                    //left 1
                    if(engineSchematic[a+137] >= 48 && engineSchematic[a+137] <= 57) {
                        third = engineSchematic[a+137]; //left 2
                        enginePart = third + second + first;
                        engineParts.push_back(enginePart);
                    }else if(engineSchematic[a+140] >= 48 && engineSchematic[a+140] <= 57) {
                        third = engineSchematic[a+140];  //cross over to check for third number : right 1
                        middleNumConfirm = true;
                        enginePart = second + first + third;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = second + first;
                        engineParts.push_back(enginePart);
                    }
                }else if(engineSchematic[a+140] >= 48 && engineSchematic[a+140] <= 57) {
                    second = engineSchematic[a+140]; //right 1
                    middleNumConfirm = true;
                    if(engineSchematic[a+141] >= 48 && engineSchematic[a+141] <= 57) {
                        third = engineSchematic[a+141]; //right 2
                        enginePart = first + second + third;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = first + second;
                        engineParts.push_back(enginePart);
                    }
                }else {
                    engineParts.push_back(first);
                }
            }
            if(middleNumConfirm == false && engineSchematic[a+141] >= 48 && engineSchematic[a+141] <= 57) {
                first = engineSchematic[a+141];
                //main
                if(engineSchematic[a+142] >= 48 && engineSchematic[a+142] <= 57) {
                    second = engineSchematic[a+142];
                    //right 1
                    if(engineSchematic[a+143] >= 48 && engineSchematic[a+143] <= 57) {
                        third = engineSchematic[a+143]; //right 2
                        enginePart = first + second + third;
                        engineParts.push_back(enginePart);
                    }else if(engineSchematic[a+140] >= 48 && engineSchematic[a+140] <= 57) {
                        third = engineSchematic[a+140];
                        enginePart = third + first + second;
                        engineParts.push_back(enginePart);
                    }else {
                        enginePart = first + second;
                        engineParts.push_back(enginePart);
                    }
                }else if(engineSchematic[a+140] >= 48 && engineSchematic[a+140] <= 57) {
                    second = engineSchematic[a+140];
                    enginePart = second + first;
                    engineParts.push_back(enginePart);
                }
                else {
                    engineParts.push_back(first);
                }
            }else if(middleNumConfirm == false && engineSchematic[a+140] >= 48 && engineSchematic[a+140] <= 57) {
                first = engineSchematic[a+140];
                engineParts.push_back(first);
            }
            if(size(engineParts) == 2) {
                std::string stringOne = engineParts[0];
                std::string stringTwo = engineParts[1];
                int gearRatio = std::stoi(stringOne) * std::stoi(stringTwo);
                partTwoTotal += gearRatio;
            }
            engineParts.clear();
        }
    }
    std::cout << "Day 3 Part 2 Total: " << partTwoTotal << std::endl;
}