#ifndef SORT_BASE_H
#define SORT_BASE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef DEBUG
#define debug(format,args...) do{fprintf(stderr,"Debug>>>%s->%s()->line.%d:"format"\n",__FILE__,__FUNCTION__,__LINE__,##args);}while(0);
#endif
#define MAX_CAHR_LEN 30 
#define MAX_ARR_LEN 100

typedef struct Element
{
	int num;
} Element;

typedef int (*comp)(void *,void *);


int insert_sort(Element **arr,int arr_len,comp cmpfunc);
int load_arr_from_file(const char *filename,Element **arr,int *arr_num);
int show_arr(Element **arr,int arr_len);
int comparefun(Element *cmp1,Element *cmp2);

#endif
