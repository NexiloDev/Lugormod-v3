# Lugormod v3 Changelog

### Lugormod v3.3.1 - *Released 22 October 2025*
- New `target_fp` entity that allows forcing powers and power levels onto players inside an area. For example, setting all players to have lighting at level 3 inside a certain area on the map.
- Add `CrosshairText` and `CrosshairTextRange` keys to `func_` entities.
- Enable targeting a `lmd_trainer` from a `lmd_terminal` so that they can be chained together.
- Bug Fixes
  - Fixed a crash when a `lmd_door` was grabbed with `grabx` `graby` `grabz`.
  - Fixed a bug where `target2` was not firing on `func_door` entities.

### Lugormod v3.3.0 - *Released 6 October 2025*
- RGB Saber Support (**Note:** You will need the latest TaystJK client as of this date, to use it).
- New & Updated Commands & Features
  - `\bounty list` and `\bounty <name> <amount>` - Commands for a new Bounty system allowing you to set a bounty on another player for a certain amount of money. You must be logged into an account to do this, and the target must also have an account. Note that bounties can stack on each other, so for example two players could set a bounty of 5000 credits on the same player, meaning that player will now have a 10,000 credit bounty on them that someone can collect by killing them.
  - `\levitate` - New command allowing you to meditate but instead of sitting on the ground, you're character will hover in the air. Many additional cvars added to allow you to adjust the movement distance and velocity of the hover, along with enable FX and sounds, and even health regen for Jedi and Force regen for Sith. See the Cvars List (cvars.md).
  - `\grab` command updated to allow you to use Push\Pull binds to move the entity towards or away from you.
- Improved and expanded on the `entityinfo` command documentation on a huge amount of entities where there were errors, outdated information, or information was missing entirely.
---
### Lugormod v3.2.0 - *Released 14 June 2025*
- Updated Commands
  - `\playerlist` command now includes IPs and hostnames for clients previously supplied via the `\playerips` command which is now removed.
  - `\interact` command is now usable on `lmd_terminal` even if it has spawnflags set to 4 (on-screen menu) giving the player the option of interacting in the `old way` if they choose.
- New & Updated Entities
  - `lmd_trainer` - New entity utilising the new on-screen menu system allowing players to view account information, level up, set skills etc.. via on-screen menu. Heavily customisable with sounds, colours..etc.. allowing it to be used either with a button, or even used in conjunction with a `lmd_actor`.
  - New Key: `crosshairText` - added to various entities including `misc_model_breakable` and `lmd_terminal`. Shows a message on screen to the player when aiming at the entity. For example, you might have a lmd_actor that the player can speak to, so you place a lmd_terminal over the NPC, with a `crosshairText` key that has their name displayed to the player when they look at them.
- New Cvars
  - `lmd_melee_lightning_multiplier` - New Cvar that sets the damage of Force Lightning when used while holding melee weapon. (only applicable if melee is enabled on Force Users). By default the damage is doubled due to two hands.
---
### Lugormod v3.1.1 - *Released 13 May 2025*
- Security/Cheat Prevention
  - Implemented `speedhack` exploit prevention.
- New Feature
  - Support for instant swapping of sabers (from duals to staff etc), rather than needing to respawn for the change to take effect. Can be done via the existing `\saber` commands, or using the standard menu system.
---
### Lugormod v3.1.0 - *Released 13 April 2025*
- Entity Updates
  - `lmd_terminal` - New spawnflags option added (4) which utilites a new on-screen menu system rather than using console and the `\interact` command. Very flexible, and can even be chained together to create conversations with NPCs with dialogue choices for example.
- Minor Fixes
  - Add support for orange and grey color codes that were added via to the client in OpenJK (and subsequent forks like TaystJK and EternalJK).
---
### Lugormod v3.0.5 - *Released 25 April 2025*
- Profesion Updates
  - Reduced the range of Force Lighting and Force Drain at lower skill levels to match the range of higher levels, improved hit registration on enemies (new cvars implemented for per-server customisation)
- Entity Updates
  - `lmd_restrict` - New spawnflags for enabling/allowing Desann saber style (256) and Tavion saber style (512).
---
### Lugormod v3.0.4 - *Released (31 March 2025)*
- Command Updates
  - `\skills` command now allows skills to be lowered (eg. `\skills neutral jump down`)
  - `\bounds` command is now a on/off toggle, now has a red/blue/green axis outline, rather than white. Will now update on a 1 second interval so adjustments to bounding box size/position/location will be reflected in near-realtime.
---
### Lugormod v3.0.3 - *Released (4 January 2024)*
- New Commands & Updates
  - `\grab` command now remain at the same initial distance from player when grabbing, rather than getting pulled to the player at a hard-coded distance of 128.
  - `\cancelgrab` - New command that will drop an entity and return it to its original position (useful if grabbed by accident).
- Profession Updates
  - Force users can now use the melee "weapon", however they have no upgrade path for melee, unlike the Mercenary profession.
---
### Lugormod v3.0.2 - *Released (12 November 2023)*
- New Stat Commands
  - `\topkd` - Kill/Death Ratio
  - `\tophits` - Hit/Miss Ratio (merc only)
  - `\topduels` - Win/Loss Ratio
- New Stat Command Aliases (for existing commands)
  - `\toplevel`
  - `\topkills`
  - `\topscore`
  - `\topstashes`
  - `\toptime`
  - `\topcredits`
- Bug Fixes
  - Fix for target_give entity.
  - Fix for stash respawn timer to stop instances of players randomly losing the stash after picking it up due to it respawning.
- Other
  - Improvement to wording of stash related messages in game console.
---
### Lugormod v3.0.1 - *Released (21 October 2023)*
- Bug Fixes
  - Fix for names no longer being restricted if in use on an account.
  - Fix for `\renameplayer` and `\rename` crashing the server.
---
### Lugormod v3.0.0 - *Released (21 October 2023)*
- New Building Commands
  - `\grab` - Grabs an entity and allows you to move it with mouse.
  - `\grabx` - Rotate entity on z-axis with mouse.
  - `\grabz` - Rotate entity on z-axis with mouse.
  - `\graby` - Rotate entity on y-axis with mouse.
  - `\grabOffsetInc` - Move entity away from you.
  - `\grabOffsetDec` - Move entity towards you.
  - `\clone` - Create a duplicate of an entity.
- Bug Fixes
  - Fix for stash falling into bank (when player killed while depositing or intentionally via `\dropstash`)
  - Fix for Mercenary health being stuck at a maximum of 100.