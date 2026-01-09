* **Why Linux permissions matter for DevOps**
  * Almost all servers, containers, and cloud workloads run on Linux, so DevOps engineers continuously work with files, logs, configs, and services on Linux.
  * Correct users, groups, and permissions decide who can deploy, read logs, edit configs, or restart services; wrong settings frequently cause “Permission denied” errors in CI/CD pipelines.

---

## Users, Groups, and Ownership

* **Linux as a multi‑user system**
  * Every person or service runs as a specific user account and can belong to one or more groups.
  * User information (name, UID, home directory, shell) is defined in `/etc/passwd`, while group information (name, GID, members) is in `/etc/group`.

* **Basic terms**
  * *User* – account like `ubuntu`, `manya`, `nginx`, `jenkins`, each with its own UID and usually a home directory such as `/home/manya`.
  * *Group* – collection of users (for example, `devops`, `sudo`, `www-data`) used to share permissions.
  * Every file or directory has:
    * an **owner** (user),
    * an **owning group**,
    * permission bits for **owner**, **group**, and **others**.

* **Seeing ownership**
  * Command: `ls -l`
  * Example output:  
    `-rw-r--r-- 1 manya devops 2048 Jan  9  notes.txt`
    * Owner = `manya`, group = `devops`, permissions = `-rw-r--r--`.

---

## Permission Bits (r, w, x)

* **Structure of the permission string**
  * 10 characters: `[type][owner][group][others]`.
  * Type: `-` regular file, `d` directory, `l` symlink, etc.
  * Each permission triplet uses:
    * `r` = read,
    * `w` = write,
    * `x` = execute (for files) or “enter” (for directories),
    * `-` = no permission.

* **Example – directory**
  * `drwxr-x---`
    * `d` → directory.
    * Owner: `rwx` – full control (list, create, delete, enter).
    * Group: `r-x` – list and enter, but cannot create/delete.
    * Others: `---` – no access.[web:63]

* **Special meaning for directories**
  * `r` – list entries (see file names).
  * `w` – create, delete, or rename entries.
  * `x` – `cd` into the directory and access contents.

---

## chmod – Changing Permissions

* **Symbolic mode**
  * Syntax: `chmod [who][+/-/=][permissions] file`
  * `who`: `u` (user/owner), `g` (group), `o` (others), `a` (all).
  * Examples:
    * `chmod u+x script.sh` – add execute for owner.
    * `chmod g-w script.sh` – remove write from group.
    * `chmod o-r secrets.txt` – others cannot read.
    * `chmod ug+r file.log` – owner and group can read.

* **Numeric mode**
  * Permissions mapped to numbers:
    * read = 4, write = 2, execute = 1.
  * Sum per owner/group/others:
    * `7` = `rwx`, `6` = `rw-`, `5` = `r-x`, `4` = `r--`.
  * Examples:
    * `chmod 755 deploy.sh` → `rwxr-xr-x` (owner full; others can read/execute, common for scripts/binaries).
    * `chmod 644 config.yml` → `rw-r--r--` (owner can edit; others read only, common for configs/web assets).
    * `chmod 700 id_rsa` → `rwx------` (only owner can access private key).
    * `chmod 770 /var/shared` → `rwxrwx---` (owner and group full; no access for others).

---

## chown / chgrp – Changing Ownership

* **Why ownership changes are needed**
  * Services like `nginx`, `jenkins`, or app containers often run as their own users; files they need must be owned by or accessible to those users.
  * Mismatched ownership on volumes or log directories is a common cause of runtime permission issues.

* **Commands**
  * `chown user file` – change owner.
  * `chown user:group file` – change owner and group in one go.
  * `chgrp group file` – change only group.
  * Add `-R` for recursive changes on directories.

* **Examples**
  * `sudo chown -R nginx:nginx /var/www/myapp` – web server owns app files for serving static content and writing cache.
  * `sudo chgrp devops deploy.sh` – give `devops` group ownership of a deployment script.

---

## Practical Scenario – Shared DevOps Project Directory

* **Goal**
  * `/var/shared_project` directory where only DevOps team members have full access; others have none.

* **Steps**
  * `sudo mkdir /var/shared_project` – create the directory.
  * `sudo groupadd devs` – create `devs` group (if it does not exist).
  * `sudo chgrp devs /var/shared_project` – set group to `devs`.
  * `sudo chmod 770 /var/shared_project` – owner + group full, others no access.
  * `sudo usermod -aG devs alice` and `sudo usermod -aG devs bob` – add users to the group.

* **Result**
  * Only users in `devs` group can enter and modify contents; others will get a permission error.

---

## Essential File and Directory Commands (DevOps Daily Use)

* **Navigation and management**
  * `pwd` – show current directory.
  * `cd /var/log` – move to log directory.
  * `ls -la` – detailed listing including hidden files.
  * `mkdir releases` – create directory.
  * `touch app.log` – create empty file/update timestamp.
  * `cp file1 file2` – copy file.
  * `mv old new` – move/rename file.
  * `rm file.txt` – delete file.
  * `rm -rf build/` – delete directory recursively (dangerous, double‑check path).

* **Viewing and searching**
  * `cat app.log` – print file contents.
  * `less app.log` – paged viewer for large files.
  * `head -n 20 app.log` – first 20 lines.
  * `tail -n 50 app.log` – last 50 lines.
  * `tail -f app.log` – follow log in real time during debugging.
  * `find . -name "*.log"` – find all `.log` files in current tree.
  * `grep "ERROR" app.log` – search for lines containing “ERROR”.
  * `grep -R "DATABASE_URL" .` – recursively search for `DATABASE_URL` in project.

---

## Process Monitoring and Troubleshooting

* **Why processes matter**
  * Services and applications run as processes; monitoring them is essential when debugging crashes, high load, or memory leaks.

* **Key commands**
  * `ps aux | grep nginx` – show processes matching `nginx`.
  * `top` – live view of CPU, memory, and processes.
  * `htop` – improved interactive process viewer (if installed).
  * `kill 1234` – send SIGTERM to PID `1234` for graceful shutdown.
  * `kill -9 1234` – send SIGKILL to forcefully stop a stuck process.

* **Typical debugging flow**
  * Use `top`/`htop` to identify a process using too much CPU or RAM.
  * Inspect details with `ps aux | grep <service>`.
  * Kill or restart the service, then check logs with `tail -f` for root cause.

---

## sudo and Least Privilege

* **Concept**
  * Instead of logging in as `root`, DevOps engineers log in as normal users and use `sudo` to run only those commands that need elevated privileges.

* **Behavior**
  * `sudo` runs the command as root (or another configured user) and records it in logs for auditing.
  * Permissions and allowed commands per user/group are defined in `/etc/sudoers` and related config files.

* **Examples**
  * `sudo apt update` – update package index.
  * `sudo systemctl restart nginx` – restart web server.
  * `sudo tail -f /var/log/nginx/access.log` – follow privileged log file.

* **Best practices**
  * Do everyday work (editing code, local scripts) without `sudo`.
  * Use `sudo` only for tasks that truly require root, like installing packages, editing `/etc/...` configs, or changing ownership in system paths.

---

## Mini Checklist for Day 04

* I can read the output of `ls -l` and explain the owner, group, and permissions of any file or directory.
* I know how to use `chmod` in both symbolic (`u+x`, `g-w`) and numeric (`755`, `644`, `700`) forms.
* I can use `chown` and `chgrp` to fix ownership issues for services and shared directories.
* I am comfortable with navigation (`cd`, `ls`), file management (`cp`, `mv`, `rm`), and searching with `find` + `grep`.
* I can inspect running processes (`ps`, `top`, `htop`) and terminate or restart problematic ones.
* I understand how and when to use `sudo`, following the principle of least privilege.

---

## Interview Questions

* **Q1.** Explain the permission string `drwxrwxr-x`. Who can read, write, and execute in this directory?  
* **Q2.** What is the difference between `chmod 755` and `chmod 644`? Give one real use-case for each.  
* **Q3.** How would you create a shared directory that only DevOps team members can read/write and others cannot access?  
* **Q4.** A deployment script fails with “Permission denied” while writing logs to `/var/log/app`. Which commands and checks would you run to debug and fix this?

---

## ✅ What I Learned Today

* Linux users, groups, and permission bits are the foundation for secure deployments and shared environments in real DevOps work.[web:61][web:67]
* Commands like `chmod`, `chown`, `find`, `grep`, `ps`, `top`, and `sudo` form the everyday toolbox for managing servers and resolving access or performance problems.[web:62][web:63][web:68]
* Practicing realistic scenarios—like creating shared project folders and fixing “Permission denied” errors—builds practical intuition that transfers directly to production systems.[web:66][web:60]
