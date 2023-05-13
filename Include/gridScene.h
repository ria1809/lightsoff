
#ifndef LIGHTSOFF_GRIDSCENE_H
#define LIGHTSOFF_GRIDSCENE_H
#include <vector>
#include <random>
#include "Box.h"
#include "mouseEvent.h"
#include "threepp/threepp.hpp"
using namespace threepp;

class BoxScene {
public:
    BoxScene();
    void run();
    bool checkWin();

    int moves = 0;
    const int SIZE = 5;

private:
    Canvas m_canvas;
    GLRenderer m_renderer;
    std::shared_ptr<Scene> m_scene;
    std::shared_ptr<OrthographicCamera> m_camera;
    std::shared_ptr<BoxGeometry> m_geometry;
    std::shared_ptr<MeshBasicMaterial> m_material, m_whiteMaterial, m_yellowMaterial;
    std::vector<std::vector<Box>> m_boxes;
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<> m_dis;
    MyMouseListener m_mouseListener;
    std::shared_ptr<Mesh> mesh;
    Color color;

    Vector2 getBoxAtPosition(Vector2 pos);

    void createBoxes();
    void changeBoxColors();
    void toggle(Vector2 pos);
    void animate();


};

#endif //LIGHTSOFF_GRIDSCENE_H
