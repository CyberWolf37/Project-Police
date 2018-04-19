#ifndef OBJECTBOX_HPP
#define OBJECTBOX_HPP

// GAME Library
#include "Category.hpp"
#include "Foreach.hpp"
#include "Position.hpp"
#include "Settings.hpp"
#include "Animation.hpp"

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics/View.hpp"

// STD library
#include <vector>
#include <set>
#include <memory>
#include <utility>


class ObjectBox : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    // Some Typdef
public:

    typedef std::unique_ptr<ObjectBox> Ptr;

public:
    ObjectBox(Category_Layers::Layers layerCategory = Category_Layers::None);
    ObjectBox(const sf::Texture& texture,Category_Layers::Layers layerCategory = Category_Layers::None);
    ObjectBox(Position& position,const sf::Texture &texture, Category_Layers::Layers layerCategory = Category_Layers::None);

    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            handleEvent(const sf::Event& event, const sf::Vector2i& positionMouse);
    virtual void            update(sf::Time dt, CommandQueue &commands);

    sf::Sprite&             getSprite() const;
    void                    setSprite(const sf::Sprite sprite);

    Animation&              getAnimation() const;
    void                    setAnimation(Animation& animation);

    const bool&             getIsActive() const;
    void                    setIsActive(const bool& active);

    const bool&             getIsSelected() const;
    void                    setIsSelected(const bool& selected);

    const Category_Window&  getCategoryWindow() const;
    void                    setCategoryWindow(const Category_Window& category);

    const Category_Layers&  getCategoryLayers() const;
    void                    setCategoryLayers(const Category_Layers& category);

private:
    sf::RenderTarget        drawBoundsWindow();

private:

    Position                mPosition;
    bool                    mIsActive;
    bool                    mIsSelected;

    sf::Sprite              mSprite;
    Animation*              mAnimation;

    Category_Window         mCategoryWindows;
    Category_Layers         mCategoryLayers;

};

#endif // OBJECTBOX_HPP
