/*
* Copyright (c) 2025 SylCore
* This software is licensed under the MIT License. See LICENSE file for details.
*
* This module has been updated to work on SylCore by Sylian.
* The original module was created by AnchyDev [https://github.com/AnchyDev] and is used with respect to its original MIT license.
*
* SylCore -> https://github.com/SylCore
* SylCore Discord -> https://discord.gg/BQBD5MqspY
* Sylian -> https://github.com/Sylian1337
*/



#ifndef MODULE_STAT_BOOST_REROLL_H
#define MODULE_STAT_BOOST_REROLL_H

#include "ScriptMgr.h"
#include "Player.h"
#include "StatBoostMgr.h"
#include "Spell.h"
#include "Config.h"

class StatBoosterRerollPlayerScript : public PlayerScript
{
public:
    StatBoosterRerollPlayerScript() : PlayerScript("StatBoosterRerollPlayerScript") { }

    virtual bool OnPlayerCanCastItemUseSpell(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/, uint8 /*cast_count*/, uint32 /*glyphIndex*/) override;
};

#endif // MODULE_STAT_BOOST_REROLL_H
