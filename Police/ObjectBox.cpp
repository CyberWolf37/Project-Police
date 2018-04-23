#include "ObjectBox.hpp"

ObjectBox::ObjectBox(Category_Layers::Layers layerCategory)
    :mPosition(*this)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mSprite()
    ,mAnimation(nullptr)
    ,mWindows()
    ,mSpriteBackGround()
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    mPosition.setPositionTuile(sf::Vector2i(0,0));

    // Settings position
    mSpriteBackGround.setTextureRect(sf::IntRect(mPosition.getPositionRaw().x,mPosition.getPositionRaw().y,PIXEL,PIXEL));
    centerOrigin(mSpriteBackGround);

}

ObjectBox::ObjectBox(const sf::Texture &texture, Category_Layers::Layers layerCategory)
    :mPosition(position)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mSprite(texture)
    ,mAnimation(nullptr)
    ,mWindows()
    ,mSpriteBackGround()
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    mPosition.setPositionTuile(sf::Vector2i(0,0));

    // Settings position
    mSpriteBackGround.setTextureRect(sf::IntRect(mPosition.getPositionRaw().x,mPosition.getPositionRaw().y,PIXEL,PIXEL));
    centerOrigin(mSpriteBackGround);
}

ObjectBox::ObjectBox(Position &position, const sf::Texture &texture, Category_Layers::Layers layerCategory)
    :mPosition(position)
    ,mIsActive(false)
    ,mIsSelected(false)
    ,mSprite(texture)
    ,mAnimation(nullptr)
    ,mWindows()
    ,mSpriteBackGround()
    ,mCategoryLayers(layerCategory)
    ,mCategoryWindows(Category_Window::Type::None)
{
    // Settings
    mPosition.setPositionTuile(sf::Vector2i(0,0));

    // Settings position
    mSpriteBackGround.setTextureRect(sf::IntRect(mPosition.getPositionRaw().x,mPosition.getPositionRaw().y,PIXEL,PIXEL));
    centerOrigin(mSpriteBackGround);

    // Settings Sprite
    centerOrigin(mSprite);
    mSprite.setPosition(mSpriteBackGround.getOrigin());
}

void ObjectBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    if(mIsSelected && mCategoryWindows != Category_Window::Type::None)
    {
        target.draw(drawBoundsWindow(),states);
    }

    if(mAnimation != nullptr)
    {
        mAnimation->draw(target,states);
    }
    else
    {
        target.draw(mSprite,States);
    }
}

void ObjectBox::handleEvent(const sf::Event &event, const sf::Vector2f &positionMouse)
{
    if(mSpriteBackGround.getLocalBounds().contains(positionMouse) && mIsActive)
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
    if(mAnimation != nullptr)
    {
        mAnimation->update(dt);
    }

}

sf::Sprite &ObjectBox::getSprite() const
{
    return mSprite;
}

void ObjectBox::setSprite(const sf::Sprite &sprite)
{
    mSprite = sprite;
}

void ObjectBox::setTextureBackground(const sf::Texture &texture)
{
    mSpriteBackGround.setTexture(texture);
}

Animation &ObjectBox::getAnimation() const
{
    return mAnimation;
}

void ObjectBox::setAnimation(Animation &animation)
{
    mAnimation = animation;
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

const Category_Window &ObjectBox::getCategoryWindow() const
{
    return mCategoryWindows;
}

void ObjectBox::setCategoryWindow(const Category_Window &category)
{
    mCategoryWindows = category;
}

const Category_Layers &ObjectBox::getCategoryLayers() const
{
    return mCategoryLayers;
}

void ObjectBox::setCategoryLayers(const Category_Layers &category)
{
    mCategoryLayers = category;
}

const sf::RectangleShape ObjectBox::drawBoundsWindow()
{
    sf::FloatRect bounds(mSpriteBackGround.getLocalBounds());
    texture.create(bounds.width,bounds.height);

    mWindows.setSize(sf::Vector2f(bounds.width,bounds.height));
    mWindows.setOutlineThickness(-4.f);

    if(mCategoryWindows == Category_Window::Type::Selected)
    {
        mWindows.setOutlineColor(sf::Color::Cyan);
    }
    else if(mCategoryWindows == Category_Window::Type::Activate)
    {
        mWindows.setOutlineColor(sf::Color::Green);
    }
    else if(mCategoryWindows == Category_Window::Type::None)
    {
        mWindows.setOutlineColor(sf::Color::Transparent);
    }

    return mWindows;
}
