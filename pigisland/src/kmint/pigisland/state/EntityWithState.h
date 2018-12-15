#ifndef KMINT_ASESSMENT_ENTITYWITHSTATE_H
#define KMINT_ASESSMENT_ENTITYWITHSTATE_H

#include "StateMachine.h"

namespace kmint
{
    namespace pigisland
    {
        template<class T>
        class EntityWithState
        {
        public:
            EntityWithState(T &owner);
            StateMachine<T>& getStateMachine() const;
        protected:
            std::unique_ptr<StateMachine<T>> stateMachine;
        };

        template<class T>
        StateMachine<T>& EntityWithState<T>::getStateMachine() const
        {
            return *stateMachine;
        }

        template<class T>
        EntityWithState<T>::EntityWithState(T &owner): stateMachine(std::make_unique<StateMachine<T>>(owner))
        {}
    }
}


#endif //KMINT_ASESSMENT_ENTITYWITHSTATE_H
