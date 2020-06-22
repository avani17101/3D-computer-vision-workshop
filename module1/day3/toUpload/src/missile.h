#include "main.h"


#ifndef ZOOM_H
#define ZOOM_H


class Missile {
public:
    Missile() {}
    Missile(glm::vec3 position, glm::vec3 z_ref);
    glm::vec3 position;
    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;
    glm::vec3 z_speed;
    
    void draw(glm::mat4 VP);
    void tick();
    
private:
    VAO *object;
    VAO *structure;
    VAO *object1;
    VAO *structure1;
};


#endif