#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashMap {
private:
    list<pair<int, int>> table[TABLE_SIZE];  // key, value pairs

    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Insert key-value pair
    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value;  // Update if key already exists
                return;
            }
        }
        table[index].push_back({key, value});
    }

    // Get value for a key
    int get(int key) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key)
                return kv.second;
        }
        return -1;  // Not found
    }

    // Remove key-value pair
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Key " << key << " removed." << endl;
                return;
            }
        }
        cout << "Key " << key << " not found." << endl;
    }

    // Display entire table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto& kv : table[i]) {
                cout << "(" << kv.first << ", " << kv.second << ") ";
            }
            cout << endl;
        }
    }
};

// --- Main Program ---
int main() {
    HashMap map;

    map.insert(1, 100);
    map.insert(11, 200); // Collision
    map.insert(2, 300);

    map.display();

    cout << "Value for key 11: " << map.get(11) << endl;

    map.remove(1);
    map.display();

    return 0;
}
