import Foundation

class MyHashMap {
    private var buckets: [[(Int, Int)]]
    private let capacity: Int
    
    init() {
        capacity = 10000
        buckets = Array(repeating: [], count: capacity)
    }
    
    private func getIndex(_ key: Int) -> Int {
        return key % capacity
    }
    
    func put(_ key: Int, _ value: Int) {
        let index = getIndex(key)
        var bucket = buckets[index]
        
        if let existingIndex = bucket.firstIndex(where: { $0.0 == key }) {
            bucket[existingIndex].1 = value
        } else {
            bucket.append((key, value))
        }
        buckets[index] = bucket
    }
    
    func get(_ key: Int) -> Int {
        let index = getIndex(key)
        let bucket = buckets[index]
        
        guard let value = bucket.first(where: { $0.0 == key })?.1 else {
            return -1
        }
        
        return value
    }
    
    func remove(_ key: Int) {
        let index = getIndex(key)
        var bucket = buckets[index]
        
        if let existingIndex = bucket.firstIndex(where: { $0.0 == key }) {
            bucket.remove(at: existingIndex)
        }
        buckets[index] = bucket
    }
}
