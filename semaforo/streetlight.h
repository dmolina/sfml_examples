/*!
 * \file streetlight.h.
 *
 * \brief StreetLight class Include.
 */
#include <SFML/Graphics.hpp>

/**
 * This enum represents the mode of the streetlight.
 */
enum StreetLight_mode { Stop = 1, Careful = 2, Run = 3, None = 4 };

/**
 * This class represent a streetlight.
 *
 * It maintains a red, and yellow, and a green lights (circles), and it turns on
 * each one in function on its mode.
 */
class StreetLight {
private:
  sf::CircleShape *red;
  sf::CircleShape *yellow;
  sf::CircleShape *green;
  StreetLight_mode current;

private:
  /**
   * Change the current mode.
   * 
   * The lights are turn on and turn off according to the current mode.
   *
   * @param mode of the streetlight (from StreetLight_mode).
   *
   */
  void setMode(StreetLight_mode mode);

public:
  /*!
   * Constructor of the StreetLight
   *
   * @param size of the circles of the streetlight.
   */
  StreetLight(int size);
  /**
   * Destructor
   */
  ~StreetLight();
  /**
   * Change to next mode.
   *
   * From None -> Stop, Stop -> Run, Run -> Careful, Careful -> Stop.
   */
  void nextMode(void);
  /**
   * Reset the streetlight to initial mode.
   */
  void reset(void) { setMode(None); }
  /**
   * Draw the streetlight.
   *
   * @param windows in which the streetlight will be shown.
   */
  void draw(sf::RenderWindow &windows);
};
