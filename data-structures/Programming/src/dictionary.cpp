#include <dictionary.h>

static uint32_t hash(const std::string &s) {
  uint32_t
    sum = 0;

  for (uint32_t i=0;i<s.length();i++)
    sum = sum * i + s[i];

  return sum;
}

void Dictionary::clear() {
  for (uint32_t i=0;i<TABLE_SIZE;i++)
    status[i] = UNUSED;

  nItems = 0;
}

void Dictionary::add(const std::string &key,const Fraction value) {
	uint32_t pos = hash(key) % TABLE_SIZE;

	while (status[pos] != UNUSED) {
		if (status[pos] == IN_USE && keys[pos] == key) {
			values[pos] = value;
			return;
		}

		pos = (pos + 1) % TABLE_SIZE;
	}

	if (nItems == MAX_ITEMS) {
		throw std::overflow_error("Dictionary is full");
	}
	else {
		pos = (pos + 1) % TABLE_SIZE;

		while (status[pos] != UNUSED) {
			if (status[pos] == IN_USE && keys[pos] == key) {
				values[pos] = value;
				return;
			}

			pos = (pos + 1) % TABLE_SIZE;
		}
	}

	keys[pos] = key;
	values[pos] = value;
	status[pos] = IN_USE;
	nItems++;
	return;
}

Fraction Dictionary::search(const std::string &key) {
	uint32_t pos = hash(key) % TABLE_SIZE;

	while (status[pos] != UNUSED) {
		if (status[pos] == IN_USE && keys[pos] == key) {
			return values[pos];
		}

		pos = (pos + 1) % TABLE_SIZE;
	}

	throw std::domain_error("Key not found");
}

void Dictionary::remove(const std::string &key) {
	uint32_t pos = hash(key) % TABLE_SIZE;

	while (status[pos] != UNUSED) {
		if (status[pos] == IN_USE && keys[pos] == key) {
			status[pos] = DELETED;
			return;
		}

		pos = (pos + 1) % TABLE_SIZE;
	}

	throw std::domain_error("Key not found");
}
