#include "parachute.h"
#include "main.h"

Para::Para(float xs, float ys) {
    
    this->position = glm::vec3(xs, 100, ys);

    
    // ?0.3;
    
    static GLfloat g_vertex_buffer_data[300];
    GLfloat x[30], y[30];

    for(int i = 0; i < 30; ++i)
    {
        x[i] = 2*cos(2*3.14*i/30);
        y[i] = 2*sin(2*3.14*i/30);

    }

    
    for(int i = 1; i < 14; ++i)

    {
        int j = 0;
       g_vertex_buffer_data[18*i]    = x[i+j];
       g_vertex_buffer_data[18*i+1]  = y[i+j];
       g_vertex_buffer_data[18*i+2]  = 0;
       g_vertex_buffer_data[18*i+3]  = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+4]  = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+5]  = 0;
       g_vertex_buffer_data[18*i+6]  = x[i+j];
       g_vertex_buffer_data[18*i+7]  = y[i+j];
       g_vertex_buffer_data[18*i+8]  = 2;
       g_vertex_buffer_data[18*i+9]  = x[i+j];
       g_vertex_buffer_data[18*i+10] = y[i+j];
       g_vertex_buffer_data[18*i+11] = 2;  
       g_vertex_buffer_data[18*i+12] = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+13] = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+14] = 2;
       g_vertex_buffer_data[18*i+15] = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+16] = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+17] = 0;
    }

    static GLfloat g_vertex_buffer_data2[] = 
    {
      x[1], y[1], 0,
      x[1], y[1], 2,
      0, -1, 1,
      x[13], y[13], 0,
      x[13], y[13], 2,
      0, -1, 1,

    };



   
    //tail 1


    color_t color = { 0,153,0};

    this->object    = create3DObject(GL_TRIANGLES, 234/3, g_vertex_buffer_data, color, GL_FILL);
    this->structure = create3DObject(GL_TRIANGLES, 6    , g_vertex_buffer_data2, COLOR_BLACK, GL_LINE);

}

void Para::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate = glm::rotate((float) (rotation * M_PI / 180.0f), glm::vec3(0,1,0));
    glm::mat4 scale = glm::scale(glm::vec3(10,10,10));


    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate*scale);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->structure);

}


void Para::tick(float z) {
      if(this->position.z - z < 450)
      {
        this->position.y -= 0.3f;
      }

      this->position.z -= 0.3f;

         // this->position.y -= speed;
}

