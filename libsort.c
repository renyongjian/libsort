#include"libsort.h"

int load_arr_from_file(const char *filename,Element **arr,int *arr_num)
{
	if (NULL == filename || NULL == arr)
	{
		return -1;
	}

	FILE *fp = fopen(filename,"r");
	if (NULL == fp)
	{
		return -1;
	}
	
	char buff[MAX_CAHR_LEN] = "";
	int i=0;
	while (NULL != fgets(buff,MAX_CAHR_LEN,fp))
	{
		int num = atoi(buff);
		arr[i] = malloc(sizeof(int));
		memset(arr[i],0x00,sizeof(int));
		arr[i]->num  = num;
		*arr_num = i;
		i++;
		if (i > MAX_ARR_LEN)
		{
			return 0;	
		}
	}
	return 0;
}


int show_arr(Element **arr,int arr_len)
{
	if (NULL == arr || arr_len == 0)
	{
		return -1;
	}

	int i ;
	for (i=0; i<=arr_len; i++)
	{
		if (NULL == arr[i])
		{
			return -1;
		}
		printf("Element Arr[%d] is %d\n",i,arr[i]->num);
	}
}


int comparefun(Element *cmp1,Element *cmp2)
{
	if (NULL == cmp1 || NULL == cmp2)
	{
		return -1;
	}
	if(cmp1->num > cmp2->num)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*
 * insert_sort 
 * data : 2018/4/12
 * */
int insert_sort(Element **arr,int arr_len,comp cmpfunc)
{
	if (NULL == arr || arr_len == 0 || NULL == cmpfunc)
	{
		return -1;
	}

	int i,j;
	for (i=1; i<=arr_len; i++)
	{
		Element *tmp = arr[i];
		for (j = i-1; j>=0; j--)
		{
			if (cmpfunc(arr[j],tmp)>0)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = tmp;
	}
}

/*
 * quick_sort 
 *data : 2018/4/12
 *
 * */
int quick_sort(Element **arr,int left,int right,comp cmpfunc)
{
	if (NULL == arr || left >= right || NULL == cmpfunc)	
	{
		return -1;
	}
	int i = left,j = right;
	Element *tmp = arr[i];
	while(i<j)
	{
		while ((i<j) && (cmpfunc(arr[j],tmp)>0))
		{
			j--;
		}
		arr[i] = arr[j];
		while ((i<j) && (cmpfunc(arr[i],tmp)<=0))
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = tmp;
	quick_sort(arr,left,i-1,cmpfunc);
	quick_sort(arr,i+1,right,cmpfunc);
}

/*
 *
 * merger_sort
 * 注意这里使用的是元素个数来进行归并的，也可以使用下标进行归并，使用下标进行归并的时候，传入的SR是不能改变的。
 * date : 2018/4/13
 * */
int merger(Element **sr,Element **tr,int srsize ,int trsize,comp comparefun)
{
	if (NULL == sr || NULL == tr)
	{
		return -1;
	}

	int i,j,k,t;
	i=j=k=0;
	Element *tmp[srsize+trsize+1];
	while(i<srsize && j<trsize)
	{
		if (comparefun(sr[i],tr[j])>0)
		{
			tmp[k++] = tr[j++];
		}
		else
		{
			tmp[k++] = sr[i++];
		}
	}
	while (i < srsize)
	{
		tmp[k++] = sr[i++];
	}

	while (j< trsize)
	{
		tmp[k++] = tr[j++];
	}
	
	for (t=0; t<(srsize+trsize); t++)
	{
		sr[t] = tmp[t];
		debug("merger sr[t] = %d",sr[t]->num);
	}

}

int merger_sort(Element **sr,int n,comp comparefun)
{
	if (NULL == sr)
	{
		return -1;
	}

	if (n<= 1)
	{
		return -1;
	}

	int mid = n/2;
	merger_sort(&sr[0],mid,comparefun);
	merger_sort(&sr[mid],n-mid,comparefun);
	merger(&sr[0],&sr[mid],mid,n-mid,comparefun);
}

/*
 * heap_sort
 * data :　2018/4/14
 * */

int heap_adust(Element **arr,int index,int max_element,comp comparefun)
{
	if (NULL == arr || index < 0)
	{
		return -1;
	}

	int i,m = max_element;
	Element *tmp = arr[index];
	debug("the index is %d",index);
	for (i=2*index+1;i<m;i=i*2+1)
	{
		if ((i<m-1)&&comparefun(arr[i],arr[i+1])<=0)
		{
			i++;
		}
		if (comparefun(arr[i],tmp)<=0)
		{
			break;
		}
		arr[index] = arr[i];
		index = i;
	}
	arr[index] = tmp;
}


int swap(Element **arr,int index1,int index2)
{
	if (NULL == arr || index1 < 0 || index2 < 0)
	{
		return -1;
	}
	Element *tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}


int heap_sort(Element **arr,int arr_num,comp comparefun)
{
	if (NULL == arr)
	{
		return -1;
	}
	
	int i=0,n=arr_num;
	for(i=n/2-1;i>=0;i--)
	{
		heap_adust(arr,i,n,comparefun);
	}

	for (i=n-1; i>=0; i--)
	{
		swap(arr,0,i);
		heap_adust(arr,0,i,comparefun);
	}
}
