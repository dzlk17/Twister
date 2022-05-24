#include "color.h"

bool Color::FreePlaces()
{
    for (auto i : places)
    {
        if( i == true)
            return true;
    }
    return false;
}

Color RandomColor(std::array<Color, C>& colours)
{
    int n = random(C);
    if(colours[n].FreePlaces())
        return colours[n];
    return RandomColor(colours);
}

QString RandomPlace(Color &col, Player& player)
{
        int m = random(N);
        while( !col.places[m])
        {
            m = random(N);
        }
        col.places[m] = false;
        return player.random_limb(&(col.places[m])) + " " + QString::number(m+1);
}

