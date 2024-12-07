#ifndef BATTLEVISITOR_HPP
#define BATTLEVISITOR_HPP

#include "Visitor.hpp"
#include "NPC.hpp"
#include "Elf.hpp"
#include "Druid.hpp"
#include "Dragon.hpp"
#include <memory>
#include <vector>

class BattleVisitor : public Visitor {
public:
    BattleVisitor(int range, std::vector<std::unique_ptr<NPC>>& npcs);
    void visit(Dragon* dragon) override;
    void visit(Elf* elf) override;
    void visit(Druid* druid) override;
private:
    int range;
    std::vector<std::unique_ptr<NPC>>& npcs;
};

#endif