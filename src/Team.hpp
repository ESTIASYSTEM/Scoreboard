//
// Team.hpp
// Scoreboard.hpp
//

#ifndef TEAM_HPP
#define TEAM_HPP

#include <memory>
#include <string>


#include <SFML/Graphics.hpp>

class Team
{
public:

    typedef std::shared_ptr<Team> Ptr;

public:

    // Constructor and Destructor
    Team();
    Team(const std::string& name, const unsigned long& score = 0);

    // Methods
    void    incrementScore(const unsigned long& increment = 1);
    void    decrementScore(const unsigned long& decrement = 1);

    void    resetScore();

    // Getters
    std::string     getName() const;
    unsigned long   getScore() const;


    // Setters
    void    setName(const std::string& name);
    void    setScore(const unsigned long& score);

private:

    std::string     mName;
    unsigned long   mScore;

};

#endif //TEAM_HPP
