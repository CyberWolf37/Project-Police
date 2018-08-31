#include "ObjectBox.hpp"

ObjectBox::ObjectBox(Category_Layers::Layers layerCategory)
    :mPosition(*this)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mBounds(0.f,0.f,PIXEL,PIXEL)
    ,mFrames()
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    mPosition.setPositionTuile(sf::Vector2i(0,0));
    centerOrigin(mFrames);

}

ObjectBox::ObjectBox(const Position &position, Category_Layers::Layers layerCategory)
    :mPosition(position)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mBounds(0.f,0.f,PIXEL,PIXEL)
    ,mFrames()
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    centerOrigin(mFrames);
}

ObjectBox::ObjectBox(const ObjectBox &object)
    :mPosition(object.getPosition())
    ,mIsActive(object.getIsActive())
    ,mIsSelected(object.getIsSelected())
    ,mBounds(object.getBounds())
    ,mFrames()
    ,mCategoryLayers(object.getCategoryLayers())
    ,mCategoryWindows(object.getCategoryWindow())
{
    // Settings
    centerOrigin(mFrames);
}

void ObjectBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    if(mIsSelected && mCategoryWindows != Category_Window::Type::None)
    {
        target.draw(drawBoundsWindow(),states);
    }
}

void ObjectBox::handleEvent(const sf::Event &event, const sf::Vector2f &positionMouse)
{
    if(mBounds.contains(positionMouse) && mIsActive)
    {
        mIsSelected = true;
        mCategoryWindows = Category_Window::Type::Selected;
    }
    else if(mIsSelected && mIsActive && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        mCategoryWindows = Category_Window::Type::Activate;
    }
    else
    {
        mIsSelected = false;
        mCategoryWindows = Category_Window::Type::None;
    }
}

void ObjectBox::update(sf::Time dt, CommandQueue &commands)
{
    // Do nothing by default
}

const sf::FloatRect &ObjectBox::getBounds() const
{
    return mBounds;
}

void ObjectBox::setBounds(const sf::FloatRect &bounds)
{
    mBounds = bounds;
}

bool Button::isSelectable() const
{
    return true;
}

const bool &ObjectBox::getIsActive() const
{
    return mIsActive;
}

void ObjectBox::setIsActive(const bool &active)
{
    mIsActive = active;
}

const bool &ObjectBox::getIsSelected() const
{
    return mIsSelected;
}

void ObjectBox::setIsSelected(const bool &selected)
{
    mIsSelected = selected;
}

const Category_Window::Type &ObjectBox::getCategoryWindow() const
{
    return mCategoryWindows;
}

void ObjectBox::setCategoryWindow(Category_Window::Type &category)
{
    mCategoryWindows = category;
}

const Category_Layers::Layers &ObjectBox::getCategoryLayers() const
{
    return mCategoryLayers;
}

void ObjectBox::setCategoryLayers(const Category_Layers::Layers &category)
{
    mCategoryLayers = category;
}

Position &ObjectBox::getPosition() const
{
    return mPosition;
}

const sf::RectangleShape ObjectBox::drawBoundsWindow()
{
    mFrames.setPosition(mPosition.getPositionRaw());
    mFrames.setSize(mBounds);
    mFrames.setOutlineThickness(-4.f);

    if(mCategoryWindows == Category_Window::Type::Selected)
    {
        mFrames.setOutlineColor(sf::Color::Cyan);
    }
    else if(mCategoryWindows == Category_Window::Type::Activate)
    {
        mFrames.setOutlineColor(sf::Color::Green);
    }
    else if(mCategoryWindows == Category_Window::Type::None)
    {
        mFrames.setOutlineColor(sf::Color::Transparent);
    }

    return mFrames;
}
