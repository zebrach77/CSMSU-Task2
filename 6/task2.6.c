#include <stdio.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
struct tree_node
{
  struct tree_node *left , *right;
  int elem;
};
typedef struct tree_node* tree;

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
  if(tr->left==NULL)
  {
    
  }
  else
  {

  }
}
