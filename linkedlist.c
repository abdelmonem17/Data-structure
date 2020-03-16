/*
 * linkedlist.c
 *
 *  Created on: Oct 31, 2019
 *      Author: AVE-LAP-062
 */

#include "Linkedlist.h"


static uint8_t editDataInList(ST_list *list, uint8_t position, linkedlist_data_Type data);


uint8_t createList(ST_list *list)
{

 list->head=(New_Node *) malloc(sizeof(New_Node));
 if(list->head)
 {
	 list->head->next_node=NULL;
	 list->size=0;
	 return 1;
 }
 else
	 return 0;

}

uint8_t insertToList(ST_list *list, uint8_t position, linkedlist_data_Type data)
{
	//uint8_t location=position;
	New_Node *next,*current;

	current=list->head;
	for(int i=0;i<position;i++)
	{
		if(current->next_node==NULL)
		{
			printf("error ,sorry you exceed the list bound\n");
			return 0;
		}
		else
		{
			current=current->next_node;
		}
	}
	New_Node *node=(New_Node *)malloc(sizeof(New_Node));
	if(current->next_node !=NULL)
	{
	next=current->next_node;
	current->next_node=node;
	node->next_node=next;
    node->data=data;
	}
	else
	{
		//insert in last position
		current->next_node=node;
		node->next_node=NULL;
		node->data=data;
	}
	list->size++;
	return 1;

}
static uint8_t editDataInList(ST_list *list, uint8_t position, linkedlist_data_Type data)
{
	New_Node *current;
		current=list->head;
		for(int i=0;i<position-1;i++)
		{
			if(current->next_node==NULL)
			{
				printf("error ,sorry you exceed the list bound\n");
				return 0;
			}
			else
			{
				current=current->next_node;
			}
		}
		current->next_node->data=data;
		return 1;
}

uint8_t deleteFromList(ST_list *list, uint8_t position, linkedlist_data_Type* data)
{

		New_Node *current;

		current=list->head;
		for(int i=0;i<position;i++)
		{
			if(current->next_node==NULL)
			{
				printf("error ,sorry you exceed the list bound\n");
				return 0;
			}
			else
			{
				current=current->next_node;
			}
		}

		if(current->next_node !=NULL)
		{
			*data= current->next_node->data;
			current->next_node=current->next_node->next_node;

		}
		else{
			//current->next_node=NULL;

		}
		list->size--;
		return 1;
}

New_Node* searchIntoList(ST_list *list, linkedlist_data_Type data)
{

	New_Node *current;

	current=list->head;
	while(current->data !=data)
	{
		if(current->next_node ==NULL)
		{
		   current= 0;
		   break;
		}
		else
		{
			current=current->next_node;
		}


	}
	return current;

}

void sortList(ST_list *list)
{

		//insertion sort
		//New_Node * temp_node;
		New_Node *current_inner,*current_outer;
		uint8_t count_out,count_in;
		linkedlist_data_Type unused_data;

		for(current_outer =list->head->next_node ,count_out =0; count_out < list->size; current_outer=current_outer->next_node,count_out++)
		{

			for(current_inner =list->head->next_node,count_in =0 ; count_in < count_out;count_in++)
			{
						if( (current_inner->data)  >  (current_outer->data) )
						{

							insertToList(list,count_in,current_outer->data);
							//delete old place
							deleteFromList(list,count_out+1,&unused_data);
							break;
						}
						current_inner=current_inner->next_node;

			}

		}

}
void reverseList(ST_list *list)
{
	linkedlist_data_Type temp;
	New_Node *current_start,*current_end;
	//linkedlist_data_Type unused_data;
	for(linkedlist_size_Type i=0;i<list->size/2;i++)
	{

		//swap
		current_start=list->head->next_node;
		for(linkedlist_size_Type k=0;k<i;k++)
		{
			current_start=current_start->next_node;
		}
		current_end=list->head->next_node;

			//if(current_end->next_node !=NULL)
				for(linkedlist_size_Type k=0;k<(list->size-i-1);k++)
					{
						current_end=current_end->next_node;
					}
		//	else
				//element from end was found
			//	break;
				temp=current_end->data;
				editDataInList(list,list->size-i,current_start->data);
				editDataInList(list,i,temp);
		}

		//insert in new place
//		insertToList(list,i,current_end->data);
//		//delete old place
//		deleteFromList(list,list->size,&unused_data);
//
//		//insert in new place
//		insertToList(list,list->size-i,current_start->data);
//		//delete old place
//		deleteFromList(list,i+1,&unused_data);


	//}

}
uint8_t getDataInList(ST_list *list, uint8_t position, linkedlist_data_Type *pData)
{
			New_Node *current;
			current=list->head;
			for(int i=0;i<position;i++)
			{
				if(current->next_node==NULL)
				{
					printf("error ,sorry you exceed the list bound\n");
					return 0;
				}
				else
				{
					current=current->next_node;
				}
			}
			*pData= current->next_node->data;
			return 1;
}
