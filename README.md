# Simple_DVD_Bouncing_Logo
"DVD Bouncing Logo" made in C just for fun

## Animation
![alt text](https://raw.githubusercontent.com/d3suu/Simple_DVD_Bouncing_Logo/master/bounce-animation.gif)

## Compiling and running
```shell
~# git clone https://github.com/d3suu/Simple_DVD_Bouncing_Logo.git
~# cd Simple_DVD_Bouncing_Logo
~# gcc logo.c -o logo
~# ./logo
```

## Modification
On these lines:
```C
#define Y_SIZE 20 // You can change these values as you want!
#define X_SIZE 50
#define SPEED 150
```
`Y_SIZE` and `X_SIZE` stands for borders dimensions, while `SPEED` changes the speed of generating next frameBuffer becouse of terminal refresh speed. For `SPEED` values higher than 50 should be okay. Also higher values = slower refresh rate.

On these lines:
```C
const char logoChar = '@';
const char borderChar = '#';
```
You can change how borders and logo looks like.
