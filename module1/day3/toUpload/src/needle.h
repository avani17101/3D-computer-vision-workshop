#include "main.h"
// #include "needle.h"

#ifndef NEEDLE_H
#define NEEDLE_H


class Needle {
public:
    Needle() {}
    Needle(color_t color);
        
    glm::vec3 position;
    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;
    int score;


    
    void draw(glm::mat4 VP, float rotation);
    // void set_position();
    void tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position);
    
   
   
private:
    VAO *object;
    // VAO *structure;
};
#endif