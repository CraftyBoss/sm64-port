#include "src/game/envfx_snow.h"

const GeoLayout cannon_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, arm_cannon_root_mesh),
		GEO_DISPLAY_LIST(0, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, arm_cannon_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, arm_cannon_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
