 ## 🔹 What Is a REST API?

- A **REST API** exposes server resources over HTTP using a set of endpoints (URIs) and standard methods like GET, POST, PUT, DELETE.
- Core REST ideas: client–server separation, stateless requests, cacheability, layered architecture.

---

## 🔹 Identify Resources and URIs

- First step is **object modeling** – identify main resources (for example, users, orders, products) and relations.
- Each resource is exposed via a **noun‑based URI**, not action verbs.

**Examples**

- `/users` – collection of users.  
- `/users/{id}` – single user.  
- `/users/{id}/orders` – orders belonging to a user.

---

## 🔹 Use HTTP Methods Semantically

Common mapping:

- **GET** – read data (safe, no side‑effects).
- **POST** – create new resource or perform non‑idempotent action.  
- **PUT** – replace existing resource (idempotent).  
- **PATCH** – partial update.  
- **DELETE** – delete resource.

**Example**

- `GET /users/123` → fetch user 123.  
- `POST /users` → create a new user.  
- `DELETE /users/123` → delete user 123.

---

## 🔹 Request/Response and Status Codes

- Use standard **status codes** to convey result:
  - `200 OK` – success.  
  - `201 Created` – new resource created.  
  - `400 Bad Request` – invalid input.  
  - `401 Unauthorized` / `403 Forbidden`.  
  - `404 Not Found`.  
  - `500 Internal Server Error`.

- Prefer **JSON** responses with consistent structure: data + metadata + errors.

---

## 🔹 Versioning and Pagination (Brief)

- Version APIs using a path (`/v1/...`) or header so changes do not break old clients. 
- For list endpoints, add pagination parameters (`?page=1&limit=20` or cursor) to keep responses small and performant.

---

## 🔹 System Design – Day 10 Takeaways

- Good REST design focuses on **resource‑oriented URIs, proper HTTP methods, and clear status codes**. 
- Versioning, pagination, and consistent JSON shapes are standard expectations in system‑design interviews for API‑based services.
