#ifndef DATATABLES_H
#define DATATABLES_H

// Core Library
#include "ResourceIdentifiers.hpp"
#include "TextureSpliter.hpp"
#include "ResourceHolder.hpp"
#include "Tuile.hpp"
#include "RectangleRoom.hpp"
#include "Category.hpp"
#include "Animation.hpp"

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

struct SbireData
{
    // Sbire points
    int lifePoints = 0;
    int workPoints = 0;
    int defensePoints = 0;
    int attackPoints = 0;

    // Sbire Animation
    Animation moveUp;
    Animation moveDown;
    Animation moveRight;
    Animation moveLeft;

};

std::vector<BuildData>      initializeBuildData(const TextureSpliter::MapPtr &ptr);
std::vector<SbireData>      initializeSbireData(const sf::Texture& textures);

#endif // DATATABLES_H
