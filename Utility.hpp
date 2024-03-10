#ifndef __UTILITY
#define __UTILITY
#include <SFML/Graphics.hpp>


/// \param os  Left operand
/// \param c   Right operand

/// \return output stream

std::ostream& operator<<(std::ostream& os, const sf::Color& c)
{
	os << "r:" << c.r << " g:" << c.g << " b:" << c.b << " a:" << c.a;
	return os;
}
#endif 