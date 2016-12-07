//
//  Enemy.hpp
//  Projet test
//
//  Created by ORTEGA Pierre on 24/10/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
class Enemy {
public:
  Enemy(std::string pPathTex);
  ~Enemy();
  void consModelEnemy();
  void setTexture();
  GLdouble GetXPosmin();
  GLdouble GetYPosmin();
  GLdouble GetZPos();
  GLdouble GetXPosmax();
  GLdouble GetYPosmax();
  
protected:
  GLdouble xPosmin;
  GLdouble yPosmin;
  GLdouble zPos;
  GLdouble xPosmax;
  GLdouble yPosmax;

  sf::Texture texture;
  std::string pathTex;
  
};

#endif /* Enemy_hpp */
