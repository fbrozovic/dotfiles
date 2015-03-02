# File: .zshrc

# Source Prezto.
if [[ -s "${ZDOTDIR:-$HOME}/.zprezto/init.zsh" ]]; then
  source "${ZDOTDIR:-$HOME}/.zprezto/init.zsh"
fi
zstyle ':completion:*' insert-tab false

# Aliases
alias dir="dir --color=auto"
alias egrep="egrep --color=auto"
alias ffs='sudo $(fc -ln -1)'
alias fgrep="fgrep --color=auto"
alias lr="ls -R"
alias ll="ls -alh"
alias la="ll -A"
alias lm="la | less"
alias vdir="vdir --color=auto"
alias vi="vim"
alias zconfig="vim ~/.zshrc"

# Customize to your needs...
export PATH=~/bin:/usr/local/bin:$PATH
#
set -o vi
#file extension aliases

alias -s pdf=zathura
alias -s tex=vim
alias -s mp3=mpv
alias -s mkv=mpv
alias -s avi=mpv
alias -s mp4=mpv
alias -s jpg=sxiv
alias -s png=sxiv
alias -s py=vim
alias -s c=vim
alias -s html=google-chrome-stable

HIST_IGNORE_ALL_DUPS="true"
export HISTSIZE=3000
export SAVEHIST=3000
export KEYTIMEOUT=1
export BROWSER=google-chrome-stable
export EDITOR=vim
export VISUAL=vim
export LANG=en_US.UTF-8
export XDG_CONFIG_HOME=~/.config
export LS_COLORS='di=34:ln=35:so=32:pi=33:ex=31:bd=36;01:cd=33;01:su=31;40;07:sg=36;40;07:tw=32;40;07:ow=33;40;07:'
