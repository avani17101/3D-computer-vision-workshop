#include "main.h"
#include "jet.h"

#ifndef FUEL_H
#define FUEL_H


class fuelTank {
public:
    fuelTank() {}
    fuelTank(int xs, int ys);
        
    glm::vec3 position;
    
    void draw(glm::mat4 VP);
    // void set_position();
    // void tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position, int fuel, float speed);
    
   
   
private:
    VAO *object;
};

#endif