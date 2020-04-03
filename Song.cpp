//Song.cpp

#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

   Song::Song()
   {
      artist = "";
      title = "";
      size = MAX_SIZE;
   }

   Song::Song(string _artist, string _title)
   {
      title = _title;
      artist = _artist;
      size = MAX_SIZE;
   }

   Song::Song(string _artist, string _title, int _size)
   {
      title = _title;
      artist = _artist;
      size = _size;
   }
   
   string Song::getArtist() const
   {
      return artist;
   }

   void Song::setArtist(string name)
   {
      artist = name;
   }

   string Song::getTitle() const
   {
      return title;
   }
  
   void Song::setTitle(string tit)
   { 
      title = tit;
   }

   int Song::getSongSize() const
   {
      return size;
   }
   
   void Song::setSongSize(int s)
   {
      size = s;
   }

   bool Song::operator >(Song const &rhs)
   {
      if(artist == rhs.artist){
         if(title == rhs.title){
            return (size > rhs.size);
         }
         return (title > rhs.title);
      }
      return (artist > rhs.artist);
   }

   bool Song::operator <(Song const &rhs)
   {
      if(artist == rhs.artist){
         if(title == rhs.title){
            return (size < rhs.size);
         }
         return (title < rhs.title);
      }
      return (artist < rhs.artist);
   }
   
   bool Song::operator ==(Song const &rhs)
   {
      return (artist == rhs.artist &&
              title == rhs.title &&
              size == rhs.size);
   }

   Song::~Song()
   {
    //  cout << "debug - in destructor for " << artist << endl;
   }

 /*  ostream& operator << (ostream& out, const Song &s)
   {
      out << s.getArtist() << ", " << g.getTitle() << " -" << g.getSongSize() << "MB";
      return out;
   }*/
