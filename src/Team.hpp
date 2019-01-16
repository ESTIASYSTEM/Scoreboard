//
// Team.hpp
// Scoreboard.hpp
//

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
    void    decrement(const unsigned long& decrement = 1);

    void    resetScore();

    // Getters
    unsigned long   getScore() const;
    std::string     getName() const;

    // Setters
    void    setScore(const unsigned long& score);

private:

    std::string     mName;
    unsigned long   mScore;

};
