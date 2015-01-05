.PHONY: prereq install

prereq:
	@sudo pacman --noconfirm --needed -S git clang

install:
	@sudo pacman --noconfirm --needed -S gvim python2-pip python2
	@pip2 install --user git+git://github.com/Lokaltog/powerline
	@wget -O /tmp/PowerlineSymbols.otf https://github.com/Lokaltog/powerline/raw/develop/font/PowerlineSymbols.otf
	@wget -O /tmp/10-powerline-symbols.conf https://github.com/Lokaltog/powerline/raw/develop/font/10-powerline-symbols.conf
	@sudo mkdir -p /usr/share/fonts/local
	@sudo mv /tmp/PowerlineSymbols.otf /usr/share/fonts/local
	@mkdir -p ~/.config/fontconfig/conf.d
	@mv /tmp/10-powerline-symbols.conf ~/.config/fontconfig/conf.d
	@sudo fc-cache -vf /usr/share/fonts/local
	@git clone git://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/Vundle.vim
	@vim +PluginInstall +qall
	@cd ~/.vim/bundle/YouCompleteMe && ./install --clang-completer --system-libclang

