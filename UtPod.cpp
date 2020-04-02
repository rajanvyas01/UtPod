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
         memSize = MAX_MEMORY;
      }
      memSize = size;
   }
  
   int UtPod::addSong(Song const &s)
   {
      return 0;
   }  

   int UtPod::removeSong(Song const &s)
   {
   }

   void UtPod::shuffle()
   {
   }

   void UtPod::showSongList()
   {
   }

   void UtPod::sortSongList()
   {
   }
    
   void UtPod::clearMemory()
   {
   }

   int UtPod::getRemainingMemory()
   {
   }

   UtPod::~UtPod()
   {
   }
