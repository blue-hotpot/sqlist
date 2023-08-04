#include<stdio.h>
#include"sqlist.h"
#include<stdlib.h>
#include<string.h> 
sqlink list_creat()
{
	sqlink l;
	l=(sqlink)malloc(sizeof(sqlist));
	if(l==NULL)
	{
		printf("list creat fail\n");
		return l;
	}
	memset(l,0,sizeof(sqlist));
	l->last=-1;
	return l;
}
void list_free(sqlink l)
{
	free(l);
	l=NULL;
}
void list_clear(sqlink l)
{
    memset(l,0,sizeof(sqlist));
	l->last=-1;
}
//
int list_empty(sqlink l)
{
	if(l==NULL)
		return 1;
	else
		return 0;
}


int list_length(sqlink l)
{
    return (l->last+1);
}


int list_locate(sqlink l,data_t value)
{
	int i;
	for(i=0;i<=l->last;i++)
	{
		if(value==l->data[i])
			return i;
	}
	return -1;
}//in problem


int list_insert(sqlink l,data_t value,int position)
{
	if(position<0||position>N-1||l->last==N-1)
	{
		printf("this is fail");
		return -1;
	}
	else
	{
		for(int i=l->last;i>=position;i--)
	    {
		    l->data[i+1]=l->data[i];
	    }
	    l->data[position]=value;
		l->last++;
	    if(position>l->last)
			l->last=position;
		return 0;
	}
}


int list_delete(sqlink l,int position)
{
	int i;
	if(position<0||position>l->last)
	{
		printf("position is fail\n");
		return -1;
	}
	else
	{
		for(i=position;i<l->last;i++)
		{
			l->data[i]=l->data[i+1];
		}
		l->data[i+1]=0;
		l->last--;
		return 0;
	}
}



int list_show(sqlink l)
{
	if(l==NULL)
		return -1;
	for(int i=0;i<=l->last;i++)
	{
		printf("%d ",l->data[i]);
	}
	puts("");
	return 0;
	
}


int list_merge(sqlink l1,sqlink l2)
{
	int j=-1;
	for(int i=0;i<=l2->last;i++)
	{
		j=list_locate(l1,l2->data[i]);
		if(j>=0)
			continue;
		else
			list_insert(l1,l2->data[i],l1->last+1);
	}
	return 0;
}
int list_purge(sqlink l)
{
	int i,j;
	for(i=0;i<l->last;i++)
	{
		for(j=i+1;j<=l->last;j++)
		{
			if(l->data[i]==l->data[j])
			{
				list_delete(l,j);
				j--;
			}
				
		}
	}
	return 0;
}

int list_sort(sqlink l)
{
	int j;
	data_t fl;
	for(int i=0;i<l->last;i++)
	{
		for(j=i+1;j<=l->last;j++)
		{
			if(l->data[j]<l->data[i])
			{
				fl=l->data[i];
				l->data[i]=l->data[j];
				l->data[j]=fl;
			}
		}
	}
	return 0;
}
