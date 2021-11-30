#ifndef FLAGS_H
# define FLAGS_H

# define BIT_0 1
# define BIT_1 2
# define BIT_2 4
# define BIT_3 8
# define BIT_4 16
# define BIT_5 32
# define BIT_6 64
# define BIT_7 128
# define BIT_8 256
# define BIT_9 512
# define BIT_10 1024
# define BIT_11 2048
# define BIT_12 4096
# define BIT_13 8192
# define BIT_14 16384
# define BIT_15 32768
# define BIT_32 4294967296

enum	e_key_flags
{
	W = BIT_0,
	S = BIT_1,
	A = BIT_2,
	D = BIT_3,
	LEFT_ARROW = BIT_4,
	RIGHT_ARROW = BIT_5,
	CTRL = BIT_6,
	SPACE = BIT_7,
	SHIFT = BIT_8,
	ESC = BIT_14,
	G = BIT_15
};

#endif