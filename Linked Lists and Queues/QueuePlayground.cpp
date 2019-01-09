//
//  main.cpp
//  QueuePlayground
//
//  Created by Robin Nguyen on 11/6/18.
//  Copyright © 2018 Robin Nguyen. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include"Queue.h"

using std::cin;
using std::cout;
using std::endl;

double get_number();
char get_command();
void print_menu();

int main(int argc, const char * argv[]) {
    Queue q;
    char choice;
    do{
        print_menu();
        choice = toupper(get_command());
        switch(choice){
            case'E':
                cout << "Peace boiii" << endl;
                break;
            case'P': q.print();
                break;
            case'A': q.QueueCycle();
                cout << "Queue afterwards: " << endl;
                q.print();
                break;
            case'I': q.list_insert(get_number());
                break;
            case'S': cout << "Queue Size: " << q.size() << endl;
                break;
            default: cout << "Incorrect Input." << endl;
        }
    }while(choice!= 'E');
    return 0;
}

void print_menu(){
    cout << "P to print menu." << endl;
    cout << "A to advance Queue to next in line." << endl;
    cout << "I to insert another item in Queue." << endl;
    cout << "S for size of Queue." << endl;
    cout << "E to exit." << endl;
}

char get_command(){
    char choice;
    cout << "Please enter in your choice: " << endl;
    cin >> choice;
    return choice;
}

double get_number(){
    double number;
    cout << "Enter Item for Queue: " << endl;
    cin >> number;
    return number;
}
