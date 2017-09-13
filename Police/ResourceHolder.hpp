#ifndef RESSOURCEHOLDER_HPP
#define RESSOURCEHOLDER_HPP

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>


template <typename Resource, typename Identifier>
class ResourceHolder
{

    public:
            void            load(Identifier id, const std::string& filename );

            template <typename Parameter>
            void            load(Identifier id, const std::string& filename, const Parameter& secondParame);

            Resource&       get(Identifier id);
            const Resource& get(Identifier id) const;

            void            insertResource(Identifier id, std::unique_ptr<Resource> resource);


    private:
            std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"
#endif // RESSOURCEHOLDER_HPP
