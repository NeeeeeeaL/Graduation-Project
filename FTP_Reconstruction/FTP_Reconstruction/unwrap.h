#pragma once

#include "main.h"

#define BYTE unsigned char

#define swap(x,y) {EDGE t; t=x; x=y; y=t;}
#define order(x,y) if (x.reliab > y.reliab) swap(x,y)
#define o2(x,y) order(x,y)
#define o3(x,y,z) o2(x,y); o2(x,z); o2(y,z)

typedef enum { yes, no } yes_no;

using namespace cv;
using namespace std;


//pixel information
struct PIXEL
{
	//int x;					//x coordinate of the pixel
	//int y;					//y coordinate
	int increment;			//No. of 2*pi to add to the pixel to unwrap it
	int number_of_pixels_in_group;	//No. of pixels in the pixel group
	float value;			//value of the pixel
	float reliability;
	int group;				//group No.
	int new_group;
	struct PIXEL *head;		//pointer to the first pixel in the group in the linked list
	struct PIXEL *last;		//pointer to the last pixel in the group
	struct PIXEL *next;		//pointer to the next pixel in the group
};

//the EDGE is the line that connects two pixels.
//if we have S PIXELs, then we have S horizental edges and S vertical edges
struct EDGE
{
	float reliab;			//reliabilty of the edge and it depends on the two pixels
	PIXEL *pointer_1;		//pointer to the first pixel
	PIXEL *pointer_2;		//pointer to the second pixel
	int increment;			//No. of 2*pi to add to one of the pixels to unwrap it with respect to the second 
};

void  Mix(EDGE *Pointer1, int *index1, int *index2, int size);
void  sort(EDGE *Pointer, int *index, int size);
void  quick_sort(EDGE *Pointer, int size);
yes_no find_pivot(EDGE *left, EDGE *right, float *pivot_ptr);
EDGE *partition(EDGE *left, EDGE *right, float pivot);
void quicker_sort(EDGE *left, EDGE *right);
void  initialisePIXELs(float *WrappedImage, PIXEL *pixel, int image_width, int image_height);
float wrap(float pixel_value);
int find_wrap(float pixelL_value, float pixelR_value);
void calculate_reliability(float *wrappedImage, PIXEL *pixel, int image_width, int image_height);
void  horizentalEDGEs(PIXEL *pixel, EDGE *edge, int image_width, int image_height);
void  verticalEDGEs(PIXEL *pixel, EDGE *edge, int image_width, int image_height);
void  gatherPIXELs(EDGE *edge, int image_width, int image_height);
void  unwrapImage(PIXEL *pixel, int image_width, int image_height);
void  returnImage(PIXEL *pixel, float *unwrappedImage, int image_width, int image_height);
void  unwrap(const Mat & src, Mat & dst);
