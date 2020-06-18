#include "main.h"

#ifndef JET_H
#define JET_H


class Jet {
public:
    Jet() {}
    Jet(float xs, float ys, color_t color);
    glm::vec3 position;
    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;
    
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    void left();
    void right();
    void up();
    void down();
    void rollRight();
    // void rollRight?();
    void rollLeft();
    void forward();
    void hover();
    float speed;
    double rotation;
    double pitch;
    double roll;
    int fuel;

private:
    VAO *object;
    VAO *structure;
};


#endif