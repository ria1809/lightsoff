#include "play.h"
#include "gridScene.h"
#include "threepp/threepp.hpp"

using namespace threepp;

void play::toggle(){
    if (color == Color::yellow)
        color = Color::white;
    else
        color = Color::yellow;

    auto material = MeshBasicMaterial::create();
    material->color = color;
    mesh->setMaterial(material);
}
void play::win(){
    // Check if all boxes are white
    bool allWhite = true;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            auto box = m_boxes[i][j];
            auto material = box->material();
            if (color != Color::white) {
                allWhite = false;
                break;
            }
        }
        if (!allWhite) break;
    }

    // If all boxes are white, print out a congratulatory message and prompt user to play again
    if (allWhite) {
        allWhite= true;
    }
}

//
// Created by Ria Sharma on 12/05/23.
//
