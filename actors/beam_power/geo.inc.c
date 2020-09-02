#include "src/game/envfx_snow.h"

const GeoLayout power_shot[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(5, 0, 0, 0, beam_power_Plane_mesh),
		GEO_DISPLAY_LIST(0, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, beam_power_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, beam_power_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
