# Lugormod U# 2.4.8.4 Cvarlist
## lmd_maxSameIp
### Default value: 3
```
Maximum number of users that can have the same ip.  Once this limit is reached for a certain ip, all new connections from the ip will be ignored.  Usefull for stopping fake player attacks.
```
## lmd_melee_lightning_multiplier
### Default value: 2
```
Set the multiplier for melee force lightning damage.
```
## lmd_autoBanSameIp
### Default value: 0
```
If lmd_maxsameip is set, then this cvar controls whether to ban ips that go over the given limit.
```
## lmd_datapath
### Default value: default
### Restart required
```
The data path that lugormod will use for its accounts, entity sets, and other files.
```
## lmd_drain_below_level_3_range
### Default value: 512
```
Set the range for force drain below level 3.
```
## lmd_startingCr
### Default value: 0
```
The number of credits a newly registered player starts with
```
## lmd_stashRate
### Default value: 60000
```
The time in miliseconds to wait between checking to spawn a stash.  This time is offset by a random value, and may not spawn a stash each check.
```
## lmd_stashDepoTime
### Default value: 15000
```
The time in miliseconds needed to deposit a stash.
```
## lmd_stashCr
### Default value: 10
```
The default number of credits in a stash.  This is only used in the new lmd_stash* entity set, and only if no credits value is already given.
```
## lmd_adminGodLevel
### Default value: 1
### Restart required
```
The minimum admin level required to be able to use the God profession.  Set this to 0 to disable it fully.  Only admins this level and lower will be able to view and select this profession.  If an admin has this profession and this value is lowered below the admin's level, they will NOT loose the profession.This only applies to automatically created level based admin.  Authfiles must specify it manually via an authflag.
```
## lmd_adminCheatLevel
### Default value: 3
```
The minimum admin level required to be able to use cheats.  Set this to 0 to disable it.  This only applies to automatically created level based admin.  Authfiles must specify it manually via an authflag.
```
## lmd_saveAllPlaced
### Default value: 0
```
Allow all entities created with the place command to save.  This is for those of you who got too used to the bug which caused this to happen in the first place.  By default, only entities created by admins with the "save placed" auth flag or the level 1 auto authfile will save
```
## lmd_set_saber_delay
### Default value: 750
```
Set the delay for instant saber switch for when to be able to use saber again after swapping.
```
## lmd_set_saber_duels
### Default value: 1
```
Enable/Disable instant saber switch in duels.
```
## lmd_allow_set_saber
### Default value: 1
```
Enable/Disable instant saber switch.
```
## lmd_enforceEntWait
### Default value: 600
### Restart required
```
Minimum time in miliseconds to force certain entities to have a delay.  This works on func_doors and trigger_multiples.  Use this if the map you are playing on has troublesome doors that constantly open and close when the use button is tapped.
```
## lmd_spTurrets
### Default value: 0
### Restart required
```
This reverses spawnflags 4 and 8 for the misc_turretG2 entity.  Only turn this on if you are playing on a single player map that has turrets.
```
## lmd_adminLogLevels
### Default value: 1
### Restart required
```
Weather or not to log commands for the default admin levels.
Set this to 1 to log all levels to seperate files, or 2 to log them all to the file set by lmd_admindefaultlogfile
```
## lmd_adminDefaultLogFile
### Default value: all
### Restart required
```
Admins who have no other logfile set will log to this by default.Logs appear under <data folder>/logs/admin/*.log
```
## lmd_chatDisable
### Default value: 0
```
Bitmask to disable certain chat types.
1: Normal
2: Team
4: Tell
8: Admin
16: Close
32: Buddies
64: Friends
```
## lmd_chatDisableUseSay
### Default value: 0
```
If a chat mode is disabled with lmd_chatdisable, send is as normal chat rather than blocking it.
Does not work for tell.
```
## lmd_chatPrimary
### Default value: 1
```
Set the default chat mode for say.  If this mode is disabled, the mod will seek the next enabled mode.
Values:
0: Say
1: Team
2: Admins
3: Close
4: Buddies
5: Friends
```
## lmd_chatSecondary
### Default value: 4
```
Set the default chat mode for team say.  If this mode is disabled, the mod will seek the next enabled mode.
Values:
0: Say
1: Team
2: Admins
3: Close
4: Buddies
5: Friends
```
## lmd_banFile
### Default value: bans.txt
```
The file to store bans to.
```
## lmd_vehcloaking
### Default value: 0
```
Allow the cloak item to be used when in a vehicle.
To activate, a player must use the hotkey to directly use the cloak item.
```
## lmd_accBaseDays
### Default value: 0
```
Number of days to keep an account between user logins.
```
## lmd_accLevelDays
### Default value: 7
```
Level modifier for days to keep an account between user logins.
Days added is account level multiplied by this value.
```
## lmd_accLevelDiscount_time
### Default value: 300
```
Time in seconds of active server play per 1 CR discount to the cost of a new level, starting at their last level up.
Set to 0 for no discount
```
## lmd_accLevelDiscount_maxTime
### Default value: 432000
```
Time in seconds from their last level up before a player stops receiving a time based discount to their next level up.
Set to 0 for no maximum limit.
```
## lmd_accMaxDays
### Default value: 70
```
Maximum number of days to keep an account between user logins.
```
## lmd_lightning_below_level_3_range
### Default value: 600
```
Set the range for force lightning below level 3.
```
## lmd_logArchive
### Default value: 1
### Restart required
```
Create a new log file every day.  Records them under "logs/<date>.log"
Only checks for new days on map changes.
```
## lmd_closeChatRadius
### Default value: 512
```
Ajust the radius for the close chat mode.
```
## lmd_closeChatLOS
### Default value: 0
```
If set to 1, close chat is only hearable by those directly visible to the person chatting.
```
## lmd_loginSecurity
### Default value: 2
```
If set to 0, users will not be required to use a security code, but can if they choose.
If set to 1, users must enter their security code if they are logging in with a new ip.
If set to 2, only admins are required to use a security code.
It is highly recommended you set this to 1 or 2.
```
## bot_enableChat
### Default value: 1
```
Enable bot chat.
```
## g_startingWeapons
### Default value: 0
```
Players will get these weapons in addition to their normal set.
```
## g_startingAmmo
### Default value: 0
```
The percent of each weapon's maximum ammo to load the starting weapons with.  This only affects weapons listed in g_startingWeapons.
```
## lmd_penaltyAddTime
### Default value: 20
```
The minimum time in seconds between penalizing a player.
```
## lmd_penaltyRemoveTime
### Default value: 60
```
The time in seconds to wait after a penalty or a previous removal to remove one penalty.
```
## lmd_penaltyJailCount
### Default value: 3
```
How many penalties needed to jail a player.  Set to 0 to never jail on penalties.
```
## lmd_penaltyJailTime
### Default value: 5
```
When jailing  a player due to penalties, how many minutes to jail them for.
```
## lmd_penaltyTmpbanCount
### Default value: 6
```
How many penalties needed to temporarily ban a player.  Set to 0 to never jail on penalties.
```
## lmd_penaltyTmpbanTime
### Default value: 0
```
When banning a player due to penalties, how many minutes to ban them for.  A value of 0 will use the value in g_tmpBanTime.
```
## lmd_allowEmptyHostname
### Default value: 1
```
Prevent a player from joining if the attempt to identify their hostname fails.
```
## lmd_enableCorpseDrag
### Default value: 0
```
Experimental.  Enable dragging corpses with the use key.
```
## lmd_rewardcr_kill
### Default value: 0
```
Give a player credits for killing other players.  Does not work for killing NPCs.
```
## g_privateDuel
### Default value: 289
```
Bitmask to enable private duels between clients
0: Off
1: Private duels enabled
2: Multiple private duels enabled
4: Give full health at start of a duel
8: Give full armor at start of a duel
16: Give full force power at start of a duel
32: Restore full health at end of a duel
64: Restore full armor at end of a duel
128: Restore full force power at end of a duel
256: Force saber on at duel start
512: Force bow at duel start (Warning: sometimes this will loop)
1204: There is a king
2048: Frags give points only in duel in FFA
4096: Disable severing of duels

```
## g_noVoteTime
### Default value: 5
```
Number of minutes to wait after a map change before votes are allowed again.  This does not apply to admins level 3 or lower.
```
## g_autoRandomSpots
### Default value: 1
### Restart required
```
When certain lugormod specfic game modes are turned on, some items get disabled.  This will convert those disabled items into random_spots temporarily.
Due to recent entity system changes, this currently does not affect the g_weaponDisable cvar.
```
## g_scorePlums
### Default value: 0
```
When a player gets a score change, everyone will see a small colored number float up from their head with the number of points gained/lossed.
```
## g_maxForceLevel
### Default value: 5
```
This is the maximum force level that players can get.  Changing this may hamper the jedi profession.
```
## g_checkSkin
### Default value: 1
```
Stop players from using skin setups that might result in invisible or untextured players.
```
## g_gameMode
### Default value: 0
### Restart required
```
Settings for the lugormod-specific game modifiers.
1-6 are game modes, 8-256 are additional bitmask options
0: Normal
1: Instant Gib
2: Rocket Arena
3: Sniper Arena
4: Melee Arena
5: Super Merc/Jedi
6: Instant Disrupt

8: Low Gravity
16: With Force Jump
32: Start with Jetpack
64: Start with Grappling Hook
128: Respawn timer (20 sec)

```
## g_chickenTime
### Default value: 600
```
If set, a player will loose points if they do not respond to a duel challenge by another player within this many seconds.  This does not apply if you are challenged by a bot.  Set to 0 to disable this rule.
```
## g_fixShields
### Default value: 0
```
If no lugormod game mode is set, then the shield item will have 500 health and will regenerate 20 points per second.
```
## g_allowBlackNames
### Default value: 0
```
Allow players to use the color black in their names.
```
## g_profanityFile
### Default value: 
```
Specifies the config file to load data for the profanity filter.
```
## g_fixForce
### Default value: 0
```
Activates changes/improvements for certain forcepowers.
TODO: list values and changes.
```
## g_nakenAddress
### Default value: 
```
The ip or hostname of a naken chat server.  If this is set, the game will attempt to join the specified server and send all player chat to it.
WARNING: may cause the server to freeze.
```
## g_nakenRoom
### Default value: ja
```
If g_nakenAddress is set, this is the chat room to join.
```
## g_grapplingHook
### Default value: 0
```
If this is set to 1, then the stun baton alt fire becomes a grappling hook.
If this is set to 2, then the stun baton will always fire the hook no matter what attack is used.
```
## g_disableSpec
### Default value: 0
```
A bitmask containing different options for spectators.
1: Spectators will not be able to move.
4: Spectators will be unable to follow players.
This does not affect admins level 2 or lower.
```
## g_cmdLvlFile
### Default value: cmdleveldefs.cfg
```
The lugormod config file to load admin command level information from.
```
## g_dontLoadNPC
### Default value: 1
```
This cvar has the following effects when enabled:
Disables the fx_rain entity.
Disables loading of npc navigation waypoints.
Disables point_combat entities.
Allows doors with 'toggle' and 'start locked' spawnflags to still be used after they are unlocked.
Makes the 'misc_security_panel' entity toggle mover states between locked and unlocked.
Makes one-time use 'target_scriptrunner' entities become infinite use with a 60 second wait between triggerings.
Enables spawnflags 1 (player only) and 8 (npc only) for the 'trigger_push' entity.
Forces spawnflag 2048 (multiple) on the 'trigger_push' entity.
Reverses the effect of spawnflag 16 (relative) on the 'trigger_push' entity.
Changes the spawnflag 'push_constant' from 2 to 32 on the 'trigger_push' entity.
Forces trigger_hurt to always toggle on/off when used.
Forces spawnflag 1024 and changes the model of the 'emplaced_gun' entity.
```
## g_tmpBanTime
### Default value: 20
```
Number of minutes that a temporary ban lasts.
```
## g_kingTime
### Default value: 600
```
Number of seconds the 'duel king' has to find another opponent to duel before they loose king status.
```
## g_motdDispTime
### Default value: 5
```
Number of seconds to display the motd to a newly joined player.
```
## g_disableBail
### Default value: 0
```
Disable players bailing out of a flying vehicle when it is still airborn.
```
## g_voteFix
### Default value: 0
```
If the yes votes are greater than the no votes on a vote completion, then consiter the vote passed.
This does not affect player kick votes.
```
## g_maxVoteCount
### Default value: 3
```
The maximum number of votes a player can make.  This does not affect admins.
```
## g_enterMotd
### Default value: 
```
The message a player will see when they join the game.
```
## g_cmdDisable
### Default value: 0
```
A bitmask for disabling certain commands or feature sets.
TODO: document what this does.
```
## g_nameForServer
### Default value: server
```
The name to use when sending chat with '/rcon say'.
```
## g_duelForcePowerDisable
### Default value: 0
### Restart required
```
Bitmask of forcepowers to disable when in the duel or power duel gametype.
```
## g_pickupDisable
### Default value: 0
### Restart required
```
Bitmask of items to disable.
TODO: document possible values.
```
## g_meditateProtect
### Default value: 0
```
Number of miliseconds to wait before granting invincibility to someone using the meditation taunt.  Disabled if 0.
```
## g_meditateExtraForce
### Default value: 100
```
If a player uses the meditation taunt, then increase their max forcepower by this amount for the duration of the taunt.
DANGER: Can severely unbalance the game!  It is highly recommended you leave this as-is to avoid placing non force using professions at a severe disadvantage.
```
List generated: Dec  9 2020
