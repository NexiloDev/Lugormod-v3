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