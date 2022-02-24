
#include <iostream>
#include "Matrice.h"

int main()
{
    auto m1 = Matrice(3, 3, 0.5);
    m1 = m1 + 2;
    m1.print();
}

