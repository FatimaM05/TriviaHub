#include <iostream>
#include "Class.h"
using namespace std;



// class to represent the root of the entire tree
class Educational_Institute{
    public: 
    string InstituteName;
    string InstituteAddress;
    string Email;
    CLinkedList classes;

    Educational_Institute(){
        classes = CLinkedList();
    }

    Educational_Institute(string name, string address, string email){
        InstituteName = name;
        InstituteAddress = address;
        Email = email;
        classes = CLinkedList();
    }

    string getName(){return InstituteName;}

    string getAddress(){return InstituteAddress;}

    string getEmail(){return Email;}

    void setName(string name){InstituteName = name;}

    void setAddress(string address){InstituteAddress = address;}

    void setEmail(string email){Email = email;}

};
