#include "DataTables.hpp"


using namespace std::placeholders;

std::vector<BuildData> initializeBuildData()
{
    std::vector<BuildData> data(RectangleRoom::TypeBuild::TypeCount);

    data[RectangleRoom::TypeBuild::Chamber].hitpoints = 100;

    // Set the Tuile map
    data[RectangleRoom::TypeBuild::Chamber].TuileMap[RectangleRoom::TypeTuile::TopLeft]       =
    data[RectangleRoom::TypeBuild::Chamber].TuileMap[RectangleRoom::TypeTuile::TopRight]      =
    data[RectangleRoom::TypeBuild::Chamber].TuileMap[RectangleRoom::TypeTuile::MiddleFront]   =
    data[RectangleRoom::TypeBuild::Chamber].TuileMap[RectangleRoom::TypeTuile::MiddleSide]    =
    data[RectangleRoom::TypeBuild::Chamber].TuileMap[RectangleRoom::TypeTuile::BottomLeft]    =
    data[RectangleRoom::TypeBuild::Chamber].TuileMap[RectangleRoom::TypeTuile::BottomRight]   =

    return data;
}
