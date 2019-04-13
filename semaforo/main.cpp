#include <SFML/Graphics.hpp>
#include "streetlight.h"

using namespace sf;

int main(void) {
  sf::RenderWindow window(sf::VideoMode(200, 600), "SFML works!");
  StreetLight sem(100.0f);

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
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            sem.nextMode();
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            sem.reset();
          }
        }
      }

      window.clear();
      sem.draw(window);
      window.display();
    }

  return 0;
}
