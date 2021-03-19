# simple-xxd
A really simple utility that outputs in xxd format.  It's simple enough you can
just copy paste in the function when you're debugging code & it only depends on
`stddef.h` (size_t) and `stdio.h` (putchar)

This library is dual licensed so you can pick if you want/need Apache 2.0 or LGPLv2.

# Building

```
gcc xxd.c example.c
```
