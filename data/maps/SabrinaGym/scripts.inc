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
	setflag FLAG_SABRINAGYM_SABRINA_HIDDEN
	setobjectxy 20, 1, 33
	removeobject 20
	delay 30
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SYS_PREVENT_MAP_FADE_IN
	applymovement OBJ_EVENT_ID_PLAYER, SabrinaGym_PlayerEnter
	waitmovement 0
	goto SabrinaGym_Init_1


SabrinaGym_Nurse::
	lock
	msgbox SabrinaGym_Nurse_Text_0
	msgbox SabrinaGym_Nurse_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SabrinaGym_Nurse_2
SabrinaGym_Nurse_1:
	applymovement 2, CommonMovement_NurseBow
	msgbox SabrinaGym_Nurse_Text_3, MSGBOX_AUTOCLOSE
	release
	end

SabrinaGym_Nurse_2:
	msgbox SabrinaGym_Nurse_Text_2
	closemessage
	applymovement 2, CommonMovement_NurseBow
	waitmovement 0
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	delay 30
	goto SabrinaGym_Nurse_1


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
	applymovement 1, CommonMovement_FaceDown
	waitmovement 0
	return


SabrinaGym_DontGoIn_2::
	msgbox SabrinaGym_DontGoIn_2_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteQuestion
	delay 60
	applymovement 19, SabrinaGym_TrainerMoveDown
	waitmovement 0
	applymovement 19, CommonMovement_EmoteExclamation
	delay 60
	return


SabrinaGym_DontGoIn_3::
	msgbox SabrinaGym_DontGoIn_3_Text_0
	msgbox SabrinaGym_DontGoIn_3_Text_1
	msgbox SabrinaGym_DontGoIn_3_Text_2
	msgbox SabrinaGym_DontGoIn_3_Text_3
	msgbox SabrinaGym_DontGoIn_3_Text_4
	msgbox SabrinaGym_DontGoIn_3_Text_5
	closemessage
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


SabrinaGym_Announcement_2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteExclamation
	delay 60
	msgbox SabrinaGym_Announcement_2_Text_0
	msgbox SabrinaGym_Announcement_2_Text_1
	closemessage
	setvar VAR_SABRINAGYM_STATE, 4
	release
	end


SabrinaGym_Announcement_3::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteExclamation
	delay 60
	msgbox SabrinaGym_Announcement_3_Text_0
	msgbox SabrinaGym_Announcement_3_Text_1
	closemessage
	setvar VAR_SABRINAGYM_STATE, 5
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


SabrinaGym_PresentGymLeader::
	applymovement OBJ_EVENT_ID_PLAYER, CommonMovement_EmoteExclamation
	delay 60
	msgbox SabrinaGym_PresentGymLeader_Text_0, MSGBOX_AUTOCLOSE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SabrinaGym_CamUp
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_1, MSGBOX_AUTOCLOSE
	applymovement 10, SabrinaGym_CameraMan_1
	applymovement 11, SabrinaGym_ManDown
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_2, MSGBOX_AUTOCLOSE
	applymovement 11, CommonMovement_EmoteQuestion
	delay 60
	msgbox SabrinaGym_PresentGymLeader_Text_3, MSGBOX_AUTOCLOSE
	applymovement 11, CommonMovement_FaceLeft
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_4, MSGBOX_AUTOCLOSE
	applymovement 11, CommonMovement_FaceRight
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_5, MSGBOX_AUTOCLOSE
	applymovement 11, CommonMovement_FaceDown
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_6, MSGBOX_AUTOCLOSE
	applymovement 11, CommonMovement_WalkRight
	waitmovement 0
	applymovement 10, CommonMovement_FaceLeft
	applymovement 11, CommonMovement_FaceLeft
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_7, MSGBOX_AUTOCLOSE
	addobject 20
	setobjectxy 20, 15, 8
	playse SE_DOOR
	delay 60
	applymovement 20, SabrinaGym_ManDown
	waitmovement 0
	msgbox SabrinaGym_PresentGymLeader_Text_8
	msgbox SabrinaGym_PresentGymLeader_Text_9, MSGBOX_AUTOCLOSE
	trainerbattle_single TRAINER_SABRINA_YOUNG, SabrinaGym_PresentGymLeader_Text_10, SabrinaGym_PresentGymLeader_Text_10
	return


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
	msgbox SabrinaGym_Adah_Text_2
	msgbox SabrinaGym_Adah_Text_3
	msgbox SabrinaGym_Adah_Text_4
	msgbox SabrinaGym_Adah_Text_5
	closemessage
	end


SabrinaGym_Louise::
	trainerbattle_double TRAINER_LOUISE, SabrinaGym_Louise_Text_0, SabrinaGym_Louise_Text_1, SabrinaGym_Louise_Text_2
	msgbox SabrinaGym_Louise_Text_3
	msgbox SabrinaGym_Louise_Text_4
	msgbox SabrinaGym_Louise_Text_5
	closemessage
	end


SabrinaGym_Reina::
	trainerbattle_single TRAINER_REINA, SabrinaGym_Reina_Text_0, SabrinaGym_Reina_Text_1
	msgbox SabrinaGym_Reina_Text_2
	msgbox SabrinaGym_Reina_Text_3
	msgbox SabrinaGym_Reina_Text_4
	closemessage
	end


SabrinaGym_Gandalf::
	trainerbattle_single TRAINER_GANDALF, SabrinaGym_Gandalf_Text_0, SabrinaGym_Gandalf_Text_1
	msgbox SabrinaGym_Gandalf_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Spike::
	trainerbattle_single TRAINER_SPIKE, SabrinaGym_Spike_Text_0, SabrinaGym_Spike_Text_1
	msgbox SabrinaGym_Spike_Text_2
	msgbox SabrinaGym_Spike_Text_3
	msgbox SabrinaGym_Spike_Text_4
	closemessage
	end


SabrinaGym_Paletto::
	trainerbattle_single TRAINER_PALETTO, SabrinaGym_Paletto_Text_0, SabrinaGym_Paletto_Text_1
	msgbox SabrinaGym_Paletto_Text_2
	msgbox SabrinaGym_Paletto_Text_3
	msgbox SabrinaGym_Paletto_Text_4
	closemessage
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

SabrinaGym_CamUp:
	walk_up
	walk_up
	delay_16
	step_end

SabrinaGym_ManDown:
	walk_slow_down
	walk_slow_down
	delay_16
	step_end

SabrinaGym_CameraMan_1:
	walk_left
	face_down
	delay_16
	step_end

CommonMovement_NurseBow:
	nurse_joy_bow
	delay_16
	face_down
	step_end

SabrinaGym_Nurse_Text_0:
	.string "Nurse: Hello there, Challenger!$"

SabrinaGym_Nurse_Text_1:
	.string "May I fresh up your POKéMON?$"

SabrinaGym_Nurse_Text_2:
	.string "Nurse: Very well!\nThis will only take a moment...$"

SabrinaGym_Nurse_Text_3:
	.string "Nurse: Best of luck to you!$"

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

SabrinaGym_DontGoIn_3_Text_1:
	.string "But it's all over now anyway.\nHm? What do you mean?$"

SabrinaGym_DontGoIn_3_Text_2:
	.string "Oh, you had no idea?!\nLet me set some IMPORTANT things\lstraight:$"

SabrinaGym_DontGoIn_3_Text_3:
	.string "You can't just try IMPORTANT BATTLES\nagain and again, like vs a \lGYM LEADER, for example.$"

SabrinaGym_DontGoIn_3_Text_4:
	.string "If you lose, you gotta live with that loss.\nBut, most subordinate trainers will give\lyou tips about their superiors's\lPOKéMON.$"

SabrinaGym_DontGoIn_3_Text_5:
	.string "I lost against the GYM LEADER.\nMy GYM CHALLENGE end here.\pI'm going home.$"

SabrinaGym_DontLeave_Text_0:
	.string "Sorry, but if you leave the GYM,\nyour challenge will be FORFEIT.\lThere is NO GOING BACK or TRYING AGAIN.\lDo you REALLY want to give up?$"

SabrinaGym_Announcement_1_Text_0:
	.string "???: And who do we have here?$"

SabrinaGym_Announcement_1_Text_1:
	.string "Announcer: This young trainer has\njust started the SAFFRON CHALLENGE!$"

SabrinaGym_Announcement_1_Text_2:
	.string "Let's see how good they do.\nGive them a big round of applause!$"

SabrinaGym_Announcement_2_Text_0:
	.string "Announcer: Wow, Challenger {PLAYER} is\ncoming in HOT!$"

SabrinaGym_Announcement_2_Text_1:
	.string "But are they strong enough to make it\nto the GYM LEADER?\lOnly time will tell...$"

SabrinaGym_Announcement_3_Text_0:
	.string "Announcer: Challenger {PLAYER} is\nalmost there!$"

SabrinaGym_Announcement_3_Text_1:
	.string "Victory is close-\nbut the hardest challenge is\lyet to come.$"

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

SabrinaGym_PresentGymLeader_Text_0:
	.string "Announcer: OH MAN, HERE THEY ARE!$"

SabrinaGym_PresentGymLeader_Text_1:
	.string "Announcer: Well, well, well.$"

SabrinaGym_PresentGymLeader_Text_2:
	.string "Congrats on coming this far.\nThe final challenge of SAFFRON GYM\lawaits!$"

SabrinaGym_PresentGymLeader_Text_3:
	.string "Hahaha, no, I'm not the GYM LEADER.\pAhem...$"

SabrinaGym_PresentGymLeader_Text_4:
	.string "DEAR AUDIENCE!$"

SabrinaGym_PresentGymLeader_Text_5:
	.string "IT'S THE MOMENT YOU'VE BEEN\nWAITING FOR!$"

SabrinaGym_PresentGymLeader_Text_6:
	.string "Please, put your hands together for\nthe LEADER of SAFFRON GYM!\pThe girl of mystery,\nthe mistress of PSYCHIC POKéMON...$"

SabrinaGym_PresentGymLeader_Text_7:
	.string "... my darling daughter.\nSABRINA!$"

SabrinaGym_PresentGymLeader_Text_8:
	.string "Announcer: Show 'em what you got, honey.$"

SabrinaGym_PresentGymLeader_Text_9:
	.string "And at least TRY to smile for the camera,\nokay?$"

SabrinaGym_PresentGymLeader_Text_10:
	.string "...$"

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

SabrinaGym_Adah_Text_3:
	.string "A hint about the GYM LEADER?\nHm, I guess I owe you since you beat me.$"

SabrinaGym_Adah_Text_4:
	.string "How about this:\nTheir trademark POKéMON is ALAKAZAM.\lAnd it's real strong. No joke.$"

SabrinaGym_Adah_Text_5:
	.string "I heard it uses a FIGHTING TYPE\nATTACK to deal with DARK TYPE\lPOKéMON.$"

SabrinaGym_Louise_Text_0:
	.string "Can I see into the future?\nMaybe!$"

SabrinaGym_Louise_Text_1:
	.string "I totally saw that coming!$"

SabrinaGym_Louise_Text_2:
	.string "Sorry, but you'll need more\nPOKéMON to fight me!$"

SabrinaGym_Louise_Text_3:
	.string "The future isn't yet written...$"

SabrinaGym_Louise_Text_4:
	.string "Do you think I would have won\nif I used more POKéMON?$"

SabrinaGym_Louise_Text_5:
	.string "The GYM LEADER fights with 4 POKéMON,\nI thought I could take you on with\ljust 3...$"

SabrinaGym_Reina_Text_0:
	.string "POKéMON are our partners,\nin life and in combat!$"

SabrinaGym_Reina_Text_1:
	.string "Ah, farts.$"

SabrinaGym_Reina_Text_2:
	.string "What I said before I read in a\nself-help book, but I guess it\ldidn't make me a winner...$"

SabrinaGym_Reina_Text_3:
	.string "I read too that you can gain the\nadvantage in battle by using\lSTAT-ALTERING moves.$"

SabrinaGym_Reina_Text_4:
	.string "Its a strategy the GYM LEADER uses\non their ESPEON.\pGet their STATS up and pass them on\nwith BATON PASS.$"

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

SabrinaGym_Spike_Text_3:
	.string "Oh, by the way, which POKéMON\ndo you think is better?\pI use BRONZOR, but the GYM LEADER\nuses METANG for STEEL TYPE coverage.$"

SabrinaGym_Spike_Text_4:
	.string "Even with its use of MAGNET RISE,\nI think my BRONZOR could take their\lMETANG any day!$"

SabrinaGym_Paletto_Text_0:
	.string "All eyes are on us now...$"

SabrinaGym_Paletto_Text_1:
	.string "Smile and wave,\njust smile and wave.$"

SabrinaGym_Paletto_Text_2:
	.string "Watching the GYM challenge is\na really popular passtime.\lI'm excited to work at the GYM\lduring GYM SEASON.$"

SabrinaGym_Paletto_Text_3:
	.string "Hm... I was really trying to take\nsome pointers from the GYM LEADER...$"

SabrinaGym_Paletto_Text_4:
	.string "Why? Oh, I use WOBUFFET because of them.\nIt's their OPENING POKéMON!\lBut I guess I still have much to learn...$"
