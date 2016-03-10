#include "list.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList()
{
	List *result = new List;
	ListElement *element = new ListElement;
	result->head = element;
	element->next = nullptr;
	return result;
};

void insertToHead(List *list, int value)
{
	ListElement *element = new ListElement;
	element->next = list->head;
	list->head = element;
	list->head->value = value;
}

void printList(List *list)
{
	ListElement *tmp = list->head;
	while (tmp->next != nullptr)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	printf("\n");
}

void deleteList(List *list)
{
	ListElement *tmp = list->head;
	ListElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
	delete list;
}

/*void insert(List *list, int value, ListElement *position)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = position->next;
	position->next = newElement;
}
*/


