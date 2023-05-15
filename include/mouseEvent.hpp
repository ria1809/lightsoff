

#ifndef LIGHTSOFF_MOUSEEVENT_HPP
#define LIGHTSOFF_MOUSEEVENT_HPP

#include "threepp/threepp.hpp"
#include "mouseEvent.hpp"

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

#endif //LIGHTSOFF_MOUSEEVENT_HPP
