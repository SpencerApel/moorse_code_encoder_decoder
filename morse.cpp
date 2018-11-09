#include "morse.h"

Morse::Morse(const char *file_path)
{
    root = nullptr;
    build_tree(file_path);
}

Morse::~Morse()
{

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
    {
        std::cout << "tempnull" << std::endl;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->letter = ' ';
        temp->code = " ";
    }
    if(code.size() == 0)
    {
        std::cout << "set letter " << c << std::endl;
        //std::cout << "curr temp letter b4 set " >> temp->letter << "|" << std::endl;
        //temp->letter = c;
        temp->code = "code";
        std::cout << "letter set" << std::endl;
    }
    else
    {
        if(code[0] == dot)
        {
            std::cout << "add dot" << std::endl;
            std::cout << "code size: " << code.size() << std::endl;
            add_node(temp->left, code.substr(1), c);
        }
        else
        {
            std::cout << "add dash" << std::endl;
            std::cout << "code size: " << code.size() << std::endl;
            add_node(temp->right, code.substr(1), c);
        }
    }
}
    
std::string Morse::encode()
{

}
    
std::string Morse::decode()
{

}