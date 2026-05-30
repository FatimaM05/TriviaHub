#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "HighScores.h"
#include <ctime>
// //file handling library below
#include <fstream>
#include <sstream>


using namespace std;

//--------------------------------------------Exception cases--------------------------------------------------//

bool isInteger(const string &inputstring){
    for( char const &c: inputstring){                   
        if(c < '0' || c > '9'){                         
            return false;
        }       
    }
    return true;
}
//converting the taken string input to integer
int stringToint(const string &inputstring){
    int number = 0;
    for( char const &c : inputstring){             
        number = number* 10 + ( c - '0');     //for moving the characters to left and the next character cmng in that place...then converting that character to integer
    }
    return number;
}

class NAryTree {
    public:
    Educational_Institute root;


    //default constructor
    NAryTree () {}
    //parameterized constructor
    NAryTree (string n, string a, string e) {
        root = Educational_Institute(n, a, e);
    }


//--------------------------------------insert methods are below---------------------------------------------//
    void InsertClass(string className) {
        root.classes.Insert(className);
    }
    void InsertSubjects(string className, string subjectName) { 
                ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        current->Node.subjects.Insert(subjectName);

    }

    void InsertChapters(string classNo, string subjectName, int chapterNumber) {
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != classNo) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        subjectHead->Node.chapters.Insert(chapterNumber);
    }
    void InsertQuestions(string classNo,string subjectName, int ChapterNo,string question, string OptionA,string OptionB,string OptionC,string OptionD,string CorrectOption, int priority ) 
    {
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != classNo) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        ChapterNode* chapterHead = subjectHead->Node.chapters.head;
        while (chapterHead->Node.ChapterNumber != ChapterNo) {
            chapterHead = chapterHead->Next;
        }
        chapterHead->Node.Questions.Insert(question, OptionA,OptionB,OptionC,OptionD,CorrectOption, priority);
        
    }
//--------------------------------------insert methods are above---------------------------------------------//



//--------------------------------------Delete methods are below---------------------------------------------//
    void DeleteClass(string ClassName){
    root.classes.Delete(ClassName);
    }

    void DeleteSubject(string className, string SubjectName){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        current->Node.subjects.Delete(SubjectName);
    }


    void DeleteChapter(string className, string subjectName, int ChapterNo){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
                SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }

        subjectHead->Node.chapters.Delete(ChapterNo);
    }


    void DeleteQuestion(string className, string subjectName, int ChapterNo,int QuestionNo){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        ChapterNode* chapterHead = subjectHead->Node.chapters.head;
        while (chapterHead->Node.ChapterNumber != ChapterNo) {
            chapterHead = chapterHead->Next;
        }
        chapterHead->Node.Questions.Delete(QuestionNo);
    }
//--------------------------------------Delete methods are above---------------------------------------------//




//--------------------------------------display methods are below---------------------------------------------//
    
    void DisplayClasses(){
        root.classes.displayAll();
    }
    void DisplaySubjects(string className){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        current->Node.subjects.displayAll();

    }
    void DisplayChapters(string className, string subjectName){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        subjectHead->Node.chapters.displayAll();
    }
    void DisplayQuestions(string classNo, string subjectName, int ChapterNo){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != classNo) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        ChapterNode* chapterHead = subjectHead->Node.chapters.head;
        while (chapterHead->Node.ChapterNumber != ChapterNo) {
            chapterHead = chapterHead->Next;
        }
        chapterHead->Node.Questions.displayAll();
    }
//--------------------------------------display methods are above---------------------------------------------//

//--------------------------------------GetSize of lists ----------------------------------------------------//
    int GetClassSize(){
        return root.classes.GetSize();
    }

    string Getclass(int num){
        ClassNode* c = root.classes.head;
        for(int i=1; i<num; i++){
            c = c->Next;
        }
        return c->Node.ClassName;
    }

    int GetSubjectsSize(string className){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        
        return current->Node.subjects.GetSize();
    }

    string GetSubject(string className,int num){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        for(int i=1; i<num; i++){
            subjectHead = subjectHead->Next;
        }

        return subjectHead->Node.getSubjectName();

    }

    int GetChaptersSize(string className, string subjectName){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        return subjectHead->Node.chapters.GetSize();
    }

    int GetChaptersNo(string className,string subjectName, int num){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        ChapterNode* chapter = subjectHead->Node.chapters.head;
        for(int i=1; i<num; i++){
            chapter = chapter->Next;
        }

        return chapter->Node.ChapterNumber;
    }

    int GetQuestionsSize(string className, string subjectName, int ChapterNo){
        ClassNode* current = root.classes.head;
        while (current->Node.ClassName != className) {
            current = current->Next;
        }
        SubjectNode* subjectHead = current->Node.subjects.head;
        while (subjectHead->Node.Name != subjectName) {
            subjectHead = subjectHead->Next;
        }
        ChapterNode* chapterHead = subjectHead->Node.chapters.head;
        while (chapterHead->Node.ChapterNumber != ChapterNo) {
            chapterHead = chapterHead->Next;
        }
        return chapterHead->Node.Questions.GetSize();
    }

//---------------------------------------Find Methods are below-----------------------------------------------//

    bool FindClass(string ClassName) {
    ClassNode* current = root.classes.head;
    while (current != nullptr && current->Node.ClassName != ClassName) {
        current = current->Next;
    }
        return current != nullptr;
    }

    bool FindSubject(string ClassName, string SubjectName) {
    ClassNode* currentClass = root.classes.head;
    while (currentClass != nullptr && currentClass->Node.ClassName != ClassName) {
        currentClass = currentClass->Next;
    }
    if (currentClass == nullptr) {
        return false;
    }

    SubjectNode* currentSubject = currentClass->Node.subjects.head;
    while (currentSubject != nullptr && currentSubject->Node.Name != SubjectName) {
        currentSubject = currentSubject->Next;
    }
    return currentSubject != nullptr;
    }

    bool FindChapter(string ClassName, string SubjectName, int ChapterNo) {
    ClassNode* current = root.classes.head;
    while (current != nullptr && current->Node.ClassName != ClassName) {
        current = current->Next;
    }
    if (current == nullptr) {
        return false;
    }

    SubjectNode* currentSubject = current->Node.subjects.head;
    while (currentSubject != nullptr && currentSubject->Node.Name != SubjectName) {
        currentSubject = currentSubject->Next;
    }
    if (currentSubject == nullptr) {
        return false;
    }

    ChapterNode* currentChapter = currentSubject->Node.chapters.head;
    while (currentChapter != nullptr && currentChapter->Node.ChapterNumber != ChapterNo) {
        currentChapter = currentChapter->Next;
    }

    return currentChapter != nullptr;
    }

    bool FindQuestion(string ClassName, string SubjectName, int ChapterNo, int QuestionNo) {

    ClassNode* currentClass = root.classes.head;
    while (currentClass != nullptr && currentClass->Node.ClassName != ClassName) {
        currentClass = currentClass->Next;
    }
    if (currentClass == nullptr) {
        return false;
    }

    SubjectNode* currentSubject = currentClass->Node.subjects.head;
    while (currentSubject != nullptr && currentSubject->Node.Name != SubjectName) {
        currentSubject = currentSubject->Next;
    }
    if (currentSubject == nullptr) {
        return false;
    }

    ChapterNode* currentChapter = currentSubject->Node.chapters.head;
    while (currentChapter != nullptr && currentChapter->Node.ChapterNumber != ChapterNo) {
        currentChapter = currentChapter->Next;
    }
    if (currentChapter == nullptr) {
        return false;
    }
    QuestionNode* currentQuestion = currentChapter->Node.Questions.head;
    while (currentQuestion != nullptr && currentQuestion->question.QuestionNo != QuestionNo) {
        currentQuestion = currentQuestion->Next;
    }
    return currentQuestion != nullptr;
    }

   //----------------------------------------Find Methods are above----------------------------------------------//
  
  
  //--------------------------------------Display entire tree method---------------------------------------------//
    void DisplayEntireTree() {    // Note: this method is gpt generated, didn't code it myself, remove if you would like since it is only for testing, we dont need to actually display the entire tree at any point, as far as i can think of anyways

        // Display Educational Institute details
        cout << "Educational Institute Details:" << endl;
        cout << "Name: " << root.getName() << endl;
        cout << "Address: " << root.getAddress() << endl;
        cout << "Email: " << root.getEmail() << endl;
        cout << endl;

        // Display all classes
        cout << "Classes:" << endl;
        ClassNode* classPtr = root.classes.head;
        while (classPtr != nullptr) {
            cout << "Class: " << classPtr->Node.ClassName << endl;

            // Display all subjects in the class
            SubjectNode* subjectPtr = classPtr->Node.subjects.head;
            while (subjectPtr != nullptr) {
                cout << "\tSubject: " << subjectPtr->Node.Name << endl;

                // Display all chapters in the subject
                ChapterNode* chapterPtr = subjectPtr->Node.chapters.head;
                while (chapterPtr != nullptr) {
                    cout << "\t\tChapter: " << chapterPtr->Node.ChapterNumber << endl;

                    // Display all questions in the chapter
                    QuestionNode* questionPtr = chapterPtr->Node.Questions.head;
                    while (questionPtr != nullptr) {
                        cout << "\t\t\tQuestion " << questionPtr->question.getQuestionNo() << ": " << questionPtr->question.getquestion() << endl;
                        cout << "\t\t\tOptions:" << endl;
                        cout << "\t\t\t\tA. " << questionPtr->question.getOptionA() << endl;
                        cout << "\t\t\t\tB. " << questionPtr->question.getOptionB() << endl;
                        cout << "\t\t\t\tC. " << questionPtr->question.getOptionC() << endl;
                        cout << "\t\t\t\tD. " << questionPtr->question.getOptionD() << endl;
                        cout << "\t\t\tCorrect Option: " << questionPtr->question.CorrectOption << endl;
                        cout << "\t\t\tPriority: " << questionPtr->question.priority << endl;
                        questionPtr = questionPtr->Next;
                    }

                    chapterPtr = chapterPtr->Next;
                }

                subjectPtr = subjectPtr->Next;
            }

            classPtr = classPtr->Next;
        }
    }
//--------------------------------------Display entire tree method---------------------------------------------//




//--------------------------------------Priority Quiz Method below, built in display---------------------------------------------//
void PriorityQuiz(string StudentName,string classNo, StrLinkedlist sub, int questionsCount) {

    int TotalQuestions = 0;
    int TotalScore = 0;
    int score;
    string strchoice;
    int choice;
    string option;
    string* CorrectOptions = new string[questionsCount];

    cout<<"\n\n\U0001F4DA Subjects: ";
    sub.displayList();

    // Find the class node
    ClassNode* current = root.classes.head;
    while (current != nullptr && current->Node.ClassName != classNo) {
        current = current->Next;
    }
    if (current == nullptr) {
        cout << "Class not found!" << endl;
        return ;
    }

    MinHeap heap;

    cout<<"\n\033[1;31mFor each question, please choose the correct option.\033[0m\n";
    // Loop through the subjects in the list
    StrNode* SubjectName = sub.head;
    while (SubjectName != nullptr) {
        SubjectNode* SubjectList = current->Node.subjects.head;
        
        // Find the subject node
        while (SubjectList != nullptr && SubjectList->Node.Name != SubjectName->SubName) {
            SubjectList = SubjectList->Next;
        }
        if (SubjectList == nullptr) {
            SubjectName = SubjectName->next;
            continue;
        }

        cout << "\nSubject: " << SubjectName->SubName << endl;
        score = 0;

        // Loop through the chapters for the subject
        IntNode* chapterNumber = SubjectName->Chapters->head;
        while (chapterNumber != nullptr) {
            ChapterNode* chapterList = SubjectList->Node.chapters.head;
            
            // Find the chapter node
            while (chapterList != nullptr && chapterList->Node.ChapterNumber != chapterNumber->ChapNumber) {
                chapterList = chapterList->Next;
            }
            if (chapterList == nullptr) {
                chapterNumber = chapterNumber->next;
                continue;
            }

            QuestionNode* questionList = chapterList->Node.Questions.head;
            int size = chapterList->Node.Questions.GetSize();

            // Create array of questions
            Question* arr = new Question[size];
            for (int i = 0; i < size; i++) {
                arr[i] = questionList->question;
                questionList = questionList->Next;
            }

            // Sort questions using MinHeap
            heap.SortHeap(arr, size);

            cout << "\nChapter No: " << chapterNumber->ChapNumber <<"\n\n";
            // Display questions
            for (int i = 0; i < questionsCount ; i++) {
                
                TotalQuestions++;
                CorrectOptions[i] = arr[i].CorrectOption;
                cout<<"\n\n";
                cout<<"Q."<<i+1<<" ";
                arr[i].displayH();

                    while(true){
                        cout<<"Choose: ";
                        cin >> strchoice;
                        if(isInteger(strchoice)){
                            choice = stringToint(strchoice);
                            break;
                        }
                        else{
                            cout<<"Invalid choice, Kindly enter from 1, 2, 3, 4"<<endl;
                            continue;
                        }

                    }
                    
              
                
                // Determine the chosen option
                switch (choice) {
                    case 1:
                        option = arr[i].OptionA;
                        break;
                    case 2:
                        option = arr[i].OptionB;
                        break;
                    case 3:
                        option = arr[i].OptionC;
                        break;
                    case 4:
                        option = arr[i].OptionD;
                        break;
                    default:
                        cout << "\nInvalid choice, Kindly choose from 1, 2, 3, 4" << endl;
                        i--;
                        TotalQuestions--;
                        continue;
                }

                // Check if the chosen option is correct
                if (option == arr[i].CorrectOption) {
                    score++;
                    TotalScore++;
                }

            }
            cout<<"\n";
            cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
            cout<< "│\t                    \033[1;31mCorrect Options\033[0m\t\t         │\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
            for(int i = 0; i < questionsCount; i++){
                cout<<i + 1<<"."<<" "<<CorrectOptions[i]<<endl;
            }

            delete[] arr;
            chapterNumber = chapterNumber->next;
        }

        cout << "\nQuiz for " << SubjectName->SubName << " is completed" << endl;
        cout << "Your score in this section is " << score << "/" << SubjectName->Chapters->GetSize() * questionsCount << endl;
        cout<<"=========================================================================\n";

        SubjectName = SubjectName->next;
    }
    
    cout << "\nYour Quiz has been completed" << endl;
    cout << "Your Total score in quiz is " << TotalScore << "/" << TotalQuestions <<endl<<endl;

    HistoryStack stack;
    stack.push(StudentName,classNo,sub,TotalQuestions,TotalScore,"");
    stack.saveQuizHistory();
}

//--------------------------------------Priority Quiz Method above, built in display---------------------------------------------//



// -------------------------------------Random Quiz Method Below--------------------------------------------------//

// Randomization will be done in two steps:1.Collect alllll questions from a subject; 2. Shuffle those questions

    // randomization started here

    void GenerateQuestions(string StudentName, string classChosen, StrLinkedlist subjects, int noOfQuestions)
    {

        cout<<"\n\n\U0001F4DA Subjects: ";
        subjects.displayList();
        cout<<"\n\033[1;31mFor each question, please choose the correct option.\033[0m\n\n";

        ClassNode *current = root.classes.head;
        while (current != nullptr && current->Node.ClassName != classChosen)
        {
            current = current->Next;
        }
        

        // Collecting the questions
        StrNode *TraverseSubParameter = subjects.head; // To traverse the parameter 'subjects'

        int totalscore = 0;
        int totalQuestions = 0;
        while (TraverseSubParameter != nullptr)
        {
            cout << TraverseSubParameter->GetSubName() << ":\n";
            // trying to find the subject object whose name is the same as present in our 'subjects' parameter
            SubjectNode *currentTwo = current->Node.subjects.head;
            while (currentTwo != NULL)
            {
                if (TraverseSubParameter->SubName == currentTwo->Node.Name)
                {
                    break;
                }
                currentTwo = currentTwo->Next;
            }
            QLinkedList FinalQuiz; // Linkedlist to collect the questions of all chapters for a subject
            IntNode *chapNo = (TraverseSubParameter->Chapters->head);
            // trynna find the chapter node whose chap no is in the current traversesubparameter's chapters intlinkedlist
            while (chapNo != NULL)
            {
                ChapterNode *ChapterOfSubNodeOfSubjects = currentTwo->Node.chapters.head;
                while (chapNo->GetChapNumber() != ChapterOfSubNodeOfSubjects->GetNode().GetChapterNumber())
                {
                    ChapterOfSubNodeOfSubjects = ChapterOfSubNodeOfSubjects->Next;
                }

                // now we have the required chapter of the subject whose question's we're currently collecting

                QLinkedList AllQuestions;                        // Linkedlist to collect all questions of a subject's chapter
                totalQuestions = totalQuestions + noOfQuestions; // updating the number of total questions by adding the 'NoOfQuestions' Parameter for each chapter
                QuestionNode *questionOfTheChapSelected = ChapterOfSubNodeOfSubjects->GetNode().Questions.head;
                while (questionOfTheChapSelected != nullptr)
                {
                    AllQuestions.Insert(questionOfTheChapSelected->GetQuestion());
                    questionOfTheChapSelected = questionOfTheChapSelected->GetNext();
                }
                // The current selected subject's one chapter's questions have been selected till here. We're gonna move them to an array and shuffle these questions and
                // insert the number of questions the user specified for each chapter in the finalquiz linkedlist
                int size = AllQuestions.GetSize();
                
                    QLinkedList cl2 = Shuffle(AllQuestions.getHead(), size);

                    QuestionNode *current123 = cl2.getHead();
                    
                    for (int i = 0; i < noOfQuestions; i++)
                    {
                        FinalQuiz.Insert(current123->GetQuestion());
                        current123 = current123->GetNext();
                    }
                
                // Now, we're gonna move on to the next chapter
                chapNo = chapNo->GetNext();
            }
            // one subject's all questions are collected till here. Now we'll shuffle them all and display them.
            // copying the finalQUiz linkedlist to an array
            int FinalSize = FinalQuiz.GetSize();
            if (FinalSize == 0)
            {
                cout << "No questions found for subject " << TraverseSubParameter->GetSubName() << "." << endl;
            }
            else
            {
                // Printing the quiz
                int score = 0;
                char answer;

                QuestionNode *q = FinalQuiz.getHead();
                int i = 1;
                int x = 0;
                while (q != nullptr)
                {
                    cout << endl
                         << "Q." << i << ". " << q->GetQuestion().getquestion() << endl
                         << "  1) " << q->GetQuestion().getOptionA() << "\t2) " << q->GetQuestion().getOptionB() << "\t3) " << q->GetQuestion().getOptionC() << "\t4) " << q->GetQuestion().getOptionD() << endl;
                start:
                    if (x == 1)
                    {
                        cout << "Please enter a number from 1 to 4.\n";
                        x = 0;
                    }
                    cin >> answer;
                    if (answer >= 'a' && answer <= 'z' || answer >= 'A' && answer <= 'Z' || answer <= '0' || answer >= '9')
                    {
                        x = 1;
                        goto start;
                    }
                    switch (answer)
                    {
                    case '1':
                        if (q->GetQuestion().getOptionA() == q->GetQuestion().getCorrectOption())
                        {
                            score++;
                            totalscore++;
                            cout << "Correct Answer. Your current score in " << TraverseSubParameter->GetSubName() << " is " << score << endl;
                        }
                        else
                        {
                            cout << "Incorrect answer. Correct answer is '" << q->GetQuestion().getCorrectOption() << "'.\n";
                        }
                        break;
                    case '2':
                        if (q->GetQuestion().getOptionB() == q->GetQuestion().getCorrectOption())
                        {
                            totalscore++;
                            score++;
                            cout << "Correct Answer. Your current score in " << TraverseSubParameter->GetSubName() << " is " << score << endl;
                        }
                        else
                        {
                            cout << "Incorrect answer. Correct answer is '" << q->GetQuestion().getCorrectOption() << "'.\n";
                        }
                        break;
                    case '3':
                        if (q->GetQuestion().getOptionC() == q->GetQuestion().getCorrectOption())
                        {
                            totalscore++;
                            score++;
                            cout << "Correct Answer. Your current score in " << TraverseSubParameter->GetSubName() << " is " << score << endl;
                        }
                        else
                        {
                            cout << "Incorrect answer. Correct answer is '" << q->GetQuestion().getCorrectOption() << "'.\n";
                        }
                        break;
                    case '4':
                        if (q->GetQuestion().getOptionD() == q->GetQuestion().getCorrectOption())
                        {
                            totalscore++;
                            score++;
                            cout << "Correct Answer. Your current score in " << TraverseSubParameter->GetSubName() << " is " << score << endl;
                        }
                        else
                        {
                            cout << "Incorrect answer. Correct answer is '" << q->GetQuestion().getCorrectOption() << "'.\n";
                        }
                        break;
                    default:
                        cout << "Invalid choice selected. Answer again." << endl;
                        goto start;
                        break;
                    }
                    q = q->GetNext();
                    i++;
                }
                cout << "\n\nQuiz for subject '" << TraverseSubParameter->GetSubName() << "' completed. You scored " << score << " out of " << FinalSize << "." << endl;
            }
            // Moving on to the next subject in the 'subjects' parameter

            TraverseSubParameter = TraverseSubParameter->GetNext();
        }
        cout << "\n\nQuiz completed. You scored " << totalscore << "/" << totalQuestions << "." << endl;
        
        HistoryStack stack;
        stack.push(StudentName,classChosen, subjects,totalQuestions, totalscore,"");
        stack.saveQuizHistory();
    }

    QLinkedList Shuffle(QuestionNode *LL, int size)
    {
        static mt19937 generator(static_cast<unsigned int>(std::time(0))); // Seed the random number generator
        uniform_int_distribution<int> distribution(1, 10);
        int a = distribution(generator);

        CircularLinkedList cl1;
        for (int i = 0; i < size; i++)
        {
            Question n = LL->GetQuestion();
            cl1.InsertNode(n);
            LL = LL->GetNext();
        }
        CircularLinkedList RandomizedCList = cl1.Josephus(a);
        QLinkedList Randomizedlist;
        CircularNode *current = RandomizedCList.First;
        for (int i = 0; i < size; i++)
        {
            Randomizedlist.Insert(current->GetData());
            current = current->GetNext();
        }
        return Randomizedlist;
    }

// -------------------------------------Random Quiz Method is above--------------------------------------------------//




//--------------------------------------File handling methods are below---------------------------------------------//
// NOTE: comma is being used as the primary separator in all the file handling so try not to use comma inside anything, like question statements or options or class name etc.
// MARK: FILE HANDLING FOR THE ENTIRE TREE
// identifiers:
// EI means educational institute
// C means class
// CS means class subject
// CSC means class subject chapter
// CSCQ means class subject chapter question
void saveEntireTree() {
    ofstream x("EducationalInstitute.txt"); // file created with the name as mentioned in the parenthesis in write stream
    if (x.is_open()) {
        x << "EI" << "," << root.getName() << "," << root.getAddress() << "," << root.getEmail() << endl; // educational institute details pasted into the file

        ClassNode* ClassHead = root.classes.head;
        while (ClassHead != NULL) {
            x << "C" << "," << ClassHead->Node.ClassName << endl; // class is pasted into the file

            SubjectNode* SubjectHead = ClassHead->Node.subjects.head;
            while (SubjectHead != NULL) {
                x << "CS" << "," << ClassHead->Node.ClassName << "," << SubjectHead->Node.Name << endl; // the subjects of that class are pasted into the file prefixed with the classNo.

                ChapterNode* chapterHead = SubjectHead->Node.chapters.head;
                while (chapterHead != NULL) {
                    x << "CSC" << "," << ClassHead->Node.ClassName << "," << SubjectHead->Node.Name << "," << chapterHead->Node.ChapterNumber << endl; // the chapters of that subject of that class are pasted into that file prefixed by both classNo and subjectName.

                    QuestionNode* QuestionsHead = chapterHead->Node.Questions.head;
                    while (QuestionsHead != NULL) {
                        x << "CSCQ" << "," << ClassHead->Node.ClassName << "," << SubjectHead->Node.Name << "," << chapterHead->Node.ChapterNumber << "," << QuestionsHead->question.getQuestionNo() << "," << QuestionsHead->question.getquestion() << "," << QuestionsHead->question.getOptionA() << "," << QuestionsHead->question.getOptionB() << "," << QuestionsHead->question.getOptionC() << "," << QuestionsHead->question.getOptionD() << "," << QuestionsHead->question.CorrectOption << "," << QuestionsHead->question.priority << endl; // the questions of that chapter of that subject of that class are pasted into the file prefixed by all 3 respectively
                        QuestionsHead = QuestionsHead->Next; // loop iterator for the inner most (questions) while loop
                    }
                    chapterHead = chapterHead->Next; // loop iterator for the second inner most (chapters) while loop
                }
                SubjectHead = SubjectHead->Next; // loop iterator for the third inner most (subject) while loop
            }
            ClassHead = ClassHead->Next; // loop iterator for the outer (classes) while loop
        }
    }
    x.close();
}

// we read the line using the commas as separator, put each string we read into variables, and use those variables to call our insert functions
void loadEntireTree() {
    ifstream y("EducationalInstitute.txt"); // opening the file in read stream
    if (y.is_open()) {

    string line; // variable to store whatever is read from the file
    string type; // variable to store the very first string of the line, basically whatever is b4 the coma
    string classNo, subNo, chpNo, quesNo, ques, a, b, c, d, correct, priority; // self explanatory


    while (getline(y, line)) // read the file until we run out of lines to read
    {  
        stringstream ss(line); // declare a string stream string to read through the file
        getline(ss, type, ','); // read the very first string b4 the comma and store in type variable
        
        if (type == "EI") { // if type is EI then the line is of the data for the educational institute
            string n, a, e;
            getline(ss, n, ',');
            getline(ss, a, ',');
            getline(ss, e, ',');
            Educational_Institute root = Educational_Institute(n,a,e);
        }
        else if (type == "C") { // if the type is C then the data is for a class
            getline(ss, classNo, ',');
            InsertClass(classNo);
        }
        else if (type == "CS") { // if the type is CS then the data is of a subject
            getline(ss, classNo, ',');
            getline(ss, subNo, ',');
            InsertSubjects(classNo, subNo);
        }
        else if (type == "CSC") { // if the type is CSC then the data is of a chapter
            getline(ss, classNo, ',');
            getline(ss, subNo, ',');
            getline(ss, chpNo, ',');
            int chpInt = stoi(chpNo);
            InsertChapters(classNo, subNo, chpInt);
        }
        else if (type == "CSCQ") { // if the type is CSCQ then the data is of a question
            getline(ss, classNo, ',');
            getline(ss, subNo, ',');
            getline(ss, chpNo, ',');
            int ch = stoi(chpNo); // string to int type casting
            getline(ss, quesNo, ',');
            int qNo = stoi(quesNo); // string to int type casting
            getline(ss, ques, ',');
            getline(ss, a, ',');
            getline(ss, b, ',');
            getline(ss, c, ',');
            getline(ss, d, ',');
            getline(ss, correct, ',');
            getline(ss, priority, ',');
                int pri;
                try {
                    pri = stoi(priority);
                } catch (const invalid_argument& e) {
                    cerr << "Invalid priority: " << priority << endl;
                    continue;
                }
            InsertQuestions(classNo, subNo, ch, ques, a, b, c, d, correct, pri);
        }
    }
    }

    y.close();
}

void deleteEntireTree () {
    remove("EducationalInstitute.txt");
    cout << "The EducationalInstitute.txt file has been deleted from the folder, start creating the tree from scratch ma lad" << endl;
}
//--------------------------------------File handling methods are above---------------------------------------------//

};


