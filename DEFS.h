#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	SET_FLAG_CELL,	// Set Flag on a Cell
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	///TODO: Add more action types of Design Mode
	SET_ANTENNA, // set antenna 
	SET_BELT, // set belt
	SET_WATER_PIT, //set water bit
	SET_DANGER_ZONE, // set danger zone
	SET_WORKSHOP, //set workshop
	SET_ROTATING_GEAR_CLOCK, // set rotating gear clock
	SET_ROTATING_GEAR_ANTI_CLOCK,
	ADD_BELT,
	ADD_ROTATINGGEAR,
	ADD_FLAG,
	COPY_GAME_OBJECT,
	CUT_GAME_OBJECT,
	PASTE_GAME_OBJECT,
	DELETE_GAME_OBJECT,
	SAVE_GRID,
	OPEN_GRID, // LOAD OR OPEN



	//  [2] Actions of Play Mode

	EXECUTE_COMMANDS,	// Execute the saved commands
	SELECT_COMMAND,		// Select a command from the available ones to be executed

	TO_DESIGN_MODE,	// Go to Design Mode

	///TODO: Add more action types of Play Mode
	REPOOT_AND_REPAIR,
	USE_CONSUMABLE,
	NEW_GAME,
	// EXIT, IS DEFINIED ABOVE NO NEED FOR DEFINE AGAING

	//  [3] Others

	EMPTY,							// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,						// Inside Grid Area
	STATUS 							// Inside StatusBar Area
};

enum Direction // Directions of the game
{
	RIGHT,
	UP,
	LEFT,
	DOWN,
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,

	COMMANDS_COUNT,
};

enum Type
{
	Flags,
	WaterPits,
	DangerZones,
	Belts,
	Workshops,
	Antennas,
	RotatingGears,
};

#endif