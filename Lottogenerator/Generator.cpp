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

namespace t = me::simonprinz::tools;

void Generator::printConfiguration() const
{
    t::println("=== Derzeitige Konfiguration ===");
    t::print(t::str(this->gamesPerDay));
    t::print(" Spiel");
    t::print(this->gamesPerDay != 1 ? "e" : "");
    t::println(" pro Tag");
    t::print("am ");
    switch (this->playDays)
    {
        case Days::Wednesday:
            t::print("Mittwoch ");
            break;
        case Days::Saturday:
            t::print("Samstag ");
            break;
        case Days::Both:
            t::println("Mittwoch und Samstag");
            break;
    }
    t::print("für ");
    t::print(t::str(this->playWeeks));
    t::print(" Woche");
    t::println(this->playWeeks != 1 ? "n" : "");
    t::print(" => ");
    t::print(t::str(this->calculatePrice()));
    t::println(" €");
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
