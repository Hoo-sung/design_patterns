#include "Observer.h"

int Observer::_static_number = 0;

Observer::Observer(Subject &subject) : _subject(subject) {
    this -> _subject.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::_static_number<<"\".\n";
    this->_number = Observer::_static_number;
}

Observer::~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this-> _number <<"\".\n";
}

void Observer::Update(const std::string &message_from_subject) {
    _message_from_subject = message_from_subject;
    PrintInfo();
}

void Observer::RemoveMeFromTheList() {
    _subject.Detach(this);
    std::cout << "Observer \"" << _number << "\" removed from the list.\n";
}

void Observer::PrintInfo() {
    std::cout << "Observer \"" << this -> _number << "\": a new message is available --> " << this -> _message_from_subject << "\n";
}



