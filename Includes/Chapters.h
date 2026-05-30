#include <iostream>
#include "Question.h"
using namespace std;


// a class to represent the "Chapters entity"
class Chapter{
    public:

    int ChapterNumber;
	QLinkedList Questions;

    Chapter(){
	Questions = QLinkedList();
	}

    Chapter(int num){
        ChapterNumber = num;
		Questions = QLinkedList();
    }

    int GetChapterNumber(){
        return ChapterNumber;
    }

    void setChapter(int chapter){
        ChapterNumber = chapter;
    }
};

// Singly Linked list and Node Class using the "Chapter" class
class ChapterNode{
public:
	Chapter Node;
	ChapterNode* Next;

	ChapterNode() {}
	ChapterNode(Chapter node, ChapterNode* next) {
		Node = node;
		Next = nullptr;
	}
	Chapter GetNode() { return Node; }
	ChapterNode* GetNext() { return Next; }
	void SetNode(Chapter n) { Node = n; }
	void SetNext(ChapterNode* n) { Next = n; }
};

// singly linked list
class ChpLinkedList {
public:
	ChapterNode* head;
	ChpLinkedList() { head = nullptr; }
	ChpLinkedList(ChapterNode* h) { head = h; }
	ChapterNode* GetHead() { return head; }

	void Insert(int cNumber) {
		Chapter c(cNumber);
		ChapterNode* newChp = new ChapterNode(c, nullptr);
		if(head == nullptr)
		{
			head = newChp;
		}
		else {
			ChapterNode* current = head;
			while (current->GetNext() != nullptr) {
				current = current->GetNext();
			}
			current->SetNext(newChp);
		}
	}

	void Delete(int cNumber) {
		if (head == nullptr) {
			return;
		}
		else {
			ChapterNode* current = head;
			ChapterNode* prev = nullptr;
			while ((current->GetNode()).GetChapterNumber()!= cNumber) {
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
		int size = 0;
		ChapterNode* current = head;
		if (head == nullptr) { return 0; }
		else if (head->GetNext() == nullptr) { return 1; }
		else {
			while (current != nullptr) {
				size++;
				current = current->GetNext();
			}
		}
		return size;
	}

    void displayAll(){
        if(head == NULL){return;}
        ChapterNode* current = head;
        while(current != NULL){
            cout << current->GetNode().GetChapterNumber() << endl;
            current = current->GetNext();
        }
    }
};

// Int List
class IntNode
{
public:
	int ChapNumber;
	IntNode *next;

	IntNode(int chapNo, IntNode *nextNode = nullptr)
	{
		ChapNumber = chapNo;
		next = nextNode;
	}
	int GetChapNumber() { return ChapNumber; }
	IntNode *GetNext() { return next; }
	void SetNext(IntNode *nextN) { next = nextN; }
	void SetChapNumber(int chapNo) { ChapNumber = chapNo; }
};
class IntLinkedlist
{
public:
	IntNode *head;
	IntLinkedlist() { head = nullptr; }
	IntLinkedlist(int chapNo)
	{
		IntNode *newnode = new IntNode(chapNo);
		head = newnode;
	}
	void Insert(int chapNo)
	{
		IntNode *newNode = new IntNode(chapNo);
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		else if (head->GetNext() == nullptr)
		{
			head->SetNext(newNode);
			return;
		}
		else
		{
			IntNode *current = head;
			while (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
			current->SetNext(newNode);
		}
	}

	int GetSize() {
		int size = 0;
		IntNode* current = head;
		if (head == nullptr) { return 0; }
		else if (head->GetNext() == nullptr) { return 1; }
		else {
			while (current != nullptr) {
				size++;
				current = current->GetNext();
			}
		}
		return size;
	}

	void Display(){
		if(head==nullptr){
			return;
		}
		else{
			IntNode* current = head;
			while(current->GetNext()!=nullptr){
				cout<<current->GetChapNumber()<<", ";
				current= current->GetNext();
			}
			cout<<current->GetChapNumber();
		}
	}

};

