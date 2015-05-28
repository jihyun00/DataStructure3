#include <iostream>
#include <string>
#include <stdlib.h>
#include "linkedlist.h"

using namespace std;

node* Chain::createNode(std::string strValue) {
    int value = atoi(strValue.c_str());

    node* newNode = new node;
    newNode->data = value;
    newNode->link = NULL;

    return newNode;
}

node* Chain::getNode(std::string strValue) {
    int value = atoi(strValue.c_str());

    node* head = first;

    if(head == NULL) {
        return NULL;
    }
    
    while(head != NULL) { // 노드가 끝일 때까지
        if(head->data == value) {
            return head;
        } else {
            head = head->link;
        }
    }

    return NULL;
}

void Chain::insert(string targetValue, string value, bool status) {
    node* newNode = createNode(value);

    node* target = getNode(targetValue);
    if(target == NULL) {
        cout << "error" << endl;

        return;
    }

    newNode->link = target->link;
    target->link = newNode;

    if(status == true) {
        cout << "done" << endl;
    }

}

void Chain::insertListFront(string value, bool status) {
    node* newNode = createNode(value);
    node* pointNode = first;

    if(first == NULL) {
        first = last =  newNode; 
    } else {
        newNode->link = pointNode;
    }

    first = newNode;

    if(status == true) {
        cout << "done" << endl;
    }
}

void Chain::insertListBack(string value, bool status) {
    node* newNode = createNode(value);
    node* pointNode = first;

    if(first == NULL) {
        first = last = newNode;
    } else {
        while(pointNode->link != NULL) {
            pointNode = pointNode->link;
        }

        pointNode->link = newNode;
    }

    last = newNode;

    if(status == true) {
        cout << "done" << endl;
    }
}

void Chain::deleteNode(string deleteValue) {
    node* target = getNode(deleteValue);
    node* current = first;

    if(target == NULL) {
        cout << "error" << endl;

        return;
    }

    if(target == first) {
        first = first->link;
    } else { 
        while(current != NULL && current->link != target) { // 지우려는 노드의 전 노드 링크를 찾기
            current = current->link;
        }

        if(current != NULL) {
            current->link = target->link;
        }
    }

    delete target;

    cout << "done" << endl;
}

void Chain::reverse() {
    node* current = first;
    node* prev = 0;
    node* final; // last를 담아둘 노드

    if(first == NULL) {
        cout << "error" << endl;

        return;
    }

    while(current != NULL) {
        node* r = prev;
        prev = current;
        current = current->link;
        prev->link = r;
        if(current == first) {
            final = current;
        }
    }

    first = prev;
    last = final;

    cout << "done" << endl;
}

void Chain::printList() {
    node* nodeList = first;

    if(nodeList == NULL) {
        cout << "error" << endl;
        return;
    }

    while(nodeList != NULL) {
        cout << nodeList->data << " ";
        nodeList = nodeList->link;
    }

    cout << endl;
}
