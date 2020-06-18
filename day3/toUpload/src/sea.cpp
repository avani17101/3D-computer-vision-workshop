#include "sea.h"
#include "main.h"

Sea::Sea(float x, float y, color_t color) {
    this->position = glm::vec3(x, 0, 1.0 * y);
    
    static const GLfloat g_vertex_buffer_data[] = {
      0.0f  , -0.4f, 0.0f,
      40.0f, -0.4f , 0.0f,
      0.0f  , -0.4f, 40.0f,

      40.0f, -0.4f , 0.0f,
      0.0f  , -0.4f, 40.0f,
      40.0f, -0.4f, 40.0f,



    };
    
    this->object    = create3DObject(GL_TRIANGLES, 6, g_vertex_buffer_data, color, GL_FILL);
    this->structure    = create3DObject(GL_TRIANGLES, 6, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);

}

void Sea::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->structure);


}



