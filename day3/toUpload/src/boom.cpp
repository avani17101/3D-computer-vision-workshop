#include "boom.h"

Bomb::Bomb(glm::vec3 position, glm::vec3 z_ref) {
    
    this->position = position;
    this->z_speed = z_ref;
    // this->x_ref = x_ref;
    // this->y_ref = y_ref;
    
    this->z_ref = (z_ref);
    
    glm::vec3 temp_x;
    
    temp_x.x = z_ref.x + 1;
    temp_x.y = z_ref.y + 1;
    temp_x.z = z_ref.z + 1;
    this->gravity = 0;


    this->x_ref = glm::normalize(glm::cross(glm::normalize(temp_x), z_ref));
    this->y_ref = glm::normalize(glm::cross(z_ref, x_ref));

    // this->rotation = 0;
    // this->pitch = 0;
    // this->roll = 0;

    
    // speed = 1;
    float scale_x = 0.3f;
    
    static GLfloat g_vertex_buffer_data[1260];
    static GLfloat g_vertex_buffer_data2[432];
    
    GLfloat x[30], y[30];

    for(int i = 0; i < 30; ++i)
    {
        x[i] = scale_x*cos(2*3.14*i/10);
        y[i] = scale_x*sin(2*3.14*i/10);

    }

    
    for(int i = 0; i < 10; ++i)

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
       g_vertex_buffer_data[18*i+8]  = scale_x;
       g_vertex_buffer_data[18*i+9]  = x[i+j];
       g_vertex_buffer_data[18*i+10] = y[i+j];
       g_vertex_buffer_data[18*i+11] = scale_x;  
       g_vertex_buffer_data[18*i+12] = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+13] = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+14] = scale_x;
       g_vertex_buffer_data[18*i+15] = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+16] = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+17] = 0;
    }

    




    for(int j = 0; j < 5; ++j)
    {
        for(int i = 0; i < 10; ++i)
        {
           g_vertex_buffer_data[18*i + 180* (j+1)]       = x[j] * x[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 1]  = x[j] * y[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 2]  = 2*scale_x + y[j]/(scale_x * 2); //back
           g_vertex_buffer_data[18*i + 180* (j+1) + 3]  = x[j] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 4]  = x[j] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 5]  = 2*scale_x + y[j]/(scale_x * 2); //back
           g_vertex_buffer_data[18*i + 180* (j+1) + 6]  = x[j+1] *x[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 7]  = x[j+1] *y[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 8]  = 2*scale_x + y[j+1]/(scale_x * 2);//front
           g_vertex_buffer_data[18*i + 180* (j+1) + 9]  = x[j+1] * x[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 10] = x[j+1] * y[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 11] = 2*scale_x  + y[j+1]/(scale_x * 2);  //front
           g_vertex_buffer_data[18*i + 180* (j+1) + 12] = x[j+1] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 13] = x[j+1] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 14] = 2*scale_x + y[j+1]/(scale_x * 2);//front
           g_vertex_buffer_data[18*i + 180* (j+1) + 15] = x[j] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 16] = x[j] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 17] = 2*scale_x + y[j]/(scale_x * 2);//back

        }
    }

    for(int i = 0; i < 10; ++i)

    {
       int j = 0;
       g_vertex_buffer_data[1080 + 18*i]    = x[i+j];
       g_vertex_buffer_data[1080 + 18*i+1]  = y[i+j];
       g_vertex_buffer_data[1080 + 18*i+2]  = -2.0f * scale_x;
       g_vertex_buffer_data[1080 + 18*i+3]  = x[(i+j+1)%30];
       g_vertex_buffer_data[1080 + 18*i+4]  = y[(i+j+1)%30];
       g_vertex_buffer_data[1080 + 18*i+5]  = -2.0f * scale_x;
       g_vertex_buffer_data[1080 + 18*i+6]  = x[i+j];
       g_vertex_buffer_data[1080 + 18*i+7]  = y[i+j];
       g_vertex_buffer_data[1080 + 18*i+8]  = -1.0f * scale_x;
       g_vertex_buffer_data[1080 + 18*i+9]  = x[i+j];
       g_vertex_buffer_data[1080 + 18*i+10] = y[i+j];
       g_vertex_buffer_data[1080 + 18*i+11] =-1.0f * scale_x;  
       g_vertex_buffer_data[1080 + 18*i+12] = x[(i+j+1)%30];
       g_vertex_buffer_data[1080 + 18*i+13] = y[(i+j+1)%30];
       g_vertex_buffer_data[1080 + 18*i+14] = -1.0f * scale_x;
       g_vertex_buffer_data[1080 + 18*i+15] = x[(i+j+1)%30];
       g_vertex_buffer_data[1080 + 18*i+16] = y[(i+j+1)%30];
       g_vertex_buffer_data[1080 + 18*i+17] = -2.0f * scale_x;
    }

    for(int i = 0; i < 10; ++i)

    {
        int j = 0;
       g_vertex_buffer_data2[18*i]    = x[i+j];
       g_vertex_buffer_data2[18*i+1]  = y[i+j];
       g_vertex_buffer_data2[18*i+2]  = scale_x;
       g_vertex_buffer_data2[18*i+3]  = x[(i+j+1)%30];
       g_vertex_buffer_data2[18*i+4]  = y[(i+j+1)%30];
       g_vertex_buffer_data2[18*i+5]  = scale_x;
       g_vertex_buffer_data2[18*i+6]  = x[i+j];
       g_vertex_buffer_data2[18*i+7]  = y[i+j];
       g_vertex_buffer_data2[18*i+8]  = 2*scale_x;
       g_vertex_buffer_data2[18*i+9]  = x[i+j];
       g_vertex_buffer_data2[18*i+10] = y[i+j];
       g_vertex_buffer_data2[18*i+11] = 2*scale_x;  
       g_vertex_buffer_data2[18*i+12] = x[(i+j+1)%30];
       g_vertex_buffer_data2[18*i+13] = y[(i+j+1)%30];
       g_vertex_buffer_data2[18*i+14] = 2*scale_x;
       g_vertex_buffer_data2[18*i+15] = x[(i+j+1)%30];
       g_vertex_buffer_data2[18*i+16] = y[(i+j+1)%30];
       g_vertex_buffer_data2[18*i+17] = scale_x;
    }

    for(int i = 0; i < 10; ++i)

    {
        int j = 0;
       g_vertex_buffer_data2[180 + 18*i]    = x[i+j];
       g_vertex_buffer_data2[180 + 18*i+1]  = y[i+j];
       g_vertex_buffer_data2[180 + 18*i+2]  = -1.0f*scale_x;
       g_vertex_buffer_data2[180 + 18*i+3]  = x[(i+j+1)%30];
       g_vertex_buffer_data2[180 + 18*i+4]  = y[(i+j+1)%30];
       g_vertex_buffer_data2[180 + 18*i+5]  = -1.0f*scale_x;
       g_vertex_buffer_data2[180 + 18*i+6]  = x[i+j];
       g_vertex_buffer_data2[180 + 18*i+7]  = y[i+j];
       g_vertex_buffer_data2[180 + 18*i+8]  = 0;
       g_vertex_buffer_data2[180 + 18*i+9]  = x[i+j];
       g_vertex_buffer_data2[180 + 18*i+10] = y[i+j];
       g_vertex_buffer_data2[180 + 18*i+11] = 0;  
       g_vertex_buffer_data2[180 + 18*i+12] = x[(i+j+1)%30];
       g_vertex_buffer_data2[180 + 18*i+13] = y[(i+j+1)%30];
       g_vertex_buffer_data2[180 + 18*i+14] = 0;
       g_vertex_buffer_data2[180 + 18*i+15] = x[(i+j+1)%30];
       g_vertex_buffer_data2[180 + 18*i+16] = y[(i+j+1)%30];
       g_vertex_buffer_data2[180 + 18*i+17] = -1.0f*scale_x;
    }


    color_t missile1 = {0, 0, 0};
    color_t missile2 = {255, 170, 0};
   

    this->object    = create3DObject(GL_TRIANGLES, 1260/3, g_vertex_buffer_data, missile1, GL_FILL);
    this->structure = create3DObject(GL_TRIANGLES, 1260/3, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);
    this->object1    = create3DObject(GL_TRIANGLES, 360/3, g_vertex_buffer_data2, missile2, GL_FILL);
    this->structure1 = create3DObject(GL_TRIANGLES, 360/3, g_vertex_buffer_data2, COLOR_BLACK, GL_LINE);

}

void Bomb::draw(glm::mat4 VP) {
    
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    float scale_mat = 4;
    scale[0] = glm::vec4(scale_mat,0,0,0);
    scale[1] = glm::vec4(0,scale_mat,0,0);
    scale[2] = glm::vec4(0,0,scale_mat,0);
    scale[3] = glm::vec4(0,0,0,1);
    
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate;

    rotate[0] = glm::vec4(x_ref, 0.0);
    rotate[1] = glm::vec4(y_ref, 0.0);
    rotate[2] = glm::vec4(z_ref, 0.0);
    rotate[3] = glm::vec4(0.0,0.0,0.0, 1.0);



    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->structure);
    draw3DObject(this->object1);
    draw3DObject(this->structure1);


}



void Bomb::tick() {

  this->position += this->z_speed;
  this->position -= glm::vec3(0,1,0)*this->gravity;
  this->gravity += 0.01;
  
}

