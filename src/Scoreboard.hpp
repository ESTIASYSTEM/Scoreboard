//
// Scoreboard.hpp
// Scoreboard
//

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Team.hpp"

class Scoreboard : sf::Drawable
{
public:

    Scoreboard();


private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    std::vector<Team::Ptr> teamArray;


}
