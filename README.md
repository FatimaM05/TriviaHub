# Trivia Hub

Trivia Hub is a C++ console-based quiz application built as a Data Structures and Algorithms project. The system manages school quiz content, lets students attempt quizzes, stores quiz attempts, and ranks scores using custom DSA implementations instead of relying on database frameworks.

The main focus of the project is to demonstrate how core data structures can be applied in a practical application. Classes, subjects, chapters, and questions are organized as an N-ary tree-like hierarchy. Quiz history is handled through a stack, priority-based quiz selection uses a heap, random quiz generation uses linked lists and circular/Josephus-style shuffling, and high scores are ranked through a max heap.

## Scope

Trivia Hub supports two main user roles:

- **Admin**: manages the educational content and views student performance.
- **Student**: signs up, logs in, attempts quizzes, and reviews quiz results.

The application stores its data locally in text files, making it suitable for a DSA course project, offline demonstrations, and learning how file handling works with custom data structures.

## Main Features

- Admin and student authentication
- Student signup, login, username update, and password reset
- Admin-protected signup using an admin key
- Add, delete, and view classes
- Add, delete, and view subjects
- Add, delete, and view chapters
- Add, delete, and view questions
- Attempt random quizzes
- Attempt priority quizzes
- Select quiz length: 5, 10, 15, or 20 questions
- Choose subjects and chapters before starting a quiz
- Save quiz attempts with marks and date/time
- View personal quiz history
- View class quiz history
- View all quiz history as admin
- View personal top scores
- View class top scores
- View all-time high scores
- Local file persistence for users, school data, and scores

## DSA Concepts Used

### N-ary Tree / Hierarchical Tree

The educational institute data is modeled as a hierarchy:

```text
Educational Institute
└── Classes
    └── Subjects
        └── Chapters
            └── Questions
```

This structure is implemented through the `NAryTree` class and linked-list based child collections.

### Linked Lists

Linked lists are used throughout the project for:

- Class storage
- Subject storage
- Chapter storage
- Question storage
- Selected subjects and chapters for a quiz

Important linked list classes include:

- `CLinkedList`
- `SLinkedList`
- `ChpLinkedList`
- `QLinkedList`
- `StrLinkedlist`
- `IntLinkedlist`

### Stack

Quiz history is implemented using a stack in `HistoryStack`. Each quiz attempt is pushed as a `StdQuizNode`, storing:

- Student name
- Class
- Selected subjects and chapters
- Total marks
- Obtained marks
- Date and time

The history stack can display all attempts, attempts by student, or attempts by class.

### Heap

Heaps are used in two important parts of the project:

- `MinHeap` is used for priority quizzes, where questions are sorted by priority.
- `HighScoreHeap` is used to rank quiz attempts by percentage for high score views.

### Circular Linked List and Josephus Shuffle

Random quiz generation uses a circular linked list and a Josephus-style process to shuffle questions before displaying them to the student.

### File Handling

The project uses text files as persistent storage:

- `EducationalInstitute.txt`: stores the full school/class/subject/chapter/question tree.
- `users.txt`: stores admin and student accounts.
- `Scores.txt`: stores quiz attempts and scores.

## Project Structure

```text
.
├── TriviaHub.cpp
├── send_reset_code.py
├── EducationalInstitute.txt
├── Scores.txt
├── users.txt
└── Includes/
    ├── Execute.h
    ├── Users.h
    ├── NAryTree.h
    ├── HighScores.h
    ├── Stacky.h
    ├── Educational_Institute.h
    ├── Class.h
    ├── Subjects.h
    ├── Chapters.h
    └── Question.h
```

## Main Components

### `TriviaHub.cpp`

The entry point of the application. It includes `Execute.h` and starts the project by calling:

```cpp
Execute();
```

### `Includes/Execute.h`

Contains the main application flow, menus, dashboards, admin portal, student portal, quiz selection, and user interaction logic.

### `Includes/Users.h`

Handles:

- User classes
- Student and administrator models
- Signup
- Login
- Validation
- Password reset
- User file handling

### `Includes/NAryTree.h`

Contains the main educational institute tree logic. It supports:

- Inserting classes, subjects, chapters, and questions
- Deleting classes, subjects, chapters, and questions
- Displaying tree data
- Loading and saving the full tree
- Random quiz generation
- Priority quiz generation

### `Includes/Question.h`

Defines:

- `Question`
- `QuestionNode`
- `QLinkedList`
- `MinHeap`
- `CircularLinkedList`

This file supports question storage, heap sorting, and randomization.

### `Includes/Stacky.h`

Implements quiz history using a stack. It stores and displays previous quiz attempts.

### `Includes/HighScores.h`

Implements score ranking using a max heap. It displays all scores, student-specific scores, and class-specific scores.

### `send_reset_code.py`

Python helper script used by the forgot password feature to send a reset code through email.

## Technology Stack

- **Language:** C++
- **Helper script:** Python
- **Interface:** Console / terminal
- **Storage:** Text files
- **Platform target:** Windows console
- **Compiler:** MinGW g++ or another Windows-compatible C++ compiler

The project includes `Windows.h`, `MessageBoxW`, `system("cls")`, and `system("pause")`, so it is designed mainly for Windows.

## How to Run

### 1. Open the project folder

Open a terminal inside the project root, where `TriviaHub.cpp` is located.

### 2. Compile the project

Using MinGW g++ on Windows:

```bash
g++ TriviaHub.cpp -o TriviaHub.exe
```

If your compiler needs explicit Windows GUI library linking for message boxes, use:

```bash
g++ TriviaHub.cpp -o TriviaHub.exe -luser32
```

### 3. Run the executable

```bash
TriviaHub.exe
```

Or, from PowerShell:

```powershell
.\TriviaHub.exe
```

### 4. Use the dashboard

When the program starts, choose:

- `1` for Admin
- `2` for Student
- `3` to Exit

Admins can manage quiz data and view reports. Students can attempt quizzes and view their history and scores.

## Password Reset Setup

The forgot password feature calls:

```text
send_reset_code.py
```

This script uses Python SMTP email sending. To use it reliably, Python must be installed and available from the command line. The SMTP account details should be configured safely before using this feature in a real environment.

## Data Files

### `EducationalInstitute.txt`

Stores the complete educational tree using comma-separated records:

- `EI`: educational institute details
- `C`: class
- `CS`: class subject
- `CSC`: class subject chapter
- `CSCQ`: class subject chapter question

### `users.txt`

Stores user records for admins and students.

### `Scores.txt`

Stores quiz attempt records, including student, class, selected subjects/chapters, marks, and date/time.

## Notes

- Avoid using commas inside class names, subject names, chapter data, questions, options, or answers because the project uses commas as file delimiters.
- The existing `.exe` files are compiled outputs. The main source file is `TriviaHub.cpp`.
- The project is intentionally built with custom DSA structures to show implementation knowledge, not to depend on database or framework abstractions.
