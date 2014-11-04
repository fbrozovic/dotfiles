# File: .zshrc
#Author: TingoL
#Contact e-mail: amelxmx [at] gmail [dot] com

# Source Prezto.
if [[ -s "${ZDOTDIR:-$HOME}/.zprezto/init.zsh" ]]; then
  source "${ZDOTDIR:-$HOME}/.zprezto/init.zsh"
fi
zstyle ':completion:*' insert-tab false

alias zconfig="vim ~/.zshrc"

# Customize to your needs...
export PATH=$PATH:/home/tingol/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin:/usr/bin/core_perl
#
set -o vi
#file extension aliases

alias -s smc=zsnes
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
alias -s html=dwb

HIST_IGNORE_ALL_DUPS="true"
export HISTSIZE=3000
export SAVEHIST=3000
export KEYTIMEOUT=1
export BROWSER=/usr/bin/dwb
export EDITOR=/usr/bin/vim
export VISUAL=/usr/bin/vim
export LANG=en_US.UTF-8
export XDG_CONFIG_HOME=/home/tingol/.config
export PROJECT_HOME=~/Dev
export WORKON_HOME=~/Envs
export LS_COLORS='di=34:ln=35:so=32:pi=33:ex=31:bd=36;01:cd=33;01:su=31;40;07:sg=36;40;07:tw=32;40;07:ow=33;40;07:'
VIRTUALENVWRAPPER_PYTHON=/usr/bin/python2
VIRTUALENVWRAPPER_VIRTUALENV=/usr/bin/virtualenv-2.7
#. /usr/bin/virtualenvwrapper.sh
