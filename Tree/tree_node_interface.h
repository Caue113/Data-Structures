struct tree_node
{
    int key;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree{
    struct tree_node *root;   
};

struct tree_node *tree_node_create();
void tree_insert(struct tree_node *tree, struct tree_node *node);
void tree_delete(struct tree_node *tree, int key);

struct tree_node *tree_search(struct tree_node *tree, int key);

void tree_transverse_preorder(struct tree_node *tree);
void tree_transverse_inorder(struct tree_node *tree);
void tree_transverse_postorder(struct tree_node *tree);

