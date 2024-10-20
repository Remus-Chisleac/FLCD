#include <iostream>
#include <list>
#include <vector>
#include <string>

class HashTable {
private:
    // Array of lists (each list handles collisions via chaining)
    std::vector<std::list<std::pair<std::string, int>>> table;
    int numElements;
    int capacity;
    const float LOAD_FACTOR_THRESHOLD = 0.75;

    // Hash function to map keys to an index
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % capacity;
        }
        return hash;
    }

    // Resize the hash table
    void resizeTable() {
        int newCapacity = capacity * 2;
        std::vector<std::list<std::pair<std::string, int>>> newTable(newCapacity);

        for (int i = 0; i < capacity; ++i) {
            for (auto& pair : table[i]) {
                int newIndex = hashFunction(pair.first) % newCapacity;
                newTable[newIndex].push_back(pair);
            }
        }

        table = std::move(newTable);
        capacity = newCapacity;
    }

public:
    // Constructor
    HashTable(int initialCapacity = 10) : capacity(initialCapacity), numElements(0) {
        table.resize(initialCapacity);
    }

    // Insert or update key-value pair
    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;  // Update value if key already exists
                return;
            }
        }
        table[index].push_back({ key, value });
        numElements++;

        if (numElements > capacity * LOAD_FACTOR_THRESHOLD) {
            resizeTable();  // Resize when load factor exceeds the threshold
        }
    }

    // Search for a key, returns true if found and sets the value
    bool search(const std::string& key, int& value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    // Remove a key from the hash table
    bool remove(const std::string& key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                numElements--;
                return true;
            }
        }
        return false;
    }

    // Display the hash table (for debugging)
    void display() {
        for (int i = 0; i < capacity; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") -> ";
            }
            std::cout << "NULL\n";
        }
    }
};

class SymbolTable {
private:
    HashTable identifiers;        // For regular identifiers (variables, etc.)
    HashTable constants;          // For constants (e.g., numeric constants)
    HashTable functionIdentifiers; // For function identifiers (e.g., function names)

public:
    // Constructor initializes the hash tables with an initial capacity
    SymbolTable() : identifiers(10), constants(10), functionIdentifiers(10) {}

    // Add a regular identifier (variable, etc.)
    void addIdentifier(const std::string& name, int value) {
        identifiers.insert(name, value);
    }

    // Add a constant to the constants table
    void addConstant(const std::string& name, int value) {
        constants.insert(name, value);
    }

    // Add a function identifier (function name)
    void addFunctionIdentifier(const std::string& name, int value) {
        functionIdentifiers.insert(name, value);
    }

    // Find a regular identifier and return true if found
    bool findIdentifier(const std::string& name, int& value) {
        return identifiers.search(name, value);
    }

    // Find a constant and return true if found
    bool findConstant(const std::string& name, int& value) {
        return constants.search(name, value);
    }

    // Find a function identifier and return true if found
    bool findFunctionIdentifier(const std::string& name, int& value) {
        return functionIdentifiers.search(name, value);
    }

    // Display all symbol tables (for debugging purposes)
    void displaySymbolTable() {
        std::cout << "Identifiers:\n";
        identifiers.display();
        std::cout << "\nConstants:\n";
        constants.display();
        std::cout << "\nFunction Identifiers:\n";
        functionIdentifiers.display();
    }
};

// Assuming HashTable and SymbolTable classes are defined as discussed earlier

int main() {
    // Create an instance of the SymbolTable
    SymbolTable symTable;

    // Add some regular identifiers (variables)
    symTable.addIdentifier("x", 10);
    symTable.addIdentifier("y", 20);
    symTable.addIdentifier("z", 30);

    // Add some constants
    symTable.addConstant("PI", 314);  // Store 3.14 as 314 for simplicity
    symTable.addConstant("E", 271);   // Store 2.71 as 271

    // Add some function identifiers
    symTable.addFunctionIdentifier("main", 1);
    symTable.addFunctionIdentifier("add", 2);
    symTable.addFunctionIdentifier("subtract", 3);

    // Search for some identifiers and function names
    int value;
    if (symTable.findIdentifier("x", value)) {
        std::cout << "Found identifier 'x' with value: " << value << "\n";
    }
    else {
        std::cout << "'x' not found.\n";
    }

    if (symTable.findConstant("PI", value)) {
        std::cout << "Found constant 'PI' with value: " << value << "\n";
    }
    else {
        std::cout << "'PI' not found.\n";
    }

    if (symTable.findFunctionIdentifier("add", value)) {
        std::cout << "Found function identifier 'add' with value: " << value << "\n";
    }
    else {
        std::cout << "'add' not found.\n";
    }

    // Display the entire symbol table (for debugging purposes)
    std::cout << "\nDisplaying the entire symbol table:\n";
    symTable.displaySymbolTable();

    return 0;
}