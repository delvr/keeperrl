#include "stdafx.h"
#include "saved_game_info.h"
#include "text_serialization.h"
#include "parse_game.h"

ViewId SavedGameInfo::getViewId() const {
  return minions[0].viewId;
}

OldSavedGameInfo getOldInfo(const SavedGameInfo& info) {
  CHECK(!info.retiredEnemyInfo);
  return OldSavedGameInfo{info.minions, 0, info.name, info.progressCount, info.spriteMods};
}

SavedGameInfo fromOldInfo(const OldSavedGameInfo& info) {
  return SavedGameInfo{info.minions, none, info.name, info.progressCount, info.spriteMods};
}
