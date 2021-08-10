SabrinaGym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SabrinaGym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SabrinaGym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SabrinaGym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SABRINA_GYM
	return

SabrinaGym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, SabrinaGym_Init
	.2byte 0


SabrinaGym_Init::
	compare VAR_SABRINAGYM_STATE, 0
	goto_if_eq SabrinaGym_Init_2
SabrinaGym_Init_1:
	setvar VAR_TEMP_0, 1
	release
	end

SabrinaGym_Init_2:
	applymovement OBJ_EVENT_ID_PLAYER, SabrinaGym_PlayerEnter
	waitmovement 0
	goto SabrinaGym_Init_1


SabrinaGym_Nurse::
	lock
	msgbox SabrinaGym_Nurse_Text_0
	msgbox SabrinaGym_Nurse_Text_1
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	closemessage
	release
	end


SabrinaGym_Security::
	lock
	faceplayer
	switch VAR_SABRINAGYM_STATE
	case 0, SabrinaGym_Security_3
	goto_if_set FLAG_SABRINAGYM_FRESHWATER, SabrinaGym_Security_6
	msgbox SabrinaGym_Security_Text_2, MSGBOX_AUTOCLOSE
	msgbox SabrinaGym_Security_Text_3, MSGBOX_AUTOCLOSE
	msgbox SabrinaGym_Security_Text_4, MSGBOX_AUTOCLOSE
	giveitem ITEM_FRESH_WATER
	setflag FLAG_SABRINAGYM_FRESHWATER
	closemessage
SabrinaGym_Security_5:
SabrinaGym_Security_1:
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	release
	end

SabrinaGym_Security_3:
	msgbox SabrinaGym_Security_Text_0, MSGBOX_AUTOCLOSE
	goto SabrinaGym_Security_1

SabrinaGym_Security_6:
	msgbox SabrinaGym_Security_Text_1, MSGBOX_AUTOCLOSE
	goto SabrinaGym_Security_5


SabrinaGym_DontGoIn_Left::
	lockall
	call SabrinaGym_DontGoIn_1
	releaseall
	end


SabrinaGym_DontGoIn_Right::
	lockall
	call SabrinaGym_DontGoIn_1
	releaseall
	end


SabrinaGym_TraierLeave_Right::
	applymovement 19, CommonMovement_WalkLeft
	waitmovement 0
	call SabrinaGym_DontGoIn_2
	applymovement 19, CommonMovement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceLeft
	waitmovement 0
	call SabrinaGym_DontGoIn_3
	return


SabrinaGym_TraierLeave_Left::
	call SabrinaGym_DontGoIn_2
	applymovement 19, CommonMovement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceRight
	waitmovement 0
	call SabrinaGym_DontGoIn_3
	return


SabrinaGym_DontGoIn_1::
	applymovement 1, CommonMovement_EmoteExclamation
	delay 60
	applymovement 1, CommonMovement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_FaceDown
	waitmovement 0
	delay 30
	msgbox SabrinaGym_DontGoIn_1_Text_0, MSGBOX_AUTOCLOSE
	msgbox SabrinaGym_DontGoIn_1_Text_1, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkDown
	waitmovement 0
	delay 30
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	return


SabrinaGym_DontGoIn_2::
	msgbox SabrinaGym_DontGoIn_2_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteQuestion
	delay 60
	applymovement 19, SabrinaGym_TrainerMoveDown
	waitmovement 0
	delay 30
	applymovement 19, CommonMovement_EmoteExclamation
	delay 60
	return


SabrinaGym_DontGoIn_3::
	msgbox SabrinaGym_DontGoIn_3_Text_0, MSGBOX_AUTOCLOSE
	applymovement 19, SabrinaGym_DefeatedTrainer
	waitmovement 0
	playse SE_DOOR
	removeobject 19
	setvar VAR_SABRINAGYM_STATE, 2
	setflag FLAG_SABRINAGYM_BUGCATCHER
	return


SabrinaGym_DontLeave::
	lockall
	applymovement 1, CommonMovement_EmoteExclamation
	delay 60
	applymovement 1, CommonMovement_WalkDown
	waitmovement 0
	delay 30
	msgbox SabrinaGym_DontLeave_Text_0, MSGBOX_AUTOCLOSE
	applymovement 1, CommonMovement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkUp
	waitmovement 0
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	release
	end


SabrinaGym_Announcement_1::
	lock
	msgbox SabrinaGym_Announcement_1_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteExclamation
	delay 60
	msgbox SabrinaGym_Announcement_1_Text_1
	msgbox SabrinaGym_Announcement_1_Text_2
	closemessage
	setvar VAR_SABRINAGYM_STATE, 3
	release
	end


SabrinaGym_CounterLady::
	lock
	switch VAR_SABRINAGYM_STATE
	case 0, SabrinaGym_CounterLady_3
	msgbox SabrinaGym_CounterLady_Text_6, MSGBOX_AUTOCLOSE
SabrinaGym_CounterLady_1:
	release
	end

SabrinaGym_CounterLady_3:
	msgbox SabrinaGym_CounterLady_Text_0
	msgbox SabrinaGym_CounterLady_Text_1
	msgbox SabrinaGym_CounterLady_Text_2
	closemessage
	delay 60
	msgbox SabrinaGym_CounterLady_Text_3
	msgbox SabrinaGym_CounterLady_Text_4
	msgbox SabrinaGym_CounterLady_Text_5
	closemessage
	giveitem ITEM_TM46
	setvar VAR_SABRINAGYM_STATE, 1
	msgbox SabrinaGym_CounterLady_Text_6, MSGBOX_AUTOCLOSE
	goto SabrinaGym_CounterLady_1


SabrinaGym_Boy_1::
	lockall
	faceplayer
	msgbox SabrinaGym_Boy_1_Text_0
	msgbox SabrinaGym_Boy_1_Text_1, MSGBOX_AUTOCLOSE
	releaseall
	end


SabrinaGym_Girl_1::
	lockall
	faceplayer
	msgbox SabrinaGym_Girl_1_Text_0
	msgbox SabrinaGym_Girl_1_Text_1, MSGBOX_AUTOCLOSE
	releaseall
	end


SabrinaGym_Trashcan::
	lock
	msgbox SabrinaGym_Trashcan_Text_0, MSGBOX_SIGN
	closemessage
	end


SabrinaGym_Adah::
	trainerbattle_single TRAINER_ADAH, SabrinaGym_Adah_Text_0, SabrinaGym_Adah_Text_1
	msgbox SabrinaGym_Adah_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Louise::
	trainerbattle_double TRAINER_LOUISE, SabrinaGym_Louise_Text_0, SabrinaGym_Louise_Text_1, SabrinaGym_Louise_Text_2
	msgbox SabrinaGym_Louise_Text_3, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Reina::
	trainerbattle_single TRAINER_REINA, SabrinaGym_Reina_Text_0, SabrinaGym_Reina_Text_1
	msgbox SabrinaGym_Reina_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Gandalf::
	trainerbattle_single TRAINER_GANDALF, SabrinaGym_Gandalf_Text_0, SabrinaGym_Gandalf_Text_1
	msgbox SabrinaGym_Gandalf_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Spike::
	trainerbattle_single TRAINER_SPIKE, SabrinaGym_Spike_Text_0, SabrinaGym_Spike_Text_1
	msgbox SabrinaGym_Spike_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Paletto::
	trainerbattle_single TRAINER_PALETTO, SabrinaGym_Paletto_Text_0, SabrinaGym_Paletto_Text_1
	msgbox SabrinaGym_Paletto_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Sabrina_Debug::
	trainerbattle_single TRAINER_SABRINA_YOUNG, SabrinaGym_Paletto_Text_0, SabrinaGym_Paletto_Text_1
	msgbox SabrinaGym_Paletto_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_PlayerEnter:
	walk_slow_up
	walk_slow_up
	step_end

SabrinaGym_TrainerMoveDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_16
	step_end

SabrinaGym_DefeatedTrainer:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_16
	step_end

SabrinaGym_Nurse_Text_0:
	.string "Nurse: Hello there, Challenger!$"

SabrinaGym_Nurse_Text_1:
	.string "May I fresh up your POKéMON?$"

SabrinaGym_Security_Text_0:
	.string "Hi, how can I help you?\nOh, you're a GYM CHALLENGER?\lPlease, check in with the SERVICE COUNTER\lto challenge this GYM.\pYou know the drill! $"

SabrinaGym_Security_Text_1:
	.string "Oh yeah, I also participated in\nthe GYM CHALLENGE in my youth.\pAny advice?\nHm...\pNever, ever stop believing in\nyourself and your team.\pEven if things get hard and no-one\nelse does...\pYou mustn't give up and\nwork hard.\lAlways.\pAh, but I digress.\nSorry for blabbering on!$"

SabrinaGym_Security_Text_2:
	.string "Oh, hi there, young\nchamp-in-the-making!$"

SabrinaGym_Security_Text_3:
	.string "If you're a challenger, I gotta\nwarn ya:\lThe trainers in this GYM are no JOKE!$"

SabrinaGym_Security_Text_4:
	.string "Here, this is for you.\nKeep your cool!$"

SabrinaGym_DontGoIn_1_Text_0:
	.string "Sorry, if you're a visitor, please\nuse the visitor entrances.$"

SabrinaGym_DontGoIn_1_Text_1:
	.string "Oh?\nYou're a challenger?\pIn that case, please check in at\nthe front desk to get started.$"

SabrinaGym_DontGoIn_2_Text_0:
	.string "OUT OF MY WAY!\nMOVE!$"

SabrinaGym_DontGoIn_3_Text_0:
	.string "It's crazy! These trainers are\ninsanely strong!\pIt's like they can predict my\nevery move!\pDarn...\nI knew I should've challenged\lANISTAR GYM instead...$"

SabrinaGym_DontLeave_Text_0:
	.string "Sorry, but if you leave the GYM,\nyour challenge will be FORFEIT.\lDo you really want to give up?\pBelieve in yourself a bit more!$"

SabrinaGym_Announcement_1_Text_0:
	.string "???: And who do we have here?$"

SabrinaGym_Announcement_1_Text_1:
	.string "Announcer: This young trainer has\njust started the SAFFRON CHALLENGE!$"

SabrinaGym_Announcement_1_Text_2:
	.string "Let's see how good they do.\nGive them a big round of applause!$"

SabrinaGym_CounterLady_Text_0:
	.string "Hi there, love!\nWelcome to SAFFRON GYM!$"

SabrinaGym_CounterLady_Text_1:
	.string "Are you an audience member, or-\nOh! Is that a TRAINER-CARD I see?$"

SabrinaGym_CounterLady_Text_2:
	.string "Let me see that for a moment, please...$"

SabrinaGym_CounterLady_Text_3:
	.string "Ah, I see!\nTHREE shining BADGES, and your\lPOKéMON-TEAM is looking mighty\lstrong too!$"

SabrinaGym_CounterLady_Text_4:
	.string "I'll let the GYM LEADER know that you'll\nbe contending for your FOURTH BADGE.$"

SabrinaGym_CounterLady_Text_5:
	.string "Here, this a participatory gift!$"

SabrinaGym_CounterLady_Text_6:
	.string "We'll be cheering you on!$"

SabrinaGym_Boy_1_Text_0:
	.string "Oh man, oh man, oh man...\nI'm so nervous...\pI already lost, but by friend\nis still in there...$"

SabrinaGym_Boy_1_Text_1:
	.string "The trainers in the GYM are\ncrazy strong!\lI didn't even make it to the GYM LEADER...$"

SabrinaGym_Girl_1_Text_0:
	.string "Darn, tickets are all sold out...$"

SabrinaGym_Girl_1_Text_1:
	.string "Guess I'll try again tomorrow,\nI just hope the challengers are\las strong then as they are today!$"

SabrinaGym_Trashcan_Text_0:
	.string "The trashcan is full of empty\nsoda bottles and popcorn bags.$"

SabrinaGym_Adah_Text_0:
	.string "Welcome to SAFFRON CITY GYM!\nLet's see what you're made of...$"

SabrinaGym_Adah_Text_1:
	.string "Oh, nicely done!$"

SabrinaGym_Adah_Text_2:
	.string "Good luck!\nYou'll need it here...$"

SabrinaGym_Louise_Text_0:
	.string "Can I see into the future?\nMaybe!$"

SabrinaGym_Louise_Text_1:
	.string "I totally saw that coming!$"

SabrinaGym_Louise_Text_2:
	.string "Sorry, but you'll need more\nPOKéMON to fight me!$"

SabrinaGym_Louise_Text_3:
	.string "The future isn't yet written...$"

SabrinaGym_Reina_Text_0:
	.string "POKéMON are our partners,\nin life and in combat!$"

SabrinaGym_Reina_Text_1:
	.string "Ah, farts.$"

SabrinaGym_Reina_Text_2:
	.string "What I said before I read in a\nself-help book, but I guess it\ldidn't make me a winner...$"

SabrinaGym_Gandalf_Text_0:
	.string "Hey, come one...\nI'll fight ya, but don't ask\labout me name, OK?$"

SabrinaGym_Gandalf_Text_1:
	.string "Aw man...$"

SabrinaGym_Gandalf_Text_2:
	.string "Why did my parents hate me?$"

SabrinaGym_Spike_Text_0:
	.string "Taking on all the GYM CHALLENGERS\nis a bunch of work...$"

SabrinaGym_Spike_Text_1:
	.string "That wasn't my best performance...$"

SabrinaGym_Spike_Text_2:
	.string "I'm tired...$"

SabrinaGym_Paletto_Text_0:
	.string "All eyes are on us now...$"

SabrinaGym_Paletto_Text_1:
	.string "Smile and wave,\njust smile and wave.$"

SabrinaGym_Paletto_Text_2:
	.string "Watching the GYM challenge is\na really popular passtime.\lI'm excited to work at the GYM\lduring GYM SEASON.$"
