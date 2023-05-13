//
// Created by Ria Sharma on 13/05/23.
//

#ifndef LIGHTSOFF_BOX_H
#define LIGHTSOFF_BOX_H
#include "threepp/threepp.hpp"

using namespace threepp;

struct Box {

    std::shared_ptr<Mesh> mesh;
    Color color;

    void setColor(Color _color) {
        color = _color;
        auto material = MeshBasicMaterial::create();
        material->color = _color;
        mesh->setMaterial(material);
    };

    void toggle() {
        if (color == Color::white) {
            setColor(Color::yellow);
        } else {
            setColor(Color::white);
        }
    }
};
#endif //LIGHTSOFF_BOX_H
