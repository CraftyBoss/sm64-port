#include "src/game/envfx_snow.h"

const GeoLayout e_tank_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE(1, 0, 0, 0, 90, 0, 90),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, e_tank_item_root_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, e_tank_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, e_tank_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
