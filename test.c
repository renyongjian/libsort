#include"libsort.h"


int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		debug("need more params");
		return -1;
	}
	char *filename = argv[1];
	Element *Arr[MAX_CAHR_LEN];
	int arr_num = 0; 
	debug("start insert_sort test");
	load_arr_from_file(filename,Arr,&arr_num);
	insert_sort(Arr,arr_num,comparefun);
	show_arr(Arr,arr_num);
	debug("end insert_sort test");
	debug("start quick_sort test");
	load_arr_from_file(filename,Arr,&arr_num);
	quick_sort(Arr,0,arr_num,comparefun);
	show_arr(Arr,arr_num);
	debug("end quick_sort test");
	debug("start M_sort test");
	debug("arr_num = %d",arr_num);
	load_arr_from_file(filename,Arr,&arr_num);
	merger_sort(Arr,arr_num+1,comparefun);
	show_arr(Arr,arr_num);
	debug("end M_sort test");
	debug("start heap_sort test");
	load_arr_from_file(filename,Arr,&arr_num);
	heap_sort(Arr,arr_num+1,comparefun);
	show_arr(Arr,arr_num);
	debug("end heap_sort test");
	return 0;
}
