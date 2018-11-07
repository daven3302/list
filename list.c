#include <stdio.h>
#include <stdlib.h>
int counter = 0;	//use for function append
typedef struct listobj	//listobj
{
	int data,index;
	struct listobj *prev,*next;
}list;
void initialize(list* x)
{
	x->next = NULL;
}

/*void append(list *x,int y)	//insert element
{
	if(counter)		//if this isn't the first node,then do it 
	{
		x->next = (list*)malloc(sizeof(list));
		x->next->prev = x;
		x = x->next;
	}
	x->data = y;
	x->index = counter++;
	printf("a[%d] = %d\n",x->index,x->data);
	initialize(x);
}
*/

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		printf("n = %d\n",n);
		list *a,*head,*end;
		a = (list*)malloc(sizeof(list));
		head = a;
		head->prev = NULL;
		int cache;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&cache);
			//append(a,cache);
			/*if(counter)		//line 44 ~ line 52 is the inner of fuction append 
			{
				a->next = (list*)malloc(sizeof(list));
				a->next->prev = a;
				a = a->next;
			}
			a->data = cache;
			a->index = counter++;
			printf("a[%d] = %d\n",a->index,a->data);
			initialize(a);*/
			end = a;
		}
		a = head;
		int test;
		printf("a[%d] = %d\n",a->index,a->data);
		while(scanf("%d",&test) != EOF)  
		{
			if(test)	//press 1 to store next element 
			{
				if(a->next == NULL) printf("error\n");
				else a = a->next;
			}
			else 		//press 0 to store last element
			{
				if(a->prev == NULL) printf("error\n");
				else a = a->prev;
			}
			printf("a[%d] = %d\n",a->index,a->data);
		}
		while(a->next != NULL) a = a->next;		//a=end
		while(a->prev != NULL) 
		{
			if(a->next != NULL) free(a->next);		//free a
			a = a->prev;
		}
	}
	return 0;
}