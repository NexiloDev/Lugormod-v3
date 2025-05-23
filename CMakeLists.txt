cmake_minimum_required(VERSION 3.5)

set(CMAKE_CONFIGURATION_TYPES Release Debug CACHE STRING INTERNAL FORCE)

# Option Defaults
option(FORCE_32 "Enable 32 bit compile" ON)
option(CUSTOM_OUTPUT_DIR "Customize Output Directory" OFF)

if(UNIX)
	# Prevent breaking the proxy patcher with over optimization, it doesn't like something in level 3...
#	set( CMAKE_C_FLAGS_RELEASE "-O2 -g -ggdb" CACHE STRING "Flags used by the compiler during release builds" )
#	set( CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb" CACHE STRING "Flags used by the compiler during release builds" )
	set( CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "Flags used by the compiler during release builds" )
	set( CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "Flags used by the compiler during release builds" )
endif()


project(Lugormod-v3)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)

if(FORCE_32)
	message("Forcing 32bit compilation")
endif()

set(GAME_SRC
	game/tri_coll_test.c 
	game/w_force.c 
	game/w_saber.c 
	game/WalkerNPC.c 
	game/ai_main.c 
	game/ai_util.c 
	game/ai_wpnav.c 
	game/AnimalNPC.c 
	game/bg_g2_utils.c 
	game/bg_lib.c 
	game/bg_misc.c 
	game/bg_panimate.c 
	game/bg_pmove.c 
	game/bg_saber.c 
	game/bg_saberLoad.c 
	game/bg_saga.c 
	game/bg_slidemove.c 
	game/bg_vehicleLoad.c 
	game/bg_weapons.c 
	game/FighterNPC.c 
	game/g_active.c 
	game/g_arenas.c 
	game/g_battleground.c 
	game/g_bot.c 
	game/g_client.c 
	game/g_cmds.c 
	game/g_combat.c 
	game/g_defender.c 
	game/g_exphysics.c 
	game/g_ghost.c 
	game/g_ICARUScb.c 
	game/g_items.c 
	game/g_lingoCleaner.c 
	game/g_log.c 
	game/g_main.c 
	game/g_mem.c 
	game/g_misc.c 
	game/g_missile.c 
	game/g_mover.c 
	game/g_nav.c 
	game/g_navnew.c 
	game/g_object.c 
	game/g_saga.c 
	game/g_session.c 
	game/g_spawn.c 
	game/g_strap.c 
	game/g_svcmds.c 
	game/g_syscalls.c 
	game/g_target.c 
	game/g_team.c 
	game/g_timer.c 
	game/g_trigger.c 
	game/g_turret.c 
	game/g_turret_G2.c 
	game/g_utils.c 
	game/g_vehicles.c 
	game/g_vehicleTurret.c 
	game/g_weapon.c 
	game/gls_crashreport.c 
	game/Lmd_Accounts.c 
	game/Lmd_Accounts_Core.c 
	game/Lmd_Accounts_CustomSkills.c 
	game/Lmd_Accounts_Friends.c 
	game/Lmd_Accounts_Property.c 
	game/Lmd_Accounts_Stats.c 
	game/Lmd_Actor_Core.c 
	game/Lmd_Actor_Entities.c 
	game/Lmd_Admin.c 
	game/Lmd_API_Accounts.c 
	game/Lmd_API_Commands_Auths.c 
	game/Lmd_API_Entities.c 
	game/Lmd_API_Memory.c 
	game/Lmd_API_Professions.c 
	game/Lmd_Arrays.c 
	game/Lmd_Bans.c 
	game/Lmd_Checksum.c 
	game/Lmd_Command_Confirm.c 
	game/Lmd_Command_Interact.c 
	game/Lmd_Commands.c 
	game/Lmd_Commands_Auths.c 
	game/Lmd_Commands_Cheats.c 
	game/Lmd_Commands_Core.c 
	game/Lmd_Commands_NPC.c 
	game/Lmd_Console.c 
	game/Lmd_Crafting.c 
	game/Lmd_CrashReport.c 
	game/Lmd_Credits.c 
	game/Lmd_Creditshunt.c
	game/Lmd_Crosshair.c  
	game/Lmd_Data.c 
	game/Lmd_Entities_Commands.c 
	game/Lmd_Entities_Core.c 
	game/Lmd_Entities_Ents.c 
	game/Lmd_Entities_Groups.c 
	game/Lmd_Entities_Load.c 
	game/Lmd_Entities_Logical.c 
	game/Lmd_Entities_Spawner.c 
	game/Lmd_Factions_Old.c 
	game/Lmd_Force_Core.c 
	game/Lmd_Force_Dark.c 
	game/Lmd_Force_Light.c 
	game/Lmd_Force_Neutral.c 
	game/Lmd_Inventory_Core.c 
	game/Lmd_Inventory_Core_AccBased.c 
	game/Lmd_Inventory_General.c 
	game/Lmd_Inventory_Quest.c 
	game/Lmd_IPs.c 
	game/Lmd_KeyPairs.c 
	game/Lmd_King.c 
	game/Lmd_Locations.c 
	game/Lmd_Main.c 
	game/Lmd_mem.c 
	game/Lmd_Misc.c 
	game/Lmd_Missile.c 
	game/Lmd_ParseField.c 
	game/Lmd_Parser.c 
	game/Lmd_Patcher.c 
	game/Lmd_PlayerActions.c 
	game/Lmd_PlayerGuide.c 
	game/Lmd_Prof_Core.c 
	game/Lmd_Prof_Jedi.c 
	game/Lmd_Prof_Jedi_Crafting.c 
	game/Lmd_Prof_Merc.c 
	game/Lmd_Prof_Other.c 
	game/Lmd_Prof_Tech.c 
	game/Lmd_Prof_Tech_Old.c 
	game/Lmd_Property.c 
	game/Lmd_RandomChat.c 
	game/Lmd_RandomSpot.c 
	game/Lmd_Script.c 
	game/Lmd_SetSaber.c
	game/Lmd_StashZone.c 
	game/Lmd_Time.c 
	game/lmd_turret.c 
	game/Lmd_Variables.c 
	game/Lmd_Weapons_Core.c 
	game/naken.c 
	game/NPC.c 
	game/NPC_AI_Atst.c 
	game/NPC_AI_Default.c 
	game/NPC_AI_Defender.c 
	game/NPC_AI_Droid.c 
	game/NPC_AI_GalakMech.c 
	game/NPC_AI_Grenadier.c 
	game/NPC_AI_Howler.c 
	game/NPC_AI_ImperialProbe.c 
	game/NPC_AI_Interrogator.c 
	game/NPC_AI_Jedi.c 
	game/NPC_AI_Mark1.c 
	game/NPC_AI_Mark2.c 
	game/NPC_AI_MineMonster.c 
	game/NPC_AI_Rancor.c 
	game/NPC_AI_Remote.c 
	game/NPC_AI_Sand_creature.c 
	game/NPC_AI_Seeker.c 
	game/NPC_AI_Sentry.c 
	game/NPC_AI_Sniper.c 
	game/NPC_AI_Stormtrooper.c 
	game/NPC_AI_Utils.c 
	game/NPC_AI_Wampa.c 
	game/NPC_behavior.c 
	game/NPC_combat.c 
	game/NPC_goal.c 
	game/NPC_misc.c 
	game/NPC_move.c 
	game/NPC_reactions.c 
	game/NPC_senses.c 
	game/NPC_sounds.c 
	game/NPC_spawn.c 
	game/NPC_stats.c 
	game/NPC_utils.c 
	game/q_math.c 
	game/q_shared.c 
	game/qtalk.c 
	game/SpeederNPC.c 
	
	disasm/assembl.c
	disasm/disasm.c
	disasm/disasm.h
	disasm/asmserv.c
	)

set(SHARED_HEADER game/ai.h
                  game/animdefs.h
                  game/anims.h
                  game/b_*.h
                  game/bg_*.h
                  game/q_*.h
                  game/g_team.h
                  game/g_public.h
                  cgame/animtable.h
                  ghoul2/*.h
                  qcommon/*.h)

file(GLOB_RECURSE GAME_HEADER game/*.h ${SHARED_HEADER})

source_group("Source Files" REGULAR_EXPRESSION ".+\\.(c|cpp)")
source_group("Header Files" REGULAR_EXPRESSION ".+\\.(h|hpp)")

set(DEFINITIONS 
	_JK2
	$<$<CONFIG:Debug>:_DEBUG> $<$<CONFIG:Debug>:DEBUG> 
	$<$<CONFIG:Release>:FINAL_BUILD>)


if(WIN32)
	set(TARGET_SUFFIX x86${CMAKE_SHARED_LIBRARY_SUFFIX})
    #set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2")
	#set(CMAKE_CXX_FLAGS_DEBUG "/MT /Od")
else()
	if(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
		set(TARGET_SUFFIX arm${CMAKE_SHARED_LIBRARY_SUFFIX})
	elseif(FORCE_32 OR CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$")
		if(APPLE)
			set(TARGET_SUFFIX x86${CMAKE_SHARED_LIBRARY_SUFFIX})
		else()
			# e.g. Linux
			set(TARGET_SUFFIX i386${CMAKE_SHARED_LIBRARY_SUFFIX})
		endif()
	elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^x86.64$")
		set(TARGET_SUFFIX x86_64${CMAKE_SHARED_LIBRARY_SUFFIX})
	elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "powerpc")
		set(TARGET_SUFFIX ppc${CMAKE_SHARED_LIBRARY_SUFFIX})
	elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "powerpc64")
		set(TARGET_SUFFIX ppc64${CMAKE_SHARED_LIBRARY_SUFFIX})
	else()
		set(TARGET_SUFFIX ${CMAKE_SYSTEM_PROCESSOR}${CMAKE_SHARED_LIBRARY_SUFFIX})
	endif()
endif()

if (WIN32)
    set(RESOURCEFILES
        "win32/AutoVersion.h"
        "win32/resource.h"
        "win32/JK2game.rc"
    )
endif()

if(WIN32)
set(GAME_SRC ${GAME_SRC} ${GAME_HEADER} ${RESOURCEFILES})
else()
set(GAME_SRC ${GAME_SRC} ${GAME_HEADER})
endif()


if(WIN32)
		set(STATIC_LIBRARIES
			dbghelp.lib
			winmm.lib
			psapi.lib
			)
endif()


add_library(GameLibrary SHARED ${GAME_SRC})
if (FORCE_32)
	set_target_properties(GameLibrary PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif()
set_target_properties(GameLibrary PROPERTIES PREFIX "")
set_target_properties(GameLibrary PROPERTIES SUFFIX ${TARGET_SUFFIX})
set_target_properties(GameLibrary PROPERTIES OUTPUT_NAME jampgame)
set_target_properties(GameLibrary PROPERTIES PROJECT_LABEL "Game Library")

#target_properties(TARGET GameLibrary PROPERTY C_STANDARD 90)
if(WIN32)
	target_link_libraries(GameLibrary ${STATIC_LIBRARIES} )
endif()

target_compile_definitions(GameLibrary PUBLIC "_GAME" "QAGAME" "GAME" "LMD_NEW_FORCEPOWERS" "LMD_NEW_WEAPONS" "MISSIONPACK" "_JK2" "JK2AWARDS" ${DEFINITIONS})

# Cmake Output
if (CUSTOM_OUTPUT_DIR)
if (WIN32)
set(ModDirDebug "${PROJECT_SOURCE_DIR}/ftp/GameData/lugormod")
set(ModDirRelease "${PROJECT_SOURCE_DIR}/ftp/GameData/lugormod")
else()
set(ModDirDebug "${PROJECT_SOURCE_DIR}/ftp/GameData/lugormod")
set(ModDirRelease "${PROJECT_SOURCE_DIR}/ftp/GameData/lugormod")
endif()

if(WIN32)
set_target_properties(GameLibrary PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${ModDirDebug}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${ModDirRelease}")
else()
set_target_properties(GameLibrary PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${ModDirDebug}"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${ModDirRelease}")
endif()
endif()