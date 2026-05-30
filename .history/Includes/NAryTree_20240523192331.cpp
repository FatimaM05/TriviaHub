#include <iostream>
#include "Educational_Institute.h"
using namespace std;

class NAryTree {
    public:
    Educational_Institute root;

    NAryTree () {}

    NAryTree (string n, string a, string e) {
        root = Educational_Institute(n, a, e);
    }
// Insert methods are below
    void InsertClass(string className) {
        root.classes.Insert(className);
    }
    void InsertSubjects(string className, string subjectName) {  
        ClassNode* c1 = root.classes.findCLass(className);
        c1->GetNode().subjects.Insert(subjectName);
    }
    // void InsertChapters(string classNo, string subjectName, int chapterNumber) {
    //     Class c1 = root.classes.findCLass(classNo);
    //     Subject s1 = c1.subjects.findSubject(subjectName);
    //     s1.chapters.Insert(chapterNumber);
    //}
//     void InsertQuestions(string classNo,string subjectName, int ChapterNo, int QuestionNo, string       question, string OptionA,string OptionB,string OptionC,string OptionD,string CorrectOption ) {
//         Class c1 = root.classes.findCLass(classNo);
//         Subject s1 = c1.subjects.findSubject(subjectName);
//         Chapter ch1 =s1.chapters.findChapter(ChapterNo);
//         ch1.Questions.Insert(QuestionNo, question, OptionA,OptionB,OptionC,OptionD,CorrectOption);
//     }
// // Insert methods are above
//     void DeleteClass(string ClassName){
//        root.classes.Delete(ClassName);
//     }
//     void DeleteSubject(string className, string SubjecName){
//         Class c1 = root.classes.findCLass(className);
//         c1.subjects.Delete(SubjecName);
//     }
//     void DeleteChapter(string className, string subjectName, int ChapterNo){
//         Class c1 = root.classes.findCLass(className);
//         Subject s1 = c1.subjects.findSubject(subjectName);
//         s1.chapters.Delete(ChapterNo);
//     }
//     void DeleteQuestion(string className, string subjectName, int ChapterNo,int QuestionNo){
//         Class c1 = root.classes.findCLass(className);
//         Subject s1 = c1.subjects.findSubject(subjectName);
//         Chapter ch1 = s1.chapters.findChapter(ChapterNo);
//         ch1.Questions.Delete(QuestionNo);
//     }
//Delete methods are above
    
    // void DisplayClasses(){
    //     root.classes.displayAll();
    // }
    void DisplaySubjects(string className){
        ClassNode* c1 = root.classes.findCLass(className);
        c1->GetNode().subjects.displayAll();
    }
    // void DisplayChapters(string className, string subjectName){
    //     Class c1 = root.classes.findCLass(className);
    //     Subject s1 = c1.subjects.findSubject(subjectName);
    //     s1.chapters.Display();
    // }
    // void DisplayQuestions(string className, string subjectName, int ChapterNo){
    //     Class c1 = root.classes.findCLass(className);
    //     Subject s1 = c1.subjects.findSubject(subjectName);
    //     Chapter ch1 = s1.chapters.findChapter(ChapterNo);
    //     ch1.Questions.displayAll();
    // }


    

};

int main(){
    NAryTree tree = NAryTree();

    tree.InsertClass("Class1");
    tree.InsertClass("Class2");
    tree.InsertClass("Class3");
    tree.InsertClass("Class4");

    
    tree.InsertSubjects("Class1", "English");
    tree.InsertSubjects("Class1", "Maths");
    tree.InsertSubjects("Class1", "Bio");
    tree.InsertSubjects("Class1", "Urdu");

    tree.DisplaySubjects("Class1");

    // tree.InsertSubjects("Class2", "English");
    // tree.InsertSubjects("Class2", "Maths");
    // tree.InsertSubjects("Class2", "Bio");
    // tree.InsertSubjects("Class2", "Urdu");

    // tree.InsertSubjects("Class3", "English");
    // tree.InsertSubjects("Class3", "Maths");
    // tree.InsertSubjects("Class3", "Bio");
    // tree.InsertSubjects("Class3", "Urdu");


    // tree.InsertSubjects("Class4", "English");
    // tree.InsertSubjects("Class4", "Maths");
    // tree.InsertSubjects("Class4", "Bio");
    // tree.InsertSubjects("Class4", "Urdu");


    // tree.InsertChapters("Class1", "English", 1);
    // tree.InsertChapters("Class1", "English", 1);
    // tree.InsertChapters("Class1", "English", 1);
    // tree.InsertChapters("Class1", "English", 1);


    // tree.InsertQuestions("Class1", "English", 1, 1, "what ya upto dawg", "nothing", "absoultely nothing", "uk homes", "yeehaaa", "nothing");
    // tree.InsertQuestions("Class1", "English", 1, 2, "what ya doing dawg", "complaining", "complaining like a woman", "complainging like an aunty", "complaining like one particular aunty", "fatima");
    // tree.InsertQuestions("Class1", "English", 1, 3, "so hows the complaining going aunty?", "good", "great", "uk how it is son", "oh absolutely fabulous", "ya know dawgg");


    // tree.DisplayClasses();
    // tree.DisplaySubjects("Class1");
    // tree.DisplaySubjects("Class2");
    // tree.DisplaySubjects("Class3");
    // tree.DisplayChapters("Class1", "English");
    // tree.DisplayQuestions("Class1", "English", 1);

    return 0;
}