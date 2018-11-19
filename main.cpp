#include "morse.h"

int main()
{
    Morse m = Morse("morse.txt");
    m.encode("Mor!se");
    m.decode(".__. ._. ___ __. ._. ._ __ __ .. _. __.");
    return 0;
}