#include "main.h"
#include "timer.h"
#include "jet.h"
#include "sea.h"
#include "dashboard.h"
#include "needle.h"
#include "volcano.h"
#include "missile.h"
#include "checkpoint.h"
#include "boom.h"
#include "circular.h"
#include "fueltank.h"
#include "fueltank.h"
#include "arrow.h"
#include "parachute.h"




using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/************************8*
* Customizable functions *
**************************/

Jet plane;
Sea sea[10][400];


float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int eye_x, eye_y, eye_z, tar_x, tar_y, tar_z;
bool toggle = true;
int fps = 60;
float screen_zoom_scroll = 12.0;

bool toggle_top;
bool toggle_tower;
bool toggle_pilot;
bool toggle_heli;
bool protect;
int timer;
int mouse_timer = 0;
bool mouse_pressed;
int rotation = 0;
// Arrow arrow;

double xpos, ypos, old_x_pos, old_y_pos;

glm::vec3 eye, target, up;

Timer t60(1.0 / fps);

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    switch (button) {
    case GLFW_MOUSE_BUTTON_LEFT:
        if (action == GLFW_PRESS) {
            mouse_pressed = true;
            // Do something
            return;
        } else if (action == GLFW_RELEASE) {
            mouse_pressed = false;
            // Do something
        }
        break;

    default:
        break;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    if(yoffset<0)
    {
        screen_zoom_scroll += 3.0;
    }    // Do something
    else
    {
        screen_zoom_scroll -= 3.0;
    }
    //reset_screen();
}


bool volcanoDetect(Jet plane, Volcano volcano)
{
    glm::vec3 temp_plane = plane.position + plane.z_ref;
    glm::vec3 temp_volcano = volcano.position;

    if((temp_plane.x > temp_volcano.x) && (temp_plane.x < temp_volcano.x + 40))
    {
        if( ( temp_plane.z > temp_volcano.z ) && ( temp_plane.z < temp_volcano.z + 40 ))
        {
            return true;
        }
    }

    return false;
}

bool tooFar(Jet plane, glm::vec3 position)
{
    if(glm::distance(plane.position, position) > 100)
    {
        return true;
    }
}

bool missileDestShip(glm::vec3 missileTip, glm::vec3 Target)
{
    if(glm::distance(missileTip, Target) < 40)
    {
        return true;
    }
}

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Donq   q't change unless you are sure!!
    set_camera();

    // Compute Camera matrix (view)

    Matrices.view = glm::lookAt( eye, target, up); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!

    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;

    // Matrices.projection = glm::frustum(left, right, bottom, top, 1.0f, 400.0f);
    Matrices.projection = glm::ortho(left, right, bottom, top, 1.0f, 700.0f);
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 400; ++j)
        {
            sea[i][j].draw(VP);
            /* code */
        }
        /* code */
    }


    plane.draw(VP);

    if(!toggle_heli && !toggle_pilot && !toggle_tower && !toggle_top)
    {    
        // score_info.draw(VP);

        glm::vec3 temp_z = glm::vec3(plane.z_ref.x,0, plane.z_ref.z);
        glm::vec3 temp_x = glm::vec3(0,0,1);

        float len = sqrt(temp_z.z*temp_z.z + temp_z.x*temp_z.x);

        float rotation = acos( float(temp_x.z*temp_z.z)/len); 

        if(temp_z.x < 0)
        {
            rotation = 2*M_PI - rotation;
        }


        // needle.draw(VP, -1 * rotation);
    }



}

void tick_input(GLFWwindow *window) {
    int q  = glfwGetKey(window, GLFW_KEY_Q);
    int e  = glfwGetKey(window, GLFW_KEY_E);
    int up  = glfwGetKey(window, GLFW_KEY_UP);
    int down  = glfwGetKey(window, GLFW_KEY_DOWN);

    int a  = glfwGetKey(window, GLFW_KEY_A);
    int d  = glfwGetKey(window, GLFW_KEY_D);
    int w  = glfwGetKey(window, GLFW_KEY_W);
    
    
    int top_view = glfwGetKey(window, GLFW_KEY_T);
    int tower_view = glfwGetKey(window, GLFW_KEY_Y);
    int pilot_view = glfwGetKey(window, GLFW_KEY_U);
    int heli_view = glfwGetKey(window, GLFW_KEY_I);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int x = glfwGetKey(window, GLFW_KEY_X);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int left = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);

    int toggle_test = glfwGetKey(window, GLFW_KEY_P);


    
   
    if(heli_view)
    {
        if(timer%10==0)
        {
            if(!toggle_heli)
            {
                toggle_heli = true;
            }
            else
            {
                toggle_heli = false;
                
            }
            // timer++;
        }
    }


    if(pilot_view)
    {
        toggle_pilot = true;
    }
    else
    {
        toggle_pilot = false;
    }



    if(toggle_test)
    {
        if(timer%10==0)
        {
            if(!protect)
            {
                protect = true;
                cout<<protect<<endl;
            }
            else
            {
                protect = false;
                
            }
            // timer++;
        }
    }

    // cout<<protect<<endl;


    if(tower_view)
    {
        toggle_tower = true;
    }
    else
    {
        toggle_tower = false;
    }

    if(top_view)
    {
        toggle_top = true;
    }
    else
    {
        toggle_top = false;
    }


    if(e)
    {
        plane.right();
    }

    if(q)
    {
        plane.left();
    }


    if(right)
    {
        plane.right();
    }

    if(left)
    {
        plane.left();
    }


    if(up)
    {
        plane.up();
    }

    if(down)
    {
        plane.down();
    }

    if(a)
    {
        plane.rollLeft();
    }

    if(d)
    {
        plane.rollRight();
    }

    if(w)
    {
        plane.forward();
    }

    if(s)
    {
        plane.hover();
    }



    timer++;
    timer = timer%10;


   

   
}

void tick_elements() {

    plane.tick();


}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    eye_x = eye_z = eye_y = tar_x = tar_y = tar_z = 0;


    plane      = Jet(0, 0, COLOR_PLANE);
    // score_info = DashBoard(COLOR_BLACK);
    // needle     = Needle(COLOR_BLACK);
    // arrow = Arrow(0,0);
    protect = false;


    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 400; ++j)
        {
            sea[i][j] = Sea(40*i - 200, 40*j, COLOR_SEA);
            /* code */
        }
        /* code */
    }


    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    // srand(time(0));
    srand(time(NULL));

    int width  = 1200;
    int height = 1200;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_input(window);
            tick_elements();
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();

    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}

void set_camera()
{
   
    if(!toggle_heli)
    {
        eye   = plane.position + plane.y_ref * 4.0f - plane.z_ref*12.0f;
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        target = plane.position + plane.y_ref * 2.0f + plane.z_ref;
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        up = plane.y_ref;

        if(toggle_top)
        {
            eye = plane.position + plane.y_ref * 10.0f;
            target = plane.position;
            up = plane.z_ref;
        }

        if(toggle_tower)
        {
            eye =  plane.position + glm::vec3(40,40,40);
            target = plane.position;
            up = glm::vec3(0,1,0);
        }

        if(toggle_pilot)
        {
            eye   = plane.position + plane.z_ref*4.0f;
            target = plane.position + plane.z_ref*10.0f;
            up = plane.y_ref;
        }
    }
    else
    {
        target = plane.position;
        up = glm::vec3(0,1,0);
        glfwGetCursorPos(window, &xpos, &ypos);
       
        glm::vec3 cam_rot = glm::vec3(0,0,1);

        /*
        process then save these as old
        */

        if(mouse_pressed)
        {
            if(xpos > old_x_pos)
            {
                rotation--;
            }   

            if(xpos < old_x_pos)
            {
                rotation++;
            }

            if(xpos==old_x_pos)
            {
                rotation+=0;
            }
        }


        glm::mat4 rotate = glm::rotate((float) (rotation * M_PI / 180.0f), glm::vec3(0,1,0));
        cam_rot = glm::vec3(rotate * glm::vec4(cam_rot,1.0f));

        eye   = plane.position + glm::vec3(0,1,0)*4.0f + cam_rot*screen_zoom_scroll;

        old_x_pos = xpos;
        old_y_pos = ypos;
   
    }
    

}
