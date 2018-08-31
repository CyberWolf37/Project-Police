#ifndef OBJECTBOX_HPP
#define OBJECTBOX_HPP

// GAME Library
#include "Category.hpp"
#include "Foreach.hpp"
#include "Position.hpp"
#include "Settings.hpp"
#include "Animation.hpp"
#include "Utility.hpp"
#include "CommandQueue.hpp"

// SFML Library
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTexture.hpp"

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
    ObjectBox(Category_Layers::Layers layerCategory = Category_Layers::Layers::SceneNone);
    ObjectBox(const Position& position,Category_Layers::Layers layerCategory = Category_Layers::Layers::SceneNone);
    ObjectBox(const ObjectBox& object);

    virtual void                    draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void                    handleEvent(const sf::Event& event, const sf::Vector2f &positionMouse);
    virtual void                    update(sf::Time dt, CommandQueue &commands);

    const sf::FloatRect&            getBounds() const;
    void                            setBounds(const sf::FloatRect& bounds);

    virtual bool                    isSelectable() const;

    const bool&                     getIsActive() const;
    void                            setIsActive(const bool& active);

    const bool&                     getIsSelected() const;
    void                            setIsSelected(const bool& selected);

    const Category_Window::Type&    getCategoryWindow() const;
    void                            setCategoryWindow(const Category_Window::Type& category);

    const Category_Layers::Layers&  getCategoryLayers() const;
    void                            setCategoryLayers(const Category_Layers::Layers& category);

    Position&                       getPosition() const;

private:
    const sf::RectangleShape        drawBoundsWindow();

protected:
    Position                    mPosition;
    bool                        mIsActive;
    bool                        mIsSelected;
    sf::FloatRect               mBounds;

    sf::RectangleShape          mFrames;

    Category_Window::Type       mCategoryWindows;
    Category_Layers::Layers     mCategoryLayers;

};

#endif // OBJECTBOX_HPP
