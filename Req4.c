/*
 * Req.c
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */

#include "Req4.h"
#include "Req2.h"
#include "Queue.h"
#include "Stack.h"
int64_t evaluate(char* expression)
{

	stack_size_Type exp_size=0,queue_usedSize=0;
	ST_queueInfo queue;
	int32_t num=0;
	int64_t result;
	int32_t operand2,operand1;
	int32_t operation;

	//compute size of input string
	while(expression[exp_size] !=0)
	{
			++exp_size;
	}
	//create queue for storing operands and operations
	createQueue(&queue,exp_size);

	//check for right balanced parantheses
	if(checkForBalancedParantheses(expression) ==0)
	{
		printf("Error :unbalanced expression\n");
		return 0;
	}
	else
	{
		for(uint16_t i=0;i<=exp_size;i++)
		{
			//storing operands and operations in queue

			if(expression[i] >= '0' && expression[i] <= '9')
			{
				//get the oprand
				num=num*10+ (expression[i]-'0');

			}
			else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||expression[i] == '/')
			{
				enqueue(&queue,num);
				enqueue(&queue,expression[i]);
				num=0;
				queue_usedSize +=2;
			}
			else if(expression[i]==0)
			{
				enqueue(&queue,num);
				++queue_usedSize;
				//nothing
			}
		}
	 //handle operations
	  dequeue(&queue,&operand1);
	  result=operand1;
	  for(int i=0;i<queue_usedSize/2;i++)
	  {
		  dequeue(&queue,&operation);
		  dequeue(&queue,&operand2);
		  switch(operation)
		  {
		  case '+':
			  result +=operand2;
			  break;
		  case '-':
			  result -=operand2;
		  	  break;
		  case '*':
		  	result *=operand2;
		  	break;
		  case '/':
		  	result /=operand2;
		  	break;

		  }
	  }

	}
	return result;
}
