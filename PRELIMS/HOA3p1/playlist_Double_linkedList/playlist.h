#ifndef playlist_H
#define playlist_H

#include <iostream>

template <typename T> 
class playlist {
    public:
        T data;
        playlist<T>* next = nullptr;
        playlist<T>* prev = nullptr;
};

//====================
//newnode
//====================

template <typename T>
//This function creates a new node in the playlist
//this function and the variables in it stays throughout the entire program
playlist<T>* new_node(T newData) {
    
    playlist<T>* newNode = new playlist<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

//====================
//add music
//==================== 

template <typename T>
void addsong(T newData, playlist<T>** currenthead) {
    
    //holds the data of the new node

    //!note: when it calls the function new_node it can access the variables in the function
    //ex. data, next, prev because it is a pointer to the new node created in the function new_node
    
    //so everytime we create a new node we must call the function new_node to create a new node and store the data in it
    playlist<T>* newNode = new_node(newData);
    
    if (*currenthead == nullptr) {
        
        //it assigns next and prev in the new_node function to point to itself because it is the first node in the playlist
        //because of the if stat
        newNode->next = newNode;
        newNode->prev = newNode;

        *currenthead = newNode;
        return;
    }
    
    playlist<T>* tail = (*currenthead)->prev;
    
    //connects to a new node which is the current head and the tail which is the last node in the playlist
    newNode->next = *currenthead;
    newNode->prev = tail;
    
    //connects the previous node which is tail to the new node which is the current head
    tail->next = newNode;
    (*currenthead)->prev = newNode;

    //holds the address of the new node which is the current head and assigns it to the current head pointer
    *currenthead = newNode;
};

//====================
//next song
//==================== 

template <typename T>
void next_song(playlist<T>** currenthead) {
    
    //to check if there are no songs in the playlist
    if (*currenthead == nullptr) {
        std::cout << "Playlist is empty. \n";
        return;
    }
    
    //points to the next song in the playlist
    *currenthead = (*currenthead)->next;

    std::cout << "Now playing: " << (*currenthead)->data << "\n";
};

//====================
//previous song
//==================== 

template <typename T>
void prev_song(playlist<T>** currenthead) {
    
    if (*currenthead == nullptr) {
        std::cout << "Playlist is empty. \n";
        return;
    }
    
    //points to the previous song in the playlist
    *currenthead = (*currenthead)->prev;

    std::cout << "Now playing: " << (*currenthead)->data << "\n";
};

//===================
//plays all songs
//===================
template <typename T>
void playAll(playlist<T>* currentNode) {

    if (currentNode == nullptr) {
        std::cout << "Playlist is empty. \n";
        return;
    }
    
    //places the currentnode at the start by default
    playlist<T>* start = currentNode;
    int num = 1;

    //outputs the song and traverses to the songs
    do {
        std::cout << num << ". " << currentNode->data << std::endl;

        num++;
        currentNode = currentNode->next;
    } while (currentNode != start); //prints the data without going back to the start
                                    //(because currentnode is assigned to the start by default)
};

//====================
// remove current song
//====================

template <typename T>
void remove_song(int pos, playlist<T>** currenthead) {

    if (*currenthead == nullptr) {
        std::cout << "Playlist is empty. Nothing to remove.\n";
        return;
    } 

    if (pos < 1) {
        std::cout << "Invalid position.\n";
        return;
    }

    //the songToRemove is the pointer accesing the pointer of the currenthead
    playlist<T>* songToRemove = *currenthead;

    // if there is one song in the playlist it removes it
    //meaning if the next song/node is itself(meaning theres only one)it will delete the current node/song- 
    //-and sets the currenthead pointer to null ptr
    if (songToRemove->next == songToRemove) {
        if (pos != 1) {
            std::cout << "Position out of bounds.\n";
            return;
        }
        std::cout << "Removed: " << songToRemove->data << "\n";
        delete songToRemove;
        *currenthead = nullptr;
        return;
    }

    //accesses the position given by the user in the main file
    for (int i = 1; i < pos; i++) {
        songToRemove = songToRemove->next;
        if (songToRemove == *currenthead) {
            std::cout << "Position out of bounds.\n";
            return;
        }
    }

    //creates a pointer called prevNode and nextNode and assigns it to the songToRemove 
    //- pointer which indicates the next and previous songs will be removed
    playlist<T>* prevNode = songToRemove->prev;
    playlist<T>* nextNode = songToRemove->next;

    //assigns the next and previous song 
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    // Move current head to the next song if we removed the original head node
    if (songToRemove == *currenthead) {
        *currenthead = nextNode;
    }

    //removes the chosen song to remove
    std::cout << "Removed: " << songToRemove->data << "\n";
    std::cout << "Now playing: " << (*currenthead)->data << "\n";

    // Free allocated memory
    delete songToRemove;
};

#endif 