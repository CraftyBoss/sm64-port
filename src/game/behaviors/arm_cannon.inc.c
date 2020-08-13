// arm_cannon.c.inc

static struct ObjectHitbox sArmCannonHitbox = {
    /* interactType:      */ 0,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 0,
    /* height:            */ 0,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

s32 arm_cannon_set_hitbox(void) {
    obj_set_hitbox(o, &sArmCannonHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        o->oInteractStatus = 0;
        return 1;
    }

    return 0;
}

void arm_cannon_despawn(void) {

}

void bhv_arm_cannon_init(void) {
    o->oMoveAnglePitch = -0x4000;
    o->oAction = 0;
    o->oGravity = 0.0f;
    o->oFriction = 0.0f;
    o->oBuoyancy = 0.0f;
    o->oOpacity = 0xFF;
}

void bhv_arm_cannon_shot_init(void) {
    Vec3f objPos;
    f32 dist;
    s16 pitch;
    s16 yaw;

    object_pos_to_vec3f(objPos, o);

    vec3f_get_dist_and_angle(objPos,gMarioState->area->camera->focus,&dist,&pitch,&yaw);
    o->oMoveAngleYaw = yaw;
    o->oMoveAnglePitch = pitch;
    o->oAction = 0;
    o->oGravity = 0.0f;
    o->oFriction = 0.0f;
    o->oBuoyancy = 0.0f;
    o->oOpacity = 0xFF;
    o->oTimer = 0;
}

void bhv_arm_cannon_shot_loop(void) {
    s16 collisionFlags;
    o->oForwardVel = 100.0f;
    o->oVelY = o->oForwardVel * sins(o->oMoveAnglePitch);
    cur_obj_update_floor_and_walls();
    collisionFlags = object_step_without_floor_orient();

    if(collisionFlags & 2 || collisionFlags & 1 || (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_HIT_WALL)) || o->oTimer >= 120) {
        spawn_mist_particles();
        obj_mark_for_deletion(o);
    }else {
        o->oTimer++;
    }
}

void bhv_arm_cannon_loop(void) {
    Vec3f objPos;
    Vec3f mPos;

    object_pos_to_vec3f(objPos, o);
    vec3f_copy(mPos, gMarioState->pos);

    switch (o->oAction)
    {
    case 0:
        // obj_copy_pos(o, gMarioObject);
        obj_set_pos_relative(o,gMarioObject,-20, 100, 40, 40);
        if(o->header.gfx.unk38.animFrame == 1) {
            cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
            spawn_object_relative(0, 0, 0, 0, o, MODEL_BOWLING_BALL, bhvArmCannonShot);
        }
        break;
    case 1:
        obj_mark_for_deletion(o);
        break;
    case 2:
        obj_set_pos_relative(o,gMarioObject,-20, 100, 40, 40);
        
        
        if(o->header.gfx.unk38.animFrame >= 9) {
            o->header.gfx.unk38.animFrame = 0;
            o->oAction = 0;
        }
        break;
    
    default:
        break;
    }
    
}
