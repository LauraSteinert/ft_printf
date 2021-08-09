# ft_printf
Because putnbr and putstr aren’t enough.
Made for 42sp.

## How does it work?
My version of printf is extremally forward, with no use of structs for types of conversion or length of the printed string/number/everything your heart desires.
It holds cspdiuxX% conversions, and no flags (maybe a work in progress. probably not.)
The function comes with a associated Makefile and I heavely use my library, that has it's own Makefile: [libft](https://github.com/LauraSteinert/libft).
First, the function parameter starts with a va_list, to get all the possible arguments that a person can pass to the printf function.

### va_list
va_list is a macro function that is able to hold a undefined number of arguments. It can be initialized with va_start, and ended with va_end. As it is a list of the arguments passed, in order to reach for the next one, you should use va_arg, that acess the next argument. 

### Cases
The subfunction "cases" will deal with the conversions handled. It will be called after a while that goes until the end of the arguments under "format". Before that, if we have a character that it's not '%', we should place it in the screen and add one to our "length" variable. That can be made using the "ft_putchar_fd" from libft.
Entering "cases", we will see which character we are dealing with. The first case happens when a person writes something like "%0", and that case is not treated by ft_printf. 
Then we have the following paths:

|     Character    |       Meaning         |          Path            |
| ---------------- |:--------------------: | -----------------------: |
|       **c**      |      character        |     format_char.c        |
|       **s**      | string                |     format_string.c      |
|       **p**      | pointer               |     format_ptr.c         |
|       **d**      | decimal               |     format_int.c         |
|       **i**      | integer               |     format_int.c         |
|       **u**      | unsigned int          |     format_unsigned.c    |
|       **x**      | hexadecimal lowercase |     format_hexa_l.c      |
|       **X**      | hexadecimal uppercase |     format_hexa_u.c      |
|       **%**      | literal percentage    | prints the character '%' |

Each path has either ft_putchar_fd or ft_putstr_fd or ft_put_nbr_fd, using write. They return the length of whatever is printed, in order for the ft_printf to be able to return the total length of the printed string/number/etc.

## Makefile
(Not so much hidden secret: The Makefile for this project has a colored message!!!! :D)
The Makefile calls for the libft first, and creates the objects for ft_printf later on. 
Main rules goes as follows:

| Command       | Meaning                                                    |
| ------------- |:----------------------------------------------------------:| 
| make          | Makes the ft_printf.a project                              |
| make clean    | Erases the objects files.                                  |
| make re       | Calls "fclean" rule, followed by "all".                    |
