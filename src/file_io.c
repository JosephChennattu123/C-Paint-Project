#include "file_io.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"

int image_read(image_t *img, FILE *fin) {
    int width,height;
    int i = fscanf(fin,"P3 %d %d 255",&width,&height);
    if(i!=2)
    {
    return -1;
    }

    if(width<0 && height<0)
    {
        return -1;
    }

    pixel_t *pixelarr = malloc(width*height*sizeof(pixel_t));
    if(pixelarr== NULL)
    {
    return -1;
    }

    for(int q= 0;q<(width*height);q++)
    {
        int red,green,blue;
        int n = fscanf(fin,"%d %d %d",&red,&green,&blue);
        if((n!=3)||(red<0 || red>255)||(green<0 || green>255)||(blue<0 || blue>255)){
        free (pixelarr);
        return -1;
        }
        pixelarr[q].r= red;
        pixelarr[q].g= green;
        pixelarr[q].b= blue;
    }
    img->w= width;
    img->h=height;
    img->img = pixelarr;
    return 0;
}

void image_write(const image_t *img, FILE *fout) {
   fprintf(fout,"P3 %d %d 255 ", img->w, img->h);
   for(int i =0; i< img->w * img->h; i++){
    fprintf(fout,"%d %d %d ", img->img[i].r, img->img[i].g, img->img[i].b);
    }
    
}
void image_free(image_t *img) {
    if (img->img != NULL) {
        free(img->img);
    }
    img->w = img->h = 0;
    img->img = NULL;
}
