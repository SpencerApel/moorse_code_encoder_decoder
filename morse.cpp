#include "morse.h"

Morse::Morse(const char *file_path)
{
    root = new node();
    build_tree(file_path);
}

Morse::~Morse()
{
    //delete[] root;
}

void Morse::build_tree(const char *file_path)
{
    std::ifstream file_in;
    file_in.open(file_path); //open file

    std::string morse_file;
    for (int i = 0; i < alphabet_size; i++) //loop through the file
    {
        file_in >> morse_file;
        root = add_node(root, morse_file.substr(1), morse_file[0]); //create a node and add to root
    }
}

Morse::node *Morse::add_node(node *temp, std::string code, char c)
{
    if (temp == nullptr) //if temp is nullptr
        temp = new node(); //create new node
    if (code.length() == 0) //if there are no more . or _
    {
        temp->letter = c; //set letter to current node
        return temp;
    }
    else
    {
        if (code[0] == dot) //if next char is a dot
            temp->left = add_node(temp->left, code.substr(1), c); //go left and recursively call
        else //if next char is a dash
            temp->right = add_node(temp->right, code.substr(1), c); //go right and recursively call
    }
    return temp;
}

void Morse::encode(std::string code)
{
    
}

void Morse::encode(node *temp, std::string code)
{

}

void Morse::decode(std::string code)
{
    
}

char Morse::decode(node *temp, std::string code)
{
    
}