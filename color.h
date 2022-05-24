#pragma once
#include <iostream>
#include <array>
#include "player.h"

#define N 6
#define C 4

/**
 * @brief The Color class - stores all places of the same color on the board, color name and methods necessary to manage them
 */
class Color
{
public:
    /**
     * @brief RandomPlace Friend function which choose randomly one free place and assign it to player
     * @param col Array of places in one previous choosen color
     * @param player
     * @return command for player
     */
    friend QString RandomPlace(Color &col, Player& player);

    /**
     * @brief Color Constructor, set all places as free and color name
     * @param s Color name
     */
    Color(const char* s): name{s}
    {
        places.fill({true});
    }
    /**
     * @brief GetName
     * @return color name
     */
    QString GetName() const
    {
        return name;
    }
    /**
     * @brief FreePlaces Check if given color contains free places
     * @return
     */
    bool FreePlaces();

private:
    QString name;
    std::array<bool, N> places;
};
/**
 * @brief RandomColor Randomly choose one color from list and use FreePlaces function
 * @param colours Array of colors
 * @return Object of class color which contains free places
 */
Color RandomColor(std::array<Color, C>& colours);




