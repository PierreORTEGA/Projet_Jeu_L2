
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//



// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <iostream>
#ifdef __APPLE__
  #include <OpenGL/glu.h>
#else
  #include <GL/glut.h>
#endif
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "firstpersonne.hpp"
#include "Map.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

using namespace std;
//GLuint loadBMP_custom(const char * imagepath);
int main()
{

  // Create the main window
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML OpenGL");
  
  // Create a clock for measuring time elapsed
  sf::Clock Clock;
  
  //prepare OpenGL surface for HSR
  glClearDepth(1.f);
  glClearColor(0.3f, 0.3f, 0.3f, 0.f);
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  
  
  firstpersonne  player(100.f, 1.f, 1.f, 300.0f);
  Enemy* enemy = new Enemy("/Users/ortegapierre/Desktop/ProjetPA-TowerBay/Projet test/Projet test/stainedglass05.jpg");
  Map map("/Users/ortegapierre/Desktop/ProjetPA-TowerBay/Projet test/Projet test/metal091.jpg");

  glEnable(GL_TEXTURE_2D);
  Projectile * tire=NULL;
    // Start game loop
  while (App.isOpen())
  {

    // Process events
    
    sf::Event Event;
    while (App.pollEvent(Event))
    {
      // Close window : exit
      if (Event.type == sf::Event::Closed)
        App.close();
      
      // Escape key : exit
      if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
        App.close();
      
    }
    
    //Prepare for drawing
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Apply some transformations for the cube
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -200.f);
    

    player.rotationCamera();
    map.setTexture();

 

    if (enemy) {
      if(player.destructionEnemy(enemy)){
        //cout<<"object detruit"<<endl;
        delete enemy;
        enemy=NULL;
      }else{
        //cout<<"object non detruit"<<endl;
        enemy->setTexture();
      }
    }
    // Finally, display rendered frame on screen
    App.display();
    App.setFramerateLimit(60);
  }
  
  return EXIT_SUCCESS;
}
