#include "SFML_VE.h"

void MotionState::time_step(sf::Time delta_time, int time_multplier)
{
    position += (delta_time.asSeconds() * time_multplier) * velocity;
    velocity += (delta_time.asSeconds() * time_multplier) * acceleration;
}

float operator&(const sf::Vector2f v1, const sf::Vector2f v2) { return v1.x * v1.x + v2.y * v2.y; }

float magnitude_sqr(sf::Vector2f v) { return v & v; }
float magnitude(sf::Vector2f v) { return sqrt(magnitude_sqr(v)); }

// The unit direction vector going from v1 to v2
sf::Vector2f dirvec(sf::Vector2f v_start, sf::Vector2f v_end, bool unit)
{
    if (unit)
        return (v_end - v_start) / magnitude(v_end - v_start);
    else
        return v_end - v_start;
}
