#include "DataTables.hpp"


using namespace std::placeholders;

std::vector<BuildData> initializeBuildData(const TextureSpliter::MapPtr &ptr)
{
    // Init data vector
    std::vector<BuildData> data(RectangleRoom::TypeBuild::TypeCount);
    std::pair<RectangleRoom::TypeTuile,std::unique_ptr<Tuile>> pairTuileMap;

    // Set the Tuile map for chamber
    std::unique_ptr<Tuile> tuileTopLeft(new Tuile((*ptr)[1]));
    pairTuileMap = std::make_pair(RectangleRoom::TypeTuile::TopLeft, std::move(tuileTopLeft));
    data[RectangleRoom::TypeBuild::Chamber].TuileMap.insert(std::move(pairTuileMap));

    std::unique_ptr<Tuile> tuileTopRight(new Tuile((*ptr)[2]));
    pairTuileMap = std::make_pair(RectangleRoom::TypeTuile::TopRight, std::move(tuileTopRight));
    data[RectangleRoom::TypeBuild::Chamber].TuileMap.insert(std::move(pairTuileMap));

    std::unique_ptr<Tuile> midlleFront(new Tuile((*ptr)[14]));
    pairTuileMap = std::make_pair(RectangleRoom::TypeTuile::MiddleFront, std::move(midlleFront));
    data[RectangleRoom::TypeBuild::Chamber].TuileMap.insert(std::move(pairTuileMap));

    std::unique_ptr<Tuile> midlleSide(new Tuile((*ptr)[13]));
    pairTuileMap = std::make_pair(RectangleRoom::TypeTuile::MiddleSide, std::move(midlleSide));
    data[RectangleRoom::TypeBuild::Chamber].TuileMap.insert(std::move(pairTuileMap));

    std::unique_ptr<Tuile> bottomLeft(new Tuile((*ptr)[7]));
    pairTuileMap = std::make_pair(RectangleRoom::TypeTuile::BottomLeft, std::move(bottomLeft));
    data[RectangleRoom::TypeBuild::Chamber].TuileMap.insert(std::move(pairTuileMap));

    std::unique_ptr<Tuile> bottomRight(new Tuile((*ptr)[8]));
    pairTuileMap = std::make_pair(RectangleRoom::TypeTuile::BottomRight, std::move(bottomRight));
    data[RectangleRoom::TypeBuild::Chamber].TuileMap.insert(std::move(pairTuileMap));

    return data;
}
