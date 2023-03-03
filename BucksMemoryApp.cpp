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
	NPC** npcs = NULL;
	int count;
	int size;
public:
	AIManager(int size) :size(size) {
		if(size > 0) npcs = new NPC * [size];
		count = 0;
	}
	int Add(int id) {
		if(count < size)
		{
			NPC* temp = new NPC(id);
			for (int n = 0; n < count; n++)
				if (npcs[n]->id == id && id) return 0;
			if (id != 0)
			{
				npcs[count++] = temp;
			}
			return id;
		}
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

void MemoryErrorHandler() {
	cerr << "You have run out of memory! \n";
	exit(1);
};

//Functions need to be declared in advance so they're both initialised before they call one another
void FunctionBCallsA();
void FunctionACallsB();

void FunctionACallsB() {
	FunctionBCallsA();
};

void FunctionBCallsA() {
	FunctionACallsB();
};

int main() {
	AIManager* ai = new AIManager(10);
	std::set_new_handler(MemoryErrorHandler);

	FunctionACallsB();
	//Having the array as static prevented the stack overflow from happening somehow
	//int arr[1000000];

	//signed long int matrix[1201][1201] = { 0 };

	//for(int i = 1; i > 0; i++)
	//{
	//	char* MemoryString = new char[512000];
	//	std::cout << sizeof(MemoryString) << endl;
	//}
	ai->Add(0);
	ai->Add(1);
	ai->Add(2);
	ai->Add(3);
	ai->Display();
	ai->Delete();
	return 0;
};