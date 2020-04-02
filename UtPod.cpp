//UtPod.cpp

#include "Song.h"
#include "UtPod.h"
#include <stdlib.h>

using namespace std;

UtPod::UtPod()
{ 
   songs = NULL;
   memSize = MAX_MEMORY;
}

UtPod::UtPod(int size)
{
   songs = NULL;
   memSize = size;
   if(size <= 0 || size > MAX_MEMORY){
      memSize = MAX_MEMORY;
   }
}
 
int UtPod::addSong(Song const &s)
{
  if(getRemainingMemory() > s.getSongSize()){
     struct SongNode *temp = new struct SongNode;
     if(songs == NULL){
        temp->next = NULL;
     }
     else{
        temp->next = songs;
     }
     songs = temp;
     Song q = s;
     temp->s = q;
     return SUCCESS;
  }
  else{
     return NO_MEMORY;
  }
}  

int UtPod::removeSong(Song const &s)
{
  return 0;
}

void UtPod::shuffle()
{
}

void UtPod::showSongList()
{
   int count = 1;
   SongNode *temp;
   temp = songs;
   while(temp != NULL){
   cout << count << ". " << temp->s.getArtist() << ", " << temp->s.getTitle() << "  " << temp->s.getSongSize() << "MB" << endl;
   temp = temp->next;
   count++;
   }
}

void UtPod::sortSongList()
{
}
    
void UtPod::clearMemory()
{
}

int UtPod::getRemainingMemory()
{
   if(songs == NULL){
      return memSize;
   }
   else{
      SongNode *temp;
      temp = songs;
      int count = 0;

      while(temp != NULL){
         count += temp->s.getSongSize();
         temp = temp->next;
      }
      return (memSize - count);
   }
}

UtPod::~UtPod()
{
}
