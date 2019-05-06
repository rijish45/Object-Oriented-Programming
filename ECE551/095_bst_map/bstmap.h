#ifndef BST_MAP_H
#define BST_MAP_H

#include <iostream>

#include "map.h"
using namespace std;

template<typename K, typename V>
class BstMap : public Map<K, V>
{
 private:
  class Node
  {
   public:
    K key;
    V value;
    Node * left;
    Node * right;

    Node(K k, V v) : key(k), value(v), left(NULL), right(NULL) {}
  };

  Node * root;

 public:
  BstMap() : root(NULL) {}
  BstMap(const BstMap & bmap) : root(NULL) { assignmentHelper(bmap.root); }
  ~BstMap() { freeHelper(root); }

  void assignmentHelper(Node * current) {
    if (current != NULL) {
      add(current->key, current->value);
      assignmentHelper(current->left);
      assignmentHelper(current->right);
    }
  }

  BstMap & operator=(const BstMap & bmap) {
    if (this == &bmap)
      return *this;
    freeHelper(root);
    root = NULL;
    assignmentHelper(bmap.root);
    return *this;
  }

  void freeHelper(Node * current) {
    if (current != NULL) {
      freeHelper(current->left);
      freeHelper(current->right);
      delete current;
    }
  }

  void printHelper(Node * current) {
    if (current != NULL) {
      cout << current->key << "  ";
      printHelper(current->left);
      printHelper(current->right);
    }
  }

  void printTesting() { printHelper(root); }
  Node * add(Node * current, const K & key, const V & value) {
    if (current == NULL) {
      Node * tmp = new Node(key, value);
      return tmp;
    }
    else if (key == current->key) {
      current->value = value;
      return current;
    }

    if (key < current->key)
      current->left = add(current->left, key, value);
    else
      current->right = add(current->right, key, value);

    return current;
  }

  const V & lookup(const K & key) const throw(std::invalid_argument) {
    Node * current = root;
    while (current != NULL) {
      if (key == current->key)
        break;
      else if (key < current->key)
        current = current->left;
      else
        current = current->right;
    }
    if (current == NULL)
      throw std::invalid_argument("key not found!!");

    return current->value;
  }

  Node * removeHelper(Node * current, const K & key) {
    if (current == NULL)
      return current;

    if (key == current->key) {
      if (current->left == NULL) {
        Node * tmp = current->right;
        delete current;
        return tmp;
      }
      else if (current->right == NULL) {
        Node * tmp = current->left;
        delete current;
        return tmp;
      }
      else {
        Node * tmp = current->right;
        Node * parent = current;
        bool right_null = true;

        while (tmp->left != NULL) {
          parent = tmp;
          tmp = tmp->left;
          right_null = false;
        }

        current->key = tmp->key;
        current->value = tmp->value;

        if (right_null)
          parent->right = tmp->right;
        else
          parent->left = tmp->right;

        delete tmp;
        return current;
      }
    }

    else if (key < current->key) {
      current->left = removeHelper(current->left, key);
      return current;
    }
    else {
      current->right = removeHelper(current->right, key);
      return current;
    }
  }

  void add(const K & key, const V & value) { root = add(root, key, value); }

  void remove(const K & key) { root = removeHelper(root, key); }
};

#endif
