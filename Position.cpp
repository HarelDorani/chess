#include "Position.h"

Position::Position() {
	
}

Position::Position(const char x, const char y) {
	this->_x = x;
	this->_y = y;
}

Position::~Position() {
	
}

// Returns true if the position is the same
bool Position::operator==(const Position other) const {
	if (other.getX() == this->_x && other.getY() == this->_y) { // Checking x == x and y == y
		return true;
	}
	return false;
}

// Returns true if the position arent the same
bool Position::operator!=(const Position other) const {
	if (other.getX() != this->_x && other.getY() != this->_y) { // Checking x != x and y != y
		return true;
	}
	return false;
}

Position& Position::operator=(const Position& other) {
	if (this == &other) {
		return *this;
	}
	this->_x = other.getX();
	this->_y = other.getY();
	return *this;
}

bool Position::inBoard() const{
	if (this->_x >= 'a' && this->_x <= 'h' && this->_y >= '1' && this->_y <= '8') {
		return true;
	}
	return false;
}

// Getters
char Position::getX() const {
	return this->_x;
}
char Position::getY() const {
	return this->_y;
}
