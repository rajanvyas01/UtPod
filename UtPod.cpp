//UtPod.cpp

#include "Song.h"
#include "UtPod.h"

using namespace std;

   UtPod::UtPod()
   { 
      songs = NULL;
      memSize = MAX_MEMORY;
   }

   UtPod::UtPod(int size)
   {
      if(size <= 0 || size > MAX_MEMORY){
         size = MAX_MEMORY;
      }
      return size;
   }
  
   int UtPod::addSong(Song const &s)
   {
      return 0; 
   }   
