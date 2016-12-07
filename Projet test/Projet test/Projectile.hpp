//
//  Projectile.hpp
//  Projet test
//
//  Created by ORTEGA Pierre on 08/11/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp
#include "Enemy.hpp"
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif
#include "firstpersonne.hpp"
#include <SFML/OpenGL.hpp>
#include <stdio.h>
class Projectile {
public:
  bool destructionEnemy(Enemy * PosEnemy);
  Projectile(float x,float y,float z,float anglex ,float angley,float anglez);
  ~Projectile();
  void Updateposition();
  void ShootProjetctile();
  
private:
  GLdouble Posx;
  GLdouble Posy;
  GLdouble Posz;
  GLdouble PosxUp;
  GLdouble PosyUp;
  GLdouble PoszUp;
};
#endif /* Projectile_hpp */
