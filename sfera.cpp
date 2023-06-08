#include "main.h"
#include "tekstury.h"
#include "sfera.h"


int Sfera::sprawdz_kolizje_sfery( Snake*glowa)
{
    float x1, y1;
    //if(S==NULL) return 0;
        x1 = reszta_niedoknca(glowa->x,WX);
        y1 = reszta_niedoknca(glowa->y,WY);


                if(sqrt(pow(x1-x,2)+pow(y1-y,2))<WIELKOSC*0.75) return 1;


return 0;

}
void Sfera::generuje (int ktora)
{
  x =  rand()%(WX-2*WIELKOSC)+WIELKOSC;
  y =  rand()%(WY-2*WIELKOSC)+WIELKOSC;
  this-> ktora = ktora;
}
void Sfera::rysuje_sfere (Tekstury*T)
{
    switch(ktora)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->sfera_neutralna.ID);break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->sfera_zla.ID);break;
        case 3 : glBindTexture(GL_TEXTURE_2D, T->sfera_dobra.ID);break;
        case 4 : glBindTexture(GL_TEXTURE_2D, T->czacha.ID);break;

    }
        glPushMatrix();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glTranslatef(x,y,0);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex2i(- WIELKOSC/4,- WIELKOSC/4  );
            glTexCoord2f(0.0f,0.0f);glVertex2i(- WIELKOSC/4, WIELKOSC/4  );
            glTexCoord2f(1.0f,0.0f);glVertex2i( WIELKOSC/4, WIELKOSC/4  );
            glTexCoord2f(1.0f,1.0f);glVertex2i( WIELKOSC/4,- WIELKOSC/4  );
        glEnd();
        glDisable(GL_BLEND);
glPopMatrix();
}
