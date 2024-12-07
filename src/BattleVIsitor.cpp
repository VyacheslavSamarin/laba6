#include "BattleVisitor.hpp"
#include <iostream>
#include <vector>

BattleVisitor::BattleVisitor(int range, std::vector<std::unique_ptr<NPC>>& npcs)
    : range(range), npcs(npcs) {}

void BattleVisitor::visit(Elf* elf) {
    std::cout << "Elf " << elf->getName() << " is attacking a Druid!\n";
    std::vector<size_t> indicesToRemove;
    for (size_t i = 0; i < npcs.size(); ++i) {
        NPC* npc = npcs[i].get();
        if (dynamic_cast<Druid*>(npc) && abs(elf->getX() - npc->getX()) <= range && abs(elf->getY() - npc->getY()) <= range) {
            if (elf->fight(npc)) {
                std::cout << "Elf " << elf->getName() << " killed Druid " << npc->getName() << "!\n";
                indicesToRemove.push_back(i);
            }
        }
    }
    for (auto it = indicesToRemove.rbegin(); it != indicesToRemove.rend(); ++it) {
        npcs.erase(npcs.begin() + *it);
    }
}

void BattleVisitor::visit(Druid* druid) {
    std::cout << "Druid " << druid->getName() << " is attacking a Dragon!\n";
    std::vector<size_t> indicesToRemove;
    for (size_t i = 0; i < npcs.size(); ++i) {
        NPC* npc = npcs[i].get();
        if (dynamic_cast<Dragon*>(npc) && abs(druid->getX() - npc->getX()) <= range && abs(druid->getY() - npc->getY()) <= range) {
            if (druid->fight(npc)) {
                std::cout << "Druid " << druid->getName() << " killed Dragon " << npc->getName() << "!\n";
                indicesToRemove.push_back(i);
            }
        }
    }
    for (auto it = indicesToRemove.rbegin(); it != indicesToRemove.rend(); ++it) {
        npcs.erase(npcs.begin() + *it);
    }
}

void BattleVisitor::visit(Dragon* dragon) {
    std::cout << "Dragon " << dragon->getName() << " is attacking an Elf!\n";
    std::vector<size_t> indicesToRemove;
    for (size_t i = 0; i < npcs.size(); ++i) {
        NPC* npc = npcs[i].get();
        if (dynamic_cast<Elf*>(npc) && abs(dragon->getX() - npc->getX()) <= range && abs(dragon->getY() - npc->getY()) <= range) {
            if (dragon->fight(npc)) {
                std::cout << "Dragon " << dragon->getName() << " killed Elf " << npc->getName() << "!\n";
                indicesToRemove.push_back(i);
            }
        }
    }
    for (auto it = indicesToRemove.rbegin(); it != indicesToRemove.rend(); ++it) {
        npcs.erase(npcs.begin() + *it);
    }
}