//
//  Queue.h
//  QueuePlayground
//
//  Created by Robin Nguyen on 11/6/18.
//  Copyright © 2018 Robin Nguyen. All rights reserved.
//

#ifndef Queue_h
#define Queue_h



class Queue{
private:
    typedef double doub;
    typedef size_t size_type;
    typedef struct Node{
        Node*link;
        doub data;
        size_type priority;
    }*NodePtr;
    
    NodePtr head_ptr;
    NodePtr tail_ptr;
    NodePtr cursor;
    size_type prio;
    size_type many_nodes;
    
public:
    Queue();
    size_type size(){return many_nodes;}
    void list_insert(doub item);
    void QueueCycle();
    bool isEmpty();
    void print();
    void insert_within(doub item, size_type prio);
    
    
};

#endif /* Queue_h */
