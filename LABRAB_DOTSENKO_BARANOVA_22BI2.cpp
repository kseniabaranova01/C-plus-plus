#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

int taskA() {
    int N;
    std::cin >> N;

    std::set<int> numbers; 

    
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    std::cout << numbers.size() << std::endl;

    return 0;
}

bool isCorrectSequence(const string& sequence) {
    stack<char> brackets;

    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            brackets.push(bracket);
        }
        else {
            if (brackets.empty()) {
                return false; 
            }
            else if ((bracket == ')' && brackets.top() == '(') ||
                (bracket == ']' && brackets.top() == '[') ||
                (bracket == '}' && brackets.top() == '{')) {
                brackets.pop(); 
            }
            else {
                return false; 
            }
        }
    }

    return brackets.empty(); 
}

int taskD() {
    string sequence;
    getline(cin, sequence);

    if (isCorrectSequence(sequence)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}

int taskB() {
   
    map<int, vector<string>> students;

    int classNumber;
    string lastName;

    while (cin >> classNumber >> lastName) {
        
        students[classNumber].push_back(lastName);
    }

   
    for (int classNum = 9; classNum <= 11; ++classNum) {
        if (students.find(classNum) != students.end()) {
            for (const string& name : students[classNum]) {
                cout << classNum << " " << name << endl;
            }
        }
    }

    return 0;
}


int evaluatePostfix(const string& expression) {
    istringstream iss(expression);
    stack<int> numbers;

    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            numbers.push(stoi(token));
        }
        else {
            int operand2 = numbers.top();
            numbers.pop();
            int operand1 = numbers.top();
            numbers.pop();

            switch (token[0]) {
            case '+':
                numbers.push(operand1 + operand2);
                break;
            case '-':
                numbers.push(operand1 - operand2);
                break;
            case '*':
                numbers.push(operand1 * operand2);
                break;
            default:
                cout << "Invalid operator!" << endl;
                return 0;
            }
        }
    }

    return numbers.top();
}

int taskE() {
    string expression;
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << result << endl;

    return 0;
}

int taskG() {
    unordered_set<string> set;

    char operation;
    string word;

    while (true) {
        cin >> operation;
        if (operation == '#')
            break;

        cin >> word;

        switch (operation) {
        case '+':
            set.insert(word);
            break;
        case '-':
            set.erase(word);
            break;
        case '?':
            if (set.find(word) != set.end())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            break;
        }
    }

    return 0;
}


int main()
{
    //taskA ();
    //taskB();
    //taskD();
    //taskG();
    taskE();
    return 0;
}











