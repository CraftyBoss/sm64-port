// e_tank.inc.c

static struct ObjectHitbox sCollectETankHitbox = {
    /* interactType:      */ INTERACT_ENERGYTANK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_e_tank_init(void) {
    s8 tankId;
    u32 energyTankFlags;

    tankId = (o->oBehParams >> 24) & 0xFF;
    energyTankFlags = save_file_get_etank_flags();
    if (energyTankFlags & (1 << tankId)) {
        mark_obj_for_deletion(o);
    }

    obj_set_hitbox(o, &sCollectETankHitbox);
}

void bhv_e_tank_loop(void) {

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        mark_obj_for_deletion(o);
        o->oInteractStatus = 0;
    }
}