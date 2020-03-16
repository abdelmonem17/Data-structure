/******************************************************************************

Copyright (C) 2019 Abdelmonem Mostafa
Redistribution, modification or use of this software in source or binary
forms is permitted as long as the files maintain this copyright. Users are
permitted to modify this and use it to learn about the field of embedded
software.
********************************************************************************/

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Stack.h"
#include "Queue.h"
#include "Req2.h"

#define MAX_DATABASES 50

typedef ST_list New_Database;
typedef linkedlist_data_Type database_data_Type ;
typedef linkedlist_size_Type database_size_Type;
typedef New_Node New_Student;

/*********************************************************************
 *
 *	operation in database options
********************************************************************/
typedef enum {
	Create=1,
	Insert,
	Delete,
	Search,
	Sort,
	Operation
}StudentDatabase_Query_E;



/****************************************************************************
*
*   @brief function takes options from user and manpulate the data
*
*   @params  void
*   @return  void
****************************************************************************/

void user_monitoring(void);

/****************************************************************************
*
*   @brief function creates new database
*
*   @params  void
*   @return  void
****************************************************************************/
void Database_Create(void);

/****************************************************************************
*
*   @brief  function inserts data in a spacific place in database
*
*   @params  void
*   @return  void
****************************************************************************/
void Database_Insert(void);

/****************************************************************************
*
*   @brief function delete data from spacific place in database
*
*   @params  void
*   @return  void
****************************************************************************/
void Database_Delete(void);

/****************************************************************************
*
*   @brief function searchs for spacifc data in a spacifc database
*
*   @params  void
*   @return  void
****************************************************************************/
void Database_Search(void);

/****************************************************************************
*
*   @brief function sorts a spacific database
*
*   @params  void
*   @return  void
****************************************************************************/
void database_Sort(void);

/****************************************************************************
*
*   @brief function make an operation on data from a database according to an expression
*   such as 1+2 means add first element to the second from the database
*
*   @params  void
*   @return  void
****************************************************************************/
void database_operationOn2Nodes(void);

#endif
