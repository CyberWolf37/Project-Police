#include "ObjectBox.hpp"

ObjectBox::ObjectBox(Category_Layers::Layers layerCategory)
    :mPosition(*this)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mSprite()
    ,mAnimation(nullptr)
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    mPosition.setPositionTuile(sf::Vector2i(0,0));
    mSprite.setTextureRect(sf::IntRect(PIXEL,PIXEL,mPosition.getPositionRaw().x,mPosition.getPositionRaw().y));

}

ObjectBox::ObjectBox(const sf::Texture &texture, Category_Layers::Layers layerCategory)
    :mPosition(position)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mSprite(texture)
    ,mAnimation(nullptr)
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    mPosition.setPositionTuile(sf::Vector2i(0,0));
}

ObjectBox::ObjectBox(Position &position, const sf::Texture &texture, Category_Layers::Layers layerCategory)
    :mPosition(position)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mSprite(texture)
    ,mAnimation(nullptr)
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings

}
