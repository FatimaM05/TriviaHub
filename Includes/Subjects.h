#include <iostream>
#include "Chapters.h"
using namespace std;


// class to show the "Subjects" entity
class Subject{
    public:

    string Name;
    ChpLinkedList chapters;

    Subject(){
    chapters = ChpLinkedList();
    }

    Subject(string name){
        Name = name;
        chapters = ChpLinkedList();
    }

    string getSubjectName(){
        return Name;
    }

    void setSubject(string name){
        Name = name;
    }
};




// Singly Linked list and Node Class using the "Subject" class
class SubjectNode{
public:
	Subject Node;
	SubjectNode* Next;

	SubjectNode() {}
	SubjectNode(Subject node, SubjectNode* next) {
		Node = node;
		Next = nullptr;
	}
	Subject GetNode() { return Node; }
	SubjectNode* GetNext() { return Next; }
	void SetNode(Subject n) { Node = n; }
	void SetNext(SubjectNode* n) { Next = n; }
};

// singly linked list
class SLinkedList {
public:
	SubjectNode* head;
	SubjectNode* getHead() {
		return head;
	}
	SLinkedList() { head = nullptr; }
	SLinkedList(SubjectNode* h) { head = h; }
	SubjectNode* GetHead() { 
		return head; }

	void Insert(string SubName) {
		Subject s(SubName);
		SubjectNode* newSubject = new SubjectNode(s, nullptr);
			if (head == nullptr) {
				head = newSubject;
				return;
			}
			else {
				SubjectNode* current = head;
				while (current->GetNext() != nullptr) {
					current = current->GetNext();
				}
				current->SetNext(newSubject);
			}
	}

	void Delete(string subjectName) {
		if (head == nullptr) {
			return;
		}
		else if (head->GetNext() == nullptr && ((head->GetNode()).getSubjectName()) == subjectName){
			SubjectNode* h;
			h = head; 
			head = nullptr; 
			delete h;
		}
		else{
			SubjectNode* current = head;
			SubjectNode* prev = nullptr;
			while ((current->GetNode()).getSubjectName() != subjectName) {
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
			int count = 0;
			SubjectNode* current = head;
			while (current != nullptr) {
				count++;
				current = current->GetNext();
			}
			return count;
		}
	}
    void displayAll () {
		int i = 1;
        if (head == nullptr) { 
			// cout<<"No Subjects available in this class"<<endl;
			return; }
        else {
            SubjectNode* current = head;
            while (current != NULL) {
                cout <<i<<". "<< current->GetNode().getSubjectName()<<endl;
                current = current->GetNext();
				i++;
            }
        }
    }
};

// String List
class StrNode{
public:
	string SubName;
	IntLinkedlist* Chapters;
	StrNode* next;
	
	StrNode(string sName, StrNode* nextNode = nullptr, IntNode* chapterNo = nullptr){
		SubName = sName; next = nextNode;
		Chapters = new IntLinkedlist();
	}
	string GetSubName(){return SubName;}
	StrNode* GetNext(){return next;}
	void SetNext(StrNode* nextN){next = nextN;}
	void SetSubName(int sName){SubName = sName;}

	void InsertChapters(int chapNo){
		IntNode* NewChap = new IntNode(chapNo);
		IntNode* current = Chapters->head;
		if(current==nullptr){
			current = NewChap;
			Chapters->head = NewChap;
			return;
		}
		else{
			while(current->GetNext() == nullptr){
				current = current->next;
			}
			current->next = NewChap;
			return;
		}
	}
};

class StrLinkedlist{
	public:
	StrNode* head;

	StrLinkedlist() {
		head = NULL;
	}

	void Insert(string d) {
		if (head == NULL) {
			StrNode* newNode = new StrNode(d);
			head = newNode;
			newNode->Chapters->head = nullptr;
			return;
		}
		else {
			StrNode* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			StrNode* newNode = new StrNode(d);
			newNode->Chapters->head = nullptr;
			current->next = newNode;
			return;
		}
	}
	
	void InsertChpList(string subject, IntLinkedlist* listy) {
		StrNode* current = head;
		while (current->next != NULL) {
			if (current->GetSubName() == subject) {
				break;
		}
			current = current->next;
	}
	current->Chapters = listy;
	}
	
	void displayList() {
		StrNode* current = head;
		while (current != NULL) {
			cout << current->SubName;
			if(current->next != NULL){
				cout<<", ";
			}
			current = current->next;
		}
	}
	
};

