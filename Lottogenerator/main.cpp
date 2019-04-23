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

int main()
{
    // program should only exit if
    // the users tells it to and sets the variable to true
    bool shouldExit = false;
    while (!shouldExit)
    {
        shouldExit = true;
    }
    
    pause();
    
    // tell the calling process, everything's fine
    return EXIT_SUCCESS;
}

#pragma region Helpers

void print(std::string text)
{
    // print the text
    std::cout << text;
}

void println()
{
    // print the line break
    std::cout << std::endl;
}

void println(std::string text)
{
    // print the text followed by a line break
    print(text);
    println();
}

void pause()
{
    // tell the user, that we are waiting for him
    print("Press enter to continue...");
    
    // Note: getchar() is a better solution than the most often used system("pause")
    //       it basically does the same thing; but instead of executing the provided command
    //       at the systems terminal, it waits for the user to press the enter key
    getchar();
}

#pragma endregion /* Helpers */
