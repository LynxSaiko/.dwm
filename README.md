# <h3>Oh My Venus</h3>
![Preview](2025-06-09_01-52.png)

- [`fonts_and_terminals.md`](fonts_and_terminals.md) – Panduan install font dan terminal di berbagai distro.

```bash
# ==============================================
#            LINUX / DWM SETUP TOOLS           
# ==============================================
Defaults Layouts [F] Move Layouts to [M] gapplesgrid shortcut windows + Tab

user@linux:~$ rofi -dump-config > config.rasi  
user@linux:~$ cd .dwm  

user@linux:~/.dwm$ sudo mv blackarch bar dmenu_run /usr/local/bin/  
user@linux:~/.dwm$ sudo mv simple-tokyonight.rasi /usr/share/rofi/themes/
user@linux:~/.dwm$ mv .Xresources /home/$USER/ && xrdb -merge ~/.Xresources
user@linux:~/.dwm$ sudo make clean install  
user@linux:~/.dwm$ exit  

# ==============================================
#           USEFUL COMMANDS (OPTIONAL)          
# ==============================================

user@linux:~$ ls /usr/share/rofi/themes/       # List themes  
user@linux:~$ blackarch  # Menu rofi themes


# ==============================================
#           SHORTCUT COMMANDS (OPTIONAL)          
# ==============================================
MODKEY is Windows + combination  next to space
$ MODKEY, XK_f ( Firefox )
$ MODKEY, XK_m ( Menu )
$ MODKEY, XK_a ( Urxvt Green )
$ MODKEY, XK_b ( Urxvt Yellow )
$ MODKEY, XK_c ( Urxvt Red )
$ MODKEY, XK_d ( Urxvt White )
$ MODKEY, XK_e ( caja )
$ MODKEY, 1 ( Workspace 1 )
$ MODKEY, 2 ( Worspace 2 )
$ MODKEY, 3 ( Worspace 3 )
$ MODKEY, 4 ( Worspace 4 )
$ MODKEY, XK_n ( Dmenu )
$ MODKEY, XK_w ( KIll Apps )
$ MODKEY, XK_v ( Virtualbox )

# ==============================================
#             NOTES & TROUBLESHOOTING            
# ==============================================

# [!] Replace '$USER' with your actual username  
# [!] Requires sudo privileges for system paths

