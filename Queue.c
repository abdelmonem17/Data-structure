
#include "Queue.h"
#include "stdlib.h"
void createQueue(ST_queueInfo* info, queue_size_Type maxSize)
{

	info->queue_pointer=(queue_data_Type *)malloc(sizeof(queue_data_Type) * maxSize);
	info->start=info->end=0;
	info->queue_maxSize=maxSize;

}
void enqueue(ST_queueInfo *info, queue_data_Type data)
{

	if(info->end != info->queue_maxSize )
		{
			info->queue_pointer[info->end]=data;
			++info->end;
		}
	else if(info->end == info->queue_maxSize && info->start!=0)
	{
		if(info->start == info->queue_maxSize)
			{
					info->start=0;
			}
		info->end=0;
		info->queue_pointer[info->end]=data;
		++info->end;
	}
	else
	{
			printf("error queue is full\n");
	}
}

void dequeue(ST_queueInfo *info, queue_data_Type* data)
{


	if(info->queue_maxSize > info->start  )
	 {
				*data =info->queue_pointer[info->start];
				++info->start;
	  }
	else if(info->end != info->start)
	{
		if(info->start == info->queue_maxSize)
		{
			info->start=0;
		}
		*data =info->queue_pointer[info->start];
		++info->start;
	}
	else
	{
			printf("error empty is empty\n");
	}
}
