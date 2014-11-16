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


.PHONY: all prereq install install-config $(PREREQDIRS) $(INSTALLDIRS) $(INSTALLCONFIGDIRS)

install-frankenwm/: install-git/
