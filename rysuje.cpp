#include "maszyna_stanow.h"

void MenuTryb::rysuje(int stan, Tekstury*T)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

     glBindTexture(GL_TEXTURE_2D, T->menu_tryb.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.2,WY1*0.2);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.2,WY1*0.8);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.8,WY1*0.8);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.8,WY1*0.2);

        glEnd();
    switch(stan)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->przycisk_nie.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.448,WY1*0.247);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.448,WY1*0.356);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.580,WY1*0.356);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.580,WY1*0.237);

        glEnd();

    break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->tryb_przetrfania.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.282,WY1*0.373);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.282,WY1*0.480);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.722,WY1*0.480);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.722,WY1*0.373);

        glEnd();
        break;
        case 3 : glBindTexture(GL_TEXTURE_2D, T->tryb_kampani.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.282,WY1*0.509);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.282,WY1*0.616);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.722,WY1*0.616);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.722,WY1*0.509);
        glEnd();
        break;
    }


glDisable(GL_BLEND);
}

void MenuPoziom::rysuje(int poziom, Tekstury*T)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

     glBindTexture(GL_TEXTURE_2D, T->menu_poziom.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.1,WY1*0.2);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.1,WY1*0.8);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.9,WY1*0.8);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.9,WY1*0.2);

        glEnd();
    switch(poziom)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->poziom_latwy.ID);
    glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.159,WY1*0.362);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.159,WY1*0.492);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.379,WY1*0.492);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.379,WY1*0.362);

        glEnd();

    break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->poziom_normalny.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.402,WY1*0.363);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.402,WY1*0.493);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.622,WY1*0.493);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.622,WY1*0.363);

        glEnd();
        break;
        case 3 : glBindTexture(GL_TEXTURE_2D, T->poziom_trudny.ID);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.650,WY1*0.362);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.650,WY1*0.492);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.870,WY1*0.492);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.870,WY1*0.362);

        glEnd();
        break;
}

void Gra::rysuje()
{

}

void Koniec::rysuje(int stan, Tekstury*T)
{
    switch(stan)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->koniec_tak.ID);break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->koniec_nie.ID);break;


    }
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.3,WY*0.2);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.7,WY*0.2);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.7,WY*0.8);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.3,WY*0.8);

        glEnd();
        glDisable(GL_BLEND);
}

void Wyjscie::rysuje(int stan, Tekstury*T)
{
    switch(stan)
    {
    case 1 : glBindTexture(GL_TEXTURE_2D, T->wyjscie_tak.ID);break;
        case 2 : glBindTexture(GL_TEXTURE_2D, T->wyjscie_nie.ID);break;


    }
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);glVertex2i(WX*0.2,WY*0.2);
            glTexCoord2f(1.0f,0.0f);glVertex2i(WX*0.8,WY*0.2);
            glTexCoord2f(1.0f,1.0f);glVertex2i(WX*0.8,WY*0.8);
            glTexCoord2f(0.0f,1.0f);glVertex2i(WX*0.2,WY*0.8);

        glEnd();
        glDisable(GL_BLEND);
}
