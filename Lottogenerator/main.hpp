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

#include "Generator.hpp"
#include "Draw.hpp"
#include "tools.hpp"
#include <regex>

namespace tools = me::simonprinz::tools;

int main();

bool parse(Generator &gen, std::string line);

void generateAndPrintTickets(Generator gen);

#endif /* main_hpp */
