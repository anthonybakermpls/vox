/// STL
#include <iostream>
#include <list>

/// Third party
#include <SDL2/SDL.h>



#include "sample.h"




 

 

int main(int argc, char* argv[])
{
 
  


  if (SDL_Init(SDL_INIT_AUDIO) < 0)
          return 1; 


  std::list<Sample> sample_list;
  
  Sample s1("waves/alert.wav");
  Sample s2("waves/surface.wav");
  Sample s3("waves/temperature.wav");
  Sample s4("waves/has.wav");
  Sample s5("waves/supercooled.wav");    
  Sample s6("waves/energy.wav");    
  Sample s7("waves/supply.wav");    
  
//  sample_list.push_back(s1);
//  sample_list.push_back(s2);
//  sample_list.push_back(s3);
//  sample_list.push_back(s4);  
//  sample_list.push_back(s5);  
//
//
//  sample_list.front().play();
  

//  for (std::list<Sample>::iterator it=sample_list.begin(); it != sample_list.end(); ++it)
//    it->play();
//    
//    


  s1.play();
  s2.play();
  s3.play();
  s4.play();
  s5.play();
  s6.play();
  s7.play();
  

 
}
 
