OakLab_Intro_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OakLab_Intro_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

OakLab_Intro_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, OakLab_Intro_Init
	.2byte 0


OakLab_Intro_Init::
	setobjectxy 1, 19, 0
	setobjectxy 6, 8, 17
	applymovement 6, CommonMovement_FaceLeft
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE_IN
	applymovement OBJ_EVENT_ID_PLAYER, OakLab_PlayerEnter
	waitmovement 0
	delay 30
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteExclamation
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_Cam_ToScene
	waitmovement 0
	playse SE_PIN
	applymovement 6, CommonMovement_EmoteQuestion
	delay 60
	applymovement 6, OakLab_Kukui_This
	waitmovement 0
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 6, CommonMovement_EmoteQuestion
	delay 60
	msgbox OakLab_Intro_Init_Text_0, MSGBOX_AUTOCLOSE
	applymovement 6, OakLab_Kukui_That
	waitmovement 0
	applymovement 5, CommonMovement_FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 6, CommonMovement_EmoteQuestion
	delay 60
	msgbox OakLab_Intro_Init_Text_1, MSGBOX_AUTOCLOSE
	applymovement 6, OakLab_Kukui_Final
	waitmovement 0
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	msgbox OakLab_Intro_Init_Text_2, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	applymovement 6, CommonMovement_FaceUp
	waitmovement 0
	msgbox OakLab_Intro_Init_Text_3, MSGBOX_AUTOCLOSE
	applymovement 5, CommonMovement_FaceRight
	waitmovement 0
	delay 30
	msgbox OakLab_Intro_Init_Text_4, MSGBOX_AUTOCLOSE
	applymovement 6, CommonMovement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_Cam_FromScene
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, OakLab_Player_GreetElm
	waitmovement 0
	msgbox OakLab_Intro_Init_Text_5, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OakLab_Intro_Init_3
	case NO, OakLab_Intro_Init_4
OakLab_Intro_Init_1:
	msgbox OakLab_Intro_Init_Text_8
	closemessage
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	delay 30
	msgbox OakLab_Intro_Init_Text_9
	closemessage
	applymovement 6, CommonMovement_FaceUp
	waitmovement 0
	delay 30
	msgbox OakLab_Intro_Init_Text_10
	closemessage
	applymovement 5, CommonMovement_FaceRight
	applymovement 6, OakLab_KukuiToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceDown
	waitmovement 0
	msgbox OakLab_Intro_Init_Text_11
	msgbox OakLab_Intro_Init_Text_12
	msgbox OakLab_Intro_Init_Text_13
	closemessage
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	applymovement 5, CommonMovement_FaceLeft
	loadword 0, OakLab_KukuiScript
	setfollower 6, 0x100
	fadescreen FADE_FROM_BLACK
	setvar VAR_TEMP_0, 1
	return

OakLab_Intro_Init_3:
	msgbox OakLab_Intro_Init_Text_6
	goto OakLab_Intro_Init_1

OakLab_Intro_Init_4:
	applymovement 5, OakLab_Elm_Jump
	msgbox OakLab_Intro_Init_Text_7
	goto OakLab_Intro_Init_1


OakLab_TryLeave::
	lock
	switch VAR_OAK_LAB_STATE
	case 0, OakLab_TryLeave_2
	case 1, OakLab_TryLeave_3
	case 2, OakLab_TryLeave_4
	case 3, OakLab_TryLeave_5
	return

OakLab_TryLeave_2:
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_EmoteExclamation
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	waitmovement 0
	msgbox OakLab_TryLeave_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, OakLab_PlayerEnter
	waitmovement 0
	release
	end

OakLab_TryLeave_3:
	return

OakLab_TryLeave_4:
	return

OakLab_TryLeave_5:
	setvar VAR_GAMESTATE, 3
	return


OakLab_TryStairs::
	lock
	switch VAR_OAK_LAB_STATE
	case 0, OakLab_TryStairs_2
	case 1, OakLab_TryStairs_3
	case 2, OakLab_TryStairs_4
	return

OakLab_TryStairs_2:
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_EmoteExclamation
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceDown
	waitmovement 0
	msgbox OakLab_TryStairs_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkDown
	waitmovement 0
	release
	end

OakLab_TryStairs_3:
	return

OakLab_TryStairs_4:
	return


OakLab_Elm::
	lock
	switch VAR_OAK_LAB_STATE
	case 0, OakLab_Elm_2
	case 1, OakLab_Elm_3
	case 2, OakLab_Elm_4
	case 3, OakLab_Elm_5
	return

OakLab_Elm_2:
	goto OakLab_Elm_FirstTalk
	return

OakLab_Elm_3:
	lock
	faceplayer
	msgbox OakLab_Elm_Text_0
	closemessage
	release
	end

OakLab_Elm_4:
	lock
	faceplayer
	msgbox OakLab_Elm_Text_1
	closemessage
	release
	end

OakLab_Elm_5:
	lock
	faceplayer
	msgbox OakLab_Elm_Text_2
	closemessage
	release
	end


OakLab_KukuiWhatMon::
	goto_if_set FLAG_PROF_HIDDEN, OakLab_KukuiWhatMon_1
	return

OakLab_KukuiWhatMon_1:
	lock
	faceplayer
	msgbox OakLab_KukuiWhatMon_Text_0
	closemessage
	applymovement 6, CommonMovement_FaceUp
	waitmovement 0
	release
	end


OakLab_Elm_FirstTalk::
	compare VAR_TEMP_1, 0
	goto_if_eq OakLab_Elm_FirstTalk_2
	applymovement 5, CommonMovement_FacePlayer
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_8
	closemessage
	applymovement 5, CommonMovement_FaceUp
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_9
	closemessage
	applymovement 5, CommonMovement_FaceLeft
	waitmovement 0
OakLab_Elm_FirstTalk_1:
	release
	end

OakLab_Elm_FirstTalk_2:
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CommonMovement_WalkLeft
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_0
	closemessage
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	applymovement 5, CommonMovement_FacePlayer
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_1
	msgbox OakLab_Elm_FirstTalk_Text_2
	msgbox OakLab_Elm_FirstTalk_Text_3
	closemessage
	applymovement 5, CommonMovement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_CamUp
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_4
	msgbox OakLab_Elm_FirstTalk_Text_5
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_CamDown
	waitmovement 0
	applymovement 5, CommonMovement_FacePlayer
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_6
	applymovement 5, OakLab_Elm_Jump
	waitmovement 0
	msgbox OakLab_Elm_FirstTalk_Text_7
	closemessage
	applymovement 5, CommonMovement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, CommonMovement_WalkRight
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_1, 1
	goto OakLab_Elm_FirstTalk_1


OakLab_Ball_Chikorita::
	goto_if_set FLAG_PROF_HIDDEN, OakLab_Ball_Chikorita_1
	lock
	msgbox OakLab_Ball_Chikorita_Text_3
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_EmoteExclamation
	delay 60
	facefollower
	msgbox OakLab_Ball_Chikorita_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	waitmovement 0
	playmoncry SPECIES_CHIKORITA, 2
	waitmoncry
	delay 30
	facefollower
	msgbox OakLab_Ball_Chikorita_Text_5
	closemessage
	call OakLab_OakAppear
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_RevealOak_Chikorita
	waitmovement 0
	goto OakLab_OakAppear_2
	return

OakLab_Ball_Chikorita_1:
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	applymovement 5, CommonMovement_FaceRight
	waitmovement 0
	delay 30
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox OakLab_Ball_Chikorita_Text_0
	msgbox OakLab_Ball_Chikorita_Text_1, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OakLab_Ball_Chikorita_5
	case NO, OakLab_Ball_Chikorita_6
	return

OakLab_Ball_Chikorita_5:
	goto OakLab_ChikoritaChosen
	return

OakLab_Ball_Chikorita_6:
	hidemonpic
	msgbox OakLab_Ball_Chikorita_Text_2
	closemessage
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	release
	end


OakLab_Ball_Piplup::
	goto_if_set FLAG_PROF_HIDDEN, OakLab_Ball_Piplup_1
	lock
	msgbox OakLab_Ball_Chikorita_Text_3
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_EmoteExclamation
	delay 60
	facefollower
	msgbox OakLab_Ball_Chikorita_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	waitmovement 0
	playmoncry SPECIES_PIPLUP, 2
	waitmoncry
	delay 30
	facefollower
	msgbox OakLab_Ball_Chikorita_Text_5
	closemessage
	call OakLab_OakAppear
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_RevealOak_Piplup
	waitmovement 0
	goto OakLab_OakAppear_2
	return

OakLab_Ball_Piplup_1:
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	applymovement 5, CommonMovement_FaceRight
	waitmovement 0
	delay 30
	showmonpic SPECIES_PIPLUP, 10, 3
	msgbox OakLab_Ball_Piplup_Text_0
	msgbox OakLab_Ball_Piplup_Text_1, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OakLab_Ball_Piplup_5
	case NO, OakLab_Ball_Piplup_6
	return

OakLab_Ball_Piplup_5:
	goto OakLab_PiplupChosen
	return

OakLab_Ball_Piplup_6:
	hidemonpic
	msgbox OakLab_Ball_Chikorita_Text_2
	closemessage
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	release
	end


OakLab_Ball_Tepig::
	goto_if_set FLAG_PROF_HIDDEN, OakLab_Ball_Tepig_1
	lock
	msgbox OakLab_Ball_Chikorita_Text_3
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_EmoteExclamation
	delay 60
	facefollower
	msgbox OakLab_Ball_Chikorita_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	waitmovement 0
	playmoncry SPECIES_TEPIG, 2
	waitmoncry
	delay 30
	facefollower
	msgbox OakLab_Ball_Chikorita_Text_5
	closemessage
	call OakLab_OakAppear
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_RevealOak_Tepig
	waitmovement 0
	goto OakLab_OakAppear_2
	return

OakLab_Ball_Tepig_1:
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	applymovement 5, CommonMovement_FaceRight
	waitmovement 0
	delay 30
	showmonpic SPECIES_TEPIG, 10, 3
	msgbox OakLab_Ball_Tepig_Text_0
	msgbox OakLab_Ball_Tepig_Text_1, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OakLab_Ball_Tepig_5
	case NO, OakLab_Ball_Tepig_6
	return

OakLab_Ball_Tepig_5:
	goto OakLab_TepigChosen
	return

OakLab_Ball_Tepig_6:
	hidemonpic
	msgbox OakLab_Ball_Chikorita_Text_2
	closemessage
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	release
	end


OakLab_OakAppear::
	playse SE_DOOR
	setobjectxy 1, 5, 6
	applymovement 1, CommonMovement_WalkRight
	waitse
	msgbox OakLab_OakAppear_Text_0
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteExclamation
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_EmoteExclamation
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_FaceLeft
	special SpawnCameraObject
	return


OakLab_OakAppear_2::
	msgbox OakLab_OakAppear_2_Text_0
	msgbox OakLab_OakAppear_2_Text_1
	closemessage
	applymovement 1, OakLab_OakDownStairs
	delay 30
	fadescreen FADE_TO_BLACK
	waitmovement 0
	setobjectxy 1, 8, 13
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 13
	setobjectxy OBJ_EVENT_ID_FOLLOWER, 10, 13
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_FaceUp
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_CameraToSelection
	waitmovement 0
	applymovement 1, OakLab_OakLookAtPlayer
	fadescreen FADE_FROM_BLACK
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_2
	closemessage
	applymovement 1, OakLab_OakNod
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_3
	closemessage
	applymovement 1, OakLab_OakWalkPastBalls
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_4
	closemessage
	applymovement 1, OakLab_OakWalkPastBalls_Back
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_5
	closemessage
	applymovement 1, OakLab_OakWalkPastBalls
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_6
	msgbox OakLab_OakAppear_2_Text_7
	closemessage
	playse SE_PIN
	applymovement 1, CommonMovement_EmoteQuestion
	delay 60
	applymovement 5, OakLab_ElmToOak
	waitmovement 0
	applymovement 1, CommonMovement_FaceLeft
	waitmovement 0
	applymovement 5, OakLab_Elm_Jump
	waitmovement 0
	playse SE_BOO
	applymovement 1, CommonMovement_EmoteExclamation
	delay 60
	closemessage
	delay 30
	msgbox OakLab_OakAppear_2_Text_8
	closemessage
	msgbox OakLab_OakAppear_2_Text_9
	closemessage
	delay 30
	msgbox OakLab_OakAppear_2_Text_10
	closemessage
	playse SE_PIN
	applymovement 1, CommonMovement_EmoteExclamation
	delay 60
	msgbox OakLab_OakAppear_2_Text_11
	msgbox OakLab_OakAppear_2_Text_12
	closemessage
	playse SE_PIN
	applymovement 1, CommonMovement_EmoteExclamation
	delay 60
	msgbox OakLab_OakAppear_2_Text_13
	closemessage
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_14
	closemessage
	applymovement 1, CommonMovement_FaceLeft
	waitmovement 0
	msgbox OakLab_OakAppear_2_Text_15
	msgbox OakLab_OakAppear_2_Text_16
	closemessage
	applymovement 1, OakLab_OakLeave
	delay 60
	fadescreen 1
	playse SE_DOOR
	setobjectxy 1, 19, 0
	removeobject 1
	setflag FLAG_PROF_HIDDEN
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	waitse
	destroyfollower
	addobject 6
	setobjectxy 6, 10, 13
	applymovement 6, CommonMovement_FaceUp
	fadescreen 0
	delay 60
	msgbox OakLab_OakAppear_2_Text_17
	closemessage
	delay 60
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	msgbox OakLab_OakAppear_2_Text_18
	closemessage
	applymovement 5, CommonMovement_FaceRight
	waitmovement 0
	delay 30
	msgbox OakLab_OakAppear_2_Text_19
	closemessage
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	delay 30
	msgbox OakLab_OakAppear_2_Text_20
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceRight
	applymovement 6, CommonMovement_FaceLeft
	delay 30
	msgbox OakLab_OakAppear_2_Text_21
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	applymovement 6, CommonMovement_FaceUp
	delay 30
	msgbox OakLab_OakAppear_2_Text_22
	closemessage
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	msgbox OakLab_OakAppear_2_Text_23
	msgbox OakLab_OakAppear_2_Text_24
	msgbox OakLab_OakAppear_2_Text_25
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceRight
	applymovement 6, CommonMovement_FaceLeft
	delay 30
	msgbox OakLab_OakAppear_2_Text_26
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	applymovement 6, CommonMovement_FaceUp
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_CameraReturn
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_OAK_LAB_STATE, 1
	release
	end


OakLab_WannaLeave::
	lock
	playse SE_PIN
	applymovement 6, CommonMovement_EmoteExclamation
	delay 60
	applymovement 6, CommonMovement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	waitmovement 0
	msgbox OakLab_WannaLeave_Text_0
	closemessage
	applymovement 6, CommonMovement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkUp
	waitmovement 0
	release
	end


OakLab_DontGoThere::
	lock
	playse SE_PIN
	applymovement 5, CommonMovement_EmoteExclamation
	delay 60
	applymovement 5, CommonMovement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceRight
	waitmovement 0
	msgbox OakLab_DontGoThere_Text_0
	closemessage
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkDown
	waitmovement 0
	release
	end


OakLab_ChikoritaChosen::
	msgbox OakLab_ChikoritaChosen_Text_0
	closemessage
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	setvar VAR_STARTER_MON, 0
	removeobject 2
	call Pokemon_Chosen
	goto OakLab_RivalChooseStarter
	return


OakLab_PiplupChosen::
	msgbox OakLab_ChikoritaChosen_Text_0
	closemessage
	givemon SPECIES_PIPLUP, 5, ITEM_NONE
	setvar VAR_STARTER_MON, 1
	removeobject 3
	call Pokemon_Chosen
	goto OakLab_RivalChooseStarter
	return


OakLab_TepigChosen::
	msgbox OakLab_ChikoritaChosen_Text_0
	closemessage
	givemon SPECIES_TEPIG, 5, ITEM_NONE
	setvar VAR_STARTER_MON, 2
	removeobject 4
	call Pokemon_Chosen
	goto OakLab_RivalChooseStarter
	return


Pokemon_Chosen::
	bufferleadmonspeciesname 0
	message Pokemon_Chosen_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Pokemon_Chosen_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokemon_Chosen_2
Pokemon_Chosen_1:
	setflag FLAG_SYS_POKEMON_GET
	closemessage
	hidemonpic
	return

Pokemon_Chosen_2:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto Pokemon_Chosen_1


OakLab_RivalChooseStarter::
	playse SE_PIN
	applymovement 6, CommonMovement_EmoteExclamation
	delay 60
	msgbox OakLab_RivalChooseStarter_Text_0
	closemessage
	switch VAR_STARTER_MON
	case 1, OakLab_RivalChooseStarter_3
	case 2, OakLab_RivalChooseStarter_4
	case 0, OakLab_RivalChooseStarter_5
OakLab_RivalChooseStarter_1:
	delay 30
	fadescreen 1
	applymovement 5, CommonMovement_FaceDown
	waitmovement 0
	waitse
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 13
	setobjectxy 6, 10, 13
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceUp
	applymovement 6, CommonMovement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	switch VAR_STARTER_MON
	case 1, OakLab_RivalChooseStarter_8
	case 2, OakLab_RivalChooseStarter_9
	case 0, OakLab_RivalChooseStarter_10
OakLab_RivalChooseStarter_6:
	special RemoveCameraObject
	fadescreen 0
	setvar VAR_OAK_LAB_STATE, 2
	release
	end

OakLab_RivalChooseStarter_3:
	applymovement 6, OakLab_KukuiChooseChikorita
	waitmovement 0
	delay 30
	removeobject 2
	message OakLab_RivalChooseStarter_Text_1
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	closemessage
	goto OakLab_RivalChooseStarter_1

OakLab_RivalChooseStarter_4:
	applymovement 6, OakLab_KukuiChoosePiplup
	waitmovement 0
	delay 30
	removeobject 3
	message OakLab_RivalChooseStarter_Text_2
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	closemessage
	goto OakLab_RivalChooseStarter_1

OakLab_RivalChooseStarter_5:
	applymovement 6, OakLab_KukuiChooseTepig
	waitmovement 0
	delay 30
	removeobject 4
	message OakLab_RivalChooseStarter_Text_3
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	closemessage
	goto OakLab_RivalChooseStarter_1

OakLab_RivalChooseStarter_8:
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_ReturnChikorita
	waitmovement 0
	goto OakLab_RivalChooseStarter_6

OakLab_RivalChooseStarter_9:
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_ReturnPiplup
	waitmovement 0
	goto OakLab_RivalChooseStarter_6

OakLab_RivalChooseStarter_10:
	applymovement OBJ_EVENT_ID_CAMERA, OakLab_ReturnTepig
	waitmovement 0
	goto OakLab_RivalChooseStarter_6


OakLab_RivalBattle_Left::
	goto OakLab_RivalBattle_Start
	return


OakLab_RivalBattle_Right::
	goto OakLab_RivalBattle_Start
	return


OakLab_RivalBattle_Start::
	return


OakLab_PlayerEnter:
	walk_slow_up
	walk_slow_up
	step_end

OakLab_CamUp:
	walk_up
	walk_up
	step_end

OakLab_CamDown:
	walk_down
	walk_down
	step_end

OakLab_Elm_Jump:
	jump_in_place_right
	jump_in_place_right
	step_end

OakLab_Cam_ToScene:
	walk_up
	walk_left
	walk_left
	step_end

OakLab_Cam_FromScene:
	walk_right
	walk_right
	walk_down
	step_end

OakLab_Kukui_This:
	walk_fast_down
	walk_fast_left
	delay_16
	step_end

OakLab_Kukui_That:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	delay_16
	step_end

OakLab_Kukui_Final:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	delay_16
	step_end

OakLab_Player_GreetElm:
	walk_up
	face_left
	delay_16
	step_end

OakLab_KukuiToPlayer:
	walk_right
	walk_right
	face_up
	delay_16
	step_end

OakLab_RevealOak_Chikorita:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

OakLab_RevealOak_Piplup:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

OakLab_RevealOak_Tepig:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

OakLab_OakDownStairs:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

OakLab_CameraToSelection:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OakLab_OakLookAtPlayer:
	walk_up
	walk_up
	face_down
	delay_16
	step_end

OakLab_OakWalkPastBalls:
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	delay_16
	step_end

OakLab_OakWalkPastBalls_Back:
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	delay_16
	step_end

OakLab_OakNod:
	emote_anim_frame_one
	face_down
	delay_16
	emote_anim_frame_one
	face_down
	delay_16
	step_end

OakLab_ElmToOak:
	walk_fastest_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	delay_16
	step_end

OakLab_OakLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

OakLab_CameraReturn:
	walk_down
	walk_left
	step_end

OakLab_KukuiChooseChikorita:
	walk_left
	walk_up
	walk_up
	step_end

OakLab_KukuiChoosePiplup:
	walk_up
	walk_up
	step_end

OakLab_KukuiChooseTepig:
	walk_right
	walk_up
	walk_up
	step_end

OakLab_ReturnChikorita:
	walk_right
	walk_down
	walk_down
	step_end

OakLab_ReturnPiplup:
	walk_down
	walk_down
	step_end

OakLab_ReturnTepig:
	walk_left
	walk_down
	walk_down
	step_end

OakLab_KukuiScript::
	applymovement OBJ_EVENT_ID_FOLLOWER, CommonMovement_FacePlayer
	waitmovement 0
	msgbox OakLab_KukuiScript_Text_0, MSGBOX_SIGN
	closemessage
	end


OakLab_Intro_Init_Text_0:
	.string "Boy: What's this?$"

OakLab_Intro_Init_Text_1:
	.string "Boy: And what's that do?$"

OakLab_Intro_Init_Text_2:
	.string "Boy: And what-$"

OakLab_Intro_Init_Text_3:
	.string "Aide: Will you stop?\nPlease, do NOT touch anything!$"

OakLab_Intro_Init_Text_4:
	.string "Aide: Hey, you?$"

OakLab_Intro_Init_Text_5:
	.string "Aide: You're here to revieve your\nSTARTER POKéMON too, right?$"

OakLab_Intro_Init_Text_6:
	.string "Aide: Good to know.$"

OakLab_Intro_Init_Text_7:
	.string "Aide: Hey, don't play with me!\nWhy else would you be here?$"

OakLab_Intro_Init_Text_8:
	.string "I hope this isn't too much to ask,\nbut could you please look after\lthis troublemaker?$"

OakLab_Intro_Init_Text_9:
	.string "Aide: I appreciate his interest in\nin science, but he can't keep his\lfingers to himself!$"

OakLab_Intro_Init_Text_10:
	.string "Boy: Alright then.\nI was getting bored anyway.$"

OakLab_Intro_Init_Text_11:
	.string "Boy: Hi! Nice to meet you.\nMy name is MAKOA!$"

OakLab_Intro_Init_Text_12:
	.string "Makoa: You're a trainer-to-be too?\nThat's sooo cool!\pI can't wait to battle you!\lAfter we've made our choice, of course!$"

OakLab_Intro_Init_Text_13:
	.string "Let's go talk to the PROF.!$"

OakLab_TryLeave_Text_0:
	.string "Makoa: You can't leave yet!\nWe still need to get out POKéMON!$"

OakLab_TryStairs_Text_0:
	.string "Makoa: This goes up to the PROF.'s\nprivate quaters.\pI don't think we should go there...$"

OakLab_Elm_Text_0:
	.string "Elm: It's OK to take your time.\nThis is an important descision.$"

OakLab_Elm_Text_1:
	.string "Elm: I feel like that boy, MAKOA\nwill come around eventually.$"

OakLab_Elm_Text_2:
	.string "Elm: Good luck on your journey!\nPlease record all the POKéMON you meet!$"

OakLab_KukuiWhatMon_Text_0:
	.string "Makoa: Come on!\nI wanna choose too!$"

OakLab_Elm_FirstTalk_Text_0:
	.string "Aide: Aw man...\nThis thing just ain't working...$"

OakLab_Elm_FirstTalk_Text_1:
	.string "Aide: Hey, you!\nSorry to make such a hassle, but\lplease do NOT touch anything in here!$"

OakLab_Elm_FirstTalk_Text_2:
	.string "Aide: Hm?$"

OakLab_Elm_FirstTalk_Text_3:
	.string "Aide: Ah, you see, I'm not the PROFESSOR!\nI'm just his aide, you can call me ELM,\lADRIAN ELM.\lNice to meet you!$"

OakLab_Elm_FirstTalk_Text_4:
	.string "Elm: The PROFESSOR is just up ahead.\nHe's waiting for you for sure already!$"

OakLab_Elm_FirstTalk_Text_5:
	.string "PROF. OAK is such a busy guy.\nIt's best to not keep him waiting!$"

OakLab_Elm_FirstTalk_Text_6:
	.string "Elm: Anyway, I've got to get back\nto work...$"

OakLab_Elm_FirstTalk_Text_7:
	.string "And look after that your friend!$"

OakLab_Elm_FirstTalk_Text_8:
	.string "Elm: You again?$"

OakLab_Elm_FirstTalk_Text_9:
	.string "Elm: The PROFESSOR is just up ahead.\nHe's waiting for you for sure\lalready!$"

OakLab_Ball_Chikorita_Text_0:
	.string "Elm: This is CHIKORITA,\nthe LEAF POKéMON.$"

OakLab_Ball_Chikorita_Text_1:
	.string "Will you pick this gentle POKéMON as\n"
	.string "your partner?$"

OakLab_Ball_Chikorita_Text_2:
	.string "Elm: That's perfectly fine.\nThink it through!$"

OakLab_Ball_Chikorita_Text_3:
	.string "A POKéBALL lies on the table.$"

OakLab_Ball_Chikorita_Text_4:
	.string "Makoa: Oh!\nI wonder what POKéMON is inside...$"

OakLab_Ball_Chikorita_Text_5:
	.string "Makoa: Hm...\nThis one SOUNDS strong!$"

OakLab_Ball_Piplup_Text_0:
	.string "Elm: This is PIPLUP,\nthe PENGUIN POKéMON.$"

OakLab_Ball_Piplup_Text_1:
	.string "Will you pick this proud POKéMON as your\n"
	.string "partner?$"

OakLab_Ball_Tepig_Text_0:
	.string "Elm: This is TEPIG,\nthe FIRE PIG POKéMON.$"

OakLab_Ball_Tepig_Text_1:
	.string "Will you pick this energetic POKéMON as\n"
	.string "your partner?$"

OakLab_OakAppear_Text_0:
	.string "???: Oh, the next ones are already here?$"

OakLab_OakAppear_2_Text_0:
	.string "Oak: Sorry for being late kids, it's\nbeen a busy day.$"

OakLab_OakAppear_2_Text_1:
	.string "I'll be right there with you!$"

OakLab_OakAppear_2_Text_2:
	.string "Oak: Very well then!$"

OakLab_OakAppear_2_Text_3:
	.string "Today is a very exciting day for you, hm?$"

OakLab_OakAppear_2_Text_4:
	.string "Meeting your first partner...\nBecoming a POKéMON TRAINER...$"

OakLab_OakAppear_2_Text_5:
	.string "It is an honour and a challenge for\nall the young people the visit me\lhere in my laboratory.$"

OakLab_OakAppear_2_Text_6:
	.string "Oak: To catch POKéMON-\nThat's the real test.\lAnd to train them is-$"

OakLab_OakAppear_2_Text_7:
	.string "???: PROFESSOR!$"

OakLab_OakAppear_2_Text_8:
	.string "Oak: Spit it out, ELM!\nWhat is going on?$"

OakLab_OakAppear_2_Text_9:
	.string "Elm: I'm sorry to interrupt, but...$"

OakLab_OakAppear_2_Text_10:
	.string "It's your daughter, she's, uh...\nShe's going into labour as we speak!$"

OakLab_OakAppear_2_Text_11:
	.string "Oak: WHAT?!\nThat's early!\lI guess my grandson is a bit pushy, hm?$"

OakLab_OakAppear_2_Text_12:
	.string "Elm: We already flew her over to\nVIRIDIAN HOSPITAL, but the neighbors\lwho watched after DAISY for the day\loffered to drive you both.$"

OakLab_OakAppear_2_Text_13:
	.string "Oak: How very nice of them!$"

OakLab_OakAppear_2_Text_14:
	.string "Oak: Sorry kids, but I don't have time\nto lose!$"

OakLab_OakAppear_2_Text_15:
	.string "Oak: ELM, I'm heading out.\nYou're in charge while I'm gone, so\lgive these kids their POKéMON and don't\lforget the POKéDEXES!$"

OakLab_OakAppear_2_Text_16:
	.string "Elm: Yessir!$"

OakLab_OakAppear_2_Text_17:
	.string "Elm: Uh...$"

OakLab_OakAppear_2_Text_18:
	.string "Elm: Oh yeah, right!\pIn these POKéBALLS...$"

OakLab_OakAppear_2_Text_19:
	.string "... there are POKéMON caught by the\nPROFESSOR himself!$"

OakLab_OakAppear_2_Text_20:
	.string "The both of you may choose one-\nYour very first POKéMON PARTNER!$"

OakLab_OakAppear_2_Text_21:
	.string "Makoa: Oh man, this is EXCITING!$"

OakLab_OakAppear_2_Text_22:
	.string "Makoa: Hm, I think I'll pick...$"

OakLab_OakAppear_2_Text_23:
	.string "Elm: Oh, no!\nI think it's best if YOU practice\la bit of patiece.$"

OakLab_OakAppear_2_Text_24:
	.string "The other kid, {PLAYER} was it?\nYou can go first.$"

OakLab_OakAppear_2_Text_25:
	.string "Makoa: Maaaan, for real?\nWhat a bummer...$"

OakLab_OakAppear_2_Text_26:
	.string "Makoa: You better chose a good one,\nOK?$"

OakLab_WannaLeave_Text_0:
	.string "Makoa: Where do you think you're going?\nIf I can only pick after you, you\lbetter pick something first!$"

OakLab_DontGoThere_Text_0:
	.string "Elm: Hey, don't go up there!\nThese are PROF. OAK's private quaters!$"

OakLab_ChikoritaChosen_Text_0:
	.string "Elm: Very well!$"

Pokemon_Chosen_Text_0:
	.string "{PLAYER} chose {STR_VAR_1}!$"

Pokemon_Chosen_Text_1:
	.string "Give a nickname to {STR_VAR_1}?$"

OakLab_RivalChooseStarter_Text_0:
	.string "Makoa: OK then, this one's mine!$"

OakLab_RivalChooseStarter_Text_1:
	.string "Makoa: CHIKORITA, I choose you!$"

OakLab_RivalChooseStarter_Text_2:
	.string "Makoa: PIPLUP, I choose you!$"

OakLab_RivalChooseStarter_Text_3:
	.string "Makoa: TEPIG, I choose you!$"

OakLab_KukuiScript_Text_0:
	.string "Makoa: Let's see the PROF.!\nI can't wait!$"
