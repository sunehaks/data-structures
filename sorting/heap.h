#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include<stdint.h>
#include<assert.h>

#define HEAP_MAX_SIZE 32

typedef struct _heap_ Heap;

struct _heap_
{
	uint32_t size;
	int32_t data[HEAP_MAX_SIZE];
};


Heap heap_new(int32_t data[], uint32_t len);
void heap_add(Heap *heap, int32_t ele);
void heap_sort(Heap *heap);

#endif
