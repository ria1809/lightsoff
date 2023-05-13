//
// Created by Ria Sharma on 12/05/23.
//
#ifndef LIGHTSOFF_PLAY_H
#define LIGHTSOFF_PLAY_H
#include "threepp/threepp.hpp"
using namespace threepp;

class play{
public:
    void toggleAdjacent(int i, int j,std::vector<std::vector<std::shared_ptr<Mesh>>> m_boxes);
    void win(std::vector<std::vector<std::shared_ptr<Mesh>>> m_boxes);
private:
    std::shared_ptr<Mesh> mesh;
    Color color;


};



#endif //LIGHTSOFF_PLAY_H
