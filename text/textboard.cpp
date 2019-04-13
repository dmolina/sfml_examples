#include "textboard.h"
#include <string>

using namespace std;

static sf::Color cell_bg(203, 239, 241);

TextBoard::TextBoard(int sizex, int sizey, string text) {
  cell = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
  cell->setFillColor(cell_bg);
  font.loadFromFile("sansation.ttf");
  this->text = new sf::Text(text, font);
  this->text->setCharacterSize(100);
  sf::Vector2f pos_text = cell->getPosition();

  pos_text.x += cell->getSize().x/2.0 - this->text->getGlobalBounds().width/2;
  pos_text.y += cell->getSize().y/2.0 - this->text->getLocalBounds().height;
  this->text->setPosition(pos_text);
  this->text->setFillColor(sf::Color::Black);
}


void TextBoard::draw(sf::RenderWindow &windows) {
  windows.draw(*cell);
  windows.draw(*text);
}

void TextBoard::updateText(string text) {
  this->text->setString(text);
}

TextBoard::~TextBoard(void) {
  if (text != nullptr) {
    delete text;
    text = nullptr;
  }
  if (cell != nullptr) {
    delete cell;
    cell = nullptr;
  }
}
