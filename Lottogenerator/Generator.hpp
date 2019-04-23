/*
 * Project:      Lottogenerator
 * File:         Generator.hpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#ifndef Generator_hpp
#define Generator_hpp

#include "tools.hpp"

/**
 * enum class for days that can be used
 */
enum class Days
{
    Wednesday = 1,
    Saturday = 2,
    Both = 3
};

class Generator
{
    int gamesPerDay = 1;
    Days playDays = Days::Saturday;
    int playWeeks = 1;
    
public:
    inline void setGamesPerDay(const int g)
    {
        this->gamesPerDay = g;
    };
    inline void setDays(const Days d)
    {
        this->playDays = d;
    };
    inline void setWeeks(const int w)
    {
        this->playWeeks = w;
    };
    void printConfiguration() const;
    int getTicketAmount() const;
    float calculatePrice() const;
};

#endif /* Generator_hpp */
