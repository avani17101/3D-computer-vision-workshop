#include "fueltank.h"
#include "main.h"

fuelTank::fuelTank(int xs, int ys) {

    this->position = glm::vec3(xs,20+(rand()%2)*10,ys);


     static const GLfloat vertex_buffer_data[] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };

    color_t color = {255,77,77};

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);

   
   
    
}

void fuelTank::draw(glm::mat4 VP) {
    glm::mat4 scale = glm::mat4(1.0f);

    float scale_mat = 5;
    scale[0] = glm::vec4(scale_mat,0,0,0);
    scale[1] = glm::vec4(0,scale_mat,0,0);
    scale[2] = glm::vec4(0,0,scale_mat,0);
    scale[3] = glm::vec4(0,0,0,1);
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 shear = glm::mat4(1.0f);

    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    shear[0] = glm::vec4(1.5f, 0.0f, 0.0f, 0.0f);
    shear[1] = glm::vec4(0.0f, 2.5f, 0.0f, 0.0f);
    shear[2] = glm::vec4(0.0f, 0.0f, 0.5f, 0.0f);
    shear[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

      // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * shear * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // draw3DObject(this->obect);
    draw3DObject(this->object);

}