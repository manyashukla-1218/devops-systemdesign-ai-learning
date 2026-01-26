## 🔹 Why Databases Matter in System Design

* Almost every system persistent data store karta hai; correct database choice directly impacts scalability, consistency, and development speed.
* System design interviews me “SQL vs NoSQL” almost guaranteed topic hai, isliye high‑level trade‑offs clear hone chahiye.

---

## 🔹 Relational Databases (SQL) – Overview

* **Examples:** MySQL, PostgreSQL, SQL Server, Oracle.
* **Data model:**
  * Tables (rows & columns) with fixed schema, relationships defined via foreign keys.
  * Structured schema: each column ka type & constraints predefined.

* **Key properties:**
  * **ACID transactions:** Atomicity, Consistency, Isolation, Durability – strong guarantee for critical data (money, inventory etc.).
  * Strong consistency: after transaction commit, reads immediately updated data dekhte hain (usual configuration).

* **Strengths / When to use:**
  * Complex queries with JOINs, aggregations, reporting.
  * Strong data integrity (constraints, relationships) important – banking, orders, billing.
  * Data structure relatively stable (schema frequently change nahi hota).  

* **Limitations:**
  * Horizontal scaling (sharding) comparatively hard; traditionally vertical scaling par rely karte hain (bigger machine).

---

## 🔹 NoSQL Databases – Overview

* **Examples:** MongoDB (document), Cassandra (wide‑column), Redis (key‑value), DynamoDB (key‑value/document), Neo4j (graph).
* **Data model:**
  * Non‑relational; multiple models (document, key‑value, column‑family, graph).
  * Schema‑less ya flexible schema; nested JSON‑like documents common.

* **Typical properties:**
  * Designed for **horizontal scaling**, data shards across multiple nodes easily.
  * Often offer eventual consistency in exchange for high availability and performance (CAP trade‑off).

* **Strengths / When to use:**
  * Huge scale with high write/read throughput – large web/mobile apps, real‑time analytics.
  * Dynamic / evolving data structure (user profiles with variable fields, event logs).  
  * Specific access patterns:  
    * Key‑value for caching (Redis).  
    * Document store for JSON APIs (MongoDB).  
    * Time‑series or column‑family for logs/metrics (Cassandra).

* **Limitations:**
  * JOINs limited or absent; aggregations more manual.
  * Cross‑document strong transactions limited (DB dependent), so complex relational integrity harder.

---

## 🔹 SQL vs NoSQL – Headline Differences

* **Data model & schema**
  * SQL: relational tables with fixed, predefined schema; strong relationships and constraints.  
  * NoSQL: flexible schema, nested documents or other structures; relationships often handled at application level.

* **Scalability**
  * SQL: traditionally vertical scaling (bigger server), modern systems also support sharding but with more complexity.
  * NoSQL: built for horizontal scaling across many machines; adding nodes to handle more traffic is easier.

* **Consistency vs Availability**
  * SQL: strong consistency (ACID); good for critical data correctness.
  * Many NoSQL: tunable or eventual consistency; often favor availability & partition tolerance (CAP theorem angle).

* **Query capabilities**
  * SQL: expressive standardized SQL language, powerful joins, aggregations.
  * NoSQL: query language depends on DB; often simpler / limited but optimized for specific patterns.

---

## 🔹 Simple System Design Examples

* **Example 1 – Banking / Payments System**
  * Requirements: strict correctness for balances, transfers, audit logs.  
  * Choice: **SQL database** (PostgreSQL/MySQL) with ACID transactions.
* **Example 2 – Social Media Feed**
  * Requirements: huge scale, rapidly changing schema, mostly simple key‑based lookups.  
  * Likely architecture:
    * SQL for core user data (accounts, relationships).  
    * NoSQL (document/column store) for feeds, likes, events.

* **Example 3 – Logging / Analytics**
  * Requirements: write‑heavy, append‑only, high volume, queries mostly by time or key.  
  * Choice: **NoSQL** (Cassandra, time‑series DB, ElasticSearch) plus object storage.

---

## 🔹 Interview Questions

* What are the main differences between SQL and NoSQL databases?  
* For an e‑commerce system (users, products, orders, inventory), which parts would you put in SQL and which in NoSQL, and why?  
* How does schema flexibility in NoSQL help when requirements change frequently?

---

## ✅ What I Learned Today

* SQL databases offer strong consistency, relational schema, and powerful queries, making them ideal for core transactional data.  
* NoSQL databases sacrifice some relational features to gain horizontal scalability, flexible schemas, and high throughput, which is ideal for large‑scale, rapidly evolving applications.
