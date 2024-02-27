# Tree

Trees are non-linear data structures

Trees are useful to analyse in terms of:

- Tokenizing strings and substrings
- Order of operations (Math operations for example)
- Display a hierarchy (File system)

An example is Abstract Syntax Tree (ABS), used by compilers to understand strings as tokens and recognize specific keywords and what exactly they need and can do.

## Terminology

Root: The top node tree
Child: The direct node to the parent node.
Descendant: A direct or indirect child relative to a node.
Sibling: A node that shares the same parent as other node.
Leaf: Node with no child node
Interior node: Nodes that have children, or simply put, are not leafes.
Level: The number of edges between the root and the selected node. The root node is Level 0;
Height: The maximum depth of a tree
"Forest": A collection of trees (uncommon use?)

## Constituents

General Tree nodes may have the following:

- Key
- A list of children nodes
- Reference to parent node (optional)

For a Binary Tree:

- Key
- Left (node, may be null)
- Right (node, may be null)
- Parent (optional)

## Types of Tree:

### Binary Tree

- Each node has only two child nodes at max
- Allows to search quickly

### Binary Search Tree

They are equivalent to Binary Tree, however with some rules attached:

- The left node must be smaller than the parent node
- The right node must be bigger than the parent node
- All left nodes must be smaller than the root node
- All right nodes must be bigger than the root node

They can also be of two types: Balanced or Unbalanced

Unbalanced trees don't care about the height and depth of the tree. Each insertion simply follows the rules stated before.

The consequences to this are a Linked List like data structure, which causes Searching and Insertion operations to have O(n).

Balanced trees have another rule: the left side must have equal number of nodes of the right side. This provides us operations with O(log n)


### Ternary Tree

- Each node must have only 3 nodes at max

### N-ary Tree

- Each node may have N number of nodes. No limit imposed.

## Operations

- Create: Create a tree
- Insert: Insert a node into the tree, following the given rules of it
- Delete: Delete a node in the tree, following the given rules of it
- Search: Finds a node with a given key
- Transverse
  - Preorder: Begin with leftmost tree, then to root, then finally to rightmost tree
  - Inorder: Begin from root, then to the leftmost tree, then finally to rightmost tree
  - Postorder: Begin with leftmost tree, then to rightmost tree, then finally to root


Some uncommon

- Prunning: removing an entire section (in bulk?)
- Grafting: adding an entire section (in bulk?)