//
//  Map.hpp
//  Projet test
//
//  Created by ORTEGA Pierre on 14/10/2016.
//  Copyright © 2016 ORTEGA Pierre. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <stdio.h>
#include <iostream>
class Map {
  public :
  Map(std::string pPathTex);
  ~Map();
  void generationMap();
  void setTexture();

  
  private:
  sf::Texture texture;
  std::string pathTex;
};
#endif /* Map_hpp */
