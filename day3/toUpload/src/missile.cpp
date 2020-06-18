#include "missile.h"

Missile::Missile(glm::vec3 position, glm::vec3 z_ref) {
    
    this->position = position;
    this->z_speed = z_ref;
    // this->x_ref = x_ref;
    // this->y_ref = y_ref;
    this->z_ref = (z_ref);
    glm::vec3 temp_x;
    

    temp_x = temp_x + glm::vec3(0,0,1);


    this->x_ref = glm::normalize(glm::cross(glm::normalize(temp_x), z_ref));
    this->y_ref = glm::normalize(glm::cross(z_ref, x_ref));

    // this->rotation = 0;
    // this->pitch = 0;
    // this->roll = 0;

    
    // speed = 1;
    float scale_x = 0.03f;
    
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

//fin1;
    g_vertex_buffer_data2[360] = 0.0f;
    g_vertex_buffer_data2[361] = scale_x;
    g_vertex_buffer_data2[362] = 0.0f;

    g_vertex_buffer_data2[363] = 0.0f;
    g_vertex_buffer_data2[364] = 2*scale_x;
    g_vertex_buffer_data2[365] = 0.0f;
    
    g_vertex_buffer_data2[366] = 0.0f;
    g_vertex_buffer_data2[367] = scale_x;
    g_vertex_buffer_data2[368] = 1.5 * scale_x;

//fin2;
    g_vertex_buffer_data2[369] = scale_x;
    g_vertex_buffer_data2[370] = 0.0f;
    g_vertex_buffer_data2[371] = 0.0f;

    g_vertex_buffer_data2[372] = 2*scale_x;
    g_vertex_buffer_data2[373] = 0.0f;
    g_vertex_buffer_data2[374] = 0.0f;
    
    g_vertex_buffer_data2[375] = scale_x;
    g_vertex_buffer_data2[376] = 0.0f;
    g_vertex_buffer_data2[377] = 1.5 * scale_x;

//fin3;
    g_vertex_buffer_data2[378] = 0.0f;
    g_vertex_buffer_data2[379] = -1*scale_x;
    g_vertex_buffer_data2[380] = 0.0f;

    g_vertex_buffer_data2[381] = 0.0f;
    g_vertex_buffer_data2[382] = -2*scale_x;
    g_vertex_buffer_data2[383] = 0.0f;
    
    g_vertex_buffer_data2[384] = 0.0f;
    g_vertex_buffer_data2[385] = -1*scale_x;
    g_vertex_buffer_data2[386] = 1.5 * scale_x;

//fin4;

    g_vertex_buffer_data2[387] =-1.0f*scale_x;
    g_vertex_buffer_data2[388] = 0.0f;
    g_vertex_buffer_data2[389] = 0.0f;

    g_vertex_buffer_data2[390] = -2.0f*scale_x;
    g_vertex_buffer_data2[391] = 0.0f;
    g_vertex_buffer_data2[392] = 0.0f;
    
    g_vertex_buffer_data2[393] = -1.0f*scale_x;
    g_vertex_buffer_data2[394] = 0.0f;
    g_vertex_buffer_data2[395] = 1.5 * scale_x;

//repeating fins behind : 

    g_vertex_buffer_data2[396] = 0.0f;
    g_vertex_buffer_data2[397] = scale_x;
    g_vertex_buffer_data2[398] = 0.0f - 2.0f*scale_x;

    g_vertex_buffer_data2[399] = 0.0f;
    g_vertex_buffer_data2[400] = 2*scale_x;
    g_vertex_buffer_data2[401] = 0.0f - 2.0f*scale_x;
    
    g_vertex_buffer_data2[402] = 0.0f;
    g_vertex_buffer_data2[403] = scale_x;
    g_vertex_buffer_data2[404] = 1.5 * scale_x - 2.0f*scale_x;

//fin2;
    g_vertex_buffer_data2[405] = scale_x;
    g_vertex_buffer_data2[406] = 0.0f;
    g_vertex_buffer_data2[407] = 0.0f - 2.0f*scale_x;

    g_vertex_buffer_data2[408] = 2*scale_x;
    g_vertex_buffer_data2[409] = 0.0f;
    g_vertex_buffer_data2[410] = 0.0f - 2.0f*scale_x;
    
    g_vertex_buffer_data2[411] = scale_x;
    g_vertex_buffer_data2[412] = 0.0f;
    g_vertex_buffer_data2[413] = 1.5 * scale_x - 2.0f*scale_x;

//fin3;
    g_vertex_buffer_data2[414] = 0.0f;
    g_vertex_buffer_data2[415] = -1*scale_x;
    g_vertex_buffer_data2[416] = 0.0f - 2.0f*scale_x;

    g_vertex_buffer_data2[417] = 0.0f;
    g_vertex_buffer_data2[418] = -2*scale_x;
    g_vertex_buffer_data2[419] = 0.0f - 2.0f*scale_x;
    
    g_vertex_buffer_data2[420] = 0.0f;
    g_vertex_buffer_data2[421] = -1*scale_x;
    g_vertex_buffer_data2[422] = 1.5 * scale_x - 2.0f*scale_x;

//fin4;

    g_vertex_buffer_data2[423] =-1.0f*scale_x;
    g_vertex_buffer_data2[424] = 0.0f;
    g_vertex_buffer_data2[425] = 0.0f - 2.0f*scale_x;

    g_vertex_buffer_data2[426] = -2.0f*scale_x;
    g_vertex_buffer_data2[427] = 0.0f;
    g_vertex_buffer_data2[428] = 0.0f - 2.0f*scale_x;
    
    g_vertex_buffer_data2[429] = -1.0f*scale_x;
    g_vertex_buffer_data2[430] = 0.0f;
    g_vertex_buffer_data2[431] = 1.5 * scale_x - 2.0f*scale_x;


    


    color_t missile1={255,119, 51};
    color_t missile2={255, 242,230};
   

    this->object    = create3DObject(GL_TRIANGLES, 1260/3, g_vertex_buffer_data, missile1, GL_FILL);
    this->structure = create3DObject(GL_TRIANGLES, 1260/3, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);
    this->object1    = create3DObject(GL_TRIANGLES, 432/3, g_vertex_buffer_data2, missile2, GL_FILL);
    this->structure1 = create3DObject(GL_TRIANGLES, 432/3, g_vertex_buffer_data2, COLOR_BLACK, GL_LINE);

}

void Missile::draw(glm::mat4 VP) {
    
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    float scale_mat = 6;
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



void Missile::tick() {

  this->position += this->z_speed*2.0f;
  
}

