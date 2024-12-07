#ifndef LOGGINGVISITOR_HPP
#define LOGGINGVISITOR_HPP

#include "Visitor.hpp"
#include "NPC.hpp"
#include "Elf.hpp"
#include "Druid.hpp"
#include "Dragon.hpp"
#include <ostream>

class LoggingVisitor : public Visitor {
    public:
        LoggingVisitor(std::ostream& os);
        void visit(Dragon* Dragon) override;
        void visit(Elf* Elf) override;
        void visit(Druid* Druid) override;
    private:
        std::ostream& os;
};

#endif