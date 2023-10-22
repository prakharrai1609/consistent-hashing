#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

// Define a simple hash function using hash
size_t hash_fn(const string &key) {
    hash<string> hasher;
    return hasher(key);
}

class ConsistentHashing {
public:
    // Constructor to initialize the number of virtual nodes
    ConsistentHashing(int virtualNodes) : virtualNodes_(virtualNodes) {}

    // Add a node to the consistent hashing ring
    void addNode(const string &node) {
        for (int i = 0; i < virtualNodes_; ++i) {
            string virtualNodeName = node + "-" + to_string(i);
            size_t hash = hash_fn(virtualNodeName);
            ring_[hash] = node;
        }
    }

    // Remove a node from the consistent hashing ring
    void removeNode(const string &node) {
        for (int i = 0; i < virtualNodes_; ++i) {
            string virtualNodeName = node + "-" + to_string(i);
            size_t hash = hash_fn(virtualNodeName);
            ring_.erase(hash);
        }
    }

    // Get the node responsible for a given key
    string getNode(const string &key) {
        if (ring_.empty()) {
            return "";
        }

        size_t hash = hash_fn(key);
        auto it = ring_.lower_bound(hash);

        if (it == ring_.end()) {
            // Wrap around if the key's hash is greater than the largest hash in the ring
            it = ring_.begin();
        }

        return it->second;
    }

private:
    int virtualNodes_;  // Number of virtual nodes per real node
    map<size_t, string> ring_;
};

int main() {
    ConsistentHashing ch(3); // Number of virtual nodes per real node

    ch.addNode("Node1");
    ch.addNode("Node2");
    ch.addNode("Node3");

    cout << "Key 'mykey' is assigned to node: " << ch.getNode("mykey") << endl;

    ch.removeNode("Node2");

    cout << "After removing 'Node2', key 'mykey' is assigned to node: " << ch.getNode("mykey") << endl;

    return 0;
}
