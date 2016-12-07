//
//  Enemy.cpp
//  Projet test
//
//  Created by ORTEGA Pierre on 24/10/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#include "Enemy.hpp"
Enemy::Enemy(std::string pPathTex){
  pathTex=pPathTex;
  xPosmin=20.f;
  yPosmin=0.f;
  zPos=10.f;
  xPosmax=30.f;
  yPosmax=20.f;
}
Enemy::~Enemy(){

  
}
void Enemy::consModelEnemy(){
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0); glVertex3d(20.f, 0.f, 10.f);
  glTexCoord2d(0,1); glVertex3d(20.f,  20.f, 10.f);
  glTexCoord2d(1, 1); glVertex3d( 30.f, 20.f, 10.f);
  glTexCoord2d(1, 0); glVertex3d( 30.f,0.f, 10.f);
  glEnd();
}
void Enemy::setTexture(){
  texture.loadFromFile(pathTex);
  sf::Texture::bind( &texture );
  this->consModelEnemy();
}
GLdouble Enemy::GetXPosmin(){
  return xPosmin;
}
GLdouble Enemy::GetYPosmin(){
  return yPosmin;
}
GLdouble Enemy::GetZPos(){
  return zPos;
}
GLdouble Enemy::GetXPosmax(){
  return xPosmax;
}
GLdouble Enemy::GetYPosmax(){
  return yPosmax;
}
