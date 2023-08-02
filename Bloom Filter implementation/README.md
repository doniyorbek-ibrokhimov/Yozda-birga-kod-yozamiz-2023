# Bloom Filter in Swift

A Bloom filter is a probabilistic data structure that efficiently tests whether an element is a member of a set. It provides a space-efficient way to represent a large set of items and quickly check for membership. However, Bloom filters may occasionally produce false positives, meaning it might report that an element is in the set even if it is not, but it will never produce false negatives.

## Implementation Details

The provided Swift implementation of a Bloom filter consists of three main components:

1. **HashFunction Protocol:**
   - The `HashFunction` protocol defines a contract for hash functions that will be used by the Bloom filter. It requires implementing a `hash` function that takes an input string and returns an integer hash value.

2. **BloomFilter Class:**
   - The `BloomFilter` class is the main data structure that stores the bit array and manages the hash functions. It allows inserting elements into the filter and querying for their membership.
   - When initializing a `BloomFilter` object, you need to specify the size of the bit array and provide an array of hash functions that will be used during insertions and queries.
   - The `insert` method inserts an element into the Bloom filter by setting the corresponding bits in the bit array according to the hash values obtained from the hash functions.
   - The `contains` method checks if an element is potentially in the set by querying the corresponding bits in the bit array using the hash values from the hash functions. If any of the queried bits are not set, the element is definitely not present. If all the bits are set, there is a possibility of a false positive.

3. **Hash Functions:**
   - The implementation provides two simple hash functions as examples:
     - `SimpleHashFunction`: This function uses the built-in Swift `hashValue` method, which returns the hash value of a string. The absolute value of this hash is used to ensure it is positive.
     - `DJB2HashFunction`: This function implements the djb2 hash algorithm, which iterates through the UTF-8 representation of the input string and accumulates the hash value based on the previous value and the current character's ASCII value.

## Example Usage

The example demonstrates how to use the Bloom filter with two hash functions to test for membership of elements in the set:

```swift
let bloomFilter = BloomFilter(size: 1000, hashFunctions: [SimpleHashFunction(), DJB2HashFunction()])

// Insert elements into the Bloom filter
bloomFilter.insert("apple")
bloomFilter.insert("banana")

// Check for membership
print(bloomFilter.contains("apple"))   // Output: true (may be a false positive)
print(bloomFilter.contains("orange"))  // Output: false (definitely not present)
