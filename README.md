# dotfiles

These are my personal dotfiles for use on Arch Linux. The Makefile is currently made to work only with Arch, so a manual install (e.g. with GNU Stow or by manually symlinking the files to their correct locations) will be needed for other distributions.

## Getting Started

```
cd && git clone https://github.com/fbrozovic/dotfiles
cd dotfiles
make install
make install-config
```

That's it, everything should now be nicely set up for the current user. You may want to change the GTK and Qt themes being used:

```
lxappearance
[Choose your favorite GTK theme]
qtconfig-qt4
[Under GUI Style, select GTK+ and save with C-s]
```
