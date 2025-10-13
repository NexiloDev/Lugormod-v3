### Key Chart:
```
* = Entity is triggerable.
** = Entity can be targeted to work. Or has to be.
*** = Is an entity that is placed that doesn't need to be targeted/triggered to work.
(L) = Either a new entity created for Lugormod, or if an existing entity then edited for Lugormod.
```

- So if an entity has **(L) by it that means that it was created for Lugormod, or was edited, and has to be targeted to work.

# misc_ Entities

## misc_exploding_crate *
Spawns a crate that when hit by an attack will explode. You can change its default model by the model key, although its hitbox is hard coded.

### Keys

```
dmg           - sets the damage that the entity will give
model         - the md3 model to draw
splashRadius  - sets the damage radius around the origin of the entity
splashDamage  - sets the splash damage (if you are inside the splash radius you will receive this damage amount)
```

### Example code:

```
/place misc_exploding_crate 0
```

- will spawn an exploding crate that loads every time the entities are loaded for that map. After being destroyed, it doesn't respawn.

## misc_model_breakable *(L)

This will spawn a model in game that can either have no purpose and sit there, or it can fire a target, or it can even accept money to fire at its target.

### Spawnflags:

```
1     - Makes the model solid. If maxs/mins are defined it will follow those.
        Otherwise it will follow default maxs/mins, which go to the full extent size of the model
2     - Will cycle its animation
4     - Bounding Box will be there even when destroyed
8     - Doesn't display damage model when destroyed
16    - No smoke when used
32    - When used, will toggle to it's usemodel (model + "_u1.md3")... this does nothing if spawnflags 64 is not checked.
64    - When used it will not break
128   - Player can use it will use button
256   - No Explosion
512   - Starts deactivated
8192  - Payable button, use count and message keys
```

### Keys:

```
customSkill        - The name of the skill to check. (see lmd_customskill for details).  
customSkillCompare - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                     (default 0)  
customSkillValue   - The value to compare to.  
property    - this entity will only work for people with access to the property set here  
playerFlags - gives access to this entity for players who have this set ammount of flags, see lmd_flagplayer for more information  
useScript   - the script to use  
parm1       - the movement distance for a movable model to move to, if spawnflags 2 is set it loops its movement.  
              If not it only moves when something targets the entities targetname this only works if you have the usescript key set to something like:         
              "usescript,common/switch_on".  
parm2       - the delay to wait in milliseconds before moving again when the movement reaches its closed position or opened position  
profession  - Sets it so only a person with a certain profession can use a button.   
              Note that you can add these together: profession,3, = jedi and merc but tech can't access this button.
              -1     - no profession  
               1     - Jedi Profession  
               2     - Mercenary Profession  
               4     - Tech Profession  
  
level       - People with this level and above can use this, must be set to 1-40. So if you set it to 5, people level 5 and up can use it while people   
              below level 5 cannot use it. However now if you set it to -5 people level's 5 and below will only be able to use this.  
adminLevel  - People with this admin level and above can use this, must be set for 1-4, So if you set it to 2, admins level 2 and up can use it,   
              while people with level 3 and below cannot.  
count       - Only works when spawnflags are set to 8192, the amount of credits the person must pay for the entity to fire its target.  
message     - The message that people will see when they press 'use' on the button.  
gravity     - Add this key with the number one after it and make the z-axis to something above the ground and the model will be pushable and pullable.  
target      - What to fire at when used  
model       - the md3 model to draw  
modelScale  - how much to scale the model, 1-10 for larger model, 0-1 for smaller, ex .5 for half the size.  
targetName  - make the trigger target this value for the entity to be used  
```

### Example code:

```
/place misc_model_breakable 0 model,models/map_objects/factory/f_con1,spawnflags,8193,message,Pay Up Yo,count,20,target,spawn_desann,
```

- This will make a button that charges 20 Credits to fire its target

```
/place misc_model_breakable 0 model,models/map_objects/roof_top/mech1,angle,90,usescript,common/switch_on,spawnflags,65,parm1,7,parm2,2000,
```

- This will spawn a movable model that moves up and down with a 2 second delay between movements.

## misc_bsp ***

This entity lets lets you load a map inside a map. Once you place it you will have to 'saveit' and then do /newmap <the map your on> for it to be visible. You have to do this because brushmodels only load when the map is loaded. If you mess up, the only way to delete it, is to go into the .lmd file on your server and remove it manually. If you're experiencing issues with this entity, ensure you're not running QMM or JASS on top of Lugormod, as it seems they interpret the entitylist of misc_bsp models differently.

### Keys:
```
bspmodel - the map .bsp you want to place
```

### Example code:

```
/place misc_bsp 0 bspmodel,t1_inter,
```

- will spawn a map, t1_inter in this case at the area you are looking at

## misc_ammo_floor_unit *
Gives generic ammo when used Can be Granted a targetname to be used by another entity

### Keys:

```
count       - max charge value.
              (default 200)
chargerate  - recharge 1 point every this many milliseconds.
              (default 2000)
nodrain     - don't drain power from station if 1.
model       - the md3 model to draw, must include the extension ".md3" at the end of the model value for this to work. 
targetname  - make the trigger target this value for the entity to be used.
```

### Example code:

```
/place misc_ammo_floor_unit 0 nodrain,1,
```

- Will spawn a ammo_floor_unit, that doesn't drain

## misc_shield_floor_unit *
Gives generic shield when used can also be granted a targetname

### Keys:
```
count       - max charge value 
              (default 50)
chargerate  - recharge 1 point every this many milliseconds 
              (default 3000)
nodrain     - don't drain power from me
model       - the md3 model to draw, must include the extension ".md3" at the end of the model value for this to work
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place misc_shield_floor_unit 0 nodrain,1,
```

- Will spawn a misc_shield_floor_unit that doesn't drain

## misc_model_health_power_converter *
Gives health when used. Also can be targeted when given a targetname.

### Keys:

```
health      - the amount of health given when used 
              (default 60)
model       - the md3 model to draw, must include the extension ".md3" at the end of the model value for this to work. 
              The hitbox will not change, it is hard coded into the entity code.
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place misc_model_health_power_converter 0
```

- Will spawn a misc_health_power_converter

## misc_weapon_shooter **
fires weapon projectiles when used.

### Spawnflags:

```
1 - fire the alt-fire of the chosen weapon
2 - keep firing until used again (fires at intervals of "wait")
```

### Keys:

```
wait        - debounce time between refires.
              (defaults to 500)
target      - what to aim at (will update aim every frame if it's a moving target. 
              So, if you target it at a door, it will always shoot the door, even if the door moves)
weapon      - specify the weapon to use. Some of these are unstable, or will shut down the server when used, careful with them.
              (default is WP_BLASTER)
targetname  - make the trigger target this value for the entity to be used.
```

#### Possible weapon key->pair:

```
WP_BRYAR_PISTOL
WP_BLASTER
WP_DISRUPTOR
WP_BOWCASTER
WP_REPEATER
WP_DEMP2
WP_FLECHETTE
WP_ROCKET_LAUNCHER
WP_THERMAL
WP_TRIP_MINE
WP_DET_PACK
WP_STUN_BATON
WP_EMPLACED_GUN
WP_BOT_LASER
WP_TURRET
WP_ATST_MAIN
WP_ATST_SIDE
WP_TIE_FIGHTER
WP_RAPID_FIRE_CONC
WP_BLASTER_PISTOL
```

### Example code:

```
/place misc_weapon_shooter * weapon,WP_TURRET,target,*66,spawnflags,2,
```

- Will spawn a misc_weapon_shooter at target \*66, it will keep firing until used again, and used WP_TURRET weapon.

## misc_camera **
A working camera that is similar to the single player camera system. the player is noclipped and teleported and frozen at the camera location, and a fake model is left behind where he was. Any damage given to the fake model is passed onto the player. The entity spawns a camera model by default at the origin/angle of the entity. You can turn off the model by setting model,null,

### Keys:

```
wait        - time between the user being able to fire its targets by attacking. 
              (defaults to 1 second)
target2     - when the user attacks.
target3     - fire when the user alt-attacks.
model       - The model to draw instead of the default camera model.
targetname  - make the trigger target this value for the entity to be used.
```

### Example code:
```
/place misc_camera 500 targetname,cammy,
```

## misc_portal_surface ***
The portal surface nearest this entity will show a view from the targeted misc_portal_camera, or a mirror view if not targeting anything.
This must be within 64 world units of the surface!

### Example code:
```
/place misc_portal_surface 0 target,cam_portal,
```

## misc_portal_camera **
The target for a misc_portal_surface. You can set either angles or target another entity to determine the direction of view, like info_notnull or target_position.

### Spawnflags:

```
1 - slowly rotates
2 - rotates fast
4 - doesn't rotate
```

### Keys:

```
roll - an angle modifier to orient the camera around the target vector
```

### Example code:

```
/place misc_portal_camera 0 target,cam_pos,targetname,cam_portal,spawnflags,4,roll,270,
```

## misc_turretG2 **(L)
Spawns a turret that will fire at a person. This entity is finicky, some spawnflags don't always work together.

### Spawnflags:

```
1     - Turret will start off and toggle turning on and off when used, requires the entity to have a targetname
2     - Turret will be upside-down (with foot part on floor)
4     - will respawn after being killed (use count)
8     - Big-ass, Boxy Death Star Turbo Laser version (yes this is a direct quote from ravensofts notes)
16    - Turret will aim in front of the enemy, or lead the entity, increases chance to hit
32    - Turret will appear on radar
64    - Target Fighters (I Believe This Means Air Vehicles)
128   - Target Ground Vehicles
256   - Target Players Who Are Armed
512   - If set, turret will only attack players who fit the profession/level/maxlevel keys (By default people on property list are not attacked)
```

### Keys:

```
property      - The turret will ignore players who fit the keys
level         - The turret will ignore players who fit the keys
authlevel     - The turret will ignore players who fit the keys
maxlevel      - The turret will ignore players who fit the keys
profession    - The turret will ignore players who fit the keys
radius        - Maximum distance of targeting enemies 
                (default 512)
wait          - Time to wait between firing
                (default 150 ms)
dmg           - Damage per shot
                (default 5)
health        - Hit points of the turret
                (default 100)
count         - Time to wait before respawning
paintarget    - In the words of Lugor: target to fire off upon being hurt
painwait      - In the words of Lugor: ms to wait between firing off pain targets
random        - Random value (in degrees) of aiming off target when firing at targets
                (default 2)
shotspeed     - Speed of the projectile the Turret fired
                (default is for 1100 regular Turrets, or 20000 for Turbo-Laser Turrets)
splashDamage  - How much the damage the explosion does
splashRadius  - How far the explosion will reach
targetname    - Name to be used if using a switch to activate or deactivate
target        - Target to activate upon being destroyed (E.g. Opening a door when turret is destroyed)
target2       - Target to activate upon firing at targets
showhealth    - Will show health when person aims at the turret, if this has the value "1"
customscale   - Custom scaling, 1024 is maximum, watch out with this
                (default 100)
```

### Example code:

```
/place misc_turretG2 0 spawnflags,265,health,2000000,
```

## misc_faller **
Raining Stormtroopers?? spawned every interval+random fudgefactor, or if specified, when used. This takes up a lot of temp ents if you let them rain freely.

### Keys:

```
targetname  - if specified, will only spawn when used
interval    - spawn every so often (milliseconds)
fudgefactor - milliseconds between 0 and this number randomly added to interval
```

### Example code:

```
/place misc_faller 200 interval,1000,fudgefactor,200,
```

- Spawns a misc_faller 200 points in the air, at a 1 second interval with .2 random seconds added

## misc_slotmachine *(L)
An in game slot machine, 1 entity thats all it takes. Accepts /pay command with numbers from 10 - 200 all numbers have to be by 10, ex /pay 50.

### Keys

```
count - the starting credit the machine comes with, once the total credit hits 0 the machine will say its out of credits when used.
```

### Example code:

```
/place misc_slotmachine 0 count,5000,
```

## misc_skyportal ***
Will take a snapshot of wherever you place one of these and put it in the sky. The snapshot is a whole 360 around the origin of this entity, place on on the map and look at the sky. You Will Need To Use The misc_skyportal_orient entity to change an angle

*Note: Also note that entities in the same PVS and visible (via point trace) from this object will be flagged as portal entities. This means they will be sent and updated from the server for every client every update regardless of where they are, and they will essentially be added to the scene twice if the client is in the same PVS as them (only once otherwise, but still once no matter where the client is). In other words, don't go overboard with it or everything will explode.

### Keys:

```
fov - for the skybox. 
      (default is 80)
```

### Example code:

```
/place misc_skyportal 0
```

## misc_skyportal_orient ***
point from which to orient the sky portal cam in relation to the regular view position.

### Keys:

```
modelscale - the scale at which to scale positions
```