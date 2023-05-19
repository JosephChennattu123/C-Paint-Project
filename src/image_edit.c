#include "image_edit.h"

#include <stdlib.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) {
    int column = img->w;
    int row = img->h;
    int nc = row;
    int nr = column;
    pixel_t *mir_whore = malloc(row*column*sizeof(pixel_t));
    for(int i = 0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            mir_whore[(nr*i)+j].r=img->img[(row*(j))+(column-i-1)].r;
            mir_whore[(nr*i)+j].g=img->img[(row*(j))+(column-i-1)].g;
            mir_whore[(nr*i)+j].b=img->img[(row*(j))+(column-i-1)].b;
        }
    }
    free(img->img);
    img->h = nc;
    img->w = nr;
    img->img = mir_whore;
   }

void rotate_clockwise(image_t *img) {
    int column = img->w;
    int row = img->h;
    int nc = row;
    int nr = column;
    pixel_t *mir_whore = malloc(row*column*sizeof(pixel_t));
    for(int i = 0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            mir_whore[(nr*i)+j].r=img->img[(row*(row-j-1))+(i)].r;
            mir_whore[(nr*i)+j].g=img->img[(row*(row-j-1))+(i)].g;
            mir_whore[(nr*i)+j].b=img->img[(row*(row-j-1))+(i)].b;
        }
    }
    free(img->img);
    img->h = nc;
    img->w = nr;
    img->img = mir_whore;
}

void mirror_horizontal(image_t *img) {
    int column = img->w;
    int row = img->h;
    pixel_t *mir_whore = malloc(row*column*sizeof(pixel_t));
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mir_whore[((row*i)+(j))].r=img->img[(row*i)+(column-1-j)].r;
            mir_whore[(row*i)+(j)].g=img->img[(row*i)+(column-1-j)].g;
            mir_whore[(row*i)+(j)].b=img->img[(row*i)+(column-1-j)].b;
        }
    }
    free(img->img);
    img->img = mir_whore;

    }

void mirror_vertical(image_t *img) {
     int column = img->w;
    int row = img->h;
    pixel_t *mir_whorer = malloc(row*column*sizeof(pixel_t));
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mir_whorer[(row*(row-i-1))+(j)].r=img->img[(row*i)+j].r;
            mir_whorer[(row*(row-i-1))+(j)].g=img->img[(row*i)+j].g;
            mir_whorer[(row*(row-i-1))+(j)].b=img->img[(row*i)+j].b;
        }
    }
    free(img->img);
    img->img = mir_whorer;

}

void resize(image_t *img, int new_width, int new_height) {
    NOT_IMPLEMENTED;
    UNUSED(img);
    UNUSED(new_width);
    UNUSED(new_height);
}
