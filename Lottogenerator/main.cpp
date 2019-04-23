/*
 * Project:      Lottogenerator
 * File:         main.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.0 (23.04.2019)
 */

#include "main.hpp"

/**
 * Main method.
 *
 * @return status code of the program
 */
int main()
{
    Generator gen;
    
    // program should only exit if
    // the users tells it to and sets the variable to true
    bool shouldExit = false;
    while (!shouldExit)
    {
        tools::clear();
        tools::println("Lottogenerator v1.0");
        tools::println();
        gen.printConfiguration();
        tools::println();
        tools::println("=== Optionen ===");
        tools::println("spiele = <int>");
        tools::println("wochen = <int>");
        tools::println("tage = <Mittwoch=1mi|Samstag=1sa|Beide=2>");
        tools::println();
        tools::println("generieren - lottoscheine erstellen");
        tools::println("beenden - programm verlassen");
        tools::println();
        tools::print("Eingabe: ");
        std::string line = tools::readLine();
        line = tools::tolower(line);
        if (line == "beenden" || line == "exit")
            shouldExit = true;
        else if (line == "generieren" || line == "gen")
            generateAndPrintTickets(gen);
        else if (!parse(gen, line))
        {
            tools::println();
            tools::println("ERROR: Die Eingabe konnte nicht erkannt werden.");
            tools::pause("Drücken Sie enter zum fortfahren");
        }
    }
    
    // tell the calling process, everything's fine
    return EXIT_SUCCESS;
}

bool parse(Generator &gen, std::string line)
{
    try
    {
        std::regex regex("spiele\\s*=\\s*(\\d+)");
        std::smatch match;
        if (std::regex_search(line, match, regex) && match.size() > 1)
        {
            gen.setGamesPerDay(std::stoi(match.str(1)));
            return true;
        }
    }
    catch (std::regex_error err) {}
    
    try
    {
        std::regex regex("wochen\\s*=\\s*(\\d+)");
        std::smatch match;
        if (std::regex_search(line, match, regex) && match.size() > 1)
        {
            gen.setWeeks(std::stoi(match.str(1)));
            return true;
        }
    }
    catch (std::regex_error err) {}
    
    try
    {
        std::regex regex("tage\\s*=\\s*(1mi|1sa|2)");
        std::smatch match;
        if (std::regex_search(line, match, regex) && match.size() > 1)
        {
            std::string val = match.str(1);
            if (val == "1mi")
            {
                    gen.setDays(Days::Wednesday);
                    return true;
            }
            else if (val == "1sa")
            {
                    gen.setDays(Days::Saturday);
                    return true;
            }
            else if (val == "2")
            {
                    gen.setDays(Days::Both);
                    return true;
            }
        }
    }
    catch (std::regex_error err) {}
    
    return false;
}

void generateAndPrintTickets(Generator gen)
{
    int count = gen.getTicketAmount();
    bool displayHeader = true;
    for (int i = 0; i < count; i++)
    {
        if (displayHeader)
        {
            tools::clear();
            displayHeader = false;
            tools::print("Schein Nr");
            tools::printtab();
            tools::print("|");
            tools::printtab();
            tools::print("1");
            tools::printtab();
            tools::print("2");
            tools::printtab();
            tools::print("3");
            tools::printtab();
            tools::print("4");
            tools::printtab();
            tools::print("5");
            tools::printtab();
            tools::print("6");
            tools::printtab();
            tools::print("|");
            tools::printtab();
            tools::print("Super");
            tools::println();
        }
        Draw draw;
        draw.generateRandom();
        tools::print("Schein ");
        tools::print(tools::str(i + 1));
        tools::printtab();
        tools::print("|");
        tools::printtab();
        tools::print(tools::str(draw.getNumber(0)));
        tools::printtab();
        tools::print(tools::str(draw.getNumber(1)));
        tools::printtab();
        tools::print(tools::str(draw.getNumber(2)));
        tools::printtab();
        tools::print(tools::str(draw.getNumber(3)));
        tools::printtab();
        tools::print(tools::str(draw.getNumber(4)));
        tools::printtab();
        tools::print(tools::str(draw.getNumber(5)));
        tools::printtab();
        tools::print("|");
        tools::printtab();
        tools::print(tools::str(draw.getSuperNumber()));
        tools::println();
        if ((i + 1) % 10 == 0)
        {
            displayHeader = true;
            tools::print("Drücken Sie enter für die nächsten ");
            tools::print(tools::str((count - (i + 1) > 10) ? 10 : count - (i + 1)));
            tools::pause(" Zeilen");
        }
    }
    tools::pause("Sie können nun erneut neue Zahlen generieren oder Ihre Konfiguration ändern");
}
