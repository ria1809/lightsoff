

#ifndef LIGHTSOFF_KEYLISTENER_HPP
#define LIGHTSOFF_KEYLISTENER_HPP

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

#endif //LIGHTSOFF_KEYLISTENER_HPP
