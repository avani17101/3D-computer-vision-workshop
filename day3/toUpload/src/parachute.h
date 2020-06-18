#include "main.h"

#ifndef PARA_H
#define PARA_H


class Para {
public:
    Para() {}
    Para(float xs, float ys);
    glm::vec3 position;
    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;
    
    void draw(glm::mat4 VP);
    void tick(float z);

private:
    VAO *object;
    VAO *structure;
};


#endif