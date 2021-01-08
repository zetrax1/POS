/*!
 * \file    main.cpp
 * \brief   move a sprite with the keyboard (http://www.lucidarme.me/?p=6127)
 * \author  Philippe Lucidarme
 * \version 1.0
 * \date    12/18/2016
 */

// SFML libraries
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "model/mapa.hpp"
#include "model/hrackaPostava.hpp"
#include "controller/hra.hpp"
#include "view/monitor_view.hpp"



// Sprite speed (high values = high speed)
#define         SPRITE_SPEED        5

int main()
{

    controler::Hra hra;

    model::Postava postava;
    postava.setPozicia(50 ,100 );
    hra.addNewPostava(postava);
    hra.init_hra();

    return 0;
}


