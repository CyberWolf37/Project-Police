#include "ProgressBar.hpp"
#include "Utility.h"

namespace GUI
{

ProgressBar::ProgressBar(const FontHolder& fonts, const TextureHolder& textures)
    :mTextureProgress()
    ,mIsFinish(false)
    ,mIsSelectable(false)
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
    mText.setPosition(100,65);

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

}

bool ProgressBar::checkColision(sf::Vector2i& position)
{
    return false;

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

}

void ProgressBar::deselect()
{

}

sf::FloatRect ProgressBar::getBoundingRect()
{

}

bool ProgressBar::setSprite(const TextureHolder &textures)
{
    // For BackStage
    sf::IntRect rectBackStage (0,0,200,50);
    sf::Sprite  backStageSprite(textures.get(Textures::ProgressBar), rectBackStage);
    centerOrigin(backStageSprite);
    backStageSprite.setPosition(120,75);

    // For Progress,
    sf::IntRect rectProgress (0,50,5,50);
    sf::Sprite  progressSprite(textures.get(Textures::ProgressBar), rectProgress);
    progressSprite.setPosition(20,50);

    // For Window,
    sf::IntRect rectWindow (0,100,200,50);
    sf::Sprite  windowSprite(textures.get(Textures::ProgressBar), rectWindow);
    centerOrigin(windowSprite);
    windowSprite.setPosition(backStageSprite.getPosition());

    // For Curseur
    sf::IntRect rectCurseur (80,150,40,50);
    sf::Sprite curseurSprite(textures.get(Textures::ProgressBar), rectCurseur);
    centerOrigin(curseurSprite);

    // Stack all Sprite in a map
    mStackSprite[BackStage]  = backStageSprite;
    mStackSprite[Progress]   = progressSprite;
    mStackSprite[Windowing]  = windowSprite;
    mStackSprite[Curseur]    = curseurSprite;

    return true;
}

void ProgressBar::getSprite()
{
    mTextureProgress.clear(sf::Color::Transparent);
    mTextureProgress.draw(mStackSprite[BackStage]);
    mTextureProgress.draw(mStackSprite[Progress]);
    mTextureProgress.draw(mStackSprite[Windowing]);

    // Get the curseur If is selectable
    if(mIsSelectable)
    {
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
    if(mIsSelectable)
    {
        // Set sprite of curseur
        centerOrigin(mStackSprite[Curseur]);
        mStackSprite[Curseur].setPosition(static_cast<int>(valuePix)+20,25);

        // Set mText in the curseur
        mText.setCharacterSize(15);
        mText.setPosition(mStackSprite[Curseur].getPosition().x,10);

    }

    // And finally get the sprite
    getSprite();

}

}   // END of namespace GUI
