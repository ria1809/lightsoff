#include "gridScene.h"
#include "mouseEvent.h"
#include "play.h"
#include <iostream>
using namespace threepp;

BoxScene::BoxScene() :
        m_canvas(),
        m_renderer(m_canvas),
        m_scene(Scene::create()),
        m_camera(OrthographicCamera::create(0, 6, 0, 6 , 0.1, 1000)),
        m_geometry(BoxGeometry::create()),
        m_material(MeshBasicMaterial::create()),
        m_yellowMaterial(MeshBasicMaterial::create()),
        m_whiteMaterial(MeshBasicMaterial::create()),
        m_boxes(5, std::vector<std::shared_ptr<Mesh>>(5)),
        m_mouseListener(m_canvas),
        m_rd(),
        m_gen(m_rd()),
        m_dis(0, 1)
{
    m_canvas.addMouseListener(&m_mouseListener);
    m_renderer.setClearColor(Color::black);
    m_camera->position.set(0,0,1);
    m_camera->lookAt(0,0,0);
    m_material->color.setRGB(1, 1, 1);
    m_whiteMaterial->color.setRGB(1, 1, 1);
    m_yellowMaterial->color.setRGB(1, 1, 0);

}


void BoxScene::createBoxes() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            auto box = Mesh::create(m_geometry, m_material);
            box->position.set(0.1f + box->scale.x*0.5f + i*(box->scale.x+0.1f), 0.1f + box->scale.x*0.5f + j*(box->scale.y+0.1f),0); // set the position of the box
            m_boxes[i][j]=box; // assign the box
            m_scene->add(box); // add the box to the scene
        }
    }
}

void BoxScene::changeBoxColors() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Randomly decide whether to change the color of this box to yellow
            if (m_dis(m_gen) == 0) {
                auto box = m_boxes[i][j];
                auto yellowMaterial = MeshBasicMaterial::create();
                yellowMaterial->color.setRGB(1, 1, 0);
                box->setMaterial(yellowMaterial);

            }
        }
    }
}


void BoxScene::animate() {
    m_canvas.animate([&](float dt) -> void {
        std::cout<< m_mouseListener.mouseClick() << std::endl;
    },
        m_renderer.render(m_scene, m_camera));
    }
void BoxScene::run() {
    play playObject;
    createBoxes();
    changeBoxColors();
    playObject.toggle();
    playObject.win();
    animate();
}

