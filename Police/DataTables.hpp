#ifndef DATATABLES_H
#define DATATABLES_H

// Core Library
#include "ResourceIdentifiers.hpp"
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

struct BuildData
{
    int                                         hitpoints;
    std::map<RectangleRoom::TypeTuile,Tuile>    TuileMap;
};

std::vector<BuildData>       initializeBuildData();

#endif // DATATABLES_H
