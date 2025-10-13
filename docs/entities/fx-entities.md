### Key Chart:
```
* = Entity is triggerable.
** = Entity can be targeted to work. Or has to be.
*** = Is an entity that is placed that doesn't need to be targeted/triggered to work.
(L) = Either a new entity created for Lugormod, or if an existing entity then edited for Lugormod.
```

- So if an entity has **(L) by it that means that it was created for lugormod, or was edited, and has to be targeted to work.

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