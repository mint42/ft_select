# FT_SELECT

ft_select is a systems project in the 42 curriculum. It introduces the concept of termcaps, and terminal manipulation in noncanonical mode. The goal of ft_select is to print a list of arguments, in an alternate screen, and to perform the following actions on that list:

- Use arrow keys to move circularly through the list.
- Select and deselect arguments using the 'space bar' key.
- Delete item under cursor with 'backspace' or 'delete'.
- Validate selections using 'return' key and return the list of selected arguments to the shell, or exit the program without gettings the selected items by using 'q' or 'Esc'.

This project should also handle signals.

## Getting Started

ft_select uses [my 42 library](https://github.com/mint42/lib) which has been included as a git submodule. To set up this project, run `git clone https://github.com/mint42/ft_select` in the folder of your choice. Next, from the root of the ft_select repository run `git submodule update --init libft` to import the contents of the libft repository. Finally you can run `make` which will use the Makefile to build the library, and then the executable file `ft_select`.

```
usage: ft_select [args]
```

## Features

Aside from the basic features mentioned in the [ft_select](https://github.com/mint42/ft_select#ft_select) section, here is the full list of features implemented

- Extra key support

	-	select all
	-	delete all selected
	-	restore to default
	-	undo last deleted group
	-	help menu (auto updating)

- Adjustable window padding for X and Y axis

- Customizable output format

These options can be configured in the [config.h](https://github.com/mint42/ft_select/blob/master/includes/config.h) file

## References 

- https://learn.sparkfun.com/tutorials/terminal-basics/all
- https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html
- http://man7.org/linux/man-pages/man3/termios.3.html
- https://www.gnu.org/software/libc/manual/html_mono/libc.html#Low_002dLevel-Terminal-Interface
- https://en.wikipedia.org/wiki/Box-drawing_character

## Author

[Ari Reedy](https://github.com/mint42/)
