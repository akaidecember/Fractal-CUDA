#ifndef __MANDELBROT_SET
#define __MANDELBROT_SET
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <chrono>
#include "kernel.cuh"


namespace ms {
	class Mandelbrot_set
	{
	private:
#ifdef __STATIC_MAX_ITER
		struct ColorData { int r, g, b; };
		ColorData palette[100] = { {0, 0, 0},
								{255, 15, 0}, {255, 30, 0}, {255, 45, 0},
								{255, 61, 0}, {255, 76, 0}, {255, 91, 0},
								{255, 107, 0}, {255, 122, 0}, {255, 137, 0},
								{255, 153, 0}, {255, 168, 0}, {255, 183, 0},
								{255, 198, 0}, {255, 214, 0}, {255, 229, 0},
								{255, 244, 0}, {249, 255, 5}, {234, 255, 20},
								{219, 255, 35}, {204, 255, 50}, {188, 255, 66},
								{173, 255, 81}, {158, 255, 96}, {142, 255, 112},
								{127, 255, 127}, {112, 255, 142}, {96, 255, 158},
								{81, 255, 173}, {66, 255, 188}, {50, 255, 204},
								{35, 255, 219}, {20, 255, 234}, {5, 255, 249},
								{0, 255, 10}, {0, 255, 25}, {0, 255, 40},
								{0, 255, 56}, {0, 255, 71}, {0, 255, 86},
								{0, 255, 101}, {0, 255, 117}, {0, 255, 132},
								{0, 255, 147}, {0, 255, 163}, {0, 255, 178},
								{0, 255, 193}, {0, 255, 209}, {0, 255, 224},
								{0, 255, 239}, {0, 255, 255}, {0, 239, 255},
								{0, 224, 255}, {0, 209, 255}, {0, 193, 255},
								{0, 178, 255}, {0, 163, 255}, {0, 147, 255},
								{0, 132, 255}, {0, 117, 255}, {0, 101, 255},
								{0, 86, 255}, {0, 71, 255}, {0, 56, 255},
								{0, 40, 255}, {0, 25, 255}, {0, 10, 255},
								{5, 0, 255}, {20, 0, 255}, {35, 0, 255},
								{51, 0, 255}, {66, 0, 255}, {81, 0, 255},
								{96, 0, 255}, {112, 0, 255}, {127, 0, 255},
								{142, 0, 255}, {158, 0, 255}, {173, 0, 255},
								{188, 0, 255}, {203, 0, 255}, {219, 0, 255},
								{234, 0, 255}, {249, 0, 255}, {255, 0, 244},
								{255, 0, 229}, {255, 0, 214}, {255, 0, 198},
								{255, 0, 183}, {255, 0, 168}, {255, 0, 152},
								{255, 0, 137}, {255, 0, 122}, {255, 0, 107},
								{255, 0, 91}, {255, 0, 76}, {255, 0, 61},
								{255, 0, 45}, {255, 0, 30}, {255, 0, 15},
		};
#endif
		int width;
		int maxIter = 100;
		double startX = 0.0;		
		double startY = 0.0;
		double zoom = 1;
		bool isHUDshown = true;
		
		sf::RenderWindow* window;
		sf::Vertex* vertices;
		
		/// \param h   Hue
		/// \param s   Saturation
		/// \param v   Value
		/// \return equivalent rgb color
		///
		
		sf::Color hsv2rgb(double h, double s, double v);
		
		/// \param h   Hue

		/// \return equivalent rgb color
		
		sf::Color hsv2rgb_fast(double h);
		void showHUD();
	public:
		/// \param window      Render window
		/// \param widht       Pixel width of the screen
		/// \param height      Pixel height of the screen
		/// \param vertices    Array of verices that represent each pixel on the screen   
		
		Mandelbrot_set(sf::RenderWindow* window, int widht, int height, sf::Vertex* vertices);

		void show();

		/// \param modifierX  Value to add to startX
		/// \param modifierY  Value to add to startY

		
		void setPosition(double modifierX, double modfierY);
		
		/// \param modifier  Value to add to startX
		
		void setStartX(double modifier);
		
		/// \param modifier  Value to add to startY
		
		void setStartY(double modifier);
		
		/// \param modifier  Coefficient to apply to zoom
		
		void setZoom(double modifier);
		
		/// \param modifier  Value to add to maxIter
		
		void setIteration(int modifier);

		void invertHUD();
		
		void reset();
	};
}
#endif 

