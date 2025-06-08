# <h3>Oh My Venus</h3>
![Preview](2025-06-09_01-52.png)


```bash
# ==============================================
#            LINUX / DWM SETUP TOOLS           
# ==============================================
user@linux:~$ sudo apt update && sudo apt install -y xfonts-terminus urxvt xterm

user@linux:~$ rofi -dump-config > config.rasi  
user@linux:~$ cd .dwm  

user@linux:~/.dwm$ sudo mv blackarch bar dmenu_run /usr/local/bin/  
user@linux:~/.dwm$ sudo mv simple-tokyonight.rasi /usr/share/rofi/themes/

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
$ MODKEY, XK_a ( Urxvt )
$ MODKEY, 1 ( Workspace 1 )
$ MODKEY, 2 ( Worspace 2 ) 
$ MODKEY, XK_r ( Dmenu )
$ MODKEY, XK_v ( Virtualbox )

# ==============================================
#             NOTES & TROUBLESHOOTING            
# ==============================================

# [!] Replace '$USER' with your actual username  
# [!] Requires sudo privileges for system paths

