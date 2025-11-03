#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class ScoreBoard : public sf::Sprite { 
public:
    ScoreBoard();
    ~ScoreBoard();

    void addPts(int value);
    int getPts() const;
    void setPts(int value);
    void Load(std::string fileName);
    void Load(std::string fileName, sf::IntRect rect);
    void update(sf::RenderWindow* window, int timeElapsed);

private:
    int pts; 
    sf::Texture* texture;
};

#endif // SCOREBOARD_H