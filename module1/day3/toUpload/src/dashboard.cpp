#include "dashboard.h"

#include "main.h"

DashBoard::DashBoard(color_t color) {

    this->position = glm::vec3(1,1,1);

    this->x_ref = glm::vec3(1,0,0);
    this->y_ref = glm::vec3(0,1,0);
    this->z_ref = glm::vec3(0,0,1);
    score = 1;
    fuel = 600;
    speed = 1;
    final_score = 0;

    segs[0] = Seg(0);
    segs[1] = Seg(1);
    segs[2] = Seg(2);
    segs[3] = Seg(3);
    segs[4] = Seg(4);



    
    static const GLfloat g_vertex_buffer_data[] = {
      -2.0f, 2.0f - 1.5f, 0.0f,
      -1.0f, 2.0f - 1.5f, 0.0f,
      -1.0f, 1.8f - 1.5f, 0.0f,

      -2.0f, 2.0f - 1.5f, 0.0f,
      -1.0f, 1.8f - 1.5f, 0.0f,
      -2.0f, 1.8f - 1.5f, 0.0f,
      


      2.0f, 2.0f - 1.5f, 0.0f,
      1.0f, 2.0f - 1.5f, 0.0f,
      1.0f, 1.8f - 1.5f, 0.0f,

      1.0f, 1.8f - 1.5f, 0.0f,
      2.0f, 1.8f - 1.5f, 0.0f,
      2.0f, 2.0f - 1.5f, 0.0f,

    };

    static const GLfloat g_vertex_buffer_data1[] = 
    {
      -1.998f, 1.998f - 1.5f, -0.01f,
      -1.998f, 1.802f - 1.5f, -0.01f,
      -1.802f, 1.998f - 1.5f, -0.01f,

      -1.998f, 1.802f - 1.5f, -0.01f,
      -1.802f, 1.998f - 1.5f, -0.01f,
      -1.802f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data2[] = 
    {
      -1.798f, 1.998f - 1.5f, -0.01f,
      -1.798f, 1.802f - 1.5f, -0.01f,
      -1.602f, 1.998f - 1.5f, -0.01f,

      -1.798f, 1.802f - 1.5f, -0.01f,
      -1.602f, 1.998f - 1.5f, -0.01f,
      -1.602f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data3[] = 
    {
      -1.598f, 1.998f - 1.5f, -0.01f,
      -1.598f, 1.802f - 1.5f, -0.01f,
      -1.402f, 1.998f - 1.5f, -0.01f,

      -1.598f, 1.802f - 1.5f, -0.01f,
      -1.402f, 1.998f - 1.5f, -0.01f,
      -1.402f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data4[] = 
    {
      -1.398f, 1.998f - 1.5f, -0.01f,
      -1.398f, 1.802f - 1.5f, -0.01f,
      -1.202f, 1.998f - 1.5f, -0.01f,

      -1.398f, 1.802f - 1.5f, -0.01f,
      -1.202f, 1.998f - 1.5f, -0.01f,
      -1.202f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data5[] = 
    {
      -1.198f, 1.998f - 1.5f, -0.01f,
      -1.198f, 1.802f - 1.5f, -0.01f,
      -1.002f, 1.998f - 1.5f, -0.01f,

      -1.198f, 1.802f - 1.5f, -0.01f,
      -1.002f, 1.998f - 1.5f, -0.01f,
      -1.002f, 1.802f - 1.5f, -0.01f,

    };

//fuel;

    static const GLfloat g_vertex_buffer_data11[] = 
    {
      1.002f, 1.998f - 1.5f, -0.01f,
      1.002f, 1.802f - 1.5f, -0.01f,
      1.198f, 1.998f - 1.5f, -0.01f,

      1.002f, 1.802f - 1.5f, -0.01f,
      1.198f, 1.998f - 1.5f, -0.01f,
      1.198f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data12[] = 
    {
      1.202f, 1.998f - 1.5f, -0.01f,
      1.202f, 1.802f - 1.5f, -0.01f,
      1.398f, 1.998f - 1.5f, -0.01f,

      1.398f, 1.802f - 1.5f, -0.01f,
      1.398f, 1.998f - 1.5f, -0.01f,
      1.202f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data13[] = 
    {
      1.402f, 1.998f - 1.5f, -0.01f,
      1.402f, 1.802f - 1.5f, -0.01f,
      1.598f, 1.998f - 1.5f, -0.01f,

      1.598f, 1.802f - 1.5f, -0.01f,
      1.598f, 1.998f - 1.5f, -0.01f,
      1.402f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data14[] = 
    {
      1.602f, 1.998f - 1.5f, -0.01f,
      1.602f, 1.802f - 1.5f, -0.01f,
      1.798f, 1.998f - 1.5f, -0.01f,

      1.798f, 1.802f - 1.5f, -0.01f,
      1.798f, 1.998f - 1.5f, -0.01f,
      1.602f, 1.802f - 1.5f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data15[] = 
    {
      1.802f, 1.998f - 1.5f, -0.01f,
      1.802f, 1.802f - 1.5f, -0.01f,
      1.998f, 1.998f - 1.5f, -0.01f,

      1.998f, 1.802f - 1.5f, -0.01f,
      1.998f, 1.998f - 1.5f, -0.01f,
      1.802f, 1.802f - 1.5f, -0.01f,

    };

 static const GLfloat g_vertex_buffer_data111[] = 
    {
      1.002f, 1.998f - 1.8f, -0.01f,
      1.002f, 1.802f - 1.8f, -0.01f,
      1.198f, 1.998f - 1.8f, -0.01f,

      1.002f, 1.802f - 1.8f, -0.01f,
      1.198f, 1.998f - 1.8f, -0.01f,
      1.198f, 1.802f - 1.8f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data112[] = 
    {
      1.202f, 1.998f - 1.8f, -0.01f,
      1.202f, 1.802f - 1.8f, -0.01f,
      1.398f, 1.998f - 1.8f, -0.01f,

      1.398f, 1.802f - 1.8f, -0.01f,
      1.398f, 1.998f - 1.8f, -0.01f,
      1.202f, 1.802f - 1.8f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data113[] = 
    {
      1.402f, 1.998f - 1.8f, -0.01f,
      1.402f, 1.802f - 1.8f, -0.01f,
      1.598f, 1.998f - 1.8f, -0.01f,

      1.598f, 1.802f - 1.8f, -0.01f,
      1.598f, 1.998f - 1.8f, -0.01f,
      1.402f, 1.802f - 1.8f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data114[] = 
    {
      1.602f, 1.998f - 1.8f, -0.01f,
      1.602f, 1.802f - 1.8f, -0.01f,
      1.798f, 1.998f - 1.8f, -0.01f,

      1.798f, 1.802f - 1.8f, -0.01f,
      1.798f, 1.998f - 1.8f, -0.01f,
      1.602f, 1.802f - 1.8f, -0.01f,

    };

    static const GLfloat g_vertex_buffer_data115[] = 
    {
      1.802f, 1.998f - 1.8f, -0.01f,
      1.802f, 1.802f - 1.8f, -0.01f,
      1.998f, 1.998f - 1.8f, -0.01f,

      1.998f, 1.802f - 1.8f, -0.01f,
      1.998f, 1.998f - 1.8f, -0.01f,
      1.802f, 1.802f - 1.8f, -0.01f,

    };
   
    GLfloat x[30], y[30];

    for(int i = 0; i < 30; ++i)
    {
        x[i] = 0.35*cos(2*M_PI*i/30);
        y[i] = 0.35*sin(2*M_PI*i/30);

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





    color_t Dashb = {255, 255, 150};
    color_t COMP = {255, 187, 153};
    this->object    = create3DObject(GL_TRIANGLES, 3*4,  g_vertex_buffer_data, Dashb, GL_FILL);
    this->level5    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data1, COLOR_BLACK, GL_FILL);
    this->level4    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    this->level3    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data3, COLOR_BLACK, GL_FILL);
    this->level2    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data4, COLOR_BLACK, GL_FILL);
    this->level1    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data5, COLOR_BLACK, GL_FILL);

    this->level15    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data11, COLOR_BLACK, GL_FILL);
    this->level14    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data12, COLOR_BLACK, GL_FILL);
    this->level13    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data13, COLOR_BLACK, GL_FILL);
    this->level12    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data14, COLOR_BLACK, GL_FILL);
    this->level11    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data15, COLOR_BLACK, GL_FILL);

    this->level115    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data111, COLOR_BLACK, GL_FILL);
    this->level114    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data112, COLOR_BLACK, GL_FILL);
    this->level113    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data113, COLOR_BLACK, GL_FILL);
    this->level112    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data114, COLOR_BLACK, GL_FILL);
    this->level111    = create3DObject(GL_TRIANGLES, 3*2,  g_vertex_buffer_data115, COLOR_BLACK, GL_FILL);
   
    this->compass    = create3DObject(GL_TRIANGLES, 180,  g_vertex_buffer_data6, COLOR_BLACK, GL_FILL);
    
    // this->structure = create3DObject(GL_TRIANGLES, 2?, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);

}

void DashBoard::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate;
    rotate[0] = glm::vec4(x_ref, 0.0);
    rotate[1] = glm::vec4(y_ref, 0.0);
    rotate[2] = glm::vec4(z_ref, 0.0);
    rotate[3] = glm::vec4(0.0,0.0,0.0, 1.0);



    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // draw3DObject(this->obect);
    draw3DObject(this->compass);


   

    if(score==1)
    {
      draw3DObject(this->level1);
      
    }

    if(score==2)
    {
      draw3DObject(this->level1);
      draw3DObject(this->level2);
    }

    if(score==3)
    {
      draw3DObject(this->level1);
      draw3DObject(this->level2);
      draw3DObject(this->level3);

    }

    if(score==4)
    {
      draw3DObject(this->level1);
      draw3DObject(this->level2);
      draw3DObject(this->level3);
      draw3DObject(this->level4);

    }

    if(score>=5)
    {
      draw3DObject(this->level1);
      draw3DObject(this->level2);
      draw3DObject(this->level3);
      draw3DObject(this->level4);
      draw3DObject(this->level5);

    }

    if(fuel==0)
    {
      // draw3DObject(this->level11);
      
    }



    if(fuel==1)
    {
      draw3DObject(this->level11);
      
    }

    if(fuel==2)
    {
      draw3DObject(this->level11);
      draw3DObject(this->level12);
    }

    if(fuel==3)
    {
      draw3DObject(this->level11);
      draw3DObject(this->level12);
      draw3DObject(this->level13);

    }

    if(fuel==4)
    {
      draw3DObject(this->level11);
      draw3DObject(this->level12);
      draw3DObject(this->level13);
      draw3DObject(this->level14);

    }

    if(fuel>=5)
    {
      draw3DObject(this->level11);
      draw3DObject(this->level12);
      draw3DObject(this->level13);
      draw3DObject(this->level14);
      draw3DObject(this->level15);

    }

    if(speed==1)
    {
      draw3DObject(this->level111);
      
    }

    if(speed==2)
    {
      draw3DObject(this->level111);
      draw3DObject(this->level112);
    }

    if(speed==3)
    {
      draw3DObject(this->level111);
      draw3DObject(this->level112);
      draw3DObject(this->level113);

    }

    if(speed==4)
    {
      draw3DObject(this->level111);
      draw3DObject(this->level112);
      draw3DObject(this->level113);
      draw3DObject(this->level114);

    }

    if(speed>=5)
    {
      draw3DObject(this->level111);
      draw3DObject(this->level112);
      draw3DObject(this->level113);
      draw3DObject(this->level114);
      draw3DObject(this->level115);

    }

    segs[0].draw(VP);
    segs[1].draw(VP);
    segs[2].draw(VP);
    segs[3].draw(VP);
    segs[4].draw(VP);



    // draw3DObject(this->structure);

}

void DashBoard::tick(glm::vec3 x, glm::vec3 y, glm::vec3 z, glm::vec3 position, int fuel, float speed)
{
  this->x_ref = x;
  this->z_ref = z;
  this->y_ref = y;
  this->position = position - z*8.50f + y_ref*5.0f ;

  score = position.y/40+1;

  this->fuel = (fuel/240)+1;
  if(fuel==0)
  {
    this->fuel=0;
  }
  this->speed = speed/0.5f;

  int temp = position.z/40;
  temp+=final_score;

  segs[0].tick(x, y, z, position, temp%10);
  segs[1].tick(x, y, z, position, (temp/10)%10);
  segs[2].tick(x, y, z, position, (temp/100)%10);
  segs[3].tick(x, y, z, position, (temp/1000)%10);
  segs[4].tick(x, y, z, position, (temp/10000)%10);


  // this->fuel = score;

  // std::cout << "score : "<<score << std::endl;
  // std::cout << "y : "   << position.y<< std::endl;

}