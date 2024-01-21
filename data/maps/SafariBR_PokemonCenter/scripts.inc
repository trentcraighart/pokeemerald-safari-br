.set LOCALID_NURSE, 1

SafariBR_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariBR_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SafariBR_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_SAFARIBR
	call Common_EventScript_UpdateBrineyLocation
	end

SafariBR_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SafariBR_PokemonCenter_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariBR_PokemonCenter_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariBR_PokemonCenter_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end