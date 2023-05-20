#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"

void flood(image_t *img, int x, int y, pixel_t *target_color) {
    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;
    int wi = img->w;
    int hi = img->h;
    int rot = img->img[(wi*y)+x].r;
    int grun = img->img[(wi*y)+x].g;
    int blau = img->img[(wi*y)+x].b;
    fill(img,x,y,target_color,wi,hi,rot,grun,blau);   

}
void fill(image_t *phill, int x1, int y1, pixel_t *target_color1,int wii,int hii,int rr,int gg,int bb)
{
    if (x1 < 0 || y1 < 0 || x1 >= wii || y1 >= hii) return;
    if((phill->img[(wii*y1)+x1].r == rr) && (phill->img[(wii*y1)+x1].g == gg) && (phill->img[(wii*y1)+x1].b == bb))
    {
        
        phill->img[(wii*y1)+x1].r = target_color1->r;
        phill->img[(wii*y1)+x1].g = target_color1->g;
        phill->img[(wii*y1)+x1].b = target_color1->b;
        fill(phill, x1 + 1, y1, target_color1, wii, hii,rr,gg,bb);
        fill(phill, x1 - 1, y1, target_color1, wii, hii,rr,gg,bb);
        fill(phill, x1, y1 + 1, target_color1, wii, hii,rr,gg,bb);
        fill(phill, x1, y1 - 1, target_color1, wii, hii,rr,gg,bb);
    }
    return;
}