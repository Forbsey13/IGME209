#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Adventurer {
private:
	string name;
public:
	Adventurer(string _name) {
		name = _name;
	}
	void ReceiveAQuest(string quest) {
		cout << name << " receives a quest: " << quest << endl;
	}
};

class Guild {
private:
	vector<Adventurer*> adventurer_array;
public:
	void Register(Adventurer* adventurer) {
		if (find(adventurer_array.begin(), adventurer_array.end(), adventurer) == adventurer_array.end()) // check adventurer not in the array
			adventurer_array.push_back(adventurer);
	}
	void DeRegister(Adventurer* adventurer) {
		auto iterator = find(adventurer_array.begin(), adventurer_array.end(), adventurer); // use iterator to remove an element in vector
		if (iterator != adventurer_array.end())
			adventurer_array.erase(iterator);
	}
	void AddNewQuest(string quest) {
		cout << "Guild published a new quest" << endl;
		for (int i = 0; i < adventurer_array.size(); i++) {
			adventurer_array[i]->ReceiveAQuest(quest);
		}
	}
};

int main() {
	Adventurer* a1 = new Adventurer("A");
	Adventurer* a2 = new Adventurer("B");
	Adventurer* a3 = new Adventurer("C");

	Guild guild = Guild();

	guild.Register(a1);
	guild.Register(a2);
	guild.Register(a3);

	guild.AddNewQuest("quest 1");

	Adventurer* a4 = new Adventurer("D");
	guild.Register(a4);
	guild.DeRegister(a3);

	guild.AddNewQuest("quest 2");

	return 0;
}