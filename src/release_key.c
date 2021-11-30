#include "main.h"

int	release_key(int keycode, t_all *all)
{
	if (KEY_W == keycode)
		all -> key_flags &= ~W;
	if (KEY_S == keycode)
		all -> key_flags &= ~S;
	if (KEY_A == keycode)
		all -> key_flags &= ~A;
	if (KEY_D == keycode)
		all -> key_flags &= ~D;
	if (KEY_LEFT == keycode)
		all -> key_flags &= ~LEFT_ARROW;
	if (KEY_RIGHT == keycode)
		all -> key_flags &= ~RIGHT_ARROW;
	if (KEY_G == keycode)
		all -> key_flags &= ~G;
	if (KEY_SPACE == keycode)
		all -> key_flags &= ~SPACE;
	if (KEY_LCTRL == keycode)
		all -> key_flags &= ~CTRL;
	if (KEY_LSHIFT == keycode)
		all -> key_flags &= ~SHIFT;
	return (0);
}
