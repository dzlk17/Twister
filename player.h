#pragma once
#include <iostream>
#include <random>
#include <QApplication>

/**
 * @brief random Function returning random number in the range between 0 and n
 * @param n upper end of range
 * @return random number
 */
inline int random(int n){
    return rand() % n;
}
/**
 * @brief The Player class stores all informations about one player and necessary methods
 */
class Player{
public:
    /**
     * @brief Player Constructor, set player's name. At the beginning player has "free" limbs - doesn't touch any place on the board
     * @param s Player's name
     */
    Player(QString s): name{s}, leftHand{nullptr}, leftLeg{nullptr}, rightHand{nullptr}, rightLeg{nullptr}{}

    /**
     * @brief GetName
     * @return Player's name
     */
    QString GetName() const
    {
        return name;
    }

    /**
     * @brief random_limb Function randomly choose one of limbs and assign to it new place. Previous place is released.
     * @param pl New place choosen for player.
     * @return command for player.
     */
    QString random_limb(bool *pl);

private:
    QString name;
    bool* leftLeg;
    bool* rightLeg;
    bool* leftHand;
    bool* rightHand;
};



