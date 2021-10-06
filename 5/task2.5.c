#include <stdio.h>
#include <stdlib.h>
#define sizeArr 100
struct list_node
{
	char* elem;
	struct list_node* next;
};
typedef struct list_node* list;

list init(char* s)
{
	list l = malloc(sizeof(struct list_node));
	int i = 0;
//	char* st = s;
//	while(s[i])
//	{
//		l->elem = &s[i];
//		++i;
//		l->elem = *(&(l->elem)+1);
//	}
	l->elem = malloc(sizeof(char)*100);
	while(s[i])
	{
		l->elem[i] = s[i];
		++i;
	}
//	l->elem -= i;
	l->next = NULL;
	return l;
}


list add_node(list l, list nd)
{
	if(!l->next)
	{
		l->next = nd;
		return l;
	}
	else
	{
		l->next = add_node(l->next, nd);
		return l;
	}
}

list add_str(list l, char* s)
{
	list temp = init(s);
	return add_node(l, temp);
}

list remove_next_node(list l)
{
	list temp = l->next->next;
	free(l->next);
	l->next = temp;
	return l;
}

list remove_all_identical_nodes(list l, char* s)
{
	if(l->next->next)
	{
		int b = 1;
		int i = 0;
		while(s[i])
		{
			if(l->next->elem[i] != s[i])
				b = 0;
			++i;
		}
		if(b)
		{
			l = remove_next_node(l);
			l = remove_all_identical_nodes(l, s);
			return l;
		}
		else
		{
			l->next = remove_all_identical_nodes(l->next, s);
			return l;
		}
	}
	else
		return l;
}

void print_list(list l)
{
	if(l)
	{
		printf("%s\n", l->elem);
		print_list(l->next);
	}
}

int main()
{
	char* temp;
	char* temp0 = "begin";
	list l1 = init(temp0);
	char tt[100];
	while(scanf("%s", &tt) != EOF)
	{
//		temp0 = NULL;
		list ndTemp = init(tt);
		l1 = add_node(l1, ndTemp);
		printf("Got it\n");
	}
	printf("WAS:\n");
	print_list(l1);
	l1 = remove_all_identical_nodes(l1, tt);
	printf("\n\nBECAME:\n");
	print_list(l1);
}