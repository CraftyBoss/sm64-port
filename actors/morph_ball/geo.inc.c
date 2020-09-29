#include "src/game/envfx_snow.h"

const GeoLayout morph_ball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(99, 255, 100),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE_WITH_DL(1, 0, 0, 0, 0, 0, 0, morph_ball_Sphere_001_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, morph_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, morph_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
