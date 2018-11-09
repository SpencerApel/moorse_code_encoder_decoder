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
    for(int i = 0; i < alphabet_size; i++)
    {
        file_in >> morse_file;
        add_node(root, morse_file.substr(1), morse_file[0]);
    }
}

void Morse::add_node(node *temp, std::string code, char c)
{
    if(temp == nullptr)
        temp = new node();
    if(code.size() == 0)
        temp->letter = c;
    else
    {
        if(code[0] == dot)
            add_node(temp->left, code.substr(1), c);
        else
            add_node(temp->right, code.substr(1), c);
    }
}
    
std::string Morse::encode()
{

}
    
std::string Morse::decode()
{

}