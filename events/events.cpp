#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main(void) {
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Black);

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed) {
            window.close();
          }
          else if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
              window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
              shape.setFillColor(sf::Color::Red);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
              shape.setFillColor(sf::Color::Green);
            }
 
        }


     }
      window.clear();
      window.draw(shape);
      window.display();
    }

  return 0;
}
