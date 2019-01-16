//
// Scoreboard.cpp
// Scoreboard
//

#include "Scoreboard.hpp"


////////// Constructor and Destructor

Scoreboard::Scoreboard()

{}

Scoreboard::~Scoreboard()
{}

////////// Methods

bool Scoreboard::incrementTeamScore(const std::string& teamName, const unsigned long& increment)
{
    bool incremented(false);

    auto it = findTeam(teamName);

    if(it != teamArray.end())
    {
        it->get()->incrementScore(increment);
        incremented = true;
    }

    return incremented;
}

bool Scoreboard::decrementTeamScore(const std::string& teamName, const unsigned long& decrement)
{
    bool decremented(false);

    auto it = findTeam(teamName);

    if(it != teamArray.end())
    {
        it->get()->decrementScore(decrement);
        decremented = false;
    }

    return decremented;
}

bool Scoreboard::addTeam(Team::Ptr team)
{
    bool added(false);

    if(teamArray.size() < MAX_TEAM)
    {
        teamArray.push_back(team);
        added = true;
    }

    return added;
}

bool Scoreboard::deleteTeam(const std::string& teamName)
{
    bool deleted(false);

    auto found = findTeam(teamName);

    if(found != teamArray.end())
    {
        teamArray.erase(found);
        deleted = true;
    }

    return deleted;
}


////////// Getters



////////// Setters


////////// Internal Handling

std::vector<Team::Ptr>::iterator Scoreboard::findTeam(const std::string& teamName)
{
    auto found = std::find_if(teamArray.begin(), teamArray.end(),[&](Team::Ptr t)
    {
        return t->getName() == teamName;}
    );

    return found;
}
