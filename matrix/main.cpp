#include <SFML/Graphics.hpp>
#include "board.h"

using namespace sf;

int main(void) {
  sf::RenderWindow window(sf::VideoMode(800, 800), "Tablero!");
  Board board(8, 8, 100);

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            window.close();
          }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
          board.action(event.mouseButton.x, event.mouseButton.y);
        }
      }

      window.clear();
      board.draw(window);
      window.display();
    }

  return 0;
}
