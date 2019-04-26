/*
 * Project:      Lottogenerator
 * File:         main.hpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.1 (26.04.2019)
 */

#ifndef main_hpp
#define main_hpp

#include "Generator.hpp"
#include "Draw.hpp"
#include "tools.hpp"
#include <regex>

namespace t = me::simonprinz::tools;

/**
 * main method
 *
 * @return exit code
 */
int main();

/*
 * parses a line of input and applies it, or returns false and provides an additional error
 *
 * @param gen current generator to apply to
 * @param line input line with a user command
 * @param error will be set, if an additional error could be shown
 * @return true, if successfully parsed
 */
bool parse(Generator &gen, std::string line, std::string &error);

/*
 * generates and prints all tickets with the current configuration
 *
 * @param gen the current generation configuration
 */
void generateAndPrintTickets(Generator gen);

#endif /* main_hpp */
