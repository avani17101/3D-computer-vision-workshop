#include "main.h"
#include "segment.h"
// #include "jet.h"

#ifndef DASHBOARD_H
#define DASHBOARD_H


class DashBoard {
public:
    DashBoard() {}
    DashBoard(color_t color);
        
    glm::vec3 position;
    glm::vec3 x_ref;
    glm::vec3 y_ref;
    glm::vec3 z_ref;
    int score;
    int fuel;
    int speed;
    Seg segs[5];
    int final_score;


    
    void draw(glm::mat4 VP);
    // void set_position();
    void tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position, int fuel, float speed);
    
   
   
private:
    VAO *object;
    
    VAO *level1;
    VAO *level2;
    VAO *level3;
    VAO *level4;
    VAO *level5;
    
    VAO *level11;
    VAO *level12;
    VAO *level13;
    VAO *level14;
    VAO *level15;

    VAO *level111;
    VAO *level112;
    VAO *level113;
    VAO *level114;
    VAO *level115;

    VAO *compass;
    
   
    // VAO *structure;
};
#endif