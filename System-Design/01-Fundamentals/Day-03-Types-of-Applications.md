 ## 🔹 Why “Types of Applications” Matter

Before designing systems, it is important to understand what *kind* of application you are designing because scalability, consistency, and complexity depend on it. 
The same pattern will not work equally well for a small CRUD app and a global real‑time messaging platform.

---

## 🔹 Monolithic Applications
 
A monolithic application bundles UI, business logic, and data access into a single deployable unit (for example, one large backend service). 

**Characteristics**

- Single codebase and single deployment artifact.  
- All modules run in one process and share the same resources.

**Pros**

- Simple to start, develop, test, and deploy for small teams.
- Easier to do cross‑component refactoring because everything is together.

**Cons**

- Becomes hard to maintain and scale as the codebase grows.  
- A small change requires redeploying the whole application; failures can affect the entire system.

---

## 🔹 Client‑Server Web Applications

These are applications where the client (browser/mobile) talks to a backend server using HTTP, often with a REST or GraphQL API.

**Examples**

- E‑commerce websites, dashboards, SaaS tools, most typical web apps.  

**Key points**

- Server can be scaled horizontally with load balancers.  
- Clients are thin and mostly handle UI and basic validation.

---

## 🔹 Microservices‑based Applications

In a microservices architecture, the system is split into many small services, each responsible for a specific business capability (such as users, orders, payments).

**Characteristics**

- Each service can be developed, deployed, and scaled independently.  
- Services communicate over the network using APIs or messaging.

**Pros**

- Better scalability and fault isolation; one service failure does not always crash the entire system.  
- Teams can own services end‑to‑end and deploy independently.

**Cons**

- More operational complexity: service discovery, observability, distributed debugging, and network failures.  
- Requires good DevOps practices and tooling.

---

## 🔹 Real‑time / Streaming Applications

Applications that need live updates, such as chat systems, trading platforms, and live dashboards.

**Characteristics**

- Use technologies like WebSockets, message queues, event streams (Kafka, RabbitMQ).
- Focus on low latency and high throughput.

**Design implications**

- Need careful handling of ordering, back‑pressure, and failure recovery.  
- Often combine microservices with streaming pipelines.

---

## 🔹 Interview Questions

1. What is a monolithic application, and when is it a good choice?  
2. How is a microservices‑based application different from a monolith?  
3. Give examples of real‑time applications and why they need special design considerations.

---

## ✅ What I Learned Today

- The type of application (monolith, microservices, real‑time, etc.) strongly influences the system design choices.  
- Monoliths are simpler to start with, while microservices and streaming architectures are better for large, complex, and high‑scale systems.  
- Having this classification in mind makes it easier to reason about future topics like load balancing, databases, and caching.
