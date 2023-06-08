#include "tekstury.h"


int Tekstura::laduj_teksture(char *name)
{
 int i;
 png_structp png_ptr;
    png_infop info_ptr;
    unsigned int sig_read = 0;
    int color_type, interlace_type;
    FILE *fp;

    if ((fp = fopen(name, "rb")) == NULL)
        return FALSE;

    /* Create and initialize the png_struct
     * with the desired error handler
     * functions.  If you want to use the
     * default stderr and longjump method,
     * you can supply NULL for the last
     * three parameters.  We also supply the
     * the compiler header file version, so
     * that we know if the application
     * was compiled with a compatible version
     * of the library.  REQUIRED
     */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
                                     NULL, NULL, NULL);

    if (png_ptr == NULL) {
        fclose(fp);
        return FALSE;
    }

    /* Allocate/initialize the memory
     * for image information.  REQUIRED. */
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        fclose(fp);
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return FALSE;
    }

    /* Set error handling if you are
     * using the setjmp/longjmp method
     * (this is the normal method of
     * doing things with libpng).
     * REQUIRED unless you  set up
     * your own error handlers in
     * the png_create_read_struct()
     * earlier.
     */
    if (setjmp(png_jmpbuf(png_ptr))) {
        /* Free all of the memory associated
         * with the png_ptr and info_ptr */
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        fclose(fp);
        /* If we get here, we had a
         * problem reading the file */
        return FALSE;
    }

    /* Set up the output control if
     * you are using standard C streams */
    png_init_io(png_ptr, fp);

    /* If we have already
     * read some of the signature */
    png_set_sig_bytes(png_ptr, sig_read);

    /*
     * If you have enough memory to read
     * in the entire image at once, and
     * you need to specify only
     * transforms that can be controlled
     * with one of the PNG_TRANSFORM_*
     * bits (this presently excludes
     * dithering, filling, setting
     * background, and doing gamma
     * adjustment), then you can read the
     * entire image (including pixels)
     * into the info structure with this
     * call
     *
     * PNG_TRANSFORM_STRIP_16 |
     * PNG_TRANSFORM_PACKING  forces 8 bit
     * PNG_TRANSFORM_EXPAND forces to
     *  expand a palette into RGB
     */
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);

    png_uint_32 width, height;
    int bit_depth;
    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
                 &interlace_type, NULL, NULL);

    this->alfa = (color_type == PNG_COLOR_TYPE_RGBA);
    this->szerokosc = width;
    this->wysokosc = height;

    unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    this->obraz = (unsigned char*) malloc(row_bytes * this->wysokosc);

    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);

    for (i = 0; i < this->wysokosc; i++) {
        // note that png is ordered top to
        // bottom, but OpenGL expect it bottom to top
        // so the order or swapped
        memcpy(this->obraz+(row_bytes * (this->wysokosc-1-i)), row_pointers[i], row_bytes);
    }

    /* Clean up after the read,
     * and free any memory allocated */
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    /* Close the file */
    fclose(fp);

    /* That's it */

    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glGenTextures(1,&this->ID);
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->alfa ? 4 : 3, this->szerokosc,
                 this->wysokosc, 0, this->alfa ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE,
                 this->obraz);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    return TRUE;
}
void Tekstury::laduj_tekstury()
{

        tlo.laduj_teksture("img\\tlo_male.png");
    leb.laduj_teksture("img\\glowa.png");
    czlon.laduj_teksture("img\\czlon.png");
    ogon.laduj_teksture("img\\ogon.png");
    menu_poziom.laduj_teksture("img\\menu_poziom.png");
    poziom_latwy.laduj_teksture("img\\poziom_latwy.png");
    poziom_normalny.laduj_teksture("img\\poziom_normalny.png");
    poziom_trudny.laduj_teksture("img\\poziom_trudny.png");
    napis_latwy.laduj_teksture("img\\napis_latwy.png");
    napis_normalny.laduj_teksture("img\\napis_normalny.png");
    napis_trudny.laduj_teksture("img\\napis_trudny.png");
    koniec_tak.laduj_teksture("img\\koniec_tak.png");
    koniec_nie.laduj_teksture("img\\koniec_nie.png");
    sfera_neutralna.laduj_teksture("img\\sfera_neutralna.png");
    sfera_zla.laduj_teksture("img\\sfera_zla.png");
    czacha.laduj_teksture("img\\czacha.png");
    sfera_dobra.laduj_teksture("img\\sfera_dobra.png");
    czlon_neutralny.laduj_teksture("img\\czlon_neutralny.png");
    czlon_zly.laduj_teksture("img\\czlon_zly.png");
    czlon_dobry.laduj_teksture("img\\czlon_dobry.png");
    pasek.laduj_teksture("img\\pasek.png");
    dodatek.laduj_teksture("img\\dodatek.png");
    cyfry.laduj_teksture("img\\cyfry.png");
    menu_tryb.laduj_teksture("img\\menu_tryb.png");
    przycisk_nie.laduj_teksture("img\\przycisk_nie.png");
    tryb_kampani.laduj_teksture("img\\tryb_kampani.png");
    tryb_przetrfania.laduj_teksture("img\\tryb_przetrfania.png");
    wyjscie_tak.laduj_teksture("img\\wyjscie_tak.png");
    wyjscie_nie.laduj_teksture("img\\wyjscie_nie.png");
}

