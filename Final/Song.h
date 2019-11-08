#pragma once
#include<string>

class Song
{
	private:
		
	public:
		std::string title;
		std::string artist;
		std::string album;
		std::string genre;
		int songLength;
		int playCount;
		//contructors
		Song(): songLength(0), playCount(0) {}
		Song(std::string a, std::string b, std::string c, std::string d, int e, int f)
			:title(a), artist(b), album(c), genre(d), songLength(e), playCount(f) {}
		//destructor
		~Song() {}
	
		//setters
		void setTitle(std::string a) { title=a; }
		void setArtist(std::string a) { artist = a; }
		void setAlbum(std::string a) { album = a; }
		void setGenre(std::string a) { genre = a; }		
		void setSongLength(int a) { songLength = a; }
		void setPlayCount(int a) { playCount = a; }
		//getters
		std::string getTitle() { return title; }
		std::string getArtist() { return artist; }
		std::string getAlbum() { return album; }
		std::string getGenre() { return genre; }		
		int getSongLength() { return songLength; }
		int getPlayCount() { return playCount; }

		friend std::istream& operator >> (std::istream  &is, Song& c1)
		{
			getline(is, c1.title, '\t');
			getline(is, c1.artist, '\t');
			getline(is, c1.album, '\t');
			getline(is, c1.genre, '\t');
			is >> c1.songLength;
			is >> c1.playCount;
			return is;
		}
		
		 friend std::ostream& operator<<(std::ostream& os, Song& c2)
		{
			os << c2.title<<"\t";
			os << c2.artist << "\t" ;
			os << c2.album << "\t"  ;
			os << c2.genre << "\t"  ;
			os << c2.songLength << "\t"  ;
			os << c2.playCount << "\t"  ;
			return os;
		}
	};