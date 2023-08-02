# MyHashMap

The `MyHashMap` class is a custom implementation of a hashmap data structure in Swift. It provides basic functionality to store key-value pairs and perform operations like insertion, retrieval, and removal.

## Constructor

### init()

The constructor initializes the `MyHashMap` object with an empty map. It sets the initial `capacity` to 10,000 and creates an array of arrays called `buckets` to store the key-value pairs.

## Methods

### put(_ key: Int, _ value: Int)

The `put` method inserts a key-value pair into the hashmap. If the key already exists in the map, it updates the corresponding value with the new value. It calculates the bucket index for the given key and retrieves the corresponding bucket. If the key exists in the bucket, it updates the value. Otherwise, it appends a new tuple (key, value) to the bucket.

### get(_ key: Int) -> Int

The `get` method returns the value associated with the specified key. It calculates the bucket index for the key and retrieves the corresponding bucket. Using the `first(where:)` method, it searches for the tuple with the matching key. If the key is found, it returns the associated value. Otherwise, it returns -1 to indicate that the key is not present in the hashmap.

### remove(_ key: Int)

The `remove` method removes the key and its corresponding value from the hashmap if the map contains the mapping for the key. It calculates the bucket index for the key and retrieves the corresponding bucket. Using the `firstIndex(where:)` method, it finds the index of the tuple with the matching key. If the key is found, it removes the tuple from the bucket.

## Example Usage

```swift
let obj = MyHashMap()
obj.put(1, 1)
obj.put(2, 2)
print(obj.get(1)) // Output: 1
print(obj.get(3)) // Output: -1 (not found)
obj.put(2, 1) // Update the existing key
print(obj.get(2)) // Output: 1
obj.remove(2)
print(obj.get(2)) // Output: -1 (removed)
