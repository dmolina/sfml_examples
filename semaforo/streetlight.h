#include <SFML/Graphics.hpp>

enum StreetLight_mode { Stop=1, Careful=2, Run=3, None=4};

class StreetLight {
private:
  sf::CircleShape *red;
  sf::CircleShape *yellow;
  sf::CircleShape *green;
  StreetLight_mode current;

private:
  void setMode(StreetLight_mode mode);

public:
  StreetLight(int size);
  ~StreetLight();
  void nextMode(void);
  void reset(void) {
    setMode(None);
  }
  void draw(sf::RenderWindow &windows);
};
