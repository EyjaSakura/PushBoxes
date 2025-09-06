#pragma once

enum Direction { UP, RIGHT, DOWN, LEFT };

struct Position {
	int x, y;

	bool operator==(const Position& other)const {
		return x == other.x && y == other.y;
	}

	Position move(Direction dir) const {
		switch (dir) {
		case UP:	return { x - 1,y };
		case RIGHT:	return { x,y + 1 };
		case DOWN:	return { x + 1,y };
		case LEFT:	return { x,y - 1 };
		default:	return *this;
		}
	}
};