#include "Subject.h"

/**
 * The subject(Publisher) owns some important state and notifies when the state changes.
 */

Subject::~Subject() {
    std::cout << "Goodbye. I was the Subject\n";
}

/**
 * The subscription management methods.
 */
void Subject::Attach(IObserver *observer) {
    _list_observer.push_back(observer);
}

void Subject::Detach(IObserver *observer) {
    _list_observer.remove(observer);
}

void Subject::Notify() {
    HowManyObserver();
    for(auto* observer: _list_observer) {
        observer -> Update(_message);
    }
}

void Subject::CreateMessage(std::string message) {
    this -> _message = message;
    Notify();
}

void Subject::HowManyObserver() {
    std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
}

/**
 * Usually, the subscription logic is only a fraction of what a Subject can really do.
 * Subjects commonly hold some important business logic, that triggers a notification method
 * whenever something important is about to happen (or after it)
 */

void Subject::SomeBusinessLogic() {
    this -> _message = "change message message";
    Notify();
    std::cout << "I'm about to do something important\n";
}
