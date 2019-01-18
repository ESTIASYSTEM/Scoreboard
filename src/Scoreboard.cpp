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

void Scoreboard::update()
{
    auto bestScore = findBestScore();
    for(auto& team : teamArray)
    {
        auto t = team.get();
        t->setScoreBarRatio(t->getScore()/static_cast<float>(bestScore));
    }
}

////////// Internal Handling

unsigned long Scoreboard::findBestScore() const
{
    unsigned long bestScore(0);
    unsigned long buff;

    for(auto& team : teamArray)
    {
        buff = team.get()->getScore();
        bestScore = (buff > bestScore)? buff : bestScore;
    }

    return bestScore;
}

std::vector<Team::Ptr>::iterator Scoreboard::findTeam(const std::string& teamName)
{
    auto found = std::find_if(teamArray.begin(), teamArray.end(),[&](Team::Ptr t)
    {
        return t->getName() == teamName;}
    );

    return found;
}

////////// Draw

void Scoreboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto& team : teamArray)
    {
        target.draw(*team.get(), states);
    }
}

//
