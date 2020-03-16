/*
 * Stack.h
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */

#ifndef STACK_H_
#define STACK_H_
#include <stdint.h>

typedef char stack_data_Type ;
typedef uint16_t stack_size_Type ;

typedef	struct{

	stack_data_Type *stack_pointer;
	stack_size_Type  stack_maxSize;
	stack_size_Type top;
}ST_stackInfo;
void createStack(ST_stackInfo *info, stack_size_Type size);
void push(ST_stackInfo *info,stack_data_Type data);
void pop(ST_stackInfo *info, stack_data_Type * data);


#endif /* STACK_H_ */
