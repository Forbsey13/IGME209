#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GameMap {
private:
	int data[5][5] = {
		{0, 0, 0, 2, 2},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 1, 1},
		{0, 1, 1, 1, 0},
		{0, 0, 2, 0, 0}
	};
private:
	static GameMap* s_instance;
public:
	GameMap() {
		// s_instance = this; // another way to implement Singleton
	}
	string GetDataType(int x, int y) {
		switch (data[x][y])
		{
		case 0:
			return "Plain";
			break;
		case 1:
			return "Mountain";
			break;
		default:
			return "Forest";
			break;
		}
		return "";
	}

	static GameMap* Instance() {
		if (s_instance == NULL) {
			s_instance = new GameMap();
		}
		return s_instance;
	}
};

GameMap* GameMap::s_instance = 0;
// static variable can only be initialized outside the class definition before C++ 17
// after C++ 17, A static data member may be declared inline. 
// An inline static data member can be defined in the class definition and may specify a default member initializer. 
// It does not need an out-of-class definition

class Character {
private:
	int position_x;
	int position_y;
public:
	Character(int x, int y) {
		position_x = x;
		position_y = y;
	}
	void UpdateCharacter() {
		ReadMap();
	}
private:
	void ReadMap() {
		cout << "The terrain type is " << GameMap::Instance()->GetDataType(position_x, position_y) << endl;
	}

};

int main() {
	Character c1 = Character(1, 3);
	Character c2 = Character(2, 1);
	Character c3 = Character(4, 2);

	c1.UpdateCharacter();
	c2.UpdateCharacter();
	c3.UpdateCharacter();

	return 0;
}