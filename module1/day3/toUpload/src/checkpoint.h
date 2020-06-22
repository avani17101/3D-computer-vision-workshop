#include "main.h"


#ifndef CHECK_H
#define CHECK_H


class CheckPoint{

public:
    CheckPoint() {}
    CheckPoint(float x, float y);
    glm::vec3 position;
    glm::vec3 aim;
    int rotation_ship;
    int rotation_arrow;


    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;

    void draw(glm::mat4 VP);
    bool tick(glm::vec3 z_ref);
    int timer = 0;

private:
    VAO *ship;
    VAO *structure;
    
    VAO *canon;
    VAO *structure1;

    VAO *arrow;
    VAO *structure2;


};

#endif 