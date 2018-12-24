#ifndef PROJECT_STATEMACHINE_H
#define PROJECT_STATEMACHINE_H


#include <memory>
#include "State.h"

namespace kmint
{
    namespace pigisland
    {
        template<class T>
        class StateMachine
        {
        public:
            explicit StateMachine(T &owner);
            ~StateMachine() = default;
            void update() const;

            void changeState(std::unique_ptr<State<T>> newState);
            void revertToPreviousState();
            void setCurrentState(std::unique_ptr<State<T>> s);
            void setGlobalState(std::unique_ptr<State<T>> s);

            State<T> &getCurrentState() const
            { return currentState; }

            State<T> &getGlobalState() const
            { return globalState; }

            State<T> &getPreviousState() const
            { return previousState; }

        private:
            T &owner;
            std::unique_ptr<State<T>> currentState;
            std::unique_ptr<State<T>> previousState;
            std::unique_ptr<State<T>> globalState;
        };

        template<class T>
        void StateMachine<T>::changeState(std::unique_ptr<State<T>> newState)
        {
            if (currentState) {
                currentState->exit(owner);
                previousState = std::move(currentState);
            }
            currentState = std::move(newState);
            currentState->enter(owner);
        }

        template<class T>
        void StateMachine<T>::revertToPreviousState()
        {
            changeState(previousState);
        }

        template<class T>
        void StateMachine<T>::update() const
        {
            if (globalState) {
                globalState->execute(owner);
            }

            if (currentState) {
                currentState->execute(owner);
            }
        }

        template<class T>
        void StateMachine<T>::setCurrentState(std::unique_ptr<State<T>> s)
        {
            currentState = std::move(s);
        }

        template<class T>
        void StateMachine<T>::setGlobalState(std::unique_ptr<State<T>> s)
        {
            globalState = std::move(s);
            globalState->enter(owner);
        }

        template<class T>
        StateMachine<T>::StateMachine(T &owner): owner(owner)
        {}
    }
}


#endif //PROJECT_STATEMACHINE_H
