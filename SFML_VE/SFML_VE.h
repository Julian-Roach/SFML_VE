#pragma once

#include <SFML/System.hpp>

#define NULLVEC sf::Vector2f(0,0)

class MotionState
{
public:
    MotionState(sf::Vector2f init__position = NULLVEC, sf::Vector2f init__velocity = NULLVEC, sf::Vector2f init__acceleration = NULLVEC)
        : position(init__position), velocity(init__velocity), acceleration(init__acceleration) {};

    sf::Vector2f position, velocity, acceleration;

    void time_step(sf::Time delta_time, int time_multplier = 1);
};

float operator&(const sf::Vector2f v1, const sf::Vector2f v2);

float magnitude_sqr(sf::Vector2f v);
float magnitude(sf::Vector2f v);

// The unit direction vector going from v1 to v2
sf::Vector2f dirvec(sf::Vector2f v_start, sf::Vector2f v_end, bool unit = true);
