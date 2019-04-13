#include <SFML/Graphics.hpp>

class Board {
  sf::RectangleShape **cells;
  int nrows, ncols;
  int size;
  sf::RectangleShape *current;

public:
  Board(int nrows, int ncols, int size);
  void draw(sf::RenderWindow &windows);
  void action(int posx, int posy);
  ~Board(void);
};
