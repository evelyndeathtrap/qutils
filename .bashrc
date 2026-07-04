alias grep='grep --color=auto'
PS1='[\u@\h \W]\$ '

command_not_found_handle() {
    local cmd="$1"
    length=${cmd}
    if [ "${#cmd}" -eq 1 ]; then
        echo fail
    else
        echo what
    fi
    
    return 127
}
