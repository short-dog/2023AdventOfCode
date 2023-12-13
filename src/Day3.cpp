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
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-140] >= 33 && engineSchematic[a-140] < 46 || engineSchematic[a-140] == 47 || engineSchematic[a-140] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-139] >= 33 && engineSchematic[a-139] < 46 || engineSchematic[a-139] == 47 || engineSchematic[a-139] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-138] >= 33 && engineSchematic[a-138] < 46 || engineSchematic[a-138] == 47 || engineSchematic[a-138] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-137] >= 33 && engineSchematic[a-137] < 46 || engineSchematic[a-137] == 47 || engineSchematic[a-137] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a-1] >= 33 && engineSchematic[a-1] < 46 || engineSchematic[a-1] == 47 || engineSchematic[a-1] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+3] >= 33 && engineSchematic[a+3] < 46 || engineSchematic[a+3] == 47 || engineSchematic[a+3] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+139] >= 33 && engineSchematic[a+139] < 46 || engineSchematic[a+139] == 47 || engineSchematic[a+139] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+140] >= 33 && engineSchematic[a+140] < 46 || engineSchematic[a+140] == 47 || engineSchematic[a+140] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+141] >= 33 && engineSchematic[a+141] < 46 || engineSchematic[a+141] == 47 || engineSchematic[a+141] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+142] >= 33 && engineSchematic[a+142] < 46 || engineSchematic[a+142] == 47 || engineSchematic[a+142] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }else if(engineSchematic[a+143] >= 33 && engineSchematic[a+143] < 46 || engineSchematic[a+143] == 47 || engineSchematic[a+143] >= 58) {
                        std::cout << "engine part: " << enginePart << std::endl;
                        partOneTotal += std::stoi(enginePart);
                    }
                //if part number is two digits
                }else if(engineSchematic[a-141] >= 33 && engineSchematic[a-141] < 46 || engineSchematic[a-141] == 47 || engineSchematic[a-141] >= 58){
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-140] >= 33 && engineSchematic[a-140] < 46 || engineSchematic[a-140] == 47 || engineSchematic[a-140] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-139] >= 33 && engineSchematic[a-139] < 46 || engineSchematic[a-139] == 47 || engineSchematic[a-139] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-138] >= 33 && engineSchematic[a-138] < 46 || engineSchematic[a-138] == 47 || engineSchematic[a-138] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a-1] >= 33 && engineSchematic[a-1] < 46 || engineSchematic[a-1] == 47 || engineSchematic[a-1] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+2] >= 33 && engineSchematic[a+2] < 46 || engineSchematic[a+2] == 47 || engineSchematic[a+2] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+139] >= 33 && engineSchematic[a+139] < 46 || engineSchematic[a+139] == 47 || engineSchematic[a+139] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+140] >= 33 && engineSchematic[a+140] < 46 || engineSchematic[a+140] == 47 || engineSchematic[a+140] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+141] >= 33 && engineSchematic[a+141] < 46 || engineSchematic[a+141] == 47 || engineSchematic[a+141] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }else if(engineSchematic[a+142] >= 33 && engineSchematic[a+142] < 46 || engineSchematic[a+142] == 47 || engineSchematic[a+142] >= 58) {
                    std::cout << "engine part: " << enginePart << std::endl;
                    partOneTotal += std::stoi(enginePart);
                }
            //if part number is one digit
            }else if(engineSchematic[a-141] >= 33 && engineSchematic[a-141] < 46 || engineSchematic[a-141] == 47 || engineSchematic[a-141] >= 58){
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a-140] >= 33 && engineSchematic[a-140] < 46 || engineSchematic[a-140] == 47 || engineSchematic[a-140] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a-139] >= 33 && engineSchematic[a-139] < 46 || engineSchematic[a-139] == 47 || engineSchematic[a-139] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a-1] >= 33 && engineSchematic[a-1] < 46 || engineSchematic[a-1] == 47 || engineSchematic[a-1] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+1] >= 33 && engineSchematic[a+1] < 46 || engineSchematic[a+1] == 47 || engineSchematic[a+1] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+139] >= 33 && engineSchematic[a+139] < 46 || engineSchematic[a+139] == 47 || engineSchematic[a+139] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+140] >= 33 && engineSchematic[a+140] < 46 || engineSchematic[a+140] == 47 || engineSchematic[a+140] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }else if(engineSchematic[a+141] >= 33 && engineSchematic[a+141] < 46 || engineSchematic[a+141] == 47 || engineSchematic[a+141] >= 58) {
                std::cout << "engine part: " << enginePart << std::endl;
                partOneTotal += std::stoi(enginePart);
            }
        }
    }
    std::cout << "Day 3 Part One Total: " << partOneTotal << std::endl;
}
