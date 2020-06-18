#include "main.h"

#ifndef ARROW_H
#define ARROW_H


class Arrow{
public:
    Arrow() {}
    Arrow(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick(glm::vec3 position);
private:
    VAO *object;
    VAO *structure;
     
};

#endif // BALL_H