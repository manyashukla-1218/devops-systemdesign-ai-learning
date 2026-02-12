## 🔹 Why Containers and Docker?

- Traditional deployments depend on OS packages and manual setup; “works on my machine” issues are common. 
- **Docker** packages an application with its dependencies into a **container**, so it behaves the same across laptops, servers, and clouds.

---

## 🔹 Images vs Containers

- **Docker Image**
  - A **read‑only blueprint** that contains the app code, runtime, libraries, and OS dependencies.
  - Built from a **Dockerfile** (set of instructions like `FROM`, `COPY`, `RUN`, etc.).

- **Docker Container**
  - A **running instance** of an image with its own filesystem and process namespace. 
  - Many containers can be created from the same image.

Analogy: image = class / blueprint, container = object / running instance.

---

 ## 🔹 Basic Docker Workflow (High Level)

Common lifecycle steps:

1. **Pull** or **build** an image.  
2. **Run** a container from the image.  
3. Map ports to expose the app.  
4. Use **volumes** to persist data if needed.

Conceptual commands:

- `docker pull image` – download image from registry.  
- `docker run image` – start a container.  
- `docker ps` – list running containers.  
- `docker stop` / `docker rm` – stop and remove containers.

(You will write actual commands and Dockerfiles in later hands‑on days.)

---

## 🔹 Registries and Docker Hub

- A **container registry** stores and distributes Docker images (for example, Docker Hub, GitHub Container Registry, cloud‑specific registries).  
- Teams push their built images to a registry; servers/CI then pull from there during deployments.

---

## 🔹 DevOps – Takeaways

- Docker solves environment drift by packaging apps into images, which run as containers on any host with the Docker Engine.
- Key ideas to remember: image vs container, basic lifecycle (build/pull → run → manage), and registries for sharing images in real DevOps workflows.
