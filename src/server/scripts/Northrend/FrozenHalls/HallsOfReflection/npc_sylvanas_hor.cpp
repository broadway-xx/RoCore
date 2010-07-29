/* Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Sylvanas
SD%Complete: 80%
SDComment: new script for tc implementation.
SDCategory: Halls of Reflection
EndScriptData */

#include "ScriptPCH.h"
#include "def_hall_of_reflection.h"


//Extern Variable for manage objects

//Texts for Sylvanas story
#define SAY_INFO1 "Trinity script info:"
#define SAY_INFO2 "->Rev: 0.8.5 (alpha 1)"
#define SAY_INFO3 "->Released: 22 july 2010"

#define SAY_ONE "I... I don't believe it! Frostmourne stands before us * unguarded * just as the gnome claimed. Come, heroes!"
#define SAY_TWO "Standing this close to the blade that ended my life... The pain... It is renewed"
#define SAY_THREE "I dare not touch it. Stand back! Stand back as I attempt to commune with the blade! Perhaps our salvation lies within..."
#define SAY_FOUR "Uther... Uther the Lightbringer. How..."
#define SAY_FIVE "The Lich King is here? Then my destiny shall be fulfilled on this day!"
#define SAY_SIX "There must be a way..."
#define SAY_SEVEN "Who could bear such a burden?"
#define SAY_EIGHT "The Frozen Throne..."
#define SAY_NINE "You will not escape me that easily, Arthas! I will have my vengence!"
#define SAY_TEN "I cannot hold him for a long, we must leave at once! Let's go!"
#define SAY_ELEVEN "No wall can hold me Banshee Queen Keep the undead at bay, heroes. I will tear this barrier down!"
#define SAY_TWELVE "Another barrier? Stand strong champions. I will bring the wall down."
#define SAY_13 "I grow tried og these games, Arthas! Your walls can't stop me!"
#define SAY_14 "There's an opening up ahead GO NOW!"
#define SAY_15 "BLASTED DEAD END! So this is how it ends. Prepare yourselves, heroes dor today we make our final stand!"
                                                    
//DEFINE TO SPAWN BOSS
#define FARLIC	  38112
#define MARWYN	  38113
#define GENERAL   36723
#define QUEL      37158  
#define UTHER     37225
#define ARTHAS    37226
#define RIFLEMAN  38176
#define GHOST     38175
#define MAGE      38172
#define MERCE     38177
#define ARTHAS2   37228

//Movement functions
struct Move
{
    float fX, fY, fZ;
};

//Script setup
struct sylvanasAI : public ScriptedAI
{

sylvanasAI(Creature *c) : ScriptedAI(c) 
{
pInstance = c->GetInstanceData();
}
ScriptedInstance* pInstance;


//Timers functions
//Say Timers
uint32 SayOneTimer;
uint32 SayTwoTimer;
uint32 SayThreeTimer;
uint32 SayFourTimer;
uint32 SayFiveTimer;
uint32 SaySixTimer;
uint32 SaySevenTimer;
uint32 SayEightTimer;
uint32 SayNineTimer;
uint32 SayTenTimer;
uint32 SayElevenTimer;
uint32 SayTwelveTimer;
uint32 Say13Timer;

//Objects activation Timers
uint32 ObjActOneTimer;
uint32 ObjActTwoTimer;
uint32 ObjActThreeTimer;	
uint32 ObjActFourTimer;
uint32 ObjActFiveTimer;

//Summon Timers
uint32 SummonOneTimer;
uint32 SummonTwoTimer;
uint32 SummonThreeTimer;

//Movement Timers
uint32 MovementOneTimer;
uint32 MovementTwoTimer;
uint32 MovementThreeTimer;
uint32 MovementFourTimer;
uint32 MovementFiveTimer;
uint32 MovementSixTimer;

//Movement Check

//Waves Timers
uint32 WaveOneTimer;
uint32 WaveTwoTimer;
uint32 WaveThreeTimer;
uint32 WaveFourTimer;
uint32 WaveFiveTimer;
uint32 WaveSixTimer;
uint32 WaveSevenTimer;
uint32 WaveEightTimer;
uint32 WaveNineTimer;
uint32 WaveTenTimer;

//Arthas Object Activation Timers
uint32 ArthasPkgTimer;
uint32 ArthasPkgTwoTimer;

//Movement functions
uint32 m_uiMovePoint;
Move* m_pPointData;

uint32 MovementCHK;

//Timers
void Reset() 
{

//if (pInstance)
//{
//			pInstance->HandleGameObject(pInstance->GetData64(DATA_OBJECT_ONE), true);
//}


//Timers
SummonThreeTimer = 50;
SummonOneTimer = 100;						
ObjActOneTimer = 10000;					
SayOneTimer = 14000; 
SummonTwoTimer = 50000;				
MovementOneTimer = 125000;		
SayTwoTimer = 133000;
SayThreeTimer = 140000;
SayFourTimer = 170000;
SayFiveTimer = 182000; 
SaySixTimer = 207000;
SaySevenTimer = 232000; 
SayEightTimer = 258000; 
ArthasPkgTimer = 270000;		
ArthasPkgTwoTimer = 305000;							
SayNineTimer = 320000; 
WaveOneTimer = 321000;									
WaveTwoTimer = 360000;							
WaveThreeTimer = 410000;				
WaveFourTimer = 463000;			
WaveFiveTimer = 540000;					
WaveSixTimer = 670000;					
WaveSevenTimer = 707000;						
WaveEightTimer = 761000;						
WaveNineTimer = 817000;							
WaveTenTimer = 877000;						
MovementTwoTimer = 950000;						
MovementThreeTimer = 980000;
MovementFourTimer = 985000;	//toto
MovementFiveTimer = 1080000;
MovementSixTimer = 1110000;
ObjActTwoTimer = 1148000;
SayTenTimer = 1168000; 
ObjActThreeTimer = 1184000; 
SayElevenTimer = 1230000;
ObjActFourTimer = 1296000;
ObjActFiveTimer = 1421000;
SayTwelveTimer = 1425000;
Say13Timer = 1445000;

//When function is complete define 1 and stop using it again
MovementCHK = 0;

}

//Script for Sylvanas
void UpdateAI(const uint32 uiDiff)
{

//No combat I use for this
if (!me->getVictim())
{

//Summon ARTHAS and GENERAL (OK)
if (SummonThreeTimer <= uiDiff && MovementCHK == 0)
{                 
     me->SummonCreature(ARTHAS, 5362.586914, 2063.402344, 707.695251, 4.049755, TEMPSUMMON_TIMED_DESPAWN, 305000);
     me->SummonCreature(GENERAL, 5414.322266, 2116.086670, 707.693359, 3.939823, TEMPSUMMON_CORPSE_DESPAWN); 
	   me->MonsterYell(SAY_INFO1, LANG_UNIVERSAL, NULL);
	   me->MonsterYell(SAY_INFO2, LANG_UNIVERSAL, NULL);
	   me->MonsterYell(SAY_INFO3, LANG_UNIVERSAL, NULL);
     MovementCHK = 1;
	   printf("1:%d", MovementCHK);  
	   	me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_DANCESPECIAL);
}
else SummonThreeTimer -= uiDiff;

// Summon Uther (OK)
if (SummonOneTimer <= uiDiff && MovementCHK == 1)
{                 
 	me->SummonCreature(UTHER, 5304.470215, 2000.326904, 709.341370, 3.957872, TEMPSUMMON_TIMED_DESPAWN, 270000);
	MovementCHK = 2;
	printf("2:%d", MovementCHK);
}
else SummonOneTimer -= uiDiff;

// Activate First Doors (YES)
if (ObjActOneTimer <= uiDiff && MovementCHK == 2)
{                 

    pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
  	MovementCHK = 3;
	printf("3:%d", MovementCHK);
}
else ObjActOneTimer -= uiDiff;

// Say something (OK)
if (SayOneTimer <= uiDiff && MovementCHK == 3)
{                 
 	me->MonsterYell(SAY_ONE, LANG_UNIVERSAL, NULL);
	MovementCHK = 4;
	printf("4:%d", MovementCHK);
	me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
}
else SayOneTimer -= uiDiff;

// Summon QUEL (OK)
if (SummonTwoTimer <= uiDiff && MovementCHK == 4)
{                 
       me->SummonCreature(QUEL, 5292.438477, 1986.393066, 707.694763, 3.806288, TEMPSUMMON_CORPSE_DESPAWN);
       MovementCHK = 5;
	   printf("5:%d", MovementCHK);
}
else SummonTwoTimer -= uiDiff;

//Make motion to frostmourne (OK)
if (MovementOneTimer <= uiDiff && MovementCHK == 5)
{                 
       me->GetMotionMaster()->MovePoint(0, 5301.262695, 1997.632935, 708.534363);
       MovementCHK = 6;
	   printf("6:%d", MovementCHK);
}
else MovementOneTimer -= uiDiff;

// Say something (OK)
if (SayTwoTimer <= uiDiff && MovementCHK == 6)
{                 
      me->MonsterYell(SAY_TWO, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 7;
	   printf("7:%d", MovementCHK);
}
else SayTwoTimer -= uiDiff;

// Say something (OK)
if (SayThreeTimer <= uiDiff && MovementCHK == 7)
{                 
      me->MonsterYell(SAY_THREE, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 8;
	   printf("8:%d", MovementCHK);
}
else SayThreeTimer -= uiDiff;

// Say something (OK)
if (SayFourTimer <= uiDiff && MovementCHK == 8)
{                 
      me->MonsterYell(SAY_FOUR, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 9;
	   printf("9:%d", MovementCHK);
}
else SayFourTimer -= uiDiff;

// Say something (OK)
if (SayFiveTimer <= uiDiff && MovementCHK == 9)
{                 
      me->MonsterYell(SAY_FIVE, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 10;
	   printf("10:%d", MovementCHK);
}
else SayFiveTimer -= uiDiff;

// Say something (OK)
if (SaySixTimer <= uiDiff && MovementCHK == 10)
{                 
      me->MonsterYell(SAY_SIX, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 11;
	   printf("11:%d", MovementCHK);
}
else SaySixTimer -= uiDiff;

// Say something (OK)
if (SaySevenTimer <= uiDiff && MovementCHK == 11)
{                 
      me->MonsterYell(SAY_SEVEN, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 12;
	   printf("12:%d", MovementCHK);
}
else SaySevenTimer -= uiDiff;

// Say something (OK)
if (SayEightTimer <= uiDiff && MovementCHK == 12)
{                 
      me->MonsterYell(SAY_EIGHT, LANG_UNIVERSAL, NULL);
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 13;
	   printf("13:%d", MovementCHK);
}
else SayEightTimer -= uiDiff;

// Open Doors in front of the Arthas (NO)
if (ArthasPkgTimer <= uiDiff && MovementCHK == 13)
{                 
       MovementCHK = 14;
	   printf("14:%d", MovementCHK);
}
else ArthasPkgTimer -= uiDiff;

// Close Doors in front of the arthas (NO)
if (ArthasPkgTwoTimer <= uiDiff && MovementCHK == 14)
{                 
      MovementCHK = 15;
	   printf("15:%d", MovementCHK);
}
else ArthasPkgTwoTimer -= uiDiff;

// Say something (OK)
if (SayNineTimer <= uiDiff && MovementCHK == 15)
{                 
      me->MonsterYell(SAY_NINE, LANG_UNIVERSAL, NULL);  
      me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK); 
       MovementCHK = 16;
	   printf("16:%d", MovementCHK);
}
else SayNineTimer -= uiDiff;

// Summon wave and close dfirst door(OK)
if (WaveOneTimer <= uiDiff && MovementCHK == 16)
{                 
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), false);// DATA_OBJECT_ONE was a door, not for sure what the others were. 
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), false); // check orig file for which ones were where...
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
   
       MovementCHK = 17;
	   printf("17:%d", MovementCHK);
}
else WaveOneTimer -= uiDiff;

// Summon wave (OK)
if (WaveTwoTimer <= uiDiff && MovementCHK == 17)
{                
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 18;
	   printf("18:%d", MovementCHK);
}
else WaveTwoTimer -= uiDiff;

// Summon wave (OK)
if (WaveThreeTimer <= uiDiff && MovementCHK == 18)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 19;
	   printf("19:%d", MovementCHK);
}
else WaveThreeTimer -= uiDiff;

// Summon wave (OK)
if (WaveFourTimer <= uiDiff && MovementCHK == 19)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);

       MovementCHK = 20;
	   printf("20:%d", MovementCHK);
}
else WaveFourTimer -= uiDiff;  

// Summon wave and Farlic (OK)
if (WaveFiveTimer <= uiDiff && MovementCHK == 20)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
	   me->SummonCreature(FARLIC, 5277.700195, 2038.040039, 709.318970, 5.413250, TEMPSUMMON_CORPSE_DESPAWN);
	        
       MovementCHK = 21;
	   printf("21:%d", MovementCHK);
}
else WaveFiveTimer -= uiDiff;

if (WaveSixTimer <= uiDiff && MovementCHK == 21)
{       
	// Summon wave (OK)
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 22;
	   printf("22:%d", MovementCHK);
}
else WaveSixTimer -= uiDiff;

// Summon wave (OK)
if (WaveSevenTimer <= uiDiff && MovementCHK == 22)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 23;
	   printf("23:%d", MovementCHK);
}
else WaveSevenTimer -= uiDiff;

// Summon wave (OK)
if (WaveEightTimer <= uiDiff && MovementCHK == 23)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 24;
	   printf("24:%d", MovementCHK);
}
else WaveEightTimer -= uiDiff;

// Summon wave (OK)
if (WaveNineTimer <= uiDiff && MovementCHK == 24)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 25;
	   printf("25:%d", MovementCHK);
}
else WaveNineTimer -= uiDiff;

// Summon wave and Marwyn (OK)
if (WaveTenTimer <= uiDiff && MovementCHK == 25)
{                 
       me->SummonCreature(RIFLEMAN, 5319.611816, 2036.760864, 707.695068, 4.718950, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5316.850098, 2039.270020, 707.495984, 4.644800, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5314.871094, 2037.455933, 707.695068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5312.124023, 2038.033081, 707.495068, 4.505322, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.157715, 2038.656250, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5306.281738, 2038.199951, 707.695068, 4.869747, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5303.523438, 2037.762329, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5300.168457, 2036.671143, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5297.059570, 2035.660156, 707.695068, 5.026826, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(MERCE, 5295.018066, 2034.377808, 707.695068, 5.234171, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5280.943848, 2019.667114, 707.695068, 5.822434, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5279.434570, 2016.626099, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5277.749023, 2009.310791, 707.695068, 6.136594, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5276.219727, 2005.069824, 707.695068, 0.063895, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5277.263672, 2002.077271, 707.695068, 0.128298, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5279.029785, 1996.664917, 707.695068, 0.235112, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5280.117676, 1992.124268, 707.695068, 0.0552413, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MERCE, 5300.638672, 1975.236694, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       
       me->SummonCreature(RIFLEMAN, 5305.049805, 1974.747437, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5309.342285, 1974.271362, 707.695068, 1.460334, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5313.937500, 1975.395020, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5318.684082, 1976.831177, 707.695068, 2.204106, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5322.992676, 1978.720215, 707.695068, 1.732867, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(MAGE, 5338.338867, 1994.619141, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(RIFLEMAN, 5339.027832, 1998.648682, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5341.509766, 2003.791870, 707.695129, 2.972226, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5342.336914, 2008.628662, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5340.459473, 2013.688599, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
       me->SummonCreature(GHOST, 5338.901855, 2019.606445, 707.695129, 3.496872, TEMPSUMMON_CORPSE_DESPAWN);
	   me->SummonCreature(MARWYN, 5335.755371, 1980.771851, 709.319580, 2.410666, TEMPSUMMON_CORPSE_DESPAWN);
     
       MovementCHK = 26;
	   printf("26:%d", MovementCHK);
}
else WaveTenTimer -= uiDiff;


if (MovementTwoTimer <= uiDiff && MovementCHK == 26)
{      
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
       me->GetMotionMaster()->MovePoint(0, 5472.463379, 2174.545166, 707.695496);
       MovementCHK = 27;
	   printf("27:%d", MovementCHK);
}
else MovementTwoTimer -= uiDiff;

if (MovementThreeTimer <= uiDiff && MovementCHK == 27)
{                 
       me->GetMotionMaster()->MovePoint(0, 5517.002930, 2220.746826, 733.011108);
       MovementCHK = 28;
	   printf("28:%d", MovementCHK);
}
else MovementThreeTimer -= uiDiff;

if (MovementFourTimer <= uiDiff && MovementCHK == 28)
{      
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), false);
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), false);
       me->GetMotionMaster()->MovePoint(0, 5548.434570, 2258.476807, 733.011108);
	   me->SummonCreature(ARTHAS2, 5552.226074, 2264.014160, 733.011047, 4.030910, TEMPSUMMON_CORPSE_DESPAWN);
	   	me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_ATTACK_UNARMED);
       MovementCHK = 29;
	   printf("29:%d", MovementCHK);
}
else MovementFourTimer -= uiDiff;

if (MovementFiveTimer <= uiDiff && MovementCHK == 29)
{                 
       me->GetMotionMaster()->MovePoint(0, 5605.331543, 2197.614502, 731.668335);      
       me->MonsterYell(SAY_TEN, LANG_UNIVERSAL, NULL);
       MovementCHK = 30;
	   printf("30:%d", MovementCHK);
}
else MovementFiveTimer -= uiDiff;

if (MovementSixTimer <= uiDiff && MovementCHK == 30)
{                 
       me->GetMotionMaster()->MovePoint(0, 5541.229492, 2090.813477, 731.246460);     
       MovementCHK = 31;
	   printf("31:%d", MovementCHK);
}
else MovementSixTimer -= uiDiff;

if (ObjActTwoTimer <= uiDiff && MovementCHK == 31)
{                 
       pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
       me->MonsterYell(SAY_ELEVEN, LANG_UNIVERSAL, NULL);
       me->GetMotionMaster()->MovePoint(0, 5521.623047, 2040.331055, 731.446899);      
       MovementCHK = 32;
	   printf("32:%d", MovementCHK);
}
else ObjActTwoTimer -= uiDiff;

if (SayTenTimer <= uiDiff && MovementCHK == 32)
{                 
       me->MonsterYell(SAY_TWELVE, LANG_UNIVERSAL, NULL);
       MovementCHK = 33;
	   printf("33:%d", MovementCHK);
}
else SayTenTimer -= uiDiff;

if (ObjActThreeTimer <= uiDiff && MovementCHK == 33)
{                 
      pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
	   pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
       me->GetMotionMaster()->MovePoint(0, 5452.513184, 1906.470947, 746.387207);
       MovementCHK = 34;
	   printf("34:%d", MovementCHK);
}
else ObjActThreeTimer -= uiDiff;

if (SayElevenTimer <= uiDiff && MovementCHK == 34)
{                 
       me->MonsterYell(SAY_13, LANG_UNIVERSAL, NULL);
       MovementCHK = 35;
	   printf("35:%d", MovementCHK);
}
else SayElevenTimer -= uiDiff;

if (ObjActFourTimer <= uiDiff && MovementCHK == 35)
{                 
      pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
	  pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
       me->GetMotionMaster()->MovePoint(0, 5319.844238, 1749.765503, 771.6022478);
       MovementCHK = 36;
	   printf("36:%d", MovementCHK);
}
else ObjActFourTimer -= uiDiff;

if (ObjActFiveTimer <= uiDiff && MovementCHK == 36)
{                 
       pInstance->HandleGameObject(pInstance->GetData64(GAMEOBJECT_TYPE_DOOR), true);
       me->GetMotionMaster()->MovePoint(0, 5256.429688, 1669.162720, 784.302979);
       MovementCHK = 37;
	   printf("37:%d", MovementCHK);
}
else ObjActFiveTimer -= uiDiff;

if (SayTwelveTimer <= uiDiff && MovementCHK == 37)
{                 
       me->MonsterYell(SAY_14, LANG_UNIVERSAL, NULL);
       	me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 38;
	   printf("38:%d", MovementCHK);
}
else SayTwelveTimer -= uiDiff;

if (Say13Timer <= uiDiff && MovementCHK == 38)
{                 
       me->MonsterYell(SAY_15, LANG_UNIVERSAL, NULL);
       	me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_TALK);
       MovementCHK = 39;
	   printf("39:%d", MovementCHK);
}
else Say13Timer -= uiDiff;



}

}
};

//REGISTRATE SCRIPT
CreatureAI* GetAI_sylvanas(Creature* pCreature)
{
    return new sylvanasAI (pCreature);
}

void AddSC_sylvanas()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_sylvanas_hor";
    newscript->GetAI = &GetAI_sylvanas;
    newscript->RegisterSelf();
}