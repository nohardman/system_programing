// Assignment 2 - Efficient C Programming
// System Programming, DGIST, Prof. Yeseong Kim
//
// YOU WILL TURN IN THIS FILE.
// Read the provided instruction carefully.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmplib.h"
#include "hw2.h"

// This implementation is simply copied from "main.c".
// Your job is to modify and optimize it for better performance!


void filter_optimized(void* args[]) {
    unsigned int width = *(unsigned int*)args[0];
    unsigned int height = *(unsigned int*)args[1];
    Pixel* input = args[2];
    Pixel* output = args[3];
    float* filter = args[4];
   
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
              	double r = 0;
    	      	double g = 0;
              	double b = 0;

    		
	     	int filterIndex;

    		for (int dy = -1; dy <= 1; ++dy) {
        		int yIndex = y + dy;
        		if (yIndex < 0 || yIndex >= height) continue;

        		for (int dx = -1; dx <= 1; ++dx) {
        		    	int xIndex = x + dx;
            			if (xIndex < 0 || xIndex >= width) continue;

            			filterIndex = (dx + 1) + (dy + 1) * 3;
            			Pixel p = input[xIndex + yIndex * width];
            			r += p.r * filter[filterIndex];
            			g += p.g * filter[filterIndex];
            			b += p.b * filter[filterIndex];
        		}
    		}

    		r = r < 0 ? 0 : (r > 255 ? 255 : r);
    		g = g < 0 ? 0 : (g > 255 ? 255 : g);
    		b = b < 0 ? 0 : (b > 255 ? 255 : b);

    		Pixel p;
    		p.r = (unsigned char)r;
    		p.g = (unsigned char)g;
    		p.b = (unsigned char)b;
		output[x + y * width] = p;
	}
    }
    		
}
