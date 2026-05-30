#include <iostream>
#include "Subjects.h"
using namespace std;



// a class of "Class" entity
class Class{
    public: 
    string ClassName;
	SLinkedList subjects;

    Class(){
	subjects = SLinkedList();
	}



    Class(string name){
        ClassName = name;
		subjects = SLinkedList();
    }

    string getClassNumber(){return ClassName;}

    void setClassName(string name){ClassName = name;}
};


// Singly Linked list and Node Class using the "Class" class
class ClassNode {
public:
	Class Node;
	ClassNode* Next;

	ClassNode() {}
	ClassNode(Class node, ClassNode* next) {
		Node = node;
		Next = next;
	}
	Class GetNode() { return Node; }
	ClassNode* GetNext() { return Next; }
	void SetNode(Class n) { Node = n; }
	void SetNext(ClassNode* n) { Next = n; }
	
};

// singly linked list
class CLinkedList {
public:
	ClassNode* head;

	ClassNode* getHead () {
		return head;
	}
	CLinkedList() { head = nullptr; }
	CLinkedList(ClassNode* h) { head = h; }
	
	//Sorted insert method of the class
		void Insert(string classNumber) {
    		Class c(classNumber);
    		ClassNode* newClass = new ClassNode(c, nullptr);
    		if (head == nullptr) {
        		head = newClass;
       			return;
    		}
    		// If new class is less than the prev class, new class becomes the new head
    		else if (classNumber < head->GetNode().getClassNumber()) {
        		newClass->SetNext(head);
        		head = newClass;
        		return;
    		}
    		else{
			//going till it doesnt get larger than the prev added classes...once found will be inserted next to it
    		ClassNode* current = head;
    		while (current->GetNext() != nullptr && classNumber > current->GetNext()->GetNode().getClassNumber()) {
        		current = current->GetNext();
    		}
    		newClass->SetNext(current->GetNext());
    		current->SetNext(newClass);
			}
		}

	//Sorted insert method of class ends

	//OLD method
	// void Insert(string classNumber) {
	// 	Class c(classNumber);
	// 	ClassNode* newClass = new ClassNode(c, nullptr);
	// 		if (head == nullptr) {
	// 			head = newClass;
	// 			return;
	// 		}
	// 		else if (head->GetNext() == nullptr) {
	// 			head->SetNext(newClass);
	// 			return;
	// 		}
	// 		else {
	// 			ClassNode* current = head;
	// 			while (current->GetNext() != nullptr) {
	// 				current = current->GetNext();
	// 			}
	// 			current->SetNext(newClass);
	// 		}
	// }
	//OLD method
	void Delete(string ClassNumber) {
		if (head == nullptr) {
			return;
		}
		else if ((head->GetNext() == nullptr) && ((head->GetNode()).getClassNumber() == ClassNumber)){
			ClassNode* h; h = head; head = nullptr; delete h;
		}
		else {
			ClassNode* current = head;
			ClassNode* prev = nullptr;
			while ((current->GetNode()).getClassNumber() != ClassNumber) {
				prev = current;
				current = current->GetNext();
			}
			if (prev == NULL) head = current->Next;
			else {
				prev->SetNext(current->GetNext());
			delete current;
		}
		}
	}
	int GetSize() {
		if (head == nullptr) { return 0; }
		else if (head->GetNext() == nullptr) { return 1; }
		else {
			int count = 1;
			ClassNode* current = head;
			while (current->GetNext() != nullptr) {
				current = current->GetNext();
				count++;
			}
			return count;
		}
	}
	
    void displayAll () {
        if (head == nullptr) { return;}
        else {
            ClassNode* current = head;
            while (current != NULL) {
                cout <<"Class"<<current->GetNode().getClassNumber() << endl;
                current = current->GetNext();
            }
        }
    }
};


