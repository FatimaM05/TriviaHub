#include <iostream>
#include "Stacky.h"

// file handling library below
#include <fstream>
#include <sstream>
// for date and time
#include <ctime>
#include <limits>
#include <iomanip> // Include the iomanip library


using namespace std;

// so the concept is that i have the scores.txt file where i have the history of all the quizzes, i will fetch that and put it all in a heap and than i can either simply use a heap sort or i can make
// a max heap where i just pop the root and than heapify and than pop the root again and loop it until the heap is empty

bool isIntegerHeap(string inputstring){
    for( char c: inputstring){                   
        if(c < '0' || c > '9'){                         
            return false;
        }       
    }
    return true;
}



class HeapHistoryNode
{
public:
    string username;
    string Class;
    StrLinkedlist SubAndChap; // the strLinked list that ht and H used in their methods
    int TotalMarks;
    int ObtainedMarks;
    string dateTime;
    float Percentage;
    HeapHistoryNode *Next;

    HeapHistoryNode() { Next = NULL; }

    HeapHistoryNode(string u, string c, StrLinkedlist SC, int t, int ot, string dto = "")
    {
        username = u;
        Class = c;
        SubAndChap = SC;
        TotalMarks = t;
        ObtainedMarks = ot;
        Next = NULL;
    
        float fo = static_cast<float>(ObtainedMarks);
        float ft = static_cast<float>(TotalMarks);

        Percentage = fo/ ft * 100;

        // date and time calculation, assuming that the date and the time stored will always be the secondary.heap[0].ime, as in the time the quiz was taken
        if (dto == "")
        {
            time_t now = time(0);
            char *dt = ctime(&now);
            dateTime = string(dt);

            dateTime = dateTime.substr(0, dateTime.length() - 1);
        }
        else
        {
            dateTime = dto;
        }
    }

    void setUsername(string u) { username = u; }
    void setClass(string c) { Class = c; }
    void setTotalMarks(int t) { TotalMarks = t; }
    void setObtainedMarks(int ot) { ObtainedMarks = ot; }
    void setNext(HeapHistoryNode *next) { Next = next; }

    string getUsername() { return username; }
    string getClass() { return Class; }
    int getTotalMarks() { return TotalMarks; }
    int getObtainedMarks() { return ObtainedMarks; }
    HeapHistoryNode *getNext() { return Next; }
};

class HighScoreHeap
{
public:
    HeapHistoryNode *heap;
    int Size;
    int currentSize = 0;

    HighScoreHeap()
    {
        currentSize = 0;
    }

    HighScoreHeap(int size)
    {
        this->Size = size;
        currentSize = 0;
        heap = new HeapHistoryNode[size];
    }

    void setSize(int s)
    {
        this->Size = s;
        heap = new HeapHistoryNode[s];
    }

    void Swapper(HeapHistoryNode &parent, HeapHistoryNode &child)
    {
        HeapHistoryNode temp = parent;
        parent = child;
        child = temp;
    }

    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < currentSize && heap[left].Percentage > heap[largest].Percentage)
        {
            largest = left;
        }
        if (left < currentSize && heap[right].Percentage > heap[largest].Percentage)
        {
            largest = right;
        }
        if (largest != index)
        {
            Swapper(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent].Percentage < heap[index].Percentage)
            {
                Swapper(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }

    }

    void Insert(string u, string c, StrLinkedlist list, int total, int obtained, string dto = "")
    {
        
        if (Size == currentSize)
        {
            return;
        }
        if (currentSize == 0) {
        HeapHistoryNode newNode = HeapHistoryNode(u, c, list, total, obtained, dto);
            heap[currentSize] = newNode;
            currentSize++;
            return;
        }
        else {
        HeapHistoryNode newNode = HeapHistoryNode(u, c, list, total, obtained, dto);
        heap[currentSize] = newNode;

        heapifyUp(currentSize);
        currentSize++;
        }
    }



    void Insert(HeapHistoryNode h)
    {
        
        if (Size == currentSize)
        {
            return;
        }
        if (currentSize == 0) {
            heap[currentSize] = h;
            currentSize++;
            return;
        }
        else {
        heap[currentSize] = h;

        heapifyUp(currentSize);
        currentSize++;
        }
    }




    bool IsEmptyS() {
        if (currentSize == 0) return true;
    }

    void ExtractMax()
    {
        if (currentSize == 0)
        {
            return;
        }
        heap[0] = heap[--currentSize];
        heapifyDown(0);
    }

    int getHeapSize()
    {
        return currentSize;
    }

    void PopulateHeap()
    {

        ifstream y("Scores.txt");
        if (y.is_open())
        {
            int heapCount = 0;
            string checker;
            while (getline(y, checker))
            {
                heapCount++;
            }
            setSize(heapCount);
            y.clear();
            y.seekg(0, ios::beg);
            string line;
            int c = 0;
            while (getline(y, line))
            {
                c++;
                string username, Class, Subject, Chapter, TotalMarks, ObtainedMarks, dateTime, subCount;
                int ot, ob;
                stringstream ss(line);
                getline(ss, subCount, ','); // number of subjects
                getline(ss, username, ',');
                getline(ss, Class, ',');
                int count = stoi(subCount);
                StrLinkedlist list = StrLinkedlist();
                for (int i = 0; i < count; i++)
                {
                    getline(ss, Subject, ',');
                    list.Insert(Subject);
                    string countChap;
                    getline(ss, countChap, ','); // number of chapters in that one subject
                    int count2 = stoi(countChap);
                    IntLinkedlist *chapList = new IntLinkedlist();
                    for (int j = 0; j < count2; j++)
                    {
                        string ch;
                        getline(ss, ch, ',');
                        int chNo = stoi(ch);
                        chapList->Insert(chNo);
                    }
                    list.InsertChpList(Subject, chapList);
                }
                getline(ss, TotalMarks, ',');
                getline(ss, ObtainedMarks, ',');
                getline(ss, dateTime, '\n');
                ot = stoi(TotalMarks);
                ob = stoi(ObtainedMarks);
                Insert(username, Class, list, ot, ob, dateTime);
            }
            y.close();
        }
        y.close();
    }



void DisplayAllScores()
{
    PopulateHeap();
    HighScoreHeap secondary = HighScoreHeap(currentSize);
    int counter = 0;
    int count = currentSize;
    if (currentSize > 0)
    {
        for (int i = 0; i < count; i++)
        {
            counter++;
                cout << setw(3) << left << counter;

                // Output the username with a fixed width of, for example, 15 characters
                cout << setw(15) << left << heap[0].username << " [";

                // Calculate the width of the progress bar based on the percentage
                int progressBarWidth = static_cast<int>(heap[0].Percentage) / 1;

                // Output the progress bar
                for (int j = 0; j < progressBarWidth; j++) {
                    if(j>50){
                    cout<<"\033[1;32m";
                    cout << "*";
                    cout<<"\033[0m";
                    }
                    if(j<50){
                    cout<<"\033[1;31m";
                    cout << "*";
                    cout<<"\033[0m";
                    }
                }

                // Fill the remaining space with spaces to align the percentage
                cout << setw(50 - progressBarWidth) << right << "] ";

                // Output the percentage
                cout << setw(4) << right << heap[0].Percentage << "%" << "\n\n";
                secondary.Insert(heap[0]);
                ExtractMax();
        }
        AGAIN:
        secondary.currentSize = 0;
        secondary.PopulateHeap();
        string cs;
        cout << "Enter the index of the student to view their details or press 0 to exit: " << endl;
            while (true) {
            cin >> cs;
            if (!isIntegerHeap(cs)) {
                ShowPopup("Invalid input mate, enter a number not a string");
                goto AGAIN;
            } else {
                int c = stoi(cs);
                        if (c == 0) {
            ShowPopup("Score system terminated");
            return;
        }
        if (c > counter) {
            ShowPopup("Invalid choice mate. You entered something greater than the highest index?");
            goto AGAIN;
        }
        if (c == 1) {
            cout<<"\n";
            cout << "┌────────────────────────────────────────────────────────────────┐\n";
            cout << "│\U0001F464 Student: " << setw(52) << left << secondary.heap[0].username << "│\n";
            cout << "│\U0001F4D8 Class: " << setw(54) << left << secondary.heap[0].Class << "│\n";
            cout << "│\U0001F4C8 Percentage: " << setw(48) << left << secondary.heap[0].Percentage << " │\n";
            cout << "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
            cout<< "│            \t\t\t                                 │\n";
            StrNode* temp = secondary.heap[0].SubAndChap.head;
            while (temp != NULL) {
            cout <<"|"<< temp->SubName << ": ";
            IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << "| ";
            temp2 = temp2->next;
            }
            temp = temp->next;
            cout << "                 \t\t\t\t\t |\n";
            }
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│            \t\t\t                                 │\n";
            cout<< "|\U0001F3AF Marks: " << secondary.heap[0].ObtainedMarks << "/" << secondary.heap[0].TotalMarks << "  \U0001F4C6 Date and Time: " << secondary.heap[0].dateTime<<"\t |\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n\n\n";
            goto AGAIN;
        }
        else if (c >= 2 && c <= secondary.currentSize) 
        {
            for (int i = 1; i < c; i++) {
                secondary.ExtractMax();
            }
            cout<<"\n";
            cout << "┌────────────────────────────────────────────────────────────────┐\n";
            cout << "│\U0001F464 Student: " << setw(52) << left << secondary.heap[0].username << "│\n";
            cout << "│\U0001F4D8 Class: " << setw(54) << left << secondary.heap[0].Class << "│\n";
            cout << "│\U0001F4C8 Percentage: " << setw(48) << left << secondary.heap[0].Percentage << " │\n";
            cout << "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
            cout<< "│            \t\t\t                                 │\n";
            StrNode* temp = secondary.heap[0].SubAndChap.head;
            while (temp != NULL) {
            cout <<"|"<< temp->SubName << ": ";
            IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << "| ";
            temp2 = temp2->next;
            }
            temp = temp->next;
            cout << "                 \t\t\t\t\t |\n";
            }
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│            \t\t\t                                 │\n";
            cout<< "|\U0001F3AF Marks: " << secondary.heap[0].ObtainedMarks << "/" << secondary.heap[0].TotalMarks << "  \U0001F4C6 Date and Time: " << secondary.heap[0].dateTime<<"\t |\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n\n\n";
            }
            goto AGAIN;
            }
        }

        }
    }


};




    void displayStudentScores(string name) {
        ifstream y("Scores.txt");
        string line;
        bool checker = false;
        while (getline(y, line)) {
            string u, s, c;
            stringstream ss(line);
            getline(ss, s, ',');
            getline(ss, u, ',');
            getline(ss, c, ',');
            if (u == name) {
                checker = true;
            }
        }
        y.close();
        if (!checker) {
            ShowPopup("There is no record for the student that you entered");
            return;
        }
        
        HighScoreHeap first = HighScoreHeap();
        first.PopulateHeap();

        HighScoreHeap secondary = HighScoreHeap(first.currentSize);

        for (int i = 0; i < first.currentSize; i++) {
            if (first.heap[i].username == name) {
                secondary.Insert(first.heap[i]);
            }
        }

        HighScoreHeap secondary2 = HighScoreHeap(secondary.currentSize);
        int counter = 0;
        int count = secondary.currentSize;
        for (int i = 0; i < count; i++)
        {
            counter++;
                cout << setw(3) << left << counter;

                // Output the username with a fixed width of, for example, 15 characters
                cout << setw(15) << left << secondary.heap[0].username << " [";

                // Calculate the width of the progress bar based on the percentage
                int progressBarWidth = static_cast<int>(secondary.heap[0].Percentage) / 1;

                // Output the progress bar
                for (int j = 0; j < progressBarWidth; j++) {
                    if(j>50){
                    cout<<"\033[1;32m";
                    cout << "*";
                    cout<<"\033[0m";
                    }
                    if(j<50){
                    cout<<"\033[1;31m";
                    cout << "*";
                    cout<<"\033[0m";
                    }
                }

                // Fill the remaining space with spaces to align the percentage
                cout << setw(50 - progressBarWidth) << right << "] ";

                // Output the percentage
                cout << setw(4) << right << secondary.heap[0].Percentage << "%" << "\n\n";
                secondary2.Insert(secondary.heap[0]);
                secondary.ExtractMax();
        }
                AGAIN2:
                secondary2.currentSize = 0;
                secondary.currentSize = 0;
                secondary2.PopulateHeap();
                for (int i = 0; i < secondary2.currentSize; i++) {
                    if (secondary2.heap[i].username == name) {
                    secondary.Insert(secondary2.heap[i]);
                    }
                }
        string cs;
        cout << "Enter the index of the student to view their details or press 0 to exit: " << endl;
            while (true) {
            cin >> cs;
            if (!isIntegerHeap(cs)) {
                ShowPopup("Invalid input mate, enter a number not a string");
                goto AGAIN2;
            } else {
                int c = stoi(cs);
                        if (c == 0) {
            ShowPopup("Score system terminated");
            return;
        }
        if (c > counter) {
            ShowPopup("Invalid choice mate. You entered something greater than the highest index?");
            goto AGAIN2;
        }
        if (c == 1) {
            cout << "┌────────────────────────────────────────────────────────────────┐\n";
            cout << "│\U0001F464 Student: " << setw(52) << left << secondary.heap[0].username << "│\n";
            cout << "│\U0001F4D8 Class: " << setw(54) << left << secondary.heap[0].Class << "│\n";
            cout << "│\U0001F4C8 Percentage: " << setw(48) << left << secondary.heap[0].Percentage << " │\n";
            cout << "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
            cout<< "│            \t\t\t                                 │\n";
            cout << "Subjects and Chapters: " << endl;
            StrNode* temp = secondary.heap[0].SubAndChap.head;
            while (temp != NULL) {
            cout <<"|"<< temp->SubName << ": ";
            IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << "| ";
            temp2 = temp2->next;
            }
            temp = temp->next;
            cout << "                 \t\t\t\t\t |\n";
            }
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│            \t\t\t                                 │\n";
            cout<< "|\U0001F3AF Marks: " << secondary.heap[0].ObtainedMarks << "/" << secondary.heap[0].TotalMarks << "  \U0001F4C6 Date and Time: " << secondary.heap[0].dateTime<<"\t |\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n\n\n";
            goto AGAIN2;
        }
        else if (c >= 2 && c <= secondary.currentSize) 
        {
            for (int i = 1; i < c; i++) {
                secondary.ExtractMax();
            }
            cout<<"\n";
            cout << "┌────────────────────────────────────────────────────────────────┐\n";
            cout << "│\U0001F464 Student: " << setw(52) << left << secondary.heap[0].username << "│\n";
            cout << "│\U0001F4D8 Class: " << setw(54) << left << secondary.heap[0].Class << "│\n";
            cout << "│\U0001F4C8 Percentage: " << setw(48) << left << secondary.heap[0].Percentage << " │\n";
            cout << "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
            cout<< "│            \t\t\t                                 │\n";
            StrNode* temp = secondary.heap[0].SubAndChap.head;
            while (temp != NULL) {
            cout <<"|"<< temp->SubName << ": ";
            IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << "| ";
            temp2 = temp2->next;
            }
            temp = temp->next;
            cout << "                 \t\t\t\t\t |\n";
            }
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│            \t\t\t                                 │\n";
            cout<< "|\U0001F3AF Marks: " << secondary.heap[0].ObtainedMarks << "/" << secondary.heap[0].TotalMarks << "  \U0001F4C6 Date and Time: " << secondary.heap[0].dateTime<<"\t |\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n\n\n";
            }
            cout<<"\n";
            goto AGAIN2;
            }
        }
    }



    void displayClassScores(string Class) {
        ifstream y("Scores.txt");
        string line;
        bool checker = false;
        while (getline(y, line)) {
            string u, s, c;
            stringstream ss(line);
            getline(ss, s, ',');
            getline(ss, u, ',');
            getline(ss, c, ',');
            if (c == Class) {
                checker = true;
            }
        }
        y.close();
        if (!checker) {
            ShowPopup("There is no record for the class that you entered");
            return;
        }

        HighScoreHeap first = HighScoreHeap();
        first.PopulateHeap();

        HighScoreHeap secondary = HighScoreHeap(first.currentSize);

        for (int i = 0; i < first.currentSize; i++) {
            if (first.heap[i].Class == Class) {
                secondary.Insert(first.heap[i]);
            }
        }

        HighScoreHeap secondary2 = HighScoreHeap(secondary.currentSize);
        int counter = 0;
        int count = secondary.currentSize;
        for (int i = 0; i < count; i++)
        {
            counter++;
                cout << setw(3) << left << counter;

                // Output the username with a fixed width of, for example, 15 characters
                cout << setw(15) << left << secondary.heap[0].username << " [";

                // Calculate the width of the progress bar based on the percentage
                int progressBarWidth = static_cast<int>(secondary.heap[0].Percentage) / 1;

                // Output the progress bar
                for (int j = 0; j < progressBarWidth; j++) {
                    if(j>50){
                    cout<<"\033[1;32m";
                    cout << "*";
                    cout<<"\033[0m";
                    }
                    if(j<50){
                    cout<<"\033[1;31m";
                    cout << "*";
                    cout<<"\033[0m";
                    }
                }

                // Fill the remaining space with spaces to align the percentage
                cout << setw(50 - progressBarWidth) << right << "] ";

                // Output the percentage
                cout << setw(4) << right << secondary.heap[0].Percentage << "%" << "\n\n";
                secondary2.Insert(secondary.heap[0]);
                secondary.ExtractMax();
        }
                AGAIN2:
                secondary2.currentSize = 0;
                secondary.currentSize = 0;
                secondary2.PopulateHeap();
                for (int i = 0; i < secondary2.currentSize; i++) {
                    if (secondary2.heap[i].Class == Class) {
                    secondary.Insert(secondary2.heap[i]);
                    }
                }
        string cs;
        cout << "Enter the index of the row to view the details or press 0 to exit: " << endl;
            while (true) {
            cin >> cs;
            if (!isIntegerHeap(cs)) {
                ShowPopup("Invalid input mate, enter a number not a string");
                goto AGAIN2;
            } else {
                int c = stoi(cs);
                        if (c == 0) {
            ShowPopup("Score system terminated");
            return;
        }
        if (c > counter) {
            ShowPopup("Invalid choice mate. You entered something greater than the highest index?");
            goto AGAIN2;
        }
        if (c == 1) {
            cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
            cout<< "│\U0001F464 Student: "<<secondary.heap[0].username <<"            \t\t                         │\n";
            cout<< "│\U0001F4D8 Class: "<<secondary.heap[0].Class <<"            \t                                 │\n";
            cout<< "│\U0001F4C8 Percentage: "<<secondary.heap[0].Percentage <<"%                                             │\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
            cout<< "│            \t\t\t                                 │\n";
            StrNode* temp = secondary.heap[0].SubAndChap.head;
            while (temp != NULL) {
            cout <<"| "<< temp->SubName << ": ";
            IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << "| ";
            temp2 = temp2->next;
            }
            temp = temp->next;
            cout << "                 \t\t\t\t\t |\n";
            }
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│            \t\t\t                                 │\n";
            cout<< "|\U0001F3AF Marks: " << secondary.heap[0].ObtainedMarks << "/" << secondary.heap[0].TotalMarks << "  \U0001F4C6 Date and Time: " << secondary.heap[0].dateTime<<"\t |\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n\n";
            goto AGAIN2;
        }
        else if (c >= 2 && c <= secondary.currentSize) 
        {   

            for (int i = 1; i < c; i++) {
                secondary.ExtractMax();
            }
            cout << "┌────────────────────────────────────────────────────────────────┐\n";
            cout << "│\U0001F464 Student: " << setw(52) << left << secondary.heap[0].username << "│\n";
            cout << "│\U0001F4D8 Class: " << setw(54) << left << secondary.heap[0].Class << "│\n";
            cout << "│\U0001F4C8 Percentage: " << setw(48) << left << secondary.heap[0].Percentage << " │\n";
            cout << "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
            cout<< "│            \t\t\t                                 │\n";
            StrNode* temp = secondary.heap[0].SubAndChap.head;
            while (temp != NULL) {
            cout <<"|"<< temp->SubName << ": ";
            IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << "| ";
            temp2 = temp2->next;
            }
            temp = temp->next;
            cout << "                 \t\t\t\t\t |\n";
            }
            cout<< "└────────────────────────────────────────────────────────────────┘\n";
            cout<< "│            \t\t\t                                 │\n";
            cout<< "|\U0001F3AF Marks: " << secondary.heap[0].ObtainedMarks << "/" << secondary.heap[0].TotalMarks << "  \U0001F4C6 Date and Time: " << secondary.heap[0].dateTime<<"\t |\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n\n\n";
            }
            goto AGAIN2;
            }
        }
    }

