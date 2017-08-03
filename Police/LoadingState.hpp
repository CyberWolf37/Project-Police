#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include "State.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

#include "ProgressBar.hpp"
#include "ParallelTask.hpp"


class LoadingState : public State
{
public:
    LoadingState(StateStack& stack, Context context);

    virtual void                            draw();
    virtual bool                            update(sf::Time dt);
    virtual bool                            handleEvent(const sf::Event &event);

    void                                    setCompletion(float percent);

private:
    GUI::ProgressBar                        mProgressBar;

    ParallelTask                            mLoadingTask;

};

#endif // LOADINGSTATE_H
