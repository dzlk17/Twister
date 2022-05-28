#include "player.h"

QString Player::random_limb(bool *pl)
{
    switch(random(4))
    {
        case 0:
            if(leftLeg)
                *leftLeg = true;
            leftLeg = pl;
            return "left leg";
        case 1:
            if(rightLeg)
                *rightLeg = true;
            rightLeg = pl;
            return "right leg";
        case 2:
            if(leftHand)
                *leftHand = true;
            leftHand = pl;
            return "left hand";
        case 3:
            if(rightHand)
                *rightHand = true;
            rightHand = pl;
            return "right hand";
    }
    return "right hand";
}

void Player::FreePlayer()
{
    *leftLeg = true;
    *rightLeg = true;
    *leftHand = true;
    *rightHand = true;
}
