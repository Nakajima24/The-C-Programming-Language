//
//  main.c
//  Chapter 6. Structures
//
//  Created by Brian Chen on 21/11/2023.
//
/*
 Stack Manipulations without Function
 
 Author: Michael Chen, 2018.
 License: MIT.
 */
/* Forward declaration. */
#include <stddef.h>
#include <stdio.h>

typedef struct rgb_t rgb_t;

struct rgb_t {
    unsigned short r;
    unsigned short g;
    unsigned short b;
};

typedef union color_data_t color_data_t;

union color_data_t {
    char *description;
    rgb_t rgb;
};

typedef struct color_t color_t;

struct color_t {
    unsigned short type;
    color_data_t data;
};

int main(void)
{
    color_t red = {
        .type = 1,
        .data.description = "red"
    };

    color_t orange = {
        .type = 1,
        .data.description = "orange"
    };

    color_t beige = {
        .type = 2,
        .data.rgb = { 245, 245, 220 }
    };

    color_t colors[] = { red, orange, beige };

    for (size_t i = 0; i < 3; i++) {
        if (colors[i].type == 1) {
            printf("%s\n", colors[i].data.description);
        } else {
            printf("(%u, %u, %u)\n",
                colors[i].data.rgb.r,
                colors[i].data.rgb.g,
                colors[i].data.rgb.b);
        }
    }

    return 0;
}
