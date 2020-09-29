// snowman.c.inc

static struct ObjectHitbox morphBallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 210,
    /* height:            */ 350,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_morph_ball_init(void) {
    struct Object *sp34;

    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;

    o->oGravity = 10.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;

    o->oVelY = 0;
    o->oForwardVel = 0;

}

void bhv_morph_ball_loop(void) {
    f32 spdDiv = 1.0f;
    o->oForwardVel = gMarioState->forwardVel;
    o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f / spdDiv));
    if(o->oFaceAnglePitch > 0x10000 || o->oFaceAnglePitch < -0x10000) {
        o->oFaceAnglePitch = 0;
    }

    cur_obj_set_pos_relative_to_parent(0,50,0);
}
