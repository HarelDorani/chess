#include "Piece.h"
#include "Board.h"

Piece::Piece() {

}

Piece::Piece(const std::string name, const std::string color, const Position position) {
	this->_name = name;
	this->_color = color;
	this->_position = position;
}

Piece::~Piece() {
	this->_color.clear();
	this->_name.clear();
}

void Piece::move(Position newPosition) 
{
	this->_position = newPosition;
}

// Getters
Position Piece::getPosition() const {
	return this->_position;;
}

std::string Piece::getName() const {
	return this->_name;
}

std::string Piece::getColor() const {
	return this->_color;
}

// Setters
void Piece::setName(std::string name)
{
	this->_name = name;
}

void Piece::setColor(std::string color)
{
	this->_color = color;
}

void Piece::setPosition(Position position)
{
	this->_position = position;
}
