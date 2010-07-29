/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "def_hall_of_reflection.h"

struct instance_hall_of_reflection : public ScriptedInstance
{
    instance_hall_of_reflection(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[9];
    std::string strInstData;

    uint64 m_uiFalricGUID;
    uint64 m_uiMarwynGUID;  
    uint64 m_uiLichKingGUID;
    uint64 m_uiLiderGUID;
 
    uint64 m_uiMainGateGUID;
    uint64 m_uiFrostmourneGUID;
    uint64 m_uiExitGateGUID;

    void Initialize()
    {
        m_auiEncounter[0] = 0; 
        m_auiEncounter[1] = 0;
        m_auiEncounter[2] = NOT_STARTED;
        m_uiMainGateGUID = 0;
        m_uiFrostmourneGUID = 0;
        m_uiFalricGUID = 0;
        m_uiLiderGUID = 0;
        m_uiLichKingGUID = 0;
        m_uiExitGateGUID = 0;
    }

    void OnCreatureCreate(Creature* pCreature)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_FALRIC: 
                   m_uiFalricGUID = pCreature->GetGUID(); 
                   pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                   pCreature->SetVisibility(VISIBILITY_OFF);
                   break;
            case NPC_MARWYN: 
                   m_uiMarwynGUID = pCreature->GetGUID();  
                   pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                   pCreature->SetVisibility(VISIBILITY_OFF);
                   break;
            case BOSS_LICH_KING: 
                   m_uiLichKingGUID = pCreature->GetGUID();
                   break;
        }
    }

    void OnObjectCreate(GameObject* pGo)
    {
        switch(pGo->GetEntry())
        {
            case GO_MAIN_GATE: m_uiMainGateGUID = pGo->GetGUID(); break;
            case GO_FROSTMOURNE: m_uiFrostmourneGUID = pGo->GetGUID(); break;
            case GO_EXIT_GATE: m_uiExitGateGUID = pGo->GetGUID(); break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case TYPE_PHASE:
                m_auiEncounter[0] = uiData;
                break;
            case TYPE_LIDER:
                m_auiEncounter[1] = uiData;
                break;
            case TYPE_FALRIC:
                m_auiEncounter[2] = uiData;
                if(uiData == SPECIAL)
                   DoUseDoorOrButton(m_uiExitGateGUID);
                break;
            case TYPE_MARWYN:
                m_auiEncounter[3] = uiData;
                if(uiData == DONE)
                {
                    DoUseDoorOrButton(m_uiMainGateGUID);
                    DoUseDoorOrButton(m_uiExitGateGUID);
                }
                break;
            case TYPE_LICH_KING:
                m_auiEncounter[4] = uiData;
                break;
            case TYPE_ICE_WALL_01:
                m_auiEncounter[5] = uiData;
                break;
            case TYPE_ICE_WALL_02:
                m_auiEncounter[6] = uiData;
                break;
            case TYPE_ICE_WALL_03:
                m_auiEncounter[7] = uiData;
                break;
            case TYPE_ICE_WALL_04:
                m_auiEncounter[8] = uiData;
                break;
        }
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
        {
            case TYPE_PHASE:
                return m_auiEncounter[0];
            case TYPE_LIDER:
                return m_auiEncounter[1];
            case TYPE_FALRIC:
                return m_auiEncounter[2];
            case TYPE_MARWYN:
                return m_auiEncounter[3];
            case TYPE_LICH_KING:
                return m_auiEncounter[4];
            case TYPE_ICE_WALL_01:
                return m_auiEncounter[5];
            case TYPE_ICE_WALL_02:
                return m_auiEncounter[6];
            case TYPE_ICE_WALL_03:
                return m_auiEncounter[7];
            case TYPE_ICE_WALL_04:
                return m_auiEncounter[8];
        }
        return 0;
    }

    void SetData64(uint32 uiData, uint64 uiGuid)
    {
        switch(uiData)
        {
            case DATA_ESCAPE_LIDER:
                   m_uiLiderGUID = uiGuid;
                   break;
        }
    }

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
            case GO_MAIN_GATE: return m_uiMainGateGUID;
            case GO_FROSTMOURNE: return m_uiFrostmourneGUID;
            case NPC_FALRIC: return m_uiFalricGUID;
            case NPC_MARWYN: return m_uiMarwynGUID;
            case BOSS_LICH_KING: return m_uiLichKingGUID;
            case DATA_ESCAPE_LIDER: return m_uiLiderGUID;
        }

        return 0;
    }

};

InstanceData* GetInstanceData_instance_hall_of_reflection(Map* pMap)
{
    return new instance_hall_of_reflection(pMap);
}

void AddSC_instance_hall_of_reflection()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_hall_of_reflection";
    newscript->GetInstanceData = &GetInstanceData_instance_hall_of_reflection;
    newscript->RegisterSelf();
}