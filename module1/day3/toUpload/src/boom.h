#include "main.h"


#ifndef BOOM_H
#define BOOM_H


class Bomb {
public:
    Bomb() {}
    Bomb(glm::vec3 position, glm::vec3 z_ref);
    
    glm::vec3 position;
    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;
    glm::vec3 z_speed;
    
    void draw(glm::mat4 VP);
    void tick();
    float gravity;
    
private:
    VAO *object; 
    VAO *structure;
    VAO *object1;
    VAO *structure1;
};


#endif