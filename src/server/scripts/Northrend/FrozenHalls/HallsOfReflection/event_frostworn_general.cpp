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
 SDName: boss_general_frostsworn
 SD%Complete: 0%
 SDComment: new script for tc implementation.
 SDCategory: Halls of Reflection
 EndScriptData */

#include "ScriptPCH.h"
#include "def_hall_of_reflection.h"

enum
{
   SAY_AGGRO                    = -1594519,
   SAY_DEATH                    = -1594520,

   SPELL_SHIELD_THROWN_N        = 69222,
   SPELL_SHIELD_THROWN_H        = 73076,
   SPELL_SPIKE                  = 59446   // this is not right spell!
};

struct npc_frostworn_generalAI : public ScriptedAI
{
   npc_frostworn_generalAI(Creature *pCreature) : ScriptedAI(pCreature)
   {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Regular = pCreature->GetMap()->IsRegularDifficulty();
        Reset();
   }

   ScriptedInstance* m_pInstance;
   bool Regular;

   uint32 m_uiShieldTimer;
   uint32 m_uiSpikeTimer;

   void Reset()
   {
      m_uiShieldTimer = 5000;
      m_uiSpikeTimer = 14000;
   }

    void JustDied(Unit* pKiller)
    {
      DoScriptText(SAY_DEATH, me);
    }

    void Aggro(Unit* pVictim)
    {
      DoScriptText(SAY_AGGRO, me);
    }

   void UpdateAI(const uint32 uiDiff)
   {
        if(!UpdateVictim())
            return;

        if(m_uiShieldTimer < uiDiff)
        { 
      if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
               DoCast(pTarget, Regular ? SPELL_SHIELD_THROWN_N : SPELL_SHIELD_THROWN_H);
            m_uiShieldTimer = urand(8000, 12000);
        } else m_uiShieldTimer -= uiDiff;

        if (m_uiSpikeTimer < uiDiff) 
        {
            if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
               DoCast(pTarget, SPELL_SPIKE);
            m_uiSpikeTimer = urand(15000, 20000);
        } else m_uiSpikeTimer -= uiDiff;

        DoMeleeAttackIfReady();
   }
};

CreatureAI* GetAI_npc_frostworn_general(Creature* pCreature)
{
    return new npc_frostworn_generalAI(pCreature);
}

void AddSC_event_frostworn_general()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_frostworn_general";
    newscript->GetAI = &GetAI_npc_frostworn_general;
    newscript->RegisterSelf();
}