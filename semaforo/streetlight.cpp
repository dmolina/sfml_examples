/*!
 * \file streetlight.cpp.
 *
 * \brief StreetLight class Implementation.
 */
#include "streetlight.h"

static sf::Color background = sf::Color(100, 100, 100);

StreetLight::StreetLight(int size) {
  red = new sf::CircleShape(size);
  red->setFillColor(sf::Color::Red);
  yellow = new sf::CircleShape(size);
  yellow->setFillColor(sf::Color::Yellow);
  yellow->setPosition(0, 2*size);
  green = new sf::CircleShape(size);
  green->setFillColor(sf::Color::Green);
  green->setPosition(0, 4*size);
  current = None;
}

void StreetLight::setMode(StreetLight_mode mode) {
  // Turn off the current
  if (current == None) {
    red->setFillColor(background);
    yellow->setFillColor(background);
    green->setFillColor(background);
  }
  else if (current == Stop) {
    red->setFillColor(background);
  }
  else if (current == Careful) {
    yellow->setFillColor(background);
  }
  else if (current == Run) {
    green->setFillColor(background);
  }

  if (mode == Stop) {
    red->setFillColor(sf::Color::Red);
  }
  else if (mode == Careful) {
    yellow->setFillColor(sf::Color::Yellow);
  }
  else if (mode == Run){
    green->setFillColor(sf::Color::Green);
  }
  else {
    red->setFillColor(sf::Color::Red);
    yellow->setFillColor(sf::Color::Yellow);
    green->setFillColor(sf::Color::Green);
  }

  current = mode;
}

void StreetLight::nextMode() {
  StreetLight_mode next;

  if (current == None) {
    next = Stop;
  }
  else if (current == Stop) {
    next = Run;
  }
  else if (current == Run) {
    next = Careful;
  }
  else {
    next = Stop;
  }

  setMode(next);
}

void StreetLight::draw(sf::RenderWindow &windows) {
  windows.draw(*red);
  windows.draw(*green);
  windows.draw(*yellow);
}

StreetLight::~StreetLight() {
  if (red != nullptr) {
    delete red;
  }
  else if (green) {
    delete green;
  }
  else if (yellow) {
    delete yellow;
  }
}
