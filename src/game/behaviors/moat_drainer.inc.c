// moat_drainer.c.inc

void bhv_invisible_objects_under_bridge_init(void) {
    if (TRUE) { // save_file_get_flags() & SAVE_FLAG_MOAT_DRAINED (REMOVED FOR METROID PRIME 64)
        gEnvironmentRegions[6] = -800;
        gEnvironmentRegions[12] = -800;
    }
}
