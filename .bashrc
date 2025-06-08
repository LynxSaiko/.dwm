# colors
darkgrey="$(tput bold ; tput setaf 0)"
white="$(tput bold ; tput setaf 7)"
blue="$(tput bold; tput setaf 4)"
cyan="$(tput bold; tput setaf 6)"
nc="$(tput sgr0)"

# exports
export PATH="${HOME}/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:"
export PATH="${PATH}/usr/local/sbin:/opt/bin:/usr/bin/core_perl:/usr/games/bin:"
export PS1="\[$blue\][ \[$cyan\]\H \[$darkgrey\]\w\[$darkgrey\] \[$blue\]]\\[$darkgrey\]# \[$nc\]"
export LD_PRELOAD=""
export EDITOR="vim"
export LD_LIBRARY_PATH=/opt/python/3.9.14/lib:$LD_LIBRARY_PATH
# alias
alias ls="ls --color"
alias vi="vim"
alias shred="shred -zf"
#alias python="python2"
alias wget="wget -U 'noleak'"
alias curl="curl --user-agent 'noleak'"
alias clear='printf "\033c"'
alias python3=/opt/python/3.9.14/bin/python3
alias pip3=/opt/python/3.9.14/bin/pip3
# source files
[ -r /usr/share/bash-completion/completions ] &&
  . /usr/share/bash-completion/completions/*

[ -f ~/.fzf.bash ] && source ~/.fzf.bash
