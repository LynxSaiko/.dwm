// -------------------------------- Appearance ---------------------------------
#include "patches/gaplessgrid.c"
// border pixel of windows
static const unsigned int borderpx  = 3;
// gaps between windows 
static const unsigned int gappx = 12;
// snap pixel 
static const unsigned int snap = 10;
static const unsigned int tagpadding = 13;
static const unsigned int tagspacing = 5;
// 0: sloppy systray follows selected monitor, >0: pin systray to monitor X 
static const unsigned int systraypinning = 0;
// systray spacing 
static const unsigned int systrayspacing = 2;
// 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor
static const int systraypinningfailfirst = 1;
// 0 means no systray
static const int showsystray = 1;
static const int user_bh = 23;
/* name & cls of panel win */
// 0 means no bar 
static const int showbar = 1;
// 0 means bottom bar 
static const int topbar = 1;
static const int vertpad = 4;       /* vertical padding of bar */
static const int sidepad = 4; 
//static const char *barlayout = "l";
static const int barheight = 24;

// ---------------------------------- Fonts ------------------------------------

static const char *fonts[] = { "xos4 Terminus:pixelsize=15:antialias=false:autohint:true" };
static const char dmenufont[] = "Misc Fixed:size=13:antialias=true:autohint=true";

/* color definitions */




// HAPUS enum jika ada
// HAPUS baris ini jika ada: enum { SchemeNorm, SchemeSel };

// Definisikan warna
static const char nord_fg[] = "#D8DEE9";
static const char nord_sel_fg[] = "#2e3440";
static const char nord_bg[] = "#0f101a"; 
static const char nord_sel_bg[] = "#C0C0C0";
static const char nord_border[] = "#2F343F";
static const char nord_main_fg[] = "#888888"; // Warna lebih redup untuk MAIN

// Array colors TANPA named indices
static const char *colors[][3] = {
    /* fg,         bg,         border */
    { nord_fg,    nord_bg,      nord_border },  // Index 0 (SchemeNorm)
    { nord_sel_fg, nord_sel_bg, nord_sel_bg },   // Index 1 (SchemeSel)
    { nord_main_fg,    nord_bg,      nord_bg },       // 2 = SchemeMain (untuk MAIN)
};


// -------------------------------- Workspaces ---------------------------------
static const char *tags[] = { "PENTEST", "DEVEL", "MISC", "INTERNET", "⧉" };

static const Rule rules[] = {
    /* xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     */

    // class      instance    title       tags mask     isfloating   monitor 
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

// ---------------------------------- Layouts ----------------------------------

static const float mfact = 0.55;  // factor of master area size [0.05..0.95] 
static const int nmaster = 1;     // number of clients in master area 
static const int resizehints = 0; // 1 means respect size hints in tiled resizals 

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      gaplessgrid },
	
};
// -------------------------------- Keybindings --------------------------------


#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,  view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,  toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,  tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,  toggletag,  {.ui = 1 << TAG} },

// Helper for spawning shell commands in the pre dwm-5.0 fashion 
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands
static char dmenumon[2] = "0";
//static char *dmenumon = NULL;
static const char *termcmd[]  = { "urxvt", NULL };
static const char *dmenucmd[] = {
    "dmenu_run", "-m", dmenumon,
    "-fn", dmenufont,
    NULL
};
//static const char *dmenucmd[] = { "dmenu_run", "-m", NULL };
//static const char *roficmd[] = { "/home/lazarus/.dwm/blackarch.sh", NULL };
//static const char *dmenucmd[] = { "rofi", "-show", "run", NULL };
#include <X11/XF86keysym.h>
static Key keys[] = {

    // ------------------ Windows ------------------
	{ MODKEY|ShiftMask,  XK_f,      setlayout,      {.v = &layouts[1]} },  // Pindah ke layout floating
    // Switch between windows
    { MODKEY, XK_j, focusstack, {.i = +1 } },
    { MODKEY, XK_k, focusstack, {.i = -1 } },

    // Change window sizes
    { MODKEY, XK_i, incnmaster, {.i = +1 } },
    { MODKEY|ShiftMask, XK_i, incnmaster, {.i = -1 } },
    { MODKEY|ShiftMask, XK_h, setmfact, {.f = -0.05} },
    { MODKEY|ShiftMask, XK_l, setmfact, {.f = +0.05} },

    // Toggle floating
    { MODKEY|ShiftMask, XK_f, togglefloating, {0} },

    // Toggle bar
    { MODKEY|ShiftMask, XK_b, togglebar, {0} },

    // Move windows in current stack
    { MODKEY|ShiftMask, XK_j, rotatestack, {.i = +1 } },
    { MODKEY|ShiftMask, XK_k, rotatestack, {.i = -1 } },

    // Cycle layouts
    { MODKEY, XK_Tab, cyclelayout, {.i = +1 } },
    { MODKEY|ShiftMask, XK_Tab, cyclelayout,  {.i = -1 } },

    // Increase - decrease gaps
    { MODKEY, XK_g, setgaps, {.i = -1 } },
    { MODKEY|ShiftMask, XK_g, setgaps, {.i = +1 } },
    // Focus next - prev monitor
    { MODKEY, XK_period, focusmon, {.i = +1 } },
    { MODKEY, XK_comma, focusmon, {.i = -1 } },

    // Send window to next - prev monitor
    { MODKEY|ShiftMask, XK_period, tagmon, {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1 } },

    // Change color scheme
    { MODKEY, XK_Left, schemeToggle, {0} },
    { MODKEY, XK_Right, schemeCycle, {0} },

    // Kill window
    { MODKEY, XK_w, killclient, {0} },

    // Restart dwm
    { MODKEY|ControlMask, XK_r, quit, {1} },

	
    // Quit dwm
    //{ MODKEY|ControlMask, XK_q, quit, {0} },

	{ MODKEY,                       XK_Tab,    cyclelayout,   {0} },

	

    // ---------------- Workspaces -----------------

    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    //TAGKEYS(XK_6, 5)
    //TAGKEYS(XK_7, 6)
    //TAGKEYS(XK_8, 7)
    //TAGKEYS(XK_9, 8)

    // ------------------- Apps --------------------
    //{ MODKEY|ShiftMask, XK_c, spawn, {.v = termcmd } }, 
    { MODKEY, XK_a, spawn, SHCMD("urxvt -bg black -fg green -fn \"xft:Misc Fixed:size=14\" -geometry 88x28") },
{ MODKEY, XK_b, spawn, SHCMD("urxvt -bg black -fg yellow -fn \"xft:Misc Fixed:size=14\" -geometry 88x28") },
{ MODKEY, XK_c, spawn, SHCMD("urxvt -bg black -fg red -fn \"xft:Misc Fixed:size=14\" -geometry 88x28") },
{ MODKEY, XK_d, spawn, SHCMD("urxvt -bg black -fg white -fn \"xft:Misc Fixed:size=14\" -geometry 88x28") },
    // dmenu
    //{ MODKEY, XK_r, spawn, {.v = dmenucmd } },

    // rofi
    //{ MODKEY, XK_m, spawn, SHCMD("rofi -modi drun,run -show drun -show-icons") },
    { MODKEY, XK_m, spawn, SHCMD("blackarch") },
    //{ MODKEY, XK_m, spawn, {.v = (const char *[]){ "dmenu_run", NULL } } },
    
    //{ MODKEY, XK_r, spawn, SHCMD("dmenu_run -b -sb grey -sf black  -p 'BlackarchMenu' -nb '#0f101a'  -fn 'Terminus-12'") },
    // { MODKEY, XK_r, spawn, SHCMD("dmenu_run -b -sb grey -sf black  -p 'BlackarchMenu'  -fn 'JILilliwaup-12'") },


    // blackarch-menu
    //{ MODKEY, XK_m, spawn, SHCMD("dmenu_launch") },    

    // Window nav (rofi)
    //{ MODKEY|ShiftMask, XK_m, spawn, SHCMD("rofi -show") },

    // Terminal
   // { MODKEY, XK_Return, spawn, SHCMD("urxvt") },

    // File explorer
    { MODKEY, XK_e, spawn, SHCMD("caja") },
    { MODKEY, XK_n, spawn, SHCMD("dmenu_run") },
    // Browser
    { MODKEY, XK_f, spawn, SHCMD("firefox") },
    
    { MODKEY, XK_v, spawn, SHCMD("virtualbox") },

    // Redshift
    { MODKEY, XK_r, spawn, SHCMD("redshift -O 2400") },
    { MODKEY|ShiftMask, XK_r, spawn, SHCMD("redshift -x") },

    // Screenshot
    { MODKEY, XK_s, spawn, SHCMD("scrot") },
    { MODKEY|ShiftMask, XK_s, spawn, SHCMD("scrot -s") },

    // ----------------- Hardware ------------------

    // Volume
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%")},
    {0, XF86XK_AudioMute, spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")},

    // Brightness
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set +10%")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 10%-")},

};

// click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin 
static Button buttons[] = {
    // click            event mask    button       function         argument 
    { ClkLtSymbol,      0,            Button1,     setlayout,       {0} },
    { ClkLtSymbol,      0,            Button3,     setlayout,       {.v = &layouts[2]} },
    { ClkLtSymbol,      0,          Button3,        cyclelayout,    {.i = +1 } }, // klik kanan putar layout
    { ClkWinTitle,      0,            Button2,     zoom,            {0} },
    { ClkStatusText,    0,            Button2,     spawn,           {.v = termcmd } },
    { ClkClientWin,     MODKEY,       Button1,     movemouse,       {0} },
    { ClkClientWin,     MODKEY,       Button2,     togglefloating,  {0} },
    { ClkClientWin,     MODKEY,       Button3,     resizemouse,     {0} },
    { ClkTagBar,        0,            Button1,     view,            {0} },
    { ClkTagBar,        0,            Button3,     toggleview,      {0} },
    { ClkTagBar,        MODKEY,       Button1,     tag,             {0} },
    { ClkTagBar,        MODKEY,       Button3,     toggletag,       {0} },
};
