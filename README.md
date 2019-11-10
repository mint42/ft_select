# FT_SELECT

ft_select is a systems project in the 42 curriculum. It introduces the concept of termcaps, and terminal manipulation in noncanonical mode. The goal of ft_select is to print a list of arguments, in an alternate screen, and to perform the following actions on that list:

- Use _arrow keys_ to move circularly through the list.
- Select and deselect arguments using the _space bar key_.
- Validate selections using _return key_ and return the list of selected arguments to the shell.

## Getting Started

This project uses [my 42 library](https://github.com/mint42/lib) which has been included as a git submodule. To set up this project, run `git clone https://github.com/mint42/ft_select` in the folder of your choice. Next, from the root of the ft_select repository run `git submodule update --init libft` to import the contents of the libft repository. Finally you can run `make` which will use the Makefile to build the library, and then the executable file `ft_select`.

```
usage: ./ft_select [args]
```

## Features

Aside from the basic features mentioned in the __FT_SELECT__ section, here is the full list of features [to be] implemented

- key support

_h key_ | left
_j key_ | down 
_k key_ | up
_l key_ | right
_a key_ | select all
_d key_ | delete
_r key_ | restore to default
_u key_ | undo delete
_q key_ | quit
_? key_ | help
_/ key_ | finder				

- scroll support

## References 

https://learn.sparkfun.com/tutorials/terminal-basics/all
https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html
https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html#SEC23
http://man7.org/linux/man-pages/man3/termios.3.html
https://www.gnu.org/software/libc/manual/html_node/Setting-Modes.html#Setting-Modes
https://www.gnu.org/software/libc/manual/html_node/Mode-Data-Types.html
https://www.gnu.org/software/libc/manual/html_node/Noncanonical-Input.html#Noncanonical-Input

## Author

[Ari Reedy](https://github.com/mint42/)
