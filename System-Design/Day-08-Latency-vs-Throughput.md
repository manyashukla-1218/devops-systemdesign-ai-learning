## 🔹 Definitions

- **Latency**  
  - The **time taken** for a single request to travel through the system and get a response (end‑to‑end delay).
  - Includes network travel time, processing time on servers, and queuing/waiting time.

- **Throughput**  
  - The **amount of work** done per unit time, usually measured as requests per second, messages per second, or MB/s.  
  - Reflects how much load the system can handle overall.

In short: **latency = speed per request**, **throughput = total capacity**.

---

## 🔹 Components of Latency

- **Network latency:** time to send data from client to server and back (round‑trip time).  
- **Processing time:** CPU time to run business logic, database queries, and serialization.  
- **Queuing time:** time spent waiting in queues when servers are busy (for example, waiting in a thread pool or message queue).

User experience is usually more sensitive to latency—slow responses feel laggy even if throughput is high.

---

## 🔹 Examples to Build Intuition

- **Low latency, low throughput**  
  - A tiny service handles one request in 2 ms but crashes or overloads after 100 requests per second. 
  - Fast for each user individually, but cannot serve many users at once.

- **High throughput, high latency**  
  - A batch processing system can process terabytes per hour but each query takes minutes to finish. 
  - Great for bulk processing, bad for real‑time user responses.

- **Balanced system**  
  - A well‑tuned web API that serves thousands of requests per second (good throughput) with p95 latency under a few hundred milliseconds (good latency).

---

## 🔹 Trade‑offs Between Latency and Throughput

- Adding **batching or buffering** (for example, processing items in groups) typically increases throughput but adds latency because items wait in a queue.
- Using **dedicated resources** to respond faster can lower latency but might reduce maximum throughput because capacity is reserved rather than shared.  
- Design choice depends on product needs:
  - Real‑time UX (gaming, trading, chat) → prioritize low latency.  
  - Heavy offline jobs (analytics, ETL) → prioritize high throughput.

---

## 🔹 System Design – Day 08 Takeaways

- Latency measures how **quickly** a single request gets a response; throughput measures how **many** requests the system can handle over time.
- Many design decisions (caching, batching, queueing, replication) involve a trade‑off between latency and throughput, which must match the use‑case.
