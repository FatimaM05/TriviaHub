#include <iostream>
#include "Users.h"
string studentclass;
string UserType;
string Studentname;
string Adminname;
using namespace std;
//--------------------------------------------Display cmd--------------------------------------------------------//
void DisplayLoginDashBoard(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tLOGIN DASHBOARD\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------"; 
};

void DisplayCredentialsDashBoard(){
    cout<<"\t\t\t\t\t     ___________________________________________";
    cout<<"\n\t===================================||\t\tCREDENTIALS DASHBOARD\t\t||=======================================";
    cout<<"\n\t\t\t\t\t     -------------------------------------------"; 
};

void DisplayStudentPortal(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tSTUDENT PORTAL\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------"; 
};

void DisplayAdminPortal(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tADMIN PORTAL\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------"; 
};

void DisplayPriorityQuiz(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tPRIORITY QUIZ\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------"; 
};

void DisplayRandomQuiz(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tRANDOM QUIZ\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------"; 
};

void DisplayQuizHistory(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tQUIZ HISTORY\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------"; 
};

void DisplayHighScores(){
    cout<<"\t\t\t\t\t            ____________________________________";
    cout<<"\n\t      ====================================||\t\tHIGH SCORES\t\t||=========================================";
    cout<<"\n\t\t\t\t\t            ------------------------------------\n\n\n"; 
};

//------------------------------------------------Display cmd----------------------------------------------//


//----------------------------------------------Retrieve Methods--------------------------------------------//

//used at various places in student,admin access functions...to check the valid input and within the bounds of data entered
//inputs are needed in int...our parameters are in string. in the display method in my function to choose form menu
//there shld be int input and in function passing the number holding the string value shld be passed i.e 1.bio 2. maths ans so on

//chose str input not int...cuz for exception handling..for if user give other than int value it can show error


bool RetrieveClass(NAryTree &tree,int &classNo,string  &strclassno){ 
    while(true){
        cout<<"\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│\t                    \033[1;31mCLASSES\033[0m\t\t                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
        tree.DisplayClasses();
        int size = tree.GetClassSize();                 
        cout<<"\nChoose the class: ";
        cin>>strclassno;                            
            // exception
                if(!isInteger(strclassno)){                                         
                    ShowPopup("Invalid choice. Please enter the correct choice.");     
                    continue;
                }
                 classNo = stringToint(strclassno);                          //converting to select that number from display menu
            // exception end
        if(classNo <= 0 || classNo > size){                                 
            ShowPopup("Invalid choice. Please enter the correct choice.");
            return false;                                                           //this actually starts loop again. and ask user to enetr input again
        }
        else{
            return true;                                             
        }
    }
}
bool RetrieveSubject(NAryTree &tree,string Class,int &subjectNo, string  &strSubNo){
    while(true){
        cout<<"\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│\t                    \033[1;31mSUBJECTS\033[0m\t\t                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
        tree.DisplaySubjects(Class);
        int subsize = tree.GetSubjectsSize(Class);
        cout<<"\nChoose the subject: "<<endl;
        cin>>strSubNo;
        // exception
            if(!isInteger(strSubNo)){
                ShowPopup("Invalid choice. Please enter the correct choice.");
                continue;
            }
            subjectNo = stringToint(strSubNo);
        // exception end
        if(subjectNo <= 0 || subjectNo > subsize){
            ShowPopup("Invalid choice. Please enter the correct choice.");
            return false;
        }
        else{
            return true;
        }
    }
}
bool RetrieveChapter(NAryTree &tree,string Class, string Subject,int &chapterNo, string &strChpNo){
    while(true){
        cout<<"\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│\t                    \033[1;31mCHAPTERS\033[0m\t\t                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
        tree.DisplayChapters(Class,Subject);
        int chpsize = tree.GetChaptersSize(Class,Subject);
        cout<<"\nChoose the chapter: ";
        cin>>strChpNo;
            // exception
                if(!isInteger(strChpNo)){
                ShowPopup("Invalid choice. Please enter the correct choice.");
                continue;
                }
                chapterNo = stringToint(strChpNo);
            // exception end
        if( chapterNo <= 0 || chapterNo > chpsize){
            ShowPopup("Invalid choice. Please enter the correct choice.");
            return false;
        }
        else{
            return true;
        }
    }
}
//-----------------------------------------Retrieve Methods are above------------------------------------------//


//-------------------------------------------------Authentication------------------------------------------------//

//authetication of user details...
bool Authentication(){
    while (true) {
        
        string choice;                                              //for exception handling taking input string
        int dummychoice;
        system("cls");
        DisplayCredentialsDashBoard();
            SetConsoleOutputCP(CP_UTF8);
            cout<<"\n\n\n";
            cout<< "┌───────────────────────────────────────────┐\n"; 
            cout<< "│                  \033[1;31mMenu\033[0m                     │\n";
            cout<< "└───────────────────────────────────────────┘\n";  
            cout<< "│                                           │\n";
            cout<< "│1.Sign Up                                  │\n"; 
            cout<< "│                                           │\n";
            cout<< "│2.Login                                    │\n"; 
            cout<< "│                                           │\n";
            cout<< "│3.Forgot Password                          │\n";
            cout<< "│                                           │\n";
            cout<< "│4. Exit                                    │\n";
            cout<< "└───────────────────────────────────────────┘\n";                           
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        //exception for the choice if entered other than numeric, shows invalid input.
        if(!isInteger(choice)){
        ShowPopup("Invalid choice. Please enter the correct choice.");
        continue;
        }
        dummychoice = stringToint(choice);
        //exception end
        switch (dummychoice) {
            case 1: {
                //Signing Up Case Handling
                string username, password, email, stdClass;
                cout <<"\nEnter your username: ";
                cin.ignore();
                getline(cin, username);
                cout <<"\nEnter your password: ";
                cin >> password;
                cout <<"\nEnter your email: ";
                cin >> email;
                if(UserType == "STD"){
                cout <<"\nEnter your class: "; 
                cin >> stdClass;
                }
                studentclass = stdClass;
                if (signup(UserType,username, password, email, stdClass)) {
                    // cout<<"Signup Successful"<<endl;
                }
                break;
            }
            case 2: {
                //login
                string username, password;
                cout <<"\nEnter your username: ";
                cin.ignore();
                getline(cin, username);
                Studentname = username;
                Adminname = username;
                cout <<"\nEnter your password: ";
                cin >> password;
                if(UserType == "Admin"){
                    if(loginAdmin(username, password)){
                        return true;
                    }
                    else{
                        continue;
                    }  
                }
                else if(UserType == "STD"){ 
                    if(loginStd(username, password)) {

                    return true;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    return false;
                }
                break;
            }
            case 3: {
                //Forgetting Password
                string email;
                cout <<"\nEnter your registered email: ";
                cin >> email;
                if(forgotPassword(email)){
                    return false;
                }
                else{
                    break;
                }
                
            }
            case 4:
                cout <<"\nExiting program..." << endl;
                return false;
            default:
                ShowPopup("Invalid choice. Please enter the correct choice.");
        }
    }
    return false;
}    
//----------------------------------------------------END-------------------------------------------------------//


//-----------------------------------------------Student Access-------------------------------------------------//
void StudentAccess(NAryTree& tree){
    //If authentciation fails. Return to the main menu...
    if(!Authentication()){
        return;
    }
    while(true){   
        int score;                    
        int dummychoice;
        string choice;
        Again:
        system("cls");
        DisplayStudentPortal();
        Student student(returnStudent(Studentname));
        string UserN = Studentname;
        string UserC = student.StdClass;
        cout<<"\n\n\U0001F464 ";
        cout<<UserN;
        cout<<"\n\U0001F4D8 Class ";
        cout<<UserC;
        cout<<"\n\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│\t                    \033[1;31mMenu\033[0m\t\t                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│1. Attempt a Random Quiz\t\t\t\t\t │\n"; 
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│2. Attempt a Priority Quiz\t\t\t\t\t │\n"; 
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│3. Change Username\t\t\t\t\t\t │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│4. View Quiz History\t\t\t                         │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│5. View Highest Scores\t\t\t                         │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│6. Return to Main Menu\t\t\t                         │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";  
        cout<< "\nEnter Your choice: ";
        cin>>choice;
        //exception
            if(!isInteger(choice)){
                ShowPopup("Invalid choice. Please enter the correct choice.");
                continue;
            }
            dummychoice = stringToint(choice);
        //exception end
        //==============Change UserName==================
        if(dummychoice == 3){
            char ChangeUsername;
            string OldUsername, Password, NewUsername;
            cout <<"\nEnter your old username: ";
            cin.ignore();
            getline(cin, OldUsername);
            cout <<"\nEnter your Password: ";
            cin>>Password;
            cout <<"\nEnter the New Username: ";
            cin.ignore();
            getline(cin, OldUsername);
            if (editUserName(OldUsername, Password, NewUsername)){
                break;
            }
            else{
                continue;
            }
        }
        else if(dummychoice == 1 || dummychoice == 2){

                StrLinkedlist SubjectsList;                     
                string Class, Subject, strSubNo, strChpNo;
                int NoOfQuestions, Chapter, subjectNo, chapterNo;
                char choice;
                
                //student object to get his/her class automatically which he/she entered during signup
                Student student(returnStudent(Studentname));
                Class = student.StdClass;
                
                int size = tree.GetSubjectsSize(Class);
                if(size == 0){
                    ShowPopup("Quiz can't be taken, No Subjects Available in your class");
                    continue;
                }
                else{
                    //5-10-15-20 quiz
                    string QuestionsChoice;
                    int IntQchoice;
                    cout<<"\nPlease select your preferred quiz length: ";
                    cout<<"\n1. 05 Questions."<<endl;
                    cout<<"2. 10 Questions."<<endl;
                    cout<<"3. 15 Questions."<<endl;
                    cout<<"4. 20 Questions."<<endl;
                    cout<<"\nEnter your choice: ";
                    cin>>QuestionsChoice;;
                    //exception
                    if(!isInteger(QuestionsChoice)){
                        ShowPopup("Invalid choice. Please enter valid input!");
                        continue;
                    }
                    IntQchoice = stringToint(QuestionsChoice);
                    //
                    if(IntQchoice == 1){ NoOfQuestions = 5; }
                    else if(IntQchoice == 2){ NoOfQuestions = 10; }
                    else if(IntQchoice == 3){ NoOfQuestions = 15; }
                    else if(IntQchoice == 4){ NoOfQuestions = 20; }
                    else{ ShowPopup("Invalid choice. Please enter valid input!");
                        continue;}
                    //
                        //do-while loop for the first time it asks for sub and chp and then ask user if to add more or not
                    do{ 
                        //displays the subject menu and asks user to select the sub from menu..stores back in subject 
                        int size = tree.GetSubjectsSize(Class);
                        if(size == 0){
                            ShowPopup("No Subjects Available in the selected Class");
                            goto Again;
                        }
                        else{
                            //subjectNo = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                            bool ok = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                            if(!ok){
                                goto Again;
                            }
                            Subject = tree.GetSubject(Class,subjectNo);
                            SubjectsList.Insert(Subject);

                            //creating the pointer and retrieving the head....after that the next subject will be 
                            //added in the next of the first subject entered ..through traverse
                            StrNode* SubjectNode = SubjectsList.head;
                            while(SubjectNode->next != nullptr){
                                SubjectNode = SubjectNode->next;
                            }
                            //This do-while loop is for chapter to add first time and ask the next time
                            do{
                                int chpsize = tree.GetChaptersSize(Class,Subject);
                                if(size == 0){
                                    ShowPopup("No Chapters Available in the selected Subject");
                                    break;
                                }
                                ///this loop is for question checking, break where qs in respective chp are less then 
                                ///or equal to given "No.ofqs" by student. Break will take him out of this loop
                                ///and will ask to add select another chapter
                                    while(true){
                                        bool chpok = RetrieveChapter(tree, Class,Subject,chapterNo,strChpNo);
                                        if(!chpok){
                                            break;
                                        }
                                        Chapter = tree.GetChaptersNo(Class,Subject,chapterNo);
                                        if(tree.GetQuestionsSize(Class,Subject,Chapter) == 0 ){
                                            cout<<"\nNot enough questions are available in this chapter! Please choose another chapter!"<<endl;
                                            system("pause");
                                            break;
                                        }
                                        else{
                                            SubjectNode->Chapters->Insert(Chapter);
                                            break;
                                        }
                                    }
                                ///loop for qs checking ends here
                                cout<<"\nDo you want to add another chapter \nPress (Y/y) for \"Yes\" and any other key for No"<<endl;
                                cin>>choice;
                            }while(choice == 'Y' || choice == 'y');
                            //chapter do-while loop ends here
                            cout<<"\nDo you want to add another subject \nPress (Y/y) for \"Yes\" and any other key for No"<<endl;
                            cin>>choice;
                        }
                    }while(choice == 'Y' || choice == 'y');
                    //subject do-while loop ends here
                    if(dummychoice == 1){
                        system("cls");
                        DisplayRandomQuiz();
                        cout<<"\n\n";
                        Student student(returnStudent(Studentname));
                        string UserN = Studentname;
                        string UserC = student.StdClass;
                        cout<<"\n\n\U0001F464 ";
                        cout<<UserN;
                        cout<<"\n\U0001F4D8 Class ";
                        cout<<UserC;
                        cout<<"\n\n";
                        tree.GenerateQuestions(Studentname,Class,SubjectsList,NoOfQuestions);
                        ShowPopup("Your Quiz has been successfully saved.");
                        system("pause");
                        continue;
                        //End Randomized Quiz
                        }
                    else{
                        system("cls");
                        DisplayPriorityQuiz();
                        cout<<"\n\n";
                        Student student(returnStudent(Studentname));
                        string UserN = Studentname;
                        string UserC = student.StdClass;
                        cout<<"\n\n\U0001F464 ";
                        cout<<UserN;
                        cout<<"\n\U0001F4D8 Class ";
                        cout<<UserC;
                        cout<<"\n\n";
                        tree.PriorityQuiz(Studentname,Class,SubjectsList,NoOfQuestions);
                        ShowPopup("Your Quiz has been successfully saved.");
                        system("pause");
                        continue;
                        //End Priority Quiz
                    }
                }
                
        }
        else if(dummychoice == 4){

            HistoryStack stack;
            stack.loadQuizHistory();

            while(true){

                system("cls");
                DisplayQuizHistory();
                cout<<"\n\n";
                cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
                cout<< "│                        \033[1;31mQuiz History\033[0m\t\t                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│1. View your Quiz History\t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│2. View Class Quiz History\t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│3. Exit\t\t\t\t\t\t\t │\n";
                cout<< "│            \t\t\t                                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n";  
                cout<<"\nEnter your choice: ";
                cin>>choice;

                //exception
                if(!isInteger(choice)){
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }
                dummychoice = stringToint(choice);
                //exception end

                // Showing Student His own Quiz History
                if(dummychoice == 1){

                    system("cls");
                    DisplayQuizHistory();
                    stack.individualHistoryDisplay(Studentname);
                    system("pause");
                    continue;
                }
                // Showing Student His Class Quiz History
                else if(dummychoice == 2){

                    system("cls");
                    DisplayQuizHistory();
                    Student student = returnStudent(Studentname);
                    stack.ClassHistoryDisplay(student.StdClass);
                    system("pause");
                    continue;
                }
                else if(dummychoice == 3){
                    //Exit
                    break;
                }
                else{
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }

            }
        }
        else if(dummychoice == 5){

            while(true){

                system("cls");
                DisplayHighScores();
                cout<<"\n\n";
                cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
                cout<< "│                        \033[1;31mHigh Scores\033[0m\t\t                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│1. View your Top Scores   \t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│2. View Class Top Scores  \t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│3. Exit\t\t\t\t\t\t\t │\n";
                cout<< "│            \t\t\t                                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n";  
                cout<<"\nEnter your choice: ";
                cin>>choice;

                //exception
                if(!isInteger(choice)){
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }
                dummychoice = stringToint(choice);
                //exception end

                // Showing Student His own Top Scores
                if(dummychoice == 1){

                    system("cls");
                    DisplayHighScores();
                    displayStudentScores(Studentname);
                    continue;
                }
                // Showing Student His Class Top Scores
                else if(dummychoice == 2){

                    system("cls");
                    DisplayHighScores();
                    Student student = returnStudent(Studentname);
                    displayClassScores(student.StdClass);
                    continue;
                }
                else if(dummychoice == 3){
                    //Exit
                    break;
                }
                else{
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }

            }

        }
        else if(dummychoice == 6){
            //EXIT
            break;
        }
        else{
            ShowPopup("Invalid choice. Please enter valid input!");
        }
    }
}
//----------------------------------------------------END-------------------------------------------------------//



//--------------------------------------------------Admin Access-------------------------------------------------//
void AdminAccess(NAryTree& tree){
    //Same verification if user not found; Return to main menu
    if(!Authentication()){
        return ;
    }
    while(true){
        int dummychoice;
        string choice;
        string AdminName;
        system("cls");
        DisplayAdminPortal();
        cout<<"\n\n";
        Administrator adm(returnAdministrator(Adminname));
        string UserN = Adminname;
        cout<<"\n\n\U0001F464 ";
        cout<<UserN;
        cout<<"\n\U0001F4E9 ";
        cout<<adm.getEmail();
        cout<<"\n\n";
        cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
        cout<< "│\t                    \033[1;31mMenu\033[0m\t\t                 │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│1. Add Class\t\t\t2. Delete Class                  │\n"; 
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│3. Add Subject\t\t\t4. Delete Subject                │\n"; 
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│5. Add Chapter\t\t\t6. Delete Chapter                │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│7. Add Question\t\t8. Delete Question               │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│9. View Quiz History\t\t10. View Hightest Scores\t │\n";
        cout<< "│            \t\t\t                                 │\n";
        cout<< "│11. Return to Main Menu\t\t\t\t         │\n";
        cout<< "└────────────────────────────────────────────────────────────────┘\n";  
        cout<<"\nEnter your choice: ";
        cin>>choice;
        //exception
            if(!isInteger(choice)){
                ShowPopup("Invalid choice. Please enter valid input!");
                continue;
            }
            dummychoice = stringToint(choice);
        //exception end
        if(dummychoice == 1){
            //==============Inserting Class==================
            //displays class menu just incase to know classes...a check if class entered already exists else enter the class
            //donnut know if shld add exception handling in this case too...like to add only numeric classes or not
            string ClassId;
            cout<<"\n";
            cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
            cout<< "│\t                    \033[1;31mClasses\033[0m\t\t                 │\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
            tree.DisplayClasses();
            cout<<"\nEnter new Class: ";
            cin>>ClassId;
            if(ClassId == "0"){
                continue;
            }
            if(tree.FindClass(ClassId)){
                ShowPopup("The class you entered already exists!");
            }
            else{
                tree.InsertClass(ClassId);
                ShowPopup("\nClass has been added successfully!");
            }
        }
        else if(dummychoice == 2){
            //==============Deleting Class=================
            string ClassId;
            cout<<"\n";
            cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
            cout<< "│\t                    \033[1;31mCLASSES\033[0m\t\t                 │\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
            tree.DisplayClasses();
            cout<<"\nChoose the class: ";
            cin>> ClassId;
            if(ClassId == "0"){
                continue;
            }
            if(!tree.FindClass(ClassId)){
                ShowPopup("The class you entered does not exist!");
                continue;
            }
            else{
                cout<<"\nAre you sure you want to delete the selected class?\nPress (Y/y) for \"Yes\" and any other key for No "<<endl;
                char c;
                cin>>c;
                if(c == 'Y' || c == 'y'){
                    tree.DeleteClass(ClassId);
                    ShowPopup("\nClass has been deleted successfully!");
                }else{
                    ShowPopup("\nCouldn't delete Class!");
                    continue;
                }
            }
        }
        else if(dummychoice == 3){
            //==============Inserting Subject==================
            //retrieves the class from menu...displays subject just for show incase...find subjects help
            //avoiding etering same subject more than one time for same class
            string Class, Subject, strclassno;
            int classNo;
            bool classok = RetrieveClass(tree,classNo, strclassno);
            if(!classok){
                    continue;
            }
            Class = tree.Getclass(classNo);
            cout<<"\n";
            cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
            cout<< "│\t                    \033[1;31mSUBJECTS\033[0m\t\t                 │\n";
            cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
            tree.DisplaySubjects(Class);
            cout<<"\nEnter the new subject: "<<endl;
            cin.ignore();
            getline(cin, Subject);
            //
            if(Subject == "0"){
                continue;
            }
            if(tree.FindSubject(Class,Subject)){
                ShowPopup("The subject you entered already exists!");
                continue;
            }   
            else{
                tree.InsertSubjects(Class,Subject);
                ShowPopup("Subject has been added successfully to subjects!");
            }
            
            
        }
        else if(dummychoice == 4){
            //==============Deleting Subject==================
            string Class, Subject,strclassno, strSubNo;
            int classNo ,subjectNo;
            //Class
            bool classok = RetrieveClass(tree,classNo, strclassno);
            if(!classok){
                    continue;
            }
            Class = tree.Getclass(classNo);
            //subject
            int size = tree.GetSubjectsSize(Class);
            if(size == 0){
                ShowPopup("No Subjects Available in the selected Class");
                continue;
            }
            else{
                bool ok = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                if(!ok){
                    continue;
                }
                Subject = tree.GetSubject(Class,subjectNo);
                //deletion
                cout<<"\nAre you sure you want to delete the selected subject?\nPress (Y/y) for \"Yes\" and any other key for No"<<endl;
                char c;
                cin>>c;
                if(c == 'Y' || c == 'y'){
                    tree.DeleteSubject(Class,Subject);
                    ShowPopup("Subject has been deleted successfully!");
                }else{
                    ShowPopup("Couldn't delete Subject!");
                    continue;
                }
            }
            
        }
        else if(dummychoice == 5){
        //==============Inserting Chapters==================
            string Class, Subject, Chapter, strclassno, strSubNo;
            int classNo, subjectNo, ChapterNo;
            //class
            bool classok = RetrieveClass(tree,classNo, strclassno);
            if(!classok){
                    continue;
            }
            Class = tree.Getclass(classNo);
            //subject
            int size = tree.GetSubjectsSize(Class);
            if(size == 0){
                ShowPopup("No Subjects Available in the selected Class");
            }
            else{
                //subjectNo = RetrieveSubject(tree, Class, strSubNo);
                bool ok = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                if(!ok){
                    continue;
                }
                Subject = tree.GetSubject(Class,subjectNo);
                cout<<"\n";
                cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
                cout<< "│\t                    \033[1;31mCHAPTERS\033[0m\t\t                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
                tree.DisplayChapters(Class,Subject);
                //entering chp...sees if its numeric or not....already exists or not 
                cout<<"Enter the new chapter you want to add: ";
                cin>>Chapter;
                if(Chapter == "0"){
                    continue;
                }
                if(!isInteger(Chapter)){
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }
                ChapterNo = stringToint(Chapter);
                if(tree.FindChapter(Class,Subject,ChapterNo)){
                ShowPopup("The chapter you entered already exists!");
                }
                else{
                tree.InsertChapters(Class,Subject,ChapterNo);
                ShowPopup("Chapter has been added successfully!");
                }
            }
        }
        else if(dummychoice == 6){
        //==============Deleting Chapters==================
            string Class, Subject,strclassno, strSubNo, strChpNo;
            int classNo, subjectNo, chapterNo,Chapter;
            //class
            bool classok = RetrieveClass(tree,classNo, strclassno);
            if(!classok){
                    continue;
            }
            Class = tree.Getclass(classNo);
            //Subject
            int size = tree.GetSubjectsSize(Class);
            if(size == 0){
                ShowPopup("No Subjects Available in the selected Class");
            }
            else{
                //subjectNo = RetrieveSubject(tree, Class, strSubNo);
                bool ok = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                if(!ok){
                    continue;
                }
                Subject = tree.GetSubject(Class,subjectNo);

                //Chapter
                size = tree.GetChaptersSize(Class,Subject);
                if(size == 0){
                    ShowPopup("No Chapters Available in the selected Subject");
                }else{
                    bool chpok = RetrieveChapter(tree, Class,Subject,chapterNo,strChpNo);
                    if(!chpok){
                        continue;
                    }
                    Chapter = tree.GetChaptersNo(Class,Subject,chapterNo);
                    cout<<Chapter;
                    //deletion
                    cout<<"\nAre you sure you want to delete the selected chapter?\nPress (Y/y) for \"Yes\" and any other key for No"<<endl;
                    char c;
                    cin>>c;
                    if(c == 'Y' || c == 'y'){
                        tree.DeleteChapter(Class, Subject, Chapter);
                        ShowPopup("Chapter has been deleted successfully!");
                    }else{
                        ShowPopup("Couldn't Delete Chapter! ");
                        continue;
                    }
                }
            } 
        }
        else if(dummychoice == 7){
        //==============Inserting Questions==================
            string Class, Subject,strclassno, strSubNo, strChpNo;
            int classNo, subjectNo, Chapter, chapterNo, inputqsNo;
            //class
            bool classok = RetrieveClass(tree,classNo, strclassno);
            if(!classok){
                    continue;
            }
            Class = tree.Getclass(classNo);
            //subject
            int size = tree.GetSubjectsSize(Class);
            if(size == 0){
                ShowPopup("No Subjects Available in the selected Class");
            }
            else{
                //subjectNo = RetrieveSubject(tree, Class, strSubNo);
                bool ok = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                if(!ok){
                    continue;
                }
                Subject = tree.GetSubject(Class,subjectNo);

                //Chapter
                size = tree.GetChaptersSize(Class,Subject);
                if(size == 0){
                    ShowPopup("No Chapters Available in the selected Subject");
                }
                else{
                    bool chpok = RetrieveChapter(tree, Class,Subject,chapterNo,strChpNo);
                    if(!chpok){
                        continue;
                    }
                    Chapter = tree.GetChaptersNo(Class,Subject,chapterNo);

                    //parameters for qs alone
                    string Question, CorrectAnswer, options[4];
                    int priority;
                    //QsNo. is auto incremented..taking direct to next qs input
                    cout<<"Enter the new Question: ";
                    cin.ignore();
                    getline(cin, Question);
                    //loop to take all options together one by one
                    for(int i = 0 ; i< 4; i++){
                    cout<<"Enter the option" << i+1 <<": ";
                    getline(cin, options[i]);
                    }
                    cout<<"Enter the correct answer of the question: "<<endl;
                    getline(cin, CorrectAnswer);
                    cout<<"Enter the priority of the question: ";
                    cin>>priority;
                    tree.InsertQuestions(Class, Subject, chapterNo, Question, options[0], options[1], options[2], options[3], CorrectAnswer, priority);
                    ShowPopup("The Question has been added successfully!");
                }
            }
        }
        else if (dummychoice == 8){
        //==============Deleting Questions==================
            string Class, Subject,strclassno, strSubNo, strChpNo,strQuestionNo;
            int classNo, subjectNo, Chapter, chapterNo, questionNo;
            //class
            bool classok = RetrieveClass(tree,classNo, strclassno);
            if(!classok){
                continue;
            }
            Class = tree.Getclass(classNo);
            //subject
            int size = tree.GetSubjectsSize(Class);
            if(size == 0){
                ShowPopup("No Subjects Available in the selected Class");
            }
            else{
                //subjectNo = RetrieveSubject(tree, Class, strSubNo);
                bool ok = RetrieveSubject(tree, Class,subjectNo, strSubNo);
                if(!ok){
                    continue;
                }
                Subject = tree.GetSubject(Class,subjectNo);

                //Chapter
                size = tree.GetChaptersSize(Class,Subject);
                if(size == 0){
                    ShowPopup("No Chapters Available in the selected Subject");
                }
                else{
                    bool chpok = RetrieveChapter(tree, Class,Subject,chapterNo,strChpNo);
                    if(!chpok){
                        continue;
                    }
                    Chapter = tree.GetChaptersNo(Class,Subject,chapterNo);
                    do{
                        size = tree.GetQuestionsSize(Class,Subject,Chapter);
                        if(size == 0){
                            ShowPopup("No Questions Available in the selected Chapter");
                        }
                        else{
                            cout<<"\n";
                            cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
                            cout<< "│\t                    \033[1;31mQUESTIONS\033[0m\t\t                 │\n";
                            cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
                            //displays qs to choose the qs number
                            tree.DisplayQuestions(Class,Subject,Chapter);
                            cout<<"\nEnter the Question No. to delete : ";
                            cin>>strQuestionNo;
                            // some numeric checking too
                            if(!isInteger(strQuestionNo)){
                                ShowPopup("Invalid choice. Please enter valid input!");
                                continue;
                            }
                            questionNo = stringToint(strQuestionNo);
                            if(!tree.FindQuestion(Class,Subject,Chapter,questionNo)){
                                ShowPopup("This Question does not exist!");
                                break;
                                
                            }
                            else{
                                cout<<"\nAre you sure you want to delete the selected subject?\nPress (Y/y) for \"Yes\" and any other key for No"<<endl;
                                char c;
                                cin>>c;
                                if(c == 'Y' || c == 'y'){
                                    tree.DeleteQuestion(Class, Subject, Chapter, questionNo);
                                    ShowPopup("The Question has been deleted successfully!");
                                }
                                else{
                                    ShowPopup("Couldn't delete Question!");
                                    continue;
                                }
                                cout<<"\nDo you want to delete another question?\nPress (Y/y) for \"Yes\" and any other key for No ";
                                char choice;
                                cin>>choice;
                                if(choice != 'y' && choice != 'Y'){
                                    break;
                                }

                            }
                        }    
                    }
                    while(true);
                }
            
            }
        }
        else if(dummychoice == 9){
            HistoryStack stack;
            stack.loadQuizHistory();

            while(true){

                system("cls");
                DisplayQuizHistory();
                cout<<"\n\n";
                cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
                cout<< "│                        \033[1;31mQuiz History\033[0m\t\t                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│1. View Class Quiz History\t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│2. View Student Quiz History\t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│3. View All Time Quiz History\t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│4. Exit\t\t\t\t\t\t\t │\n";
                cout<< "│            \t\t\t                                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n";  
                cout<<"\nEnter your choice: ";
                cin>>choice;

                //exception
                if(!isInteger(choice)){
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }
                dummychoice = stringToint(choice);
                //exception end

                // Showing Admin Class Quiz History
                if(dummychoice == 1){
                    
                    string Class,strclassno;
                    int classNo;
                    // Class
                    bool ok = RetrieveClass(tree, classNo, strclassno);
                    if(!ok){
                        continue;
                    }
                    Class = tree.Getclass(classNo);
                    //Displaying History of that Class
                    system("cls");
                    DisplayQuizHistory();
                    stack.ClassHistoryDisplay(Class);
                    cout<<"\n\n";
                    system("pause");
                    continue;
                }
                // Viewing Specific Student's Quiz History
                else if(dummychoice == 2){
                    
                    string name;
                    cout<<"\nEnter the Student's Name whose Quiz History you want to see"<<endl;
                    cin>>name;
                    if(!StudentExistanceCheck(name)){
                        ShowPopup("Invalid Student Name. Student does not exist");
                        continue;
                    }
                    else{
                        system("cls");
                        DisplayQuizHistory();
                        stack.individualHistoryDisplay(name);
                        cout<<"\n\n";
                        system("pause");
                        continue;
                    }
                    
                }
                // Viewing All Time History
                else if(dummychoice == 3){
                    
                    system("cls");
                    DisplayQuizHistory();
                    stack.displayEntireHistory();
                    system("pause");
                    continue;
                }
                else if(dummychoice == 4){
                    //Exit
                    break;
                }
                else{
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }

            }
        }
        else if(dummychoice == 10){

            HighScoreHeap heap;

            while(true){

                system("cls");
                DisplayHighScores();
                cout<<"\n\n";
                cout<< "┌────────────────────────────────────────────────────────────────┐\n"; 
                cout<< "│                        \033[1;31mHigh Scores\033[0m\t\t                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│1. View Class Top Scores    \t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│2. View Student's Top Scores\t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│3. View All Top Quiz Scores \t\t\t\t\t │\n"; 
                cout<< "│            \t\t\t                                 │\n";
                cout<< "│4. Exit\t\t\t\t\t\t\t │\n";
                cout<< "│            \t\t\t                                 │\n";
                cout<< "└────────────────────────────────────────────────────────────────┘\n";  
                cout<<"\nEnter your choice: ";
                cin>>choice;

                //exception
                if(!isInteger(choice)){
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }
                dummychoice = stringToint(choice);
                //exception end

                // Showing Admin Class Top Scores
                if(dummychoice == 1){
                    
                    string Class,strclassno;
                    int classNo;
                    // Class
                    bool ok = RetrieveClass(tree, classNo, strclassno);
                    if(!ok){
                        continue;
                    }
                    Class = tree.Getclass(classNo);
                    //Displaying History of that Class
                    system("cls");
                    DisplayHighScores();
                    displayClassScores(Class);
                    continue;
                }
                // Viewing Specific Student's Quiz Top Scores
                else if(dummychoice == 2){
                    
                    string name;
                    cout<<"\nEnter the Student's Name whose Quiz Top Scores you want to see"<<endl;
                    cin>>name;
                    if(!StudentExistanceCheck(name)){
                        ShowPopup("Invalid Student Name. Student does not exist");
                        continue;
                    }
                    else{
                        system("cls");
                        DisplayHighScores();
                        displayStudentScores(name);
                        continue;
                    }
                    
                }
                // Viewing All Time High Scores
                else if(dummychoice == 3){

                    system("cls");
                    DisplayHighScores();
                    heap.DisplayAllScores();
                    continue;
                }
                else if(dummychoice == 4){
                    //Exit
                    break;
                }
                else{
                    ShowPopup("Invalid choice. Please enter valid input!");
                    continue;
                }

            }
        }
        else if(dummychoice == 11){
            //Exit
            break;
        }
        else{
            ShowPopup("Invalid choice. Please enter the valid input.");
        }
        tree.saveEntireTree();
        //tree.DisplayEntireTree();
    }
}
//----------------------------------------------------END-------------------------------------------------------//



//----------------------------------------------Main Implementation---------------------------------------------//
void Execute(){
NAryTree tree = NAryTree("SchoolName", "the address", "themail@gmail.com");
tree.loadEntireTree();
while(true){
    int user;
    string struser;
    system("cls");
    DisplayLoginDashBoard();
    cout<<"\n\n\t\t\t\t\t\t     Welcome to the Official Dashboard!\n"<<endl;
    SetConsoleOutputCP(CP_UTF8);
    cout << "┌───────────────────────────────────────────┐\n"; 
    cout << "│\033[1;31mSelect:\033[0m                                    │\n"; 
    cout << "│                                           │\n";
    cout << "│1.Admin                                    │\n"; 
    cout << "│                                           │\n";
    cout << "│2.Student                                  │\n"; 
    cout << "│                                           │\n";
    cout << "│3.Exit                                     │\n";
    cout << "└───────────────────────────────────────────┘\n"; 
    cout<<"\nEnter your access: ";
    cin>>struser;
    //exception
        if(!isInteger(struser)){
            ShowPopup("Invalid choice. Please enter valid input!");
            continue;
        }
        user = stringToint(struser);
    //exception end
    if( user == 1){
        UserType = "Admin";
        AdminAccess(tree);
    }
    else if( user == 2){
        UserType = "STD";
        StudentAccess(tree);
    }
    else if( user == 3){
        SetConsoleOutputCP(CP_UTF8);
        cout<<"\n\n\n";
        cout<<"\n\nGoodBye";
        cout << "\xE2\x9C\x8B";
        cout<<"\nExiting program...";
        break;
    }
    else{
        ShowPopup("Invalid choice. Please enter the correct choice.");
    }
}
    system("pause");
}
