\# Distributed API Rate Limiter



\## 1. Overview



A Distributed API Rate Limiter controls how many requests a client can send to an API within a specific time period.



It protects backend services from excessive traffic, accidental request bursts, and potential abuse.



This case study explores how to design a rate limiter that works across multiple application servers using Redis as shared storage.



\## 2. Problem Statement



Imagine an application where thousands of users send API requests simultaneously.



Without rate limiting:

\- A single user could send too many requests.

\- Backend services could become overloaded.

\- Application latency could increase.

\- Service availability could be affected.



We need a system that controls incoming requests while allowing legitimate traffic.



\## 3. Requirements



\### Functional Requirements



\- Identify clients using an API key or user ID.

\- Define request limits for each client.

\- Allow requests within the configured limit.

\- Reject requests that exceed the limit.

\- Return HTTP 429 when the limit is exceeded.

\- Provide retry information to clients.



\### Non-Functional Requirements



\- Low request-processing latency.

\- High availability.

\- Horizontal scalability.

\- Consistent rate-limit decisions across application servers.

\- Atomic updates to shared rate-limit state.



\## 4. High-Level Architecture



```mermaid

flowchart TD

&#x20;   A\["Client"] --> B\["API Gateway"]

&#x20;   B --> C\["Authentication"]

&#x20;   C --> D\["Rate Limiter"]

&#x20;   D --> E{"Request Allowed?"}

&#x20;   E -->|Yes| F\["Backend Service"]

&#x20;   E -->|No| G\["HTTP 429 Response"]

&#x20;   D <--> H\["Redis Shared State"]

&#x20;   F --> I\["Database"]

&#x20;   F --> J\["API Response"]

&#x20;   G --> K\["Retry-After Header"]

&#x20;   K --> A

&#x20;   J --> A

```



\### Component Responsibilities



| Component | Responsibility |

|---|---|

| Client | Sends API requests |

| API Gateway | Receives and routes requests |

| Authentication | Identifies the client |

| Rate Limiter | Checks request limits |

| Redis | Stores shared rate-limit state |

| Backend Service | Processes allowed requests |

| Database | Stores application data |



\## 5. Request Flow



1\. A client sends an API request.

2\. The API Gateway receives the request.

3\. Authentication identifies the client.

4\. The Rate Limiter checks the client's current request allowance.

5\. Redis provides the shared state required for the decision.

6\. If the request is allowed, it reaches the backend service.

7\. If the limit is exceeded, the system returns HTTP 429 Too Many Requests.



\## 6. Rate Limiting Algorithms



\### Fixed Window Counter



Counts requests within fixed time intervals.



Example: Allow 100 requests per minute.



\*\*Advantage:\*\* Simple to implement.



\*\*Limitation:\*\* Requests near window boundaries can create traffic bursts.



\### Sliding Window Log



Stores timestamps of individual requests and removes expired entries.



\*\*Advantage:\*\* Accurate request counting.



\*\*Limitation:\*\* Requires more memory.



\### Token Bucket



The bucket contains tokens. Each incoming request consumes one token.



\- Tokens are added at a configured refill rate.

\- Requests are allowed when tokens are available.

\- Requests are rejected when the bucket is empty.

\- The bucket has a maximum capacity.



\*\*Advantage:\*\* Supports controlled traffic bursts while maintaining an average request rate.



\*\*Selected Algorithm:\*\* Token Bucket.



\## 7. Example Configuration



Assume a client has the following rate limit:



| Setting | Value |

|---|---:|

| Bucket capacity | 10 tokens |

| Refill rate | 2 tokens/second |

| Cost per request | 1 token |



If the bucket contains 10 tokens, the client can initially send 10 requests.



After that, tokens refill at 2 tokens per second.



\## 8. Redis Data Model



A Redis key can represent the rate-limit state of a client.



Example:



```text

rate\_limit:user\_123

```



Stored state:



```text

tokens = 7

last\_refill\_timestamp = 1730000000

```



In a distributed system, multiple application servers use the same Redis state.



The token update and request decision must be atomic to prevent concurrent requests from incorrectly exceeding the limit.



Redis Lua scripts can perform these operations atomically.



\## 9. API Behaviour



\### Allowed Request



```http

HTTP/1.1 200 OK

```



\### Rate-Limited Request



```http

HTTP/1.1 429 Too Many Requests

Retry-After: 2

Content-Type: application/json

```



Example response:



```json

{

&#x20; "error": "rate\_limit\_exceeded",

&#x20; "message": "Too many requests. Please try again later."

}

```



\## 10. Distributed System Considerations



\### Shared State



If every application server maintains its own counter, clients may receive inconsistent rate-limit decisions.



Redis provides shared state across application servers.



\### Atomicity



Concurrent requests can attempt to consume tokens simultaneously.



Redis Lua scripts help ensure that checking and updating the token bucket happen as one atomic operation.



\### Redis Failure



The system needs a defined failure policy:



\- \*\*Fail-open:\*\* Allow requests when Redis is unavailable.

\- \*\*Fail-closed:\*\* Reject requests when Redis is unavailable.



The appropriate policy depends on business and security requirements.



\### Horizontal Scalability



More API Gateway and application instances can be added as traffic grows. They continue using shared rate-limit state.



\## 11. Trade-offs and Limitations



\- Redis introduces an additional network dependency.

\- Every rate-limit check adds processing overhead.

\- Redis availability becomes important for consistent decisions.

\- Distributed deployments must consider Redis replication, failover, and key expiration.

\- A single global Redis instance may become a bottleneck at high traffic volumes.



\## 12. Implementation



This case study contains two learning implementations:



\- \*\*C++:\*\* An in-memory Token Bucket implementation for understanding the algorithm and concurrency within a single process.

\- \*\*Redis Lua:\*\* An atomic Token Bucket operation for shared distributed state.



The C++ implementation is not itself a distributed production system. The Redis implementation demonstrates the shared-state approach.



\## 13. Possible Improvements



\- Add per-user and per-API rate limits.

\- Support different subscription tiers.

\- Add monitoring and rate-limit metrics.

\- Introduce Redis Cluster for larger workloads.

\- Add automated concurrency and load tests.

\- Evaluate alternative algorithms for different traffic patterns.



\## 14. Learning Resources



\- \[Redis Documentation](https://redis.io/docs/latest/)

\- \[Redis Lua Scripting](https://redis.io/docs/latest/develop/programmability/eval-intro/)

\- \[HTTP 429 - MDN](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Status/429)

\- \[System Design Primer](https://github.com/donnemartin/system-design-primer)



\---



\*\*Project Goal:\*\* Understand how API rate limiting works, why shared state matters in distributed systems, and how Redis can support atomic rate-limit decisions.

