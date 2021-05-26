#pragma once
#include<iostream>
#include<list>


class Song {

private:
	std::list<std::string>player_list;
	std::list<std::string>::iterator selector_position;
public:

	Song();
	~Song() = default;
	void current_song();
	void next_song();
	void prev_song();
	void current_playlist();
	void add_song();
	//bool operator<(const Song& s1) const;
	


};