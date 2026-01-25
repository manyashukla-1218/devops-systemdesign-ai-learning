# Day 07 – Load Balancing Basics

---

## 🔹 Why Load Balancing?

- As traffic grows, a single server becomes a bottleneck; a load balancer distributes requests across multiple backend servers to handle more load.  
- Main goals:
  - Improve performance and throughput.  
  - Reduce the impact of a single‑server failure.  
  - Make capacity increases as simple as adding more backend instances.

---

## 🔹  Reverse Proxy as a Load Balancer

- A **reverse proxy** is a single public endpoint that receives client requests and routes them to internal backend servers. 
- A load balancer typically acts like a reverse proxy and can:
  - Handle TLS termination (HTTPS offloading).  
  - Add caching, compression, and security filters.  
  - Run health checks against backends and avoid unhealthy nodes.

**Conceptual Nginx example:**

```nginx
upstream app_servers {
    server app1.example.com;
    server app2.example.com;
}

server {
    listen 80;
    location / {
        proxy_pass http://app_servers;
    }
}
Here Nginx receives the client request and forwards it to app1 or app2 using the default round‑robin algorithm.

🔹 Common Load Balancing Algorithms
1. Round Robin
Sends requests to each backend in sequence: 1, 2, 3, 1, 2, 3, …

Very simple and stateless; works well when all requests are similar in cost and all servers are similar in capacity.

2. Least Connections
Each new request is sent to the server with the fewest active connections at that moment.

Useful when some requests are long‑lived or heavy and simple round robin would overload a few servers.

3. IP Hash / Consistent Hashing
The backend is chosen based on a hash of the client IP (or another key).

The same client tends to hit the same server, which is helpful for sticky sessions or better cache locality.

🔹 Health Checks and Failover
A load balancer runs periodic health checks against each backend (for example, calling a /health endpoint) to ensure that only healthy servers receive traffic.

If a backend becomes unhealthy:
The load balancer temporarily removes it from the pool and stops sending traffic to it.
Once the server passes health checks again, it is added back to the pool.
This allows the system to remain available even when a single node fails, which is a core principle of high‑availability architectures.


🔹 System Design – Day 07 Takeaways
A load balancer (often implemented as a reverse proxy) distributes incoming requests across multiple backend servers to improve performance and resilience.

Round robin, least connections, IP hash, and health checks are fundamental concepts that are frequently expected in system‑design interviews.
