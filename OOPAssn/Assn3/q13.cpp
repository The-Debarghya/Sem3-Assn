/*Create a class for linked list.
Consider a separate class NODE for basic node activities and use it in class for linked list.*/

#include <iostream>
class Node {   // Node class to represent a node of the linked list.
  int data;
  Node* next;
public:
  friend class Linkedlist;
  Node(){      // Default constructor
		data = 0;
		next = NULL;
  }
	Node(int data){    // Parameterised Constructor
		this->data = data;
		this->next = NULL;
	}
};
class Linkedlist {  // Linked list class to implement a linked list.
	Node* head;
public:
	Linkedlist() { head = NULL; }  // Default constructor
	void insertNode(int);
	void printList();
	void deleteNode(int);
};
void Linkedlist::deleteNode(int index){   //delete a node of the specified index
	Node *temp1 = head, *temp2 = NULL;
	int len = 0;
	if (head == NULL) {
		std::cout << "List empty." << "\n";
		return;
  }
	while (temp1 != NULL) {    //length of the list
		temp1 = temp1->next;
		len++;
	}
	if (len < index || index < 0) {
		std::cout << "Index out of range" << "\n";
		return;
	}
	temp1 = head;
	if (index == 0) {
		head = head->next;
		delete temp1;
		return;
	}
	while (index-- > 0) {
		temp2 = temp1;
		temp1 = temp1->next;
	}
	temp2->next = temp1->next;
	delete temp1;
}
void Linkedlist::insertNode(int data){   // Create the new Node.
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
void Linkedlist::printList(){           //print the whole list
	Node* temp = head;
	if (head == NULL) {
		std::cout << "List empty" << "\n";
		return;
	}
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}
int main(){
	Linkedlist list;  //linked list object
	int choice, n;
  do {
    std::cout << "1.Add a node\n2.Display the elements of the list\n3.Delete an element by index\n4.Exit" << '\n';
    std::cout << "Enter a choice:";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "Enter the number you wanna add:";
        std::cin >> n;
        list.insertNode(n);
        std::cout <<"\n"<< n << " successfully added!!" << '\n';
        break;
      case 2:
        std::cout << "\nElements of the list are: ";
        list.printList();
        std::cout << "\n";
        break;
      case 3:
        std::cout << "Enter the index of the element you wanna delete:" ;
        std::cin >> n;
        list.deleteNode(n);
      	std::cout << "\nElements of the list are: ";
      	list.printList();
      	std::cout << "\n";
        break;
      case 4:
        exit(0); break;
      default:
        std::cout << "1.Add a node\n2.Display the elements of the list\n3.Delete an element by index\n4.Exit" << '\n';
        break;
    }
  } while(1);
	return 0;
}
