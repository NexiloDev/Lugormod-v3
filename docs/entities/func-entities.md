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
