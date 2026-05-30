#include <iostream>
using namespace std;

// a class to represent the "Questions" entity
class Question{
    public:
	int priority;
    int QuestionNo;
    string question;
    string OptionA;
    string OptionB;
    string OptionC;
    string OptionD;
    string CorrectOption;

    Question(){};

    Question(int QuestionNo, string question, string OptionA,string OptionB,string OptionC,string OptionD,string CorrectOption, int priority){
	this->QuestionNo = QuestionNo;
	this->question = question;
	this->OptionA = OptionA;
	this->OptionB = OptionB;
	this->OptionC = OptionC;
	this->OptionD = OptionD;
	this->CorrectOption = CorrectOption;
	this->priority = priority;
    }

    int getQuestionNo(){return QuestionNo;}
    string getquestion(){return question;}
    string getOptionA(){return OptionA;}
    string getOptionB(){return OptionB;}
    string getOptionC(){return OptionC;}
    string getOptionD(){return OptionD;}
    string getCorrectOption(){return CorrectOption;}
	int getPriority(){return priority;}
    
    void SetQuestionNo(int QuestionNo){ this->QuestionNo = QuestionNo;}
    void Setquestion(string question){this->question = question;}
    void SetOptionA(string OptionA){this->OptionA = OptionA;}
    void SetOptionB(string OptionB){this->OptionB = OptionB;}
    void SetOptionC(string OptionC){this->OptionC = OptionC;}
    void SetOptionD(string OptionD){this->OptionD = OptionD;}
    void SetCorrectOption(string CorrectOption){this->CorrectOption = CorrectOption;}
	void setPriority(int priority){this->priority = priority;}

    void display() {
		cout<<"\n\n";
        cout << QuestionNo<<")"<<  question << endl;
        cout << "  1)" << OptionA << "    " << "2)" << OptionB << "    " << "3)" << OptionC << "    " << "4)" << OptionD << endl;
		cout<<"\n";
    }

	void displayH() {
        cout <<  question << endl;
        cout << "  1)" << OptionA << "    " << "2)" << OptionB << "    " << "3)" << OptionC << "    " << "4)" << OptionD << endl;
		cout<<"\n";
    }

	bool IsCorrect(string option){
		if(option == CorrectOption){
			return true;
		}
		else{
			return false;
		}
	}

};

// Singly Linked list and Node Class using the "Questions" class
class QuestionNode{
public:
	Question question;
	QuestionNode* Next;

	QuestionNode(){}
	QuestionNode(Question question, QuestionNode* next) {
		this->question = question;
        Next = nullptr;
	}
	Question GetQuestion() { return question; }
	QuestionNode* GetNext() { return Next; }
	void SetQuestion(Question q) { question = q; }
	void SetNext(QuestionNode* n) { Next = n; }
};


// singly linked list
class QLinkedList {
public:
	QuestionNode* head;
    int currentQuestionNo;

	QuestionNode* getHead() {
		return head;
	}

	QLinkedList() { head = nullptr; currentQuestionNo = 0;}
	QLinkedList(QuestionNode* head) { this->head = head; }

    //H added method
    void Insert(Question q)
	{
		QuestionNode *newQuestion = new QuestionNode(q, nullptr);
		if (head == nullptr)
		{
			head = newQuestion;
			return;
		}
		else if (head->GetNext() == nullptr)
		{
			head->SetNext(newQuestion);
			return;
		}
		else
		{
			QuestionNode *current = head;
			while (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
			current->SetNext(newQuestion);
		}
	}
    //
	void Insert( string question, string OptionA,string OptionB,string OptionC,string OptionD,string CorrectOption,int priority = 0) {
		currentQuestionNo++;
        Question q = Question(currentQuestionNo, question, OptionA, OptionB,  OptionC,OptionD,CorrectOption,priority);
		QuestionNode* newQuestion= new QuestionNode(q, nullptr);
			if (head == nullptr) {
				head = newQuestion;
				return;
			}
			else if (head->GetNext() == nullptr) {
				head->SetNext(newQuestion);
				return;
			}
			else {
				QuestionNode* current = head;
				while (current->GetNext() != nullptr) {
					current = current->GetNext();
				}
				current->SetNext(newQuestion);
			}
	}
	void Delete(int QuestionNo) {
		if (head == nullptr) {
			return;
		}
		else if (head->GetNext() == nullptr && head->GetQuestion().getQuestionNo() == QuestionNo){
			QuestionNode* q; q = head; head = nullptr; delete q;
		}
		else{
			QuestionNode* current = head;
			QuestionNode* prev = nullptr;
			while (current->GetQuestion().getQuestionNo() != QuestionNo) {
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
			QuestionNode* current = head;
			while (current->GetNext() != nullptr) {
				current = current->GetNext();
				count++;
			}
			return count;
		}
	}
    void displayAll () {
        if (head == nullptr) { return; }
        QuestionNode* current = head;
        while ( current != NULL) {
            current->GetQuestion().display();
            current = current->GetNext();

        }
    }
};



class MinHeap{
    public:

    void Heapify(Question arr[], int size, int i){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left].priority  < arr[smallest].priority){
            smallest = left;
        }
        if(right < size && arr[right].priority < arr[smallest].priority){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[i], arr[smallest]);
            Heapify(arr, size, smallest);
        }
        else{
            return;
        }
    }
    
    void BuildHeap(Question arr[], int size){

        for(int i = size/2-1; i >= 0; i--){
            Heapify(arr, size, i);
        }
    }

    void SortHeap(Question arr[],int size){

        BuildHeap(arr,size);

        int n = size;
        while(n > 0){
            swap(arr[0], arr[n-1]);
            n--;
            Heapify(arr,n,0);
        }
    }

    void Heapify(int arr[], int size, int i){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left]  < arr[smallest]){
            smallest = left;
        }
        if(right < size && arr[right] < arr[smallest]){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[i], arr[smallest]);
            Heapify(arr, size, smallest);
        }
        else{
            return;
        }
    }
    
    void BuildHeap(int arr[], int size){

        for(int i = size/2-1; i >= 0; i--){
            Heapify(arr, size, i);
        }
    }

    void SortHeap(int arr[],int size){

        BuildHeap(arr,size);

        int n = size;
        while(n > 0){
            swap(arr[0], arr[n-1]);
            n--;
            Heapify(arr,n,0);
        }
    }
};


class CircularNode
{
private:
	Question data;
	CircularNode *next;

public:
	Question GetData()
	{
		return data;
	}
	void SetData(Question v)
	{
		data = v;
	}
	CircularNode *GetNext()
	{
		return next;
	}
	void SetNext(CircularNode *n)
	{
		next = n;
	}
};
class CircularLinkedList
{
public:
	CircularNode *First;

	CircularLinkedList()
	{
		First = nullptr;
	}
	void InsertNode(Question v)
	{
		CircularNode *n = new CircularNode();
		n->SetData(v);
		n->SetNext(First);

		if (First == nullptr)
		{
			First = n;
			return;
		}
		if (First->GetNext() == nullptr)
		{
			First->SetNext(n);
			return;
		}
		CircularNode *current = First;
		while (current->GetNext() != First)
		{
			current = current->GetNext();
		}
		current->SetNext(n);
	}

	void Delete(Question v)
	{
		if (First == nullptr)
		{
			cout << "The list is empty.";
			return;
		}
		CircularNode *current = First;
		CircularNode *toDelete = new CircularNode();
		if (First->GetData().getQuestionNo() == v.getQuestionNo())
		{
			if (First->GetNext() == nullptr)
			{
				First = nullptr;
			}
			else
			{
				do
				{
					current = current->GetNext();
				} while (current->GetNext() != First);
				toDelete = First;
				First = First->GetNext();
				current->SetNext(First);
			}
			delete toDelete;
			return;
		}
		current = current->GetNext();
		CircularNode *prev = First;
		while (current != First)
		{
			if (current->GetData().getQuestionNo() == v.getQuestionNo())
			{
				prev->SetNext(current->GetNext());
				delete current;
				return;
			}
			prev = current;
			current = current->GetNext();
		}
	}
	CircularLinkedList Josephus(int v)
	{
		CircularLinkedList cll;
		if (First == nullptr)
		{
			return cll;
		}
		if (First->GetNext() == nullptr)
		{
			return cll;
		}
		CircularNode *current = First;
		while (current->GetNext() != current)
		{
			for (int i = 1; i <= v; i++)
			{
				current = current->GetNext();
			}
			cll.InsertNode(current->GetData());
			CircularNode *toDelete = current;
			current = current->GetNext();
			Delete(toDelete->GetData());
		}
		cll.InsertNode(current->GetData());
		return cll;
	}
};




