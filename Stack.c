/*
 * stack.c
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */
#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
//typedef uint16_t stack_size_Type ;

void createStack(ST_stackInfo *info,stack_size_Type size)
{
	info->stack_maxSize=size;
	info->stack_pointer=(stack_data_Type *)malloc(sizeof(stack_data_Type) * size);
	info->top=0;
}

void push(ST_stackInfo *info,stack_data_Type data)
{
	if(info->top != info->stack_maxSize)
	{
		info->stack_pointer[info->top]=data;
		++info->top;
	}
	else
	{
		printf("error stack is full\n");
	}
}
void pop(ST_stackInfo *info, stack_data_Type * data)
{

	if(info->top != 0)
		{
			--info->top;
			*data= info->stack_pointer[info->top];

		}
		else
		{
			printf("error stack is empty\n");
		}
}
