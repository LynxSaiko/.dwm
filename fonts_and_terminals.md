# Linux Fonts & Terminals: Misc Fixed, Terminus, URxvt, Xterm

Panduan lengkap untuk menginstall font legendaris **Misc Fixed** dan **Terminus**, serta terminal minimalis **URxvt** dan **xterm**. Cocok untuk desktop ringan berbasis window manager seperti **DWM**, **i3**, **Fluxbox**, dan lainnya.

---


## 📦 Instalasi Berdasarkan Distro

## 📦 Debian / Ubuntu / Kali / Mint
```bash
sudo apt update

# Terminal
sudo apt install rxvt-unicode xterm

# Fonts: Misc Fixed (bitmap)
sudo apt install xfonts-base xfonts-75dpi

# Fonts: Terminus (bitmap dan TTF)
sudo apt install xfonts-terminus fonts-terminus


Arch / Manjaro / BlackArch

# Terminal
sudo pacman -S rxvt-unicode xterm

# Fonts: Misc Fixed (bitmap)
sudo pacman -S xorg-fonts-misc

# Fonts: Terminus
sudo pacman -S terminus-font ttf-terminus-nerd

Fedora

# Terminal
sudo dnf install rxvt-unicode xterm

# Fonts
sudo dnf install xorg-x11-fonts-misc terminus-fonts

openSUSE

# Terminal
sudo zypper install rxvt-unicode xterm

# Fonts
sudo zypper install xorg-x11-fonts terminus-fonts
