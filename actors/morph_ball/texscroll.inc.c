void scroll_morph_ball_Sphere_001_mesh_vtx_1() {
	int i = 0;
	int count = 28;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 15.0;
	float frequencyX = 0.10000000149011612;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 5.0;
	float frequencyY = 0.07000000029802322;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(morph_ball_Sphere_001_mesh_vtx_1);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;
	timeX += 1;
	currentY += deltaY;
	timeY += 1;

}
void scroll_actor_geo_morph_ball() {
	scroll_morph_ball_Sphere_001_mesh_vtx_1();

}
