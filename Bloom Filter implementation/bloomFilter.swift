import Foundation

// Protocol for hash functions
protocol HashFunction {
    func hash(_ input: String) -> Int
}

class BloomFilter {
    private var bitArray: [Bool]
    private let size: Int
    private let hashFunctions: [HashFunction]

    init(size: Int, hashFunctions: [HashFunction]) {
        self.size = size
        self.bitArray = Array(repeating: false, count: size)
        self.hashFunctions = hashFunctions
    }

    func insert(_ element: String) {
        for hashFunction in hashFunctions {
            let index = hashFunction.hash(element) % size
            bitArray[index] = true
        }
    }

    func contains(_ element: String) -> Bool {
        for hashFunction in hashFunctions {
            let index = hashFunction.hash(element) % size
            guard bitArray[index] else { return false }
        }
        return true
    }
}

// Simple hash function using the built-in Swift hashValue
struct SimpleHashFunction: HashFunction {
    func hash(_ input: String) -> Int {
        return abs(input.hashValue)
    }
}

// Another hash function using the djb2 algorithm
struct DJB2HashFunction: HashFunction {
    func hash(_ input: String) -> Int {
        var hash = 5381
        for char in input.utf8 {
            hash = ((hash << 5) &+ hash) &+ Int(char)
        }
        return abs(hash)
    }
}

// Example usage:
let bloomFilter = BloomFilter(size: 1000, hashFunctions: [SimpleHashFunction(), DJB2HashFunction()])

bloomFilter.insert("apple")
bloomFilter.insert("banana")

print(bloomFilter.contains("apple"))   // Output: true (may be a false positive)
print(bloomFilter.contains("orange"))  // Output: false (definitely not present)

