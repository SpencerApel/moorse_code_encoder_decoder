#include "morse.h"

Morse::Morse(const char *file_path)
{
    root = new node();
    build_tree(file_path);
}

Morse::~Morse()
{
    delete_nodes(root); //calls recursive function to delete the tree
}

void Morse::delete_nodes(node *temp)
{
    if(temp != nullptr)
    {
        delete_nodes(temp->left); //rec call for left
        delete_nodes(temp->right); //rec call for right
        delete temp; //delete the node
    }
}

void Morse::build_tree(const char *file_path)
{
    std::ifstream file_in;
    file_in.open(file_path); //open file

    string morse_file;
    for (int i = 0; i < ALPHABET_SIZE; i++) //loop through the file
    {
        file_in >> morse_file;
        root = add_node(root, morse_file.substr(1), morse_file[0], morse_file.substr(1)); //create a node and add to root
    }
}

Morse::node *Morse::add_node(node *temp, string code, char c, string code2)
{
    if (temp == nullptr) //if temp is nullptr
        temp = new node(); //create new node
    if (code.length() == 0) //if there are no more . or _
    {
        temp->letter = c; //set letter to current node
        temp->code = code2; //set code2 (morse code translation) into current node code
        return temp;
    }
    else
    {
        if (code[0] == DOT) //if next char is a DOT
            temp->left = add_node(temp->left, code.substr(1), c, code2); //go left and recursively call
        else //if next char is a DASH
            temp->right = add_node(temp->right, code.substr(1), c, code2); //go right and recursively call
    }
    return temp;
}

void Morse::encode(string message)
{
    string code;
    cout << "Encoding: " << message << endl;
    std::transform(message.begin(), message.end(), message.begin(), tolower); //make all characters in string lowercase
    encode(root, message, code); //call recursive function to encode the message
    cout << "Code: " << code << endl;
}

void Morse::encode(node *temp, string message, string &code)
{
    if(message.length() == 0)
        return;


    // if(isalpha(message[0]) == false) //if the character is not a letter of the alphabet
    //     encode(root, message.substr(1), code += " ? "); //add a ? since the char doesnt exist
    // if(message[0] <= 'a' || message[0] >= 'z')
    //     encode(root, message.substr(1), code += " ? ");


    if (message[0] == temp->letter) //if the letter is found
    {
        code += temp->code; //set string code to the char's code
        if (message.substr(1).length() != 0) //if not at the last letter
            encode(root, message.substr(1), code += SPACE); //recursive call where the message loses the first char, and a space is added to code
        return;
    }
    if (temp->left == nullptr && temp->right == nullptr) //if left and right are nullptr
        return;
    else if (temp->right == nullptr) //if right is nullptr (never have to check for left bc of the way the tree is built in morse code)
        encode(temp->left, message, code); //recursive call with to the left child
    else //if node is full
    {
        encode(temp->left, message, code); //rec call left
        encode(temp->right, message, code); //rec call right
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
    if (code[0] == DOT) //if char is a .
        decode(temp->left, code.substr(1), message); //recursively call func with pointer to left and string code 1-length
    else if (code[0] == DASH) //if char is a _
        decode(temp->right, code.substr(1), message); //recursively call func with pointer to right and string code 1-length
    else if (code[0] == SPACE || code.length() == 0) //if theres a SPACE or at the end of the code
    {
        message += temp->letter; //add letter to message
        if (code.length() != 0) //if not at the end of the code
            decode(root, code.substr(1), message); //another recursive call using root (to start over from the top for the next char)
    }
}