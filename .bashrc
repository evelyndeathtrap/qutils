  GNU nano 9.1                        .bashrc                                   
#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
alias grep='grep --color=auto'
PS1='[\u@\h \W]\$ '

command_not_found_handle() {
    local cmd="$@"
    length=${cmd}


    if [ "${#cmd}" -eq 1 ]; then
        printf $cmd > /dev/random
        return 1
    elif [ "$#" -eq 1 ]; then
        echo fail
        return 2
    fi
    return 127
}
