/*
 * Queue.h
 *
 *  Created on: Oct 30, 2019
 *      Author: AVE-LAP-062
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdint.h>
#include <stdio.h>


typedef int32_t queue_data_Type ;
typedef uint16_t queue_size_Type ;
typedef	struct{

	queue_data_Type *queue_pointer;
	queue_size_Type  queue_maxSize;
	queue_size_Type  start;
	queue_size_Type  end;
}ST_queueInfo;
void createQueue(ST_queueInfo* info, queue_size_Type maxSize);
void enqueue(ST_queueInfo *info, queue_data_Type data);
void dequeue(ST_queueInfo *info, queue_data_Type* data);


#endif /* QUEUE_H_ */
