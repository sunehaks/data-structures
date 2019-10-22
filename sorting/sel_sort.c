#include<stdio.h>
#include<stdint.h>
#include<assert.h>

void _swap_(int32_t *a, int32_t *b){
	int32_t temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int32_t list[], uint32_t size){
	int32_t pass, idx, minpos;
	for(pass=0;pass<=size-1;pass++){
		minpos = pass;
		for(idx = pass+1;idx<=size-1;idx++){
			if(list[idx]<list[minpos])
				minpos = idx;
		
			_swap_(&list[pass],&list[minpos]);
		}

	}

}

void test_sel(){
	int32_t list[4] = {16,9,80,50};

	selection_sort(list, 4);
	int32_t i,l[4]={9,16,50,80};
	for(i=0;i<4;i++)
		assert(list[i] == l[i]);

}

void main(){
	test_sel();
}