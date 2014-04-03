/// STL
#include <iostream>

/// Third party
#include <SDL2/SDL.h>








 

void cb(void *userdata, Uint8 *stream, int len);

void play();

 
// global variables
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
 
const char* sample_file="waves/message.wav";

static Uint32 wav_length; // length of our sample
static Uint8 *wav_buffer; // buffer containing our audio file
static SDL_AudioSpec wav_spec; // the specs of our piece of music 
 
 
 
 

int main(int argc, char* argv[])
{
 
  


  if (SDL_Init(SDL_INIT_AUDIO) < 0)
          return 1; 




  
  
  
  sample_file="waves/alert.wav";
  play();
  
  sample_file="waves/time.wav";
  play();
    
  sample_file="waves/to.wav";
  play();

  sample_file="waves/get.wav";
  play();

  sample_file="waves/up.wav";
  play();  
 
}
 

void play()
{
  
  if( SDL_LoadWAV(sample_file, &wav_spec, &wav_buffer, &wav_length) == NULL )
  {
    return;
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
    

  SDL_CloseAudio();
  SDL_FreeWAV(wav_buffer);  
  
}


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
