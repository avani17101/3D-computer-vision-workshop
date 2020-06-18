#include "volcano.h"
#include "main.h"

Volcano::Volcano(float x, float y) {
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
    

    static const GLfloat g_vertex_buffer_data2[] = {
      5.0f  , -0.4f, 5.0f,
      35.0f, -0.4f , 5.0f,
      20.0f  , 50.4f, 20.0f,

      5.0f, -0.4f , 5.0f,
      5.0f  , -0.4f, 35.0f,
      20.0f, 50.4f, 20.0f,


      35.0f, -0.4f , 35.0f,
      5.0f  , -0.4f, 35.0f,
      20.0f, 50.4f, 20.0f,
      
      35.0f, -0.4f , 35.0f,
      35.0f  , -0.4f, 5.0f,
      20.0f, 50.4f, 20.0f,
      
    };

    color_t color = {255, 128, 0};
    color_t color1 = {  255, 0,0};
    this->object    = create3DObject(GL_TRIANGLES, 12, g_vertex_buffer_data, color, GL_FILL);
    this->structure    = create3DObject(GL_TRIANGLES, 6, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);
    this->object1    = create3DObject(GL_TRIANGLES, 12, g_vertex_buffer_data2, color1, GL_FILL);
    this->structure1    = create3DObject(GL_TRIANGLES, 6, g_vertex_buffer_data2, COLOR_BLACK, GL_LINE);
       
}

void Volcano::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->structure);
    draw3DObject(this->object1);
    draw3DObject(this->structure1);

}