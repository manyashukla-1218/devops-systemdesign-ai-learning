 ## 🔹 What is an API in System Design?

An API (Application Programming Interface) defines how two software components communicate through well-structured requests and responses. 
In distributed systems, APIs connect clients, backend services, databases, and third‑party systems, making them the backbone of modern architectures.

APIs hide internal implementation details and expose only necessary operations, which improves modularity and security.  

---
## 🔹 HTTP as the Transport Layer

Most web APIs use HTTP or HTTPS as the underlying protocol.

Key concepts:

- **HTTP methods**:  
  - `GET` – read data.  
  - `POST` – create new resource.  
  - `PUT` / `PATCH` – update existing resource.  
  - `DELETE` – remove resource.

- **URL (endpoint)**:  
  - Identifies the resource or action, for example `/users`, `/orders/123/items`.

- **Headers**:  
  - Carry metadata like `Content-Type`, `Authorization`, and caching directives.

- **Body**:  
  - Contains the data for POST/PUT/PATCH requests, often in JSON format.

---

## 🔹 REST Architectural Style

REST (Representational State Transfer) is a widely used style for designing HTTP APIs.

### Core Principles

1. **Client‑Server**  
   - Clients and servers evolve independently; clients only know about the API contract, not implementation.[web:55]

2. **Statelessness**  
   - Each request must carry all necessary context (such as auth token); the server does not store client session state between requests.[web:55]

3. **Uniform Interface**  
   - Standard use of HTTP methods, URLs, status codes, and media types (like JSON).  
   - Resources have unique URIs like `/users/123`, `/orders/456`.

4. **Layered System**  
   - Clients may talk to intermediaries (proxies, API gateways, load balancers) without knowing the underlying layers.

5. **Cacheability**  
   - Responses explicitly mark whether they can be cached using headers like `Cache-Control` or `ETag`.

---

## 🔹 Designing Resource-Oriented APIs

REST encourages modeling the system around **resources**, not actions.

Example: User and order system

- Resources: `users`, `orders`, `products`.  
- Endpoints:  
  - `GET /users` – list users.  
  - `GET /users/123` – get one user.  
  - `POST /users` – create user.  
  - `GET /users/123/orders` – list orders for user 123.

Benefits:

- Easy to understand and document.  
- Fits naturally with CRUD operations and HTTP semantics.

---

## 🔹 Request–Response Example (JSON)

**Request**

```http
POST /users HTTP/1.1
Host: api.example.com
Content-Type: application/json

{
  "name": "Manya",
  "email": "manya@example.com"
}
Response

text
HTTP/1.1 201 Created
Location: /users/123
Content-Type: application/json

{
  "id": 123,
  "name": "Manya",
  "email": "manya@example.com",
  "createdAt": "2026-01-09T18:30:00Z"
}
Here:

Status code 201 Created indicates success and resource creation.

Location header points to the new resource URL.

🔹 Status Codes and Error Handling
Common HTTP status codes in REST APIs:[web:55][web:58]

200 OK – successful request.

201 Created – resource created.

204 No Content – success, no body (for example, after DELETE).

400 Bad Request – client sent invalid data.

401 Unauthorized – missing/invalid authentication.

403 Forbidden – authenticated but not allowed.

404 Not Found – resource does not exist.

500 Internal Server Error – unexpected server failure.

APIs usually return structured error objects:

json
{
  "error": "ValidationError",
  "message": "Email is invalid"
}
This makes client‑side debugging much easier.

🔹 Simple System Design Example – Task Management API
Imagine a task management app (like Trello but simpler).

Resources: users, boards, tasks.

Design example:

GET /boards – list boards for current user.

POST /boards – create board.

GET /boards/{id}/tasks – tasks under a board.

POST /boards/{id}/tasks – create task on a board.

Tokens (JWT) are sent via Authorization: Bearer <token> header.
Clients (web app, mobile app) all consume the same API, showing how APIs decouple frontend and backend.

🔹 Interview Questions
What is a RESTful API, and what do “stateless” and “resource-oriented” mean in this context?

How would you design basic endpoints for a user and order management system?

Why is using proper HTTP status codes important in API design?

✅ What I Learned Today
APIs provide structured contracts between services and are central to modern system design.

RESTful APIs model resources with URLs, use HTTP methods semantically, and rely on stateless requests and JSON responses.[web:55][web:58]

Good API design (clear resources, proper status codes, helpful error bodies) makes systems easier to use, document, and scale across multiple clients.
