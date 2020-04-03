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
   if(songs == NULL){         //no song in the list
      return NOT_FOUND;
   }
   Song tempSong = s;
   if(songs->next == NULL){   //one song in the list
      if(tempSong == songs->s){
         delete songs;
         songs = NULL;
         return SUCCESS;
      }
      else{
         return NOT_FOUND;
      }
   }
   else{                      //more than one song on the list
      if(songs->s == tempSong){
         SongNode *temporary = songs;
         songs = songs->next; //if removing head of list
         delete temporary;
         return SUCCESS;
      }
      SongNode *temp = songs;
      SongNode *prev = temp;
      while(temp != NULL){
         temp = temp->next;
         if(temp->s == tempSong){
            SongNode *temporary = temp;
            prev->next = temp->next;
            delete temporary;
            return SUCCESS;
         }
         prev = temp;
      }
      return NOT_FOUND;
   }
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
   SongNode *temp = songs;
   SongNode *ptr;
   SongNode *smallestNode = temp;
   Song smallestSong;
   while(temp != NULL){
      ptr = temp->next;
      smallestNode = temp;
      while(ptr != NULL){
         if(ptr->s < temp->s){
            smallestNode = ptr;
         }
         ptr = ptr->next;
      }
      smallestSong = smallestNode->s;
      smallestNode->s = temp->s;
      temp->s = smallestSong;
      temp = temp->next;
   }

}
    
void UtPod::clearMemory()
{
   SongNode *temp = songs;
   while(songs != NULL){
      songs = songs->next;
      delete temp;
      temp = songs;
   }
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
