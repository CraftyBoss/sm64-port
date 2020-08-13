static const u16 arm_cannon_anim_arm_cannonShot_values[] = {
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, 0x000B, 0x000A, 
	0x0009, 0x0006, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 
};

static const u16 arm_cannon_anim_arm_cannonShot_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x000B, 0x0002, 0x0001, 0x000D, 0x0001, 
	0x000E, 0x0001, 0x000F, 
};

static const struct Animation arm_cannon_anim_arm_cannonShot[] = {
	1,
	0,
	0,
	1,
	10,
	ANIMINDEX_NUMPARTS(arm_cannon_anim_arm_cannonShot_indices),
	arm_cannon_anim_arm_cannonShot_values,
	arm_cannon_anim_arm_cannonShot_indices,
	0,
};

