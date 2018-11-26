#ifndef MORSE_H
#define MORSE_H

#include <iostream>
#include <string>
#include <fstream>   //for file input
#include <algorithm> //used for std::transform in encode(string)
#include <ctype.h>   //to check if a char is part of the alphabet isalpha()

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

    node()
    {
      letter = ' ';
      code = " ";
      left = nullptr;
      right = nullptr;
    } //node constructor
  } * root;

  const char DOT = '.';   //go left
  const char DASH = '_';  //go right
  const char SPACE = ' '; //space delimited for decoding string
  const int ALPHABET_SIZE = 26;

  void build_tree(const char *file_path);                                   //opens file and builds tree by calling add_node()
  node *add_node(node *temp, string code, char c, const string morse_code); //adds a node to the tree is respective location
  void encode(node *temp, string &message, string &code);                   //function to encode regular text
  void decode(node *temp, string code, string &message);                    //function to decode morse text
  void delete_nodes(node *temp);                                            //to delete the tree at the end of the program

public:
  Morse(const char *file_path);
  ~Morse();
  void encode(string code); //wrapper function
  void decode(string code); //wrapper function
};

#endif