#include <SFML/Graphics.hpp>
#include <string>

class TextBoard {
  sf::RectangleShape *cell;
  sf::Font font;
  sf::Text *text;

public:
  TextBoard(int sizex, int sizey, std::string text);
  void draw(sf::RenderWindow &windows);
  void updateText(std::string text);
  ~TextBoard();
};
