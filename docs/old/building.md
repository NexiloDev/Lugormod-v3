# Lugormod U# (U-Sharp) Entity Guide

The following are entities that can be placed and saved in the game. These are not all the entities, I've removed some of the entities that are for a team gametype and some of the entities that are pointless. 

Credit goes to Phred for making the first original entitylist, without that none of this is possible. And of course to Ravensoft, whenever they didn't do anything idiotic. I will try as best as i can to give a better definition for each entity, as well as give an example on how its placed. 

For a reference to these entities and how to use them please refer to the Lugormod Building Guide, located here.

Please Note: I am still adding things as i go, I removed entities that I know are currently unstable, or don't work properly they will be readded when they get fixed.

I have gone through and organized the entities by group. (info_, misc_, trigger_, target_, fx_, lmd_, func_, misc..) Some of the entities may belong in more than one group so i am going to make a key chart. That will put a symbol by each entities name so you know what kind of entity it is. Some entities may very if they have targetnames set, I am setting their keys by if the entity is placed without a targetname.

## Key Chart:
```
* = Entity is triggerable.
** = Entity can be targeted to work. Or has to be.
*** = Is an entity that is placed that doesn't need to be targeted/triggered to work.
(L) = Entity was created or edited by either lugor/phred
```

- So if an entity has **(L) by it that means that it was created by either lugor or phred, and has to be targeted to work.

# info_ Entities

## info_player_deathmatch ***
Basic player spawnpoint, Now if your remove all the current spawnpoints and place one of these and then save, this will be the new spawnpoint. 

- Do Not use info_player_start, it is out of date. You can place as many as you want, as long as the game sees this you will be ok.

### Keys:

```
noBots    - bots cannot be spawned using this spawnpoint when set to 1.
noHumans  - humans cannot be spawned using this spawnpoint when set to 1.
target    - what to fire at when used, in this case when a person dies and this spawnpoint is used, it fires at this.
```

### Example code:

```
/place info_player_deathmatch 12 nohumans,1,
```

- i added 12 to the z-axis because without the entity spawning 12 units up, you would literally spawn inside the ground.

## info_player_jail ***

Lugormod jail spawnpoint.  
Use /jail <playername> <time> on a player and it will send them to this point, also place as many of these as you want  

### Example code:

```
/place info_player_jail 12
```

- i added 12 to the z-axis because without the entity spawning 12 units up, you would literally spawn inside the ground.

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

# trigger_ Entities

## trigger_push *
Must point at a target_position, which will be the apex of the leap. This will be client side predicted, unlike target_push.

### Spawnflags:

```
1     - Only a player can trigger this
2     - Every 1 second, it will check to see if it can trace to the target_position, if it can, the trigger is touchable.
        If it can't, the trigger is not touchable.
4     - Instead of tossing the client at the target_position, it will push them towards it. Must set a "speed"
8     - Only a NPC can trigger this
16    - instead of pushing you in a direction that is always from the center of the trigger to the target_position, it pushes *you* toward 
        the target position, relative to your current location. 
         (can use with "speed"... if don't set a speed, it will use the distance from you to the target_position)
32    - acts like a conveyor belt, will only push if player is on the ground (should probably use RELATIVE also, if you want a true conveyor belt)
128   - not active until targeted by a target_activate
256   - multiple entities can touch this trigger in a single frame *and* if needed, the trigger can have a wait of > 0
```

### Keys:

```
wait  - how long to wait between pushes (-1 = push only once)
speed - when used with the spawnflag 4, pushes the client toward the position at a constant speed 
        (default is 1000)
```

## trigger_lightningstrike * 
A trigger that will generate random lightning strikes inside it. Lighting can do damage, if used it will target on/off

*Note: (Two-Part entity, to get hurt it has to be triggered, to start or turn off it has to be targeted)

### Spawnflags:

```
1 - Start off, must be used to turn on
```

### Keys:

```
lightningfx - effect to use for lightning, MUST be specified
wait        - Seconds between strikes
              (default 1000)
random      - wait variance
              (default 2000)
dmg         - damage on strike 
              (default 50)
radius      - if non-0, does a radius damage at the lightning strike impact point (using this value as the radius). 
              otherwise will only do line trace damage
              (default 0)
targetname  - make the trigger target this value for the entity to be used, this entity is togglable so using this targetname makes it turn off and on.
```

### Example code:

```
/place trigger_lightningstrike 0 mins,-200 -400 0,maxs,200 400 800,spawnflags,1,wait,300,dmg,99,targetname,lightning,
```

- this is an area that the lightning will strike, I set the bounding box with maxs/mins, the spawnflags 1 is there because i want it to be able to be turned off and on by a button. I set the wait to 300 because I wanted to strike faster than what the default was, and i set the damage to 99 because I'm evil and I want it so when your hit, it will suck really bad.

## trigger_multiple *
Backbone of the game, this should be a highly placed entity. Often paired with maxs/mins to affect an area.

### Spawnflags:

```
1     - only a player can trigger this by touch, makes it so a NPC cannot fire a trigger_multiple
2     - Won't fire unless triggering ent's view angles are within 45 degrees of trigger's angles (in addition to any other conditions)
        If you want the player to only be able to fire the entity at a 90 degree angle you would do ",angles,0 90 0," into your spawnstring.
4     - Won't fire unless player is in it and pressing use button (in addition to any other conditions)
        (you must make a bounding box with max\mins for this to work)
8     - Won't fire unless player/NPC is in it and pressing fire button, you must make a bounding box,(max\mins) for this to work.
16    - only non-player NPCs can trigger this by touch
128   - Start off, has to be activated by a target_activate to be touchable/usable
1024  - multiple players can trigger the entity at the same time
```

### Keys:

```
customskill         - The name of the skill to check. (see lmd_customskill for details)
customskillcompare  - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                      (default 0)
customskillvalue    - The value to compare to.

property      - this entity will only work for people with access to the property set here
message       - the message to display when used
playerflags   - gives access to this entity for players who have this set ammount of flags, see lmd_flagplayer for more information
wait          - Seconds between triggerings, number < 0 means one time only.
                (default 0)
level         - Person must be a certain level to use this
adminlevel    - Person must be a certain adminlevel to use this
random        - wait variance
                (default 0)
delay         - how many seconds to wait to fire targets after tripped
target        - what to fire at, if there is a bounding box it will fire this when the player enters the box
target2       - the second target to fire at, fires after the first target 
                if the entity has a bounding box it will fire this when the thing that triggered it leaves the bounding box
speed         - How many seconds to wait to fire the target2, set it to -1 for it to fire both targets at once
                (default 1)
usetime       - If specified (in milliseconds) along with spawnflags 4, will require a client to hold the use key for x amount of ms before firing. 
                Also known as the hack you use on stash depo's. 
                (default 10000)
model         - the model for the size of the bounding box
targetname    - make the trigger target this value for the entity to be used
```

### Example code:
Because this is one of the most important entities i will list 3 examples

```
/place trigger_multiple 0 mins,-100 -5 0,maxs,100 5 200,spawnflags,2,angles,0 90 0,target,house_message,target2,house_lights,wait,3,speed,-1,
```

- This is an example you can use if, lets say your entering a house and you want a message to fly up on the screen, and you want the lights to turn on. Well if you set this in the doors entrance way, when you enter the house facing a 90 degree angle, the trigger_multiple will fire at both of its targets, i added wait 3 because i don't want the trigger_multiple to fire more than once when someone enters, i added speed -1 so both of the targets will fire at the same time.

```
/place trigger_multiple 0 mins,-100 -5 0,maxs,100 5 200,target,kill_npc,spawnflags,16,
```

- This would be an example if you had a room that had NPCs in it and you didn't want people to be able to get the NPCs out of the room, so when the NPC leaves the room it will fire at a target_kill and kill the NPC, the spawnflags 16 makes it so the trigger_multiple can only be fired by NPCs.

```
/place trigger_multiple 0 mins,-15 -15 0,maxs,15 15 45,spawnflags,4,usetime,10000,target,free_cash,
```

- This is an example of making a button that gives away free credits, but they have to hack at the button so i have it spawnflags 4 because you need to press use to hack at the button, and when you add the usetime key thats what actually makes it a hack, without the usetime key you would just be able to press use anywhere within the bounding box, and it will fire at its targets.

## trigger_once *
a trigger multiple, but it automatically sets the wait key to -1, meaning once its used it can never be used again that game

### Spawnflags:

```
1     - only a player can trigger this by touch, makes it so a NPC cannot fire a trigger_multiple
2     - Won't fire unless triggering ent's view angles are within 45 degrees of trigger's angles (in addition to any other conditions)
        if you want the player to only be able to fire the entity at a 90 degree angle you would do ",angles,0 90 0," into your spawnstring.
4     - Won't fire unless player is in it and pressing use button (in addition to any other conditions) 
        you must make a bounding box,(max\mins) for this to work
8     - Won't fire unless player/NPC is in it and pressing fire button, you must make a bounding box (max\mins) for this to work.
16    - only non-player NPCs can trigger this by touch
128   - Start off, has to be activated by a target_activate to be touchable/usable
256   - THIS IS INCORRECT! Multiple Entities Can Touch This
```

### Keys:

```
customskill         - The name of the skill to check (see lmd_customskill for details)
customskillcompare  - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                      (default 0)
customskillvalue    - The value to compare to.

property      - this entity will only work for people with access to the property set here
message       - Message to display when used.
playerflags   - gives access to this entity for players who have this set ammount of flags (see lmd_flagplayer for more information)
level         - Person must be a certain level to use this
adminlevel    - Person must be a certain adminlevel to use this
random        - wait variance 
                (default is 0)
delay         - how many seconds to wait to fire targets after tripped
target        - what to fire at, if there is a bounding box it will fire this when the player enters the box
usetime       - If specified (in milliseconds) along with spawnflags 4, will require a client to hold the use key for x amount of ms before firing
                Also known as the hack you use on stash depo's. 
                (default 10000)
model         - the model for the size of the bounding box
targetname    - make the trigger target this value for the entity to be used
```

### Example code:

```
/place trigger_once 0 mins,-50 -50 0,maxs,50 50 50,target,t232,
```

- This is an example of lets say a func_breakable(or a model that breaks when you hit it), if you use the targetname of the func_breakable it will break by itself without you having to apply damage. So if i want a func_breakable to get rid of itself when i enter a certain area, i would make a trigger_once that targets the func_breakable, who's targetname happens to be "t232", you could also use the entity trigger_always to do this.

## trigger_teleport *
First step of making a teleport. The bounding box area of a teleport, should target a target_teleporter. You don't need to use this entity, you can also use trigger_multiple. This works better if you wish to have a NPC_vehicle go through a teleport.

### Spawnflags:

```
1 - only spectators can teleport using this
2 - don't teleport players if they are in a duel
```

### Keys:

```
target - must be a target_teleporter entity
```

### Example code:

```
/place trigger_teleporter 0 mins,-15 -15 0,maxs,15 15 50,target,enter_bar,
```

- this is the area that i want to step in to be teleported, it should target a target_teleporter entity.

## trigger_hurt *
Any player that touches this will be hurt.
Targeting the trigger will toggle its on / off state.

### Spawnflags:

```
1   - The entity will start in its off state
2   - Can Be Targeted
4   - Suppresses playing the sound
8   - Nothing Can Stop Damage
16  - Changes the damage rate to once per second
```

### Keys:

```
dmg         - The damage to hurt the player per second. Set to -1, it will make the player have a fall effect as if they are falling down a hill.
              (default 5)
model       - the model for the size of the bounding box, same thing as using a bounding box, but use an existing bmodel
targetname  - make the trigger target this value for the entity to be used, when used it will turn off and on
```

### Example code:

```
/place trigger_hurt 0 mins,-500 -500 0,maxs,500 500 200,dmg,-1,targetname,hole_die,
```

- lets say i had a hole in the ground, and i wanted it so when you fall down the hole, you would fall to your death, so i set the dmg key to -1

## trigger_space *
Removes gravity from players and makes them suffocate. Does not affect vehicles that have the player inside them. This must have a bounding box (max/mins) to work.

### Keys:

```
model - the model for the size of the bounding box, same thing as useing a bounding box, but use an existing bmodel
```

### Example code:

```
/place trigger_space 0 mins,-20 -20 0,maxs,20 20 50,targetname,space,
```

- Enter the bounding box and you will die from lack of oxygen, the player will play the choking animation.

## trigger_shipboundary *
Causes vehicle to turn towards a target and travel in that direction for a set time when hit. Needs to have a bounding box(maxs/mins) to work. Best if you make it target an target_position.

### Keys:

```
target      - name of entity to turn toward
traveltime  - time to travel in this direction
model       - the model for the size of the bounding box, same thing as using a bounding box, but use an existing bmodel
```

### Example code:

```
/place trigger_shipboundary 0 mins,-2000 -2000 0,maxs,2000 2000 3000,target,ship_turnaround,traveltime,10,
```

- here is a good example of when you don't want a ship to hit a wall, so you place this before the wall and it forces the ship to turn around and face what you are targeting, you can use an target_position as a target, make that 180 degrees behind facing the wall.

## trigger_hyperspace *
Ship will turn to face the angles of the first target, which should be target_position Then fly forward, playing the hyperspace effect, then pop out at a relative point around the target2 which should also be a target_position.

### Keys:

```
target    - supposed to face the origin of where this entity is located, use target_position
target2   - supposed to head towards the origin of where this entity is placed, used target_position
model     - the model for the size of the bounding box, same thing as using a bounding box, but use an existing bmodel
```

### Example code:

```
/place trigger_hyperspace 0 mins,-500 -1 0,maxs,500 1 0,target,pos_angle,target2,pos_end,
```

# target_ Entities

## target_level_change **
changes the map to whatever you specify when this entity gets used.  This is dangerous in older lugormod versions or if not used with OpenJK. Escape sequences and the ';' can be used in the mapname key maliciously. Use with care and/or remove.

### Keys:

```
mapname - map to change to when used
```

### Example code:

```
/place target_level_change * targetname,changemap,mapname,t2_trip
```

## target_position **
Only exists for the sole purpose of having stuff aim at it, like misc_weapon_shooters, effects, tele's, trigger_push, misc_portal_camera ect.

### Keys:

```
targetname - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_position 60 targetname,blaster_fire_spot,
```

- this is an example of having a misc_weapon_shooter fire at a spot of my choosing, 60 units up from that spot.

## target_push **
Gets used by something targeting this, it will push the activator in the direction of its target, which should be a target_position or something.

### Spawnflags:

```
1 - play bounce noise
2 - will push activator in direction of 'target' at constant 'speed', speed does need to be set for this to work
```

### Keys:

```
speed - speed to push activator 
        (default 1000)
```

## target_powerup **
Sets a powerup to the player.

### Keys:

```
powerup     - use this key to set one of the powerups (listed below)
targetname  - make the trigger target this value for the entity to be used
wait        - duration
```

### Powerups:

```
0   - nothing
1   - multiply the damage by the value in the cvar g_quadfactor
2   - protection from lava/acid, and protects from all radius damage (but takes knockback). also absorbs 50% of all damage
3   - force pull effect
4   - red team flag
5   - blue team flag
6   - not used, lugor uses this for the glow-around-the-player stash effect
7   - singleplayer shield damage effect. Lugormod T2 used this for the bodyshield uitem
8   - for the dodge effect (sniper fire while you're using force sense on a higher level)
9   - despite its name, this is a force push effect (like PW_PULL, except the other way around)
10  - force speed effect
11  - cloaking effect (this does NOT make npcs ignore you by itself, notarget is set by the game code when you use the cloaking item)
12  - force enlightenment
13  - force dark enlightenment
14  - Force Boon
15  - The ysalarimi
```

### Example code:

```
/place target_powerup * targetname,Coffee,powerup,11,
```

- this is an example of what you could use to make a button that would give the player a ysalarimi blast everytime he pressed the button.

## target_remove_powerups **
Remove all powerups from the person who uses this. In U# It will not longer remove the stash glow effect when a player uses this.

### Keys:

```
targetname - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_remove_powerups * targetname,remove_powerup
```

- this will remove all the powerups that you have gained when used

## target_teleporter **
This teleports the player when used. Does not need a trigger_teleport, the same thing as misc_teleporter_dest, which isnt listed. Use angle or angles keys to change the direction that you teleport in.

### Spawnflags:

```
1 - Do not teleport player if they are in a duel.
```

### Keys:

```
targetname - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_teleporter 12 targetname,enter_bar,angle,90,
```

- this is the area that you come out of the tele at, i added 12 to the z-axis because without it you would spawn in the ground.

## target_delay **
This is a great entity for making an entity not fire its target right away, instead it waits the amount of time you set with the "wait" key to fire its target.

### Spawnflags:

```
1 - Keeps the delay from resetting the time if it is activated again while it is counting down to an event.
```

### Keys:

```
wait        - Seconds to pause before firing targets
random      - delay variance, total delay = delay +/- random seconds.
targetname  - make the trigger target this value for the entity to be used
target      - what to fire at when the delay time is hit
```

### Example code:

```
/place target_delay * wait,3,target,ship_spawn,targetname,ship_delay,
```

- This would be for if i pressed a button and i wanna give the player enough time to get to the general area of where the x-wing spawned, so i gave it a three second delay, that way there is a smaller chance of someone stealing that players ship that they paid for.

## target_speaker **
This entity will play a sound that you specify in a certain radius.

### Spawnflags:

```
1 - Makes the sound start On, loops the sound when complete
2 - Makes the sound start Off
4 - Everybody on the entire map can hear the sound
8 - Only the activator can hear the sound
```

### Keys:

```
noise       - wav file to play
wait        - Seconds between auto triggerings, 0 = don't auto trigger
random      - Wait variance, default is 0
targetname  - make the trigger target this value for the entity to be used
```

### Example code:
```
/place target_speaker 50 spawnflags,1,noise,sound/ambience/narshaddaa/cantina_1.mp3,
```

- here is a speaker for some cantina music you may hear at a bar, it will load automatically with spawnflags 1, i added 50 to the z-axis so its louder, also if its not loud enough you can try placing more of them

## target_print **
This will print a message across the screen. Basically the same as the announce command. If no spawnflag is set, it will make the print global.

### Spawnflags:

```
1   - Red Team Only
2   - Blue Team Only
4   - Only the person who activated the entity can see the message.
8   - Message will appear at top left corner of the screen
16  - Message will appear in area where chat normally appears
```

### Keys:

```
message     - text to print
wait        - don't fire off again if triggered within this many milliseconds ago
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_print * spawnflags,4,targetname,bar_text,message,^4No Laming\n ^0In the bar!,
```

- this is the entity that does basically what "/announce" does, it prints a message that you tell it to across the screen, spawnflags 4 makes it so only the activator can see the message, without it everyone can see it. Notice in the message i used "\n" this is the key you can enter anytime during a message to tell it to enter down.

## target_score **
Adds points to the players score once fired.

### Spawnflags:

```
1 - Sets your score to this count when used instead of adding to your score
```

### Keys:

```
count       - number of points to add to the activator
              (default 1)
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_score * targetname,negative_points,count,-5,
```

- when someone uses this with a button it will give them -5 points

## target_kill **
This when targeted will kill the person/npc who fires it.

### Keys:

```
targetname - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_kill * targetname,kill
```

- Kinda self-explanatory, but when something targets this it will kill its activator.

## target_counter **(L)
You have to use this entity a specified amount of times for it to fire at its target, the default is 2 times ravensoft made it so it will deactivate after it gets hit a certain amount of times, but if you set a bouncecount at -1 the entity will keep on being able to be used.

### Spawnflags:

```
1 - Start Inactive, must be hit by a target_activate to be able to be used.
```

### Keys:

```
target        - what to first fire at when the entity as been hit a certain amount of times.
target2       - fires this every time you target the entity and it isnt at its count
count         - the amount of times to be hit for firing its target
                (default 2)
bounceCount   - set this at -1 so the entity will never stop working, otherwise after the first use it will stop working 
                if you set bouncecount to 5 then after the fifth use it will stop working.
targetname    - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_counter * targetname,double_NPC_counter,target,dead_NPCS,count,2,bounceCount,-1,
```

- I've used this for quests that i wanted to fight 2 NPC's at once, each NPC_target will be double_NPC_counter, and once the counter gets used twice, or the two npcs die, it will fire its target. The bouncecount is huge because i want it to last for a long time, without stop working.

## target_random **
Randomly fires off only one of it's targets each time used, does the exact same thing as the target_relay with the random spawnflag it doesn't have a target2, target3, target4, target5, target6 function just set one target and multiple entities with that targetname. It will only fire one of them.

### Spawnflags:

```
1 - only be usable once, then disable itself
```

### Keys:

```
targetname  - make the trigger target this value for the entity to be used
target      - should target more than one entity, it will only fire at one of its targets.
```

### Example code:
Ok lets say i wanted to press a button and get a random amount of credits back..

The random selector:

```
/place target_random * targetname,random_reward,target,random_credits,
```

My array of credits:

```
/place target_credits * targetname,random_credits,count,2,
/place target_credits * targetname,random_credits,count,-2,
/place target_credits * targetname,random_credits,count,1,
/place target_credits * targetname,random_credits,count,5,
```
- all the targetnames for the credits should be the same, and the target_random will fire off only one of its targets, so you may get 2 once, and the next time you can get -2 credits.

## target_relay **(L)
Does nothing but fire at its targets, can fire at up to 6 targets it will fire them all at the same time.

### Spawnflags:

```
4     - makes the target get fired off randomly, currently this only works for target1.
128   - makes the entity start deactivated
```

### Keys:

```
targetname  - make the trigger target this value for the entity to be used
target      - the first target to fire
target2     - the second target to fire
target3     - the third target to fire
target4     - the fourth target to fire
target5     - the fifth target to fire
target6     - the sixth target to fire
```

### Example code:

```
/place target_relay * targetname,blah,target,light1,target2,light2,
```

- This will switch light entities on or off, if one of them is set to be deactivated first.

## target_scriptrunner **
Starts a script once used.

### Spawnflags:

```
1     - Will run the script on the entity that used this or tripped the trigger that used this
128   - Will start in the off state.
```

### Keys:

```
useScript   - Script to run when used
count       - how many times to run, -1 = infinite. 
              (default 1)
wait        - can't be used again in this amount of seconds 
              (default 1 second, if it's multiple-use)
delay       - how long to wait after use to run script
```

### Example code:

```
/place target_scriptrunner * targetname,run_script,Usescript,close_door_cinematic,count,1,
```

- this is a scriptrunner that i very very rarely use, it is meant to run scripts that are already in the game, i made it target a script that would close a door, i set count to one, because it should only fire once.

## target_activate **(L)
Will set the target(s) to be usable/triggerable It accepts its target(1-6) The activate must first be fired for it to activate its target.

### Keys:

```
targetname  - make the trigger target this value for the entity to be used
target      - the entity(s) to activate when targeted
target2     - the entity(s) to activate when targeted
target3     - the entity(s) to activate when targeted
target4     - the entity(s) to activate when targeted
target5     - the entity(s) to activate when targeted
target6     - the entity(s) to activate when targeted
```

### Example code:

```
/place target_activate * target,the_door,targetname,initial_entity,
```

- this entity will activate its targets, i want it to activate the door at the start of the map

## target_deactivate **(L)
Will set the target(s) to not be usable/triggerable. It accepts its target(1-6). The activate must first be fired for it to deactivate its target.

### Keys:

```
targetname  - make the trigger target this value for the entity to be used
target      - the entity(s) to deactivate when targeted
target2     - the entity(s) to deactivate when targeted
target3     - the entity(s) to deactivate when targeted
target4     - the entity(s) to deactivate when targeted
target5     - the entity(s) to deactivate when targeted
target6     - the entity(s) to deactivate when targeted
```

### Example code:

```
/place target_deactivate * targetname,tele_area_deact,target,tele_area,
```

- this would deactivate whatever its targeting, in this case i made it so it would deactivate a teleport area once it has been used

## target_play_music **
Plays the requested music files when this target is used. You must set the music key when placing this otherwise it will crash the server.

### Keys:

```
music       - directory of to use music WAV or MP3 file
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_play_music * targetname,initial_entity,music,music/mp/duel.mp3,
```

- Will change the music of the map to duel music once the map starts...

## target_screenshake **
anyone near this entity has their screen shake around, in Lugormod T2 it is bugged and always does global

### Keys:

```
intensity     - intensity of the shake
duration      - how long the shake lasts
globalshake   - if set to anything > 0, then everyone in the server will have this effect them.
                (default 0)
targetname    - make the trigger target this value for the entity to be used
```

### Example code:

```
/place target_screenshake * intensity 2000,duration,100,globalshake,1,targetname,shakey,
```

## target_laser **
Makes an invisible line between this entity and its target that damages you. Kinda pointless i know. It starts in the off state so you have to use its targetname for it to turn on

### Keys:

```
targetname  - make the trigger target this value for the entity to be used, and turn on
target      - make this target a target_position or something, you don't need to do this you can just set angles.
```

### Example code:

```
/place target_laser 20 target,laser_pos1,targetname,the_laser,
```

## target_credits **(L)
gives the person who fires this an amount of credits

### Keys:

```
count       - the amount of credits to give the activator
random      - the amount of credits you want to randomly receive this number is added onto the count
              If your count is 20 and you set this to 10 you will receive anywhere from 20-30 credits
targetname  - make the trigger target this value for the entity to be used, the person who triggers this will receive the set amount of credits
```

### Example code:

```
/place target_credits * targetname,credits,count,5,random,20
```

- Now you will receive credits from 5-25 anywhere between there

# Miscellaneous Entities

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

# Lugormod Entities

## lmd_chance * (L)
When used, gets a random number between 1 and "count", and will go from "chance" to "chance6" checking if its number is less than or equal to it.
Will fire the first target found then stop.

### Keys:

```
chance    - Number to compare
chance2   - Number to compare
chance3   - Number to compare
chance4   - Number to compare
chance5   - Number to compare
chance6   - Number to compare
count     - The maxmum random number to generate
target    - Corresponding target to fire.
target2   - Corresponding target to fire.
target3   - Corresponding target to fire.
target4   - Corresponding target to fire.
target5   - Corresponding target to fire.
target6   - Corresponding target to fire.
```

### Example Code:

```
/place lmd_chance * count,7,chance,1,chance2,2,chance3,3,chance4,4,target,hit_1,target2,hit_2,target3,hit_3,target4_hit4,
```

- This randomly genrates a number from 1-7 and fire the target if the number is the same. If it goes over 4, it doesn't fire anything. 4/7 of the time it will do nothing.

## lmd_restrict *(L)
Restricts the person inside of it by whatever spawnflags are set. Use maxs/mins to set the bounding box.

### Spawnflags:

```
1     - Damage restrict, the people inside cannot be inflicted with damage
2     - Restrict forcepowers
        (includes non-offensive force heal/protect etc...)
4     - No jetpack
8     - No duels, existing duels break if a player enters this.
16    - No firing weapons
128   - Start inactive, must be hit by a target_activate entity to become active.
```

### Keys:

```
maxs/mins
```

### Example code:

```
/place lmd_restrict 0 mins,-500 -500 0,maxs,500 500 500,spawnflags,3,
```

- Restricts damage and forcepowers in the defined area.

## lmd_stashzone ***(L)
A zone to define an area for stashes. Also controls how many stashes can be spawned per zone. A stash may be set to delete itself when removed from its zone.

### Spawnflags:

```
1 - start inactive (stashes with no active zone can be taken anywhere).
2 - master zone. Any stash spawns that are outside a zone by their zone key will be affected by the count key of a master zone. 
    Having multiple zones under a single key with this spawnflag is stupid.
```

### Keys:

```
targetname  - name of this zone.
count       - number of stashes that can be spawned at once within this zone. This overrides any settings of individual stash spawns. 
              This is per zone-entity.
              if a stash is brought into another zone of the same name but out of this one it will no longer count for this zone.
```

### Example code:

```
/place lmd_stashzone 0 mins,-1200 -1200 -1200,maxs,1200 1200 1200,spawnflags,2,targetname,main_stashzone,count,1,
```

## lmd_stashspawnpoint ***(L)
Point where stashes spawn. Can be triggered to manually spawn a stash. Multiple stashes can be spawned at once. It is possible to make a stash with 0 credits for the purpose of making it use a target when deposited (see the deposittarget key). A new stash will not spawn if the last one has not been picked up. stash spawn points that have been deactivated will not spawn stashes, although they will still run their spawn timers (they will just not spawn the stash when the timer fires). Important: if you want to use the traditional method of one stash spawning randomly, make sure all stash spawns have a random key, else only one point will spawn stashes. Or just set the spawn time to 0 and use a target_random targeting all the spawn points.

### Spawnflags:

```
1       - spawnmessage global: send the spawnmessage to everyone in the server (rather than in the stash zone), if the spawnmessage key is set.
2       - spawnmessage screen print: send the spawnmessage as a screen print, as well as in the console.
4       - pickupmessage global: send the pickup message to everyone in the server (rather than in the stash zone), if the pickupmessage key is set.
8       - pickupmessage screen print: send the pickupmessage as a screen print, as well as in the console.
16      - dropmessage global.
32      - dropmessage screen print.
64      - startdepomessage global.
128     - startdepomessage screen print.
256     - depositmessage global.
512     - depositmessage screen print.
1024    - resetmessage global.
2048    - resetmessage screen print.
4096    - display stash amount: include the credits amount on all stash messages.
8192    - stashes can spawn here even if a stash has been spawned by another spawn within the zone.
16384   - start disabled. Needs to be used by a target_activate to start spawning.
32768   - reset credits shift when dropped.
65536   - Stashes in this zone will respawn at this spawn. If no spawns have this set, stashes will not reset and just delete themselves.
131072  - Delete the stash if it leaves the zone. See zoneexittime and zoneexitmessage keys.
```

### Keys:

```
customskill         - The name of the skill to check (see lmd_customskill for details)
customskillcompare  - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                      (default 0)
customskillvalue    - The value to compare to.
zone            - the lmd_stashzone to connect this stash to. Zones control how many stashes can be spawned at once. 
                  Also, this is the area to not let the stash be removed from, if specified.
zoneexittime    - If enabled by spawnflag, how many seconds to wait before deleting the stash after it leaves the zone. 
                  (default 4)
zoneexitmessage - If a player has a stash and exits the zone, this message will be displayed along with a countdown timer. 
                  (default "You have left the stash zone.")
profession      - profession bitmask of who can use this.
minlevel        - min level needed to pick this up.
maxlevel        - any players above this level cannot pick this up.
property        - this entity will only work for people with access to the property set here
playerflags     - only players with a flag(s) specified here can pick this up.
minstashes      - players cannot pick this stash up until they have picked up this many stashes (from other spawns).
maxstashes      - players cannot pick this stash up if they have picked up more than this amount of stashes.
name            - the name to use for this stash, defaults to "money stash"
count           - number of stashes that this spawn can have spawned at once. 
                  If this is set to 0, the stash can be picked up by unregistered players and will not count as a stash deposit 
                  (will not count for the minstashes/maxstashes counter)
                  (default 1)
basedeposittime   - time in msecs needed to deposit (lmd_stashdepo can modify this)
basedepositrandom - random amount to add to the base deposit time on pickup. Amount added is random between 0 and this number.
credits           - base credit amount
creditsrandom     - random amount to add for core credits value.
sound             - sound to make on pickup.
creditshift       - credit amount to shift per second. Can be positive (increase worth longer its picked up) 
                    or negative (decrease worth longer its picked up). If the stash amount reaches 0, the stash is reset.
creditshiftrandom - random amount to add to offset each credit shift by.
creditshifttime   - how many seconds to run the shift for.
creditshiftdelay  - how long to wait before starting the shift.
spawntime         - time between spawns. Set to 0 to only spawn on use. Defaults to the contents of the cvar lmd_stashrate
spawnrandom       - random amount between 0 and this to offset the spawn time by.
stashtime         - after this many seconds after being picked up, make the stash disappear.
stashtimerandom   - A number between 0 and this will be added to the stash time.
spawnmessage      - message to send on spawn
pickupmessage     - message to send to players in the zone when picked up (can be sent to all players by spawnflag)
dropmessage       - message to send to players in the zone when dropped (can be sent to all players by spawnflag)
startdepomessage  - message to send to players in the zone when starting deposit (can be sent to all players by spawnflag)
depositmessage    - message to send to players in the zone when deposited (can be sent to all players by spawnflag)
resetmessage      - message to send when the stash is deleted due to leaving the zone or timing out.
color             - color glow to emit when not picked up. 
                    Recommend making all stashes in a zone use the same color.
light             - light intensity to emit when not picked up
pickupcolor       - color glow to emit when picked up. Recommend making all stashes in a zone use the same color.
pickuplight       - light intensity to emit when picked up.
model             - model to use. 
                    Recommend making all stashes in a zone use the same model. 
spawntarget       - target to use on spawn
pickuptarget      - target to use on pickup
droptarget        - target to use on drop
startdepotarget   - target to use on deposit start
deposittarget     - target to use on deposit.
```

### Example code:

```
/place lmd_stashspawnpoint 4 spawnflags,169301,zone,main_stashzone,zoneexitmessage,You're leaving the stashzone.,credits,80,creditsrandom,50,creditshift,-1,creditshiftdelay,60,
```

- As the size of this spawnstring is too large to fit into console, you may have to manually /spawnstring edit the keys in or you will have to place it using a script.

## lmd_stashdepo ***(L)
"Bank" You can set deposittime to 0 and have a trigger use this, if you don't want to require the player to use the entity directly.

### Spawnflags:

```
1   - no deposit time. Useful if you want to make another non-player entity trigger this
2   - don't display stash status. If set, the terminal will not tell the user if a stash is out when it is used.
4   - don't show up in /stash command.
128 - start deactivated. Must be used by a target_activate to be usable.
```

### Keys:

```
zone                  - only deposit stashes belonging to this zone.
stashname             - name to refer to the stashes with. Only used for displaying the count of stashes 
                        (not used if spawnflag 2 is set).
stashnameplural       - same as stashname, but if there are more than 1 stashes
message               - message to print when used without a stash.
profession            - profession bitmask of who can use this.
minlevel              - min level needed to pick this up.
maxlevel              - any players above this level cannot pick this up.
minstashes            - players cannot pick this stash up until they have picked up this many stashes (from other spawns).
maxstashes            - players cannot pick this stash up if they have picked up more than this amount of stashes.
depotimeoffset        - offset to change the stash base deposit time by. Can be negative. Stash deposit time will not go below 0.
depotimeoffsetrandom  - random shift to change the deposit time by.
bonuscredits          - get extra credits for depositing here. Can be negitive to remove credits from the stash. 
                        Will not remove more credits than the stash has.
bonusrandom           - random amount to add to bonus credits.
startdepomessage      - message to add to the bottom of the startdepomessage of the stash.
depositmessage        - message to add to the bottom of the depositmessage of the stash.
startdepotarget       - target to use on deposit start
deposittarget         - target to use on deposit.
model                 - md3 model to draw, uses max/mins too.
```

### Example code:

```
/place lmd_stashdepo 0 zone,master_stashzone,model,models/map_objects/imperial/control_station,model,models\map_objects\imperial\control_panel.md3,
```

## money_dispenser *(L)
Spawns a money depo where you can depo stashs at.

### Example code:

```
/place money_dispenser 0 angle,90,
```

## random_spot ***(L)
when placed, it spawns a spawn point for a stash, one random_spot is used randomly each time a money stash is spawned.

### Example code:

```
/place random_spot 0
```

## lmd_scale **(L)
Scales a player when they trigger this to the set count

### Keys:

```
scale       - The scale amount you want the player to be
time        - The time it takes for the players scale to be set back to 100.
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place lmd_scale * targetname,scaler,scale,50,time,20,
```

## lmd_playercheck ** (L)
Entity will fire target if the activator meets the usability keys

### Keys:

```
level
adminlevel
profession
customskill
customskillcompare
customskillvalue
playerflags
targetname

target    - fire if they meet requirements
target2   - fire if they do not meet requirements
```

### Example code:

```
/place lmd_playercheck * targetname,let_me_in,level,5,target,teleport_me_in,target2,deny_msg,
```

## LMD_spawner **(L)(If no targetname)
This entity was implemented by Lugor, it should be able to use any of the keys provided for npc_spawner and one more, it also allows the NPC to respawn after it has been destroyed.

### Keys:

```
customscale   - scale this npc/vehicle when it spawns.
count         - ammount of NPCs it is allowed to be on the map at once from this spawn
```

### Example code:

```
/place LMD_spawner 40 NPC_type,swoop,count,1,targetname,Sweet_Ride
```

## lmd_gravity **(L)
changes an individual players gravity

### Spawnflags:

```
1   - remove the changed gravity flag, so the player uses standard gravity again 
      (use instead of setting it to 800, as gravity will be changed by vehicles if this is the case)
2   - makes the gravity change global, so everyone has the change
```

### Keys:

```
count       - gravity to change to, note 800 is default for g_gravity
time        - the time it takes to reset gravity back to normal
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place lmd_gravity * targetname,fatty,count,2000,
```

## lmd_pwterminal *(L)
The player stands in front of it and types /interact <password> if the password is correct it fires its target, if not, then it fires target2

### Keys:

```
customskill         - The name of the skill to check (see lmd_customskill for details)
customskillcompare  - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than.
                      (default 0)
customskillvalue    - The value to compare to.
profession          - A bitmask of professions. Values: 1 - Jedi, 2 - Merc, 4 - Tech.
level               - Minimum player level.
maxlevel            - Maximum player level.
adminlevel          - Minimum admin level.
property            - this entity will only work for people with access to the property set here
playerflags         - A bitmask of flags set by the lmd_playerflag entity.
model               - The model. If the model is a glm model, you need to include the '.glm' extention. 
                      You do not need the 'map_objects/' folder in the path.
mins/maxs           - Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin. 
                      If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
message             - Text to show when used.
password            - The correct password.
target              - Target to fire when correct password is entered.
target2             - Target to fire when incorrect password is entered.
target4             - Target to fire when any password is given.
target5             - Target to fire when used.
```

### Example code:

```
/place lmd_pwterminal 0 model,models/map_objects/factory/f_con1,target,enter_bar,target2,kill,target3,banana,message,Enter Bar,
```

## lmd_toggle **(L)
Uses its targets in order until it hits its count, then resets.

### Keys:

```
target      - the first target to fire
target2     - the second target to fire
target3     - the third target to fire
target4     - the fourth target to fire
target5     - the fifth target to fire
target6     - the sixth target to fire
count       - the last target to use before resetting to its first target, should be set so if you have three targets the count would be three
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place lmd_toggle * target,red_light,target2,blue_light,target3,green_light,count,3,targetname,light_sequence,
```

## lmd_light **(L)
Spawns a light on the map, recommended you add a number greater than 0 to the z-axis to see the whole light

### Keys:

```
color       - the RGBcolors of the light in decimal percent (0 to 1, .5 would be 50%, EX: '0 .5 0' would be a faint green)
light       - the radius that the light can travel
offcolor    - same as color but when toggled off. 
              (default '0 0 0')
offlight    - radius when toggled off 
              (default 0)
targetname  - make the trigger target this value for the entity to be used
```

### Example code:

```
/place lmd_light 0 color,1 0 1,light,500,offcolor,0 1 0,offlight,500,targetname,light,
```

## lmd_door **(L)
Spawns a model that can be used as a door. If you don't set a targetname the door will have a trigger area and will fire to its open state when you get near it.

### Spawnflags:

```
1       - the door to moves to its destination when spawned, and operate in reverse. 
          It is used to temporarily or permanently close off an area when triggered (not useful for touch or take damage doors).
2       - Can be activated by force push/pull but also it can have a targetname
4       - kills the player if the player is stuck between it and a wall, and its moving (it won't reverse it movement when hits the player)
8       - wait in both the start and end states for a trigger event (stay opened until you use it again)
16      - Starts locked, with the shader animmap at the first frame and inactive. 
          Once used, the animmap changes to the second frame and the door operates normally. Note that you cannot use the door again after this.
64      - Player can use it with the use button (you can press it like a button)
128     - must be used by a target_activate before it can be used
```

### Keys:

```
model           - the md3 model to draw
target          - Door fires this when it starts moving from it's closed position to its open position.
opentarget      - Door fires this after reaching its "open" position
target2         - Door fires this when it starts moving from it's open position to its closed position.
closetarget     - Door fires this after reaching its "closed" position
targetname      - if set, no touch field will be spawned and a remote button or trigger field activates the door.
speed           - movement speed 
                  (default 100)
wait            - wait before returning (-1 = never return)
                  (default 3)
delay           - when used, how many seconds to wait before moving - default is none
dmg             - damage to inflict when blocked (set to negative for no damage)
                  (default 2)
health          - if set, the door must be shot open
linear          - set to 1 and it will move linearly rather than with acceleration 
                  (default 0)
team            - set it to the same name on two or more doors so they'll open if one of them is used, don't use too long names
vehopen         - if non-0, vehicles/players riding vehicles can open
movement        - x y z value, movement direction. movement,0 0 100, will make it move 100 units up.
```

### Example code:

```
/place lmd_door 0 model,map_objects/factory/catw2_b,speed,90,targetname,door_1,target,deact_button,closetarget,act_button,
```

- Spawns a lmd_door that moves at speed: 90, it allows vehicles to go threw it, it deacts a button once used, and then once its in its closed state it will activate the button.

## lmd_propertyterminal *(L)
What players can use to fire a target that only that set group of players can fire. The command, "/propadmin", will allow you to set who can use it.

### Spawnflags:

```
1 - If 'count' greater than zero, allow the renter to pay more money after the first payment to increase their time.
```

### Keys:

```
customskill             - The name of the skill to check. (see lmd_customskill for details)
customskillcompare      - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                          (default 0)
customskillvalue        - The value to compare to.
property                - The property to check to fire this entity.
profession              - A bitmask of professions. Values: 1 - Jedi, 2 - Merc, 4 - Tech.
level                   - Minimum player level.
maxlevel                - Maximum player level.
adminlevel              - Minimum admin level.
playerflags             - A bitmask of flags set by the lmd_playerflag entity.
model                   - The model. If the model is a glm model, you need to include the '.glm' extention. 
                          You do not need the 'map_objects/' folder in the path.
mins/maxs               - Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin. 
                          Normally, the Mins data is negitive. If no mins or maxs are specified, then a hitbox is automatically 
                          calculated to cover the entire model.
property                - The name of the property to check access to.
target                  - Target to fire if the user is a member of the property.
target2                 - Target to fire if the user is not a member of the property.
count                   - Number of credits per day this terminal costs to rent. 
                          If not set, then this terminal will not be rentable. Players can pay money to rent the terminal with '/pay <credits>'
mindays                 - If 'count', the minimum number of days this player can rent the property for.
maxdays                 - If 'count', the maximum number of days this player can rent the property for.
maxrenters              - If 'count', the maximum number of renters that this terminal will allow. Defaults to 1.
rank                    - If 'count', the property rank to give to new renters. Values are: 1 - owner, 2 - caretaker, 3 - guest
```

### Example code:

```
/place lmd_propertyterminal 0 model,models/map_objects/factory/f_con2,spawnflags,2,target,my_door,property,flips_door,
```

- This is what you would do for the first group of people you want, if you wanted to have another terminal for another group you would change the count, or property set:

```
/place lmd_propertyterminal 0 model,models/map_objects/factory/f_con2,spawnflags,2,target,his_door,property,somedudes_door,
```

## lmd_remap **(L)
This will change the shader on the map to another shader you specify. If no targetname is set, it will change shaders for you on map start

### Spawnflags

```
1 - Toggable, switches from new to old when targeted.
```

### Keys:

```
old - the shader directory of what you want to change.
new - the shader directory of what your changing the shader into.
targetname - the name of the entity, when someone fires at this it will change the shader you are referring to.
```

### Example code:

```
/place lmd_remap * old,textures/quicktrip/desert_0,new,textures/yavin/ground
```

## lmd_gate **(L)
If this is active, it uses its target when used. If it is inactive (set by a target_deactivate), then it fires its target2 when used.

### Spawnflags:

```
1 - Makes it start off
```

### Keys:

```
target - what to fire at when used, when the entity is active
target2 - what to fire at when used, when the entity is deactivated
targetname - make the trigger target this value for the entity to be used
```

### Example code:

```
/place lmd_gate * targetname,gate,target,act_spawn,target2,act_spawn2,spawnflags,1,
```

## lmd_drop **(L)
drops a model from the origin of this entity that can be picked up and fires a target
Create and launch a model that can be picked up by players.

### Spawnflags:

```
1: Player must use the item to pick it up rather than touching it.
```

### Keys:

```
customskill             - The name of the skill to check. (see lmd_customskill for details)
customskillcompare      - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                          (default 0)
customskillvalue        - The value to compare to.
profession              - A bitmask of professions. Values: 1 - Jedi, 2 - Merc, 4 - Tech.
level                   - Minimum player level.
maxlevel                - Maximum player level.
adminlevel              - Minimum admin level.
property                - this entity will only work for people with access to the property set here
playerflags             - A bitmask of flags set by the lmd_playerflag entity.
model                   - The model. If the model is a glm model, you need to include the '.glm' extention. 
                          You do not need the 'map_objects/' folder in the path.
mins/maxs               - Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin. 
                          Normally, the Mins data is negitive. If no mins or maxs are specified, then a hitbox is automatically 
                          calculated to cover the entire model.
target                  - Target to fire when picked up.
target2                 - Target to fire when time runs out.
noise                   - Sound to make when being picked up
count                   - Number of credits to give the player. 
                          If this is set and no noise key is specified, then the noise key defaults to sound/interface/secret_area.wav
velocity                - Speed at which to toss this item. Default 50.
angles                  - Angles to launch this item at
time                    - Number of seconds to stay for. Set this to -1 for no time limit. Default 30.
wait                    - Number of seconds to wait between triggerings.
```

### Example code:

```
/place lmd_drop 5 model,map_objects/desert/3po_head,count,50,targetname,drophead,velocity,0,wait,30
```

## lmd_terminal *(L)
When used it echoes different commands a player can use (/interact <1 to 6>)

### Spawnflags:

```
1: Send the output to the player's screen.
2: Do not send the output to the player's console.
```

### Keys:

```
customskill             - The name of the skill to check. (see lmd_customskill for details)
customskillcompare      - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                          (default 0)
customskillvalue        - The value to compare to.
profession              - A bitmask of professions. Values: 1 - Jedi, 2 - Merc, 4 - Tech.
level                   - Minimum player level.
maxlevel                - Maximum player level.
adminlevel              - Minimum admin level.
property                - this entity will only work for people with access to the property set here
playerflags             - A bitmask of flags set by the lmd_playerflag entity.
model                   - The model. If the model is a glm model, you need to include the '.glm' extention. 
                          You do not need the 'map_objects/' folder in the path.
mins/maxs               - Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin. 
                          Normally, the Mins data is negitive. If no mins or maxs are specified, then a hitbox is automatically 
                          calculated to cover the entire model.
message                 - Message to display when used.
usetarget               - Target to fire when the player presses the use key on this.
globaltarget            - Targe to fire when any command is used.
cmd-cmd6                - Name of each command.
target-target6          - Target to use for each command.
```

### Example code:

```
/place lmd_terminal 0 model,map_objects/factory/f_con1,spawnflags,2,message,I have some powerups,cmd,Bodyshield,cmd2,Speed,cmd3,Red Light,target,bodyshield_pu,target2,speed_pu,target3,rlight_pu,
```
- Spawns a terminal that displays the message "I have some powerups" at the top of the screen and has 3 options displayed. Corresponding targets fire.

## lmd_iobject **(L)
When used it grants the client an item specified here that can be used with the /inventory command.

### Keys:

```
name: The custom name you want this item to have.
noCombine: If this is set to 1, this item will not combine with others.
noDelete: If this is set to 1, the user will not be able to delete this item.
type: type of iobject to use
      The current iObject types are:

      ```
      medpack (combinable)
      weaponpack (not combinable)
      ammopack (combinable)
      upcount (combinable) Inverse keycard, for collection quests.
      downcount (combinable) Keycard 2.0
      ```

health: Amount of health to give when used.
shield: Amount of shield to give when used.
uses: Number of uses.

blaster: ammo count.
powercell: ammo count.
metalbolt: ammo count.
rocket: ammo count.
thermal: ammo count.
tripmine: ammo count.
detpack: ammo count.
```

### Weapons: bitmask of weapons

written as: weapon,<bitmask>,
        
```
2 WP_STUN_BATON
4 WP_MELEE
8 WP_SABER
16 WP_BRYAR_PISTOL
32 WP_BLASTER
64 WP_DISRUPTOR
128 WP_BOWCASTER
256 WP_REPEATER
512 WP_DEMP2
1024 WP_FLECHETTE
2048 WP_ROCKET_LAUNCHER
4096 WP_THERMAL
8192 WP_TRIP_MINE
13684 WP_DET_PACK
32768 WP_CONCUSSION
65536 WP_BRYAR_OLD
```
        
NOTE: this does NOT give ammo. The user must pick up ammo to use, or in some cases see, the weapon.

### iObject type keys

```
* upcount (combinable) Inverse keycard, for collection quests.
        property: Name of the property to grant access to when enough of these are picked up.
        max: Grant access to the property when "current" is greater than or equal to this.
        count: Current number of item type picked up. When another upcount item with the same name and property key is picked up, 
               this number is increased by the new item's current value. Defaults to 1.

* downcount (combinable) Keycard 2.0
        property: The property to grant access to while "current" is less than "count".
        max: Maximum number of times to allow access to the property.
        count: Current number of uses left.
        noAutoDelete: Set this to 1 to disable automatic deletion this item when it runs out of uses.

        While "keycard" still will spawn using a conversion placeholder for backwards compatibility, its item no longer officially exists. 
        Use "downcount" instead.
```

### Example code: 

```
<NEED EXAMPLE>
```

## lmd_customskill
An entity that, when used, creates a new custom skill for the person who targets it.

### Spawnflags:

```
1 - (Use with Value key) rather than adding value to player's current skill, entity will set player's value for this skill to the amount set in the value key.
```

### Keys:

```
skill   - Name of the skill (choose your own)
value   - Essentially the "level" of the skill
```

## lmd_mover **(L)
A moving model can be used to do movements for pendulum/rotating/bobbing/door for any of the ontype,onatype,offtype,offatype keys use the list of available movements and specify it to that number. Ex: ontype,0, for don't move at all. The entity is toggleable so if you use its targetname it will switch to its off state. by default its off state movement type is 0.

### Spawnflags:

```
1 - The set model will be solid
```

### Keys:

```
model           - the md3 model to draw
targetname      - make the trigger target this value for the entity to be used
```

Types - Use the movements list, an 'ontype/offtype' is for movement, while an 'onatype/offatype' is a rotation.

```
ontype          - Movement type when in the on state (See types of movement list)
offtype         - Movement type when in the off state (See types of movement list)
onatype         - Rotation type when in the on state (See types of movement list)
offatype        - Rotation type when in the off state (See types of movement list)
```

Durations - The time it takes for the model to complete its action in milliseconds. An 'onduration/offduration' is for the time it takes to complete a movement, while an 'onaduration/offaduration' is the time it takes to complete a rotation.

```
onduration      - The time it takes for the model to move to the set delta when in the on state (milliseconds)
offduration     - The time it takes for the model to move to the set delta when in the off state (milliseconds)
onaduration     - The time it takes for the model to rotate to the set delta when in the on state (milliseconds)
offaduration    - The time it takes for the model to rotate to the set delta when in the off state (milliseconds)
```

Deltas - How far something will move/rotate to. An 'ondelta/offdelta' is how far the model will move. An 'onadelta/offadelta' how far the model will rotate to.

```
ondelta         - How many units to move to when in the on state. (X Y Z)
offdelta        - How many units to move to when in the off state. (X Y Z)
onadelta        - How far the model will rotate to from the base of the model in the on state. (X Y Z)
offadelta       - How far the model will rotate to from the base off the model in the off state. (X Y Z)
```

### Types Of Movement

```
0       - Don't move at all.
1       - Teleport between starting and ending point.
2       - Move towards its goal, after its goal is reached it will keep moving forever. Use this movement type for models that rotate.
3       - Move towards its goal, and stop when the goal is reached.
4       - Move towards its goal, near the end it will start to decelerate then stop.
5       - Slowly accelerate towards middle of goal. Accelerating fastest at the middle of its goal then slowly start to decelerate 
          after it hit the middle of its goal towards the end. It will come back down to the starting point and keep moving like that forever. 
          Use this for bobbing and pendulums.
6       - This one is kind of pointless. It will ignore any set delta keys and fall to the ground at 800 units per second (Default Gravity Setting) 
          and ignores any objects in its way. So it will keep falling through the floor.
```

### Example code:

Because this is new and not a lot of people understand it I will explain how to do the same movements t2_pendulum, t2_bobbing, and t2_rotating used to do.

```
/place lmd_mover 0 model,models/map_objects/desert/3po_head,onaduration,1000,onadelta,0 180 0,onatype,2,
```

- Spawns a sphere that will rotate 180 degrees and keep rotating for ever it takes 1 second to complete its goal

```
/place lmd_mover 0 model,models/map_objects/factory/catw2_b,spawnflags,1,ontype,5,onduration,3000,ondelta,0 0 200
```

- Spawns a catwalk that will bob up and down 200 units. It takes 3 seconds to complete its goal

```
/place lmd_mover 0 model,models/map_objects/factory/catw2_b,onaduration,5000,onatype,5,onadelta,50 0 0,angles,90 0 0,spawnflags,1,
```

- Spawns a catwalk that will swing in a pendulum motion 50 units back and forth takes 5 seconds to complete the full movement

## lmd_rentterminal *(L)
Entity is used for a player to use the /pay command on the terminal and then he can have access to it as long as he wants or until it reaches the set max time.

### Spawnflags:

```
1 - Time will expire if player dies while owning the terminal
2 - Can pay for more time while you already own the terminal
4 - Tell the renter when they are at 30/15/5 seconds left.
```

### Keys:

```
customskill             - The name of the skill to check. (see lmd_customskill for details)
customskillcompare      - Comparison type. -1 for direct compare (use this for text), 0 for greater or equal to, 1 for less than. 
                          (default 0)
customskillvalue        - The value to compare to.
profession              - A bitmask of professions. Values: 1 - Jedi, 2 - Merc, 4 - Tech.
level                   - Minimum player level.
maxlevel                - Maximum player level.
adminlevel              - Minimum admin level.
property                - this entity will only work for people with access to the property set here
playerflags             - A bitmask of flags set by the lmd_playerflag entity.
model                   - The model. If the model is a glm model, you need to include the '.glm' extention. 
                          You do not need the 'map_objects/' folder in the path.
mins/maxs               - Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin. 
                          Normally, the Mins data is negitive. If no mins or maxs are specified, then a hitbox is automatically 
                          calculated to cover the entire model.
message                 - The message to be displayed when the terminal is used.
count                   - Cost.
minutes                 - Number of minutes to gain when payed 'count' number of credits.
wait                    - Minimum time to wait between payments, if spawnflag 2 is set.
maxtime                 - Maximum number of minutes a player can rent.
mintime                 - Minimum number of minutes a player can rent.
target                  - Target to fire when used by its current renter.
target2                 - Target to fire when the rent runs out.
target3                 - Target to fire when first rented.
target4                 - Target to fire when used by someone who is not the renter while being rented.
target5                 - Target to fire when used by anyone when not being rented.
```

### Example code:

```
/place lmd_rentterminal 0 model,models/map_objects/factory/f_con1,message,Rent House,minutes,60,count,50,target,tele_inhouse,target2,act_exit,target3,moremoney_msg,
```

## lmd_body **(L)
Leaves behind a fake player body like misc_camera does when you use it. Any damage given to the body while the entity is in use is forwarded to the client who used it. Unless the trigger that targets this, targets a delay which targets a target_teleporter .01 seconds later you will be stuck in your body. The next time this entity gets used the body gets removed.

### Keys:

```
targetname - make the trigger target this value for the entity to be used
```

### Example code:

```
/place lmd_body 0 targetname,body
```

## lmd_flagplayer **(L)
sets a flag to a player so you can give them temporary access to stuff, works kind of like a keycard. When you target this it grants you lets say flags 5, then you can have misc_model_breakable with the playerflags key set to 5 and only this person will have access to it.

### Keys:

```
flags - the amount of flags to set to the player, only players with this set flags can have access to entities with the playerflags key.
```

### Example code:

```
/place lmd_flagplayer 0 flags,5,targetname,give_accesstobar,
```

# NPC Entities

## NPC_spawner **(L)
Spawns a NPC that you specify, remember all keys are case sensative.(Its not npc_type, its NPC_type), if this is going to be used by a button add "count,-1," so it can spawn more than once.

### Spawnflags:

```
16      - NPC can be in air, but will spawn on the closest floor surface below it
32      - Will spawn with no default AI (BS_CINEMATIC), or the blinking that happens when it spawns
256     - Spawner is shy (wont spawn if a player is looking at it)
```

### Keys:

```
NPC_type        - name of NPC to spawn
targetname      - name this NPC goes by for targeting
count           - how many NPCs to spawn (only if targeted), set to -1 for it to be able to spawn after the first use
                  (default 1)
delay           - how long to wait to spawn after used
wait            - if trying to spawn and blocked, how many seconds to wait before trying again
NPC_target      - NPC's target to fire when killed
NPC_target2     - NPC's target to fire when knocked out
NPC_target4     - NPC's target to fire when killed by friendly fire
NPC_target5     - Fires this target for the player, so if the NPC_target5 is targeting credits, player will receive credits for killing the npc.
NPC_target6     - target to fire when npc kills a player
NPC_type        - type of NPC to be spawned
health          - starting health 
                  (default 100)
delay           - after spawned or triggered, how many seconds to wait to spawn the NPC
showhealth      - set to 1 to show health bar on this entity when crosshair is over it
noBasicSounds   - set to 1 to prevent loading and usage of basic sounds (pain, death, etc)
noCombatSounds  - set to 1 to prevent loading and usage of combat sounds 
                  (anger, victory, etc.)
noExtraSounds   - set to 1 to prevent loading and usage of "extra" sounds 
                  (chasing the enemy - detecting them, flanking them... also jedi combat sounds)
```


For and of the following keys use the script # that is listed after the script type.

### Script Type Keys:

```
spawnscript - default script to run once spawned (none by default)
usescript - default script to run when used (none by default)
awakescript - default script to run once awoken (none by default)
angerscript - default script to run once angered (none by default)
painscript - default script to run when hit (none by default)
fleescript - default script to run when hit and below 50% health (none by default)
deathscript - default script to run when killed (none by default)
```

### Script Type Spawnflags:

```
1: Stand around, do absolutely nothing
2: Roam around, collect stuff
3: Crouch-Walk toward their goals
4: Run toward their goals
5: Stay in one spot and shoot- duck when necessary
6: Wait around for an enemy
7: Follow a path, looking for enemies
8: Track down enemies and kill them
9: Run from enemies
10: Run from enemies, shoot them if they hit you
11: Run to your goal and shoot enemy when possible
12: Defend an entity or spot?
13: Stay hidden, shoot enemy only when have perfect shot and back turned
14: Attack, evade, use cover, move about, etc. Full combat AI - id NPC code
15: Go for lowest health buddy, hide and heal him.
16: Find nearest cover from enemies
17: Go get some ammo
18: Go somewhere and fight along the way
19: turn until facing desired angles
20: do nothing
21: Maintain a formation
22: Crouch-walk toward their goals
```

-To use a script you would enter the name of the script you want and then the # key of what you want it to actually fire when it hits that mark: ",spawnscript,14" should make the npc fight its enemies when spawned.

### Example code:

```
/place NPC_spawner 30 NPC_type,desann,count,-1,spawnscript,14,NPC_target,desann_dead,
```

## NPC_Vehicle **
Spawns a NPC Vehicle, please note the entity name is case sensitive.

### Spawnflags:

```
1   - die after certain amount of time of not having a pilot
2   - Fighters: Don't drop until someone gets in it 
      (this only works as long as no one has *ever* ridden the vehicle, to simulate ships that are suspended-docked)
      note: ships inside trigger_spaces do not drop when unoccupied
16  - spawn on the floor, instead of floating around in the air
32  - Will spawn with no default AI (BS_CINEMATIC), or won't blink when spawned
64  - Starts not solid
256 - Spawner is shy (wont spawn if a player is looking at it)
```

### Keys:

```
dropTime        - use with spawnflags 2, the vehicle will drop straight down for this number of seconds before flying forward
dmg             - use with spawnflags 1, delay in milliseconds for ship to explode if no pilot 
                  (default 10000)
speed           - use with spawnflags 1, distance for pilot to get away from ship after dismounting before it starts counting down the death timer
model2          - if the vehicle can have a droid, this NPC will be spawned and placed there
showhealth      - set to 1 to show health bar on this entity when crosshair is over it
targetname      - make the trigger target this value for the entity to be used
```

### Example code:
```
/place NPC_Vehicle 30 NPC_type,tie-fighter,count,-1,targetname,ship1a,spawnflags,3,dmg,1,dropTime,2
```

# fx_ Entities

## fx_rain ***
This is a world rain effect, meaning that it will play the effect everywhere on the map, or anywhere there is a weatherzone. Weatherzones have to be placed before the map compiles. This weather effect will move slowly if spawned and there is a misc_skyporal on the map. Please note that placing this effect will extremly increase the load time when you connect.

### Keys:

```
count - the number of rain particles 
        (default 500)
```

### Example code:

```
/place fx_rain 0 count,600,
```

## fx_snow ***
This is a world snow effect, meaning that it will play the effect everywhere on the map, or anywhere there is a weatherzone. Weatherzones have to be placed before the map compiles. This weather effect will move slowly if spawned and there is a misc_skyporal on the map. Please note that placing this effect will extremly increase the load time when you connect.

### Keys:

```
count - the number of snow particles 
        (default 1000)
```

### Example code:

```
/place fx_snow 0 count,1200,
```

## fx_spacedust ***
This is a world space dust effect, meaning that it will play the effect everywhere on the map, or anywhere there is a weatherzone. Weatherzones have to be placed before the map compiles. This weather effect will move slowly if spawned and there is a misc_skyporal on the map. Please note that placing this effect will extremly increase the load time when you connect.

### Keys:

```
count - the number of space dust particles 
        (default 1000)
```

### Example code:

```
/place fx_spacedust 0 count,1200,
```

## fx_runner **
Runs the specified effect, if it is used it will toggle, on/off.

### Spawnflags:

```
1 - effect will start in the off state
2 - effect fires once, and thats when its used
4 - does radius damage around effect, you set the damage variables with the 'splashRadius', 'splashDamage' keys
```

### Keys:

```
fxFile        - name of the effect file to play
target        - direction to aim the effect in 
                (default to up)
target2       - uses its target2 when the fx gets triggered
splashRadius  - the radius around the origin that the fx is located
                (default 16)
splashDamage  - the damage to give everything in the splash radius
                (default is 5)
soundset      - plays start sound when toggled on, loop sound while on, and a stop sound when turned off
targetname    - make the trigger target this value for the entity to be used
```

### Example code:

```
/place fx_runner 0 fxfile,effects/misc/possession,wait,2000,spawnflags,3,
```

- Creates an effect that only fires once when used, and starts off.

# func_ Entities (see following post for func entities)

## func_timer **
This is the only func_ entity that doesn't need a bmodel. Repeatedly fires its targets. Can be turned on or off by using its targetname.

### Spawnflags:

```
1 - Starts on
```

### Keys:

```
wait - base time between triggering all targets, default is 1
random - wait variance, default is 0 so, the basic time between firing is a random time between (wait - random) and (wait + random)
targetname - make the trigger target this value for the entity to be used
target - what the entity will fire at in increments of the wait time.
```

### Example code:

```
/place func_timer * target,light_switch,spawnflags,1,wait,3,random,1,
```

- ok this is an example of using the func_timer to target an entity almost every 3 seconds, i added 1 to the random so that the entity will be used every 2, 3, 4 seconds randomly.

## func_plat **
Uses a bmodel that will move up like an elevator, it cannot start up and move down however. It can only start down and move up.

### Spawnflags:

```
64 - Allows you to use the brush model as a button
128 - Starts deactivated, you need to hit it with a target_activate to use it again.
```

### Keys:

```
lip - How high to rest above from a brush default 8
height - How far to move up. The default is the height of the bmodel
speed - How fast to move, default 200
dmg - How much damage to cause to a player if they block the path of the entity when its moving
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_plat * targetname,plat,lip,1,model,*5,height,200,speed,20
```

## func_button **
Spawns a button type object that when used moves in a direction, fires all of its targets and returns back to original spot.

### Spawnflags:

```
64 - Allows player to use the bmodel with use
128 - Starts deactivated
```

### Keys:

```
angles - determines what direction to move at.
target - what to fire at when used
speed - speed to move at, default 40
wait - how long to wait to return to its closed position, set to -1 for it to never return
health - if set the button must be killed in order to fire its target
lip - How high to rest above from a brush default 4
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_button * model,*22,angles,0 180 0,target,the_door,lip,5,
```

## func_door **
A bmodel that opens and closes, can fire targets along the way. When this entity doesn't have a targetname it will autospawn another entity to trigger it called a "trigger_door". To delete this entity edit the func_door to have a targetname.

### Spawnflags:

```
1       - Start Open
2       - Moves when push/pull is used on it
4       - Crushes anything in its path, instead of returning to its position it came from
8       - Stops at the end of its movement and doesn't returned unless used again
16      - Shows shader animmap It starts off and wont move properly until something uses its targetname, 
          the trigger_door entity wont effect it until after its used its first time
64      - Can be used with use key
128     - Starts deactivated
```

### Keys:

```
team - Use this to pair up two door together like double doors, that move in opposite directions. give both the same team key and once 1 is triggered the second one automatically moves.
model - bmodel to draw
target - Door fires this when it starts moving from it's closed position to its open position.
opentarget - Door fires this after reaching its "open" position
target2 - Door fires this when it starts moving from it's open position to its closed position.
closetarget - Door fires this after reaching its "closed" position
angles - determines its angle that it moves towards
dmg - damage to inflict when a player blocks its path default 2, set to -1 for no damage
speed - how fast the bmodel moves, default 100
targetname - if set there will be no trigger_door spawned and will only move when used
health - if set the door must be killed to move open
delay - if set how long to wait before starting to move
wait - if set how long to wait when it reaches its open position to move towards its closed position
lip - How high to rest above from a brush default 8
```

### Example code:

```
/place func_door * model,*25,angles,0 360 0,targetname,the_door,target,deact_button,closetarget,act_button,
```

## func_static **
equivalent to misc_model_breakable for bmodels

### Spawnflags:

```
1 - Will be used when you Force-Push it
2 - Will be used when you Force-Pull it
4 - Toggle the shader animation frame between 1 and 2 when used
8 - Make it do damage when it's blocked
16 - Make it do damage when it hits any entity
64 - Player can use it, fires its target when used
128 - Starts Deactivated
```

### Keys:

```
target - what to fire at when used
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_static * origin,0 0 100,model,*5,spawnflags,64,target,door,
```

## func_rotating **

### Spawnflags:

```
4 - Moves on X Axis
8 - Moves on Y Axis
16 - Will hurt a player if blocked
64 - Can be used
128 - Start Deactivated
```

### Keys:

```
speed - how fast it moves default is 100
dmg - damage to inflict when blocked
spinangles - set rotation on all three axis X Y Z
health - the set health it has when this is set it gets destroyed when killed
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_rotating * origin,200 0 0,model,*5,dmg,200,spawnflags,20,spinangles,90 20 50,
```

## func_bobbing **
bmodel that bobs up and down

### Spawnflags:

```
1       - On X Axis
2       - On Y Axis
64      - Player can use bmodel
128     - Start Deactivated
```

### Keys:

```
height  - How high to bob
speed   - How long it takes to complete the bob
dmg     - damage to inflict when blocked
model   - bmodel to draw
color   - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light   - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_bobbing * origin,0 50 0,model,*69,height,200,speed,5,
```

## func_pendulum **
A bmodel that swings like a pendulum

### Spawnflags:

```
64 - can be used
128 - start deactivated
```

### Keys:

```
speed - Number of degrees each way the pendulum swings, default 30
dmg - Damage to inflict when blocked
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_pendulum * origin,0 200 0,model,*5,speed,5,
```

## func_train **
Spawns a bmodel that follows path_corner entities as a train

### Spawnflags:

```
1 - Start On
2 - Can be toggled on and off
16 - Damages anything in its path
64 - Can be used
128 - Starts Deactivated
```

### Keys:

```
speed - how fast to move
target - the path_corner to start the train at
dmg - how much damage to inflict when blocked
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_train * target,path_corn1,speed,200,dmg,200,spawnflags,65,
```

## func_breakable *
spawns a bmodel that gets destroyed when attacked

### Spawnflags:
```
1 - Can only be broken by being used
2 - Does damage on impact
8 - Can be broken by impact damage, like how glass gets broken
16 - Saber Only
32 - Only takes damage from ATST or Emplaced Guns
64 - Using it doesn't make it break, it can still break from damage
128 - Player can use it
256 - Don't use the explosion effect when destroyed
```

### Keys:

```
paintarget - what to fire at when hit but not destroyed
wait - how long to wait before firing paintarget
delay - when destroyed how long to wait before blowing up
health - how much health it has
splashdamage - how much damage to give to players withing the splash radius
splashradius - the radius around the entities origin to give damage to when destroyed
model - bmodel to draw
```

### Example code:

```
/place func_breakable * origin,0 0 0,model,*25,health,200,splashradius,200,splashdamage,200,
```

## func_glass *
same thing can be done with func_breakable

### Spawnflags:

```
64 - Can be Used
128 - Start Deactivated
```

### Keys:

```
maxshards - how many shards of glass to draw when broke
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_glass * origin,0 0 0,model,*5,maxshards,5,
```

## func_usable *
bmodel that disappears when its used and reappears when its used again

### Spawnflags:

```
1 - Starts disappeared
8 - Doesn't Toggle on and off when used, just fires target
64 - Can be used
128 - Start Deactivated
```

### Keys:

```
target - what to fire at every time it is turned to off state
model - bmodel to draw
color - add this before light key for the light key to work properly it does a RGB value so ",color,1 0 0" for a red light
light - radius of light, color key must be set first in your spawnstring for it to work
```

### Example code:

```
/place func_usable * origin,0 50 0,model,*22,spawnflags,1,target,credits,
```
