#include<stdio.h>
#include<stdint.h>
#include<assert.h>
#include<string.h>
#include "heap.h"

static void _swap_(int32_t *a, int32_t *b){
	int32_t temp = *a;
	*a = *b;
	*b = temp;
}

static void _heapify_(int32_t data[], uint32_t len, uint32_t par){
	assert(len>0 && len<=HEAP_MAX_SIZE && par>0);

	uint32_t child = 2 * par ; 
	while(child<= len && par>0){
		if(child+1<=len)
			if(data[child]<=data[child+1])
				++child;
		if(data[par]>=data[child])
			break;
		_swap_(&data[par],&data[child]);
		par = child;
		child = 2 * par;
	}
}

static void test_heap(int32_t data[], uint32_t size){
	for (int i = size; i/2 >=1; --i){
		//printf("%d %d\n", data[i],data[i/2]);
		assert(data[i]<=data[i/2]);
	}
}

Heap heap_new(int32_t data[], uint32_t len){
	assert(len>0 && len<HEAP_MAX_SIZE);
	Heap heap;
	for(uint32_t par = len/2; par>=1; --par)
		_heapify_(data,len,par);
	heap.size = len;
	memcpy(heap.data,data,(len+1)*sizeof(int32_t));
	test_heap(heap.data,heap.size);
	return heap;
}

void heap_sort(Heap *heap){
	assert(heap->size>0 && heap->size < HEAP_MAX_SIZE);
	for (int i = heap->size; i >=2; --i)
	{
		_swap_(&heap->data[1],&heap->data[i]);
		_heapify_(heap->data,i-1,1);	/* code */
		//printf("%d\n", heap->data[i]);
	}
}

void heap_add(Heap *heap, int32_t ele){
	assert(heap->size+1 <= HEAP_MAX_SIZE);
	heap->data[heap->size+1] = ele;
	++heap->size;
	_heapify_(heap->data,heap->size,heap->size/2);
}

void test_hs(){
	int32_t list[5] = {0,16,9,80,50};

	Heap heap = heap_new(list,4);
	heap_sort(&heap);
	int32_t i,l[5]={0,80,50,16,9};
	for(i=1;i<5;i++)
		assert(list[i] == l[i]);

}

void test_add(){
	int32_t list[5] = {0,16,9,80,50};

	Heap heap = heap_new(list,4);
	heap_add(&heap,30);
	int32_t l[] = {0,80,50,16,9,30};
	for(int i=1;i<=heap.size;i++)
		assert(heap.data[i] == l[i]);

}

void main(){
	test_hs();
	test_add();
}