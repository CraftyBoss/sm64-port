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

static struct ObjectHitbox sArmCannonShotHitbox = {
    /* interactType:      */ 0,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 50,
};

s16 canShoot;
s16 hasShot;

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
    o->oTimer = 0;
    canShoot = 0;
    hasShot = 0;
}

void bhv_arm_cannon_shot_init(void) {
    Vec3f objPos;
    f32 dist;
    s16 pitch;
    s16 yaw;

    object_pos_to_vec3f(objPos, o);
    obj_set_hitbox(o, &sArmCannonShotHitbox);

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

    if(obj_attack_collided_from_other_object(o)) {
        spawn_mist_particles();
        obj_mark_for_deletion(o);
    }
}

void bhv_arm_cannon_loop(void) {
    Vec3f objPos;
    Vec3f mPos;
    s16 animID = o->header.gfx.unk38.animID;

    object_pos_to_vec3f(objPos, o);
    vec3f_copy(mPos, gMarioState->pos);

    switch (o->oAction)
    {
    case 0:
        obj_set_pos_relative(o,gMarioObject,-20, 100, 40, 40);
        if(gMarioState->intendedMag > 0.0f) {
            if(animID == 0) {
                cur_obj_init_animation(1);
            }
        }else {
            if(o->header.gfx.unk38.animFrame >= 14) {
                cur_obj_init_animation(0);
            }
        }
        break;
    case 1:
        obj_mark_for_deletion(o);
        break;
    case 2:
        obj_set_pos_relative(o,gMarioObject,-20, 100, 40, 40);

        if(hasShot) {
            if(o->header.gfx.unk38.animID == 2 || o->header.gfx.unk38.animID == 4) {
                cur_obj_init_animation(0);
            }
            o->header.gfx.unk38.animFrame = 0;
            o->oArmCannonChargeTimer = 0;
            hasShot = 0;
        }

        if(gMarioState->controller->buttonDown & B_BUTTON) {
            o->oArmCannonChargeTimer++;
        }

        if(!(gMarioState->controller->buttonDown & B_BUTTON)) {
                o->oAction = 3;
        }else {
            if(o->oArmCannonChargeTimer >= 5) {
                o->oAction = 4;
            }
        }

        break;
    case 3:
        obj_set_pos_relative(o,gMarioObject,-20, 100, 40, 40);
        shoot_arm_cannon(gMarioState->beamSel);
        break;
    case 4:
        obj_set_pos_relative(o,gMarioObject,-20, 100, 40, 40);
        if(gMarioState->controller->buttonDown & B_BUTTON && !(hasShot)) {
            if(o->header.gfx.unk38.animID != 5) {
                cur_obj_init_animation(5);
            }
            o->oArmCannonChargeTimer++;
        }else {
            if(!(hasShot) && o->oArmCannonChargeTimer >= 8) {
                cur_obj_init_animation(4);
                spawn_object_relative_with_scale(0, 0, 0, 0, 5, o, MODEL_BEAM_POWER, bhvArmCannonShot);
                hasShot = 1;
            }else if(!(hasShot)) {
                cur_obj_init_animation(4);
                spawn_object_relative_with_scale(0, 0, 0, 0, 8, o, MODEL_BEAM_POWER, bhvArmCannonShot);
                hasShot = 1;
            }
            if(o->header.gfx.unk38.animFrame >= 9) {
                o->oAction = 0;
            }
        }
        break;
    default:
        break;
    }
    
}

void shoot_arm_cannon(s16 cannonType) {
        if(o->header.gfx.unk38.animID != 2) {
                cur_obj_init_animation(2);
        }
        if(o->header.gfx.unk38.animFrame == 3) {
            canShoot = 1;
        }else {
            canShoot = 0;
        }

        if(canShoot) {
            switch (cannonType)
            {
            case CANNON_BEAM_POWER:
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, 0, 0, o, MODEL_BEAM_POWER, bhvArmCannonShot);
                break;
            case CANNON_BEAM_ICE:
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, 0, 0, o, MODEL_BEAM_ICE, bhvArmCannonShot);
                break;
            case CANNON_BEAM_WAVE:
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, 0, 0, o, MODEL_BEAM_WAVE, bhvArmCannonShot);
                break;
            case CANNON_BEAM_FIRE:
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, 0, 0, o, MODEL_BEAM_FIRE, bhvArmCannonShot);
                break;
            default:
                break;
            }
            canShoot = 0;
            hasShot = 1;
        }

        if(o->header.gfx.unk38.animFrame >= 9) {
            o->oAction = 0;
        }
}