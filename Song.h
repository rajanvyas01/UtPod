//Song.h

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

//SONG class declaration
class Song
{
   private:
      string artist;
      string title;
      int size;

      static const int MAX_SIZE = 512;
 
   public:
      //Default constructor
      Song();
      Song(string title, string artist);
      Song(string title, string artist, int size);

      string getArtist() const;
      void setArtist(string name);
      string getTitle() const;
      void setTitle(string tit);
      int getSongSize() const;
      void setSongSize(int s);

      bool operator >(Song const &rhs);
      bool operator <(Song const &rhs);
      bool operator ==(Song const &rhs);

      ~Song();
 
};

//ostream& operator << (ostream& out, cost Song &s);

#endif
