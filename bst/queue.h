#ifndef _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_
#include<stdint.h>

#define MAX_DEPTH 32

typedef struct _queue_ Q;
typedef struct _queue_result_ Res;

struct _queue_{
	uint32_t size;
	uint32_t count;
	uint32_t head;
	uint32_t tail;
	int32_t data[MAX_DEPTH];
};

struct _queue_result_
{
	int32_t data;
	int32_t status;	
};

#define QUEUE_OK 1
#define QUEUE_FULL 2
#define QUEUE_EMPTY 3

Q queue_new(uint32_t size);
Res queue_res();
uint32_t queue_full(Q *q);
uint32_t queue_empty(Q *q);
Q* queue_add(Q *q, int32_t ele, Res *res);
Q* queue_delete(Q *q, Res *res);

#endif