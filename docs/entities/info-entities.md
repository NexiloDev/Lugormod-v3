### Key Chart:
```
* = Entity is triggerable.
** = Entity can be targeted to work. Or has to be.
*** = Is an entity that is placed that doesn't need to be targeted/triggered to work.
(L) = Either a new entity created for Lugormod, or if an existing entity then edited for Lugormod.
```

- So if an entity has **(L) by it that means that it was created for Lugormod, or was edited, and has to be targeted to work.

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