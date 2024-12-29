#include"DoublyLinkedList.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DoublyLinkedList<int> list1;
	list1.addToEnd(1);
	list1.addToEnd(2);
	list1.addToEnd(3);
	cout << "List 1: ";
	list1.display();
	cout << endl;

	DoublyLinkedList<int> list2;
	list2.addToEnd(4);
	list2.addToEnd(5);
	list2.addToEnd(3);
	cout << "List 2: ";
	list2.display();
	cout << endl;

	Node<int>* clonedHead = list1.clone();
	DoublyLinkedList<int> clonedList;
	list1.initializeListFromNode(clonedHead, clonedList);
	cout << "Cloned List: ";
	clonedList.display();
	cout << endl;

	Node<int>* mergedHead = list1 + list2;
	DoublyLinkedList<int> mergedList;
	list1.initializeListFromNode(mergedHead, mergedList);
	cout << "Merged List: ";
	mergedList.display();
	cout << endl;

	Node<int>* commonElementsHead = list1 * list2;
	DoublyLinkedList<int> commonElementsList;
	list1.initializeListFromNode(commonElementsHead, commonElementsList);
	cout << "Common Elements List: ";
	commonElementsList.display();
	cout << endl;

	list1.swapHeadAndTail();
	cout << "List 1 after swapping head and tail: ";
	list1.display();
	cout << endl;

	return 0;
}
