/*
 * Project:      Lottogenerator
 * File:         Draw.hpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#ifndef Draw_hpp
#define Draw_hpp

// let's define a datatype SINT for small numbers
#define SINT short unsigned int

// exceptions
#include <stdexcept>
// to_string
#include <iostream>
// better randomness
#include "random.hpp"

/**
 * represents one draw with six numbers + super number
 */
class Draw
{
    /**
     * normal numbers drawn
     */
    SINT numbers[6];
    /**
     * additional super number
     */
    SINT supernumber;
    
public:
    /**
     * Generates random numbers and fills the numbers array aswell as the supernumber.
     */
    void generateRandom();
    
    /**
     * gets a single number out of the numbers stored in the array at the position of index
     *
     * @param index array index
     * @return number at position index
     */
    inline SINT getNumber(int index) const
    {
        // if the index is smaller than 0 or greater than the length,
        // we throw an out of range exception at this point
        if (index < 0 || index > this->length())
            throw std::out_of_range("index must be between 0 and " + std::to_string(this->length() - 1));
        // return the number at the specific position
        return this->numbers[index];
    };
    
    /**
     * gets the super number for this draw
     *
     * @return the super number
     */
    inline SINT getSuperNumber() const
    {
        // return the super number
        return this->supernumber;
    };
    
    /**
     * gets the length of the numbers array
     *
     * @return length of the numbers array
     */
    inline int length() const
    {
        // Note: this is an example for an int array with a length of 6
        //       the total size of the numbers array (=24) divided by
        //       the single size of one item in the numbers array (=4) equals
        //       the length of the array (24 / 4 = 6)
        return sizeof(this->numbers) / sizeof(typeof(this->numbers[0]));
    };
    
private:
    /**
     * Sorts the numbers array with the bubble sort algorithm
     */
    void sortNumbers();
};

#endif /* Draw_hpp */
