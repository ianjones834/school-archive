#include <iostream>
#include <fstream>
#include "linearlist.h"
#include "queue.h"

struct Word {
  Word* ptr = nullptr;
  LinearList<Word*> list;
};

const int NUM_WORDS = 5757;

std::string sgbTable[NUM_WORDS];
Word *wordTable[NUM_WORDS];

Queue<Word*> wordQueue;

void genLadder(Word*, Word*);
bool hammingDistranceEqualsOne(std::string, std::string);
void initializeWordTable();
int searchSgbTable(std::string);
int searchWordTable(Word*);

int main() {
  initializeWordTable();

  std::string stringOne;
  std::string stringTwo;

  std::cin >> stringOne >> stringTwo;

  int indexOne = searchSgbTable(stringOne);
  int indexTwo = searchSgbTable(stringTwo);

  std::cout << std::endl;

  if (indexOne == -1) {
    std::cout << "Error: first word not in list" << std::endl;
    return 0;
  }
  else if (indexTwo == -1) {
    std::cout <<  "Error: second word not in list" << std::endl;
    return 0;
  }

  genLadder(wordTable[indexOne], wordTable[indexTwo]);

  return 0;
}

void genLadder(Word *wordOne, Word *wordTwo) {
  Word *wordPtr;
  wordQueue.enqueue(wordTwo);

  while (!wordQueue.isEmpty()) {
    wordPtr = wordQueue.dequeue();

    for (int i = 0; i < wordPtr -> list.size(); i++) {
      Word *tmpWord = wordPtr -> list[i];

      if (tmpWord -> ptr == nullptr && tmpWord != wordTwo) {
        tmpWord -> ptr = wordPtr;
        wordQueue.enqueue(tmpWord);
      }
    }
  }

  if (wordOne -> ptr != nullptr) {
    std::cout << "Ladder:" << std::endl;

    int index = searchWordTable(wordOne);
    std::cout << sgbTable[index] << std::endl;
    wordPtr = wordOne -> ptr;

    while (wordPtr != nullptr) {
      index = searchWordTable(wordPtr);
      std::cout << sgbTable[index] << std::endl;
      wordPtr = wordPtr -> ptr;
    }
  }
  else {
    std::cout << "No ladder exists" << std::endl;
  }
}

bool hammingDistanceEqualsOne(std::string wordOne, std::string wordTwo) {
  int hammingDistance = 0;
  int characterPtr = 0;

  while (hammingDistance <= 1 && characterPtr < 5) {
    if (wordOne[characterPtr] != wordTwo[characterPtr]) {
      hammingDistance++;
    }

    characterPtr++;
  }

  return hammingDistance == 1;
}

void initializeWordTable() {
  std::ifstream input;
  input.open("sgb-words.txt");

  for (int i = 0; i < NUM_WORDS; i++) {
    input >> sgbTable[i];
    Word *tmpPtr = new Word;
    wordTable[i] = tmpPtr;
  }

  input.close();

  for (int i = 0; i < NUM_WORDS - 1; i++) {
    std::string wordOne = sgbTable[i];

    for (int j = i + 1; j < NUM_WORDS; j++) {
      std::string wordTwo = sgbTable[j];

      if (hammingDistanceEqualsOne(wordOne, wordTwo)) {
        (*wordTable[i]).list.insert(0, wordTable[j]);
        (*wordTable[j]).list.insert(0, wordTable[i]);
      }
    }
  }
}

int searchSgbTable(std::string string) {
  for (int i = 0; i < NUM_WORDS; i++) {
    if (string == sgbTable[i]) {
      return i;
    }
  }

  return -1;
}

int searchWordTable(Word *word) {
  for (int i = 0; i < NUM_WORDS; i++) {
    if (word == wordTable[i]) {
      return i;
    }
  }

  return -1;
}
