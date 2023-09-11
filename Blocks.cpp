#include "Block.h"
#include "Position.h"

class Lshape : public Block {
public:
	Lshape() {
		id = 1;
		cells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}
};


class Jshape : public Block {
public:
	Jshape() {
		id = 2;
		cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(0, 2) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[3] = { Position(2, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}
};

class Ishape : public Block {
public:
	Ishape() {
		id = 3;
		cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };
		cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
		move(-1, 3);
	}
};

class Oshape : public Block {
public:
	Oshape() {
		id = 4;
		cells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		cells[2] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		cells[3] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		move(0, 4);
	}
};


class Sshape : public Block {
public:
	Sshape() {
		id = 5;
		cells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
		cells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
		cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
		move(0, 3);
	}
};

class Tshape : public Block {
public:
	Tshape() {
		id = 6;
		cells[0] = { Position(0,1), Position(1,2), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,1), Position(1,2), Position(1,0), Position(2,1) };
		cells[3] = { Position(1,0), Position(0,1), Position(1,1), Position(2,1) };
		move(0, 3);
	}
};

class Zshape : public Block {
public:
	Zshape() {
		id = 7;
		cells[0] = { Position(0,0), Position(1,2), Position(0,1), Position(1,1) };
		cells[1] = { Position(0,2), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,1), Position(2,2), Position(1,0), Position(2,1) };
		cells[3] = { Position(1,0), Position(0,1), Position(1,1), Position(2,0) };
		move(0, 3);
	}
};