#include <iostream>
#include <list>
#include <cstring>

using namespace std;

// Hashtable to implement Phone Book

class HashTable {
private:
  static const int hashgroups = 10;
  list<pair<int, string>> table[hashgroups];

public:
  bool isEmpty() const;
  int hashFunction(int key);
  void insert(int key, string value);
  void remove(int key);
  string search(int key);
  void print();
};

bool HashTable::isEmpty() const {
  int sum{};
  for (int i = 0; i < hashgroups; i++) {
    sum += table[i].size();
  }

  if (!sum) {
    return true;
  }

  return false;
}

int HashTable::hashFunction(int key) {
  return key % hashgroups;
}

void HashTable::insert(int key, string value) {
  int hashValue = hashFunction(key);
  auto& cell = table[hashValue];
  auto bItr = begin(cell);

  bool keyExists = false;

  for (; bItr != end(cell); bItr++) {
    if (bItr->first == key) {
      keyExists = true;
      bItr->second = value;
      cout << "[WARNGING] Key exists, value updated." << endl;
      break;
    }
  }

  if (!keyExists) {
    cell.emplace_back(key, value);
  }

  return;
}

void HashTable::remove(int key) {
  int hashValue = hashFunction(key);
  auto& cell = table[hashValue];
  auto bItr = begin(cell);

  bool keyExists = false;

  for (; bItr != end(cell); bItr++) {
    if (bItr->first == key) {
      keyExists = true;
      bItr = cell.erase(bItr);
      cout << "[INFO] Key exists, value removed." << endl;
      break;
    }
  }

  if (!keyExists) {
    cout << "[ERROR] Key does not exist." << endl;
  }

  return;
}

string HashTable::search(int key) {
  int hashValue = hashFunction(key);
  auto& cell = table[hashValue];
  auto bItr = begin(cell);

  for (; bItr != end(cell); bItr++) {
    if (bItr->first == key) {
      return bItr->second;
    }
  }

  return ""; // Return an empty string if the key is not found
}

void HashTable::print() {
  for (int i = 0; i < hashgroups; i++) {
    if (table[i].size() == 0) {
      continue;
    }

    auto bItr = begin(table[i]);

    for (; bItr != end(table[i]); bItr++) {
      cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
    }
  }

  return;
}


int main() {
  HashTable HT;

  if (HT.isEmpty()) {
    cout << "[INFO] HashTable is empty." << endl;
  }

  HT.insert(905, "Jimmy");
  HT.insert(201, "Tom");
  HT.insert(332, "Sally");
  HT.insert(902, "Snady");
  HT.insert(907, "Nitin");
  HT.insert(909, "Anuj");
  HT.insert(918, "rob");
  HT.insert(918, "Rick");

  HT.print();

  HT.remove(905);
  HT.remove(1905);

  if (HT.isEmpty()) {
    cout << "[INFO] HashTable is still empty." << endl;
  }

  return 0;
}
