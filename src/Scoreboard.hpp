//
// Scoreboard.hpp
// Scoreboard
//

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Team.hpp"



class Scoreboard : public sf::Drawable
{
public:

    static const int MAX_TEAM = 4;
    static const int SCORE_SIZE_THRESHOLD = 300;

public:

    Scoreboard();
    ~Scoreboard();

    // Methods
    bool    incrementTeamScore(const std::string& teamName, const unsigned long& increment);
    bool    decrementTeamScore(const std::string& teamName, const unsigned long& decrement);

    bool    addTeam(Team::Ptr team);
    bool    deleteTeam(const std::string& teamName);

    void    update();

protected:

    // Internal Handling
    unsigned long                    findBestScore() const;
    std::vector<Team::Ptr>::iterator findTeam(const std::string& teamName);


private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    std::vector<Team::Ptr> teamArray;

};

#endif //SCOREBOARD_HPP
