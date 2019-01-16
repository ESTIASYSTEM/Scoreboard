//
// Main.cpp
// Scoreboard
//

#include <SFML/System.hpp>

#include "Scoreboard.hpp"
#include "Team.hpp"

#include <iostream>

int main(int argc, char** argv)
{

    Scoreboard testBoard;

    auto testTeam = std::make_shared<Team>();
    testTeam->setName("test");
    testTeam->setScore(542429);

    std::cout << "Team added?: "    << testBoard.addTeam(testTeam)              << std::endl;
    std::cout << "Team name: "      << testTeam->getName()                      << std::endl;
    std::cout << "Team score: "     << testTeam->getScore()                     << std::endl;
    std::cout << "Decremented?: "   << testBoard.decrementTeamScore("test", 49) << std::endl;
    std::cout << "Team score: "     << testTeam->getScore()                     << std::endl;
    std::cout << "Team deleted?: "  << testBoard.deleteTeam("test")             << std::endl;



    return EXIT_SUCCESS;
}
