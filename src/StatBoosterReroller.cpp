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

#include "StatBoosterReroller.h"

bool StatBoosterRerollPlayerScript::OnPlayerCanCastItemUseSpell(Player* player, Item* item, SpellCastTargets const& targets, uint8 /*cast_count*/, uint32 /*glyphIndex*/)
{
    if (!item)
    {
        return true;
    }

    auto itemTemplate = item->GetTemplate();
    if (!itemTemplate)
    {
        return true;
    }

    if (itemTemplate->ItemId != 41605)
    {
        return true;
    }

    if (!sConfigMgr->GetOption<bool>("StatBoostReroll.Enable", false))
    {
        ChatHandler(player->GetSession()).SendSysMessage("This item is disabled.");
        return false;
    }

    auto targetItem = targets.GetItemTarget();
    if (!targetItem)
    {
        return false;
    }

    if (sConfigMgr->GetOption<bool>("StatBoostReroll.AllowOwnedItemsOnly", true) &&
        targetItem->GetOwner()->GetGUID() != player->GetGUID())
    {
        ChatHandler(player->GetSession()).SendSysMessage("You cannot re-roll items other than your own.");
        return false;
    }

    if (StatBoostMgr::BoostItem(player, targetItem, 100))
    {
        player->DestroyItemCount(itemTemplate->ItemId, 1, true);

        uint32 visualId = sConfigMgr->GetOption<uint32>("StatBoostReroll.VisualId", 62015);
        player->CastSpell(player, visualId);
        //player->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
    }
    else
    {
        ChatHandler(player->GetSession()).SendSysMessage("You cannot re-roll this item.");
    }

    return false;
}

void AddStatBoostRerollScripts()
{
    new StatBoosterRerollPlayerScript();
}
