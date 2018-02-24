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

std::vector<SbireData> initializeSbireData(const sf::Texture& textures)
{

    std::vector<SbireData> data(Category_Sbires::NoneSbire);

    // Set Worker Sbire data
    data[Category_Sbires::WorkerSbire].lifePoints = 10;
    data[Category_Sbires::WorkerSbire].workPoints = 20;
    data[Category_Sbires::WorkerSbire].defensePoints = 10;
    data[Category_Sbires::WorkerSbire].attackPoints = 10;

    // Set Worker Sbire Animation
    Animation a_moveUp(textures);
    a_moveUp.setFrameSize(sf::Vector2i(24,32));
    a_moveUp.setIndex(sf::Vector2i(0,128));
    a_moveUp.setDuration(sf::seconds(1));
    a_moveUp.setNumFrames(3);
    data[Category_Sbires::WorkerSbire].moveUp = a_moveUp;

    Animation a_moveDown(textures);
    a_moveUp.setFrameSize(sf::Vector2i(24,32));
    a_moveUp.setIndex(sf::Vector2i(0,192));
    a_moveUp.setDuration(sf::seconds(1));
    a_moveUp.setNumFrames(3);
    data[Category_Sbires::WorkerSbire].moveDown = a_moveDown;

    Animation a_moveRight(textures);
    a_moveUp.setFrameSize(sf::Vector2i(24,32));
    a_moveUp.setIndex(sf::Vector2i(0,160));
    a_moveUp.setDuration(sf::seconds(1));
    a_moveUp.setNumFrames(3);
    data[Category_Sbires::WorkerSbire].moveRight = a_moveRight;

    Animation a_moveLeft(textures);
    a_moveUp.setFrameSize(sf::Vector2i(24,32));
    a_moveUp.setIndex(sf::Vector2i(0,224));
    a_moveUp.setDuration(sf::seconds(1));
    a_moveUp.setNumFrames(3);
    data[Category_Sbires::WorkerSbire].moveLeft = a_moveLeft;

    // Set Worker Sbire data
    data[Category_Sbires::OfficeSbire].lifePoints = 20;
    data[Category_Sbires::OfficeSbire].workPoints = 20;
    data[Category_Sbires::OfficeSbire].defensePoints = 20;
    data[Category_Sbires::OfficeSbire].attackPoints = 20;

    // Set Worker Sbire Animation
    data[Category_Sbires::OfficeSbire].moveUp;
    data[Category_Sbires::OfficeSbire].moveDown;
    data[Category_Sbires::OfficeSbire].moveRight;
    data[Category_Sbires::OfficeSbire].moveLeft;

    // Set None Sbire data
    data[Category_Sbires::NoneSbire].lifePoints = 10;
    data[Category_Sbires::NoneSbire].workPoints = 10;
    data[Category_Sbires::NoneSbire].defensePoints = 10;
    data[Category_Sbires::NoneSbire].attackPoints = 10;

    // Set None Sbire Animation
    data[Category_Sbires::NoneSbire].moveUp;
    data[Category_Sbires::NoneSbire].moveDown;
    data[Category_Sbires::NoneSbire].moveRight;
    data[Category_Sbires::NoneSbire].moveLeft;

    return data;


}

