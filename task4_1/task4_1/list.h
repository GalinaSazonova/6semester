#pragma once

struct ListElement;
struct List;
List *createList();
void printList(List *list);
void deleteList(List *list);
void insertToHead(List *list, int number);
void insert(List *list, int value, int n);
int numberOfElements(List *list);
ListElement *position(List *list, int n);
ListElement* last(List *list);
List *reverse(List *list);