
#ifndef LIGHTSOFF_GRIDSCENE_H
#define LIGHTSOFF_GRIDSCENE_H
#include <vector>
#include <random>
#include "mouseEvent.h"
#include "threepp/threepp.hpp"
using namespace threepp;

class BoxScene {
public:
    BoxScene();
    void run();
    void checkWin();

private:
    Canvas m_canvas;
    GLRenderer m_renderer;
    std::shared_ptr<Scene> m_scene;
    std::shared_ptr<OrthographicCamera> m_camera;
    std::shared_ptr<BoxGeometry> m_geometry;
    std::shared_ptr<MeshBasicMaterial> m_material, m_whiteMaterial, m_yellowMaterial;
    std::vector<std::vector<std::shared_ptr<Mesh>>> m_boxes;
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<> m_dis;
    MyMouseListener m_mouseListener;
    std::shared_ptr<Mesh> mesh;
    Color color;


    void createBoxes();
    void changeBoxColors();
    void animate();


};

#endif //LIGHTSOFF_GRIDSCENE_H
