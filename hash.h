#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <cstdlib>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here

        // this is where I need to hash the string into the array??
        // first item would be to make sure the string is in a lowercase
        // form that way we dont have any bad conversions
        
        // just do a to lower conversion for fucks sake
        unsigned long long w[5];
        // need to initialize the hash array
        for (int i = 0; i < 5; ++i) {
          w[i] = 0;
        }
        // find the size of the string for iteration use
        int stringSize = k.size();
        // the base function basically counts down from 5 for every 6 substr
        for (int i = 27; i >= 0; --i) {
          unsigned long long byte = 36; // base conversion
          // power allowable 0-5 so perfect mod 6
          auto power = i % 6;
          byte = pow(byte, power);
          if (i < stringSize) {
            // casting is necessay since is in type long long unsigned
            // follow the formula given to us
            w[4 - (int)ceil(i / 6)] += byte * letterDigitToNumber(k[stringSize - i - 1]);
          }
          else {
            w[4 - (int)ceil(i / 6)] = 0;
          }
        }
        // need to find the hash index of the item
        HASH_INDEX_T hash = 0;
        for (int i = 0; i < 5; ++i) {
          hash += (HASH_INDEX_T)(rValues[i] * w[i]);
        }

        return hash;
        

        


    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        // would do simple math so that a-z is within 0-25 and 0-9 is 26-35
        // we can use the char ascii shit i believe here for that 

        // check if the letters are capitalized
        if ((int)letter >= 65 && (int)letter <= 90) {
          // tolower only takes in a char so this is convenient 
          letter = std::tolower(letter);
        }
        // for ascii conversion
        // this is if the letter is in the number range 0-9
        if ((int)letter >= 48 && (int)letter <= 57) {
          return (HASH_INDEX_T)letter - 22; // 35 cap
        }
        // letter is a char representation of letter 
        else if ((int)letter >= 97 && (int)letter <= 122) {
          return (HASH_INDEX_T)letter - 97; // 25 cap
        }
        else {
          return -1; // outrageous shit 
        }


    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
