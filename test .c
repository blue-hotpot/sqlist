#include<stdio.h>
#include"sqlist.h"
void test();
int main(int argc,const char*argv[])
{
    test();
}

void test()
{
	sqlink l;
    l=list_creat();
	list_insert(l,1,0);
	list_insert(l,4,3);
	list_insert(l,2,5);
	list_insert(l,2,6);
	list_insert(l,4,7);
	list_show(l);
	list_purge(l);
	list_show(l);
	list_sort(l);
	list_show(l);
}


