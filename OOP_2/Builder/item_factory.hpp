#ifndef ITEM_FACTORY_HPP
#define ITEM_FACTORY_HPP

#include <map>
#include <functional>

#include "../item_builder/item_builder.hpp"



class ItemBuilderFactory{
    public:
        ItemBuilderFactory();
        ItemPtr create_item(std::string);
};

#endif //ITEM_FACTORY_HPP
