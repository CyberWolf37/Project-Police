#ifndef CATEGORY_HPP
#define CATEGORY_HPP

// Entity used to dispatch commands
namespace Category
{
    enum Layers
    {
        None                = 0,
        SceneGroundLayer    = 1 << 0,
        SceneBuildingLayer  = 1 << 1,
        //SceneObjectLayer    = 1 << 2,
    };

}

namespace Category_Build
{
    enum Type
    {
        None        = 0,
        Room        = 1,

    };
}

namespace TuileState
{
    enum ID
    {
        None,
        GroundTuile,
        ObjectTuile,
    };
}

namespace Category_Sbires
{
    enum ID
    {
        WorkerSbire,
        OfficeSbire,
        NoneSbire,

    };
}

#endif // CATEGORY_HPP
