/*
 * Req2.c
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */

#include "Req2.h"
#include "Stack.h"
uint8_t checkForBalancedParantheses(char* expression)
{
	ST_stackInfo 	stack1;
	uint8_t isBalanced=1;
	char ch1;
	uint16_t exp_size=0;
	while(expression[exp_size] !=0)
	{
		exp_size++;
	}
	createStack(&stack1,exp_size);
	//createStack(&stack2,exp_size);
	for(int i=0;i<exp_size;i++  )
	{
		if((expression[i]=='{') || (expression[i]=='(') || (expression[i]=='['))
			{
			push(&stack1,expression[i]);
				//size1++;
			}
	}

		for(int k=0;k<exp_size;k++)
		{
			if( (expression[k]=='}') || (expression[k]==')') || (expression[k]==']') )
			{
				pop(&stack1,&ch1);
			//pop(&stack2,&ch2);
				switch(ch1)
						{
						case '{':
							if(expression[k] != '}')
								isBalanced=0;
							break;
						case '[':
							if(expression[k] != ']')
								isBalanced=0;
							break;
						case '(':
							if(expression[k] != ')')
								isBalanced=0;
						  break;

						}
			}
			if(isBalanced==0)
				break;
		}


	return isBalanced;

}
