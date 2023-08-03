# Trie Data Structure in Swift

The Trie is a tree-like data structure used for efficient retrieval of keys in a large dataset of strings. Each node in the Trie represents a single character, and the path from the root to a node forms a string.

## Implementation Details

The Swift implementation of the Trie consists of two classes:

1. **TrieNode Class:**
   - The `TrieNode` class represents a single node in the Trie. Each node contains a dictionary called `children`, which maps characters to their corresponding child nodes. This allows fast access to child nodes based on the characters they represent.
   - The `isEndOfWord` property is a boolean flag that indicates whether the node represents the end of a word in the Trie.

2. **Trie Class:**
   - The `Trie` class is the main data structure representing the Trie. It consists of a single property `root`, which is a `TrieNode` and serves as the starting point of the Trie.
   - When initializing a `Trie`, it creates an empty `root` node.

The Trie provides three main methods:

1. `insert(_ word: String)`: Inserts a word into the Trie. It traverses the Trie character by character and creates new nodes as needed.

2. `search(_ word: String) -> Bool`: Checks if a given word exists in the Trie. It traverses the Trie character by character and verifies if the last node representing the last character in the word has the `isEndOfWord` property set to `true`.

3. `startsWith(_ prefix: String) -> Bool`: Checks if there is any word in the Trie that starts with the given prefix. It traverses the Trie character by character and confirms if the entire prefix is found.

## Example Usage

```swift
let trie = Trie()

trie.insert("apple")
trie.insert("banana")

print(trie.search("apple"))     // Output: true
print(trie.search("orange"))    // Output: false

print(trie.startsWith("app"))   // Output: true
print(trie.startsWith("ban"))   // Output: true
print(trie.startsWith("ora"))   // Output: false
