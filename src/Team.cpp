//
// Team.cpp
// Scoreboard
//

#include "Team.hpp"

////////// Constructor and Destructor

Team::Team()
: mName("Team")
, mScore(0)
{}

Team::Team(const std::string& name, const unsigned long& score)
: mName(name)
, mScore(score)
{}

////////// Methods

void Team::incrementScore(const unsigned long& increment)
{
    setScore(getScore() + increment);
}

void Team::decrementScore(const unsigned long& decrement)
{
    setScore(getScore() - decrement);
}

void Team::resetScore()
{
    setScore(0);
}

////////// Getters

std::string Team::getName() const
{
    return mName;
}

unsigned long Team::getScore() const
{
    return mScore;
}

////////// Setters

void Team::setName(const std::string& name)
{
    mName = name;
}

void Team::setScore(const unsigned long& score)
{
    mScore = score;
}
