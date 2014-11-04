# .bashrc
# Modified from helmuthdu's Arch Ultimate Installer <http://github.com/helmuthdu/aui> by Filip Brozovic <fbrozovic@gmail.com> 

# Conditionals
_islinux=false
[[ "$(uname -s)" =~ Linux|GNU|GNU/* ]] && _islinux=true

_isarch=false
[[ -f /etc/arch-release ]] && _isarch=true

_isxrunning=false
[[ -n "$DISPLAY" ]] && _isxrunning=true

_isroot=false
[[ $UID -eq 0 ]] && _isroot=true


# PS1 Configuration
  [[ -f $HOME/.dircolors ]] && eval $(dircolors -b $HOME/.dircolors)
  if $_isxrunning; then

    [[ -f $HOME/.dircolors_256 ]] && eval $(dircolors -b $HOME/.dircolors_256)

    export TERM='xterm-256color'

     B='\[\e[1;38;5;33m\]'
    LB='\[\e[1;38;5;81m\]'
    GY='\[\e[1;38;5;242m\]'
     G='\[\e[1;38;5;82m\]'
     P='\[\e[1;38;5;161m\]'
    PP='\[\e[1;38;5;93m\]'
     R='\[\e[1;38;5;196m\]'
     Y='\[\e[1;38;5;214m\]'
     W='\[\e[0m\]'

    get_prompt_symbol() {
      [[ $UID == 0 ]] && echo "#" || echo "\$"
    }

    if [[ $PS1 && -f /usr/share/git/git-prompt.sh ]]; then
      source /usr/share/git/completion/git-completion.bash
      source /usr/share/git/git-prompt.sh

      export GIT_PS1_SHOWDIRTYSTATE=1
      export GIT_PS1_SHOWSTASHSTATE=1
      export GIT_PS1_SHOWUNTRACKEDFILES=0

      export PS1="$GY[$Y\u$GY@$P\h$GY:$B\W\$(__git_ps1 \"$GY|$LB%s\")$GY]$W\$(get_prompt_symbol) "
    else
      export PS1="$GY[$Y\u$GY@$P\h$GY:$B\W$GY]$W\$(get_prompt_symbol) "
    fi
  else
    export TERM='xterm-color'
  fi


# bash options
  shopt -s cdspell                 # Correct cd typos
  shopt -s checkwinsize            # Update windows size on command
  shopt -s histappend              # Append History instead of overwriting file
  shopt -s cmdhist                 # Bash attempts to save all lines of a multiple-line command in the same history entry
  shopt -s extglob                 # Extended pattern
  shopt -s no_empty_cmd_completion # No empty completion
  # Autocompletion
    complete -cf sudo
    if [[ -f /etc/bash_completion ]]; then
      . /etc/bash_completion
    fi


# Exports
  export PATH=~/bin:/usr/local/bin:$PATH
  # Colored manpages
    if $_isxrunning; then
      export PAGER=less
      export LESS_TERMCAP_mb=$'\E[01;31m'       # begin blinking
      export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold
      export LESS_TERMCAP_me=$'\E[0m'           # end mode
      export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode
      export LESS_TERMCAP_so=$'\E[38;5;246m'    # begin standout-mode - info box
      export LESS_TERMCAP_ue=$'\E[0m'           # end underline
      export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline
    fi


# Aliases
  # Automatic coloring
    alias ls='ls --color=auto'
    alias dir='dir --color=auto'
    alias vdir='vdir --color=auto'
    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
  # ls stuff
    alias lr='ls -R'                    # recursive ls
    alias ll='ls -alh'
    alias la='ll -A'
    alias lm='la | less'

    alias vi='vim'

    alias ffs='sudo $(history -p \!\!)'


#          git config --global user.name $NAME
#          git config --global user.email $EMAIL
#          git config --global github.user $USER
#          git config --global color.ui true
#          git config --global color.status auto
#          git config --global color.branch auto
#          git config --global color.diff auto
#          git config --global diff.color true
#          git config --global core.filemode true
#          git config --global push.default matching
#          git config --global core.editor $EDITOR
#          git config --global format.signoff true
#          git config --global alias.reset 'reset --soft HEAD^'
#          git config --global alias.graph 'log --graph --oneline --decorate'
  # up: goes up many dirs as the number passed as argument, if none goes up by 1 by default
    up() {
      local d=""
      limit=$1
      for ((i=1 ; i <= limit ; i++)); do
        d=$d/..
      done
      d=$(echo $d | sed 's/^\///')
      if [[ -z "$d" ]]; then
        d=..
      fi
      cd $d
    }
