#ifndef _LINEARLIST_H
#define _LINEARLIST_H

#include <cstdint>
#include <stdexcept>

template <typename ListType>
struct ListNode {
	ListType datum;
	ListNode<ListType> *next;
};

template <typename ListType>
class LinearList {
	public:
		LinearList() {
			head = nullptr;
			count = 0;
		}

		LinearList(const LinearList<ListType> &list) {
			ListNode<ListType> *src = list.head;
			ListNode<ListType> **dest = &head;

			for (uint32_t i = 0; i < list.count; i++) {
				*dest = new ListNode<ListType>;

				(*dest) -> datum = src -> datum;

				src = src -> next;

				dest = &(*dest) -> next;
			}

			count = list.count;
		}

		~LinearList() {
			clear();
		}

		uint32_t size() {
			return count;
		}

		bool isEmpty() {
			return count == 0;
		}

		void clear() {
			ListNode<ListType> *tmp;

			for (int i = 0; i < count; i++) {
				tmp = head -> next;
				delete head;
				head = tmp;
			}

			head = nullptr;
			count = 0;
		}

		uint32_t search(const ListType &key) {
			ListNode<ListType> *tmp = head;

			for (int i = 0; i < count; i++) {
				if (key == tmp -> datum) {
					return i;
				}

				tmp = tmp -> next;
			}

			throw std::domain_error("Key not found");
		}

		ListType &operator[](int32_t pos) {
			ListNode<ListType> *tmp = head;

			if (pos < 0 || pos >= count) {
				throw std::domain_error("Invalid index");
			}

			for (int i = 0; i < pos; i++) {
				tmp = tmp -> next;
			}

			return tmp -> datum;
		}

		void map(void (*fp)(ListType &)) {
			ListNode<ListType> *tmp = head;

			for (int i = 0; i < count; i++) {
				(*fp)(tmp -> datum);
				tmp = tmp -> next;
			}
		}

		void insert(uint32_t pos, const ListType &d) {
			ListNode<ListType> *ptr;
			ListNode<ListType> **pred;

			if (pos > count) {
				throw std::domain_error("Invalid Index");
			}

			ptr = new ListNode<ListType>;
			ptr -> datum = d;

			pred = &head;

			for (int i = 0; i < pos; i++) {
				pred = &((*pred) -> next);
			}

			ptr -> next = *pred;
			*pred = ptr;

			count++;
		}

		void remove(uint32_t pos) {
			ListNode<ListType> *ptr;
			ListNode<ListType> *pred;

			if (pos >= count) {
				throw std::domain_error("Invalid Index");
			}

			pred = &head;

			for (int i = 0; i < pos; i++) {
				pred = &((*pred) -> next);
			}

			ptr = *pred;
			*pred = ptr -> next;

			delete ptr;
			count--;
		}

	private:
		ListNode<ListType> *head;
		uint32_t count;
};


#endif