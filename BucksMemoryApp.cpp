#include <iostream>
using namespace std;
class NPC {
public:
	int id;
	NPC() {}
	NPC(int id) :id(id) {}
};
class AIManager {
private:
	NPC** npcs;
	int count;
	int size;
public:
	AIManager(int size) :size(size) {
		npcs = new NPC * [size];
		count = 0;
	}
	int Add(int id) {
		NPC* temp = new NPC(id);
		for (int n = 0; n < count; n++)
			if (npcs[n]->id == id) return 0;
		npcs[count++] = temp;
		return id;
	}
	void Display() {
		for (int n = 0; n < count; n++)
			cout << "NPC ID: " << npcs[n]->id << endl;
	}
	void Delete() {
		delete[] npcs;
		npcs = 0;
	}
};
int main() {
	AIManager* ai = new AIManager(10);
	ai->Add(1);
	ai->Add(2);
	ai->Add(3);
	ai->Display();
	ai->Delete();
	return 0;
};