/*
 * Project:      Lottogenerator
 * File:         main.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

// include header file
#include "main.hpp"

/**
 * Main method.
 *
 * @return status code of the program
 */
int main() {
    
#pragma region Test
    Draw d;
    d.generateRandom();
    for (int i = 0; i < d.length(); i++) {
        std::cout << d.getNumber(i) << "\t";
    }
    std::cout << d.getSuperNumber();
#pragma endregion /* Test */
    
    //pause();
    
    // tell the calling process, everything's fine
    return EXIT_SUCCESS;
}

void pause() {
#ifdef _WIN32_
    system("pause");
#else
    system("read -n 1 -s -p \"Press any key to continue...\"");
#endif
}
