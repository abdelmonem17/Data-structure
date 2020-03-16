/*
 * student.c
 *
 *  Created on: Nov 1, 2019
 *      Author: Eng Abdo
 */

#include "Database.h"

//number of databases
static uint16_t databases_count=0;

static New_Database  *databases_Repo[MAX_DATABASES];

void user_monitoring(void)
{

	  StudentDatabase_Query_E query_type ;
	  uint32_t num_queries=22;
	  ST_queueInfo queries;

	  printf("Please Enter Number of Queries:");
	  fflush(stdout);
      scanf("%d",&num_queries);
	  printf("Please choose the queries: \n		1- Create DataBase. \n		2- Insert to DataBase.\n		3- Delete from the DataBase.\n		4- Search into the DataBase.\n		5- Sort the DataBase.\n		6- Operation on two nodes\n");
	  printf("waiting for your response...\n");
	  fflush(stdout);

		//create queue of queries
	   createQueue(&queries,num_queries);
		//handling queries
	for(int16_t i=0;i<num_queries;i++)
	{
		//take queries from user and store it in the queue
		scanf("%d",(int32_t *)&query_type);
		enqueue(&queries,query_type);
	}


	//restoring queries from the queue and handling them
	for(int16_t i=0;i<num_queries;i++)
	{
		dequeue(&queries,(queue_data_Type *)&query_type);

		switch((uint16_t)query_type)
		{
			case Create:
				Database_Create();
				break;
			case Insert:
				Database_Insert();
				break;
			case Delete:
				Database_Delete();
				break;
			case Search:
				Database_Search();
				break;
			case Sort:
				database_Sort();
				break;
			case Operation:
				database_operationOn2Nodes();
				break;
			default:
				printf("invalid opertion\n");
				break;

		}
	}

}

void Database_Create(void)
{
	New_Database *pDatabase=(New_Database *)malloc(sizeof(New_Database));
	printf("Creating a Database ...\n");
	if( createList(pDatabase) !=0)
	{
		databases_Repo[databases_count++]=pDatabase;
		printf("Database Created Successfully!!!\n");
		printf("Number of DBs is %d\n",databases_count);
	}
	else
	{
		printf("Unable to create a Database!!!!\n");
	}

}

void Database_Insert(void)
{
	uint32_t database_number;
	database_size_Type position;
	database_data_Type data;

	printf("Please Select DB to insert into: ");
	fflush(stdout);
	scanf("%d",&database_number);
	printf("Please Enter Data to insert: ");
	fflush(stdout);
	scanf("%d",&data);
	printf("Please enter the position to insert into: ");
	fflush(stdout);
	scanf("%d",&position);
	--position;
    if(database_number <= databases_count)
    {
        if( insertToList(databases_Repo[database_number-1],position,data) !=0)
        {
            printf("Data Inserted successfully!!\n");
        }
        else
        {
            printf("unsble to insert data!!!!!\n");
        }
    }
    else
    {
        printf("sorry the this database not found\n");
    }

}

void Database_Delete(void)
{
	uint32_t database_number;
	database_size_Type position;
	database_data_Type unused_data;


	printf("Please Select DB to delete from: ");
	fflush(stdout);
	scanf("%d",&database_number);
	printf("Please enter the position to delete from: ");
	fflush(stdout);
	scanf("%d",&position);
	--position;
	if(database_number <= databases_count)
	{


		if(deleteFromList(databases_Repo[database_number-1],position,&unused_data) !=0)
		{
			printf("deleted successfully!!\n");
		}
		else
		{
			printf("unsble to delete data!!!!!\n");
		}
	}

	else
	{
		printf("sorry the this database not found\n");
	}


}
void Database_Search(void)
{

		uint32_t database_number;
		database_data_Type data;


		printf("Please Select DB to search into: ");
		fflush(stdout);
		scanf("%d",&database_number);
		printf("Please enter the data to be found: ");
		fflush(stdout);
		scanf("%d",&data);

        if(database_number <= databases_count)
        {

            if(searchIntoList(databases_Repo[database_number-1],data) !=NULL)
                {
                    printf("data found successfully!!\n");
                }
                else
                {
                    printf("unsble to find data!!!!!\n");

                }

        }
        else
        {
            printf("sorry the this database not found\n");
        }


}
void database_Sort(void)
{
	uint32_t database_number;
	printf("Please Select DB to sort: ");
	fflush(stdout);
	scanf("%d",&database_number);

	if(database_number <= databases_count)
	{
		if(databases_Repo[database_number-1]->size > 1)
			sortList(databases_Repo[database_number-1]);
		else
		{
			printf("sorry database must have 2 records at least to be sorted\n");
		}
	}
	else
	{
		printf("sorry the this database not found\n");
	}

}
void database_operationOn2Nodes(void)
{

	uint32_t database_number;
	char expression[50]={0};

	stack_size_Type exp_size=0,queue_usedSize=0;
	ST_queueInfo queue;
	int32_t num=0;
	int32_t result;
	database_data_Type operand2,operand1;
	queue_data_Type position;
	int32_t operation;

	//geting database number and the expression to be evaluted
	printf("Please Select DB to operate on: ");
	fflush(stdout);
	scanf("%d",&database_number);
	printf("Please enter the the expression to be evaluted: ");
	fflush(stdout);
	scanf("%s",expression);
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
		return;
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


		if(database_number <= databases_count)
		{

			//handle operations
			dequeue(&queue,&position);
			--position;
			getDataInList(databases_Repo[database_number-1],(linkedlist_size_Type)position,&operand1);
			result=operand1;
			for(int i=0;i<queue_usedSize/2;i++)
			{
				dequeue(&queue,&operation);
				//dequeue(&queue,&operand2);
				dequeue(&queue,&position);
				--position;
				getDataInList(databases_Repo[database_number-1],(linkedlist_size_Type)position,&operand2);
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

			printf("the result of expression is: %d\n",result);
		}
		else
		{
			printf("sorry the this database not found\n");
		}

	}

}
