#ifndef OBSERVER_H
#define OBSERVER_H

#include "IObserver.h"
#include "Subject.h"
#include <iostream>

class Observer : public IObserver {
    public:
        Observer(Subject &subject);
        virtual ~Observer();

        void Update(const std::string &message_from_subject) override;
        void RemoveMeFromTheList();
        void PrintInfo();

    private:
        // Subject* _subject;
        Subject &_subject; //무조건 subject 참조하는 관계 -> 변경 X
        std::string _message_from_subject;
        int _number;
        static int _static_number;
};

#endif