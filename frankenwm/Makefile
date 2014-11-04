.PHONY: prereq install

prereq:
	@sudo pacman --needed -S libxcb xcb-util xcb-util-wm xcb-util-keysyms

install:
	$(eval GITDIR := $(shell mktemp -d))
	echo $(GITDIR)
	cp config.h $(GITDIR)
	@cd $(GITDIR) && git clone git://github.com/sulami/FrankenWM && cd FrankenWM && cp ../config.h . && make && mkdir -p ~/bin && cp frankenwm ~/bin && rm -rf $(GITDIR)
