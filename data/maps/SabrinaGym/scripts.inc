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
	applymovement OBJ_EVENT_ID_PLAYER, SabrinaGym_PlayerEnter
	waitmovement 0
	setvar VAR_TEMP_0, 1
	return


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
	case 1, SabrinaGym_Security_4
SabrinaGym_Security_1:
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	release
	end

SabrinaGym_Security_3:
	msgbox SabrinaGym_Security_Text_0, MSGBOX_AUTOCLOSE
	goto SabrinaGym_Security_1

SabrinaGym_Security_4:
	goto_if_set FLAG_SABRINAGYM_FRESHWATER, SabrinaGym_Security_6
	msgbox SabrinaGym_Security_Text_2, MSGBOX_AUTOCLOSE
	msgbox SabrinaGym_Security_Text_3, MSGBOX_AUTOCLOSE
	msgbox SabrinaGym_Security_Text_4, MSGBOX_AUTOCLOSE
	giveitem ITEM_FRESH_WATER
	closemessage
SabrinaGym_Security_5:
	goto SabrinaGym_Security_1

SabrinaGym_Security_6:
	msgbox SabrinaGym_Security_Text_1, MSGBOX_AUTOCLOSE
	goto SabrinaGym_Security_5


SabrinaGym_DontGoIn::
	lockall
	applymovement 1, CommonMovement_EmoteExclamation
	delay 60
	applymovement 1, CommonMovement_FaceRight
	waitmovement 0
	delay 30
	msgbox SabrinaGym_DontGoIn_Text_0, MSGBOX_AUTOCLOSE
	msgbox SabrinaGym_DontGoIn_Text_1, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_WalkDown
	waitmovement 0
	delay 30
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	releaseall
	end


SabrinaGym_CounterLady::
	lock
	switch VAR_SABRINAGYM_STATE
	case 0, SabrinaGym_CounterLady_3
	case 1, SabrinaGym_CounterLady_4
SabrinaGym_CounterLady_1:
	release
	end

SabrinaGym_CounterLady_3:
	giveitem ITEM_TM46
	setvar VAR_SABRINAGYM_STATE, 1
	goto SabrinaGym_CounterLady_1

SabrinaGym_CounterLady_4:
	goto SabrinaGym_CounterLady_1


SabrinaGym_Boy_1::
	lockall
	faceplayer
	msgbox SabrinaGym_Boy_1_Text_0
	msgbox SabrinaGym_Boy_1_Text_1, MSGBOX_AUTOCLOSE
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


SabrinaGym_PlayerEnter:
	walk_slow_up
	walk_slow_up
	step_end

SabrinaGym_Nurse_Text_0:
	.string "Nurse: Hello there, Challenger!$"

SabrinaGym_Nurse_Text_1:
	.string "May I fresh up your POKéMON?$"

SabrinaGym_Security_Text_0:
	.string "Hi, how can I help you?\nOh, you're a GYM CHALLENGER?\lPlease, check in with the SERVICE COUNTER\lto challenge this GYM.\pYou know the drill! $"

SabrinaGym_Security_Text_1:
	.string "Good luck out there!$"

SabrinaGym_Security_Text_2:
	.string "Oh, hi there, young\nchamp-in-the-making!$"

SabrinaGym_Security_Text_3:
	.string "If you're a challenger, I gotta\nwarn ya:\lThe trainers in this GYM are no JOKE!$"

SabrinaGym_Security_Text_4:
	.string "Here, this is for you.\nKeep your cool!$"

SabrinaGym_DontGoIn_Text_0:
	.string "Sorry, if you're a visitor, please\nuse the visitor entrances.$"

SabrinaGym_DontGoIn_Text_1:
	.string "Oh?\nYou're a challenger?\pIn that case, please check in at\nthe front desk to get started.$"

SabrinaGym_Boy_1_Text_0:
	.string "Oh man, oh man, oh man...\nI'm so nervous...\pI already lost, but by friend\nis still in there...$"

SabrinaGym_Boy_1_Text_1:
	.string "The trainers in the GYM are\ncrazy strong!\lI didn't even make it to the GYM LEADER...$"

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
