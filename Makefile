DIRS=$(sort $(dir $(wildcard */)))
PREREQDIRS=$(DIRS:%=prereq-%)
INSTALLDIRS=$(DIRS:%=install-%)
INSTALLCONFIGDIRS=$(DIRS:%=install-config-%)

prereq: prereq-global $(PREREQDIRS)

install: prereq $(INSTALLDIRS)

install-config: $(INSTALLCONFIGDIRS)

$(PREREQDIRS):
	$(MAKE) -C $(@:prereq-%=%) prereq

$(INSTALLDIRS):
	$(MAKE) -C $(@:install-%=%) install

$(INSTALLCONFIGDIRS):
	@stow $(@:install-config-%=%)

prereq-global:
	@[ -f /etc/arch-release ] || (echo \*\*\* Not running on Arch Linux. Stop. && exit 1)
	@echo Making sure the system is up to date...
	@sudo pacman --noconfirm --needed -Syu
	@if hash stow; then echo "GNU Stow found"; else sudo pacman --noconfirm --needed -S stow; fi

post-install:
	@echo Configuring vim plugins...
	@vim +PluginInstall +qall
	@~/.vim/bundle/YouCompleteMe/install.sh --clang-completer --system-libclang 


.PHONY: all prereq install install-config $(PREREQDIRS) $(INSTALLDIRS) $(INSTALLCONFIGDIRS) post-install

install-frankenwm/: install-git/
