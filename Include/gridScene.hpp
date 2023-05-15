
#ifndef LIGHTSOFF_GRIDSCENE_HPP
#define LIGHTSOFF_GRIDSCENE_HPP
#include <vector>
#include <random>
#include "Box.hpp"
#include "mouseEvent.hpp"
#include "keyListener.hpp"
#include "threepp/threepp.hpp"
using namespace threepp;

class BoxScene {
public:
    BoxScene();
    void run();
    bool checkWin();
    void generateValidPattern();
    const int SIZE = 5;
    int moves = 0;


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
    MyKeyListener m_keyListener;
    std::shared_ptr<Mesh> mesh;
    std::vector<std::vector<bool>> m_valids = {
            {true, true, true, false, false},
            {true, true, false, true, true},
            {true, false, true, true, false},
            {true, false, false, false, true},
            {false, true, true, false, true},
            {false, true, false, true, false},
            {false, false, true, true, true}
    };
    Vector2 getBoxAtPosition(Vector2 pos);
    void createBoxes();
    void toggle(Vector2 pos);
    void animate();


};

#endif //LIGHTSOFF_GRIDSCENE_HPP
