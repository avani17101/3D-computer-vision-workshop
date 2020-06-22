#include "main.h"

#ifndef SEA_H
#define SEA_H


class Sea{
public:
    Sea() {}
    Sea(float x, float y, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
private:
    VAO *object;
    VAO *structure;
};

#endif // BALL_H