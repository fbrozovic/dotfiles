.PHONY: prereq install

prereq:
	@sudo pacman --noconfirm --needed -S git clang cmake wget

install:
	@sudo pacman --noconfirm --needed -S gvim python2-pip python2 ctags flake8
	@pip2 install --user git+git://github.com/Lokaltog/powerline
	@wget -O /tmp/PowerlineSymbols.otf https://github.com/Lokaltog/powerline/raw/develop/font/PowerlineSymbols.otf
	@sudo mkdir -p /usr/share/fonts/local
	@sudo mv /tmp/PowerlineSymbols.otf /usr/share/fonts/local
	@sudo fc-cache -vf /usr/share/fonts/local
	@[ -d ~/.vim/bundle/Vundle.vim ] || git clone git://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
