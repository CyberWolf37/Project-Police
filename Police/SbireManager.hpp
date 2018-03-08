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


class SbireManager
{
public:
    typedef std::shared_ptr<Sbires>              SbirePtr;

    typedef std::vector<SbirePtr>               SbireStack;

public:
    SbireManager(SceneNode& sceneGraph, sf::Texture& texture);

    void                    createSbire(Category_Sbires::ID category);
    void                    update(sf::Time dt);

private:
    SbireStack              mStackSbire;
    SceneNode&              mSceneGraph;
    sf::Texture&            mTextureSbire;



};

#endif // SBIREMANAGER_H
