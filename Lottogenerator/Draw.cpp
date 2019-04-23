/*
 * Project:      Lottogenerator
 * File:         Draw.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#include "Draw.hpp"

namespace rnd = me::simonprinz::random;

void Draw::generateRandom()
{
    // iterate through the whole length of the array
    for (int i = 0; i < this->length(); i++)
    {
        // create a variable to store the generated number
        // Note: this number needs to be initiailzed,
        //       otherwise the compiler throws a warning
        //       when assigning the value into the array
        SINT number = 0;
        // create a boolean that shows if the number is valid
        bool valid = false;
        
        // while the number is not valid, we stay in this loop
        while (!valid)
        {
            // generate a new number and set valid to true,
            // until someone says it's not
            number = rnd::generateRandomInt(1, 49);
            valid = true;
            
            // iterate through the part of the array we already filled with values
            // and check if our drawn number is already in it,
            // if that's the cast we mark our number as not valid
            // Note: this loop continues only if valid == true, otherwise it exits
            for (int j = 0; j < i && valid; j++)
                if (this->numbers[j] == number)
                    valid = false;
        }
        
        // set the current iteration in the array to the valid random number
        this->numbers[i] = number;
    }
    // generate the supernumber
    this->supernumber = rnd::generateRandomInt(0, 9);
    
    // sort the numbers to be ascending
    this->sortNumbers();
}

void Draw::sortNumbers()
{
    // create a temporary variable for
    // switching two numbers in the array
    SINT temp;
    
    // iterate through the whole legnth of the array
    for (int i = 0; i < this->length(); i++)
        // iterate only through the numbers which need to be sorted
        // which is the the length of the array minus the current iteration from above minus 1
        for (int j = 0; j < this->length() - 1 - i; j++)
            
            // if the current number is greater than the next in the array switch it
            if (this->numbers[j] > this->numbers[j + 1])
            {
                // save the current number in our temp variable,
                // so we can safely override it in the next step
                // and recover it to the next array position
                temp = this->numbers[j];
                this->numbers[j] = this->numbers[j + 1];
                this->numbers[j + 1] = temp;
            }
}
