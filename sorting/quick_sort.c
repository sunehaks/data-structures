#include<stdio.h>
#include<stdint.h>
#include<assert.h>

void _swap_(int32_t *a, int32_t *b){
	int32_t temp = *a;
	*a = *b;
	*b = temp;
}

static uint32_t _partition_(int32_t list[], uint32_t start, uint32_t end){
	int32_t up, down;
	int32_t piv = list[start];
	up = start;
	down = end;
	do{
		while(list[up]<=piv && up<=down)
			++up;
		while(list[down]>=piv && up<=down)
			--down;
		if(up<=down)
			_swap_(&list[up],&list[down]);
	}while(up<=down);

	_swap_(&list[start],&list[down]);
	return down;
}

void quick_sort(int32_t list[], uint32_t start, uint32_t end){
	if(start<end){
		uint32_t mid = _partition_(list,start,end);
		quick_sort(list,start,mid-1);
		quick_sort(list,mid+1,end);
	}

}

void test_qui(){
	int32_t list[4] = {16,9,80,50};

	quick_sort(list, 0, 3);
	int32_t i,l[4]={9,16,50,80};
	for(i=0;i<4;i++)
		assert(list[i] == l[i]);

}

void main(){
	test_qui();
}