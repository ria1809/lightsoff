#include "play.h"
#include "threepp/threepp.hpp"

using namespace threepp;

void play::toggleAdjacent(int i, int j,std::vector<std::vector<std::shared_ptr<Mesh>>> m_boxes) {
    if (color == Color::yellow)
        color = Color::white;
    else
        color = Color::yellow;

    auto material = MeshBasicMaterial::create();
    material->color = color;
    m_boxes[i][j]->setMaterial(material);

    if (i - 1 >= 0) {
        auto adjacentBox = m_boxes[i - 1][j];
        adjacentBox->setMaterial(material);
    }

    if (i + 1 < m_boxes.size()) {
        auto adjacentBox = m_boxes[i + 1][j];
        adjacentBox->setMaterial(material);
    }

    if (j - 1 >= 0) {
        auto adjacentBox = m_boxes[i][j - 1];
        adjacentBox->setMaterial(material);
    }

    if (j + 1 < m_boxes[0].size()) {
        auto adjacentBox = m_boxes[i][j + 1];
        adjacentBox->setMaterial(material);
    }
}
void play::win(std::vector<std::vector<std::shared_ptr<Mesh>>> m_boxes){
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
