#ifndef _BSTREE_H
#define _BSTREE_H

#include <cstdint>
#include <stdexcept>

template<typename TreeType>
struct TreeNode {

};

template <class TreeType>
class SortedLinearList {

  public:

    SortedLinearList() {
      root = nullptr;
    }

    ~SortedLinearList() {
      prvClear(root);
    }

    void clear() {
      prvClear(root);
      root = nullptr;
    }

    bool isEmpty() {
      return root == nullptr;
    }

    int32_t size() {
      if (root == nullptr) {
        return 0;
      }

      return root -> count;
    }

    int32_t height() {
      if (root == nullptr) {
        return 0;
      }

      return root -> height;
    }

    int32_t search(TreeType) {

    }

    TreeType &operator[](int32_t) {

    }

    void traverse(void (*fp)(TreeType &)) {
      prvTraverse(root, fp);
    }

    void insert(TreeType) {

    }

    void remove(TreeType) {

    }

  private:

    void prvClear(TreeNode<TreeType> *) {

    }

    void prvTraverse(TreeNode<TreeType> *, void (*)(TreeType &)) {

    }
};

#endif