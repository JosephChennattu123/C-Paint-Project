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
            mir_whore[(nc*i)+j].r=img->img[(column*(j))+(column-i-1)].r;
            mir_whore[(nc*i)+j].g=img->img[(column*(j))+(column-i-1)].g;
            mir_whore[(nc*i)+j].b=img->img[(column*(j))+(column-i-1)].b;
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
            mir_whore[(nc*i)+j].r=img->img[(column*(row-j-1))+(i)].r;
            mir_whore[(nc*i)+j].g=img->img[(column*(row-j-1))+(i)].g;
            mir_whore[(nc*i)+j].b=img->img[(column*(row-j-1))+(i)].b;
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
            mir_whore[(column*i)+(j)].r=img->img[(column*i)+(column-1-j)].r;
            mir_whore[(column*i)+(j)].g=img->img[(column*i)+(column-1-j)].g;
            mir_whore[(column*i)+(j)].b=img->img[(column*i)+(column-1-j)].b;
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
            mir_whorer[(column*(row-i-1))+(j)].r=img->img[(column*i)+j].r;
            mir_whorer[(column*(row-i-1))+(j)].g=img->img[(column*i)+j].g;
            mir_whorer[(column*(row-i-1))+(j)].b=img->img[(column*i)+j].b;
        }
    }
    free(img->img);
    img->img = mir_whorer;

}

void resize(image_t *img, int new_width, int new_height) {
    
  int ow = img->w;
  int oh = img->h;
  pixel_t *resizer = malloc(new_width*new_height*sizeof(pixel_t));
  for(int i=0;i<new_height;i++)
  {
    for(int j=0;j<new_width;j++)
    {
        if(i<oh && j<ow)
        {
            resizer[(new_width*i)+j].r= img->img[(ow*i)+j].r;
            resizer[(new_width*i)+j].g= img->img[(ow*i)+j].g;
            resizer[(new_width*i)+j].b= img->img[(ow*i)+j].b;
        }
        if(i>=oh || j>=ow)
        {
            resizer[(new_width*i)+j].r=0;
            resizer[(new_width*i)+j].g=0;
            resizer[(new_width*i)+j].b=0;
        }
    }
  }
  /*  //solving for each individual case
  //new_width<ow&&new_height<oh
  if(new_width<=ow && new_height<=oh)
  {
  for(int i =0;i<new_height;i++)
  {
    for(int j=0;j<new_width;j++)
    {
            resizer[(new_width*i)+j].r= img->img[(new_width*i)+j].r;
            resizer[(new_width*i)+j].g= img->img[(new_width*i)+j].g;
            resizer[(new_width*i)+j].b= img->img[(new_width*i)+j].b;
        }
  }
  }
  //new_width>=ow &&newheight<=oh
  if(new_width>=ow && new_height<=oh)
  {
  for(int i =0;i<new_height;i++)
  {
    for(int j=0;j<new_width;j++)
    {       
            if(j<ow)
            {
            resizer[(new_height*i)+j].r= img->img[(new_height*i)+j].r;
            resizer[(new_height*i)+j].g= img->img[(new_height*i)+j].g;
            resizer[(new_height*i)+j].b= img->img[(new_height*i)+j].b;
            }
            if(j>=ow)
            {
                resizer[(new_height*i)+j].r= 0;
                resizer[(new_height*i)+j].g= 0;
                resizer[(new_height*i)+j].b= 0;
            }
        }
  }
  }
  //new_height>=oh && new_width<=ow
  if(new_height>=oh && new_width<=ow)
  {
    for(int i =0;i<new_height;i++)
  {
    for(int j=0;j<new_width;j++)
    {       
            if(i<oh)
            {
            resizer[(oh*i)+j].r= img->img[(oh*i)+j].r;
            resizer[(oh*i)+j].g= img->img[(oh*i)+j].g;
            resizer[(oh*i)+j].b= img->img[(oh*i)+j].b;
            }
            if(i>=ow)
            {
                resizer[(new_height*i)+j].r= 0;
                resizer[(new_height*i)+j].g= 0;
                resizer[(new_height*i)+j].b= 0;
            }
        }
  }
  }
  */

  img->h=new_height;
  img->w=new_width;
  free(img->img);
  img->img = resizer;
  
  }
