/// STL
#include <iostream>

/// Third party
#include <SDL2/SDL.h>








 
// audio callback
void cb(void *userdata, Uint8 *stream, int len);
 
// global variables
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
 
 

int main(int argc, char* argv[])
{
 
  

  // Initialize SDL.
  if (SDL_Init(SDL_INIT_AUDIO) < 0)
          return 1; 

  const char* sample_file="waves/message.wav";



  // local variables
  static Uint32 wav_length; // length of our sample
  static Uint8 *wav_buffer; // buffer containing our audio file
  static SDL_AudioSpec wav_spec; // the specs of our piece of music
  
  

  // the specs, length and buffer of our wav are filled
  if( SDL_LoadWAV(sample_file, &wav_spec, &wav_buffer, &wav_length) == NULL )
  {
    return 1;
  }

  wav_spec.callback = cb;	// set the callback function
  wav_spec.userdata = NULL;


  audio_pos = wav_buffer; // copy sound buffer
  audio_len = wav_length; // copy file length
  

  if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
  {
    fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
    exit(-1);
  }
  

  SDL_PauseAudio(0);  // Start playing


  while ( audio_len > 0 )   // wait until we're don't playing
  {
      SDL_Delay(100); 
  }
  
    
    
    
    
    
    
  // shut everything down
  SDL_CloseAudio();
  SDL_FreeWAV(wav_buffer);
 
}
 



// here you have to copy the data of your audio buffer into the
// requesting audio buffer (stream)
// you should only copy as much as the requested length (len)
void cb(void *userdata, Uint8 *stream, int len) 
{
  if (audio_len ==0)
      return;
  
  len = ( len > audio_len ? audio_len : len );
  SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
  
//	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
  
  audio_pos += len;
  audio_len -= len;
}
