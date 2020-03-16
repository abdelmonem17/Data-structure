/*
 * Linkedlist.h
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef int32_t linkedlist_data_Type ;
typedef uint32_t linkedlist_size_Type ;


typedef	struct linkedList{

	struct linkedList *next_node;
	linkedlist_data_Type data ;

}New_Node;

typedef	struct{

	New_Node *head;
	linkedlist_size_Type size;

}ST_list;

uint8_t createList(ST_list *list);
uint8_t insertToList(ST_list *listHead, uint8_t position, linkedlist_data_Type data);
uint8_t deleteFromList(ST_list *listHead, uint8_t position, linkedlist_data_Type* data);
New_Node* searchIntoList(ST_list *listHead, linkedlist_data_Type data);
void sortList(ST_list *listHead);
void reverseList(ST_list *list);
uint8_t getDataInList(ST_list *list, uint8_t position, linkedlist_data_Type *pData);

#endif /* LINKEDLIST_H_ */
