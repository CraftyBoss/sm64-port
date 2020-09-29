// moat_grill.c.inc

void bhv_moat_grills_loop(void) {
    if (TRUE) // save_file_get_flags() & SAVE_FLAG_MOAT_DRAINED (REMOVED FOR METROID PRIME 64)
        cur_obj_set_model(MODEL_NONE);
    else
        load_object_collision_model();
}
