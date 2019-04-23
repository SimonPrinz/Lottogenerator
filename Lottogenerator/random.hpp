/*
 * Project:      Lottogenerator
 * File:         random.hpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#ifndef random_hpp
#define random_hpp

// random_device, etc.
#include <random>
// exceptions
#include <stdexcept>

/**
 * Generates a random number between min and max (both including)
 *
 * @param min minimum number (incl.)
 * @param max maximum number (incl.)
 * @return a random number between both parameters (incl.)
 */
int generateRandomInt(int min, int max);

#endif /* random_hpp */
