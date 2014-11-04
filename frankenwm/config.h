/* see LICENSE for copyright and license */
#include <X11/XF86keysym.h>

#ifndef CONFIG_H
#define CONFIG_H

/* Button definitions, nothing to edit for you */
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/* EDIT THIS: general settings */
#define MASTER_SIZE     0.52      /* master-stack ratio */
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False mean panel is on bottom */
#define PANEL_HEIGHT    14        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    TILE      /* TILE MONOCLE BSTACK GRID FIBONACCI EQUAL */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_MOUSE    False     /* Focus the window the mouse just entered */
#define FOLLOW_WINDOW   False     /* Follow the window when moved to a different desktop */
#define CLICK_TO_FOCUS  True      /* Focus an unfocused window when clicked */
#define BORDER_WIDTH    1         /* window border width */
#define FOCUS           "#cccccc" /* focused window border color   */
#define UNFOCUS         "#121212" /* unfocused window border color */
#define DESKTOPS        6         /* number of desktops - edit DESKTOPCHANGE keys to suit */
#define DEFAULT_DESKTOP 0         /* the desktop to focus on exec */
#define MINWSZ          50        /* minimum window size in pixels */
#define USELESSGAP      15        /* the size of the useless gap in pixels */
#define GLOBALGAPS      True      /* use the same gap size on all desktops */
#define MONOCLE_BORDERS False     /* display borders in monocle mode */
#define INVERT          False     /* use alternative modes by default */
#define AUTOCENTER      True      /* automatically center windows floating by default */
#define OUTPUT_TITLE    False     /* output the title of the currently active window */
#define USE_SCRATCHPAD  False     /* enable the scratchpad functionality */
#define SCRPDNAME       "scratchpad" /* the name of the scratchpad window */

/*
 * EDIT THIS: applicaton specific rules
 * Open applications to specified desktop with specified mode.
 * If desktop is negative, then current is assumed. Desktops are 0-indexed.
 * Sadly, this can not be empty (for now), so enter something non-existent if
 * you do not wish to use this functionality
 */
static const AppRule rules[] = { \
    /*  class     desktop  follow  float */
    { "vlc",         3,    True,    False },
    { "weechat",     2,    False,   False },     
    { "cmus",        2,    False,   False },     
    { "ranger",     -1,    False,   True },     
    { "sxiv",       -1,    False,   True },     
};

/* helper for spawning shell commands, usually you don't edit this */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/*
 * EDIT THIS: commands
 * Adjust and add these to the shortcuts below to launch anything you want by
 * pressing a key (combination). The last argument should ALWAYS be a null
 * pointer.
 */
static const char *termcmd[]        = { "termite", NULL };
static const char *webcmd[]         = { "google-chrome-stable", NULL };
static const char *filecmd[]        = { "rclick.menu", NULL };
static const char *menucmd[]        = { "dmenu-recent", NULL };
static const char *autostartcmd[]   = { "autostart", NULL };
static const char *calccmd[]        = { "dmenu-calc", NULL };
static const char *wallcmd[]        = { "dmenu-wall", NULL };
static const char *playcmd[]        = { "cmus-remote", "-u", NULL };
static const char *stopcmd[]        = { "cmus-remote", "-s", NULL };
static const char *pausecmd[]       = { "cmus-remote", "-p", NULL };
static const char *nextcmd[]        = { "cmus-remote", "-n", NULL };
static const char *prevcmd[]        = { "cmus-remote", "-r", NULL };
static const char *volupcmd[]       = { "exec", "amixer", "-q", "set", "PCM", "2dB+", "unmute", NULL };
static const char *voldncmd[]       = { "exec", "amixer", "-q", "set", "PCM", "2dB-", "unmute", NULL };
static const char *volmutecmd[]     = { "exec", "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *scrpcmd[]        = { "termite", NULL };

#define DESKTOPCHANGE(K,N) \
    {  MOD4,             K,              change_desktop, {.i = N}}, \
    {  MOD4|ShiftMask,   K,              client_to_desktop, {.i = N}},

/*
 * EDIT THIS: shortcuts
 * By default, all shortcuts use only Mod4 (+ Shift/Control), but you can use
 * Mod1 as well if you like to, I just prefer not to. (Update: handling
 * floating windows makes more sense when using Mod1 as well, so there's that)
 */
static key keys[] = {
    /* modifier          key            function           argument */

    /* select windows */
    {  MOD4,             XK_j,          next_win,          {NULL}},
    {  MOD4,             XK_k,          prev_win,          {NULL}},
    /* select the master window, or the previously focussed slave */
    {  MOD4,             XK_w,          focusmaster,       {NULL}},
    /* select urgent window */
    {  MOD4,             XK_BackSpace,  focusurgent,       {NULL}},

    /* move windows */
    {  MOD4|SHIFT,       XK_j,          move_down,         {NULL}},
    {  MOD4|SHIFT,       XK_k,          move_up,           {NULL}},
    /* swap the current window to master */
    {  MOD4,             XK_Return,     swap_master,       {NULL}},
    /* maximize the current window */
    {  MOD4,             XK_f,          maximize,          {NULL}},
    /* minimize window to queue/pull window from queue */
    {  MOD4,             XK_m,          minimize,          {NULL}},
    {  MOD4,             XK_n,          restore,           {NULL}},
    /* move the current window to the center of the screen, floating */
    {  MOD4,             XK_c,          centerwindow,      {NULL}},
    /* toggles inverted stacking modes (left/top stack) */
    {  MOD4|SHIFT,       XK_i,          invertstack,       {NULL}},
    /* show/hide all windows on all desktops */
    {  MOD4|CONTROL,     XK_s,          showhide,          {NULL}},
    /* toggle the scratchpad terminal, if enabled */
    {  MOD4,             XK_s,          togglescratchpad,  {NULL}},

    /* move floating windows */
    {  MOD4|MOD1,        XK_j,          float_y,           {.i = +10}},
    {  MOD4|MOD1,        XK_k,          float_y,           {.i = -10}},
    {  MOD4|MOD1,        XK_h,          float_x,           {.i = -10}},
    {  MOD4|MOD1,        XK_l,          float_x,           {.i = +10}},
    /* resize floating windows */
    {  MOD4|MOD1|CONTROL,XK_j,          resize_y,          {.i = +10}},
    {  MOD4|MOD1|CONTROL,XK_k,          resize_y,          {.i = -10}},
    {  MOD4|MOD1|CONTROL,XK_h,          resize_x,          {.i = -10}},
    {  MOD4|MOD1|CONTROL,XK_l,          resize_x,          {.i = +10}},
    /* reset the selected floating window to tiling */
    {  MOD4,             XK_t,          tilemize,          {NULL}},

    /* mode selection */
    {  MOD4|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    {  MOD4|SHIFT,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  MOD4|SHIFT,       XK_b,          switch_mode,       {.i = BSTACK}},
    {  MOD4|SHIFT,       XK_g,          switch_mode,       {.i = GRID}},
    {  MOD4|SHIFT,       XK_f,          switch_mode,       {.i = FIBONACCI}},
    {  MOD4|SHIFT,       XK_d,          switch_mode,       {.i = DUALSTACK}},
    {  MOD4|SHIFT,       XK_e,          switch_mode,       {.i = EQUAL}},

    /* spawn terminal, dmenu, w/e you want to */
    {  MOD4,             XK_Return,     spawn,             {.com = termcmd}},
    {  MOD4,             XK_r,          spawn,             {.com = menucmd}},
    {  MOD4,             XK_a,          spawn,             {.com = autostartcmd}},
    {  MOD4,             XK_q,          spawn,             {.com = menucmd}},
    {  MOD4,             XK_b,          spawn,             {.com = webcmd}},
    {  MOD4,             XK_c,          spawn,             {.com = calccmd}},
    {  MOD4,             XK_w,          spawn,             {.com = wallcmd}},
    {  0,      XF86XK_AudioPlay,        spawn,             {.com = playcmd}}, 
    {  0,      XF86XK_AudioPause,       spawn,             {.com = pausecmd}}, 
    {  0,      XF86XK_AudioNext,        spawn,             {.com = nextcmd}}, 
    {  0,      XF86XK_AudioPrev,        spawn,             {.com = prevcmd}}, 
    {  0,      XF86XK_AudioStop,        spawn,             {.com = stopcmd}}, 
    {  0,      XF86XK_AudioRaiseVolume, spawn,             {.com = volupcmd}}, 
    {  0,      XF86XK_AudioLowerVolume, spawn,             {.com = voldncmd}}, 
    {  0,      XF86XK_AudioMute,        spawn,             {.com = volmutecmd}}, 
    {  0,      XF86XK_Launch1,          spawn,             {.com = filecmd}}, 
    /* kill current window */
    {  MOD4|SHIFT,       XK_q,          killclient,        {NULL}},

    /* desktop selection */
       DESKTOPCHANGE(    XK_1,                             0)
       DESKTOPCHANGE(    XK_2,                             1)
       DESKTOPCHANGE(    XK_3,                             2)
       DESKTOPCHANGE(    XK_4,                             3)
       DESKTOPCHANGE(    XK_5,                             4)
       DESKTOPCHANGE(    XK_6,                             5)
    /* toggle to last desktop */
    {  MOD4,             XK_Tab,        last_desktop,      {NULL}},
    /* jump to the next/previous desktop */
    {  MOD4|CONTROL,     XK_h,          rotate,            {.i = -1}},
    {  MOD4|CONTROL,     XK_l,          rotate,            {.i = +1}},
    /* jump to the next/previous desktop with windows */
    {  MOD4|CONTROL|SHIFT, XK_h,        rotate_filled,     {.i = -1}},
    {  MOD4|CONTROL|SHIFT, XK_l,        rotate_filled,     {.i = +1}},

    /* resize master/first stack window */
    {  MOD4,             XK_h,          resize_master,     {.i = -10}},
    {  MOD4,             XK_l,          resize_master,     {.i = +10}},
    {  MOD4,             XK_o,          resize_stack,      {.i = -10}},
    {  MOD4,             XK_p,          resize_stack,      {.i = +10}},

    /* resize the borders */
    {  MOD4|CONTROL,     XK_u,          adjust_borders,    {.i = -1}},
    {  MOD4|CONTROL,     XK_i,          adjust_borders,    {.i = +1}},
    /* resize the useless gaps between the windows */
    {  MOD4|CONTROL,     XK_o,          adjust_gaps,       {.i = -1}},
    {  MOD4|CONTROL,     XK_p,          adjust_gaps,       {.i = +1}},
    /* toggle the panel space */
    {  MOD4|CONTROL,     XK_b,          togglepanel,       {NULL}},

    /* exit */
    {  MOD4|CONTROL,     XK_q,          quit,              {.i = 0}},
};

/* EDIT THIS: mouse-based shortcuts */
static Button buttons[] = {
    /* move/resize using the mouse */
    {  MOD4,    Button1,     mousemotion,   {.i = MOVE}},
    {  MOD4,    Button3,     mousemotion,   {.i = RESIZE}},
};
#endif
