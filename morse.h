#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>

class Morse
{
  private:
    struct node
    {
        char letter;
        std::string code;
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
    struct node *add_node(node *temp, std::string code, char c); //adds a node to the tree is respective location
    void encode(node *temp, std::string code); //function to encode regular text
    char decode(node *temp, std::string code); //function to decode morse text

  public:
    Morse(const char *file_path);
    ~Morse();
    void encode(std::string code); //wrapper function
    void decode(std::string code); //wrapper function
};

#endif