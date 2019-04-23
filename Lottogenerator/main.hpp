/*
 * Project:      Lottogenerator
 * File:         main.hpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#ifndef main_hpp
#define main_hpp

// cout and cin
#include <iostream>
// Draw class
#include "Draw.hpp"

/**
 * Main method.
 *
 * @return status code of the program
 */
int main();

#pragma region Helpers

/**
 * prints the text to the screen
 */
void print(std::string text);

/**
 * prints a line break
 */
void println();

/**
 * prints the text and a line break to the screen
 */
void println(std::string text);

/**
 * Pauses the console and waits for the user to press a key.
 */
void pause();

#pragma endregion /* Helpers */

#endif /* main_hpp */
