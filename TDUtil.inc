#include <a_samp>

#define TAG_PLAYER_TEXT 0xC0000008
#define TAG_TEXT 0xC000000C

#define ShowPlayerTextDrawForPlayer ShowTextDrawForPlayer
#define HidePlayerTextDrawForPlayer HideTextDrawForPlayer

stock ShowTextDrawForPlayer(const playerid, const {PlayerText,Text}:textDraw, const timeToDisplayInMs = 0)
{	
	new textDrawTag = tagof(textDraw);

	if(textDrawTag == TAG_TEXT)
	{
		TextDrawShowForPlayer(playerid, Text:textDraw);

		if(timeToDisplayInMs >= 1)
		{
			SetTimerEx(
				"HideTextDrawForPlayerPub",
				timeToDisplayInMs,
				false,
				"dd",
				playerid, _:textDraw);
		}
	}
	else if(textDrawTag == TAG_PLAYER_TEXT)
	{
		PlayerTextDrawShow(playerid, PlayerText:textDraw);

		if(timeToDisplayInMs >= 1)
		{
			SetTimerEx(
				"HideTextDrawForPlayerPub",
				timeToDisplayInMs,
				false,
				"dd",
				playerid, _:textDraw);
		}		
	}
}

stock ShowTextDrawForAll(const Text:textDraw, const timeToDisplayInMs = 0)
{
	TextDrawShowForAll(Text:textDraw);

	if(timeToDisplayInMs >= 1)
	{
		SetTimerEx("HideTextDrawForAllPub", timeToDisplayInMs, false, "d", textDraw);
	}

	return true;
}

stock HideTextDrawForPlayer(const playerid, const {PlayerText,Text}:textDraw, const timeToWaitBeforeHidingInMs = 0)
{
	new textDrawTag = tagof(textDraw);

	if(textDrawTag == TAG_TEXT)
	{
		if(timeToWaitBeforeHidingInMs >= 1)
		{
			SetTimerEx(
				"HideTextDrawForPlayerPub",
				timeToWaitBeforeHidingInMs,
				false,
				"dd",
				playerid, _:textDraw);
		}
		else
		{
			TextDrawHideForPlayer(playerid, Text:textDraw);
		}
	}
	else if(textDrawTag == TAG_PLAYER_TEXT)
	{
		if(timeToWaitBeforeHidingInMs >= 1)
		{
			SetTimerEx(
				"HideTextDrawForPlayerPub", 
				timeToWaitBeforeHidingInMs,
				false, 
				"dd", 
				playerid, _:textDraw);
		}
		else
		{
			PlayerTextDrawHide(playerid, PlayerText:textDraw);
		}
	}
}

forward HideTextDrawForPlayerPub(const playerid, const {PlayerText,Text}:textDraw);
public HideTextDrawForPlayerPub(const playerid, const {PlayerText,Text}:textDraw)
{
	HideTextDrawForPlayer(playerid, textDraw);
}

stock HideTextDrawForAll(const Text:textDraw, const timeToWaitBeforeHidingInMs = 0)
{
	if(timeToWaitBeforeHidingInMs >= 1)
	{
		SetTimerEx(
			"HideTextDrawForAllPub",
			timeToWaitBeforeHidingInMs,
			false,
			"d",
			_:textDraw);
	}
	else
	{
		TextDrawHideForAll(Text:textDraw);
	}
}

forward HideTextDrawForAllPub(const Text:textDraw);
public HideTextDrawForAllPub(const Text:textDraw)
{
	HideTextDrawForAll(Text:textDraw);
}