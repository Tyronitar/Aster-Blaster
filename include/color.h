#ifndef __COLOR_H__
#define __COLOR_H__

#include <SDL2/SDL_render.h>

/**
 * A color to display on the screen.
 * The color is represented by its red, green, and blue components.
 * Each component must be between 0 (black) and 1 (white).
 */
typedef struct rgb_color {
    float r;
    float g;
    float b;
    float a;
} rgb_color_t;

typedef enum render_type {
    COLOR,
    TEX
} render_type_e;

typedef struct render_data_texture {
    SDL_Texture *tex;
    int dx;
    int dy;
    int w;
    int h;
} render_data_texture_t;

typedef union render_data {
    render_data_texture_t texture;
    rgb_color_t color;
} render_data_t;

typedef struct render_info {
    render_type_e type;
    render_data_t data;
} render_info_t;

/**
 * The black color, i.e. (0, 0, 0).
 */
extern const rgb_color_t COLOR_BLACK;

/**
 * The white color, i.e. (1, 1, 1).
 */
extern const rgb_color_t COLOR_WHITE;

// Create render information using a color
render_info_t render_color(rgb_color_t color);

// Create render information from SDL_Texture
render_info_t render_texture(SDL_Texture *tex, int w, int h);

/**
 * Returns a rgb_color_t value made from the given arguments.
 * 
 * @param r the red component of the color_t
 * @param g the green component of the color_t
 * @param b the blue component of the color_t
 * @return an rgb_color_t value with the given components
 */
rgb_color_t rgb(float r, float g, float b);

/**
 * Returns a rgb_color_t value made from the given HSV arguments.
 * This will convert the HSV to RGB.
 * 
 * @param h the hue component of the color_t
 * @param s the saturation component of the color_t
 * @param v the value component of the color_t
 * @return an rgb_color_t value with the given components
 */
rgb_color_t hsv(float h, float s, float v);

#endif // #ifndef __COLOR_H__
