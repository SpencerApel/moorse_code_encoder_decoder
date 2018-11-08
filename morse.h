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
    };
    const int alphabet_size = 26;
    node *root;
    void build_tree(const char *file_path);
    void merge(std::string arr[], int left, int middle, int right);
    void merge_sort(std::string arr[], int left, int right);

public:
    Morse(const char *file_path);
    ~Morse();
    std::string encode();
    std::string decode();
};

#endif