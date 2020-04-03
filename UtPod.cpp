//UtPod.cpp

#include "Song.h"
#include "UtPod.h"
#include <stdlib.h>
#include <ctime>

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
           //more than one song on the list
   if(songs->s == tempSong){
      SongNode *temporary = songs;
      songs = songs->next; //if removing head of list
      delete temporary;
      return SUCCESS;
   }
   SongNode *temp = songs;
   SongNode *prev = songs;
   temp = temp->next;
   while(temp != NULL){
      if(temp->s == tempSong){
         SongNode *temporary = temp;
         prev->next = temp->next;
         delete temporary;
         return SUCCESS;
      }
      prev = temp;
      temp = temp->next;
   }
   return NOT_FOUND;
}

void UtPod::shuffle()
{
   if((songs == NULL) || (songs->next == NULL)){
        return;
    }

    srand(time(0));
    int numSongs = 0;
    SongNode *song1 = songs;
    SongNode *song2 = NULL;

    while(song1 != NULL){
        numSongs++;
        song1 = song1->next;
    }

    if(numSongs < 2){
        return;
    }

    for(int k = 0; k < (numSongs * 3); k++){
        song1 = songs;
        song2 = songs;
        int rNum1 = (rand() % numSongs);
        int rNum2 = (rand() % numSongs);

        for(int i = 0; i < rNum1; i++){
            song1 = song1->next;
        }
        for(int j = 0; j < rNum1; j++){
            song2 = song2->next;
        }

        Song saveSong = song1->s;
        song1->s = song2->s;
        song2->s = saveSong;
    }

    return;

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
