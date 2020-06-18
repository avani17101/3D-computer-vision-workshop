#include "circular.h"
#include "main.h"

circularRing::circularRing(int xs, int ys) {

    this->position = glm::vec3(xs,20+(rand()%2)*10,ys);

   GLfloat x[30], y[30];
    
    for(int i = 0; i < 30; ++i)
    {
        x[i] = 20*cos(2*M_PI*i/30);
        y[i] = 20*sin(2*M_PI*i/30);

    }


    static GLfloat g_vertex_buffer_data6[30*18];

    for(int i = 0; i < 30; ++i)
    {
        int j = 0;
       g_vertex_buffer_data6[18*i]    = 1*x[i+j];
       g_vertex_buffer_data6[18*i+1]  = 1*y[i+j];
       g_vertex_buffer_data6[18*i+2]  = 0;
       g_vertex_buffer_data6[18*i+3]  = 1*x[(i+j+1)%30];
       g_vertex_buffer_data6[18*i+4]  = 1*y[(i+j+1)%30];
       g_vertex_buffer_data6[18*i+5]  = 0;
       g_vertex_buffer_data6[18*i+6]  = 0.9  * x[i+j];
       g_vertex_buffer_data6[18*i+7]  = 0.9  * y[i+j];
       g_vertex_buffer_data6[18*i+8]  = 0;
       g_vertex_buffer_data6[18*i+9]  = 0.9  * x[i+j];
       g_vertex_buffer_data6[18*i+10] = 0.9  * y[i+j];
       g_vertex_buffer_data6[18*i+11] = 0;
       g_vertex_buffer_data6[18*i+12] = 1*x[(i+j+1)%30];
       g_vertex_buffer_data6[18*i+13] = 1*y[(i+j+1)%30];
       g_vertex_buffer_data6[18*i+14] = 0;
       g_vertex_buffer_data6[18*i+15] = 0.9  * x[(i+j+1)%30];
       g_vertex_buffer_data6[18*i+16] = 0.9  * y[(i+j+1)%30];
       g_vertex_buffer_data6[18*i+17] = 0;

    }
    color_t snoke = {25,25,25};

    this->object    = create3DObject(GL_TRIANGLES, 10*18,  g_vertex_buffer_data6, snoke, GL_FILL);
   
}

void circularRing::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
      // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // draw3DObject(this->obect);
    draw3DObject(this->object);

}