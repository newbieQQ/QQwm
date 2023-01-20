/* See LICENSE file for copyright and license details. */

/* 外观部分 */

/* alt-tab configuration */
static const unsigned int tabModKey   = 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey = 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
//static const unsigned int tabPosY     = 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
//static const unsigned int tabPosX     = 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab     = 600;	/* tab menu width */
static const unsigned int maxHTab     = 200;	/* tab menu height */
static const unsigned int borderpx    = 1;        /* 边界多少像素 */
static const unsigned int gappx       = 12;       /* gap pixel between windows */
static const unsigned int snap        = 32;       /* snap pixel */
static const int showbar              = 1;        /* 0 means no bar */
static const int topbar               = 0;        /* 0 means bottom bar */

static const char *fonts[]          = { 
  "monospace:size=12",
  "WenQuanYi Micro Hei:size=12:type=Regular:antialias=true:autoint=true",
  "Symbols Nerd Font:pixelsize=17:type=2048-em:antialias=true:autoint=true",
};



static const char dmenufont[]       = "WenQuanYi Micro Hei:size=20:type=Regular:antialias=true:autoint=true";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#000000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  "};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance      title       tags mask     isfloating   monitor */
	{ "Gimp",           NULL,       NULL,       0,            1,           -1 },
	{ "Google Chrome",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact        = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "  ",      tile },    /* first entry is default */
	{ "  ",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2]          = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run",
//                                    "-m", dmenumon,
                                      "-fn", dmenufont,
//                                  "-nb", col_gray1,
//                                  "-nf", col_gray3,
//                                  "-sb", col_cyan,
//                                  "-sf", col_gray4,
                                     "-c", "-l", "8", NULL};
static const char *termcmd[]     = { "st", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };
static const char *obsidiancmd[] = { "obsidian", NULL };
static const char *roficmd[]     = { "rofi", "-show", "combi", NULL};
static const char *flameshot[]   = { "flameshot", "gui", NULL};
static const char *QQcmd[]       = { "linuxQQ", NULL};

static const Key keys[] = {
  /*                              键位                                */
	/* modifier                     key        function        argument */
	{ ControlMask|Mod1Mask,         XK_a,      spawn,          {.v = flameshot } },

	{ ControlMask|ShiftMask,        XK_p,      spawn,          {.v = dmenucmd } },
	{ ControlMask|ShiftMask,        XK_o,      spawn,          {.v = firefoxcmd } },
	{ ControlMask|ShiftMask,        XK_i,      spawn,          {.v = obsidiancmd } },
	{ ControlMask|ShiftMask,        XK_d,      killclient,     {0} },

	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
//	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      fullscreen,      {0} },
//	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ Mod1Mask,             		    XK_Tab,    altTabStart,	   {0} },

	TAGKEYS(                        XK_y,                      0)
	TAGKEYS(                        XK_u,                      1)
	TAGKEYS(                        XK_i,                      2)
	TAGKEYS(                        XK_o,                      3)
	TAGKEYS(                        XK_p,                      4)
	TAGKEYS(                        XK_x,                      5)

	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

