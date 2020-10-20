static const u16 e_tank_anim_anim_none_values[] = {
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 
};

static const u16 e_tank_anim_anim_none_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 
};

static const struct Animation e_tank_anim_anim_none[] = {
	0,
	0,
	0,
	1,
	60,
	ANIMINDEX_NUMPARTS(e_tank_anim_anim_none_indices),
	e_tank_anim_anim_none_values,
	e_tank_anim_anim_none_indices,
	0,
};

