/*
 * Project:      Lottogenerator
 * File:         main.cpp
 *
 * Author:       Simon Prinz
 * Copyright:    © 2019 Simon Prinz. All rights reserved
 *
 * Version:      1.1 (26.04.2019)
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
        t::clear();
        t::println("Lottogenerator v1.0");
        t::println();
        // printConfiguration writes everything currently
        // configured in the Generator to the screen
        gen.printConfiguration();
        t::println();
        t::println("=== Optionen ===");
        t::println("spiele = <int:1-12>");
        t::println("wochen = <int:1-5>");
        t::println("tage = <Mittwoch=1mi|Samstag=1sa|Beide=2>");
        t::println();
        t::println("generieren - lottoscheine erstellen");
        t::println("beenden - programm verlassen");
        t::println();
        
        // input of the user
        t::print("Eingabe: ");
        // waiting for the user to enter something and press enter
        std::string line = t::readLine();
        // converting the input to all lowercase for parsing
        line = t::tolower(line);
        
        std::string error = "";
        // if the users wants to exit, we set shouldExit to true
        // this will result in the termination of the program in the next loop
        if (line == "beenden" || line == "exit")
            shouldExit = true;
        // if the user wants to generate his tickets
        // we call the printTickets method with our current generator configuration
        else if (line == "generieren" || line == "gen")
            generateAndPrintTickets(gen);
        // if none of the above could be applied, we try to parse the input
        // and write an error in the case the input was not valid
        else if (!parse(gen, line, error))
        {
            t::println();
            t::print("ERROR: ");
            // error is a custom error provided by the parse method
            if (error != "")
                t::println(error);
            else
                t::println("Die Eingabe konnte nicht erkannt werden.");
            t::pause("Drücken Sie enter zum fortfahren");
        }
    }
    
    // tell the calling process, everything's fine
    return EXIT_SUCCESS;
}

bool parse(Generator &gen, std::string line, std::string &error)
{
    try
    {
        // try to parse the "spiele = <int>" command
        std::regex regex("spiele\\s*=\\s*(\\d+)");
        std::smatch match;
        // if a match is found apply it
        if (std::regex_search(line, match, regex) && match.size() > 1)
        {
            int games = std::stoi(match.str(1));
            // checking the int if it's valid
            if (games < 1 || games > 12) {
                error = "Spiele muss zwischen 1 und 12 (inklusive) liegen";
                return false;
            }
            // set the games per day
            gen.setGamesPerDay(games);
            return true;
        }
    }
    catch (std::regex_error err) {}
    
    try
    {
        // try to parse the "wochen = <int>" command
        std::regex regex("wochen\\s*=\\s*(\\d+)");
        std::smatch match;
        // if a match is found apply it
        if (std::regex_search(line, match, regex) && match.size() > 1)
        {
            int weeks = std::stoi(match.str(1));
            // checking if the int is valid
            if (weeks < 1 || weeks > 5) {
                error = "Wochen muss zwischen 1 und 5 (inklusive) liegen";
                return false;
            }
            // set the weeks
            gen.setWeeks(weeks);
            return true;
        }
    }
    catch (std::regex_error err) {}
    
    try
    {
        // parsing the "tage = <str>" command
        std::regex regex("tage\\s*=\\s*(1mi|1sa|2)");
        std::smatch match;
        // if a match is found, apply it
        if (std::regex_search(line, match, regex) && match.size() > 1)
        {
            std::string val = match.str(1);
            // going through multiple if cases to set the enum value
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
    
    // no command could be found
    return false;
}

void generateAndPrintTickets(Generator gen)
{
    // get the total ticket amount to be generated
    int count = gen.getTicketAmount();
    // should the column header be displayed
    bool displayHeader = true;
    Draw draw;
    // loop as many times as there are tickets to generate
    for (int i = 0; i < count; i++)
    {
        // show the table header
        if (displayHeader)
        {
            t::clear();
            // display for next row
            displayHeader = false;
            t::print("Schein Nr");
            t::printtab();
            t::print("|");
            t::printtab();
            t::print("1");
            t::printtab();
            t::print("2");
            t::printtab();
            t::print("3");
            t::printtab();
            t::print("4");
            t::printtab();
            t::print("5");
            t::printtab();
            t::print("6");
            t::printtab();
            t::print("|");
            t::printtab();
            t::print("Super");
            t::println();
        }
        // generate new numbers for this ticket
        draw.generateRandom();
        t::print("Schein ");
        t::print(t::str(i + 1));
        t::printtab();
        t::print("|");
        t::printtab();
        t::print(t::str(draw.getNumber(0)));
        t::printtab();
        t::print(t::str(draw.getNumber(1)));
        t::printtab();
        t::print(t::str(draw.getNumber(2)));
        t::printtab();
        t::print(t::str(draw.getNumber(3)));
        t::printtab();
        t::print(t::str(draw.getNumber(4)));
        t::printtab();
        t::print(t::str(draw.getNumber(5)));
        t::printtab();
        t::print("|");
        t::printtab();
        t::print(t::str(draw.getSuperNumber()));
        t::println();
        
        // pause every ten rows for better readability
        if ((i + 1) % 10 == 0)
        {
            // show the header next time
            displayHeader = true;
            // wait for the user to continue
            t::print("Drücken Sie enter für die nächsten ");
            t::print(t::str((count - (i + 1) > 10) ? 10 : count - (i + 1)));
            t::pause(" Zeilen");
        }
    }
    // hint for what to do next
    t::pause("Sie können nun erneut neue Zahlen generieren oder Ihre Konfiguration ändern");
}
