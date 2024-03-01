#include <stdio.h>
#include <iostream>

using namespace std;

class Color {
public:
	virtual void print() = 0;
};

class Red : public Color {
public:
	void print() override {
		cout << "red";
	}
};

class Green : public Color {
public:
	void print() override {
		cout << "green";
	}
};

class Monster {
protected:
	Color* color_ptr;
	string name;
public:
	Monster(Color* _color_ptr) {
		color_ptr = _color_ptr;
	}
	void print() {
		color_ptr->print();
		cout << " " << name << endl;
	}
};

class Goblin : public Monster {
public:
	Goblin(Color* _color_ptr) :Monster(_color_ptr) {
		name = "goblin";
	};
};

class Troll : public Monster {
public:
	Troll(Color* _color_ptr) :Monster(_color_ptr) {
		name = "goblin";
	};
};

class Dragon : public Monster {
public:
	Dragon(Color* _color_ptr) :Monster(_color_ptr) {
		name = "goblin";
	};
};

int main() {
	Monster* a = new Goblin(new Green());
	Monster* b = new Goblin(new Red());
	Monster* c = new Dragon(new Red());

	a->print();
	b->print();
	c->print();
}