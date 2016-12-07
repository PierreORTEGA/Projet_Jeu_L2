//
//  Map.cpp
//  Projet test
//
//  Created by ORTEGA Pierre on 14/10/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#include "Map.hpp"

Map::Map(std::string pPathTex){
  
  pathTex=pPathTex;
}
Map::~Map(){
  
}
void Map::generationMap(){
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0); glVertex3d(-100.f, 0.f, -100.f);
  glTexCoord2d(0,1); glVertex3d(-100.f,  200.f, -100.f);
  glTexCoord2d(1, 1); glVertex3d( 100.f, 200.f, -100.f);
  glTexCoord2d(1, 0); glVertex3d( 100.f,0.f, -100.f);
  
  glTexCoord2f(0, 0);glVertex3f(-100.f, 0.f,  100.f);
  glTexCoord2f(0, 1);glVertex3f(-100.f, 0.f, -100.f);
  glTexCoord2f(1, 1);glVertex3f( 100.f, 0.f, -100.f);
  glTexCoord2f(1, 0);glVertex3f( 100.f, 0.f,  100.f);
  
  glTexCoord2f(0, 0); glVertex3f(-100.f, 0.f, 100.f);
  glTexCoord2f(0, 1); glVertex3f(-100.f,  200.f, 100.f);
  glTexCoord2f(1, 1); glVertex3f( 100.f,  200.f, 100.f);
  glTexCoord2f(1, 0); glVertex3f( 100.f, 0.f, 100.f);
  
  
  glTexCoord2f(0, 0); glVertex3f(-100.f, 0.f, -100.f);
  glTexCoord2f(0, 1); glVertex3f(-100.f,  200.f, -100.f);
  glTexCoord2f(1, 1); glVertex3f(-100.f,  200.f,  100.f);
  glTexCoord2f(1, 0); glVertex3f(-100.f, 0.f,  100.f);
  
  
  glTexCoord2f(0, 0);glVertex3f(100.f, 0.f, -100.f);
  glTexCoord2f(0, 1);glVertex3f(100.f,  200.f, -100.f);
  glTexCoord2f(1, 1);glVertex3f(100.f,  200.f,  100.f);
  glTexCoord2f(1, 0);glVertex3f(100.f, 0.f,  100.f);
  
  
  
  glTexCoord2f(0, 0);glVertex3f(-100.f, 200.f,  100.f);
  glTexCoord2f(0, 1);glVertex3f(-100.f, 200.f, -100.f);
  glTexCoord2f(1, 1);glVertex3f( 100.f, 200.f, -100.f);
  glTexCoord2f(1, 0);glVertex3f( 100.f, 200.f,  100.f);
  glEnd();
}
void Map::setTexture(){

  texture.loadFromFile(pathTex);
  sf::Texture::bind( &texture );
  this->generationMap();
}

































