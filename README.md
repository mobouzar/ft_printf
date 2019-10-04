# ft_printf

### Objectifs

This project aims at rebuilding the printf library with basic functionality. I tried to implement as much of the original as possible, and also have a few extra things which I found to be rather useful.

### Fonctions autorisées

◦ write ◦ malloc ◦ free ◦ exit ◦ les fonctions du man 3 stdarg

# How to use it

### Download and compile the library

```
git clone https://github.com/mobouzar/ft_printf ft_printf
cd ft_printf
make
```

### Compile with your files

If you want to create a quick prog with the static library created before : Add the include in your header.h or in your file 

```c
#include "ft_printf.h"
```
### Then compile just like that

```
gcc yourfile1.c yourfile2.c libftprintf.a -o prog
```

### And execute it easily

```
./prog
```

# Contact or contribute

If you want to contact me, or fix / improve this project, just send me a mail at mobouzar@student.1337.ma
