//ATTENTION: This task is'nt done yet!!!
//ATTENTION: This task is'nt done yet!!!
//ATTENTION: This task is'nt done yet!!!
//ATTENTION: This task is'nt done yet!!!
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
tree tr1;
void init(tree tr, int val)
{
  tr->left = NULL;
  tr->right = NULL;
  tr->elem = val;
}

void add_node(tree tr, int val){
  if(val < tr->elem)
  {
    init(tr->left, val);
  }
  else if(val > tr->elem)
  {
    init(tr->right, val);
  }
  else
  {
    fprintf(stderr, RED "%s\n" RESET, "element already exists");
  }
}


void remove_tree(tree tr)
{
  if(tr->left==NULL && tr->right==NULL)
  {
    free(tr);
  }
  else if(tr->left)
    remove_tree(tr->left);
  else if(tr->right)
    remove_tree(tr->right);
}

tree find_elem_and_return(tree tr, int val)
{
  if (!tr)
  {
    fprintf(stderr, RED "%s\n" RESET, "Element not found");
    return tr;
  }
  if(val < tr->elem)
  {
    return find_elem_and_return(tr->left, val);
  }
  else if(val > tr->elem)
  {
    return find_elem_and_return(tr->right, val);
  }
  else
  {
    return tr;
  }
}

void remove

int main()
{
  add_node(tr1, 34);
  add_node(tr1, 56);
  add_node(tr1, 12);
  add_node(tr1, 33);
  add_node(tr1, 12);
}
