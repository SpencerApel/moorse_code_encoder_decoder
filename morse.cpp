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

    string morse_file;
    for (int i = 0; i < alphabet_size; i++) //loop through the file
    {
        file_in >> morse_file;
        root = add_node(root, morse_file.substr(1), morse_file[0]); //create a node and add to root
    }
}

Morse::node *Morse::add_node(node *temp, string code, char c)
{
    if (temp == nullptr)    //if temp is nullptr
        temp = new node();  //create new node
    if (code.length() == 0) //if there are no more . or _
    {
        temp->letter = c; //set letter to current node
        return temp;
    }
    else
    {
        if (code[0] == dot)                                         //if next char is a dot
            temp->left = add_node(temp->left, code.substr(1), c);   //go left and recursively call
        else                                                        //if next char is a dash
            temp->right = add_node(temp->right, code.substr(1), c); //go right and recursively call
    }
    return temp;
}

void Morse::encode(string message)
{
    string code;
    cout << "Encoding: " << message << endl;
    std::transform(message.begin(), message.end(), message.begin(), tolower);
    cout << message << endl;
    //std::transform(message.begin(), message.end(), code.begin(), encode(root, message, code));
    encode(root, message, code);
    cout << "Code: " << code << endl;
}

void Morse::encode(node *temp, string message, string &code)
{
    cout << "currently at: " << temp->letter << endl;

    if (message[0] == temp->letter)
    {
        cout << "FOUND IT!" << endl;
        if (message.substr(1).length() != 0)
            encode(root, message.substr(1), code += " ");
        return;
    }
    
    if (temp->left == nullptr && temp->right == nullptr)
    {
        code.pop_back();
        return;
    }
    else if (temp->left == nullptr || temp->right == nullptr)
    {
        if (temp->left == nullptr)
            encode(temp->right, message, code += dash);
        else if (temp->right == nullptr)
            encode(temp->left, message, code += dot);
    }
    else
    {
        cout << "rec call" << endl;
        encode(temp->left, message, code += dot);
        encode(temp->right, message, code += dash);
    }
}

void Morse::decode(string code)
{
    string message;
    cout << "Decoding: " << code << endl;
    decode(root, code, message); //call decode function
    cout << "Message: " << message << endl;
}

void Morse::decode(node *temp, string code, string &message)
{
    if (code[0] == dot)                                  //if char is a .
        decode(temp->left, code.substr(1), message);     //recursively call func with pointer to left and string code 1-length
    else if (code[0] == dash)                            //if char is a _
        decode(temp->right, code.substr(1), message);    //recursively call func with pointer to right and string code 1-length
    else if (code[0] == delimiter || code.length() == 0) //if theres a space or at the end of the code
    {
        message += temp->letter;                   //add letter to message
        if (code.length() != 0)                    //if not at the end of the code
            decode(root, code.substr(1), message); //another recursive call using root (to start over from the top for the next char)
    }
}