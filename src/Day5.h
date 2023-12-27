//
// Created by Ben Short on 12/16/23.
//

#ifndef DAY5_H
#define DAY5_H
#include <vector>


class Day5 {
public:
    void getData();
    void parseOne();
    virtual void matchNumbers(unsigned long keyNumber, std::vector<std::string> inputConvert);

    void reverseMatchNumbers(unsigned long keyNumber, std::vector<std::string> inputConvert);

    void matchLocation(unsigned long keyNumber, std::vector<std::string> inputConvert);

    void reverseMatchLocation(unsigned long keyNumber, std::vector<std::string> inputConvert);

    void parseSeeds();

    void findLocation();

    void parseSeeds2();

    void findLocation2();

    void reverseFindLocation2();

    void lowestLocation();

    void lowestLocation2();

    void clearData();

    static void runDay5();

    std::vector<unsigned long int> locationData;
    std::vector<unsigned long int> destinationKeys;
    int amountOfKeys = -1;

    std::vector<std::string> theAlmanac;
    std::vector<std::string> theAlmanacParsed;

    std::vector<unsigned long int> seedsParsed;
    std::vector<unsigned long int> seedsParsed2;

    std::vector<std::string> seedList;
    std::vector<std::string> seedToSoil;
    std::vector<std::string> soilToFertilizer;
    std::vector<std::string> fertilizerToWater;
    std::vector<std::string> waterToLight;
    std::vector<std::string> lightToTemperature;
    std::vector<std::string> temperatureToHumidity;
    std::vector<std::string> humidityToLocation;

};



#endif //DAY5_H
