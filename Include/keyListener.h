

#ifndef LIGHTSOFF_KEYLISTENER_H
#define LIGHTSOFF_KEYLISTENER_H

#include "threepp/threepp.hpp"
#include <iostream>

using namespace threepp;

struct MyKeyListener: KeyListener {

    bool reset = false;

    void onKeyPressed(KeyEvent evt) override {
        if (evt.key == 82){
            reset = true;
        }

    }

    void onKeyReleased(KeyEvent evt) override {
        if (evt.key == 82){
            reset = false;
        }
    }

    [[nodiscard]] bool onResetPressed() const{

        return reset;
    };
};

#endif //LIGHTSOFF_KEYLISTENER_H
