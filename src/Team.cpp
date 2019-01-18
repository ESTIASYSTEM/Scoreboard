//
// Team.cpp
// Scoreboard
//

#include "Team.hpp"

////////// Constructor and Destructor

Team::Team()
: mName("Team")
, mScore(0)
{
    mPointText.setString("POINTS");
}

Team::Team(const std::string& name, const unsigned long& score)
: mName(name)
, mScore(score)
{
    mPointText.setString("POINTS");
}

////////// Methods

void Team::incrementScore(const unsigned long& increment)
{
    setScore(std::min<unsigned long>(getScore() + increment, std::numeric_limits<unsigned long>::max()));
}

void Team::decrementScore(const unsigned long& decrement)
{
    setScore(std::max<long long>(0 ,static_cast<long long>(getScore() - decrement)));
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

    mScoreText.setString(std::to_string(score));
    utils::centerOrigin<sf::Text>(mScoreText);
    utils::centerOrigin<sf::Text>(mPointText);
    mScoreText.setOrigin(mScoreText.getOrigin().x, mScoreText.getGlobalBounds().height);
    mPointText.setOrigin(mPointText.getOrigin().x, 0);
}

void Team::setScoreBarColor(const sf::Color& color)
{
    mScoreBar.setFillColor(color);
}

void Team::setScoreBarRatio(const float& ratio)
{
    auto clampedRatio = utils::clamp<float>(ratio, 0, 1);
    long newHeight = MIN_HEIGHT + clampedRatio*(MAX_HEIGHT - MIN_HEIGHT);

    mScoreBar.setSize(sf::Vector2f(mScoreBar.getSize().x, -newHeight));
    mScoreText.setPosition(0, mScoreBar.getPosition().y - newHeight/2.f - 10);
    mPointText.setPosition(0, mScoreBar.getPosition().y - newHeight/2.f + 10);
}

void Team::setScoreCharacterSize(const unsigned& size)
{
    mScoreText.setCharacterSize(size*1.5);
    mPointText.setCharacterSize(size);
}

void Team::setScoreColor(const sf::Color& color)
{
    mScoreText.setFillColor(color);
    mPointText.setFillColor(color);
}

void Team::setTexture(const sf::Texture& texture)
{
    mSprite.setTexture(texture);
    this->setupGraphics();

}

void Team::setTextFont(const sf::Font& font)
{
    mScoreText.setFont(font);
    mPointText.setFont(font);
    utils::centerOrigin<sf::Text>(mScoreText);
    utils::centerOrigin<sf::Text>(mPointText);

}

/////////// Internal Handling

void Team::setupGraphics()
{
    //Centering Sprite Origin
    utils::centerOrigin<sf::Sprite>(mSprite);

    // Updating the bar width
    auto spriteRect = mSprite.getGlobalBounds();
    mScoreBar.setSize(sf::Vector2f(spriteRect.width*2.f/3.f, mScoreBar.getSize().y));

    // Centering the origin of the scorebar
    utils::centerOrigin<sf::RectangleShape>(mScoreBar);
    mScoreBar.setOrigin(mScoreBar.getOrigin().x,0);

    // Setting the position of the scorebar
    mScoreBar.setPosition(0,-(spriteRect.height/2.f*(3/5.f)));
}

/////////// Draw

void Team::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();

    target.draw(mScoreBar, states);
    target.draw(mPointText, states);
    target.draw(mScoreText, states);
    target.draw(mSprite, states);

}

//
