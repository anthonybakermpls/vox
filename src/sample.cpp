#include "sample.h"



Sample::Sample()
{

    
}


Sample::Sample(const char* s)
{
  wave_file=s;
  if( SDL_LoadWAV(wave_file, &wav_spec, &wav_buffer, &wav_length) == NULL )
  {
    return;
  }
  wav_spec.callback = cb;
  wav_spec.userdata = this; // slip this in as void *userdata 
  audio_pos = wav_buffer; // copy sound buffer
  audio_len = wav_length; // copy file length
}

Sample::~Sample()
{
  SDL_FreeWAV(wav_buffer);
}



void Sample::play()
{


  if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
  {
    fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
    exit(-1);
  }
  
  SDL_PauseAudio(0);  // Start playing

  while ( audio_len > 0 )   // wait until we're done playing
  {
      SDL_Delay(10); 
  }
    
  SDL_CloseAudio();
}


  
void Sample::cb(void *userdata, Uint8 *stream, int len)
{
  
  Sample* s=static_cast<Sample*>(userdata);
  
  if (s->audio_len ==0)
      return;
  
  len = ( len > s->audio_len ? s->audio_len : len );
  SDL_memcpy (stream, s->audio_pos, len); 					// simply copy from one buffer into the other
  
//	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
  
  s->audio_pos += len;
  s->audio_len -= len;
  
  
}

    
