#include "Druid.hpp"

Druid::Druid(const std::string& name, int x, int y) : NPC(name, x, y) {}
void Druid::accept(Visitor& Visitor) {Visitor.visit(this);}
bool Druid::fight(NPC* other) { return dynamic_cast<Dragon*>(other) != nullptr; }

const std::string Druid::type = "Druid";