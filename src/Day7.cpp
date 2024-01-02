//
// Created by Ben Short on 12/22/23.
//
#include "Day7.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <__algorithm/ranges_sort.h>
int cardsAccounted = 0;
void Day7::runDay7() {
    Day7 day7;
    day7.getData();
    day7.partOne();
    day7.partTwo();
}
void Day7::getData() {
    std::ifstream file ("/Users/short/CLionProjects/2023AOC/src/Day7Data.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;
        std::getline(ss, cell, '\n');
        gameData.push_back(cell);
    }
    for (int i = 0; i < size(gameData); i++){
        std::string parse = gameData[i];
        std::stringstream parseStream(parse);
        std::string parseString;
        while(std::getline(parseStream, parseString, ' ')){
            parseList.push_back(parseString);
        }
        hands.push_back(parseList[0]);
        bids.push_back(std::stoi(parseList[1]));
        parseList.clear();
    }
    file.close();
}
long assignPoint(int currentCard, long points) {
    long score = 0;
    if (currentCard > 0) {
        if (cardsAccounted == 0) {
            score += points * 100'000'000;
        }else if (cardsAccounted == 1) {
            score += points * 1'000'000;
        }else if (cardsAccounted == 2) {
            score += points * 10'000;
        }else if (cardsAccounted == 3) {
            score += points * 100;
        }else if (cardsAccounted == 4) {
            score += points;
        }
        cardsAccounted++;
    }
    return score;
}
void Day7::partOne() {
    for (int i = 0; i < hands.size(); i++) {
        std::string currentHand = hands[i];
        long currentRank = 0;
        int A = 0; int K = 0; int Q = 0; int J = 0; int T = 0;
        int nine = 0; int eight = 0; int seven = 0; int six = 0;
        int five = 0; int four = 0; int three = 0; int two = 0;
        for (int ii = 0; ii < currentHand.length(); ii++) {
            if (const char currentCard = currentHand[ii]; currentCard == 'A') {
                A++;
            }else if (currentCard == 'K') {
                K++;
            }else if (currentCard == 'Q') {
                Q++;
            }else if (currentCard == 'J') {
                J++;
            }else if (currentCard == 'T') {
                T++;
            }else if (currentCard == '9') {
                nine++;
            }else if (currentCard == '8') {
                eight++;
            }else if (currentCard == '7') {
                seven++;
            }else if (currentCard == '6') {
                six++;
            }else if (currentCard == '5') {
                five++;
            }else if (currentCard == '4') {
                four++;
            }else if (currentCard == '3') {
                three++;
            }else if (currentCard == '2') {
                two++;
            }
        }
        currentHandTotals.push_back(A);
        currentHandTotals.push_back(K);
        currentHandTotals.push_back(Q);
        currentHandTotals.push_back(J);
        currentHandTotals.push_back(T);
        currentHandTotals.push_back(nine);
        currentHandTotals.push_back(eight);
        currentHandTotals.push_back(seven);
        currentHandTotals.push_back(six);
        currentHandTotals.push_back(five);
        currentHandTotals.push_back(four);
        currentHandTotals.push_back(three);
        currentHandTotals.push_back(two);
        std::ranges::sort(currentHandTotals);
        std::reverse(currentHandTotals.begin(),currentHandTotals.end());
        if (currentHandTotals[0] == 5) {
            currentRank += 70000000000;
        }else if (currentHandTotals[0] == 4) {
            currentRank += 60000000000;
        }else if (currentHandTotals[0] == 3 && currentHandTotals[1] == 2) {
            currentRank += 50000000000;
        }else if (currentHandTotals[0] == 3 && currentHandTotals[1] == 1) {
            currentRank += 40000000000;
        }else if (currentHandTotals[0] == 2 && currentHandTotals[1] == 2) {
            currentRank += 30000000000;
        }else if (currentHandTotals[0] == 2 && currentHandTotals[1] == 1) {
            currentRank += 20000000000;
        }else if (currentHandTotals[0] == 1) {
            currentRank += 10000000000;
        }
        cardsAccounted = 0;
        for (int i = 0; i < currentHand.length(); i++) {
            currentRank += assignPoint(currentHand[i], cardPoints.find(currentHand[i])->second);
        }
        ranks.push_back(currentRank);
        rankMap.emplace(currentRank, i);
        currentHandTotals.clear();
    }
    std::ranges::sort(ranks);
    long partOneTot = 0;
    for (int i = 0; i < ranks.size(); i++) {
        int iter = rankMap.find(ranks[i])->second;
        int bid = bids[iter];
        //std::cout << hands[iter] << " " << ranks[i] << " " << bid << std::endl;
        partOneTot += ((i+1) * bid);
    }
    std::cout << partOneTot << std::endl;
}

void Day7::partTwo() {
    ranks.clear();
    rankMap.clear();
    for (int i = 0; i < hands.size(); i++) {
        std::string currentHand = hands[i];
        long currentRank = 0;
        int A = 0; int K = 0; int Q = 0; int J = 0; int T = 0;
        int nine = 0; int eight = 0; int seven = 0; int six = 0;
        int five = 0; int four = 0; int three = 0; int two = 0;
        for (int ii = 0; ii < currentHand.length(); ii++) {
            if (const char currentCard = currentHand[ii]; currentCard == 'A') {
                A++;
            }else if (currentCard == 'K') {
                K++;
            }else if (currentCard == 'Q') {
                Q++;
            }else if (currentCard == 'T') {
                T++;
            }else if (currentCard == '9') {
                nine++;
            }else if (currentCard == '8') {
                eight++;
            }else if (currentCard == '7') {
                seven++;
            }else if (currentCard == '6') {
                six++;
            }else if (currentCard == '5') {
                five++;
            }else if (currentCard == '4') {
                four++;
            }else if (currentCard == '3') {
                three++;
            }else if (currentCard == '2') {
                two++;
            }else if (currentCard == 'J') {
                A++; K++; Q++; J++; T++; nine++; eight++; seven++; six++; five++; four++; three++; two++;
            }
        }
        currentHandTotals.push_back(A);
        currentHandTotals.push_back(K);
        currentHandTotals.push_back(Q);
        currentHandTotals.push_back(J);
        currentHandTotals.push_back(T);
        currentHandTotals.push_back(nine);
        currentHandTotals.push_back(eight);
        currentHandTotals.push_back(seven);
        currentHandTotals.push_back(six);
        currentHandTotals.push_back(five);
        currentHandTotals.push_back(four);
        currentHandTotals.push_back(three);
        currentHandTotals.push_back(two);
        std::ranges::sort(currentHandTotals);
        std::reverse(currentHandTotals.begin(),currentHandTotals.end());
        int secondCard = currentHandTotals[1] - J;
        if (currentHandTotals[0] == 5) {
            currentRank += 70000000000;
        }else if (currentHandTotals[0] == 4) {
            currentRank += 60000000000;
        }else if (currentHandTotals[0] == 3 && secondCard == 2) {
            currentRank += 50000000000;
        }else if (currentHandTotals[0] == 3 && secondCard == 1) {
            currentRank += 40000000000;
        }else if (currentHandTotals[0] == 2 && secondCard == 2) {
            currentRank += 30000000000;
        }else if (currentHandTotals[0] == 2 && secondCard == 1) {
            currentRank += 20000000000;
        }else if (currentHandTotals[0] == 1) {
            currentRank += 10000000000;
        }
        cardsAccounted = 0;
        for (int i = 0; i < currentHand.length(); i++) {
            currentRank += assignPoint(currentHand[i], cardPoints2.find(currentHand[i])->second);
        }
        ranks.push_back(currentRank);
        rankMap.emplace(currentRank, i);
        currentHandTotals.clear();
    }
    std::ranges::sort(ranks);
    long partTwoTot = 0;
    for (int i = 0; i < ranks.size(); i++) {
        int iter = rankMap.find(ranks[i])->second;
        int bid = bids[iter];
        //std::cout << hands[iter] << " " << ranks[i] << " " << bid << std::endl;
        partTwoTot += ((i+1) * bid);
    }
    std::cout << partTwoTot << std::endl;
}