# Lugormod U# 2.4.8.4 Entitylist

## lmd_playereffect
Logical: true
### Description
When triggered, this entity will use its target when enabled, and use its target2 when disabled.
### Keys
```
effect              : '1' Invincible. '2' Electrocution. '3' Fall to death. '4' Jail. '5' Godmode. '6' Shield. '7' Notarget. '8' Invisible. '9' Undying.
wait                : Time to play the effect for. Default: '30'
```

## lmd_actor
Logical: true
### Description
An interactive non-player character controllable by the lmd_actor_* entities.
THIS IS A PREVIEW.  The actor system is not yet complete. This will be greatly expanded in the future.
As of now, the actor is only a standing immoble model. Future additions will allow it to be controlled.For more information, visit
lugormod.robophreddev.net/tasks/task/interactive-non-player-characters-actors
Web link now defunct.
### Spawnflags
```
1         : Drop to floor.
```
### Keys
```
NPC_TargetName      : The name to use for lmd_actor_modify or lmd_actor_action.
target              : The target to use after spawning an actor.
model               : The model to use for this actor.
skin                : The model skin to use for this actor.
modelscale          : The scale to apply to the model.
legsanim            : The text name of a legs animation to apply. Use the admin command '\anims' to find an animation.
torsoanim           : The text name of a torso animation to apply. Use the admin command '\anims' to find an animation.
color               : The custom RGB color of the model, if available.
```

## lmd_body
Logical: true
### Description
A false player body. When a player uses this, a clone of their model will appear where they are, doing their last animation.
Damage to the body will transfer to the player. If the player is not also teleported, they will be stuck inside the newly spawned body.
This is unstable, and may crash clients while leaving the server operational.

## lmd_chance
Logical: true
### Description
Fire one of six targets based on a random number.
### Keys
```
count               : The maximum random number to generate.
chance, chance2, ..., chance6: If the random number is less than or equal to the given value, then fire the relevant target.
```

## lmd_door
Logical: false
### Description
The lugormod equivalent of func_door: an entity that moves between 2 states, open and closed. This can also be used as an elevator.
### Spawnflags
```
1         : Reverse open and close positions.
2         : Activate by force push or pull.
4         : Crush players when closing.
8         : Toggle on/off: Stay open or closed until next used.
16        : Start locked. Do not open or close until it is used once. If the shader has a second animation stage, it will show its second stage until unlocked.
64        : Players can press the use key to trigger this.
128       : Start disabled. Do not trigger until used by a target_activate.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : Fired when the door starts moving from the closed position to the open position.
openTarget          : Fired after reaching the 'open' position.
target2             : Fired when it starts moving from the open position to the closed position.
closeTarget         : Fire after reaching the 'closed' position.
targetName          : Trigger when an entity uses this. If not specified, the door will open when someone gets close to it.
movement            : Vector cordinates containing the distance to move in each direction. Default is 0 0 100.
speed               : Movement speed (100 default).
wait                : Seconds wait before returning to the closed position (3 default, -1 = never return).
delay               : How many seconds to wait after it is used before moving - default is none.
dmg                 : Damage to inflict when blocked (2 default, set to negative for no damage). Requires the 'Crush players' spawnflag.
color               : Constantly emit this color. Buggy.
light               : Emit light at this intensity. Buggy.
health              : If set, the door must be shot to open.
linear              : If non-0, then move at a constant speed, rather than accelerating and decelerating.
teamAllow           : Even if locked, this team can always open and close it just by walking up to it. Values are: '0' - none, '1' - red, '2' - blue.
vehOpen             : If non-0, vehicles/players riding vehicles can open this door by getting close.
```

## t2_door
Logical: false

## lmd_drop
Logical: true
### Description
Create and launch a model that can be picked up by players.
### Spawnflags
```
1         : Spawn the item at the player's position.
2         : Player must use the item to pick it up rather than touching it.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : Target to fire when picked up.
target2             : Target to fire when time runs out.
noise               : Sound to make when being picked up
count               : Number of credits to give the player. If this is set and no noise key is specified, then the noise key defaults to sound/interface/secret_area.wav
velocity            : Speed at which to toss this item. Default '50'
offset              : Offset to drop from the player if spawnflag 4 is set. Default '64'
angles              : Angles to launch this item at
time                : Number of seconds to stay for. Set this to '-1' for no time limit.  Default '30'
wait                : Number of seconds to wait between triggerings.
```

## lmd_dropcr
Logical: true
### Description
Create and launch a model that can be picked up by players.
### Spawnflags
```
1         : Spawn the item at the player's position.
2         : Player must use the item to pick it up rather than touching it.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : Target to fire when picked up.
target2             : Target to fire when time runs out.
noise               : Sound to make when being picked up
count               : Number of credits to give the player. If this is set and no noise key is specified, then the noise key defaults to sound/interface/secret_area.wav
velocity            : Speed at which to toss this item. Default '50'
offset              : Offset to drop from the player if spawnflag 4 is set. Default '64'
angles              : Angles to launch this item at
time                : Number of seconds to stay for. Set this to '-1' for no time limit.  Default '30'
wait                : Number of seconds to wait between triggerings.
```

## lmd_flagplayer
Logical: true
### Description
Set temporary values on a player. These flags can be used by any entity that supports the usability keys. Flags are cleared on player death. This is unrelated to the capture the flag gametype.
### Keys
```
flags               : Bitmask of values to add to the player. If value is negative, the flags will be removed.
```

## lmd_gate
Logical: true
### Description
When triggered, this entity will use its target when enabled, and use its target2 when disabled.
### Spawnflags
```
1         : Start off
```
### Keys
```
target              : Target to fire when triggered and enabled.
target2             : Target to fire when triggered and disabled.
```

## t2_gate
Logical: true

## lmd_gravity
Logical: true
### Description
Change the gravity for a specific player.
### Spawnflags
```
2         : Change the gravity for the entire level.
```
### Keys
```
count               : New gravity value
time                : Number of seconds to change the gravity for. '0' for no time limit.
```

## target_gravity_change
Logical: true
### Description
Change the gravity for a specific player.
### Spawnflags
```
2         : Change the gravity for the entire level.
```
### Keys
```
count               : New gravity value
time                : Number of seconds to change the gravity for. '0' for no time limit.
```

## lmd_speed
Logical: true
### Description
Change the speed for a specific player.
### Spawnflags
```
2         : Change the speed for the entire level.
```
### Keys
```
count               : New speed value
time                : Number of seconds to change the speed for. '0' for no time limit.
```

## lmd_iobject
Logical: true
### Description
Gives the user the specified inventory object.
### Keys
```
type                : The inventory type to use.
name                : The name the item should use. Defaults to the type name
noDelete            : Don't let the user delete this item.
noCombine           : Do not let this item combine with other items, if applicable.
...                 : Extra item-specific keys.
```

## lmd_light
Logical: false
### Description
This entity lights up an area. It can be toggled between two colors.
### Keys
```
light               : The intensity of the light when turned on.
color               : The colors in decimal precent form (0 to 1, 0.5 would be 50%) for the color to display. Values are RGB in that order. Example: color,1 0 1, would be yellow.
offlight            : Same as light but when toggled off.
offcolor            : Same as color but when toggled off.
```

## t2_light
Logical: false

## lmd_mover
Logical: false
### Description
A model able to make use of any combination of movement patterns. Always spawns with its on movement settings.
Movement types      : '0' Stationary.
                    : '1' Interpolation.
                    : '2' Linear (no acceleration), move forever.
                    : '4' Linear (no aceleration), stop when the duration has passed.
                    : '5' Sine, accelerate and reverse after the duration.
                    : '6' Gravity.
### Keys
```
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
onDelta             : The movement offset when turned on. This is a vector, and needs the x, y, and z values specified (like mins/maxs/origin and others).
|                   : This is the origin/angles the entity should be at once 'duration' completes.
onDuration          : The movement time when turned on. The object will move Delta units every this many milliseconds. This may repeat if the right movement type is set.
onType              : The movement type when turned on.
offDelta            : The movement/rotation offset when turned on. This is a vector, and needs the x, y, and z values specified (like mins/maxs/origin and others).
|                   : This is the origin/angles the entity should be at once 'duration' completes.
offDuration         : The movement time when turned on. The object will move Delta units every this many milliseconds. This may repeat if the right movement type is set.
offType             : The movement type when turned on.
onADelta            : The angular rotation offset when turned on. This is a vector, and needs the x, y, and z values specified (like mins/maxs/origin and others).
|                   : This is the origin/angles the entity should be at once 'duration' completes.
onADuration         : The angular movement time when turned on The object will move Delta units every this many milliseconds. This may repeat if the right movement type is set.
onAType             : The angular movement type when turned on.
offADelta           : The angular movement/rotation offset when turned on. This is a vector, and needs the x, y, and z values specified (like mins/maxs/origin and others).
|                   : This is the origin/angles the entity should be at once 'duration' completes.
offADuration        : The angular movement time when turned on. The object will move Delta units every this many milliseconds. This may repeat if the right movement type is set.
offAType            : The angular movement type when turned on.
```

## lmd_playercheck
Logical: true
### Description
Fires its target if the user meets the usability keys, target2 if not.
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
target              : Target to fire if the player meets the usability keys.
target2             : Target to fire if the player does not meet the usability keys.
```

## lmd_propertyterminal
Logical: false
### Description
Fires target if the player is a member of the specified property, target2 if they are not.  If set, players may rent property access via this terminal.
### Spawnflags
```
1         : If 'count' is greater than zero, allow the renter to pay more money after the first payment to increase their time.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
property            : The name of the property to check access to.
target              : Target to fire if the user is a member of the property.
target2             : Target to fire if the user is not a member of the property.
count               : Number of credits per day this terminal costs to rent. If not set, then this terminal will not be rentable. Players can pay money to rent the terminal with '/pay <credits>'
mindays             : If 'count', the minimum number of days this player can rent the property for.
maxdays             : If 'count', the maximum number of days this player can rent the property for.
maxrenters          : If 'count', the maximum number of renters that this terminal will allow. Defaults to 1.
rank                : If 'count', the property rank to give to new renters. Values are: 1 - owner, 2 - caretaker, 3 - guest.
grantmessage        : Message to display when user has access.
denymessage         : Message to display when user does not have access.
```

## t2_propertyterminal
Logical: false

## lmd_property
Logical: true
### Description
Sets or removes a property access rank on the activator.
### Keys
```
property            : The property to set access to.
rank                : If 'count', the property rank to give to new renters. Values are: '1' - owner, '2' - caretaker, '3' - guest, '0' - remove access.
1                   : Drop to floor.
```

## lmd_pwterminal
Logical: false
### Description
A terminal that fires its target when the correct password is given. Players can enter a password using '\interact <password>'.
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
message             : Text to show when used.
password            : The correct password.
target              : Target to fire when correct password is entered.
target2             : Target to fire when incorrect password is entered.
target4             : Target to fire when any password is given.
target5             : Target to fire when used.
randPw              : Generates a new, random password of the same length, everytime the entity is (re)spawned.
```

## t2_pwterminal
Logical: false

## lmd_remap
Logical: true
### Description
Replace a texture or shader in the game with a new texture/shader. This affects all textures, including map textures, models, sabers, and the ui interface.
### Spawnflags
```
1         : Toggle the remap on and off when used.
```
### Keys
```
old                 : Shader to replace.
new                 : Shader to use in place of the old one.
```

## lmd_rentterminal
Logical: false
### Description
A terminal that can be rented. Players pay money using '\pay <credits>', and then can trigger the terminal's target as many times as they want before the rent runs out.
### Spawnflags
```
1         : The rent will expire when the player dies.
2         : Player will be able to pay more money after the initial payment to increase the rental time.
4         : Warn the player when there are 30, 15, and 5 seconds left before the rent runs out.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
message             : The message to be displayed when the terminal is used.
count               : Cost to rent this terminal.
minutes             : Number of minutes to gain when payed 'count' number of credits.
wait                : Minimum time to wait between payments, if spawnflag 2 is set.
maxTime             : Maximum number of minutes a player can rent.
minTime             : Minimum number of minutes a player can rent.
target              : Target to fire when used by its current renter.
target2             : Target to fire when the rent runs out.
target3             : Target to fire when first rented.
target4             : Target to fire when used by someone who is not the renter while being rented.
target5             : Target to fire when used by anyone when not being rented.
```

## t2_rentterminal
Logical: false

## lmd_restrict
Logical: true
### Description
Restrict certain player actions or events within the given area.
### Spawnflags
```
1         : Players in this area will not take damage.
2         : Players in this area will not be able to use forcepowers.
4         : Players in this area will not be able to use their jetpack.
8         : Players in this area will not be able to duel. Existing duels will be broken if a player enters it.
16        : Players in this area will not be able to fire weapons. Players may still see the weapon fire animation.
128       : Start disabled. Must be used by a target_activate to have any effect.
```
### Keys
```
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
```

## lmd_scale
Logical: true
### Description
Changes a player's scale.
### Keys
```
scale               : The scale between 1 and 1024 to set the player to. A scale of 0 will set them to their default scale. Default 0.
time                : Number of seconds for the scale to last. '0' for unlimited. Default: '0'
```

## lmd_stashdepo
Logical: false

## lmd_stashspawnpoint
Logical: true

## lmd_stashzone
Logical: false

## lmd_terminal
Logical: false
### Description
List up to 6 commands to the player. The player can activate a command by using '\interact <command number>'.
### Spawnflags
```
1         : Send the output to the player's screen.
2         : Do not send the output to the player's console.
```
### Keys
```
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
#FLAGS              : (null)
message             : Message to display when used.
useTarget           : Target to fire when the player presses the use key on this.
globalTarget        : Targe to fire when any command is used.
cmd-cmd6            : Name of each command.
target-target6      : Target to use for each command.
```

## t2_terminal
Logical: false

## lmd_toggle
Logical: true
### Description
Targets 1 through 'count' will be used in order. One target will be fired per trigger.
### Keys
```
count               : The highest target number you are using. Must be greater than 1.
target -> target6   : Targets to fire.
```

## t2_toggle
Logical: true

## lmd_train
Logical: false
### Description
A train that moves between path_corner target points.
### Spawnflags
```
1         : Start moving as soon as the map loads.
2         : Toggle movemen when used.
4         : Stop when blocked.
32        : Keep moving when blocked, crush through the blocking player.
64        : Usable by players.
128       : Start disabled.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
speed               : Movement speed.  Default '100'
dmg                 : Damage to inflict when blocked.
target              : The first path_corner to move to.
color               : Vector of red, blue, and green values.
light               : Intensity of emitted color.
wait                : Time to wait between uses, if spawnflag 64 is set.
```

## lmd_customskill
Logical: true
### Description
Set a custom skill value to a registered player. No affect on players who are not logged in. No affect on profession skills.
### Spawnflags
```
1         : Direct set. Use this to override the value or set it to a string.
```
### Keys
```
skill               : The custom skill name to set.
value               : If spawnflag 1 is ^1not^7 set, this is added to the origional as a non-decimal number. Otherwise, it is directly set.
```

## lmd_event
Logical: true
### Description
Trigger targetnames on various player events.
### Spawnflags
```
1         : For deathTarget and killTarget, both the attacker and target must be inside the trigger
2         : deathTarget is only called for a combat death (No suicides or untriggered entity damage).
128       : Start deactivated.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : Target to fire if a player enters this area. The trigger will not refire on this player until they exit and re-enter
exitTarget          : Target to fire when a player exits this area. This will never be called without Target firing first.
deathTarget         : Target to fire when a player dies.
killTarget          : Target to fire when a player kills another player.
```

## lmd_interact
Logical: true
### Description
List up to 6 commands to the player. The player can activate a command by using '/interact <command name>'.
Note that this uses names instead of numbers.
### Spawnflags
```
1         : Password mode.  Do not show the player the commands or tell them when the command is invalid.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
message             : Message to display while interacting.
radius              : How far away from this entity the player may wander before the interaction is canceled.
globalTarget        : Targe to fire when any command is used.
unknownTarget       : Targe to fire when any command is used.
cmd, cmd2, ..., cmd6: Name of each command.
target, target2, ..., target6: Target to use for each command.
```

## info_player_start
Logical: true
### Description
Deprecated.  Use info_player_deathmatch instead.

## info_player_jail
Logical: true
### Description
Jailed players will spawn here.
### Keys
```
Target              : Target is fired when a player spawns at this spawn point.
```

## info_player_duel
Logical: true
### Description
For use in the duel game type.  A duelist will spawn here.
### Keys
```
Target              : Target is fired when a player spawns at this spawn point.
NoHumans            : Do not let human players spawn on this spawn point.
NoBots              : Do not let bots spawn on this spawn point.
```

## info_player_duel1
Logical: true
### Description
For use in the power duel game type.  The staff duelist will spawn here.
### Keys
```
Target              : Target is fired when a player spawns at this spawn point.
NoHumans            : Do not let human players spawn on this spawn point.
NoBots              : Do not let bots spawn on this spawn point.
```

## info_player_duel2
Logical: true
### Description
For use in the power duel game type.  The paired saber duelists will spawn here.
### Keys
```
Target              : Target is fired when a player spawns at this spawn point.
NoHumans            : Do not let human players spawn on this spawn point.
NoBots              : Do not let bots spawn on this spawn point.
```

## info_player_deathmatch
Logical: true
### Description
For use in the power duel game type.  The paired saber duelists will spawn here.
### Spawnflags
```
1         : Initial: The first time the player enters the game (from connection or a team switch), they will spawn here.
```
### Keys
```
Target              : Target is fired when a player spawns at this spawn point.
NoHumans            : Do not let human players spawn on this spawn point.
NoBots              : Do not let bots spawn on this spawn point.
```

## info_player_siegeteam1
Logical: true

## info_player_siegeteam2
Logical: true

## info_player_intermission
Logical: true

## info_player_intermission_red
Logical: true

## info_player_intermission_blue
Logical: true

## info_jedimaster_start
Logical: true

## info_player_start_red
Logical: true

## info_player_start_blue
Logical: true

## info_null
Logical: true

## info_notnull
Logical: true
### Description
Used as a positional target for in-game calculation, like jumppad targets, effects. target_position does the same thing
### Keys
```
targetname          : make the trigger target this value for the entity to be used
```

## info_camp
Logical: true

## info_siege_objective
Logical: false

## info_siege_radaricon
Logical: false

## info_siege_decomplete
Logical: true

## target_siege_end
Logical: true

## misc_siege_item
Logical: false

## func_plat
Logical: false
### Description
A vertically moving brushmodel platform.  Moves to its extended position when stood on, and returns when left alone.
This is a brush model entity, so be careful when using it.  The origin may not behave as intended.
### Spawnflags
```
64        : Activate when used by the player.
128       : Start deactivated.
```
### Keys
```
Model               : Required.  Brush model to apply.
Model2              : Md3 model to also apply.
Lip                 : Distance above the spawn position to go to when idle.  Default 8.
Height              : Distance above the spawn position to move to when touched.  Defaults to the brush's height.
Speed               : Speed to move at.  Default 200.
Dmg                 : Damage to apply when blocked from moving.  Default 2.
Color               : The vector color to emit.  May flicker and randomize when in motion.
Light               : The light intensity of the color to emit.
```

## func_button
Logical: false

## func_door
Logical: false
### Description
A bmodel that opens and closes and fires its targets along the way. When this entity doesn't have a targetname, it will auto-spawn another entity to trigger it called trigger_door.
### Spawnflags
```
1         : starts open
2         : moves when push/pull is used on it
4         : crushes anything in its path, instead of returning to the position it came from.
8         : stops at the end of its movement and doesn't return unless used again
16        : starts locked, with the shader animmap at the first frame and inactive.
          : once used, the animmap changes to the second frame and the door operates normally.
          : note that you cannot use the door again after this.
64        : can be used with use key
128       : starts deactivated
```
### Keys
```
model               : bmodel to draw
model2              : .md3 model to also draw
model2scale         : percent of normal scale (on all x y and z axii) to scale the model2 if there is one.
                    : 100 is normal scale, min is 1 (100 times smaller than normal), max is 1000 (ten times normal).
angle               : determines the opening direction
target              : door fires this when it starts moving from its closed position.
opentarget          : Door fires this after reaching its open position
target2             : Door fires this when it starts moving from it's open position to its closed position.
closetarget         : Door fires this after reaching its closed position.
targetname          : if set, no touch field will be spawn and must be triggered by remote button or trigger field.
speed               : movement speed (100 default)
wait                : wait before returning (3 default, -1 = never return)
delay               : when used, how many seconds to wait before moving (0 default)
lip                 : lip remaining at end of move (8 default)
dmg                 : damage to inflict when blocked (2 default, set to negative for no damage)
color               : go read func_static
light               : intensity of light/color
health              : if set, the door must be shot open
linear              : set to 1 and it will move linearly rather than with acceleration (default is 0)
teamallow           : even if locked, this team can always open:
                    : 0 - none (locked to everyone)
                    : 1 - red
                    : 2 - blue
vehopen             : if non-0, vehicles/players riding vehicles can open
```

## func_static
Logical: false
### Description
Equivalent to misc_model_breakable but for bmodels.
### Spawnflags
```
1         : will be used when you force-push it
2         : will be used when you force-pull it
4         : toggle the shader anim frame between 1 and 2 when used
8         : make it do damage when it's blocked
16        : make it do damage when it hits an entity
64        : player can use it with use button
128       : starts deactivated, must be used by a target_activate before it can be used
2048      : Very very evil, do not use this. BROADCAST
```
### Keys
```
model               : bmodel to draw
model2              : .md3 model to also draw
model2scale         : percent of normal scale (on all x y and z axii) to scale the model2 if there is one.
                    : 100 is normal scale, min is 1 (100 times smaller than normal), max is 1000 (ten times normal).
color               : RGB color value to use for bmodel. ex: color,1 0 1, makes pink. color,1 1 1, makes white
light               : intensity of color/light
material            : default is 0 - MAT_METAL
                    : choose a number 0 - 16
dmg                 : how much damage to do when it crushes (use with spawnflags 8/16)
linear              : set to 1 and it will move linearly rather than with accelleration. (default is 0)
```

## func_rotating
Logical: false
### Description
Spawns a rotating bmodel. Can cause damage.
### Spawnflags
```
4         : moves on x-axis
8         : moves on y-axis
16        : will hurt a player, if blocked
64        : can be used
128       : starts deactivated
```
### Keys
```
model               : bmodel to draw
model2              : .md3 model to also draw
model2scale         : percent of normal scale (on all x y and z axii) to scale the model2 if there is one.
                    : 100 is normal scale, min is 1 (100 times smaller than normal), max is 1000 (ten times normal).
speed               : determines how fast it moves; default value is 100.
dmg                 : damage to inflict when blocked (2 default)
spinangles          : instead of using 'speed', you can set use this to set rotation on all 3 axes (pitch yaw and roll)
health              : default is 0
                    : if health is set, the following keys are available:
numchunks           : Multiplies the number of chunks spawned. (default 1)  (.5) is half as many chunks, (2) is twice as many chunks
chunksize           : scales up/down the chunk size by this number (default is 1)
showhealth          : if non-0, will display the health bar on the hud when the crosshair is over this ent (in siege)
teamowner           : in siege this will specify which team this thing is 'owned' by.
                    :  To that team the crosshair will highlight green, other team: highlight red.
splashRadius        : damage radius to do
splashDamage        : damage to do
color               : RGB color value to use for bmodel. ex: color,1 0 1, makes pink. color,1 1 1, makes white
light               : intensity of color/light
material            : default is '0 - MAT_METAL' - choose a number 0 - 16
teamnodmg           : appicable only during Siege gametype. if 1, team 1 can't damage this. 
```

## func_bobbing
Logical: false
### Description
bmodel that bobs up and down
### Spawnflags
```
1         : on x-axis
2         : on y-axis
64        : player can use bmodel
128       : starts deactivated
```
### Keys
```
model               : bmodel to draw
model2              : .md3 model to also draw
model2scale         : percent of normal scale (on all x y and z axii) to scale the model2 if there is one.
                    : 100 is normal scale, min is 1 (100 times smaller than normal), max is 1000 (ten times normal).
height              : amplitude of bob (32 default)
speed               : seconds to complete a bob cycle (4 default)
phase               : the 0.0 to 1.0 offset in the cycle to start at
dmg                 : damage to inflict when blocked (2 default)
color               : RGB color value to use for bmodel. ex: color,1 0 1, makes pink. color,1 1 1, makes white
light               : intensity of color/light
```

## func_pendulum
Logical: false

## func_train
Logical: false

## func_group
Logical: false

## func_timer
Logical: false

## func_breakable
Logical: false

## func_glass
Logical: false

## func_usable
Logical: false

## func_wall
Logical: false

## trigger_lightningstrike
Logical: true
### Description
A vertically moving brushmodel platform.  Moves to its extended position when stood on, and returns when left alone.
This is a brush model entity, so be careful when using it. The origin may not behave as intended.
### Spawnflags
```
1         : Start off
```
### Keys
```
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
targetName          : Toggles on and off when used.
lightningFX         : Effect file to play on lightning.  Default env/huge_lightning.
wait                : Time in milliseconds between lightning strikes.  Default 1000.
random              : Random time offset in milliseconds to add to the time between strikes.  Default 2000.
dmg                 : Damage per strike.  Default 50.
radius              : Splash radius for applying damage around a lightning strike point.  Default 0 (direct strike).
```

## trigger_once
Logical: false

## trigger_multiple
Logical: true
### Description
A basic trigger. Fires its target when conditions are met.
### Spawnflags
```
1         : Only triggerable by players.
2         : Only trigger if the user is facing the trigger's angles.
4         : Require the use button to be held.
8         : Require the attack button to be held.
16        : Only triggerable by NPCs.
32        : Same as spawnflag 2.  For single player map compatibility.
128       : Start deactivated.
256       : Allow multiple entities to trigger this at once.  Warning: Requires g_synchronousClients to work with players.  Not compatible with the wait key.
```
### Keys
```
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
wait                : Time in seconds to wait between triggerings.  Default 0.
random              : Random plus or minus wait offset offset in seconds.
delay               : Number of seconds to wait after a triggering before firing the target.
target              : Target to use on triggering
target2             : Target to use after a triggering when conditions are no longer met (such as the player leaving the trigger).
speed               : Time in seconds to wait for another triggering before firing Target2.  Default 1.
noise               : The sound to play on the activator's origin when triggered.
NPC_targetname      : Only triggerable by an NPC with this NPC_targetname.
team                : Only the specified team can activate this trigger.  0: Any, 1: Red, 2: Blue.  Default 0.
soundSet            : Ambient sound set to play when this trigger is activated.
useTime             : Time in milliseconds the user is required to use this trigger for it to activate.  Plays a hacking animation and visual.  Requires spawnflag 4 to be set.
```

## trigger_push
Logical: false
### Description
Moves or throws a player in the direction of the target.
Warning: This entity must have a valid target that is placed before the trigger, otherwise the entity will fail to spawn.
Warning: Always put a wait key on this entity, otherwise it can glitch clients or crash the server.
Warning: If the target is lower than the trigger, the server may crash.
### Spawnflags
```
1         : Only affect players.
2         : Constant: Move the player at a constant speed in a straight line. Incompatible with Relative or Linear.
4         : Linear: Move the player in a straight line.  Requires a speed value. Incompatible with Linear or Constant.
8         : Only affect NPCs.
16        : Relative: Push the player in the direction of the trigger to its target, rather than the player to the target.  Incompatible with Linear or Constant.
32        : Same as spawnflag 2.  For single player map compatibility.
128       : Start deactivated.
2048      : Allow multiple entities to trigger this at once.  Warning: Requires g_synchronousClients to work with players.
```
### Keys
```
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : The entity to aim at.  The direction will be taken on spawn.
wait                : How long to wait between pushes.
speed               : How fast to push the player.
```

## trigger_space
Logical: false
### Description
Suffocate and freeze all players within the trigger.
### Spawnflags
```
128       : Start deactivated.
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
```

## trigger_shipboundary
Logical: false

## trigger_hyperspace
Logical: false

## trigger_asteroid_field
Logical: false

## trigger_teleport
Logical: false

## trigger_hurt
Logical: false

## trigger_always
Logical: true

## trigger_visible
Logical: true

## target_give
Logical: true

## target_remove_powerups
Logical: true

## target_delay
Logical: true

## target_speaker
Logical: true

## target_print
Logical: true

## target_laser
Logical: true

## target_score
Logical: true

## target_teleporter
Logical: true

## target_relay
Logical: true

## target_kill
Logical: true

## target_position
Logical: true

## target_location
Logical: true

## target_counter
Logical: true

## target_random
Logical: true

## target_scriptrunner
Logical: false

## target_interest
Logical: true

## target_activate
Logical: true

## target_deactivate
Logical: true

## target_level_change
Logical: true

## target_play_music
Logical: true

## target_push
Logical: true

## target_powerup
Logical: true

## light
Logical: true

## path_corner
Logical: true

## misc_teleporter_dest
Logical: true

## defender
Logical: false

## misc_security_panel
Logical: false
### Description
Uses its target. Is shorthand for the model: kejim/sec_panel.md3
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : fires at this target
targetname          : can toggle activation/deactivation if targeted
```

## misc_stuff
Logical: false

## misc_exploding_crate
Logical: false

## misc_model
Logical: false

## misc_model_static
Logical: false

## misc_model_breakable
Logical: false
### Description
This will spawn a model in game that can have no purpose, be usable, or be payable.
### Spawnflags
```
1         : Makes the object solid. If mins/maxs defined it will follow those
2         : Will cycle its animation
4         : When destroyed, bounding box will still exist
8         : When destroyed, doesn't display damage
16        : When used, no smoke
32        : When used, it will toggle its usemodel (model + '_u1.md3'), won't do anything without spawnflags 64
64        : When used, it will not break.
128       : Player can use it like a button
256       : No explosion
512       : Starts deactivated
1024      : Unknown
2048      : Unknown
4096      : Unknown
8192      : Payable button, use count for cost and message for display
```
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
model               : The model. If the model is a glm model, you need to include the '.glm' extention. You do not need the 'map_objects' folder in the path.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
usescript           : The script to use
parm1               : The movement distance for a moveable model to move to, usescript must be set
                    : Spawnflags 2 makes it loop its movement, otherwise it only moves when targeted or used
parm2               : The delay in ms to move again after completing its parm1 movement
count               : Only works is spawnflags 8192 is set. The amount of credits a player must pay to fire entity target
message             : The message to display when a player presses 'use' on the button
gravity             : Use this to enable/disable gravity. Make sure z-axis is off the ground when spawning. Model will be pushable/pullable
target              : What to fire at when used
modelscale          : How much to scale the model. 1-10 for larger, 0-1 for smaller. ex: .5 half size
targetname          : Make the trigger target this value for the entity to be used
```

## misc_G2model
Logical: false

## misc_portal_surface
Logical: false

## misc_portal_camera
Logical: false

## misc_weather_zone
Logical: false

## misc_bsp
Logical: false

## terrain
Logical: false

## misc_skyportal_orient
Logical: true

## misc_skyportal
Logical: true

## gametype_item
Logical: false

## misc_ammo_floor_unit
Logical: false

## misc_shield_floor_unit
Logical: false

## misc_model_shield_power_converter
Logical: false

## misc_model_ammo_power_converter
Logical: false

## misc_model_health_power_converter
Logical: false

## fx_runner
Logical: false
### Description
Runs the specified effect, if it is used, it will toggle on/off
### Spawnflags
```
1         : effect starts off, toggles on/off when used
2         : effect fires only when used
4         : does radius damage around effect every delay ms
```
### Keys
```
fxFile              : name of the effect file to play
target              : direction to aim the effect in, otherwise defaults to up
target2             : uses its target2 when the fx gets triggered
delay               : how often to call the effect, don't over-do this (default 200)
random              : random amount of time to add to delay, (default 0, 200 = 0 to 200 ms)
splashRadius        : only works when damage spawnflag is on (default 16)
splashDamage        : only works when damage spawnflag is on (default 5)
soundSet            : bmodel set to use, player starts sound when toggled on 
                    : loop sound while on (doesn't play on a oneshot), and a stop sound when turned off
```

## target_screenshake
Logical: true
### Description
Shakes whoever targeted the entity's screen. Default global shake.
### Keys
```
intensity           : intensity of the shake. default 10
duration            : duration of the shake. default 800
globalshake         : if it's not 0, shake all clients. default 1
```

## target_escapetrig
Logical: true

## misc_maglock
Logical: false
### Description
DOES NOT WORK. Place facing a func_door (using the angle, not a targetname) and it will lock that door. Can only be destroyed by lightsaber and will automatically unlock the door it's attached to. NOTE: place these half-way in the door to make it flush with the door's surface.
### Keys
```
target              : thing to use when destroyed (not doors, it automatically unlocks the door it was angled at)
health              : default is 10
model               : Default: imp_detention/door_lock.md3 (doesn't exist)
```

## misc_faller
Logical: true
### Description
Raining stormtroopers?? spawned every interval+random fudgefactor or if specified, when used. Be careful, it will take up a lot of tempEnts if you let it rain freely
### Keys
```
targetname          : if specified, will only spawn when used
interval            : spawn every so often (milliseconds)
fudgefactor         : milliseconds between 0 and this number randomly added to inverval
```

## ref_tag
Logical: true

## ref_tag_huge
Logical: true

## misc_weapon_shooter
Logical: true
### Description
Fires weapon projectiles when used.
### Spawnflags
```
1         : fire the alt-fire of the chosen weapon
2         : keep firing until used again (fires at intervals of wait)
```
### Keys
```
wait                : debounce time between refires (defaults to 500)
target              : what to aim at (will update aim every frame if its a moving target)
weapon              : specify the weapon to use (default is WP_BLASTER)
                    : WP_BRYAR_PISTOL
                    : WP_BLASTER
                    : WP_DISRUPTOR
                    : WP_BOWCASTER
                    : WP_REPEATER
                    : WP_DEMP2
                    : WP_FLECHETTE
                    : WP_ROCKET_LAUNCHER
                    : WP_THERMAL
                    : WP_TRIP_MINE
                    : WP_DET_PACK
                    : WP_STUN_BATON
                    : WP_EMPLACED_GUN
                    : WP_BOT_LASER
                    : WP_TURRET
                    : WP_ATST_MAIN
                    : WP_ATST_SIDE
                    : WP_TIE_FIGHTER
                    : WP_RAPID_FIRE_CONC
```

## lmd_spawner
Logical: true

## NPC_spawner
Logical: true

## NPC_Vehicle
Logical: true

## waypoint
Logical: true

## waypoint_small
Logical: true

## waypoint_navgoal
Logical: true

## waypoint_navgoal_8
Logical: true

## waypoint_navgoal_4
Logical: true

## waypoint_navgoal_2
Logical: true

## waypoint_navgoal_1
Logical: true

## fx_spacedust
Logical: true

## fx_rain
Logical: true

## fx_snow
Logical: true

## point_combat
Logical: true

## misc_holocron
Logical: false

## shooter_blaster
Logical: true

## team_CTF_redplayer
Logical: true

## team_CTF_blueplayer
Logical: true

## team_CTF_redspawn
Logical: true

## team_CTF_bluespawn
Logical: true

## item_botroam
Logical: true

## emplaced_gun
Logical: false

## misc_turret
Logical: false
### Description
A Hoth style turret.  Uses 2 entities.
### Spawnflags
```
1         : Start disabled.
```
### Keys
```
radius              : How far away an enemy can be for it to pick it up. Default: 1024.
wait                : Time between shots in milliseconds. Default: 300.
dmg                 : How much damage each shot does. Default: 100.
health              : How much damage it can take before exploding. Default: 3000.
speed               : How fast the turret can aim.  Default: 10.
splashDamage        : How much splash damage is done by the projectiles. Default: 300.
splashRadius        : The radius of the projectile explosion. Default: 128
shotspeed           : How fast the projectile moves.
targetname          : Toggles on / off when triggered.
target              : The targetname to fire when the turret is destroyed.
target2             : The targetname to fire when the turret locks on to an enemy.
```

## misc_turretG2
Logical: false

## misc_camera
Logical: false

## random_spot
Logical: true

## money_dispenser
Logical: false

## control_point
Logical: false

## emplaced_eweb
Logical: false

## target_fixdoor
Logical: false

## target_credits
Logical: true

## target_crash
Logical: true

## rail_mover
Logical: false

## rail_track
Logical: true

## rail_lane
Logical: true

## misc_slotmachine
Logical: false
### Description
An in-game slot machine. Accepts /pay with numbers 10-200. All numbers have to be divisble by 10.
### Keys
```
count               : the starting credit the machine has. When this hits 0 the machine will say 'out of credits'
```

## ghost_exit_red
Logical: true

## ghost_exit_blue
Logical: true

## target_modify
Logical: true
### Description
Modifies all entities on a map with the given targetname. It can change any specified key of the entity.
This has the same effect as /spawnstring edit, and results in the entity respawning.
If no key or value specified, it will only respawn the entity.
### Keys
```
target              : Target entity to edit or reset.
key                 : SpawnString key.
value               : SpawnString value.
```

## lmd_cskill_compare
Logical: true
### Description
Compares values of two customskills, and fires respective target.
### Keys
```
skill1              : skill to compare.
skill2              : skill to compare.
target              : Target to fire if skill1 is greater.
target2             : Target to fire if skill2 is greater.
target3             : Target to fire if both are equal.
```

## lmd_countcheck
Logical: true
### Description
Fires target or target2 depending on the current count of players who meet the requirements.
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
count               : Required count of players.
target              : Target to fire if greater or equal.
target2             : Target to fire if less.
```

## lmd_iterateplayers
Logical: true
### Description
Iterates among all connected players and fires its target for them.
### Keys
```
profession          : A bitmask of professions. Values: 1 - jedi/sith, 2 - merc
level               : Minimum player level.
maxLevel            : Maximum player level.
adminLevel          : Minimum admin level.
playerFlags         : A bitmask of flags set by the lmd_flagplayer entity.
property            : Check if the player can access the property. Any rank will work.
customSkill         : Name of a custom skill to check for.
customSkillValue    : Value to compare.
customSkillCompare  : Comparison type. -1 text, 0 greater or equal, 1 lesser.
requireCredits      : If positive, the player must have this many credits or more. If negative, the player must have less than this.
mins/maxs           : Hitbox data. Both values are vectors containing the x, y, and z sizes from the model's origin.
                    : Normally, the Mins data is negative. If no mins or maxs are specified, then a hitbox is automatically calculated to cover the entire model.
target              : Target to fire for any connected player who meets the requirements.
```

## target_heal
Logical: true
### Description
Heals or damages the user by a specified value of health or armor.
### Keys
```
health              : Health points to acquire.
armor               : Shield points to acquire.
ammo                : Ammo to acquire. Does not affect every ammo type. Use a value of '16777216' to set maximum a player can carry.
```

## lmd_actor_modify
Logical: true
### Description
Change actor attributes on the fly. All actors matching the NPC_Target with their NPC_TargetName will be affected.
### Keys
```
NPC_Target          : The name of the actors to affect.
target              : This target will be fired once this entity finishes applying all modifications.
origin              : If non-zero, the actor will be teleported to this origin.
angles              : If non-zero, the actor will be turned to face these angles.
modelscale          : The scale to apply to the model.
legsanim            : The text name of a legs animation to apply. Use the admin command '\anims' to find an animation.
torsoanim           : The text name of a torso animation to apply. Use the admin command '\anims' to find an animation.
color               : The custom RGB color of the model, if available.
```

## target_animate
Logical: true
### Description
Makes the user play specified animation.
### Keys
```
torsoAnim           : Upper animation to be played.
legsAnim            : Lower animation to be played.
torsoTime           : Time in milliseconds to play the upper animation for.
legsTime            : Time in milliseconds to play the lower animation for.
```

List generated: Nov 12 2020
