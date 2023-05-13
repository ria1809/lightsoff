//
// Created by Ria Sharma on 12/05/23.
//

#ifndef LIGHTSOFF_MOUSEEVENT_H
#define LIGHTSOFF_MOUSEEVENT_H

#include "threepp/threepp.hpp"
#include "mouseEvent.h"

using namespace threepp;

// MyMouseListener has been copied from threepp/examples/objects/decal.cpp

class MyMouseListener: public MouseListener {

public:

    Vector2 realPos{};
    bool mouseDown = false;
    bool lastMouseState = false;
    Vector2 mouse{-Infinity<float>, -Infinity<float>};

    explicit MyMouseListener(Canvas& canvas): canvas(canvas) {}


    void onMouseDown(int button, const Vector2& pos) override {
        if (button == 0 && !lastMouseState) {// left mousebutton
            mouseDown = true;
            lastMouseState = true;
            realPos = pos;
        }
    }

    void onMouseUp(int button, const Vector2& pos) override {
        lastMouseState = false;
    }

private:
    Canvas& canvas;
};

#endif //LIGHTSOFF_MOUSEEVENT_H
