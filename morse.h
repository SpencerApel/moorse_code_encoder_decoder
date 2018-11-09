#ifndef MORSE_H
#define MORSE_H

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

        node(){letter = ' '; code = " "; left = nullptr; right = nullptr;}
    };
    node *root;
    const char dot = '.';
    const char dash = '_';
    const int alphabet_size = 26;
    void build_tree(const char *file_path);
    void add_node(node *temp, std::string code, char c);

public:
    Morse(const char *file_path);
    ~Morse();
    std::string encode();
    std::string decode();
};

#endif