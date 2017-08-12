#include "ProgressBar.hpp"
#include "Utility.h"

// For test
#include <iostream>

namespace GUI
{

ProgressBar::ProgressBar(const FontHolder& fonts, const TextureHolder& textures)
    :mTextureProgress()
    ,mIsFinish(false)
    ,mIsSelectable(false)
    ,mIsCurseurview(false)
    ,mValue(0.f)
    ,mText()
{
    // Set texture for progress Bar
    mTextureProgress.create(240,100);

    // Set the text who display the value
    mText.setFont(fonts.get(Fonts::Main));

    // Get Value for string
    std::string stringValue = toString(mValue);
    mText.setString(stringValue + '%');
    mText.setCharacterSize(20u);
    mText.setColor(sf::Color::White);
    centerOrigin(mText);
    mText.setPosition(120,65);

    // Set the sprites
    setSprite(textures);

    // Set Default value
    getSprite();

    // Set origin in the top left of rectangle shape
    this->setOrigin(20,50);
}

void ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    // Draw the sprite
    sf::Sprite sprite(mTextureProgress.getTexture());

    // Draw Now the Target
    target.draw(sprite, states);

}

void ProgressBar::handleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        std::cout << "ProgressBar Test check"<< std::endl;
    }
}

bool ProgressBar::checkColision(sf::Vector2i& position)
{
    // Check item
    ProgressBar::Type itemChecked = checkItem(position);
    std::cout << itemChecked << std::endl;

    // If the position was not in our progress rect
    if(itemChecked == BackStage || itemChecked == Progress || itemChecked == Windowing || itemChecked == CurseurTop || itemChecked == Curseur)
    {
        // If we are in the box
        std::cout << "in box" << std::endl;
        return true;
    }
    else
    {
        // If we not
        return false;
    }

}

ProgressBar::Type ProgressBar::checkItem(sf::Vector2i &position)
{
    // Type for save the type
    ProgressBar::Type saveType = TypeCount;

    // Check up the items
    for (int i = BackStage; i <= TypeCount; i++ )
    {

        // Get the type value
        ProgressBar::Type type = static_cast<Type>(i);

        // Save the variables we need
        sf::FloatRect boundsItem = mStackSprite[type].getGlobalBounds();
        sf::Vector2f positionSprite = this->getPosition();


        // Check if the position is in the box
        if(
        position.x < (positionSprite.x + boundsItem.width) &&
        position.x >  positionSprite.x &&
        position.y < (positionSprite.y + boundsItem.height) &&
        position.y >  positionSprite.y )
        {
            saveType = type;
            std::cout << type;
        }
    }
    std::cout << std::endl;

    return saveType;

}

void ProgressBar::setSelectable(bool select)
{
    mIsSelectable = select;

}

bool ProgressBar::isSelectable() const
{
    return mIsSelectable;
}

void ProgressBar::select()
{
    mIsCurseurview = true;
    setValue(mValue);
}

void ProgressBar::deselect()
{
    mIsCurseurview = false;
    setValue(mValue);
}

sf::FloatRect ProgressBar::getBoundingRect()
{
    return mStackSprite[BackStage].getGlobalBounds();
}

void ProgressBar::setSprite(const TextureHolder &textures)
{
    // For BackStage
    sf::IntRect rectBackStage (0,0,200,50);
    sf::Sprite  backStageSprite(textures.get(Textures::ProgressBar), rectBackStage);
    backStageSprite.setPosition(20,50);

    // For Progress,
    sf::IntRect rectProgress (0,50,5,50);
    sf::Sprite  progressSprite(textures.get(Textures::ProgressBar), rectProgress);
    progressSprite.setPosition(20,50);

    // For Window,
    sf::IntRect rectWindow (0,100,200,50);
    sf::Sprite  windowSprite(textures.get(Textures::ProgressBar), rectWindow);
    windowSprite.setPosition(backStageSprite.getPosition());

    // For Curseur Top
    sf::IntRect rectCurseurTop (80,150,40,50);
    sf::Sprite curseurTopSprite(textures.get(Textures::ProgressBar), rectCurseurTop);
    curseurTopSprite.setPosition(150,50);

    // For Curseur
    sf::IntRect rectCurseur (136,150,2,50);
    sf::Sprite curseurSprite (textures.get(Textures::ProgressBar), rectCurseur);
    curseurSprite.setPosition(0,0);

    // Stack all Sprite in a map
    mStackSprite[BackStage]  = backStageSprite;
    mStackSprite[Progress]   = progressSprite;
    mStackSprite[Windowing]  = windowSprite;
    mStackSprite[CurseurTop] = curseurTopSprite;
    mStackSprite[Curseur]    = curseurSprite;
}

void ProgressBar::getSprite()
{
    mTextureProgress.clear(sf::Color::Transparent);
    mTextureProgress.draw(mStackSprite[BackStage]);
    mTextureProgress.draw(mStackSprite[Progress]);
    mTextureProgress.draw(mStackSprite[Windowing]);

    // Get the curseur If is selectable & iscurseurview
    if(mIsSelectable && mIsCurseurview)
    {
        mTextureProgress.draw(mStackSprite[CurseurTop]);
        mTextureProgress.draw(mStackSprite[Curseur]);
    }

    mTextureProgress.draw(mText);
    mTextureProgress.display();
}

void ProgressBar::setValue(size_t value)
{
    // Set the value
    mValue = static_cast<float>(value);
    mText.setString(toString(mValue) + '%');

    // Set the value of pix
    float valuePix = 1.9;
    valuePix *= mValue;
    valuePix += 5;

    sf::IntRect rectSpriteProgess(0,50,static_cast<int>(valuePix) ,50);

    // Set the change of progress Sprite
    mStackSprite[Progress].setTextureRect(rectSpriteProgess);

    // If is selectable change position of curseur
    if(mIsSelectable && mIsCurseurview)
    {
        // Set sprite of curseur
        centerOrigin(mStackSprite[CurseurTop]);
        centerOrigin(mStackSprite[Curseur]);
        mStackSprite[CurseurTop].setPosition(static_cast<int>(valuePix)+20,25);
        mStackSprite[Curseur].setPosition(static_cast<int>(valuePix)+20,75);

        // Set mText in the curseur
        mText.setCharacterSize(15);
        mText.setPosition(mStackSprite[CurseurTop].getPosition().x,10);

    }
    else
    {
        // Set The Text Position
        mText.setPosition(120,65);
        mText.setCharacterSize(20u);
    }

    // And finally get the sprite
    getSprite();

}

}   // END of namespace GUI
