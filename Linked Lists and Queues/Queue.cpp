//
//  Queue.cpp
//  QueuePlayground
//
//  Created by Robin Nguyen on 11/6/18.
//  Copyright © 2018 Robin Nguyen. All rights reserved.
//

#include<iostream>
#include <stdio.h>
#include<cstdlib>
#include"Queue.h"
using namespace std;

Queue::Queue(): head_ptr(NULL), tail_ptr(NULL), many_nodes(0), cursor(0){}

bool Queue::isEmpty(){
    return (many_nodes > 0);
}

void Queue::list_insert(doub item){
     NodePtr new_node = new Node; //create new node
    if(head_ptr == NULL){
        head_ptr = new Node;
        head_ptr->data = item;
        prio = 1;
        head_ptr->priority = 1;
        head_ptr->link = NULL;
       // cursor = head_ptr;
    }else if(head_ptr->link == NULL){
        head_ptr->link = new_node;
        new_node->data = item;
        new_node->priority = ++prio;
        new_node->link = NULL;
    }else{
        NodePtr temp = head_ptr;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new_node;
        new_node->data = item;
        new_node->priority = ++prio;
        new_node->link = NULL;
    }
    many_nodes++;
}

void Queue::QueueCycle(){
    if(head_ptr == NULL){
        cout << "Nothing to Cycle" << endl;
    }else if(head_ptr->link == NULL){
        cout << "You're up." << endl;
        head_ptr->data = NULL;
        head_ptr->priority = NULL;
        head_ptr = NULL;
        delete head_ptr;
        many_nodes--;
    }else{
        NodePtr iter = head_ptr;
        NodePtr previous = head_ptr;
        while(iter->link != NULL){
            iter->data = (iter->link)->data;
            previous = iter;
            iter = iter->link;
            many_nodes--;
        }
        delete iter;
        previous->link = NULL;
    }
}

void Queue::print(){
    if(head_ptr == NULL){
        cout << "Empty" << endl;
    }else{
    NodePtr iter = head_ptr;
    while(iter!=NULL){
        cout << "Priority Number " << iter->priority << ": " << iter->data << endl;
        iter = iter->link;
    }
}
}

void Queue::insert_within(doub item, size_type user_prio){
    NodePtr temp = head_ptr;
    if(head_ptr == NULL){
        head_ptr = new Node;
        head_ptr->data = item;
        prio = 1;
        head_ptr->priority = prio;
        head_ptr->link = NULL;
    }
    while(temp->link != NULL && user_prio <= temp->priority){
        
    }
    
}
