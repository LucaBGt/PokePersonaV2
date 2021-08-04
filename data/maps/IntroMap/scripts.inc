IntroMap_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IntroMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

IntroMap_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_GAMESTATE, 0, Prepare
	.2byte 0


Prepare::
	lock
	setflag FLAG_SYS_PREVENT_MAP_FADE_IN
	msgbox Prepare_Text_0, MSGBOX_AUTOCLOSE
	warpsilent MAP_INTERROGATION_ROOM, -1, 7, 10
	setvar VAR_GAMESTATE, 1
	end


Prepare_Text_0:
	.string "Test$"
