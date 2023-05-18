#include "image_edit.h"

#include <stdlib.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) {
    NOT_IMPLEMENTED;
    UNUSED(img);
}

void rotate_clockwise(image_t *img) {
    NOT_IMPLEMENTED;
    UNUSED(img);
}

void mirror_horizontal(image_t *img) {
    int column = img->w;
    int row = img->h;
    pixel_t *mir_whore = malloc(row*column*sizeof(pixel_t));
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mir_whore[((row*i)+(column-1-j))].r=img->img[(row*i)+j].r;
            mir_whore[(row*i)+(column-1-j)].g=img->img[(row*i)+j].g;
            mir_whore[(row*i)+(column-1-j)].b=img->img[(row*i)+j].b;
        }
    }
    free(img->img);
    img->img = mir_whore;

    }

void mirror_vertical(image_t *img) {
    NOT_IMPLEMENTED;
    UNUSED(img);
}

void resize(image_t *img, int new_width, int new_height) {
    NOT_IMPLEMENTED;
    UNUSED(img);
    UNUSED(new_width);
    UNUSED(new_height);
}
