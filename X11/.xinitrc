#!/bin/sh
xsetroot -cursor_name watch
command -v warpcursor && warpcursor 1
xset +fp /usr/share/fonts/artwiz-fonts
xset +fp /usr/share/fonts/local
xset +fp ~/.fonts
xset fp rehash
xrdb -merge "${HOME}/.Xresources"
xset r rate 250 50
xsetroot -solid black
xsetroot -cursor_name left_ptr
feh --bg-scale $(cat ~/.wallpaper) &
#transmission-daemon &
compton -r 12 -o 0.5 -c -b
unclutter -idle 5 -noevents &
exec bspwm
