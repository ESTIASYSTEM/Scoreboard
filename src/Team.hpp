//
// Team.hpp
// Scoreboard.hpp
//

#ifndef TEAM_HPP
#define TEAM_HPP

#include <memory>
#include <limits>
#include <string>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"

class Team : public sf::Transformable, public sf::Drawable
{
public:

    typedef std::shared_ptr<Team> Ptr;

    static const unsigned MAX_HEIGHT = 1000;
    static const unsigned MIN_HEIGHT = 100;
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
    void    setScoreBarColor(const sf::Color& color);
    void    setScoreBarRatio(const float& ratio);
    void    setScoreCharacterSize(const unsigned& size);
    void    setScoreColor(const sf::Color& color);
    void    setTexture(const sf::Texture& texture);
    void    setTextFont(const sf::Font& font);

protected:

    // Internal Handler
    void   setupGraphics();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    std::string         mName;
    unsigned long       mScore;
    sf::RectangleShape  mScoreBar;

    sf::Text            mScoreText;
    sf::Text            mPointText;
    sf::Sprite          mSprite;


};

#endif //TEAM_HPP
