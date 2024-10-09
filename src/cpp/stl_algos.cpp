/**********************************************************
 * Author: Onkar Rajopadhye
 *
 * How to run this program:
 * [prompt]$ g++ -Wall -g stl_algos.cpp -o stl_algos
 * [prompt]$ ./stl_algos
 *
**********************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;


// Sorts first elem of a pair in ascending and second element in descending order
bool compPairMixedOrder(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first == b.first && a.second > b.second) {
    return true;
  }
  return false;    
}

#define MARKER -1     // For NULL nodes
 
// A binary tree Node has key,
// pointer to left and right children
struct Node {
    int          key;          // to be generic, this should be string 
    struct Node *left, *right;
};
 
// Helper function that allocates a new Node with the
// given key and NULL left and right pointers.
struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
// This function stores a tree in a file pointed by fp
void serialize(Node* root, FILE* fp)
{
    // If current node is NULL, store marker
    if (root == NULL) {
        fprintf(fp, "%d ", MARKER);
        return;
    }
 
    // Else, store current node and 
    // recur for its children
    fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}
 
// This function constructs a tree from 
// a file pointed by 'fp'
void deSerialize(Node*& root, FILE* fp)
{
    // Read next item from file. 
    // If there are no more items
    // or next item is marker, then return
    int val;
    if (!fscanf(fp, "%d ", &val) || val == MARKER)
        return;
 
    // Else create node with this item 
    // and recur for children
    root = newNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}
 
// A simple inorder traversal used for 
// testing the constructed tree
void inorder(Node* root)
{
    if (root) {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}
 
// Driver code
int treeSerDe()
{
    // Construct a tree shown in the above figure
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
 
    // Open a file and serialize the tree into the file
    FILE* fp = fopen("tree.txt", "w");
    if (fp == NULL) {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);
 
    // Deserialize the stored tree into root1
    Node* root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);
 
    cout << "Inorder Traversal of the tree constructed from file:\n";
    inorder(root1);
    cout << '\n';
 
    return 0;
}

int main() {
  std::vector<std::pair<int,int>> v2 = {{6,3}, {6,4}, {1,3}, {1,5}, {5,5}};
  std::sort(v2.begin(), v2.end(), compPairMixedOrder);

  std::cout << "\nContents after sorting:\n";
  for (auto i: v2) {
    std::cout << i.first << ", " << i.second << '\n';
  }

  cout << "\n================= next_permutation ==============================\n";
  std::string str("abc"); // already sorted
  cout << "Printing all permutations of a string:\n" << str << '\n';
  while(std::next_permutation(str.begin(), str.end())) {
    cout << str << '\n';
  }


  cout << "\n================= Tree SerDe ==============================\n";
  treeSerDe();

  return 0;
}