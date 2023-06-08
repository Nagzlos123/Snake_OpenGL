#ifndef SFERA_H_INCLUDED
#define SFERA_H_INCLUDED

#include "snake.h"

#define NEUTRALNA 1
#define ZLA 2
#define DOBRA 3
#define CZACHA 4

class Sfera
{
    public:
    int x,y;
    int ktora;

    void generuje (int ktora);
void rysuje_sfere (Tekstury*T);
int sprawdz_kolizje_sfery( Snake*glowa);
};


#endif // SFERA_H_INCLUDED
