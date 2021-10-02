
#include <stdio.h>
#include <stdlib.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
struct tree_node
{
	struct tree_node *left , *right;
	int elem;
};
typedef struct tree_node* tree;



tree init(int val)
{
	tree tr = malloc(sizeof(struct tree_node));
	tr->left = NULL;
	tr->right = NULL;
	tr->elem = val;
	return tr;
}

tree add_node_with_val(tree tr, int val){
	if(!tr)
	{
		tr = init(val);
	}
	else if(tr->left && val < tr->elem)
	{
		add_node_with_val(tr->left, val);
	}
	else if(!tr->left && val < tr->elem)
	{
		tr->left = init(val);
	}
	else if(tr->right && val > tr->elem)
	{
		add_node_with_val(tr->right, val);
	}
	else if(!tr->right && val > tr->elem)
	{
		tr->right = init(val);
	}
	else if(tr->elem == val)
	{
		fprintf(stderr, RED "%s\n" RESET, "element already exists");
	}
	return tr;
}

tree add_node(tree tr, tree node){
	if(!tr)
	{
		tr = node;
	}
	else if(tr->left && node->elem < tr->elem)
	{
		add_node_with_val(tr->left, node);
	}
	else if(!tr->left && node->elem < tr->elem)
	{
		tr->left = node;
	}
	else if(tr->right && node->elem > tr->elem)
	{
		add_node_with_val(tr->right, node);
	}
	else if(!tr->right && node->elem > tr->elem)
	{
		tr->right = node;
	}
	else if(tr->elem == node->elem)
	{
		fprintf(stderr, RED "%s\n" RESET, "element already exists");
	}
	return tr;
}


int is_val_in_tree(tree tr, int val)
{
	if(val == tr->elem)
		return 1;
	if(tr->left && val < tr->elem)
		return is_val_in_tree(tr->left, val);
	if(tr->right && val > tr->elem)
		return is_val_in_tree(tr->right, val);
	if(!tr->left && !tr->right)
		return 0;
}

tree find_node(tree tr, int val)
{
	if(val == tr->elem)
		return tr;
	if(tr->left && val < tr->elem)
		return find_node(tr->left, val);
	if(tr->right && val > tr->elem)
		return find_node(tr->right, val);
	if(!tr->left && !tr->right)
		return NULL;
}

void remove_tree(tree tr)
{
	if(tr->left)
	{
		remove_tree(tr->left);
		free(tr->left);
		tr->left = NULL;

	}
	if(tr->right)
	{
		remove_tree(tr->right);
		free(tr->right);
		tr->right = NULL;

	}

}


tree copy_tree(tree tr)
{
	if (tr)
	{
		tree trNew = init(tr->elem);
		trNew->left = copy_tree(tr->left);
		trNew->right = copy_tree(tr->right);
		return trNew;
	}
	return NULL;
}

tree remove_node(tree tr, tree nodest)
{
	tree node = copy_tree(nodest);
	if(tr)
	{
		if(tr->left)
		{
			if (tr->left->elem == node->elem)
			{
				tree tempLeft = node->left;
				tree tempRight = node->right;

				remove_tree(tr->left);
				free(tr->left);
				tr->left = NULL;

				if (tempLeft)
					tr = add_node(tr, tempLeft);
				if (tempRight)
					tr = add_node(tr, tempRight);

				return tr;
			}
		}
		if(tr->right)
		{
			if (tr->right->elem == node->elem)
			{
				tree tempLeft = node->left;
				tree tempRight = node->right;

				remove_tree(tr->right);
				free(tr->right);
				tr->right = NULL;

				if (tempLeft)
					tr = add_node(tr, tempLeft);
				if (tempRight)
					tr = add_node(tr, tempRight);
				return tr;
			}
		}
		tr->left = remove_node(tr->left, node);
		tr->right = remove_node(tr->right, node);
		return tr;

	}
	return NULL;
}
/*
 *       1
 *     0   5
 *        3
 *         6
 *
 *
 */
int char2intDigit(char c)
{
	return c-'0';
}

int char2int(char c[])
{
	int ind1 = 1;
	int res = 0;
	//integer part
	while (c[ind1])
	{
		res = (res * 10) + char2intDigit(c[ind1]);
		++ind1;
	}
	return res;
}

int main()
{
	tree tr1 = NULL;
	char temp[20];
	while(scanf("%s", &temp)!=EOF)
	{
		int num = char2int(temp);
		printf("%d\n", num);
		if(temp[0]=='+')
			tr1 = add_node_with_val(tr1, num);
		else if(temp[0]=='-')
		{
			tree ndTemp = find_node(tr1, num);
			remove_node(tr1, ndTemp);
		}
		else if(temp[0]=='?')
		{
			if(is_val_in_tree(tr1, num))
				printf("Element found\n");
			else
				printf("Element not found\n");
		}
	}
//	tr1 = add_node_with_val(tr1, 24);
//	tr1 = add_node_with_val(tr1, 26);
//	tr1 = add_node_with_val(tr1, 67);
//	tr1 = add_node_with_val(tr1, 68);
//	tree nd = find_node(tr1, 67);
//	remove_node(tr1, nd);
}