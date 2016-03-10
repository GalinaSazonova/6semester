#pragma once

struct ListElement;
struct List;
List *createList();
void printList(List *list);
void deleteList(List *list);
void insertToHead(List *list, int number);
//void insert(List *list, int value, ListElement *position);
