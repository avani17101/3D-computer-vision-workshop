#include "main.h"

#ifndef SEG_H
#define SEG_H


class Seg {
public:
    Seg() {}
    Seg(int pos);
    glm::vec3 position;
    glm::vec3 position1;

    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;

    void draw(glm::mat4 VP);
    // void tick(glm::vec3 x_ref, glm::vec3 y_ref, glm::vec3 z_ref);
    void tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position, int number);
    int number;
private:
    VAO *a;
    VAO *b;
    VAO *c;
    VAO *d;
    VAO *e;
    VAO *f;
    VAO *g;

};

#endif // JP_H
