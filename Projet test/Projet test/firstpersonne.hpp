//
//  firstpersonne.hpp
//  Projet test
//
//  Created by ORTEGA Pierre on 14/10/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#ifndef firstpersonne_hpp
#define firstpersonne_hpp
#ifdef __APPLE__
  #include <OpenGL/glu.h>
#else
  #include <GL/glut.h>
#endif
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <math.h>
#include "Enemy.hpp"
#include "Projectile.hpp"
class firstpersonne {
public:
  firstpersonne(float fov, float aspect, float zNear, float zFar);
  void UpdateCamera(GLdouble pX,GLdouble pY,GLdouble pZ,GLdouble pCenterX,GLdouble pCenterY,GLdouble pCenterZ,GLdouble pUpX,GLdouble pUpY,GLdouble pUpZ);
  GLdouble GetXcam();
  GLdouble GetYcam();
  GLdouble GetZcam();
  GLdouble GetXcamCenter();
  GLdouble GetYcamCenter();
  GLdouble GetZcamCenter();
  bool Collision(double xCoorPlus, double zCoorPlus, double xCoorMoins, double zCoorMoins,GLdouble camPosX,GLdouble camPosZ,GLdouble camCenterX,GLdouble camCenterZ);
  void rotationCamera();
  void deplacementCamera(float pLx,float pLy, float pLz);
  bool destructionEnemy(Enemy * PosEnemy);
protected:
  GLdouble Xcam=0;
  GLdouble Ycam=0.f;
  GLdouble Zcam=0;
  GLdouble XcamCenter=0.f;
  GLdouble YcamCenter=0;
  GLdouble ZcamCenter=-1.f;
  // angle of rotation for the camera direction
  float angle1=0.0;
  float angle2=0.0;
};
#endif /* firstpersonne_hpp */
