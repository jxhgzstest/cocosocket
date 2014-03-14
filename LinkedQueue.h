/* 
 * File:   LinedQueue.h
 * Author: beykery
 *
 * Created on 2014��3��18��, ����13:09
 */

#ifndef LINKEDQUEUE_H
#define	LINKEDQUEUE_H

#include "Queue.h"
#include <stdlib.h>

typedef struct Node {
    void* data;
    Node* next;
} Node;

template <class T>
class LinedQueue : public Queue<T> {
public:

    LinedQueue() : head(NULL), tail(NULL), size(0) {
    };

    virtual~LinedQueue() {
        Node* p = head;
        while (p != NULL) {
            delete ((T*) p->data);
            Node* t = p;
            p = p->next;
            free(t);
        }
    };

  virtual  bool Offer(T* e) {
        Node* p = (Node*) malloc(sizeof (Node));
        p->data = e;
        p->next = NULL;
        if (size <= 0) {
            head = p;
            tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
        size++;
        return true;
    };

  virtual  T* Peek() {
        if (head != NULL) {
            return (T*) (head->data);
        }
        return NULL;
    };

   virtual T* Poll() {
        if (head != NULL) {
            T* t = (T*) (head->data);
            Node* oh = head;
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
            free(oh);
            size--;
            return t;
        }
        return (T*) (NULL);
    };

  virtual int Size() {
        return size;
    };
protected:
    Node* head;
    Node* tail;
    int size;
};

#endif	/* LINKEDQUEUE_H */

