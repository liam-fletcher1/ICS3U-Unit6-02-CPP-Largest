// Copyright (c) 2021 Liam Fletcher All rights reserved.
//
// Created by: Liam Fletcher
// Created on: Oct 2021
// This gets random numbers then finds the largest using an array

#include <iostream>
#include <random>
#include <ctime>
#include <array>


template<size_t N>
int LargestOfNumbers(std::array<int, N> listofNumbers) {
    int bigNumber;

    bigNumber = listofNumbers[0];
    for (int userX = 1; userX < N; userX++) {
        if (listofNumbers[userX] > bigNumber) {
            bigNumber = listofNumbers[userX];
        }
    }

    return bigNumber;
}


main() {
    // this function uses an array to generate 10 random numbers
    //  from 1-100 and output the mean

    std::array<int, 10> randomNum;
    int numberArray;
    int largeNumber;
    int sum = 0;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 100);
    // [0, 100]


    // output
    for (int loop_count = 0; loop_count < 10; loop_count++) {
        numberArray = idist(rgen);
        randomNum[loop_count] = numberArray;
    }

    std::cout << "The random numbers are:" << std::endl;
    std::cout << "" << std::endl;

    for (int loopCount; loopCount < 10; loopCount++) {
        std::cout << randomNum[loopCount] << " ";
        sum += randomNum[loopCount];
    }
    std::cout << "" << std::endl;

    largeNumber = LargestOfNumbers(randomNum);

    std::cout << "\nThe largest number is: "
    << largeNumber << "." << std::endl;
    std::cout << "\nDone." << std::endl;
}
