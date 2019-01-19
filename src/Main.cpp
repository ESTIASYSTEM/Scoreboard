//
// Main.cpp
// Scoreboard
//

#include <SFML/System.hpp>

#include "Scoreboard.hpp"
#include "Team.hpp"

#include <algorithm>
#include <iostream>
#include <regex>


int main(int argc, char** argv)
{

    int char_size(75);
    sf::Texture tex_gryffindor;
    sf::Texture tex_ravenclaw;
    sf::Texture tex_slytherin;
    sf::Texture tex_hufflepuff;
    sf::Texture tex_background;
    sf::Texture tex_wall;

    sf::Font testFont;

    // Loading the textures
    if(!tex_gryffindor.loadFromFile("img/gryffindor_x2.png"))
        return EXIT_FAILURE;

    if(!tex_ravenclaw.loadFromFile("img/ravenclaw_x2.png"))
        return EXIT_FAILURE;

    if(!tex_slytherin.loadFromFile("img/slytherin_x2.png"))
        return EXIT_FAILURE;

    if(!tex_hufflepuff.loadFromFile("img/hufflepuff_x2.png"))
        return EXIT_FAILURE;

    if(!tex_background.loadFromFile("img/background.jpg"))
        return EXIT_FAILURE;

        if(!tex_wall.loadFromFile("img/grunge_wall.png"))
            return EXIT_FAILURE;

    if(!testFont.loadFromFile("font/HARRYP__.TTF"))
        return EXIT_FAILURE;



    // defining the background
    sf::Sprite back_sprite;
    back_sprite.setTexture(tex_background);
    back_sprite.setPosition(2560/2.f,1600/2.f-100);
    back_sprite.setScale(1.5,1.5);
    utils::centerOrigin<sf::Sprite>(back_sprite);

    sf::Sprite wall_sprite;
    wall_sprite.setTexture(tex_wall);
    wall_sprite.setPosition(2560/2.f,1600/2.f);
    wall_sprite.setScale(2560/500.f,1600/375.f);
    wall_sprite.setColor(sf::Color(255,255,255,100));
    utils::centerOrigin<sf::Sprite>(wall_sprite);

    // Creating the teams

    Scoreboard scoreboard;

    auto gryffindorTeam = std::make_shared<Team>();
    gryffindorTeam->setName("gryffindor");
    gryffindorTeam->setPosition(2560/5.f,1300);
    gryffindorTeam->setScoreCharacterSize(char_size);
    gryffindorTeam->setScoreColor(sf::Color(51,51,51));
    gryffindorTeam->setScoreBarColor(sf::Color(234,154,151));
    gryffindorTeam->setTexture(tex_gryffindor);
    gryffindorTeam->setTextFont(testFont);
    gryffindorTeam->setScore(0);

    auto slytherinTeam = std::make_shared<Team>();
    slytherinTeam->setName("slytherin");
    slytherinTeam->setPosition(2560*4/5.f,1300);
    slytherinTeam->setScoreCharacterSize(char_size);
    slytherinTeam->setScoreColor(sf::Color(51,51,51));
    slytherinTeam->setScoreBarColor(sf::Color(144,214,195));
    slytherinTeam->setTexture(tex_slytherin);
    slytherinTeam->setTextFont(testFont);
    slytherinTeam->setScore(0);

    auto ravenclawTeam = std::make_shared<Team>();
    ravenclawTeam->setName("ravenclaw");
    ravenclawTeam->setPosition(2560*3/5.f,1300);
    ravenclawTeam->setScoreCharacterSize(char_size);
    ravenclawTeam->setScoreColor(sf::Color(51,51,51));
    ravenclawTeam->setScoreBarColor(sf::Color(219,222,242));
    ravenclawTeam->setTexture(tex_ravenclaw);
    ravenclawTeam->setTextFont(testFont);
    ravenclawTeam->setScore(0);


    auto hufflepuffTeam = std::make_shared<Team>();
    hufflepuffTeam->setName("hufflepuff");
    hufflepuffTeam->setPosition(2560*2/5.f,1300);
    hufflepuffTeam->setScoreCharacterSize(char_size);
    hufflepuffTeam->setScoreColor(sf::Color(51,51,51));
    hufflepuffTeam->setScoreBarColor(sf::Color(246,242,201));
    hufflepuffTeam->setTexture(tex_hufflepuff);
    hufflepuffTeam->setTextFont(testFont);
    hufflepuffTeam->setScore(0);

    scoreboard.addTeam(gryffindorTeam);
    scoreboard.addTeam(slytherinTeam);
    scoreboard.addTeam(ravenclawTeam);
    scoreboard.addTeam(hufflepuffTeam);

    // Creating the window
    sf::RenderWindow paramW(sf::VideoMode(800, 600), "parameters", sf::Style::Close);
    sf::RenderWindow window(sf::VideoMode(2560, 1600), "Scoreboard", sf::Style::None);
    paramW.setFramerateLimit(60);
    window.setFramerateLimit(60);

    // For new parameters
    sf::Text command_display;
    command_display.setFont(testFont);
    command_display.setCharacterSize(100);
    command_display.setPosition(400,300);
    std::string command("");
    std::string command_team_name("");
    long command_team_points(-1);

    bool lockedWindow(true);

    // Run the program as long as the window is open
    while (paramW.isOpen())
    {

        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                paramW.close();
                window.close();
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Left)
            {
                scoreboard.incrementTeamScore("gryffindor", 50);
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Up)
            {
                scoreboard.incrementTeamScore("slytherin", 50);
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Right)
            {
                scoreboard.incrementTeamScore("ravenclaw", 50);
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Down)
            {
                scoreboard.incrementTeamScore("hufflepuff", 50);
            }
        }

        // parametering
        while(paramW.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                paramW.close();
                window.close();
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Up && !lockedWindow)
            {
                auto pos = window.getPosition();
                if(!event.key.alt)
                    window.setPosition(sf::Vector2i(pos.x,pos.y-1));
                else
                    window.setPosition(sf::Vector2i(pos.x,pos.y-50));
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Down && !lockedWindow)
            {
                auto pos = window.getPosition();
                if(!event.key.alt)
                    window.setPosition(sf::Vector2i(pos.x,pos.y+1));
                else
                    window.setPosition(sf::Vector2i(pos.x,pos.y+50));
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Left && !lockedWindow)
            {
                auto pos = window.getPosition();
                if(!event.key.alt)
                    window.setPosition(sf::Vector2i(pos.x-1,pos.y));
                else
                    window.setPosition(sf::Vector2i(pos.x-50,pos.y));
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Right && !lockedWindow)
            {
                auto pos = window.getPosition();
                if(!event.key.alt)
                    window.setPosition(sf::Vector2i(pos.x+1,pos.y));
                else
                    window.setPosition(sf::Vector2i(pos.x+50,pos.y));
            }

            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Tab)
            {
                lockedWindow = (lockedWindow)? false : true;
            }




            if (event.type == sf::Event::TextEntered)
            {
                auto unicode = event.text.unicode;
                if(unicode == 10) // return
                {
                    // Treating the command...
                    // first we try to find the names

                    // lowering
                    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
                    //std::cout << command << std::endl;
                    if(command == "g")
                    {
                        scoreboard.incrementTeamScore("gryffindor", 1);
                    }
                    else if(command == "s")
                    {
                        scoreboard.incrementTeamScore("slytherin", 1);
                    }
                    else if(command == "r")
                    {
                        scoreboard.incrementTeamScore("ravenclaw", 1);
                    }
                    else if(command == "h")
                    {
                        scoreboard.incrementTeamScore("hufflepuff", 1);
                    }
                    else
                    {
                        if (command.find("gryf") != std::string::npos)
                        {
                            command_team_name = "gryffindor";
                        }
                        else if (command.find("slyt") != std::string::npos)
                        {
                            command_team_name = "slytherin";
                        }
                        else if (command.find("rave") != std::string::npos)
                        {
                            command_team_name = "ravenclaw";
                        }
                        else if (command.find("huff") != std::string::npos)
                        {
                            command_team_name = "hufflepuff";
                        }

                        //we found a good team name, then we can look for points
                        if(command_team_name.size() != 0)
                        {
                            std::size_t const n = command.find_first_of("0123456789");
                            if (n != std::string::npos)
                            {
                                std::size_t const m = command.find_first_not_of("0123456789", n);
                                auto number = command.substr(n, m != std::string::npos ? m-n : m);
                                if(!number.empty() && std::all_of(number.begin(), number.end(), ::isdigit))
                                {
                                    command_team_points = std::stoi(number);
                                }
                            }
                        }

                        if(command_team_points >= 0)
                        {
                            if (command.find("-") != std::string::npos)
                            {
                                scoreboard.decrementTeamScore(command_team_name, command_team_points);
                            }
                            else
                            {
                                scoreboard.incrementTeamScore(command_team_name, command_team_points);
                            }
                        }
                    }
                    command.clear();
                    command_team_name.clear();
                    command_team_points = -1;

                }
                else if(unicode == 8) // backspace
                {
                    command.pop_back();
                }
                else
                {
                    command += event.text.unicode;
                }

                command_display.setString(command);
                utils::centerOrigin<sf::Text>(command_display);
            }
        };

        // update Cycle
        scoreboard.update();

        // drawing the Window
        window.clear(sf::Color::Black);


        window.draw(back_sprite);
        window.draw(wall_sprite);
        window.draw(scoreboard);

        // drawing parameter window
        paramW.clear(sf::Color::Black);

        paramW.draw(command_display);

        // End of the current frame
        window.display();

        paramW.display();
    }

    return EXIT_SUCCESS;

}
