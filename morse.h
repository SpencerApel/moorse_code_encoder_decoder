#ifndef MORSE_H
#define MORSE_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> //used for std::transform in encode(string)

using std::cout;
using std::endl;
using std::string;

class Morse
{
  private:
    struct node
    {
        char letter;
        string code;
        node *left;
        node *right;

        node(){letter = ' '; code = " "; left = nullptr; right = nullptr;} //node constructor
    };
    node *root;

    const char dot = '.'; //go left
    const char dash = '_'; //go right
    const char delimiter = ' '; //space delimited for decoding string
    const int alphabet_size = 26;

    void build_tree(const char *file_path); //opens file and builds tree by calling add_node()
    node *add_node(node *temp, string code, char c); //adds a node to the tree is respective location
    void encode(node *temp, string message, string &code); //function to encode regular text
    void decode(node *temp, string code, string &message); //function to decode morse text

  public:
    Morse(const char *file_path);
    ~Morse();
    void encode(string code); //wrapper function
    void decode(string code); //wrapper function
};

#endif