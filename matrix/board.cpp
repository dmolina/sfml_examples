#include "board.h"

static sf::Color cell_bg(203, 239, 241);

Board::Board(int nrows, int ncols, int size) {
  const int tam = nrows * ncols;
  const int thickness = 2.0;
  int total = 0;
  this->nrows = nrows;
  this->ncols = ncols;
  this->size = size;

  this->current = nullptr;
  cells = new sf::RectangleShape *[tam];

  for (int x = 0; x < ncols; x++) {
    for (int y = 0; y < nrows; y++) {
      cells[total] = new sf::RectangleShape(
          sf::Vector2f(size - thickness, size - thickness));
      cells[total]->setPosition(x * size, y * size);
      cells[total]->setFillColor(cell_bg);
      cells[total]->setOutlineColor(sf::Color::Black);
      cells[total]->setOutlineThickness(2.0);
      total += 1;
    }
  }
}

void Board::draw(sf::RenderWindow &windows) {
  int total = nrows * ncols;

  for (int i = 0; i < total; i++) {
    windows.draw(*cells[i]);
  }
}

void Board::action(int posx, int posy) {
  int ix, iy;

  ix = posx / this->size;
  iy = posy / this->size;

  if (current != nullptr) {
    current->setFillColor(cell_bg);
  }

  current = cells[ix * nrows + iy];
  current->setFillColor(sf::Color::Blue);
}

Board::~Board(void) {
  int total = nrows * ncols;

  if (cells == nullptr) {
    return;
  }

  for (int i = 0; i < total; i++) {
    delete cells[i];
  }

  delete[] cells;
  cells = nullptr;
}
