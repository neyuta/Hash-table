#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class HashTable {
private:
    unordered_map<int, int> table;

public:
    void insert(int key, int value) {
        table[key] = value;
    }

    int search(int key) {
        if (table.find(key) != table.end()) {
            return table[key];
        }
        else {
            return -1;
        }
    }

    void remove(int key) {
        if (table.find(key) != table.end()) {
            cout << "Deleting a key: " << key << ", Meaning: " << table[key] << endl;
            table.erase(key);
        }
        else {
            cout << "Key" << key << " not found for deletion." << endl;
        }
    }

    void removeRandom() {
        if (table.empty()) {
            cout << "The table is empty. Cannot be deleted." << endl;
            return;
        }

        auto it = next(begin(table), rand() % table.size());
        int key = it->first;
        int value = it->second;

        cout << "Deleting a random key: " << key << ", Meaning: " << value << endl;

        table.erase(key);
    }

    void printTable() {
        for (const auto& pair : table) {
            cout << "Key: " << pair.first << ", Meaning: " << pair.second << endl;
        }
    }
};

int main() {
    srand(time(NULL));

    HashTable ht;

    for (int i = 0; i < 10; ++i) {
        int key = rand() % 100;
        int value = rand() % 1000;
        ht.insert(key, value);
    }

    cout << "Table contents:" << endl;
    ht.printTable();

    int keyToFind = 5;
    int result = ht.search(keyToFind);
    if (result != -1) {
        cout << "The value for the key was found" << keyToFind << ": " << result << endl;
    }
    else {
        cout << "Key" << keyToFind << "not found." << endl;
    }

    for (int i = 0; i < 3; ++i) {
        ht.removeRandom();
    }

    cout << "Table contents after deletion:" << endl;
    ht.printTable();

    return 0;
}