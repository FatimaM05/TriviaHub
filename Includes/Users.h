#include <iostream>
//file handling library below
#include <fstream>
#include <sstream>
// ctime is needed for the forget password functionality
#include <ctime>
// Nary 
#include "NAryTree.h"


using namespace std;


const string adminKey = "1234"; 
// user class that the administrator and student will inherit, just 2 data members of username and password
class user {
private:
    string username;
    string password;
    string email;

public:
    user() {}

    user (string n, string p, string e) {username = n; password = p; email = e;}

    string getName() {return username;}
    string getPassword() {return password;}
    string getEmail() {return email;}
    void setUserName(string n) {username = n;}
    void setPassword (string p) {password = p;}
    void setEmail (string e) {email = e;}  

};
// administrator class that inherits user and calls the constructor in the user class
class Administrator : public user {
public:
    Administrator(string u, string p, string e) : user(u, p, e) {}
};
// student class that inherits user as well and calls the constructor just like administrator class
class Student : public user {
public:
    string StdClass; // which class is this student in
    Student(string u, string p, string e, string s) : user(u, p, e) {StdClass = s;}
};


// the following 2 validation methods would go directly above the main, not a header class
// this methods just accepts a string and checks if the string is valid to be used as a user name or not, i.e: it has at least one upper case word
    bool validUserName(string n) {
        bool has_uppercase_Letter = false;
        for (char c : n) {
            if (isupper(c)) {
                has_uppercase_Letter = true;
                break;
            }
        }
        if (!has_uppercase_Letter) {
            ShowPopup("The username must contain at least one uppercase letter.");
            return false;
        }
        return true;
    }



// this method just accepts a string and checks if the string is valid to be used as a password, i.e: it has at least 5 characters, a symbol, a digit and a capital letter
    bool validatePassword(string p) {
        if (p.length() < 5) {
            ShowPopup("The password must be at least 5 characters long.");
            return false;
        }

        bool has_uppercase_Letter = false;
        bool has_symbol = false;
        bool has_number = false;
        for (char c : p) {
            if (isupper(c)) {
                has_uppercase_Letter = true;
            } else if (ispunct(c)) {
                has_symbol = true;
            } else if (isdigit(c)) {
                has_number = true;
            }
        }
        if (!has_uppercase_Letter) {
            ShowPopup("The password must contain at least one uppercase letter.");
            return false;
        } else if (!has_symbol) {
            ShowPopup("The password must contain at least one symbol.");
            return false;
        } else if (!has_number) {
            ShowPopup("The password must contain at least one digit.");
            return false;
        }
        return true;
    }


// this method just accepts a string and checks if the string is valid to be used as an email or not, i.e: it must have more then 5 char, must have @ and a dot
    bool validateEmail(string e) {
    if (e.length() < 5) {
        ShowPopup("The email must be at least 5 characters long.");
        return false;
    }
    bool dot_symbol;
    bool at_symbol;
    for (char a : e) {
        if (a == '@') {
            at_symbol = true;
            break;
        }
    }
    for (char a : e) {
        if (a == '.') {
            dot_symbol = true;
        }
    }
        if (!at_symbol) {ShowPopup("The email must contain the @ symbol."); return false;}
        if (!dot_symbol) {ShowPopup("The email must contain a '.' dot."); return false;}
        if (!at_symbol && !dot_symbol) { ShowPopup("The email must contain a dot and the @ symbol."); return false;}
        return true;
}

// if the user is signing up and he uses a username that is already in the file then he shouldn't be able to add that same user again
    bool userAlreadyExists(string user) {
        ifstream y("users.txt");    // opening the user file in read stream
        if (y.is_open()) {
            string line;

            while (getline(y, line)) {
                stringstream ss(line);  // a string stream is declared so we can use delimiters and extract specific part of a line, basically to perform operations on a string
                string u, type;   // to store username
                getline(ss, type, ',');
                getline(ss, u, ',');
                if (u == user) {
                    ShowPopup("User already exists, we suggest that you login instead"); 
                    y.close();
                    return true;
                }
                
            }
        }
        y.close();
        return false;
    }

// the user signs up when its his first time, he enters a username and password and that data is stored in the file, could have other data too such as email, class of the student etc.
    bool signup (string type, string user, string pass, string email, string stdClass = "") {
        if (!validUserName(user) || !validatePassword(pass) || userAlreadyExists(user) || !validateEmail(email)) {return false;}
        else if (validUserName(user) && validatePassword(pass) && !userAlreadyExists(user) && validateEmail(email)) {
            ofstream x("users.txt", ios::app);  // opening the user file in write stream, append to be exact
            if (x.is_open()) {
                if (type == "Admin") {
                    string key;
                    cout << "\nEnter the 4-digit Admin key to proceed:" << endl;
                    cin >> key;
                    if (key != adminKey) {
                        ShowPopup("Invalid Admin key");
                        return false;
                    }
                x << "Admin" << "," << user << "," << pass << "," << email << endl;   // the separator is a comma so its easy to read this later
                }
                else if (type == "STD") {
                x << "STD" << "," << user << "," << pass << "," << email << "," << stdClass << endl;   // the separator is a comma so its easy to read this later
                }
        x.close();
        ShowPopup("Sign up successful!");
        return true;
            }
        }
        return false;
    }


// if the user has already signed up then he would need to login simply, we gotta match the strings he enters and see if they match the data in the file
    bool loginAdmin (string user, string pass) {
        ifstream y("users.txt");    // users file opened in read stream
        if (y.is_open()) {
            string line;

            while (getline(y, line)) {
                string u, p, e, type;    // to store password and username for comparison
                stringstream ss(line);
                getline(ss, type, ',');
                if (type == "Admin") {
                getline(ss, u, ',');      // username read
                getline(ss, p, ',');      // password read
                getline(ss, e, '\n');     // email read
                //getline(ss, s, '\n');   // class read, admin doesn't have a class
                if (u == user && p == pass) {
                ShowPopup("Login successful! Welcome back ");
                return true;
                y.close();
                }
                }
            }
        }
        y.close();
        ShowPopup("Invalid username or password");
        return false;
    }




// if the user has already signed up then he would need to login simply, we gotta match the strings he enters and see if they match the data in the file
    bool loginStd (string user, string pass) {
        ifstream y("users.txt");    // users file opened in read stream
        if (y.is_open()) {
            string line;

            while (getline(y, line)) {
                string u, p, e, s, type;    // to store password and username for comparison
                stringstream ss(line);
                getline(ss, type, ',');
                if (type == "STD") {
                getline(ss, u, ',');      // username read
                getline(ss, p, ',');      // password read
                getline(ss, e, ',');     // email read
                getline(ss, s, '\n');   // class read
                if (u == user && p == pass) {
                ShowPopup("Login successful! Welcome back ");
                return true;
                y.close();
                }
                }
            }
        }
        y.close();
        ShowPopup("Invalid username or password");
        return false;
    }

// if the user wants to change his username, he would enter his old username and password and then enter his new username
// we have 2 files, we transfer all the data from the main file to the dump file and we change the username from the old one to the new one
    bool editUserName(string oldUser, string pass, string newUser) {
        if (!validUserName(newUser) || userAlreadyExists(newUser)) { return false;} 
        else {
        ofstream dump("dump.txt");  // new file in write stream
        ifstream y("users.txt");    // old file in read stream
        if (dump.is_open() && y.is_open()) {
            string line;

            while (getline(y, line)) {
                stringstream ss(line);
                string u, p, e, s,type;
                getline(ss, type, ',');
                getline(ss, u, ',');
                getline(ss, p, ',');
                getline(ss, e, ',');
                getline(ss, s, '\n');
                if (u == oldUser && p == pass) {
                    if (type == "Admin") 
                    {
                    dump << type << "," << newUser << "," << p << "," << e << endl;
                    }
                    else {
                    dump << type << "," << newUser << "," << p << "," << e << "," << s << endl;}
                    }// if the old username and password match then we replace the old username with the new one in the write stream file
                else {
                    dump << line << endl;
                    }
                }
                    y.close();
                    dump.close();
                    remove("users.txt");    // we delete the old file
                    rename("dump.txt", "users.txt");    //we rename the new file, effectively making it the old file with the new username
                    ShowPopup("Username successfully changed");
                    return true;
        }
            else {
                ShowPopup("Error editing the username");
                return false;
                }
    }
    }


// if the user wants to change his password, then he enters his old password and username and then the new password
// same exact concept as the edit username so not going to explain
    bool editPass(string user, string oldPass, string newPass ) {
        if (!validatePassword(newPass)) {return false;}
        else {
            ofstream dump("dump.txt");
            ifstream y("users.txt");
            if (dump.is_open() && y.is_open()) {
                string line;

                while (getline(y, line)) {
                    stringstream ss(line);
                    string u, p, e, s, type;
                    getline(ss, type, ',');
                    getline(ss, u, ',');
                    getline(ss, p, ',');
                    getline(ss, e, ',');
                    getline(ss, s, '\n');
                    if (u == user && p == oldPass) {
                        if (type == "Admin") 
                        {
                        dump << type << "," << u << "," << newPass << "," << e << endl;
                        }
                        else {
                        dump << type << "," << u << "," << newPass << "," << e << "," << s << endl;}
                        }
                    else {
                        dump << line << endl;
                    }
                }
                y.close();
                dump.close();
                remove("users.txt");
                rename("dump.txt", "users.txt");
                ShowPopup("Password successfully changed");
                return true;
            }
            else {
                ShowPopup("Error editing the password");
                return false;
            }
        }
    }

void deleteAllUsers() {
    remove("users.txt");
    ShowPopup("All the users have been deleted ma lad, make new users from scratch. you basically deleted the users.txt file from the folder, go check if you wanna");
}
//====================================THE FOLLOWING CODE IS NEEDED FOR THE EMAIL SENDING==========================================


string generateCode() {
    srand(time(0)); // time(0) gives us the time in seconds since jan 1st 1970, so it would be a massive value. we use srand to set the initial value of the rand function, so the initial value is the current time in seconds which changes every second of course, making it truly unique
    int code = rand() % 900000 + 100000;    // makes sure that we get something between 100,000 and 999,999
    return to_string(code);
}

// Function to send the reset code via email
void sendResetCode(string email, string code) {
    string command = "python send_reset_code.py " + email + " " + code; // command to execute the python file from the terminal
    system(command.c_str());    // access the terminal using the system function and then use c_str to convert normal string to command string, think of the system("pause") that we do in our normal labs, using that lets us access and pause the terminal display, this is just taking that a step further
}


// read the file for the username (which is being used as the email here)and see if the user enters the right 6 digit code, if so then change the password with the new password
bool forgotPassword(string email) {
    ifstream y("users.txt");
    if (y.is_open()) {
        string line;

        while (getline(y, line)) {
            stringstream ss(line);
            string u, p, e, s,type;
            getline(ss, type, ',');
            getline(ss, u, ',');
            getline(ss, p, ',');
            getline(ss, e, ',');
            getline(ss, s, '\n');
            if (e == email) {
                y.close();
                AGAIN:
                string code = generateCode();
                sendResetCode(e, code);
                cout << "A reset code has been sent to your email." << endl;

                string enteredCode;
                cout << "Please enter the code: ";
                cin >> enteredCode;
                if (enteredCode == code) {
                    string newPassword;
                    cout << "\nEnter your new password: ";
                    cin >> newPassword;
                    if (validatePassword(newPassword)) {
                        editPass(u, p, newPassword);
                        //ShowPopup("Your password has been successfully reset.");
                        return true;
                    } else {
                        ShowPopup("Invalid password format.");
                        return false;
                    }
                } else {
                    ShowPopup("Invalid reset code.");
                    int c = 0;
                    cout << "\nPress 1 if you want to receive the code again (protip: don't enter it wrong this time)" << endl;
                    cin >> c;
                    if (c == 1) {
                        goto AGAIN;
                    }
                    else{
                    return false;
                    }
                }
            }
        }
    }
    y.close();
    ShowPopup("User not found.");
    return false;
}

// enter the username of a student and get the object of that student using file handling, so you can find the students password, email and class using just his username, might be useful in some situation so its just a utility method
// NOTE: manipulating the object will not have any permanent affect, keep that in mind, so changing the stuff of the student object is not ganna do any file handling
Student returnStudent(string username) {
    ifstream y("users.txt");
    if (y.is_open()) {
        string line;
        while (getline(y, line)) {
            stringstream ss(line);
            string type;
            getline(ss, type, ',');
            if (type == "STD") {
            string u, p, e, s;
            getline(ss, u, ',');
            getline(ss, p, ',');
            getline(ss, e, ',');
            getline(ss, s, '\n');
            if (u == username) {
                Student std(u, p, e, s);
                y.close();
                return std;
            }
    }
    }
}
y.close();
}


bool StudentExistanceCheck(string user) {
        ifstream y("users.txt");    // opening the user file in read stream
        if (y.is_open()) {
            string line;

            while (getline(y, line)) {
                stringstream ss(line);  // a string stream is declared so we can use delimiters and extract specific part of a line, basically to perform operations on a string
                string u, type;   // to store username
                getline(ss, type, ',');
                if (type == "STD") {
                getline(ss, u, ',');
                if (u == user) { 
                    y.close();
                    return true;
                    }
                }
                
            }
        }
        y.close();
        return false;
    }

    Administrator returnAdministrator(string username) {
    ifstream y("users.txt");
    if (y.is_open()) {
        string line;
        while (getline(y, line)) {
            stringstream ss(line);
            string type;
            getline(ss, type, ',');
            if (type == "Admin") {
            string u, p, e;
            getline(ss, u, ',');
            getline(ss, p, ',');
            getline(ss, e, ',');
            if (u == username) {
                Administrator adm(u, p, e);
                y.close();
                return adm;
            }
    }
    }
}
y.close();
}

//=====================================================forget password functionality code finishes here====================================================