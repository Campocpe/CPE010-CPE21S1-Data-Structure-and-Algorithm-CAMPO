#include <iostream>
#include <string>

#include "playlist.h"

int main() {

    //assigns the data type in the value t
    //creates the point variable head 
    //head points to each song as an indicator, right now its set to nullptr 

    playlist<std::string>* head = nullptr;
    int choice;

    //outputs the menu and choices
    do {
        std::cout << "1. Add Song\n2. Play All Songs\n3. Next Song\n4. Previous Song\n5. Remove Song\n6. Exit\nEnter choice: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "invalid choice \n";
            continue;
        }

        //creates a menu for the user to choose and access the songs   
        switch (choice) {

            //====================
            //add music
            //==================== 
            case 1:
            {
                std::string song;

                std::cout << "Enter music name: ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, song);
                
                //add the songname the head pointer to the function for it to execute
                addsong(song, &head);
                
                break;
            }
            
            //====================
            //plays all song
            //==================== 

            case 2:
            {
                std::cout << "=====playlist==== \n";

                playAll(head);

                break;
            }
            
            //====================
            //next song
            //==================== 
            case 3:
            {
                next_song(&head);
                break;
            }
            
            //====================
            //previous song
            //==================== 
            case 4:
            {
                prev_song(&head);
                break;
            }
            
            //====================
            //removes current song
            //==================== 
            case 5:
            {
                int numb;

                std::cout << "enter the song placement you want to delete: ";
                if (std::cin >> numb) {
                    remove_song(numb, &head);
                } else {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "invalid choice \n";
                }

                break;
            }

            case 6:
            {
                std::cout << "exiting playlist\n";
                break;
            }

            default:
            {
                std::cout << "invalid choice \n";
                break;
            }
        }

    } while (choice != 6);

    // Free remaining nodes on exit
    while (head != nullptr) {
        remove_song(1, &head);
    }

    return 0;
}