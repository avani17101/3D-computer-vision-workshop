#include "needle.h"
#include "main.h"

Needle::Needle(color_t color) {

    this->position = glm::vec3(1,1,1);

    this->x_ref = glm::vec3(1,0,0);
    this->y_ref = glm::vec3(0,1,0);
    this->z_ref = glm::vec3(0,0,1);
    score = 1;

    
    static const GLfloat g_vertex_buffer_data[] = {
      0.0f, 0.0f, -0.01f,
      0.0f, 0.3f, -0.01f,
      0.3*cos(4*M_PI/3), 0.3*sin(4*M_PI/3), -0.01f,

      0.0f, 0.0f, -0.01f,
      0.0f, 0.3f, -0.01f,
      -0.3*cos(4*M_PI/3), 0.3*sin(4*M_PI/3), -0.01f,

      
      
    };

    // color_t compass = {204, 34, 0};



    this->object    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data, COLOR_BLACK, GL_FILL);
    
    // this->structure = create3DObject(GL_TRIANGLES, 2?, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);

}

void Needle::draw(glm::mat4 VP, float rotation) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    
    glm::mat4 rotate1 = glm::rotate((float) (-1*rotation), glm::vec3(0,0,1));


    glm::mat4 rotate;
    rotate[0] = glm::vec4(x_ref, 0.0);
    rotate[1] = glm::vec4(y_ref, 0.0);
    rotate[2] = glm::vec4(z_ref, 0.0);
    rotate[3] = glm::vec4(0.0,0.0,0.0, 1.0);



    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate *rotate1);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);


}

void Needle::tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position)
{
  this->x_ref = x;
  this->z_ref = z;
  this->y_ref = y;
  this->position = position - z*8.50f + y_ref*5.0f ;

}