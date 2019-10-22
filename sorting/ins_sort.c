#include<stdio.h>
#include<stdint.h>
#include<assert.h>

void _swap_(int32_t *a, int32_t *b){
	int32_t temp = *a;
	*a = *b;
	*b = temp;
}

void insertion_sort(int32_t list[], uint32_t size){
	int32_t pass, idx,key;
	for(pass=1;pass<=size-1;pass++){
		key = list[pass];
		for(idx = pass-1;idx>=0;idx--){
			if(key<list[idx])
				list[idx+1]=list[idx];
		
			list[idx+1]=key;
		}

	}

}

void test_ins(){
	int32_t list[4] = {16,9,80,50};

	insertion_sort(list, 4);
	int32_t i,l[4]={9,16,50,80};
	for(i=0;i<4;i++)
		assert(list[i] == l[i]);

}

void main(){
	test_ins();
}