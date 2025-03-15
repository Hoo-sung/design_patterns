#include <iostream>
#include <string>

/**
 * The base Component interface defines operations that can be altered
 * by decorators.
 */
class Component {
    public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent: public Component {
    public:
        std::string Operation() const override{
            return "ConcreteComponent";
        }
};

class Decorator: public Component {
    /**
     * @var Component
     */
    protected:
        Component* _component;

    public:
        Decorator(Component* component) : _component(component) {
        }
        /**
         * The Decorator delegates all work to the wrapped component.
         */
        std::string Operation() const override {
            return this->_component->Operation();
        }       
};

/**
 * Concrete Decorators call the wrapped object and alter its result in some way.
 */
class ConcreteDecoratorA: public Decorator {
    /**
     * Decorators may call parent implementation of the operation, instead of
     * calling the wrapped object directly. This approach simplifies extension of
     * decorator classes.
     */
    public:
        ConcreteDecoratorA(Component* component) : Decorator(component) {
        }
        
        std::string Operation() const override {
            return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
        }
};

/**
 * Decorators can execute their behavior either before or after the call to a
 * wrapped object.
 */
class ConcreteDecoratorB: public Decorator {
    public: 
        ConcreteDecoratorB(Component* component): Decorator(component) {
        
        }

        std::string Operation() const override {
            return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
        }
};

/**
 * The client code works with all objects using the Component interface. This
 * way it can stay independent of the concrete classes of commponents it works
 * with.
 */
void ClientCode(Component* component){
    std::cout << "RESULT: " << component-> Operation();
}

int main(){
    /**
     * This way the Client code can support both simple components...
     */
    Component* simple = new ConcreteComponent;
    std::cout<<"Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout<<"\n\n";
    /**
     * ...as well as decorated ones.simple
     * 
     * Note how decorators can wrap not only simple components but the other
     * decorators as well
     */
    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout<<"Client: Now I've got a decorated component:\n";
    ClientCode(decorator2);
    std::cout<< "\n\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}