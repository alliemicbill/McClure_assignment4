// BinaryTree Header File
#ifndef NODE
#define NODE

template<class T>
struct NodeType{

  T key;
  Node<T> *left;
  Node<T> *right;
};
#endif //NODE

#ifndef BTREE
#define BTREE

template<class T>
class BinaryTree{

 private:

  NodeType *root;  

 public:

 BinaryTree();
  ~BinaryTree();
  void insert(T key);
  void deleteItem(T key);
  void retrieve(T &item, bool &found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  int countNodes(NodeType * tree) const;
  void getItem(NodeType *tree, T &item, bool &found) const;
  void putItem(NodeType *&tree, T item);
  void deleteRec(NodeType *&tree, T item);
  void deleteNode(NodeType *&tree);
  void getPredecessor(NodeType *tree, T &data);
  void printInOrder(NodeType *tree) const;
  void printPreOrder(NodeType *tree) const;
  void printPostOrder(NodeType *tree) const;
  void destroy(NodeType *&tree);
};//BinaryTree
