/*
 * Project:      Lottogenerator
 * File:         tools.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#include "tools.hpp"

namespace me
{
    namespace simonprinz
    {
        namespace tools
        {
            std::string readLine()
            {
                // temporary variable for the line to read
                std::string line;
                // read from cin and populate line
                std::getline(std::cin, line);
                //return line
                return line;
            }
            
            void print(const std::string text)
            {
                // print the text
                std::cout << text;
            }
            
            void println()
            {
                // print the line break
                std::cout << std::endl;
            }
            
            void printtab()
            {
                // print a tabulator
                std::cout << "\t";
            }
            
            void println(const std::string text)
            {
                // print the text followed by a line break
                print(text);
                println();
            }
            
            void pause()
            {
                pause("Press enter to continue...");
            }
            
            void pause(std::string message)
            {
                // tell the user, that we are waiting for him
                print(message);
                
                // Note: getchar() is a better solution than the most often used system("pause")
                //       it basically does the same thing; but instead of executing the provided command
                //       at the systems terminal, it waits for the user to press the enter key
                getchar();
            }
            
            void clear()
            {
                system("clear");
            }
            
            std::string tolower(std::string str)
            {
                for (int i = 0; i < str.length(); i++)
                    if (str[i] <= 'Z' && str[i] >= 'A')
                        str[i] = str[i] - ('Z' - 'z');
                return str;
            }
            
            /*std::string toupper(std::string str)
            {
                for (int i = 0; i < str.length(); i++)
                    if (str[i] <= 'z' && str[i] >= 'a')
                        str[i] = str[i] + ('Z' - 'z');
                return str;
            }*/
        }
    }
}
