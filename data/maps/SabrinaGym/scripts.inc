SabrinaGym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SabrinaGym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SabrinaGym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_SABRINA_GYM
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


SabrinaGym_Adah::
	trainerbattle_single TRAINER_ADAH, SabrinaGym_Adah_Text_0, SabrinaGym_Adah_Text_1
	msgbox SabrinaGym_Adah_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Louise::
	trainerbattle_single TRAINER_LOUISE, SabrinaGym_Adah_Text_0, SabrinaGym_Adah_Text_1
	msgbox SabrinaGym_Adah_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Reina::
	trainerbattle_single TRAINER_REINA, SabrinaGym_Adah_Text_0, SabrinaGym_Adah_Text_1
	msgbox SabrinaGym_Adah_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Gandalf::
	trainerbattle_single TRAINER_GANDALF, SabrinaGym_Adah_Text_0, SabrinaGym_Adah_Text_1
	msgbox SabrinaGym_Adah_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Spike::
	trainerbattle_single TRAINER_SPIKE, SabrinaGym_Adah_Text_0, SabrinaGym_Adah_Text_1
	msgbox SabrinaGym_Adah_Text_2, MSGBOX_AUTOCLOSE
	end


SabrinaGym_Nurse_Text_0:
	.string "Nurse: Hello there, Challenger!$"

SabrinaGym_Nurse_Text_1:
	.string "May I fresh up your POKéMON?$"

SabrinaGym_Adah_Text_0:
	.string "You wanna play too?\nIt'll be fun...$"

SabrinaGym_Adah_Text_1:
	.string "Tibbers...$"

SabrinaGym_Adah_Text_2:
	.string "Hop, skip, jump!$"
