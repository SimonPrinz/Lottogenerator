/*
 * Project:      Lottogenerator
 * File:         Generator.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#include "Generator.hpp"

namespace tools = me::simonprinz::tools;

void Generator::printConfiguration() const
{
    tools::println("=== Derzeitige Konfiguration ===");
    tools::print(tools::str(this->gamesPerDay));
    tools::print(" Spiel");
    tools::print(this->gamesPerDay != 1 ? "e" : "");
    tools::println(" pro Tag");
    tools::print("am ");
    switch (this->playDays)
    {
        case Days::Wednesday:
            tools::print("Mittwoch ");
            break;
        case Days::Saturday:
            tools::print("Samstag ");
            break;
        case Days::Both:
            tools::println("Mittwoch und Samstag");
            break;
    }
    tools::print("für ");
    tools::print(tools::str(this->playWeeks));
    tools::print(" Woche");
    tools::println(this->playWeeks != 1 ? "n" : "");
    tools::print(" => ");
    tools::print(tools::str(this->calculatePrice()));
    tools::println(" €");
}

int Generator::getTicketAmount() const
{
    return this->gamesPerDay * this->playWeeks * (this->playDays == Days::Both ? 2 : 1);
}

float Generator::calculatePrice() const
{
    float total = getTicketAmount();
    total += this->playDays == Days::Both ? .5 : .35;
    if (this->playWeeks >= 2)
        total += .15;
    if (this->playWeeks >= 4)
        total += .25;
    return total;
}
