#ifndef __VISUAL
#define __VISUAL
#include <SFML/Graphics.hpp>
#include "Mandelbrot_set.h"

#define WIDTH 1920
#define HEIGHT 1080

void initWindow();
/// \return List of initialized vertices

sf::Vertex* initVertices();

#endif // __VISUAL
