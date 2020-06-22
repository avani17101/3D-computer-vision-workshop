#include "jet.h"
#include "main.h"

Jet::Jet(float xs, float ys, color_t color) {
    
    this->position = glm::vec3(xs, ys, 0);
    this->x_ref = glm::vec3(1, 0, 0);
    this->y_ref = glm::vec3(0,1,0);
    this->z_ref = glm::vec3(0,0,1);
    this->rotation = 0;
    this->pitch = 0;
    this->roll = 0;
    this->fuel = 1200;

    
    speed = 0.5f;
    float scale_x = 0.3;
    
    static GLfloat g_vertex_buffer_data[2000];
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
       g_vertex_buffer_data[18*i+2]  = -2;
       g_vertex_buffer_data[18*i+3]  = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+4]  = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+5]  = -2;
       g_vertex_buffer_data[18*i+6]  = x[i+j];
       g_vertex_buffer_data[18*i+7]  = y[i+j];
       g_vertex_buffer_data[18*i+8]  = 3;
       g_vertex_buffer_data[18*i+9]  = x[i+j];
       g_vertex_buffer_data[18*i+10] = y[i+j];
       g_vertex_buffer_data[18*i+11] = 3;  
       g_vertex_buffer_data[18*i+12] = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+13] = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+14] = 3;
       g_vertex_buffer_data[18*i+15] = x[(i+j+1)%30];
       g_vertex_buffer_data[18*i+16] = y[(i+j+1)%30];
       g_vertex_buffer_data[18*i+17] = -2;
    }

    




    for(int j = 0; j < 5; ++j)
    {
        for(int i = 0; i < 10; ++i)
        {
           g_vertex_buffer_data[18*i + 180* (j+1)]       = x[j] * x[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 1]  = x[j] * y[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 2]  = 3 + y[j]/scale_x; //back
           g_vertex_buffer_data[18*i + 180* (j+1) + 3]  = x[j] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 4]  = x[j] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 5]  = 3 + y[j]/scale_x; //back
           g_vertex_buffer_data[18*i + 180* (j+1) + 6]  = x[j+1] *x[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 7]  = x[j+1] *y[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 8]  = 3 + y[j+1]/scale_x;//front
           g_vertex_buffer_data[18*i + 180* (j+1) + 9]  = x[j+1] * x[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 10] = x[j+1] * y[i]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 11] = 3  + y[j+1]/scale_x;  //front
           g_vertex_buffer_data[18*i + 180* (j+1) + 12] = x[j+1] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 13] = x[j+1] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 14] = 3 + y[j+1]/scale_x;//front
           g_vertex_buffer_data[18*i + 180* (j+1) + 15] = x[j] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 16] = x[j] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 180* (j+1) + 17] = 3 + y[j]/scale_x;//back

        }
    }


    for(int i = 0; i < 10; ++i)
    {
        int j = 0;

         g_vertex_buffer_data[18*i + 1080]       = x[j] * x[i]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 1]  = x[j] * y[i]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 2]  = -2 - y[j]/scale_x; //back
           g_vertex_buffer_data[18*i + 1080 + 3]  = x[j] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 4]  = x[j] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 5]  = -2 - y[j]/scale_x; //back
           g_vertex_buffer_data[18*i + 1080 + 6]  = x[j+1] *x[i]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 7]  = x[j+1] *y[i]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 8]  = -2 - y[j+1]/scale_x;//front
           g_vertex_buffer_data[18*i + 1080 + 9]  = x[j+1] * x[i]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 10] = x[j+1] * y[i]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 11] = -2  - y[j+1]/scale_x;  //front
           g_vertex_buffer_data[18*i + 1080 + 12] = x[j+1] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 13] = x[j+1] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 14] = -2 - y[j+1]/scale_x;//front
           g_vertex_buffer_data[18*i + 1080 + 15] = x[j] *x[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 16] = x[j] *y[(i+1)%30]/scale_x;
           g_vertex_buffer_data[18*i + 1080 + 17] = -2 - y[j]/scale_x;//back
          

    }
    //tail 1

    g_vertex_buffer_data[1260] = 0;
    g_vertex_buffer_data[1261] = scale_x;
    g_vertex_buffer_data[1262] = -1;
    g_vertex_buffer_data[1263] = 0;
    g_vertex_buffer_data[1264] = 1.3;
    g_vertex_buffer_data[1265] = -2.2;
    g_vertex_buffer_data[1266] = 0;
    g_vertex_buffer_data[1267] = scale_x;
    g_vertex_buffer_data[1268] = -2;
//tail 2
    g_vertex_buffer_data[1269] = 0;
    g_vertex_buffer_data[1270] = 1.3;
    g_vertex_buffer_data[1271] = -2.2;

    g_vertex_buffer_data[1272] = 0;
    g_vertex_buffer_data[1273] = scale_x;
    g_vertex_buffer_data[1274] = -2;

    g_vertex_buffer_data[1275] = 0;
    g_vertex_buffer_data[1276] = 1.3;
    g_vertex_buffer_data[1277] = -2.7;

//fins

    g_vertex_buffer_data[1278] = 0;
    g_vertex_buffer_data[1279] = -0.15;
    g_vertex_buffer_data[1280] = -1;

    g_vertex_buffer_data[1281] = 1.5f;
    g_vertex_buffer_data[1282] = -0.15f;
    g_vertex_buffer_data[1283] = -2;

    g_vertex_buffer_data[1284] = -1.5;
    g_vertex_buffer_data[1285] = -0.15;
    g_vertex_buffer_data[1286] = -2;


//fin1


    g_vertex_buffer_data[1287] = 1.5f;
    g_vertex_buffer_data[1288] = -0.15;
    g_vertex_buffer_data[1289] = -2;

    g_vertex_buffer_data[1290] = 1.5f;
    g_vertex_buffer_data[1291] = -0.15;
    g_vertex_buffer_data[1292] = -2.3;

    g_vertex_buffer_data[1293] = -0.3;
    g_vertex_buffer_data[1294] = -0.15;
    g_vertex_buffer_data[1295] = -2;

//fin2
    g_vertex_buffer_data[1296] = -1.5f;
    g_vertex_buffer_data[1297] = -0.15;
    g_vertex_buffer_data[1298] = -2;

    g_vertex_buffer_data[1299] = -1.5f;
    g_vertex_buffer_data[1300] = -0.15;
    g_vertex_buffer_data[1301] = -2.3;

    g_vertex_buffer_data[1302] = 0.3;
    g_vertex_buffer_data[1303] = -0.15;
    g_vertex_buffer_data[1304] = -2;

//

    g_vertex_buffer_data[1305] = 0;
    g_vertex_buffer_data[1306] = -0.15;
    g_vertex_buffer_data[1307] = 2.5;

    g_vertex_buffer_data[1308] = 1.3;
    g_vertex_buffer_data[1309] = -0.15f;
    g_vertex_buffer_data[1310] = 1.5;

    g_vertex_buffer_data[1311] = 0;
    g_vertex_buffer_data[1312] = -0.15;
    g_vertex_buffer_data[1313] = 1.5;



    g_vertex_buffer_data[1314] = 0;
    g_vertex_buffer_data[1315] = -0.15;
    g_vertex_buffer_data[1316] = 2.5;

    g_vertex_buffer_data[1317] = -1.3;
    g_vertex_buffer_data[1318] = -0.15f;
    g_vertex_buffer_data[1319] = 1.5;

    g_vertex_buffer_data[1320] = 0;
    g_vertex_buffer_data[1321] = -0.15;
    g_vertex_buffer_data[1322] = 1.5;
//

    g_vertex_buffer_data[1323] = 0;
    g_vertex_buffer_data[1324] = -0.15;
    g_vertex_buffer_data[1325] = 2.3;

    g_vertex_buffer_data[1326] = 1.5f;
    g_vertex_buffer_data[1327] = -0.15f;
    g_vertex_buffer_data[1328] = -2;

    g_vertex_buffer_data[1329] = -1.5;
    g_vertex_buffer_data[1330] = -0.15;
    g_vertex_buffer_data[1331] = -2;



    this->object    = create3DObject(GL_TRIANGLES, 420 + 12 + 12, g_vertex_buffer_data, color, GL_FILL);
    this->structure = create3DObject(GL_TRIANGLES, 420 + 12 + 12, g_vertex_buffer_data, COLOR_BLACK, GL_LINE);

}

void Jet::draw(glm::mat4 VP) {
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
    draw3DObject(this->object);
    draw3DObject(this->structure);

}

void Jet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Jet::tick() {

  this->position += (glm::normalize(this->z_ref))*speed;
  
  if(fuel!=0)
    this->fuel--;
  
  if(this->speed>0.5f)
  {
    if(this->speed>=0){
      this->speed -= 0.01f;
    }

    if(this->speed<0){
      this->speed = 0.0f;
    }
  }

  else if(this->speed<0.5)
  {
    if(this->speed>=0){
      this->speed += 0.01f;
    }

    if(this->speed>0.5){
      this->speed = 0.5f;
    }
  }

  if(fuel==0)
  {
    // this->position -= glm::vec3(0,1,0)*1.0f;
    // this->z_ref -= glm::vec3(0,1,0)*0.5f;
  }

    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

void Jet::right()
{
  if(this->rotation == 360)
  {
    this->rotation = 0;
  }

  if(this->rotation == -1*360)
  {
    this->rotation = 0;
  }
  this->rotation--;

  //rotating the reference x axis;

  glm::mat4 rotate_x    = glm::rotate((float) (-1 * M_PI / 180.0f), y_ref);

  // std::cout << "rotate x, y, z " << rotate_x[0][0] << "\t" << rotate_x[0][1] << "\t" << rotate_x[0][2] << std::endl;
  this->x_ref = glm::vec3(rotate_x * glm::vec4(this->x_ref, 1.0));

  //rotating the reference z axis;
  glm::mat4 rotate_z    = glm::rotate((float) (-1 * M_PI / 180.0f), y_ref);
  this->z_ref = glm::vec3(rotate_z * glm::vec4(this->z_ref, 1.0));


  // std::cout<<"x :" << this->x_ref.x << " y : " << this->x_ref.y << " z : " << this->x_ref.z << std::endl; 

}

void Jet::left()
{
  if(this->rotation == 360)
  {
    this->rotation = 0;
  }

  if(this->rotation == -1*360)
  {
    this->rotation = 0;
  }
  this->rotation++;

  glm::mat4 rotate_x    = glm::rotate((float) (1 * M_PI / 180.0f), y_ref);
  this->x_ref = glm::vec3(rotate_x * glm::vec4(this->x_ref, 1.0));

  glm::mat4 rotate_z    = glm::rotate((float) (1 * M_PI / 180.0f), y_ref);
  this->z_ref = glm::vec3(rotate_z * glm::vec4(this->z_ref, 1.0));
  // this->x_ref = rotate_x * this->x_re?f;
  // std::cout<<"x :" << this->x_ref.x << " y : " << this->x_ref.y << " z : " << this->x_ref.z << std::endl; 



}





void Jet::up()
{
  if(this->pitch == 360)
  {
    this->pitch = 0;
  }

  if(this->pitch == -1*360)
  {
    this->pitch = 0;
  }
  this->pitch++;
  //generate rotation matrix for rotating about x_ref
  glm::mat4 rotate_y    = glm::rotate((float) (1 * M_PI / 180.0f), x_ref);
  //rotate y_ref from y_original around x_ref;
  this->y_ref = glm::vec3(rotate_y * glm::vec4(this->y_ref, 1.0));

  glm::mat4 rotate_z    = glm::rotate((float) (1 * M_PI / 180.0f), x_ref);
  this->z_ref = glm::vec3(rotate_z * glm::vec4(this->z_ref, 1.0));
  // this->x_ref = rotate_x * this->x_re?f;
  // std::cout<<"x :" << this->x_ref.x << " y : " << this->x_ref.y << " z : " << this->x_ref.z << std::endl; 



}


void Jet::down()
{
  if(this->pitch == 360)
  {
    this->pitch = 0;
  }

  if(this->pitch == -1*360)
  {
    this->pitch = 0;
  }
  this->pitch--;
  //generate rotation matrix for rotating about x_ref
  glm::mat4 rotate_y    = glm::rotate((float) (-1 * M_PI / 180.0f), x_ref);
  //rotate y_ref from y_original around x_ref;
  this->y_ref = glm::vec3(rotate_y * glm::vec4(this->y_ref, 1.0));

  glm::mat4 rotate_z    = glm::rotate((float) (-1 * M_PI / 180.0f), x_ref);
  this->z_ref = glm::vec3(rotate_z * glm::vec4(this->z_ref, 1.0));
  // this->x_ref = rotate_x * this->x_re?f;
  // std::cout<<"x :" << this->x_ref.x << " y : " << this->x_ref.y << " z : " << this->x_ref.z << std::endl; 



}


void Jet::rollLeft()
{
   if(this->roll == 360)
  {
    this->roll = 0;
  }

  if(this->roll == -1*360)
  {
    this->roll = 0;
  }
  this->roll--;
  //generate rotation matrix for rotating about x_ref
  glm::mat4 rotate_y    = glm::rotate((float) (-1 * M_PI / 180.0f), z_ref);
  //rotate y_ref from y_original around x_ref;
  this->y_ref = glm::vec3(rotate_y * glm::vec4(this->y_ref, 1.0));

  glm::mat4 rotate_x    = glm::rotate((float) (-1 * M_PI / 180.0f), z_ref);
  this->x_ref = glm::vec3(rotate_x * glm::vec4(this->x_ref, 1.0));
  // this->x_ref = rotate_x * this->x_re?f;
  // std::cout<<"x :" << this->x_ref.x << " y : " << this->x_ref.y << " z : " << this->x_ref.z << std::endl; 



}

void Jet::rollRight()
{
  if(this->roll == 360)
  {
    this->roll = 0;
  }

  if(this->roll == -1*360)
  {
    this->roll = 0;
  }
  this->roll++;
  
  //generate rotation matrix for rotating about x_ref
  glm::mat4 rotate_y    = glm::rotate((float) (1 * M_PI / 180.0f), z_ref);
  //rotate y_ref from y_original around x_ref;
  this->y_ref = glm::vec3(rotate_y * glm::vec4(this->y_ref, 1.0));

  glm::mat4 rotate_x    = glm::rotate((float) (1 * M_PI / 180.0f), z_ref);
  this->x_ref = glm::vec3(rotate_x * glm::vec4(this->x_ref, 1.0));
  // this->x_ref = rotate_x * this->x_re?f;
  // std::cout<<"x :" << this->x_ref.x << " y : " << this->x_ref.y << " z : " << this->x_ref.z << std::endl; 



}

void Jet::forward()
{
  this->speed += 0.1f;
  if(this->speed >= 4.0f)
  {
      this->speed = 4.0f;
  }
}

void Jet::hover()
{
  this->speed -= 0.1f;
  if(this->speed <= 0.0f)
  {
      this->speed = 0.0f;
  }
}

