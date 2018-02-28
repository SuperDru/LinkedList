#include "LinkedList.h"

int main() {
	LinkedList<int> list;

	for (int i = 0; i < 10; i++) {
		list.add(i * 2);
	}

	for (int i = 0; i < 10; i++) {
		list.remove(0);
	}

	list.addBegin(10); 
	list.addBegin(7);
	cout << list.get(1);

	_getch();
	return 0;
}