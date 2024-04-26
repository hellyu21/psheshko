#include <iostream>
#include "figure.hpp"
#include "triange.hpp"
#include "para.hpp"

void figin(Figure& fg) {
    cout << fg.figin() << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    double ps1[8] = { 0, 0, 3, 0, 1, 2, 4, 2};
    Para pr(ps1, "Красный");
    figin(pr);

    cout << endl;

    double ps2[6] = { 0, 0, 2, 0, 1, 2 };
    Tria tr(ps2, "Цвет бедра испуганной лягушки");
    figin(tr);
}
