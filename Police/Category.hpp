#ifndef CATEGORY_HPP
#define CATEGORY_HPP

// Entity used to dispatch commands
namespace Category_Layers
{
    enum Layers
    {
        SceneGroundLayer,
        SceneBuildingLayer,
        SceneObjectLayer,
        SceneSbiresLayer,
        SceneNone,
    };
}

namespace Category_Build
{
    enum Type
    {
        None,
        Room,

    };
}

namespace Category_Window
{
    enum Type
    {
        Selected,
        Activate,
        None,
    };
}

namespace Category_Sbires
{
    enum ID
    {
        WorkerSbire,
        OfficeSbire,
        NoneSbire,
        CountSbire,

    };
}

namespace Category_Tasks
{
    enum ID
    {
        Working,
        Building,
        None,
    };
}

namespace Category_Direction
{
    enum ID
    {
        Up,
        Down,
        Left,
        Right,
        None,
    };
}

#endif // CATEGORY_HPP
