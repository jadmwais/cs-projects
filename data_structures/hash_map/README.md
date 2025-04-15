# 🗃️ Hash Map (Separate Chaining) – C++

This project implements a basic **Hash Map** (aka Hash Table) using an array of linked lists. Collisions are handled using **separate chaining**.

---

## 💡 Features

- `insert(key, value)` – Adds or updates a key-value pair
- `get(key)` – Retrieves the value for a given key
- `remove(key)` – Deletes a key-value pair
- `display()` – Prints all stored key-value pairs by bucket index

---

## 📦 Example

Keys are hashed using:  
```cpp
index = key % TABLE_SIZE;
