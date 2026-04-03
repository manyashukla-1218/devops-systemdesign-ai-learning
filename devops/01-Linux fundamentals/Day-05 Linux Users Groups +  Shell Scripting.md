## Linux Users, Groups and Shell Scripting (Complete Notes)

---

## 1. Linux Users and Groups

### 1.1 Why Users and Groups Matter in DevOps

Most servers, containers, and cloud workloads run on Linux. Because of this, DevOps engineers must have a strong understanding of Linux users, groups, and permissions.

Correct user and group management helps in:
- Improving system security
- Enforcing least-privilege access
- Better auditability
- Running services and CI/CD pipelines safely

In real DevOps environments:
- CI runners (Jenkins, GitLab Runner) run under dedicated users
- Web servers and application processes use non-root users
- Database and background services have restricted permissions

This reduces the blast radius if any service is compromised.

---

### 1.2 Basic Concepts

#### User
A user represents either a human or a system/service account.

Examples:
- `ubuntu`
- `devuser`
- `jenkins`
- `nginx`

Each user has:
- A unique UID (User ID)
- A home directory (e.g. `/home/devuser`)
- A default shell (e.g. `/bin/bash`)

---

#### Group
A group is a logical collection of users.

Examples:
- `devops`
- `sudo`
- `www-data`

Groups allow shared access to files, directories, and scripts. Instead of assigning permissions to individual users, permissions are often assigned to groups.

---

#### File Ownership
Every file and directory in Linux has:
- An owner (user)
- A group
- Permissions for:
  - User
  - Group
  - Others

This ownership model is fundamental for security and access control.

---

### 1.3 Common User and Group Commands

```bash
# Create a new user with home directory and bash shell
sudo useradd -m -s /bin/bash devuser

# Set password for the user
sudo passwd devuser

# Create a new group
sudo groupadd devs

# Add user to group without removing existing groups
sudo usermod -aG devs devuser

# Display user ID and group information
id devuser
groups devuser


---

## 10. Today’s Learning (Day 05 Summary)

Today, I learned how Linux user and group management plays a critical role in DevOps environments.

Key takeaways:
- Linux users and groups help enforce **least-privilege access**, which is essential for system security.
- Services, applications, and CI/CD tools should always run using **non-root users** to reduce security risks.
- File ownership and permissions determine **who can read, write, or execute** scripts and resources.
- Shell scripts are the backbone of automation in DevOps, enabling repeatable and reliable workflows.
- Proper error handling and safe scripting practices prevent silent failures in production systems.

Overall, this day strengthened my understanding of how secure access control and automation work together in real-world DevOps setups.

---

## 11. Interview Questions and Answers (Linux Users & Shell Scripting)

### Q1. Why do DevOps teams create separate Linux users for services instead of using root?

**Answer:**  
Using separate Linux users improves security by following the principle of least privilege. If a service running as root is compromised, the attacker gains full control over the system. Running services under dedicated users limits access and reduces the blast radius of security incidents.

---

### Q2. What is the purpose of Linux groups in DevOps?

**Answer:**  
Linux groups allow multiple users to share access to files and directories. In DevOps, groups make permission management easier by assigning access at the group level instead of individual users, improving scalability and maintainability.

---

### Q3. What does the `-aG` option do in the `usermod` command?

**Answer:**  
The `-aG` option appends a user to a group without removing existing group memberships. This is important in DevOps to avoid accidentally revoking required permissions.

---

### Q4. What is a shell script?

**Answer:**  
A shell script is a text file containing a sequence of Linux commands executed by a shell (usually Bash). Shell scripts are widely used in DevOps for automation tasks like deployments, backups, monitoring, and CI/CD workflows.

---

### Q5. How do you make a shell script executable?

**Answer:**  
You make a script executable by changing its permissions using:
```bash
chmod +x script.sh
