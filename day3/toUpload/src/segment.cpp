#include "segment.h"
#include "main.h"

Seg::Seg(int pos) {
    this->position1 = glm::vec3(-6.5 + 0.5f*pos  , 8.25f, 0);
    // this?->acceleration = 0;
    // speed = 0;
    // this->collected = false;
    // this->type = rand()%2;
    color_t color = COLOR_BLACK;
    this->number = 0;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static const GLfloat g_vertex_buffer_data[] = {
        0.0f, 0.0f, 0.0f,
        0.4f, 0.0f, 0.0f,
        0.4f, -0.05f, 0.0f,

        0.0f, 0.0f, 0.0f,
        0.4f, -0.05f, 0.0f,
        0.0f, -0.05f, 0.0f,


    };

    static const GLfloat g_vertex_buffer_data1[] = {
        0.0f, -0.5f, 0.0f,
        0.4f, -0.5f, 0.0f,
        0.4f, -0.55f, 0.0f,

        0.0f, -0.5f, 0.0f,
        0.4f, -0.55f, 0.0f,
        0.0f, -0.55f, 0.0f,


    };

    static const GLfloat g_vertex_buffer_data2[] = {
        0.0f, -1.0f, 0.0f,
        0.4f, -1.0f, 0.0f,
        0.4f, -1.05f, 0.0f,

        0.0f, -1.0f, 0.0f,
        0.4f, -1.05f, 0.0f,
        0.0f, -1.05f, 0.0f,


    };

     static const GLfloat g_vertex_buffer_data3[] = {
        0.0f, 0.0f, 0.0f,
        0.05f, 0.0f, 0.0f,
        0.0f, -0.5f, 0.0f,

        0.05f, 0.0f, 0.0f,
        0.0f, -0.5f, 0.0f,
        0.05f, -0.5f, 0.0f,

    };

     static const GLfloat g_vertex_buffer_data4[] = {
        0.35f, 0.0f, 0.0f,
        0.4f, 0.0f, 0.0f,
        0.35f, -0.5f, 0.0f,

        0.4f, 0.0f, 0.0f,
        0.35f, -0.5f, 0.0f,
        0.4f, -0.5f, 0.0f,

    };

    static const GLfloat g_vertex_buffer_data5[] = {
        0.0f, -0.5f, 0.0f,
        0.05f, -0.5f, 0.0f,
        0.0f, -1.0f, 0.0f,

        0.05f, -0.5f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.05f, -1.0f, 0.0f,

    };

     static const GLfloat g_vertex_buffer_data6[] = {
        0.35f, -0.50f, 0.0f,
        0.4f, -0.50f, 0.0f,
        0.35f, -1.0f, 0.0f,

        0.4f, -0.50f, 0.0f,
        0.35f, -1.0f, 0.0f,
        0.4f, -1.0f, 0.0f,

    };






    this->a = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data , color, GL_FILL);
    this->b = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data1, color, GL_FILL);
    this->c = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data2, color, GL_FILL);
    this->d = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data3, color, GL_FILL);
    this->e = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data4, color, GL_FILL);
    this->f = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data5, color, GL_FILL);
    this->g = create3DObject(GL_TRIANGLES, 2*3, g_vertex_buffer_data6, color, GL_FILL);

}

void Seg::draw(glm::mat4 VP) {
   
        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translate = glm::translate (this->position);
        glm::mat4 translate1 = glm::translate (this->position1);    // glTranslatef


        glm::mat4 scale = glm::mat4(1.0f);

        float scale_mat = 1.5;
        scale[0] = glm::vec4(0.8*scale_mat,0,0,0);
        scale[1] = glm::vec4(0, 0.6f*scale_mat,0,0);
        scale[2] = glm::vec4(0,0,scale_mat,0);
        scale[3] = glm::vec4(0,0,0,1);

        glm::mat4 rotate;
        rotate[0] = glm::vec4(x_ref, 0.0);
        rotate[1] = glm::vec4(y_ref, 0.0);
        rotate[2] = glm::vec4(z_ref, 0.0);
        rotate[3] = glm::vec4(0.0,0.0,0.0, 1.0);


        Matrices.model *= (translate *  rotate * translate1  * scale);
        glm::mat4 MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        if(this->number == 0)
        {
            draw3DObject(this->a);
            draw3DObject(this->d);
            draw3DObject(this->f);
            draw3DObject(this->c);
            draw3DObject(this->g);
            draw3DObject(this->e);

        }
        else if(this->number == 1)
        {
            draw3DObject(this->d);
            draw3DObject(this->f);

        } 

        else if(this->number == 2)
        {
            draw3DObject(this->a);
            draw3DObject(this->d);
            draw3DObject(this->b);
            draw3DObject(this->g);
            draw3DObject(this->c);
        } 

        else if(this->number == 3)
        {
            draw3DObject(this->a);
            draw3DObject(this->d);
            draw3DObject(this->b);
            draw3DObject(this->f);
            draw3DObject(this->c);



        } 
        else if(this->number == 4)
        {
            draw3DObject(this->d);
            draw3DObject(this->b);
            draw3DObject(this->e);
            draw3DObject(this->f);


        } 
        else if(this->number == 5)
        {
            draw3DObject(this->a);
            draw3DObject(this->e);
            draw3DObject(this->b);
            draw3DObject(this->f);
            draw3DObject(this->c);

        } 
        else if(this->number == 6)
        {
            draw3DObject(this->a);
            draw3DObject(this->e);
            draw3DObject(this->g);
            draw3DObject(this->c);
            draw3DObject(this->f);
            draw3DObject(this->b);

        } 
        else if(this->number == 7)
        {
            draw3DObject(this->a);
            draw3DObject(this->d);
            draw3DObject(this->f);
        } 
        else if(this->number == 8)
        {
            draw3DObject(this->a);
            draw3DObject(this->e);
            draw3DObject(this->g);
            draw3DObject(this->c);
            draw3DObject(this->f);
            draw3DObject(this->b);
            draw3DObject(this->d);

        } 
        else if(this->number == 9)
        {
            draw3DObject(this->a);
            draw3DObject(this->e);
            draw3DObject(this->f);
            draw3DObject(this->c);
            draw3DObject(this->b);
            draw3DObject(this->d);

        } 
        // draw3DObject(this->object);
    
}


void Seg::tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position, int number)
{
  this->x_ref = x;
  this->z_ref = z;
  this->y_ref = y;
  this->position = position;



  this->number = number;

 

}




// void Coin::set_position(float x, float y) {
//     this->position = glm::vec3(x, y, 0);
// }

// float Coin::ret_scrn_pos(){
//     return this->position.x;
// }

// void Coin::set_collected()
// {
//     this->collected = true;
// }

// bool Coin::ret_collected()
// {
//     return this->collected;
// }

// void Coin::fall() {
//     this->speed = -0.07;
// }

// void Coin::tick() {
    
//     this->position.y += this->speed;

//     if(this->speed != 0){
//         speed -= 0.005;
//     }

   
// }