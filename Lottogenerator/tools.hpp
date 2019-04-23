/*
 * Project:      Lottogenerator
 * File:         hpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#ifndef tools_hpp
#define tools_hpp

#include <iostream>
#include <sstream>

namespace me
{
    namespace simonprinz
    {
        namespace tools
        {
            /**
             * reads a line from input
             *
             * @return line as string
             */
            std::string readLine();
            
            /**
             * converts an object to a string
             */
            template <typename T>
            std::string str(const T &t) {
                std::stringstream ss;
                ss << t;
                return ss.str();
            }

            /**
             * prints the text to the screen
             */
            void print(const std::string text);

            /**
             * prints a line break
             */
            void println();

            /**
             * prints a tabulator
             */
            void printtab();

            /**
             * prints the text and a line break to the screen
             */
            void println(const std::string text);

            /**
             * Pauses the console and waits for the user to press a key.
             */
            void pause();
            
            /**
             * Pauses the console with a message and waits for the user to press a key.
             */
            void pause(std::string message);
            
            /**
             * clears the entire screen
             */
            void clear();
            
            std::string tolower(std::string str);
            
            //std::string toupper(std::string str);
        }
    }
}
#endif /* tools_hpp */
