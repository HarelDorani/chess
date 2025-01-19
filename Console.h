#include <iostream>
#include "Position.h"
#include <string>

Position strToPosition(std::string position)
{
	Position toReturn(position[0], position[1]);
	return toReturn;
}