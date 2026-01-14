## 🔹 Why Caching?

- A **cache** stores frequently accessed data in a faster storage layer (usually in‑memory) to reduce latency and load on databases or downstream services.
- Benefits: lower response times, fewer expensive DB queries, and better scalability under high read traffic.

---

## 🔹 Redis as a Cache

- **Redis** is an in‑memory key‑value store commonly used as a distributed cache in system design. 
- Key features:
  - Very low‑latency reads/writes from memory.  
  - Key–value data structures (strings, hashes, lists, sets, sorted sets).  
  - Optional **TTL (time‑to‑live)** per key for automatic expiration.

---

## 🔹 Basic Caching Patterns

### 1. Cache‑Aside (Lazy Loading)

- Application first checks the cache; on **cache miss**, it loads from DB, returns to client, and **stores result in cache** for next time.  
- Advantages:
  - Simple, DB is always the source of truth.  
  - You control what gets cached and for how long.

**High‑level flow**

1. Read from cache.  
2. If miss → read from DB, write to cache, return data.  
3. If hit → return cached data.

---

### 2. Read‑Through

- Application always reads through the cache layer; if data is missing, the cache system itself fetches from DB and populates the cache. 
- Abstracts cache miss handling inside the caching layer or library.

---

### 3. Write‑Through / Write‑Behind (Overview)

- **Write‑through:** writes go to cache and DB synchronously; ensures cache and DB are consistent but adds write latency.  
- **Write‑behind:** application writes to cache, and cache asynchronously updates DB later, improving write performance but complicating consistency.

---

## 🔹 Cache Eviction & Invalidation

- Since cache memory is limited, eviction policies like **LRU (Least Recently Used)** are used to remove older or less‑used entries. 
- **Cache invalidation** strategies ensure stale data does not live too long:
  - TTL expiry.  
  - Explicit delete/update on writes.  
  - Versioned keys.

---

## 🔹 System Design – Day 09 Takeaways

- Caching (often via Redis) is a standard system‑design tool to reduce read latency and database load.
- Patterns like cache‑aside, read‑through, write‑through, and sensible TTL/eviction policies are commonly discussed in interviews
