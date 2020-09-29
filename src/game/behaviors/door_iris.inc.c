// door_iris.c.inc

void bhv_door_iris_loop(void) {
    if(o->oBehParams & 0x1) {
        o->oAction = 1;
    }
    switch (o->oAction)
    {
    case 0:
        load_object_collision_model();
        if(o->oInteractStatus & ATTACK_PUNCH) {
            o->oAction = 1;
            o->oInteractStatus = 0;
            cur_obj_init_animation(1); // start door opening
        }else {
            o->oAction = 0;
        }
        break;
    case 1: // door opening
        if(cur_obj_check_if_at_animation_end()) {
            o->oTimer = 0;
            if(o->oDistanceToMario < 1000.0f) { // check if player is 500 units away
                o->oAction = 2;
            }
        }
        break;
    case 2: // check if door has been open for 2 seconds
        if(o->oTimer >= 60) {
            cur_obj_init_animation(2); // begin closing anim
            o->oAction = 3;
        }
        break;
    case 3: // door closing
        if(cur_obj_check_if_at_animation_end()) { // if door at end anim, go back to action 0 and load idle anim
            o->oAction = 0;
            cur_obj_init_animation(0);
        }
        break;
    default:
        break;
    }
}

void bhv_door_iris_init(void) {
    o->oTimer = 0;
    o->oAction = 0;
    // this section finds what rooms are adjacent to the room the door is currently in
    f32 x = o->oPosX;
    f32 z = o->oPosZ;
    struct Surface *floor;
    find_floor(x, o->oPosY, z, &floor); // finds room door is in
    if (floor != NULL) {
        o->oDoorUnkF8 = floor->room;
    }

    x = o->oPosX + sins(o->oMoveAngleYaw) * 200.0f; 
    z = o->oPosZ + coss(o->oMoveAngleYaw) * 200.0f;
    find_floor(x, o->oPosY, z, &floor); // finds forward adjacent room
    if (floor != NULL) {
        o->oDoorUnkFC = floor->room;
    }

    x = o->oPosX + sins(o->oMoveAngleYaw) * -200.0f; 
    z = o->oPosZ + coss(o->oMoveAngleYaw) * -200.0f;
    find_floor(x, o->oPosY, z, &floor); // finds backward adjacent room
    if (floor != NULL) {
        o->oDoorUnk100 = floor->room;
    }

    if (o->oDoorUnkF8 > 0 && o->oDoorUnkF8 < 60) { // if room door is currently in is room 1-60, set global adj room array values
        gDoorAdjacentRooms[o->oDoorUnkF8][0] = o->oDoorUnkFC;
        gDoorAdjacentRooms[o->oDoorUnkF8][1] = o->oDoorUnk100;
    }
}
