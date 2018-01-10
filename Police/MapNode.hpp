#ifndef MAPGAME_HPP
#define MAPGAME_HPP

// Game Library
#include "IOFile.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Build.hpp"
#include "Component.hpp"
#include "SceneNode.hpp"
#include "Foreach.hpp"

class MapGame : public SceneNode
{
    typedef std::vector<std::unique_ptr<BUILD_OBJECT::Build>>   vBuild;
    typedef std::vector<std::unique_ptr<GUI::Component>>        vComponent;

    typedef std::unique_ptr<BUILD_OBJECT::Build>                PtrBuild;
    typedef std::unique_ptr<GUI::Component>                     PtrComponent;

public:
    MapGame(size_t x,size_t y,const FileHolder& file,const TextureSplite& textureSplit);
    MapGame(sf::Vector2i size,IOFile::File& file,Textures& textureSplit);

    bool            insertObject(PtrBuild objectBuild);
    bool            insertObject(PtrComponent objectComponent);

    vBuild&         findObject(sf::Vector2i& position);
    vComponent&     findObject(sf::Vector2i& position);

public:
    // SceneNode Virtual function
    void            handleChildrenEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    virtual void    updateCurrent(sf::Time dt, CommandQueue& commands);
    void            updatechildren(sf::Time dt, CommandQueue& commands);

    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void    drawCurrent (sf::RenderTarget& target, sf::RenderStates states) const;
    void            drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    bool            createMapScene();

    void            handleBuildEvent(const sf::Event& event, const sf::Vector2i& positionMouse);
    void            handleComponentEvent(const sf::Event& event, const sf::Vector2i& positionMouse);

    void            updateBuild(sf::Time dt, CommandQueue &commands);
    void            updateComponent(sf::Time dt, CommandQueue &commands);

private:
    const sf::Vector2u      m_size;
    const FileHolder        m_file;
    const TextureHolder     m_texture;

    vBuild                  m_buildStack;
    vComponent              m_componentStack;



};

#endif // MAPGAME_HPP
