#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

class IObserver {
    public:
        virtual ~IObserver(){};
        virtual void Update(const std::string &message_from_subject) = 0;
};

#endif