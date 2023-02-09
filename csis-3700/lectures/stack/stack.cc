#include <stdexcept>
#include "stack.h"

Stack::Stack() {
	top = 0;
}

void push(StackType d) {
	if (top == STACK_SIZE)
		throw std::overflow_error

}

