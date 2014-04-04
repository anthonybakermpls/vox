#ifndef SAMPLE_H
#define SAMPLE_H


/// Third party
#include <SDL2/SDL.h>





class Sample
{
  public:
    Sample();
    Sample(const char*);
    virtual ~Sample();
    
    void play();

  private:
  
  static void cb(void *, Uint8 *, int );


  Uint8 *audio_pos; // global pointer to the audio buffer to be played
  Uint32 audio_len; // remaining length of the sample we have to play
   
  const char* wave_file;

  Uint32 wav_length; // length of our sample
  Uint8 *wav_buffer; // buffer containing our audio file
  SDL_AudioSpec wav_spec; // the specs of our piece of music 
   
    
};

#endif 
