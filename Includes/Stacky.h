// this header file contains a stack that has nodes that represent a quiz that a specific student took

#include <iostream>
//file handling library below
#include <fstream>
#include <sstream>
// for date and time
#include <ctime>
// for PopUp Message
#include <Windows.h>
#include "Educational_Institute.h"  // THIS IS NEEDED HERE SO WE CAN USE THE LINKED LISTS HT AND H ARE USING. stacky is in NAryTree header file so it there is no interference with ht and h's methods basically
using namespace std;

// Method to show PopUp on cmd

void ShowPopup(const char* message) {
    // Convert char* to wchar_t*
    int len;
    int message_len = strlen(message) + 1;
    len = MultiByteToWideChar(CP_ACP, 0, message, message_len, NULL, 0);
    wchar_t* wide_message = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, message, message_len, wide_message, len);

    // Create the message box using MessageBoxW
    MessageBoxW(NULL, wide_message, L"Message", MB_OK | MB_ICONINFORMATION);

    // Clean up
    delete[] wide_message;
}

// NOTE: THERE IS A NEW INSERT METHOD IN THE STRLINKEDLIST CLASS THAT IS USED IN MY CUTE STACKY, so yeah, be sure to add that there. its called InsertChpList



class StdQuizNode {
public:
string username;
string Class;
StrLinkedlist SubAndChap;   // the strLinked list that ht and H used in their methods
int TotalMarks;
int ObtainedMarks; 
string dateTime;

StdQuizNode* Next;


StdQuizNode () {Next = NULL;}

StdQuizNode (string u, string c, StrLinkedlist SC,  int t, int ot, string dto = "") {
    username = u; 
    Class = c;
    SubAndChap = SC;    
    TotalMarks = t;
    ObtainedMarks = ot;
    Next = NULL;

    // date and time calculation, assuming that the date and the time stored will always be the current time, as in the time the quiz was taken
if (dto == "") {
    time_t now = time(0);
    char* dt = ctime(&now);
    dateTime = string(dt);

    dateTime = dateTime.substr(0, dateTime.length() - 1);
}
else {
    dateTime = dto;
}
}

void setUsername(string u) {username = u;}
void setClass(string c) {Class = c;}
void setTotalMarks(int t) {TotalMarks = t;}
void setObtainedMarks(int ot) {ObtainedMarks = ot;}
void setNext(StdQuizNode* next) {Next = next;}

string getUsername() {return username;}
string getClass() {return Class;}
int getTotalMarks() {return TotalMarks;}
int getObtainedMarks() {return ObtainedMarks;}
StdQuizNode* getNext() {return Next;}
};


class HistoryStack {
    public: 
    StdQuizNode* top;
    HistoryStack() {top = NULL;}

    bool isEmpty() {if (top == NULL) return true; else {return false;}}

void push(string u, string c, StrLinkedlist SC, int t, int ot, string dto = "") {
    if (top == NULL) top = new StdQuizNode(u, c, SC, t, ot, dto);
    else {
        StdQuizNode* newTop = new StdQuizNode(u, c, SC, t, ot, dto);
        newTop->setNext(top);
        top = newTop;
    }
}

void pop() {
    if (top == NULL) return;
    else {
        StdQuizNode* temp = top;
        top = top->getNext();
        delete temp;
    }
    }

StdQuizNode* peek() {
    cout << "===========================================================================" << endl;
    cout << "Student: " << top->username << endl;
    cout << "Class: " << top->Class << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Subjects and Chapters: " << endl;
    StrNode* temp = top->SubAndChap.head;
        while (temp != NULL) {
        cout << temp->SubName << ": ";
        IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << " ";
            temp2 = temp2->next;
            }
        temp = temp->next;
        cout << endl;
        }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Marks: " << top->ObtainedMarks << "/" << top->TotalMarks << "  Date and Time: " << top->dateTime << endl;
    cout << "===========================================================================" << "\n\n\n";
    return top;
}

void displayEntireHistory() {
    StdQuizNode* current = top;
    int i = 1;
    cout << "\n\n\U0001F4CB ALL CLASSES QUIZ HISTORY : \n" << endl;
    while (current != NULL) {
                cout<<"\n\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│ \033[1;31m"<<i<<".\033[0m            \t\t                                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│Student: "<<current->username<<"            \t\t                         │\n";
        cout<< "│Class: "<<current->Class<<"            \t\t                                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
        cout<< "│            \t\t\t                                 │\n";
        StrNode* temp = current->SubAndChap.head;
        while (temp != NULL) {
        cout <<"|"<< temp->SubName << ": ";
        IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << " ";
            temp2 = temp2->next;
            }
        temp = temp->next;
        cout << "                 \t\t\t\t\t |\n";
        }
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "|\U0001F3AF Marks: " <<current->ObtainedMarks << "/" << current->TotalMarks << "  \U0001F4C6 Date and Time: " << current->dateTime<<"\t |\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        current = current->Next;
        i++;
    }
}

void individualHistoryDisplay (string username) {
    StdQuizNode* current = top;
    ifstream y("Scores.txt");
    string line;
    bool check = false;
    while (getline(y, line))  {
        stringstream ss(line);
        string sub, name, C;
        getline(ss, sub, ',');
        getline(ss, name, ',');
        getline(ss, C, ',');
        if (name  == username) {
            check = true;
        }
    }
    y.close();
    if (check == false) {
        ShowPopup("There is no record for this specific student");
        return;
    }
    int i = 1;
    cout << "\n\n\U0001F464Student: " << username << endl<<endl; 
    while (current != NULL) {
        if (current->username == username) {
            //
        cout<<"\n\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│ \033[1;31m"<<i<<".\033[0m            \t\t                                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│Student: "<<current->username<<"            \t\t                         │\n";
        cout<< "│Class: "<<current->Class<<"            \t\t                                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
        cout<< "│            \t\t\t                                 │\n";
        StrNode* temp = current->SubAndChap.head;
        while (temp != NULL) {
        cout <<"|"<< temp->SubName << ": ";
        IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << " ";
            temp2 = temp2->next;
            }
        temp = temp->next;
        cout << "                 \t\t\t\t\t |\n";
        }
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "|\U0001F3AF Marks: " <<current->ObtainedMarks << "/" << current->TotalMarks << "  \U0001F4C6 Date and Time: " << current->dateTime<<"\t |\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        }
    current = current->Next;
    i++;
    }
}

void ClassHistoryDisplay (string Class) {
    StdQuizNode* current = top;
    ifstream y("Scores.txt");
    string line;
    bool check = false;
    while (getline(y, line))  {
        stringstream ss(line);
        string sub, name, C;
        getline(ss, sub, ',');
        getline(ss, name, ',');
        getline(ss, C, ',');
        if (C  == Class) {
            check = true;
        }
    }
    y.close();
    if (check == false) {
        ShowPopup("There is no record for this specific class");
        return;
    }
    int i = 1;
    cout << "\n\U0001F4D8CLASS: " << Class << endl << endl; 
    while (current != NULL) {
        if (current->Class == Class) {
    //
    cout<<"\n\n";
    cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
    cout<< "│ \033[1;31m"<<i<<".\033[0m            \t\t                                 │\n";
    cout<< "└────────────────────────────────────────────────────────────────┘\n";
    cout<< "│Student: "<<current->username<<"            \t\t                         │\n";
    cout<< "│Class: "<<current->Class<<"            \t\t                                 │\n";
    cout<< "└────────────────────────────────────────────────────────────────┘\n";
    cout<< "│Subjects and Chapters:\t\t\t\t                 │\n";
    cout<< "│            \t\t\t                                 │\n";
     StrNode* temp = current->SubAndChap.head;
        while (temp != NULL) {
        cout <<"| "<< temp->SubName << ": ";
        IntNode* temp2 = temp->Chapters->head;
            while (temp2 != NULL) {
            cout << temp2->ChapNumber;
            cout << " ";
            temp2 = temp2->next;
            }
        temp = temp->next;
        cout << "                 \t\t\t\t\t |\n";
        }
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "|\U0001F3AF Marks: " <<current->ObtainedMarks << "/" << current->TotalMarks << "  \U0001F4C6 Date and Time: " << current->dateTime<<"\t |\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";
        }
    current = current->Next;
    i++;
    }
}

void saveQuizHistory() {
    int countSub = 0, countChap = 0;
ofstream x("Scores.txt", ios:: app);
if (x.is_open()) {
    StdQuizNode* current = top;

    while( current != NULL) {
            StrNode* SC = current->SubAndChap.head;
            while (SC != NULL) {
            SC = SC->next;
            countSub++; // total number of subjects
            }
            SC = current->SubAndChap.head;
        
            x << countSub << "," << current->username << "," << current->Class; 
            countSub = 0;
                while (SC != NULL) {
                x << "," << SC->SubName;
                IntNode* chap = SC->Chapters->head;
                    while (chap != NULL) {
                        chap = chap->next;
                        countChap++; // total number of chapters
                    }
                x << "," << countChap;  // write the number of chapters in that one subject
                countChap = 0;
                chap = SC->Chapters->head;
                    while (chap != NULL) {
                    x << "," << chap->ChapNumber;
                    chap = chap->next;
                }
                SC = SC->next;
                }
        
    x << ", " << current->TotalMarks << "," << current->ObtainedMarks << "," << current->dateTime << endl;
    current = current->Next;
    }
    x.close();
}
}
void loadQuizHistory() {
    HistoryStack tempStack = HistoryStack();
    ifstream y("Scores.txt");
    if (y.is_open()) {
        string line;
        while (getline(y, line)) {
            
            string username, Class, Subject, Chapter, TotalMarks, ObtainedMarks, dateTime, subCount;
            int ot, ob;
            stringstream ss(line);
            getline(ss, subCount, ','); // number of subjects
            getline(ss, username, ',');
            getline(ss, Class, ',');
            int count = stoi(subCount);
            StrLinkedlist list = StrLinkedlist();
            for (int i = 0; i < count; i++) {
                getline(ss, Subject, ',');
                list.Insert(Subject);
                string countChap;
                getline(ss, countChap, ',');    // number of chapters in that one subject
                int count2 = stoi(countChap);
                IntLinkedlist* chapList = new IntLinkedlist();
                for (int j = 0; j < count2; j++) {
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
            push(username, Class, list, ot, ob, dateTime);
        }
        y.close();
    }
    y.close();
}


};