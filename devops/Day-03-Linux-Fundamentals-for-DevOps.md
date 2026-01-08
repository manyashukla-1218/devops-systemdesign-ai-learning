## 🔹 Why Linux for DevOps?

Most servers, containers, and cloud workloads run on Linux, so DevOps engineers must understand Linux fundamentals well.
Knowing the shell, file system, users, and processes is essential for deployment, debugging, and automation.

---

## 🔹 What is Linux?

Linux is an open‑source, Unix‑like operating system widely used for servers, cloud platforms, and containers.
It provides a kernel, system tools, and utilities that together form distributions such as Ubuntu, Debian, CentOS, and Red Hat.

Key concepts:

- **Kernel** – core part of the OS handling memory, processes, and hardware.  
- **Shell** – command‑line interface (like bash, zsh) that users interact with.

---

## 🔹 Linux Directory Structure (High-level)

Some important directories you will see on almost every Linux system:

- `/` – root of the entire file system.  
- `/home` – home directories for regular users.  
- `/root` – home directory for the root (superuser) account.  
- `/etc` – configuration files for system and services.  
- `/var` – variable data like logs (`/var/log`), spool files, and caches.  
- `/usr` – user‑installed programs and libraries.  
- `/bin`, `/sbin` – essential system binaries and admin commands.

Understanding this layout helps when debugging paths, checking logs, or editing configs.

---

## 🔹 Basic Linux Commands (Navigation & Files)

Some must‑know commands for navigation and file operations in a DevOps context:

- `pwd` – print current directory path.  
- `ls` – list files; commonly used options: `ls -l`, `ls -a`.  
- `cd` – change directory (for example, `cd /var/log`).  
- `mkdir` – create directory.  
- `touch` – create an empty file or update file timestamp.  
- `cp` – copy files or directories.  
- `mv` – move or rename files.  
- `rm` – remove files; `rm -r` for directories (dangerous, be careful).  
- `cat`, `less`, `tail -f` – view file contents and follow log files.

These commands are the base for almost all day‑to‑day operations on Linux servers.

---

## 🔹 Viewing System Information & Help

- `whoami` – shows current user.  
- `uname -a` – kernel and OS details.  
- `df -h` – disk usage of mounted filesystems.  
- `free -m` – memory usage.  
- `man <command>` – open manual page; for example, `man ls` shows documentation for `ls`.

Knowing how to quickly inspect system state and find help saves a lot of time in debugging.

---

## 🔹 Interview Questions

1. Why is Linux preferred for servers and DevOps work?  
2. Explain the purpose of directories like `/etc`, `/var`, and `/home`.  
3. Name at least five basic Linux commands used for navigation and file handling.

---

## ✅ What I Learned Today

- Linux is the standard platform for servers, containers, and cloud environments, so it is a core skill for DevOps engineers. 
- Understanding the directory structure and basic commands is the foundation for later topics such as permissions, processes, and shell scripting.
- Regular practice on a Linux terminal (WSL, VM, or cloud instance) is essential to build muscle memory for these commands.
