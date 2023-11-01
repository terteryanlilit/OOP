#ifndef ITEM_REGISTRY_HPP
#define ITEM_REGISTRY_HPP

#include "../Items/item.hpp"
#include <map>
#include <memory>

using ItemPtr = std::unique_ptr<Item>;
using ItemReg = std::map<std::string, ItemPtr>;
class ItemRegistry{
    public:
        ItemRegistry();
        ItemReg item_reg;
};

#endif //ITEM_REGISTRY_HPP
