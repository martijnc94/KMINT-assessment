#ifndef PROJECT_STATE_H
#define PROJECT_STATE_H

namespace kmint
{
    namespace pigisland
    {
        struct Telegram {
            int Sender;
            int Receiver;
            int Msg;
            void* ExtraInfo;
        };

        template<class T>
        class State
        {
        public:
            virtual ~State() = default;
            virtual bool execute(T &entity) = 0;
            virtual void enter(T &entity) = 0;
            virtual void exit(T &entity) = 0;
        };

    }
}

#endif //PROJECT_STATE_H
