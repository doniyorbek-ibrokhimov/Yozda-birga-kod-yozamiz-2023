class TrieNode {
    var children: [Character: TrieNode]
    var isEndOfWord: Bool
    
    init() {
        self.children = [:]
        self.isEndOfWord = false
    }
}

class Trie {
    private let root: TrieNode
    
    init() {
        self.root = TrieNode()
    }
    
    func insert(_ word: String) {
        var currentNode = root
        
        for char in word {
            if let childNode = currentNode.children[char] {
                currentNode = childNode
            } else {
                let newNode = TrieNode()
                currentNode.children[char] = newNode
                currentNode = newNode
            }
        }
        
        currentNode.isEndOfWord = true
    }
    
    func search(_ word: String) -> Bool {
        var currentNode = root
        
        for char in word {
            guard let childNode = currentNode.children[char] else { return false }
            currentNode = childNode
        }
        
        return currentNode.isEndOfWord
    }
    
    func startsWith(_ prefix: String) -> Bool {
        var currentNode = root
        
        for char in prefix {
            guard let childNode = currentNode.children[char] else { return false }
            currentNode = childNode
        }
        
        return true
    }
}

let trie = Trie()

trie.insert("apple")
trie.insert("banana")

print(trie.search("apple"))     // Output: true
print(trie.search("orange"))    // Output: false

print(trie.startsWith("app"))   // Output: true
print(trie.startsWith("ban"))   // Output: true
print(trie.startsWith("ora"))   // Output: false
