## Why Package Management Matters

Package management is a core responsibility of DevOps engineers. Linux servers rely on package managers to install, update, and remove software in a consistent and automated manner. These tools help maintain reproducible environments across development, testing, and production systems.

Key benefits:
- Dependency management
- Version control of software
- Automation-friendly installations
- Security updates and patches

---

## Package Management Basics

A **package** contains software binaries, configuration files, and dependency information.  
A **repository** is a remote server that stores packages.

Package managers automatically:
- Resolve dependencies
- Fetch packages from repositories
- Install and upgrade software

---

## Debian / Ubuntu Package Management (`apt`)

`apt` is used in Debian-based Linux distributions such as Ubuntu. It works with `.deb` packages.

### Common `apt` Commands

```bash
# Update local package index
sudo apt update

# Install a package
sudo apt install nginx

# Remove a package (keep configuration files)
sudo apt remove nginx

# Remove package with configuration files
sudo apt purge nginx

# Upgrade all installed packages
sudo apt upgrade

# Search for a package
apt search docker
