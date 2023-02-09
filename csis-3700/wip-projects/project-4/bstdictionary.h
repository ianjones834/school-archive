//Ian Jones

#ifndef _BST_DICTIONARY_H
#define _BST_DICTIONARY_H

#include <cstdint>
#include <stdexcept>
#include <algorithm>
using namespace std;

static const uint32_t
  NULL_INDEX = 0xffffffff,
  DEFAULT_INITIAL_CAPACITY = 16;

template <typename KeyType, typename ValueType>
class BSTDictionary {
  public:
    explicit BSTDictionary(uint32_t cap = DEFAULT_INITIAL_CAPACITY) {
      if (nTrees == 0) {
        counts = new uint32_t[cap];
        heights = new uint32_t[cap];
        left = new uint32_t[cap];
        right = new uint32_t[cap];
        keys = new KeyType[cap];
        values = new ValueType[cap];

        capacity = cap;

        for (int i = 0; i < cap; i++) {
          left[i] = i + 1;
        }

        left[cap - 1] = NULL_INDEX;
        freeListHead = 0;
      }

      nTrees++;
      root = NULL_INDEX;
    }

    ~BSTDictionary() {
      nTrees--;

      if (nTrees == 0) {
        delete[] counts;
        delete[] heights;
        delete[] left;
        delete[] right;
        delete[] keys;
        delete[] values;
      }
      else {
        prvClear(root);
      }
    }

    void clear() {
      prvClear(root);
      root = NULL_INDEX;
    }

    uint32_t size() {
			if (root == NULL_INDEX) {
				return 0;
			}

      return counts[root];
    }

    uint32_t height() {
			if (root == NULL_INDEX) {
				return 0;
			}

      return heights[root];
    }

    bool isEmpty() {
      return root == NULL_INDEX;
    }

    ValueType &search(const KeyType &k) {
      uint32_t n = root;

      while (n != NULL_INDEX) {
        if (k == keys[n]) {
          return values[n];
        }
        else if (k < keys[n]) {
          n = left[n];
        }
        else {
          n = right[n];
        }
      }

      throw domain_error("Search: Key not found");
    }

    ValueType &operator[](const KeyType &k) {
      uint32_t tmp = prvAllocate();
      uint32_t n = tmp;

      root = prvInsert(root, n, k);

      if (n != tmp) {
        prvFree(tmp);
      }

      return values[n];
    }

    void remove(const KeyType &k) {
			uint32_t n = NULL_INDEX;
      root = prvRemove(root, n, k);

      if (n != NULL_INDEX) {
        prvFree(n);
      }
    }

  private:
    uint32_t getCount(uint32_t r) {
			if (r == NULL_INDEX) {
				return 0;
			}

      return counts[r];
    }

    uint32_t getHeight(uint32_t r) {
			if (r == NULL_INDEX) {
				return 0;
			}

      return heights[r];
    }

    uint32_t prvAllocate() {
      if (freeListHead == NULL_INDEX) {
        uint32_t *tmpCounts = new uint32_t[2 * capacity];
        uint32_t *tmpHeights = new uint32_t[2 * capacity];
        uint32_t *tmpLeft = new uint32_t[2 * capacity];
        uint32_t *tmpRight = new uint32_t[2 * capacity];
        KeyType *tmpKeys = new KeyType[2 * capacity];
        ValueType *tmpValues = new ValueType[2 * capacity];

        for (int i = 0; i < capacity; i++) {
          tmpCounts[i] = counts[i];
        }

        for (int i = 0; i < capacity; i++) {
          tmpHeights[i] = heights[i];
        }

        for (int i = 0; i < capacity; i++) {
          tmpLeft[i] = left[i];
        }

        for (int i = 0; i < capacity; i++) {
          tmpRight[i] = right[i];
        }

        for (int i = 0; i < capacity; i++) {
          tmpKeys[i] = keys[i];
        }

        for (int i = 0; i < capacity; i++) {
          tmpValues[i] = values[i];
        }

        delete[] counts;
        delete[] heights;
        delete[] left;
        delete[] right;
        delete[] keys;
        delete[] values;

        counts = tmpCounts;
        heights = tmpHeights;
        left = tmpLeft;
        right = tmpRight;
        keys = tmpKeys;
        values = tmpValues;

        for (uint32_t i = capacity; i < 2 * capacity; i++) {
          left[i] = i + 1;
        }

        left[2 * capacity - 1] = NULL_INDEX;
        freeListHead = capacity;
        capacity = 2 * capacity;
      }

      uint32_t tmp = freeListHead;
      freeListHead = left[freeListHead];

      left[tmp] = NULL_INDEX;
      right[tmp] = NULL_INDEX;
      counts[tmp] = 1;
      heights[tmp] = 1;

      return tmp;
    }

    void prvFree(uint32_t n) {
      left[n] = freeListHead;
      freeListHead = n;
    }

    void prvClear(uint32_t r) {
      if (r != NULL_INDEX) {
        prvClear(left[r]);
        prvClear(right[r]);
        prvFree(r);
      }
    }

    void prvAdjust(uint32_t r) {
      counts[r] = getCount(left[r]) + getCount(right[r]) + 1;
      heights[r] = max(getHeight(left[r]), getHeight(right[r])) + 1;
    }

    uint32_t prvInsert(uint32_t r, uint32_t &n, const KeyType &k) {
      if (r == NULL_INDEX) {
        keys[n] = k;
        return n;
      }

      if (k == keys[r]) {
        n = r;
      }
      else if (k < keys[r]) {
        left[r] = prvInsert(left[r], n, k);
      }
      else {
        right[r] = prvInsert(right[r], n, k);
      }

      prvAdjust(r);
      return r;
    }

    uint32_t prvRemove(uint32_t r, uint32_t &ntbd, const KeyType &k) {
      if (r == NULL_INDEX) {
        throw domain_error("Remove: Key not found");
      }

      if (k < keys[r]) {
        left[r] = prvRemove(left[r], ntbd, k);
      }
      else if (k > keys[r]) {
        right[r] = prvRemove(right[r], ntbd, k);
      }
      else {
        ntbd = r;

        if (left[r] == NULL_INDEX) {
          if (right[r] == NULL_INDEX) {
            r = NULL_INDEX;
          }
          else {
            r = right[r];
          }
        }
        else {
          if (right[r] == NULL_INDEX) {
            r = left[r];
          }
          else {

            if (getHeight(right[r]) > getHeight(left[r])) {
              uint32_t tmp = right[r];

              while (left[tmp] != NULL_INDEX) {
                tmp = left[tmp];
              }

              KeyType tmpKey = keys[tmp];
              keys[tmp] = keys[r];
              keys[r] = tmpKey;

              ValueType tmpValue = values[tmp];
              values[tmp] = values[r];
              values[r] = tmpValue;

              right[r] = prvRemove(right[r], ntbd, k);
            }
            else {
              uint32_t tmp = left[r];

              while (right[tmp] != NULL_INDEX) {
                tmp = right[tmp];
              }

              KeyType tmpKey = keys[tmp];
              keys[tmp] = keys[r];
              keys[r] = tmpKey;

              ValueType tmpValue = values[tmp];
              values[tmp] = values[r];
              values[r] = tmpValue;

              left[r] = prvRemove(left[r], ntbd, k);
            }
          }
        }
      }

      if (r != NULL_INDEX) {
        prvAdjust(r);
      }

      return r;
    }

    uint32_t root;

    static uint32_t
      *counts,
      *heights,
      *left,
      *right,
      nTrees,
      capacity,
      freeListHead;

    static KeyType *keys;

    static ValueType *values;
};

template <typename KeyType, typename ValueType>
uint32_t *BSTDictionary<KeyType, ValueType>::counts = nullptr;

template <typename KeyType, typename ValueType>
uint32_t *BSTDictionary<KeyType, ValueType>::heights = nullptr;

template <typename KeyType, typename ValueType>
uint32_t *BSTDictionary<KeyType, ValueType>::left = nullptr;

template <typename KeyType, typename ValueType>
uint32_t *BSTDictionary<KeyType, ValueType>::right = nullptr;

template <typename KeyType, typename ValueType>
uint32_t BSTDictionary<KeyType, ValueType>::nTrees = 0;

template <typename KeyType, typename ValueType>
uint32_t BSTDictionary<KeyType, ValueType>::capacity = 0;

template <typename KeyType, typename ValueType>
uint32_t BSTDictionary<KeyType, ValueType>::freeListHead = 0;

template <typename KeyType, typename ValueType>
KeyType *BSTDictionary<KeyType, ValueType>::keys = nullptr;

template <typename KeyType, typename ValueType>
ValueType *BSTDictionary<KeyType, ValueType>::values = nullptr;

#endif
