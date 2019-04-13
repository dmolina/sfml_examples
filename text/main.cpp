#include <SFML/Graphics.hpp>
#include "textboard.h"

using namespace sf;


int main(void) {
  sf::RenderWindow window(sf::VideoMode(400, 200), "Tablero!");
  TextBoard board(400, 200, "Hola");

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
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            board.updateText("Adios");
          }
        }
      }

      window.clear();
      board.draw(window);
      window.display();
    }

  return 0;
}
