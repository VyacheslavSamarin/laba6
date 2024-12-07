#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "NPC.hpp"
#include "Elf.hpp"

class Dragon : public NPC {
    public:
        Dragon(const std::string& name, int x, int y);
        void accept(Visitor& visitor) override;
        bool fight(NPC* other) override;
        const std::string& getType() const override { return type; }
    private:
        static const std::string type;
};

#endif