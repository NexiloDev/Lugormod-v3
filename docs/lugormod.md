### 27th November 2005

### David Sjöstrand

# An introduction to the Lugormod 1.2

Last update 6/30/20 by Milo Hehmsoth

## Preface
This document serves as the official documentation for the Lugormod. It is a short introduction to the most essential features of the mod. This document is a work in progress and is more or less still only a draft. It will contain spelling errors, incorrect language and confusing choice of words. I myself am not a native English speaker. If you are, and you would like to help me make this document better, please contact me.

## Conventions
The term admin will be used for administrator.

Instead of the complete name of the game Star Wars Jedi Knight: Jedi Academy the abbreviation JK:JA will be used.

A mod is a modification of a game or a game server, in this case the game server for the game JK:JA.


### Console command syntax
The syntax of a command is written as follows:
```
\command <required argument> [optional argument]
```

Sometimes the argument can only be a particular word. In this example the argument can be the word ’list’, or no argument at all:
```
\command [’list’]
```

In this example the argument is either the word ’list’ or the word ’remove’: 
```
\command <’list’|’remove’>
```

Whenever it says <player> or [player] this is either the client number or the name of a player that is currently on the server. The name is always written with all non alphabetic characters omitted (eg. the name [^4WOW^7]Super Knigt*JM* would be written wowsuperknightjm). When it says <nick> this is the regis- tered name of a player. This is also written with all non alphabetic characters omitted. Whenever it says <path> this is the name of a file either in one of the assests#.pk3 files, the base folder or the lugormod folder. You can list files in those folders in the game with the command \dir. Type \dir / to list all available folders. To list the subfolders in a folder type \dir <folder> /. To list all files with a particular file ending in a folder and all it’s sub folders type \dir <folder> <fileending>.

This example will list all sub folders in the folder models/map_objects:
```
\dir models/map_objects /
```

This example will list all .md3 models in the folder models/map_objects/yavin: 
```
\dir models/map_objects/yavin md3
```

## The basics
Before looking at the Lugormod there are some basic concepts you need to have some knowledge about. When playing a multiplayer game there is always a server or host (usually only one) and one or more clients. The server is the machine hosting the game and a client is a machine connecting to the server to play the game. When you play the game the computer you are using is a client. Things that are said to be server-side are things that stuff that happen on the server machine and things that are said to be client-side are stuff that happens on the client machine. A (JK:JA) server can be run in two ways, as a non dedicated server or a dedicated server. When you start a non dedicated server the server will start and you will join the game. Both the server and the client will run in the same process. Anything you type in the console will be a server command. When you exit the game the server will stop running. This way of starting the server is not recommended.


When you start a dedicated server, all you will get is a console window show- ing some text. If you wish to join the game, you will have to start the game and enter the game which you will find in the LAN game list. Any command you type in the console will be an ingame command. To be able to issue a server command, you will either have to type them in the server console window, or you will have to use the the command rcon. The syntax for the rcon command is:
```
\rcon [rconPassword] <command>
```

If you don’t want to type the rcon password every time you use the rcon com- mand you can set the client-side cvar rconPassword. In the ingame console type:
```
\rconPassword <password>
```

The cvar rconPassword exists server-side also, and to be able to issue a server command using rcon, the server side rconPassword must be set and the the rconPassword you provide client-side must match that of the server.

### Comments
If you have unanswered questions after reading this document, or if you want more in depth information about the mod, visit the forums at http://lugor.mine.nu/ja
               
## Chapter 1 Installing the mod
To be able to run the mod at all you will need to have Star Wars Jedi Knight: Jedi Academy version 1.01 installed on a computer.

### 1.1 Windows
On a Windows system, locate the folder where Jedi Academy was installed (this is typically something like
```
C:\Program Files\Lucas Arts\Star Wars Jedi Knight Jedi Academy).
```

In the game folder you will find a folder called ’GameData’. Unzip the Lugormod zip archive in this folder. This will create a folder called ’lugormod’. In the ’lugormod’ folder, locate and remove the following files:
```
jampgamex86.dll
jampgamei386.so
jampgame_mac.zip
```

In the ’lugormod’ folder, locate the file server.cfg. This file contains all the settings for the server. Edit this to your liking (more details on this later). You can use notepad for this. To start the server, go to the ’GameData’ folder and double click the Start dedicated.bat. This will start a dedicated internet server on the default port (29070). It is recommended that you run a dedicated server.

### 1.2 Mac OS
This doesn’t work unless you have this version downloaded. - Left for posterity’s sake. Unzip the Lugormod zip archive in this folder when using JKJA Launch
```
~/Library/Application Support/Jedi Academy MP
```


This will create a folder called ’lugormod’. In the ’lugormod’ folder locate and rename the file jampgame_mac.zip jampgame_mac.pk3. In the ’lugormod’ folder, locate and remove the following files:
```
jampgame.dll
jampgamei386.so
jampgamex86.dll
```

Start the game. Select the Lugormod from within the game. 1

### 1.2.1 Mac OS Dedicated server
Unzip the Lugormod zip archive in the same folder as you find the JKJA Dedicated Server executable. Rename the file jampgame.dll in the ’base’ folder to something else. Then move the files jampgame.dll and Lugormod.pk3 from the ’lugormod’ folder to the ’base’ folder. In the ’lugormod’ folder, locate and remove the following files:
```
jampgamei386.so
jampgamex86.dll
jampgame_mac.zip
```

Edit the server.cfg file in the ’lugormod’ folder to your liking using a text editor. Change the command line options for JKJA Dedicated Server to: 
```
+set fs_game lugormod +exec server.cfg
```

### 1.3 Linux
Unzip the Lugormod zip archive in the same folder as you find the linuxjampded executable. Use your favorite text editor to edit the server.cfg file in the ’lugormod’ folder to your liking. In the ’lugormod’ folder, locate and remove the following files:
```
jampgame.dll
jampgamex86.dll
jampgame_mac.zip
```

Start the server with the command:
```
./linuxjampded +set fs_game lugormod +exec server.cfg
```

### 1.4 The files
```
./CHANGELOG.txt				The change log
./README.txt 				The readme
./lugormod.pdf				This document (but not on GitHub!)
./Start dedicated.bat			A batch for starting a dedicated internet server in Windows
./Start LAN game.bat 			A batch for starting a dedicated LAN server in Windows
./base/bots.cfg 			A file containing a description of the bots.
./base/botfiles/astupidbot.jkb 		The personality file for the bot astupidbot
./base/botroutes 			A folder containing files with bot routes.
./lugormod/cmdleveldefs.cfg 		Admin level definitions for commands.
./lugormod/jampgame.dll			The Lugormod binary for Mac OS.
./lugormod/jampgamei386.so 		The Lugormod binary for Linux.
./lugormod/jampgamex86.dll 		The Lugormod binary for Windows.
./lugormod/Lugormod.pk3 		Some files needed client side.
./lugormod/jampgame mac.zip 		The Lugormod bundle for Mac OS X.
./lugormod/server.cfg 			The server settings.
./lugormod/mapentities			A folder containing files with saved entities.
```

# Chapter 2 The Lugormod
Lugormod is a server-side mod. It started out as a “fix” for all kinds of things I wasn’t happy with on my server. The goal or purpouse of the mod is simply to make the server a more interesting place to be in. A lot of work has gone into making single player maps work in the multi player game. I have also removed a lot of bugs from the original code, improving among other things the stability of the server. As most mods offer enhanced administration possibilities, and there is a demand for such, I implemented some in this mod too. Included with the mod is also the file Lugormod.pk3. It is a very small file that enables some previously disabled saber hilts, enables the turrets on the lambda shuttle, fixes the skin for the swoop, makes the swoop and swoop_cin hover on water, and fixes the shaders with vertical sprites for some ground textures (like in t2_trip and t2_dpred).

## 2.1 Getting started using the mod
As mentioned earlier you need to edit the server.cfg file before starting the server. This file contains the settings for the server. We will now take a look at the most important settings.

### 2.1.1 The server.cfg file
The server.cfg file contain lines with server commands to be issued at startup. Most of the commands are ’set’ or ’seta’ which are commands to modify the cvars on the server. A line typically looks something like this:
```
seta cvarname "value"
```

A line starting with // is a comment and is ignored by the server.

The first line we are interested in is the line starting with ’rconpassword’. This is the password for accessing the server remotely with the rcon command. Next we take a look at the cvar sv_hostname. This is the name of the server and is what is listed on the server list when you join a game. Set this to what ever you want.

The last cvar we will look at now is sv_maxclients. This governs how many players are allowed on the server. The maximum number of players this game can accomodate is 32. Other limiting factors are the bandwidth of your internet connection and possibly the capacity of your computer. I suggest you start low (12 or so) and go higher if there are no problems when the server is full.


### 2.1.2 Becoming an admin
To gain access to the admin commands you need to authenticate yourself as an admin. There are four admin levels. Level 1 is the most “powerful” and it is suggested that only you, the owner of the server, are a level 1 admin. As a level 1 admin you will have access to all Lugormod commands and all cheat protected commands.

Join the server you created. In the console type:
```
\rconPassword <rconpassword>
```

where <rconpassword> is the password you set earlier in the server.cfg file. Then type in the console:

```
\rcon authother <player> 1
```

where <player> is the name you are using.

Now you are authenticated as a level one admin. You will stay authenticated until you leave the server. This way you can authenticate any player as admin. You will however probably want admins to be able to authenticate themselves. More on this in section 2.2.

### 2.2 Accounts
Any playercanregistertheirnicknamewiththecommand\regnick <password> where <password> is a password selected by the user. A registered name can’t be used by any other player. When a player issues the regnick com- mand an account will be created and a user identification number (UID) will be returned (displayed in the console). The player can then use the command \login <UID> <regcode> when the player comes back to the server to login to this account. The account contains the following data:
```
• registered nick name. 
• regcode.
• profession.
• ammount of credits. 
• persistent score.
• total time on the server.
• level.
• day of the last log in.
• a string with data related to your profession 
• user ID.
```

The account will expire and is deleted if the player doesn’t login in a certain number of days. The number of days until the account is deleted is decided by the player’s level, and is 7 days for each level up to a maximum of 70 days.

Every Lugormod specific ingame command has a level. This is the admin level needed to be able to use the command. A normal, non admin, player has the admin level 0, and can only use commands with the level 0. Level 1 admins can access all commands. Level 2 Admins can access all commands except those that are level 1. A level 3 admin can access all commands except those that are level 1 or 2 and so on. The levels of the commands can be redefined. Set the cvar g_cmdLvlFile to the name of the file you want to use for this (for example cmdleveldefs.cfg). Open the file. Each row in the file is a command name - level pair. If you want to set the level for the commands blowup, drinkme and dragon all to 3, this is what you would write in your file:
```
"blowup" 3 
“drinkme" 3 
"dragon" 3
```

Now all level 3, 2 and 1 admins will be able to use those commands.

### 2.2.1 The professions
So far there are four professions, the default one which is no profession, admin, jedi/sith and mercenary.

### admin
A player who login to an account with the occupation admin will be authenticated as an admin with the admin level determined by the level in the account. To make an account an admin account use the server command makeadmin <nick> <level>. An admin account never expires, and the only way to change the level of an admin account is with the makeadmin command. To remove admin privileges from an account type makeadmin <nick> 0.

### no profession
The default profession for a newly registered player is ’no profession’. With this profession, the only benefit of levelig up is that the account will be valid for a longer time after last logging in (see section 2.5).

### jedi/sith
A player with the profession jedi/sith cannot use any weapons and only a few items. Every level the force regeneration time will be lowered (if set to anything higher than zero on the server), and the player will get some points to distribute on force powers. The current force power levels and the number of points available can be viewed with the command \forcelevel. This command is also used to raise the force power levels. The selection is persistent. The last selection can be undone with the command \undoforcelevel, but this has to be done before disconnecting or map change/restart. The maximum force power level is 5. The cost to raise the level of a force power is the current level o the force power + 1. To raise a force power from level 3 to level 4 would cost 4
points.

### mercenary
A player with the profession mercenary cannot use any force powers. A merce- nary can use all weapons and all items and will start with a jetpack, a weapon and melee. Every level the maximum health and armor points will be raised by 5 each, and the player will get some points to distribute on skills. The current skill levels and the number of points available can be viewed with the command \skill. This command is also used to raise the skill levels. The selection is persistant. The last selection can be undone with the command \undoskill, but this has to be done before disconnecting or map change/restart. The max- imum skill level is 5. The cost to raise the level of a skill is the current level of the skill + 1. To raise a skill from level 2 to level 3 would cost 3 points.

The following skills are available:
```
Starting weapon		The player will start with a more powerful weapon. 
Weapon grip		Better grip on the weapon when force pulled. 
Martial arts		Increases melee damage and adds kicks and grappling. 
Ysalmiri blast		Increases the power of an ysalamiri blast.
Jetpack fuel		Increases the ammount of jetpack fuel. 
Ammo hold		Increases the maximum ammount of ammo. 
Starting armor		The player will start with more armor. 
Stash range		Increases the range of the binoculars.
```

### 2.2.2 The scoring system
The persistant score stored in the account (see section 2.2) starts at 10 for a newly registered player. You can score or lose points in duels. If you win a duel and score points, the opponent will lose that same ammount of points. The ammount depends on how many points you and your opponent have and can be at most 10. If you have a higher score than your opponent you will receive at most one point for defeating that player. If you have a lower score you might receive several. The score is supposed to represent how good the player is rather than how many duels that player has fought. In addition to these points you may receive a bonus if you are the King (see section 2.6). This bonus depends on how many duels you have won as the King. You will get one extra bonus point for every 5 duels you have won as the King. You cannot get this bonus from the player you last defeated in a duel.

When you are challenged to a duel a message will appear centered on the screen. If you are registered (see section 2.2), the bottom row will say ’W: [#] L: [#]’ where [#] are numbers. The first number is how many points you would receive should you win, and the second number is the ammount of points you would lose should you lose the duel. The command \worthy will give you a list with these numbers for all connected players.

### The Chicken rule
If you do not accept a duel challenge from a player from whom you would not receive any points for defeating you are being a coward, and probably don’t deserve the score you have. You will lose up to 5 points for not accepting the duel. All points lost this way are restored if you win a duel against a player from whom you cannot score points. You must however do this before leaving the server, or your points will be forever lost.

When you lose points because of the chicken rule you can not lose points this way again in a certain ammount of time. This is decided by the cvar g_chickenTime. If g_chickenTime is set to 0 the chicken rule is disabled.

## 2.3 Modified Items
I found some items in the game very useless so I modified them a bit to make them more useful.

### 2.3.1 The grappling hook
The stun baton doubles as a grappling hook. Alternate fire will launch a hook that will attach to the surface you are aiming at. When you have the hook out you can reel in by pressing the jump key, and you can extend the rope by pressing the crouch key. Pressing primary fire will launch a new hook and release the old one. Pressing alternate fire will release the hook. The grappling hook can be disabled by setting the cvar g_grapplingHook to 0.

### 2.3.2 The teleporter gun
The bryar pistol is a teleporter gun. Alternate fire will launch a green stone. Primary fire will teleport you to the stone. The stone will remain for 20 minutes. It will then self destruct.

### 2.3.3 The binoculars
If there is a money stash (see section 2.4) on the map and close by, the binoculars, if worn by a player with the profession mercenary, will emit a blipping sound. The range from which you can detect the stash depends on the level in the skill ’stash range’. The sound will be more frequent the closer your aim is to the direction of the stash. The proximity of the stash is not indicated in any way.

### 2.4 Credits and stashes
For some reason this mod is best known for having money in it. I implemented this because I saw some players playing that they paid eachother money by saying ”*pays CR 10*” and such, so I decided to give them some money to play with. 

The money in the game is called credits. A player can drop money with the command \dropcr <ammount>. A player can give another player some money with the command \pay <ammount>. When using the command ’pay’ the player must stand close to, aiming at the receiving player. As level 1 admin you can use the command \iwantcredits <ammount> to give yourself money. 
	
The money is taken from a ”bank”. This bank starts out with an ammount of credits specified by the cvar g_creditsInBank, and this is the maximum ammount of credits there can be in the “world”. You can, however, add money to the bank with the server command \addtobank <ammount>. 
	
A player can earn money by finding a money stash and bringing it to a money dispenser (aka ”a bank”). When there is at least one money dispenser on the map, it will spawn money stashes in random locations on the map. There can only be one money stash at the map at a time. The time until a money stash spawns is random but depends on the number of players on the server. If there are many players the time will be shorter. 

A money dispenser is placed on the map using the command \placemoneydisp. The money dispenser will appear in the spot where you issued the command, facing the direction you did, as soon as you move away. 

The random locations around the map used for spawning the money stash at can be placed with the command \placerandomspot. Some random spots might already be on the map because all disabled item, weapon, ammo, shield and health pick ups are transformed into random spots (this behaviour can be disabled with the cvar g_autoRandomSpots). You can list all random spots by issuing the following server command entitylist random_spot.

### 2.5 The level
A registered player (see section 2.2) can gain levels. There are two ways of doing this. You can buy a level with the command:
```
\buylevel [ammount]
```

If [ammount] is enough to buy a new level, and you can afford it, you will level up. If [ammount] is not enough to buy a new level, or if you cannot afford a new level, the cost of the next level will be displayed. 

If you have the profession ’no profession’ you can also gain levels by earning a high persistant score (see section 2.2.2) and spending time on the server. 

To level up, both the score and the time must be high enough. The required time and score is displayed with the command \stats. 

The number of days an account is valid after last logging in is determined by the level and is the level multiplied by seven days. If the player does not login before this, the account is deleted.

### 2.6 The King mode
The first player to win a private duel becomes the king. The King will automatically accept duels. If a player wins a duel against the King, that player will become the King. 

To find out who is currently the King use the command \king. This will also display how many duels the current King has won since becoming the King, and how many duels the best King won. The King mode can be enabled/disabled with the cvar g_privateDuel (see section 3.3.31).

### 2.7 The bots
The bots are somewhat improved in the Lugormod. They will fight a little bit better and if you set the cvar g_botHonorableDuelAcceptance to 1 they will behave better, and not only accept duels, but also challenge players and other bots to duels. 

The bots in the Lugormod can also answer when you talk to them. They have a list of words and sentences, and if a player says a word from that list, the bots will pick a corresponding sentence and say that. Included with the mod is a fully configured bot called ’astupidbot’. It is only meant as a template for making bots of your own. 

The cvar g_botMinPlayers governs the minimum number of players there will be on your server. If at any time there are fewer than that number of players on the server, a bot will enter the game. If at any time there are more than that number players on the server, and if any of them is a bot, a bot will disconnect. Be sure to have configured at least as many bots as what you set g_botMinPlayers to.

With the server command \sayasbot <bot> <message> you can have the bot <bot> say <message>.

### 2.7.1 Bot commands
Whenever you can have a bot say something, you can have it perform one of the following actions instead of saying something:
```
gloat 		(the taunt) 
flourish 	(the taunt) 
meditate 	(the taunt) 
taunt 		(the taunt) 
bow 		(the taunt)
wait 		(stand still for a couple of seconds) 
ignore 		(stop challenging the player for a while) 
hug		(hug the player)
give 		<item>
spawn 		<vehicle>
attack		(start attacking the player)
throw		(throw the player)
forgive 	(stop hating a player)
goto 		(doesn’t really work)
surrender 	(the emote)
where 		(tell you where he is)
voteyes		(castvote yes)
voteno		(castvote no)
callvote 	<vote>
fnord 		(say something weird)
```

To have the bot do one of these actions have it say @<action>. This is an example of a server command that will make the bot ’astupidbot’ bow: 
```
sayasbot astupidbot @bow
```

### 2.7.2 Configuring the bots
The cvar g_botsFile specifies what file is to be used to define the bots. In the server.cfg provided with the mod g_botsFile is set to bots.cfg. This file can be found in the ’base’ folder. Open it with your favorite text editor. 

In this file there is only one section. This section describes ’astupidbot’. Copy the section and paste it below the existing section so that you have two sections. Now you have two bots. Change the name of the new bot by changing ’astupidbot’ to something else. 

The last line in the section is ’personality’. It specifies the name of a file containing the personality for the bot. Even though you can use the same personality file for several bots it is recommended that you create a new one for each bot. The personality file for astupidbot can be found in the ’botfiles’ folder in the ’base’ folder. Save and close the ’bots.cfg’ file and open the file astupidbot.jkb. This file is somewhat more complicated than the bots.cfg file. Most settings are explained in the file. Save the file with a new file name so that you get a new copy of the file, and set the the option ’personality’ in the bots.cfg file to refer to this file.

In the personality file you will find chat groups. There are several chat groups. In certain situations the bot will pick one of the sentences from a chat group at random and say it. For example, if the bot is killed it will pick one of the lines in the section ’Died’ and say that. One of the sections is ’ChatBack’ and it is a little bit different from the rest. It contains rows with words followed by a section containing one or more sentences. If a player says something that contains all of the words (in any order) found in one of the rows with words, the bot will randomly pick a sentence from the following section and say that. 

Here are some examples:
```
hello 
{
	Hi there! 
}
```

In the above example, if a player says the word ’hello’ in a sentence the bot will respond with “Hi there!”.
```
hello 
hi
{
	Hi there!
	Hi %s 
}
```

In this example, if a player says the words ’hi’ or ’hello’ in a sentence the bot will randomly pick one of the two answers “Hi there!” or “Hi %s”, where %s is replaced by the name of the player saying ’hi’ or ’hello’.
```
hello all
hi all
{
	Hi there! 
}
```

In this example the player must say a sentence containing both the word ‘hi’ and the word ’all’ or the word ’hello’ and the word ’all’ to get a response.

Some things to keep in mind:
The triggering words can not contain any non alphabetical characters (not even numbers).
When a match is found the ChatBack section will not be parsed any further.

```
hello 
hi
{
	Hi %s
}
hello all
{
	Hi there! 
}
```

In the above example the bot will never say “Hi there!”. Any sentence containing both the words ’hello’ and ’all’ will contain the word ’hello’ for which the answer is “Hi %s”. If you reverse the order of those sections you will have the desired result:
```
hello all 
{
	Hi there! 
}
hello 
hi
{
	Hi %s 
}
```

You can also have the bot perform an action in response to something:
```
tauntaun please
tauntaun plz
{
@spawn tauntaun 
}
jetpack please 
jetpack plz
jp please
jp plz
{
@give item_jetpack
}
```

## 2.8 Placing new stuff on the map
With the Lugormod you can place stuff on a map, save it and have it load whenever the map is loaded. There are several commands for placing stuff: placemodel, items place, and place, to mention a few (see section 3.1). 

When you have placed some stuff on the map, you will probably want to save your work. This is done with the server command saveit <filename>. You can later load up your stuff with the server command loadit <filename>. If you use the file name ’default’ it will be loaded automatically when you load the map. This is true for the FFA, Holocron FFA, Siege, Duel and Power duel game types. When you start a game of Jedi Master the file ’jedimaster’ will be loaded. For the game types Team FFA, CTF and CTY the file ’team’ will be loaded, and for the game type Battle Ground the file ’battleground’ will be loaded. 

Only the stuff placed by a level 1 admin will be saved with the command saveit.

## 2.9 Game modes
To add some variation to the game there are seven different game modes. The game mode is controlled by the g_gameMode cvar and they apply to all game types except Jedi Master, Holocron FFA, Siege and Battle Ground. The seven game modes are:
```
0 	Normal
1 	Instant Gib
2 	Rocket Arena
3 	Sniper Arena
4 	Melee Arena
5 	Super Merc/Jedi
6 	Instant Disrupt
```

To these game modes you can add any number of the following options by adding the number or numbers of the options to the number of the game mode.
```
8 	Low Gravity
16 	With Force Jump
32 	Start with JetPack
64 	Start with Grappling Hook 
128 	Start with Teleporter Gun 
256 	Respawn timer (20 sec)
```

For example, if you want instant gib with low gravity and a respawn counter you would set g_gameMode to 1 + 8 + 256 = 265 (this setting is very suitable for the CTF game type, try it out).

Players can call a vote for these game modes with the command \callvote g_gamemode <number>.

## 2.10 New game types
The game types Holocron FFA, Jedi Master and Capture the Ysalamari were disabled in JK:JA. The Lugormod enables them again. In addition there are two new game types called Battle Ground and Reborn. The first three probably don’t need any introduction, but the game type Battle Ground is explained in section 2.10.2, and Reborn in section 2.10.3

### 2.10.1 The Jedi Master game type
Because there are no maps for the Jedi Master game type, the saber must be placed on a normal FFA map somehow. This can be done automatically by setting the cvar g_jmsaberreplace. A pick up on the map will then be randomly selected and replaced by the saber. The cvar g_jmsaberreplace governs what can be replaced by the saber.
```
1	weapons
2	ammo
4	armor
8	health
16	powerup
```

Add up the numbers of the types of items you want to be used as possible positions for the Jedi Master saber.
If you want to place the saber manually use the command 
```
\place info_jedimaster_start 0 to place the saber.
```

If you set g_jmkillhealth to anything other than 0, the Jedi Master will continuously lose health and will only be able to gain health by killing other players.

The Jedi Master will gain g_jmkillhealth health for each kill.

The cvar g_jmforcelevel determines what force level the Jedi Master will have in all force powers.

The Jedi Master’s starting health is determined by the cvar g_jmstarthealth. Set the cvar g_jmhealthbar to 1 to have a health bar displayed when aiming at the Jedi Master.

The damage done by the Jedi Master’s saber is multiplied by the cvar g_jmsaberDamageScale.

### 2.10.2 The Battle Ground game type
The Battle Ground game type is played in teams. The Objective is to control command posts. A command post is taken by hacking it (use it). A player can teleport between command posts owned by the team that player is in by using the command post. The two teams start off with the same ammount of points. The points will count down until one team’s score reaches zero at which point the other team wins. The rate at which the points count down is reduced for every command post your team controls.


The game client does not allow the use of the GUI to select class in any game type other than Siege. The players will have to use the command
```
\class [1-6] to selecet class.

```

### Setting up a map for Battle Ground
You need to place at least two command posts on the map, one for each team. To place a command post owned by a team use the commands:
```
\place control_point 0 alliedTeam,1 // for the red team and
\place control_point 0 alliedTeam,2 // for the blue team.
```

Make sure the first command post you place is for the opposite team. Place player spawn points, and if you wish vehicle spawners, in the vicinity of the command posts. The spawn points will “belong” to the closest command post and the team controlling it. If you add the option ’alliedTeam’ to a vehicle spawner, the spawner will only spawn vehicles if the closest control point is controlled by the selected team. This way you can have one type of vehicles spawn when one team controls the command post, and another type of vehicles when the other team controls it.

There are two spawn flags for the command post:
```
1 Cannot be taken 
2 Important
```

The ’Cannot be taken’ flag is only valid if ’alliedTeam’ is set to either 1 or 2 (red or blue). An important control point takes longer to hack, but also reduces the rate the points count down more when controlled. You can set the option ’message’ to a description of the command post. This will be displayed when someone is trying to steal a command post from the opposite team. If you want a model other than the default one, set the option ’model’. You can also change the size of the bounding box with the options ’maxs’ and ’mins’.

Examples:
```
\place control_point 0 alliedTeam,1,spawnflags,1
```

This will spawn a command post that is owned by the red team at start and that can’t be taken by the blue team.
```
\place control_point 0 spawnflags,2,message,by the lake,
```

This will spawn an important command post that is not owned by any team at start.
Issue the server command '\saveit battleground' when you are finished placing your stuff.

### 2.10.3 The Reborn game type
Although you are in teams in this game type this is not really a team game. Your objective is to achieve the highest personal score. The game is played in several rounds. At the beginning of each round all players but one is in the blue team. 

When you are in the blue team you have no force powers and no saber but you can use weapons and pick health pick ups. You get one point for each member of the red team (the reborn) that you frag. If you are fragged by a member of the red team you become a reborn (you join the red team). 

When you are in the red team you cannot pick up weapons or health pick ups, but you have a light saber and force powers. You do not get any points for fragging blue players, but by doing so you ensure that they do not get more points. 

As the goal is the same for all the reborn, cooperation is a good idea. 

The following bonuses are awarded:
```
survival bonus		1 point every three minutes for the blue team.
last kill		2 points for the reborn who frags the last man standing.
last man standing 	3 points for the last surviving player in the blue team.
```

When all players are reborn a new round begins. The game ends when either the kill limit is reached or all players have started a round as reborn.

### 2.11 Temporary bans
The only way to ban a player is by the player’s IP address. Many players have a dynamic IP address which means that they get a new IP address every time they turn their computer on. Banning such an IP address permanently is not very effective. Also eventually someone else will get that IP address, and might not be able to connect to the server (not very probable, but still). 

In the Lugormod there are temporary bans. When added they stay for a certain ammount of time, then they are automatically removed. Any player who is vote kicked from the server will automatically get a temporary ban, so that the player can’t just reconnect instantly.

# Chapter 3 - The Lugormod Commands and Cvars

## 3.1 Ingame Commands

### \help <command>
The most useful command in the game is probably the command help. With no argument the command will display a list of all Lugormod commands available to the player. To get a short description on how to use a command supply the argument <command> to the command help. Example: \help login.

### \addloc <description>
With this command you can add a description of your current location. This is what is displayed with the command \location.

This is a level 1 admin command.

### \admins
The command will list all authenticated admins that are currently on the server. Next to every name their admin level will be displayed.

### \announce <time> <msg>
The message <msg> will be displayed for <time> seconds in the center of the screen for all players.

This is a level 3 admin command.

### \authother <player> <lvl>
Authenticates the player <player> for admin level <lvl>. The player will stay authenticated until re-authenticated, or until the player disconnects. To remove admin rights for a player set the level to 0. The player using this command can only authenticate others to a level less “powerful” than the player’s own level. 
	
This is a level 3 admin command.

### \becomeking
The current King (if any) will no longer be the King, and you will become the King.

This is a level 1 admin command.

### \blowup
The solid entity you are aiming at will explode. Use this command with caution, no checks are done before removing the entity. For removing stuff that you have placed the command killmodel is recommended.

This is a level 1 admin command.

### \bluespawnpoint
Place a player spawn point for the blue team. This is where the players in the blue team will start in a team game.

This is a level 1 admin command.

### \botwprender
Toggles the displaying of bot route waypoints. 

This is a level 1 admin command.

### \buddy [player]
Add a player to or remove a player from your list of buddies. If no argument is provided your current list of buddies will be displayed.

### \buylevel <ammount>
With this command a registered player (see section 2.2) can buy a new level (see section 2.5). If [ammount] is enough to buy a new level, and you can afford it, you will level up. If [ammount] is not enough to buy a new level, or if you cannot afford a new level, the cost of the next level will be displayed.

### \cancelvote
If there is a vote in progress, it fails. 

This is a level 3 admin command.

### \challenge <’power’|’force’|’fullforce’|’training’|’tiny’|’titan’>
With this command you can challenge another player to a “special” duel. Aim at another player when invoking the command. The “special” duel types are:
```
power		unlimited force power for both duelers.
force 		the duelers can use force powers in the duel.
fullforce	the duelers will have all force powers, and will be able to use them. 
training  	instead of being inflicted on the duelers the damage will be displayed
tiny		the duelers will be very small.
titan		the duelers will be very big.
```

The different types can be combined as in this example:
```
\challenge power fullforce titan
```

### \chpasswd <new password>
Change the password for your account. You have to be logged in to be able to do this.

### \class [1-6]
Use this command to select the class for the Battle Ground game type. If no argument is provided all the available classes will be listed. In front of each class name a number indicating how many players on the team is using that class is displayed.

### \credits
Your current wealth will be displayed (see section 2.4).

### \defender
With this command you can spawn a “defender”. It looks like an imperial dish, and will fire a deadly beam on any flying vehicle flying in a direction towards it. This is used to protect the area where the fighters are spawned from kamikaze pilots and other “ship lamers”. The fighters will be allowed to leave the area, but cannot return there.

This is a level 1 admin command.

### \dragon
Spit some fire on irritating players. 

This is a level 3 admin command.

### \drinkme
Shrink yourself. You will stay small until you either duel someone or reconnect (if you are not an admin in which case you can use the command \eatme to go back to normal size again).

### \drop <item>
Spawn and hurl an item in front of yourself. Example: \drop item_jetpack. 
	
This is a level 3 admin command.

### \dropcr <ammount>
Drop <ammount> credits (see section 2.4) infront of you. The money can then be picked up by any player.

### \drophi
Drop the currently selected holdable item infront of you. The item can then be picked up by any player.

### \dropjp
Drop your jetpack infront of you. The jetpack can then be picked up by any player.

### \dropwp
Drop the currently selected weapon infront of you. The weapon can then be picked up by any player.

### \eatme
Grow a few inches. You will stay big until you either duel someone or reconnect (if you are not an admin in which case you can use the command \drinkme to go back to normal size again).

### \emote [emote]
Perform an emote. If no argument is provided the available emotes will be displayed.

### \fixdoor
On some single player maps there may be doors that cannot be opened. It might be doors that are supposed to be opened by scripts triggered by events that take place only in the single player game. This can be amended with fixdoor. Aim at the door you wish to fix and issue the command. The fix can be saved with the server command saveit (see section 2.8).

This is a level 1 admin command.

### \fnord
Makes you say something weird. The Fnorder Program was originally written by Steve Jackson and Creede Lambard. It is used in the Lugormod with permission from Steve Jackson.

### \forcelevel [force]
Raise the force with number [force] one level. If no argument is provided, all forces and their numbers will be listed. The first time you choose a dark or light force all forces of the other side will be removed from the list.

This command is only available to players with the profession jedi/sith.

### \gethere <player>
The player <player> will be teleported to infront of you. 

This is a level 3 admin command.

### \goto <player>
You will be teleported to infront of the player <player>. 
	
This is a level 4 admin command.

### \hicredits
Display a list of the top ten wealthiest players (see section 2.4). 

This is a level 1 admin command.

### \hilevel
Display a list of the top ten players with the highest level (see section 2.5).

### \hiscore
Display a list of the top ten players with the highest persistant score (see section 2.2.2).

### \hitime
Display a list of the top ten players who has spent the most time on the server.

### \ignore [player]
Toggle ignore on the player [player]. Messages from an ignored player will not be displayed to you. If no argument is provided a list of the players you are currently ignoring (if any) will be displayed.

### \invisible [player]
The player [player] will become completly invisible. If no argument is provided you will become invisible.

This is a level 2 admin command.

### \ionlyduel
You will be more or less invulnerable until you engage in a duel. You won’t be able to harm anyone though. Once you have turned this on you can’t turn it off any way other than dueling someone. The command is for players who want to spend their time on the server dueling, without having to be bothered by players they would consider to be “lamers”.

### \items <’list’|’remove’|’place’> [itemname]
With this command you can place, remove and list the items on the map. There is a list of all items in the game in the appendix. To place an item type \items place <itemname>. The item will be placed where you stand. To remove an item type \items remove <itemname>. This will remove all items of that type. To list all items type \items list. This will display what items are placed on the map, and how many of each. To give an example, this is how to place a jetpack: \items place item_jetpack.
	
This is a level 2 admin command.

### \iwantcredits <ammount>
You will receive <ammount> credits (see section 2.4). 

This is a level 1 admin command.

### jail [player]
Put the player [player] in jail, or release the player if already in jail. If no argument is provided, the player you are aiming at will be jailed. For this to work you need to have placed at least one jail spawn point. This is done with the command \jailspawnpoint. The jailed player will spawn at such a spawnpoint. Use locations on the map from which you can’t escape. If a jailed player disconnects the players IP will be temporarily banned (see section 2.11). 

This is a level 4 admin command.

### \jailspawnpoint
Use this command to place a spawn point for players who have been jailed. Before you use the command \jail you should place at least one jail spawn point (info_player_jail). This is where a jailed player spawns. Place it in a place that can’t be escaped.

This is a level 1 admin command.

### \jmquit
If you are playing the Jedi Master game type and you are currently the Jedi Master, you will hurl the saber infront of you and will no longer be the Jedi Master.

This is a level 2 admin command.

### \killmodel
The name of this command is somewhat misleading. With this command you can remove any solid entity that you have placed. Aim at the entity and issue the command.

This is a level 2 admin command.

### \killother [player]
The player [player] will die. If no argument is provided the player you aim at will die.

This is a level 3 admin command.

### \king
This command will give you some information about the King (see section 2.6). It will tell you who is presently the King (if there is one), how many duels the current King has won, and how many duels the best King has won.

### \listadmins
This command will display a list of all accounts that has been made into an admin account (see section 2.2). The name and the admin level will be listed. 

This is a level 4 admin command.

### \location [player]
This will tell you the location of the player [player], or your location if no argument is provided. This will only work if a botlocations file exists for the map. There are some included with the mod in the lugormod/botlocations folder. It is a plain text file. Each line in the file lists the coordinates for the location and a string associated with it.

This is a level 4 admin command.

### \login <UID> <password>
With this command a player can login to an account (see section 2.2). To register an account use the command \regnick. When you do, you will have to privide a password of your own choice. A user identification number (UID) will be provided. Use the UID and the password when you login. When a nickname has been registered, noone can use that name without logging in to the account with this command.

### \newcode
This command changes the registration code for a registered player (see section 2.2). The most common reason for needing this is that a player misspells the command \login resulting in the registration code being said out loud in the game chat. The new registration code is displayed in the console.

### \newmap <map>
Loads the map <map>.

This is a level 2 admin command.

### \nocaps [player]
Whenever the player [player] says something, any upper-case letter will be changed into a lower-case letter. If no argument is provided it affects the player you are aiming at. The command toggles this setting, simply use it again on a player to turn it off. Use this on players who can’t seem to find the caps lock key after hitting it by mistake. If a player with nocaps disconnects the player’s IP will be temporarily banned (see section 2.11).

This is a level 4 admin command.

### \noclip [player]
Gives the player [player] “noclip”. If no argument is provided you will get “noclip”. This command toggles the setting.

This is a level 2 admin command.

### \novote [player]
The player [player] will not be able to call any votes. If no argument is provided the player you are aiming at will be affected. This command toggles the setting. Simply use it again on a player to allow calling votes again. If a player with novote disconnects the player’s IP will be temporarily banned (see section 2.11).

This is a level 4 admin command.

### \passvote
If there is a vote in progress, it succeeds. This is a level 2 admin command.

### \pay <ammount>
Use this to give another player <ammount> credits (see section 2.4). You have to stand close to, facing the receiving player.

### \place <classname> <dist> [field,value],[field,value],....
A manual could be written on this command alone. It is a generic command for placing any type of entity on the map, with any option. <classname> is the entity class name. The entity will appear at distance <dist> from the surface you aim at when issuing the command. See the appendix for some examples on how to use this command.

This is a level 1 admin command.

### \placecannon
Spawns an emplaced gun infront of you. 

This is a level 2 admin command.

### \placemodel <path> [zoffset] [radius]
Place a model on the map. The options [zoffset] and [radius] govern the size of the bounding box for the model (this is what makes it solid), and defaults to 0 and 16 respectively. The number of different models that can be loaded are limited both server side and client side to 512 (a model that has been loaded stays loaded even if you remove it), and the total number of entities is limited to 1024. Also every model you place puts an additional strain on the server. Don’t overdo this.

This is a level 1 admin command.

### \placemoneydisp
This places a money_dispenser (see section 2.4). The money dispenser will appear in the spot where you issued the command, facing the direction you did, as soon as you move away.

This is a level 1 admin command.

### \placerandomspot
This places a random_spot where you are standing. These are used as random locations to spawn stuff at. Currently they are only used for the money_stash (see section 2.4).

This is a level 1 admin command.

### \playerinfo [player]
Displays information about the player [player]. If no argument is provided, information about all players on the server will be displayed in a list. A player that is authenticated as admin (see section 2.1.2). will be listed with a star in the far right of the row. A unique reference number is included that can be specified when issuing other commands in place of the full player name

This is a level 4 admin command.

### \playerspawnpoint
This will place a spawn point for players. This is where a player will spawn when entering the game, and after dying. If you have placed at least one player spawn point (info_player_deathmatch) on the map and saved it so that it loads up with the map (see section 2.8), the original player spawn point(s) will be removed when the map is loaded. It is highly recommended that spawn points are placed higher than ground level to avoid player collisions.

This is a level 1 admin command.

### \playfx <path>
Plays an effect located at your eyes in the direction you are facing. The number of effects that can be loaded are limited both client side and server side to 64. An effect that you play stay loaded until you load a new map. Rather strange and unwanted behavior is to be expected if you exceed this limit.

This is a level 1 command.

### \playmusic <path>
Plays a sterio music file to all players replacing the currently active song. 

This is a level 1 admin command.

### \playsnd <path> 
Audibly plays a sound-file in your general vicinity whilst animating your model’s mouth to indicate that the voices originate from your character. The number of sounds that can be loaded is limited both client side and server side to 256. A sound you play stay loaded until you load a new map. Undesirable behavior is to be expected if you exceed this limit, therefore it is not recommended to use the command exhaustively.

This is a level 1 admin command.

### powerup <number>
There are 15 powerups in the game. This command gives you one of these powerups for 30 seconds. The powerups are:
```
1 	Quad damage (not implemented)
2 	Battle suit
3 	Pull
4 	Red flag
5 	Blue flag
6 	Neutral flag
7 	Shield hit
8 	Speed burst (only the visual effect)
9   	Disintegrate
10  	Speed (only the visual effect)
11  	Cloak
12 	Force enlightened light
13 	Force enlightened dark
14 	Force boon
15 	Ysalamiri
```

This is a level 1 admin command.

### \profession [profession]
Choose a profession. When choosing a profession a player’s level is set to 1 and all score and half the credits will be lost. If no argument is provided, the current profession and all available professions will be displayed.

### \redspawnpoint
Place a player spawn point for the red team. This is where the players in the red team will start in a team game.

This is a level 1 admin command.

### \regnick <new password>
Register your nick name so that noone else can use it. This will create an ac- count. A user identification number (UID) will be displayed in the console. Use this when you log into the account with the command \login <UID> <password>. For more information on accounts see section 2.2.

### \resetforce [cost]
Unlearn all your force powers. If no argument is provided the cost is displayed. 

This command is only available to players with the profession jedi/sith.

### \resetskill [cost]
Unlearn all your skills. If no argument is provided the cost is displayed. 

This command is only available to players with the profession mercenary.

### \say_admins <message>
Say <message> so that only other admins can hear it. In non team game types, for admins, this will be used instead of say team.

This is a level 4 admin command.

### \say_buddies <message>
Say <message> so that only your buddies can hear it. In non team game types, this will be used instead of say team if there is anyone in your list of buddies.
    
### \say_close <message>
Say <message> so that only players who are standing close to you can hear it. In non team game types, this will be used instead of say team if there is noone in your list of buddies.

### \scale [player] <size>
Scale the player [player] to the size <size> in percent. If the argument [player] is not provided you will be scaled. The maximum scale is 1023. If you set <size> to 0, scaling will be turned off (this is preferable to setting it to 100).

This is a level 3 admin command.

### \show <classname|entitynumber>
The entity/entities will emit a blue beam upwards. Use this if you need to see the location of invisible entities such as random_spot or info_player_deathmatch. 

This is a level 1 admin command.

### \showhealth
Display the health of the entity you aim at (not all entities has health). This is a level 2 admin command.

### \shutup [player]
Mute the player [player]. If no argument is provided the player you aim at will be muted. If a muted player disconnects the player’s IP will be temporarily banned (see section 2.11).

This is a level 4 admin command.

### \skill [skill]
Raise the skill with number [skill] one level. If no argument is provided, all skills and their numbers will be listed.

This command is only available to players with the profession mercenary.

### \spawn <NPC_vehicle>
Spawns the vehicle <NPC_vehicle>. 

This is a level 3 admin command.
  
### \spawner <NPC num|’list’|’remove’ num>
Add a spawner spawning the NPC (vehicle or non vehicle) <NPC> until the num- ber of such NPC:s there are on the map is <num>. It will then stop spawning until one of the NPC:s are destroyed. The spawner will spawn indefinitely, but there will be at most <num> spawns at one time. You can list all spawn- ers on the map with the command \spawner list. Next to each spawner it’s entity number will be displayed. To remove a spawner use the command \spawner remove <num> where <num> is the spawner’s entity number.

This is a level 2 admin command.

### \stats
Displays some information about your account (see section 2.2). You need to be registered to use this command.

### \strip <player> <’items’|’weapons’|’force’|’all’>
The player <player> will be releived of all items, weapons, force powers or all of it.

This is a level 3 admin command.

### \teamother <player> <team>
Put the player <player> in the team <team>.
	
This is a level 3 admin command.

### \tmpban [player]
Kick and temporarily ban the player [player]. If no argument is provided the player you are aiming at will be kicked. See section 2.11 for more information about temporary bans.

This is a level 3 admin command.

### \trace [number|property value]
Displays some information about the targeted entity/entities. If a number is provided, information on the entity with that entity number will be displayed. If a property name and a value is provided, information on all entities with a matching value for that property will be displayed. Only string value properties can be used. If no argument is provided, information on the solid entity that you are aiming at will be displayed.

This is a level 1 admin command.

### \undoforce
Undo the last selection made with the command \forcelevel. You can only undo the selections made since you last pressed any buttons (eg attack), and this must be done before disconnecting or map change/restart occurs.

This command is only available to players with the profession jedi/sith.

### \undoskill
Undo the last selection made with the command \skill. You can only undo the selections made since you last pressed any buttons (eg attack), and this must be done before disconnecting or map change/restart occurs.

This command is only available to players with the profession mercenary.

### \useent [number]
The entity with entity number [number] will be used (if it can be used). If no argument is provided the solid entity you are aiming at will be used.

This is a level 1 admin command.

### \worthy
Displays a list of all connected players. For each player the following will be displayed ’W: [#] L: [#]’ where [#] are numbers. The first number is how many points you would receive should you win, and the second number is the ammount of points you would lose should you lose a duel against that player. For more information see 2.2.2.


### \ysalamiri
This command can only be used if the player has an ysalamiri. Only one ysalamiri can be carried at a time. When using the command the player will be bestowed with the powerup ysalamiri for an ammount of time determined by the level of the ’ysalamiri blast’ skill (see section 2.2.1). At level 4 and 5 the blast will also affect other players that are close enough.

This command is only available to players with the profession mercenary.

## 3.2 Server Commands

### addtobank <ammount>
Add <ammount> credits to the bank.

### admins
The command will list all authenticated admins that are currently on the server. Next to every name their admin level will be displayed.

### announce <time> <msg>
The message <msg> will be displayed for <time> seconds in the center of the screen for all players.

### authother <player> <lvl>
Authenticates the player <player> for admin level <lvl>. The player will stay authenticated until re-authenticated, or until the player disconnects. To remove admin rights for a player set the level to 0.

### callvote <vote>
Call a vote. The name of the vote caller displayed ingame will be the name in g_nameForServer.

### chpasswd <nick> <new password>
Change the password for a registered player.

### clearcash
Take away all money (see section 2.4) from all registered players.

### clearlevels
Set the level (see section 2.5) of all non admin accounts to 1.

### clearlevelselect [nick]
Clear all skill or force levels for the account [nick]. If no argument is provided, the skill and force levels for all players will be cleared.

### clearmap
Remove all entities placed on the map (see section 2.8).

### clearnicks
Remove all non admin accounts (see section 2.2).

### clearscore
Set the persistant score (see section 2.2.2) of all registered players to 10.

### cleartime
Set the time of all accounts (see section 2.2) to 0.

### cleartmpbans
Remove all temporary bans (see section 2.11).

### deletenick <nick>
Remove the account with the name or UID <nick>.

### entitylist [’remove’] ['number'|'classname']
This is not really a Lugormod command, but I have altered it to give it some more functionality. The command will list the entity with the entity number [number], or all entities with the entity class name [classname]. If the argument ’remove’ is provided, the entities will be removed instead of listed. This is the only way to remove some entities. There might be unexpected results from removing an entity, use this with care.

### hicredits
Display a list of the top ten wealthiest players (see section 2.4).

### hilevel
Display a list of the top ten players with the highest level (see section 2.5).

### hiscore
Display a list of the top ten players with the highest persistant score (see section 2.2.2).

### hitime
Display a list of the top ten players who has spent the most time on the server.

### jail <player>
Put the player <player> in jail, or release the player if already in jail. For this to work you need to have placed at least one jail spawn point. This is done with the ingame command \jailspawnpoint. The jailed player will spawn at such a spawnpoint. Use locations on the map from which you can’t escape. If a jailed player disconnects the players IP will be temporarily banned (see section 2.11).

### killother <player>
The player <player> will die.

### listadmins
This command will display a list of all accounts that has been made into admin accounts (see section 2.2). The name and the admin level will be listed.

### loadit <filename>
Load a file with placed entities for a map. See section 2.8 for more informoation.

### location <player>
This will tell you the location of player <player>. This will only work if a botlocations file exists for the map. There are some included with the mod in the lugormod/botlocations folder. It is a plain text file. Each line in the file lists the coordinates for the location and a string associated with it.

### makestash
If there is at least one money_dispenser on the map, this will cause a money_stash to spawn (if there isn’t one already). See section 2.4 for more information about money and stashes.

### nocaps <player>
Whenever the player <player> says something, any upper-case letter will be changed into a lower-case letter. The command toggles this setting, simply use it again on a player to turn it off. Use this on players who can’t seem to find the caps lock key after hitting it by mistake. If a player with nocaps disconnects the player’s IP will be temporarily banned (see section 2.11).

### novote <player>
The player <player> will not be able to call any votes. This command toggles the setting. Simply use it again on a player to allow calling votes again. If a player with novote disconnects the player’s IP will be temporarily banned (see section 2.11).

### playerinfo <player>
Displays information about the player <player>. If no argument is provided, information about all players on the server will be displayed in a list. A player that is authenticated as admin (see section 2.1.2) will be listed with a star in the far right of the row.

### saveit <filename>
Save all entities placed on the map in a file. See section 2.8 for more information.

### savenicks
Force a save of all the registered accounts (see section 2.2). The accounts are saved to a file called nicks.lmd that resides in the folder ’lugormod/reggednicks’. This is a plain text file and can be edited manually, but for this to have any effect you need to stop the server before editing the file.

### say <message>
Say something to the players. The name displayed in the game will be the name in g_nameForServer.

### say_admins <message>
Say <message> so that only other admins can hear it.

### sayasbot <bot> <message>
Have the bot <bot> say <message>.

### shutup <player>
Mute the player <player>. If a jailed player disconnects the player’s IP will be temporarily banned (see section 2.11).

### stats <nick>
Display some information about the account with the name or UID <nick>. Among other things, last login and the registration code will be displayed.

### tell
say <player> <message>
Say something to the player <player>. The name displayed in the game will be the name in g_nameForServer.

### tmpbans
Display a list of all temporary bans (see section 2.11).

### trace <'number'|'property value'>
Displays some information about the targeted entity/entities. If a number is provided, information on the entity with that entity number will be displayed. If a property name and a value is provided, information on all entities with a matching value for that property will be displayed. Only string value properties can be used.

### uptime
Display the time since the server was started.

## 3.3 Cvars

### g_allowBlackNames
In the original game, players are not supposed to be able to use the color black at all in their names. In the Lugormod they can’t unless this is set to anything other than 0.

Defaults to ’0’
 
### g_allowVote
This is not really a Lugormod cvar, but I have made it into a bit mask with the following flags:
```
1 	all
2     	map_restart
4     	nextmap
8     	map
16    	g_gametype
32    	kick
64    	clientkick
128   	g_dowarmup
256   	timelimit
512   	fraglimit
1024  	g_gamemode
```

This way the different votes can be enabled separately. 

Defaults to ’1’

### g_autoRandomSpots
If set to anything other than 0, random spots will be placed automatically on the map.

Defaults to ’1’

### g_checkSkin
If set to anything other than 0 the skin a player chooses will be checked to see if it is valid. This will remove the possibility to have invisible body parts, or to have a grey buggy looking skin.

Defaults to ’1’

### g_chickenTime
This is the time in seconds until a player who has lost points because of the chicken rule can lose points this way again. If it is set to 0 the chicken rule is disabled. For more information about the chicken rule see section 2.2.2. 

Defaults to ’60’

### g_cmdDisable
This is a bit mask for disabling Lugormod commands. The following flags are available:
```
1 	regnick
2 	Special duels (training, force etc)
4 	drinkme and eatme
8 	dropwp, drophi and dropjp 16 fnord
32 	emote
64 	ionlyduel
128 	money
256 	Professions
```

Default to ’0’

### g_cmdLvlFile
This is the name of a file containing re-defenitions of what admin levels the Lugormod ingame commands are. This is located in /lugormod/<file.cfg>. Each row in the file is a command name - level pair. If you want to set the level for the commands blowup, drinkme and dragon all to 3, this is what you would type in your file:
```
"blowup" 	3 
"drinkme" 	3 
"dragon" 	3
```

Now all level 3, 2 and 1 admins will be able to use those commands. 

Defaults to not set.

### g_creditsInBank
This is the number of credits that the bank will start out with. 

Defaults to ’500000’

### g_disableBail
If set to anything other than 0 players will not be able to eject from an unlanded fighter.

Defaults to ’0’

### g_disableSpec
This is a bit mask with two flags, 1 and 4. If set to 1, moving in free spectate mode is disabled. If set to 4, follow spectate mode will be disabled. If set to 1 + 4 = 5 both moving in free mode and using follow mode will be disabled. This setting only applies to game types FFA and Team FFA.

Defaults to ’0’

### g_dontLoadNPC
The name of this cvar is misleading. It disables the loading of NPCs and the routes for the NPCs, but it also makes single player maps more compatible with the multi player server. Flags and names for entities are different in single player maps than in multi player maps. Setting this to anything other than 0 will make the server try to fix some of these problems. When playing a single player map, set this to 1, otherwise set it to 0.

Defaults to ’0’

### g_duelForcePowerDisable
This is a bitmask for disabling force powers in the Duel and Power Duel game types. It works exactly like the cvar g_forcePowerDisable.

Defaults to ’0’
      
### g_enterMotd
If set, this message will be displayed centered on the screen when a player enters the game. The time the message is displayed is determined by the cvar g_motdDispTime.

Defaults to not set.

### g_fixForce
Some forces are too weak to be of any use, and some are too powerful. This is a bit mask, selecting to what force powers a fix is to be applied. There are currently fixes available for the force powers:
```
256	Rage
16384 	Sense 
```

Defaults to ’0’

### g_fixShields
If this is set to anything other than 0 the shield emitters (item_shield) will be more powerful in FFA.

Defaults to ’0’

### g_gameMode
This is the game mode that is going to be played. The seven available game modes are:
```
0 Normal
1 Instant Gib
2 Rocket Arena
3 Sniper Arena
4 Melee Arena
5 Super Merc/Jedi
6 Instant Disrupt
```

To these game modes you can add any number of the following options by adding the number or numbers of the options to the number of the game mode.
```
8 	Low Gravity
16 	With Force Jump
32 	Start with JetPack
64 	Start with Grappling Hook 128 Start with Teleporter Gun 256 Respawn timer (20 sec)
```

For example, if you want instant gib with low gravity and a respawn counter you would set g_gameMode to 1 + 8 + 256 = 265 (this setting is very suitable for the CTF game type, try it out).
Players can call a vote for these game modes with the command 
```
\callvote g_gamemode <number>.
```

For more information about the game modes, see section 2.9 

Defaults to ’0’
    
### g_grapplingHook
If set to anything other than 0, the stun baton will double as a grappling hook. If set to 2 it will only be a grappling hook. See section 2.3.1 for more information. 

Defaults to ’0’

### g_jmforcelevel
The Jedi Master will get this level (0-3) in all force powers in the Jedi Master game type.

Defaults to ’3’

### g_jmhealthbar
If set to anything other than 0, when aiming at the Jedi Master in the Jedi Master game type, a health bar showing the Jedi Master’s health will appear. 

Defaults to ’0’

### g_jmkillhealth
This is how much health the Jedi Master will get for killing someone in the Jedi Master game type. If set to anything other than 0 the Jedi Master’s health will slowly count down until it reaches 0, and the only way for the Jedi Master to heal will be to kill other players.

Defaults to ’0’

### g_jmstarthealth
When becoming the Jedi Master in the game type Jedi Master the player’s health will be set to this.

Defaults to ’100’

### g_jmsaberDamageScale
The damage done by the Jedi Master’s saber in the Jedi Master game type will be multiplied by this.

Defaults to ’2’

### g_jmsaberreplace
Because there are no maps for the Jedi Master game type, the saber must be placed on a normal FFA map somehow. This can be done automatically by setting the cvar g_jmsaberreplace. A pick up on the map will then be randomly selected and replaced by the saber. The cvar g_jmsaberreplace governs what can be replaced by the saber.
```
1 	weapons
2 	ammo
4 	armor
8 	health
16	powerup
32 	holdable item
```

Add up the numbers of the types of items you want to be used as possible positions for the Jedi Master saber. This is only done if there isn’t already an info_jedimaster_start on the map.

Defaults to ’1’

### g_kingTime
This is the time in seconds after the King (see section 2.6) last dueled someone until the King will lose the crown. If set to 0 the king will never run out of time. 

Defaults to ’600’

### g_maxVoteCount
The maximum number of votes a player can call. 

Defaults to ’3’

### g_meditateProtect
The time in milli seconds until a player who started meditating becomes pro- tected. The player will be protected from everything. If set to 0 protection by meditating is disabled. Meditate only protects in the FFA game type, and only when not in a private duel.

Defaults to ’0’

### g_motdDispTime.
Time in seconds to display g_enterMotd.

Defaults to '5'

### g_nameForServer
This is the name displayed when you use the server commands say, tell and callvote.

Defaults to ’server’

### g_noVoteTime
This is the ammount of time in minutes until a vote can be called after a map change.

Defaults to ’5’

### g_pickupDisable
Disables pick ups on the map according to it’s type. This is a bit mask with the following flags:
```
1 	weapons
2	ammo
4 	armor
8	health
16	powerup
32	holdable items
```

Disabled pick ups will be transformed into random spots (see section 2.4). 

Defaults to ’0’

### g_privateDuel
This isn’t really a Lugormod cvar, but I have made it into a bit mask with the following flags:
```
1 	Private duels enabled
2 	Multiple duels enabled
4 	Full health at duel start
8 	Full armor at duel start
16 	Full force power at duel start
32 	Full health at duel end
64 	Full armor at duel end
128	Full force power at duel end
256 	Force saber on at duel start
512 	Force bow at duel start
4096	King mode on
8192 	Only score frags in private duels in FFA 16384 Disable severing of duels
```

Defaults to '289'

### g_profanityFile
This is the name of the configuration file for the profanity filter. The file is a regular text file listing first all words that are to be filtered followed by a section with measures to be taken.
```
badword
verybadword 
reallybadword 
extremlybadword
{
	warn "Mind your language\nplease"
	censor "I told you not to talk like that"
	mute "That’s it buddy, you have been muted" 
}
```

Each line in the section of measures is an action possibly followed by a message. If there is a message it will be displayed in the center of the screen for the offending player. The first time a player uses one of the disallowed words, the first line of actions will be used, the second time the second will be used and so on. When the last action is reached it will be used over and over. The possible measures are:
```
warn 	Does nothing.
censor 	The message is removed.
mute 	The message is removed and the player is muted.
jail 	The message is removed and the player is jailed.
kick 	The message is removed and the player is kicked.
ban 	The message is removed and the player is kicked and temporarily banned.
```

If g_profanityFile is not set, the filter is disabled.

Defaults to not set

### g_scorePlums
If set to anything other than 0 a score plum will be displayed over a players head when the player score points.

Defaults to ’0’

### g_tmpBanTime
This is the time in minutes a temporary ban lasts. See section 2.11 for more information about temporary bans.

Defaults to ’20’

### g_voteFix
Normally when voting, anyone who doesn’t vote will be counted as having voted no. If this is set to anything other than 0 only voting players will be counted if voting for anything other than kicking a player.

Defaults to ’0’
   
## Appendix A

### A.1.1 Placing a turret
The entity classname of a turret is turret_G2. The type of turret you get depends on the spawnflags. There are two types of turrets you can get, a small turret hanging from roof, or the huge death star like turbo laser. By default you get the small one, but by setting the spawn flag 4 you will get the big one. Here is an example for placing a small one (aim at a ceiling):
```
\place turret_G2 0
```

and to place a big one (aim at the ground):
```
\place turret_G2 0 spawnflags,4
```

This is how you place a turret with a switch. First we place the turret. Look at the spot where you want the turret to be, and type:
```
\place misc_turretG2 0 spawnflags,13,targetname,bigcannon,angle,90
```

Then we place the switch. Look at a wall where you want to place the switch, and type:
```
\place misc_model_breakable 0 parm1,4,parm2,1000,wait,2, spawnflags,193,target,bigcannon,model,map_objects/desert/switch3, usescript,common/switch_on,angle,90
```

To rotate the turret or the switch just change the number after ’angle’ (I just set it to 90 as an example). 

These are all the available spawn flags and options for the turret_G2:
```
Spawnflags:
1	Starts off
2	make it rest on a surface/floor instead of hanging from the ceiling
4	Big-ass, Boxy Death Star Turbo Laser version
8	will respawn after being killed (use count)
16	Turret will aim ahead of moving targets ("lead" them)
32	show on radar
64	target fighters
128	target ground vehicles 256 target armed players

Options:
count 		- if CANRESPAWN spawnflag, decides how long it is before gun respawns (in ms) - defaults to 20000 (20 seconds)
customscale 	- custom scaling size. 100 is normal size, 1024 is the max scaling. this will change the bounding box size, so be careful of starting in solid!
dmg 		- How much damage each shot does (default 5)
health 		- How much damage it can take before exploding (default 100)
icon	 	- icon that represents the objective on the radar
paintarget 	- target to fire off upon being hurt
painwait 	- ms to wait between firing off pain targets
radius 		- How far away an enemy can be for it to pick it up (default 512) wait - Time between shots (default 150 ms)
random 		- random error (in degrees) of projectile direction when it comes out of the muzzle (default is 2)
shotspeed 	- the speed of the missile it fires travels at (default is 1100 for regular turrets, 20000 for TURBOLASERS)
splashDamage 	- How much damage the explosion does
splashRadius 	- The radius of the explosion
targetname 	- Toggles it on/off
target 		- What to use when destroyed
target2 	- What to use when it decides to start shooting at an enemy showhealth - set to 1 to show health bar on this entity when crosshair is over it

teamowner 	- crosshair shows green for this team, red for opposite team
	0 - none
	1 - red
	2 - blue

alliedTeam 	- team that this turret won't target
	0 - none
	1 - red
	2 - blue

teamnodmg - team that turret does not take damage from
	0 - none
	1 - red
	2 - blue
```

### Placing a jump pad

Look at the spot where you want the the jump pad to be and type:
```
\place trigger_push 0 maxs,100 100 20,mins,-100 -100 0,spawnflags,256, target,jumpto
```

Now look at the spot you want people to jump to and type:
```
\place info_notnull 20 targetname,jumpto
```

### Placing a teleporter

Look at the spot where you want the the teleporter to be and type:
```
\place trigger_teleport 0 maxs,100 100 100,mins,-100 -100 0,target,teleto
```

Now look at the spot you want people to be teleported to and type:
```
\place misc_teleporter_dest 20 targetname,teleto
```

## References
```
item_ammodisp
item_binoculars
item_eweb_holdable
item_force_boon
item_force_enlighten_dark
item_force_enlighten_light
item_healthdisp
item_jetpack
item_medpac
item_medpac_big
item_medpak_instant
item_seeker
item_sentry_gun
item_shield
item_shield_lrg_instant
item_shield_sm_instant
item_ysalimari
```
```
weapon_bryar_pistol //This is a teleporter in the lugormod weapon_blaster
weapon_stun_baton // doubles as grappling hook in the Lugormod weapon_melee
weapon_saber
weapon_blaster_pistol
weapon_blaster
weapon_bowcaster
weapon_disruptor
weapon_repeater
weapon_flechette
weapon_demp2
weapon_concussion_rifle
weapon_rocket_launcher
weapon_thermal
weapon_trip_mine
weapon_det_pack
weapon_emplaced
```
```
ammo_all
ammo_blaster
ammo_detpack
ammo_force
ammo_metallic_bolts
ammo_powercell
ammo_rockets
ammo_thermal
ammo_tripmine
```
```
team_CTF_blueflag
team_CTF_neutralflag
team_CTF_redflag
```

## Acknowledgements
I would like to thank all the players on my server and all the people on my forums helping me with ideas and finding bugs. I especially would like to thank Storm for being a great help in anwering questions in the forums, and even writing a faq for the Lugormod. 

I would also like to thank the admins on my server for helping me look after it. 

Thank you Steve Jackson of Steve Jackson Games (http://www.sjgames.com) for letting me use the fnord program in my mod.

### c 2004-2005 David Sjö̈strand
