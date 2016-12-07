//
//  firstpersonne.cpp
//  Projet test
//
//  Created by ORTEGA Pierre on 14/10/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#include "firstpersonne.hpp"

firstpersonne::firstpersonne(float fov, float aspect, float zNear, float zFar){
  //// Setup a perspective projection & Camera position
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fov, aspect, zNear, zFar);
}
void firstpersonne::UpdateCamera(GLdouble pX,GLdouble pY,GLdouble pZ,GLdouble pCenterX,GLdouble pCenterY,GLdouble pCenterZ,GLdouble pUpX,GLdouble pUpY,GLdouble pUpZ){
  

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  // Apply some transformations for the cube
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  
  if(!this->Collision(100, 100, -100, -100,pX,pZ,pCenterX,pCenterZ)){
    Xcam+=pX;
    Ycam=pY;
    Zcam+=pZ;
  
    YcamCenter=pCenterY;
    XcamCenter=pCenterX;
    ZcamCenter=pCenterZ;
   
  }
  
    gluLookAt(Xcam, 10.f, Zcam, Xcam+XcamCenter, 10.f+YcamCenter,Zcam+ZcamCenter, 0.f, 1000.f, 0.f);
  
  
  //glTranslated(Zcam,0,Xcam);
}
GLdouble firstpersonne::GetXcam(){
  return Xcam;
}
GLdouble firstpersonne::GetYcam(){
  return Ycam;
}
GLdouble firstpersonne::GetZcam(){
  return Zcam;
}
GLdouble firstpersonne::GetXcamCenter(){
  return XcamCenter;
}
GLdouble firstpersonne::GetYcamCenter(){
  return YcamCenter;
}
GLdouble firstpersonne::GetZcamCenter(){
  return ZcamCenter;
}
void firstpersonne::rotationCamera(){
  
  float lx=0.0f,lz=-1.0f,ly=10.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    angle1 += 0.05f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    angle1 -= 0.05f;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    angle2+=0.05f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    angle2-=0.05f;
  }
  if (angle2 > 7.8){
    angle2 = 7.8;
  }
  else if (angle2 < 4.8){
    angle2 = 4.8;
  }
  lx = sin(angle1)*cos(angle2);
  ly=sin(angle2);
  lz = cos(angle1)*cos(angle2);
  this->deplacementCamera(lx,ly,lz);
}
void firstpersonne::deplacementCamera(float pLx,float pLy, float pLz){
  float fraction = 0.1f;
  float speed=5.f;
  float axisVertical, axisHorizontal;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
    axisHorizontal = pLz * fraction*speed;
    axisVertical = pLx * fraction*speed;

    
  }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    axisHorizontal =-pLz * fraction*speed;
    axisVertical = -pLx * fraction*speed;
    
  }else {
    axisHorizontal = 0;
    axisVertical =0;
  }
  
  this->UpdateCamera(axisVertical, pLy, axisHorizontal, pLx,pLy,pLz, 0, 0, 1.f);
  
}
// fonction reserve a la classe projectile 
bool firstpersonne::destructionEnemy(Enemy * PosEnemy){
  bool res=false;
  if (this->GetXcam()<=PosEnemy->GetXPosmax() && this->GetXcam()>=PosEnemy->GetXPosmin()) {
    std::cout<<this->GetZcam()<<"et"<<PosEnemy->GetZPos()<<std::endl;
    if(this->GetZcam()>=PosEnemy->GetZPos() && this->GetZcam()<=PosEnemy->GetZPos()+1.0f){
        std::cout<<this->GetZcam()<<"et"<<PosEnemy->GetZPos()<<std::endl;
        res=true;
    }
  }
  return res;

}
bool firstpersonne::Collision(double xCoorPlus, double zCoorPlus, double xCoorMoins, double zCoorMoins,GLdouble camPosX,GLdouble camPosZ,GLdouble camCenterX,GLdouble camCenterZ){
  bool res=false;
  if (this->GetXcam()+camPosX+camCenterX>=xCoorPlus || this->GetZcam()+camPosZ+camCenterZ>=zCoorPlus) {
    res=true;
  } else if(this->GetXcam()+camPosX+camCenterX<=xCoorMoins || this->GetZcam()+camPosZ+camCenterZ<=zCoorMoins){
    res=true;
  }
  return res;
}

