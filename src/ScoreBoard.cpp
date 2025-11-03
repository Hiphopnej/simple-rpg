
#include "ScoreBoard.h"
#include <stdexcept>


ScoreBoard::ScoreBoard() {
    pts = 0;
    texture = new sf::Texture();
}

ScoreBoard::~ScoreBoard() {
    delete texture;
}

void ScoreBoard::addPts(int value) {
    pts += value;
}

int ScoreBoard::getPts() const {
    return pts;
}

void ScoreBoard::setPts(int value) {
    pts = value;
}

void ScoreBoard::Load(std::string fileName) {
    if (texture->loadFromFile(fileName, sf::IntRect())) {
        setTexture(*texture); // Use setTexture from sf::Sprite
    } else {
        throw std::runtime_error("Failed to load texture from file: " + fileName);
    }
}

void ScoreBoard::Load(std::string fileName, sf::IntRect rect) {
    if (texture->loadFromFile(fileName, rect)) {
        setTexture(*texture); // Use setTexture from sf::Sprite
    } else {
        throw std::runtime_error("Failed to load texture from file: " + fileName);
    }
}

