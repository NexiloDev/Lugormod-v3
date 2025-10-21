**Last Update:** 13 October 2025

**Note:** This documentation relates to the latest version of Lugormod v3. Some entities may differ or not exist in prior versions of Lugormod. (https://lugormod.com/downloads/).

### Key Chart:
```
* = Entity is triggerable.
** = Entity can be targeted to work. Or has to be.
*** = Is an entity that is placed that doesn't need to be targeted/triggered to work.
(L) = Either a new entity created for Lugormod, or if an existing entity then edited for Lugormod.
```

- So if an entity has **(L) by it that means that it was created for Lugormod, or was edited, and has to be targeted to work.

# Other Entities

## path_corner **
these are the waypoints for func_train

### Keys:

```
target      - next path corner and other targets to fire
speed       - speed to move to the next corner
              (default 100)
wait        - seconds to wait before behining move to next corner
targetname  - make the previus path_corner target this, if it is the first path_corner the func_train needs to target this
              If it is the first path corner, the last path_corner needs to also target this
```
### Example code:

```
/place path_corner 20 targetname,path_a,target,path_b,wait,5,speed,90,
```

- this is a the first path_corner, you can make as many as you want, i will make three of them, the first one should target the second one.

```
/place path_corner 20 targetname,path_b,target,path_c,wait,5,speed,90,
```

- this is the second path_corner, it should be the targetname of what the first one is targeting, also it should target the third path_corner

```
/place path_corner 20 targetname,path_c,target,path_a,wait,5,speed,90,
```

- this is the last path_corner that I am placing so it should target the first original path_corner, now to actually place the model see the func_train entity.

## emplaced_gun ***
Spawns a turret gun that can be used if your a non jedi profession

### Spawnflags:

```
1 - Can Respawn
```

### Keys:

```
customskill         - The name of the skill to check (see lmd_customskill for details)
customskillcompare  - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than
                      (default 0)
customskillvalue    - The value to compare to.
property    - this entity will only work for people with access to the property set here
playerflags - gives access to this entity for players who have this set ammount of flags, see lmd_flagplayer for more information
profession  - only a person with this set profession can use this
level       - only a person with this set level can use this
adminlevel  - only a person set with this admin level can use this
count       - if spawnflag 1 is set, decides how long it is before gun respawns (in ms)
constraint  - number of degrees gun is constrained from base angles on each side 
              (default 60.0)
showhealth  - set to 1 to show health bar on this entity when cross hair is over it
              (default 0)
```

### Example code:

```
/place emplaced_gun 0 spawnflags,1,count,10000,contraint,45,
```

## Item Entities **
(all of these entities have the same keys, listed below)

```
shield_sm_instant
item_shield_lrg_instant
item_medpak_instant
item_seeker
item_shield
item_medpac
item_medpac_big
item_binoculars
item_sentry_gun
item_jetpack
item_healthdisp
item_ammodisp
item_eweb_holdable
item_seeker
item_force_enlighten_light
item_force_enlighten_dark
item_force_boon
item_ysalimari
```

## Ammo Entities **
(all of these entities have the same keys, listed below)

```
ammo_thermal
ammo_tripmine
ammo_detpack
ammo_force
ammo_blaster
ammo_powercell
ammo_metallic_bolts
ammo_rockets
ammo_all
```

## Weapon Entities **
(all of these entities have the same keys, listed below)

```
weapon_stun_baton
weapon_melee
weapon_saber
weapon_blaster_pistol
weapon_concussion_rifle
weapon_bryar_pistol
weapon_blaster
weapon_disruptor
weapon_bowcaster
weapon_repeater
weapon_demp2
weapon_flechette
weapon_rocket_launcher
weapon_thermal
weapon_trip_mine
weapon_det_pack
weapon_emplaced
```

### Spawnflags:

```
1 - if you set this and lets say you put 20 on the z-axis the entity will be floating in the air and wont fall to the ground
```

### Keys:

```
wait        - the time to wait before respawning after picked up, if set to -1 it only appears when used.
target      - target to fire when picked up
targetname  - when wait is set to -1 this is what needs to be trigger for the entity to spawn
```

### Example code:

```
/place item_force_boon 0 wait,-1,targetname,spawn_boon,
```