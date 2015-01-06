# dotfiles

These are my personal dotfiles for use on Arch Linux. The Makefile is currently made to work only with Arch, so a manual install (e.g. with GNU Stow or by manually symlinking the files to their correct locations) will be needed for other distributions.

## Getting Started

```
cd && git clone https://github.com/fbrozovic/dotfiles
cd dotfiles
make install
make install-config
make post-install
```

### User-specific setup
Some configuration files have to be created manually by the user in order for everything to work as intended.

#### bspwm
##### ~/.config/bspwm/netdev.cfg
This file defines the network interfaces whose IP addresses are shown in the bar:
```
WIFI_DEV="wlp14s0"
ETH_DEV="enp8s0"
```
If one or both devices are not present on the system, set the variable(s) to `none` or some other non-existent network interface.

##### ~/.config/bspwm/bspwmrc.local (optional)
This file contains any bspwm configuration commands which you do not want to push to github (e.g. if they're machine-specific or contain sensitive information).

#### mutt
Mutt is configured to use a GMail account, so the only thing missing is to set up the user credentials. Do this in the file `~/.mutt/userconfig.muttrc`:
```
set imap_user = username@gmail.com
set imap_pass = password
```

That's it, everything should now be nicely set up for the current user. You may want to change the GTK and Qt themes being used:

```
lxappearance
[Choose your favorite GTK theme]
qtconfig-qt4
[Under GUI Style, select GTK+ and save with C-s]
```
