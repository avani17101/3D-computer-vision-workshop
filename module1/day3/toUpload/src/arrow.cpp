#include "arrow.h"
#include "main.h"

Arrow::Arrow(float x, float y) {
    this->position = glm::vec3(x, 0, 1.0 * y);
    
    static const GLfloat g_vertex_buffer_data[] = {
      0.0f  , -0.4f, 0.0f,
      40.0f, -0.4f , 0.0f,
      20.0f  , 30.4f, 20.0f,

      0.0f, -0.4f , 0.0f,
      0.0f  , -0.4f, 40.0f,
      20.0f, 30.4f, 20.0f,


      40.0f, -0.4f , 40.0f,
      0.0f  , -0.4f, 40.0f,
      20.0f, 30.4f, 20.0f,
      
      40.0f, -0.4f , 40.0f,
      40.0f  , -0.4f, 0.0f,
      20.0f, 30.4f, 20.0f,
      
    };
    



    color_t color = {255, 128, 0};
    color_t color1 = {  255, 0,0};
    this->object    = create3DObject(GL_TRIANGLES, 12, g_vertex_buffer_data, color1, GL_FILL);
    // this->structure    = create3DObject(GL_TRIANGLES, 12, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);

}    

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position + glm::vec3(0,80,0) + glm::vec3(40,0,0));    // glTranslatef
    Matrices.model *= (translate*glm::rotate((float)M_PI, glm::vec3(0,0,1)));
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    // draw3DObject(this->structure);

}

void Arrow::tick(glm::vec3 position)
{
  this->position = position;
}