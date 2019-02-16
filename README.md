# Simple_DVD_Bouncing_Logo
"DVD Bouncing Logo" made in C just for fun

## Compiling and running
```shell
~# git clone https://github.com/d3suu/Simple_DVD_Bouncing_Logo.git
~# cd Simple_DVD_Bouncing_Logo
~# gcc logo.c -o logo
~# ./logo
```

## Modification
On line 8 and 9 you have size of borders for logo, change them as you want! `SPEED` variable on line 10 changes the speed of generating next frameBuffer becouse of terminal refresh speed. Values higher than 50 should be okay. Also higher values = slower refresh rate.
