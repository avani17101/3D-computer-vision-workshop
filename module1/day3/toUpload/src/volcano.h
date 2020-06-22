#include "main.h"

#ifndef VOLC_H
#define VOLC_H


class Volcano{
public:
    Volcano() {}
    Volcano(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
private:
    VAO *object;
    VAO *structure;
        VAO *object1;
    VAO *structure1;
};

#endif // BALL_H