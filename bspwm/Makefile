.PHONY: prereq install

prereq:
	@rm -rf /tmp/phallus-fonts && git clone git://github.com/phallus/fonts /tmp/phallus-fonts && cd /tmp/phallus-fonts && ./install

install:
	@yaourt --noconfirm --needed -S bspwm-git sxhkd-git
