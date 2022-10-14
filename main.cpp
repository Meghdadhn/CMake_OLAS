#include <iostream>
#include <basics.h>
#include <GLFW/glfw3.h>

int main () 
{

    int a, b;
    std::cout << "Please input 2 numbers!\n";
    std::cin >> a >> b;

    std::cout << "sum\t" << add (a,b) << "\n";
    std::cout << "subtrance\t" << subtract (a,b) << "\n";


    GLFWwindow *window;


    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }


    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();


    return 0;
}