#ifndef CATEGORY_HPP
#define CATEGORY_HPP

// Entity used to dispatch commands
namespace Category
{
    enum Layers
    {
        None                = 0,
        SceneGroundLayer    = 1 << 0,
        //SceneBuildingLayer  = 1 << 1,
        //SceneObjectLayer    = 1 << 2,
    };

}

namespace Textures
{
    enum Type
    {

    };
}

#endif // CATEGORY_HPP
