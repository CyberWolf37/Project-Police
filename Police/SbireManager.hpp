#ifndef SBIREMANAGER_H
#define SBIREMANAGER_H

// Core Library
#include "Sbires.hpp"
#include "Category.hpp"
#include "SceneNode.hpp"
#include "Foreach.hpp"

// SFML Library
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"

// STD Libraryy
#include <vector>
#include <memory>

// Test Debug
#include <QDebug>


class SbireManager
{
public:
    typedef std::shared_ptr<Sbires>             SbirePtr;
    typedef std::vector<SbirePtr>               SbireStack;

public:
    SbireManager(SceneNode& sceneGraph);

    void                    createSbire(Category_Sbires::ID category,sf::Vector2i& position);
    void                    setTexture(sf::Texture& texture);
    sf::Texture&            getTexture();

    SbireStack&             getSbireStack();
    SbirePtr&               getSbireActive();

private:
    SbireStack              mStackSbire;
    SceneNode&              mSceneGraph;
    sf::Texture             mTextureSbire;



};

#endif // SBIREMANAGER_H
