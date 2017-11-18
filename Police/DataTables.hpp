#ifndef DATATABLES_H
#define DATATABLES_H

// Core Library
#include "ResourceIdentifiers.hpp"
#include "TextureSpliter.hpp"
#include "ResourceHolder.hpp"
#include "Tuile.hpp"
#include "RectangleRoom.hpp"

// SFML Library
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"

// STD Library
#include <vector>
#include <map>
#include <functional>

using namespace BUILD_OBJECT;

struct BuildData
{
    std::map<RectangleRoom::TypeTuile,std::unique_ptr<Tuile>>    TuileMap;
};

std::vector<BuildData>       initializeBuildData(const TextureSpliter::MapPtr &ptr);

#endif // DATATABLES_H
