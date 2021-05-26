// list_ds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "list_player.h"

void play_list(Song* songs) {
    char selection;
    do {
        
        std::cout << "F - Play First Song " << std::endl;
        std::cout << "N - Play Next song " << std::endl;
        std::cout << "P - Play Previous song" << std::endl;
        std::cout << "A - Add and play a new Song at current location" << std::endl;
        std::cout << "L - List the current playlist " << std::endl;
        std::cout << "============================================== " << std::endl;
        std::cout << "Enter a selection (Q to quit):" << std::endl;

        std::cin >> selection;
        selection = toupper(selection);

        switch (selection) {
        case 'F':
            songs->current_song();
            break;
        case 'N':
            songs->next_song();
            break;
        case 'P':
            songs->prev_song();
            break;
        case 'A':
            songs->add_song();
            break;
        case 'L':
            songs->current_playlist();
            break;
        default:
            std::cout << "Player exiting.......Good bye!!";
            break;
        }


    } while (selection != 'Q');
}

/*Song class impl starts here*/

Song::Song():
    player_list{
                "God's Plan          Drake                 5",
                "Never Be The Same   Camila Cabello        5",
                "Pray For Me   The Weekendand K.Lamar      4",
                "The Middle    Zedd, Maren Morris & Grey   5",
                "Wait          Maroone                     5",
                "Whatever It Takes Imagine      Dragons    3"}
{

    selector_position = player_list.begin();

    current_playlist();

}

void Song::current_song() {

    std::cout << " Current song --> "<< *selector_position<< std::endl;
}

void Song::next_song() {

    if (selector_position != player_list.end() && std::next(selector_position)!= player_list.end()) {
        ++selector_position;
    }
    else { 
        selector_position = player_list.begin();
    }
    
    std::cout << " Current song --> " << *selector_position << std::endl;
}

void Song::current_playlist() {
    printf("\n");
    std::cout << "============ Current playlist ============== "<<std::endl;
    std::cout << "Title              Artist               Ratings" << std::endl;
    auto it = player_list.begin();
    while (it != player_list.end()) {
        std::cout << *it << std::endl;
        ++it;
    }
    printf("\n");
}

void Song::prev_song() {
    if (selector_position == player_list.begin()) selector_position = --player_list.end();

    else {
        selector_position--;
    }

    std::cout << "Now playing "<< *selector_position <<std::endl;
}

void Song::add_song() {

    std::string title;
    std::string rating;
    std::string artist;

    std::cout << "Adding and playing new song " << std::endl;
    std::cout << "Enter song title " << std::endl;
    std::cin >> title;

    std::cout << "Enter artist name " << std::endl;
    std::cin >> artist;

    std::cout << "Enter your rating (1-5) " << std::endl;
    std::cin >> rating;

    std::string song_to_add{ title + "               " + artist + "                " + rating };
    player_list.insert(selector_position, song_to_add);
    selector_position--;
    current_playlist();
}

//Uses std::list data structure to simulate a playlist.
int main()
{
    Song song;
    play_list(&song);
}

