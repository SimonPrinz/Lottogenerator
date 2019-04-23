/*
 * Project:      Lottogenerator
 * File:         random.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#include "random.hpp"

namespace me
{
    namespace simonprinz
    {
        namespace random
        {
            // Warning:
            // These two components should be defined globally
            // for use in the entire project!

            // create a random device for randomness (as of C++ 11)
            std::random_device G_randomdevice;
            // create a random number generator for that device
            std::mt19937 G_randomnumbergenerator(G_randomdevice());

            int generateRandomInt(const int min, const int max)
            {
                // check if min is somehow greater than max
                if (min > max)
                    throw std::out_of_range("max has to be greater or equal to min");
                // check if both values are equal, if so return one of them
                if (min == max)
                    return min;
                
                // create a distribution range
                std::uniform_int_distribution<std::mt19937::result_type> distrange(min, max);
                // return the random number
                return distrange(G_randomnumbergenerator);
            }
        }
    }
}
