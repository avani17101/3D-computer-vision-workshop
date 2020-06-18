#include "checkpoint.h"
#include "main.h"

CheckPoint::CheckPoint(float x, float y) 
{
        rotation_ship = 0;
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


    this->timer = 0;  
    this->position = glm::vec3(x, 0, y);
    
    

    color_t color  = {  102, 85,  0};
    color_t color1 = {  255,217, 25};
    color_t color2 = {  179,0, 0};


    this->ship         = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
    this->structure    = create3DObject(GL_TRIANGLES, 12*3  , vertex_buffer_data, COLOR_BLACK, GL_LINE);
    
    this->canon        = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color1, GL_FILL);
    this->structure1   = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_BLACK, GL_LINE);
    
    this->arrow        = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color2, GL_FILL);
    this->structure2   = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_BLACK, GL_LINE);
       
}


void CheckPoint::draw(glm::mat4 VP) 
{

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 translate1 = glm::translate (glm::vec3(20,0,20));    // glTranslatef

    glm::mat4 rotation_ship_mat = glm::rotate((float) (rotation_ship * M_PI / 180.0f), glm::vec3(0,1,0));
    
    glm::mat4 scale = glm::mat4(1.0f);
    float scale_mat = 10;
    scale[0] = glm::vec4(scale_mat,0,0,0);
    scale[1] = glm::vec4(0,0.5f*scale_mat,0,0);
    scale[2] = glm::vec4(0,0,scale_mat,0);
    scale[3] = glm::vec4(0,0,0,1);

    Matrices.model *= (glm::translate(glm::vec3(0,10,0)) * translate * translate1 * rotation_ship_mat * scale);
    glm::mat4 MVP = VP * Matrices.model;
    
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    

    draw3DObject(this->ship);
    draw3DObject(this->structure);







    /*canon*/
    scale_mat = 10;
    scale[0] = glm::vec4(scale_mat , 0              , 0             , 0);
    scale[1] = glm::vec4(0         ,      scale_mat , 0             , 0);
    scale[2] = glm::vec4(0         , 0              , 2.0f*scale_mat, 0);
    scale[3] = glm::vec4(0         , 0              ,0              , 1);


    glm::mat4 rotate;
    rotate[0] = glm::vec4(x_ref, 0.0);
    rotate[1] = glm::vec4(y_ref, 0.0);
    rotate[2] = glm::vec4(z_ref, 0.0);
    rotate[3] = glm::vec4(0.0,0.0,0.0, 1.0);

    Matrices.model = glm::mat4(1.0f);
    // translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate * translate1 * rotate * scale * glm::translate(glm::vec3(0,0,1)));
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    

    draw3DObject(this->canon);
    draw3DObject(this->structure1);

    







    /*canon part two*/
    Matrices.model = glm::mat4(1.0f);
    // translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate * translate1 * rotate * glm::rotate((float) ((45) * M_PI / 180.0f), glm::vec3(0,0,1)) * scale * glm::translate(glm::vec3(0,0,1)));
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

    draw3DObject(this->arrow);
    draw3DObject(this->structure2);

}

bool CheckPoint::tick(glm::vec3 z_ref)
{

    this->z_ref = glm::normalize(z_ref);
    
    glm::vec3 temp_x;
    

    temp_x = temp_x + glm::vec3(0,0,1);


    this->x_ref = glm::normalize(glm::cross(glm::normalize(temp_x), z_ref));
    this->y_ref = glm::normalize(glm::cross(z_ref, x_ref));


    rotation_ship++;
    rotation_arrow++;

    timer++;
    timer = timer%60;
    
    if(timer==0)
    {
      return true;
    }

    return false;
}