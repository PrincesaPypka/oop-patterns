# oop patterns

Here stored some examples for patterns, that where given in [the most brilliant
book ever!](https://wickedlysmart.com/books/) We need 'Head First Design
Patterns'.

### Strategy pattern

Defines a **family of algorithms**, encapsulates each one, and makes them
interchangeable. Strategy lets the algorithm vary independently of clients
that use it.

In other words the Strategy pattern is a design pattern that allows you to
encapsulate a group of related algorithms and make them interchangeable. It
helps to promote loose coupling between objects and enables you to vary
behavior at runtime by choosing among different strategies.

In the Strategy pattern, you have three main components:

- **context**
- set of **concrete strategies**
- interface or abstract class that defines the behavior of the strategies.

The context is the object responsible for invoking the algorithms,
while the strategies are the encapsulated algorithms that can be exchanged at
runtime. The interface or abstract class defines the common behavior of the
strategies and allows them to be interchanged.

| Pros                                                                      | Cons                                                 |
|:--------------------------------------------------------------------------|:-----------------------------------------------------|
| Encapsulated in objects and can be exchanged during run time              | Clients must know and choose the right strategy      |
| Adding new strategies is easy. You only have to implement a new strategy. | The number of objects (strategies) increases heavily |
| Replaces conditional execution based on `if/else` or `switch`statements   |                                                      |
| Callables are often lightweight implementations for strategies            |                                                      |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/strategy-pattern/SimUDuck),
`FlyBehavior class` and `QuackBehavior class` are **interfaces of algorithm
families** which providing different Quack and Fly behaviors.

[Here is a more real world example](https://github.com/some404day)

### Observe pattern

Defines a one-to-many dependency between objects so that when one object
changes state, all of its dependencies are notified and updated automatically.

In other words, The Observer pattern is a software design pattern in which an
object, called the subject, maintains a list of its dependents, called
observers, and notifies them automatically of any changes to its state.
This is useful when you have objects that need to be updated in response to
changes in another object, but you don't want to tightly couple the two
objects together.

The main components of the Observer pattern are:

- **Subject:** This is the object that maintains a list of its observers and
  notifies them of any changes to its state. It provides methods to attach,
  detach and notify observers.
- **Observer:** This is the interface that defines the update method that the
  subject calls when its state changes. Any object that implements this
  interface can be an observer of the subject.
- **Concrete Subject:** This is a concrete implementation of the subject
  interface.
  It maintains the state that the observers are interested in and notifies them
  of any changes to it.
- **Concrete Observer:** This is a concrete implementation of the observer
  interface. It registers with a concrete subject and implements the update
  method to receive notifications from the subject.

| Pros                                                                                                                           | Cons                                                                                                                                  |
|:-------------------------------------------------------------------------------------------------------------------------------|:--------------------------------------------------------------------------------------------------------------------------------------|
| Promotes loose coupling between objects by allowing the subject to know only that its observers implement a certain interface. | Can add complexity to the code by requiring the maintenance of a list of observers and ensuring that they are notified appropriately. |
| Makes it easy to add or remove observers dynamically at runtime, providing more flexibility in system design.                  | Can add overhead to the system by requiring the subject to notify its observers every time its state changes.                         |
| Separates the concerns of the subject and its observers, making the code more modular and easier to maintain.                  | Can lead to memory leaks if observers are not properly removed when they are no longer needed.                                        |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/observer-pattern/WeatherStation),
`CurrentConditionDisplay class` is a **concrete observer**, `DisplayInterface
class` is a **observer** and `WeatherData class` is a **concrete subject**
and a **subject** in the same time. It may be not the very best idea, but oh
well...

[Here is a more real world example](https://github.com/some404day)

### Decorator pattern

Attaches additional responsibilities to an object dynamically. Decorators
provide a flexible alternative to subclassing for extending functionality.

In other words, it allows behavior to be added to an individual object,
either statically or dynamically, without affecting the behavior of other
objects from the same class.

The main components of the decorator pattern are:

- **Component interface:** This is the interface or abstract class that
  defines the methods that the concrete components and decorators must
  implement. It provides the basic functionality that the decorator can
  enhance or modify.
- **Concrete component:** This is the class that implements the component
  interface. It represents the basic functionality that the decorator can
  enhance or modify.
- **Decorator:** This is the abstract class that implements the component
  interface and also contains a reference to the component object that it
  decorates. It provides an interface that is identical to the component's
  interface, so that it can be used in the same way as the component.
- **Concrete decorator:** This is the class that extends the decorator and
  provides additional functionality or behavior to the component. It may
  also override some methods of the component to modify its behavior or add
  new functionality.

| Pros                                                                                                                                             | Cons                                                                                                                |
|:-------------------------------------------------------------------------------------------------------------------------------------------------|:--------------------------------------------------------------------------------------------------------------------|
| Allows adding functionality to an object without changing its class, which can promote code reusability.                                         | Can result in a large number of small classes if used excessively, making the code harder to understand.            |
| Allows adding and removing responsibilities at runtime, providing more flexibility in the system design.	                                        | Can be complex to implement, especially with multiple decorators, increasing the potential for errors.              |
| Allows composition of behaviors instead of inheritance, which can reduce the complexity of the code.                                             | Can introduce overhead by creating multiple objects to achieve the desired behavior, which can affect performance.  |
| Provides a flexible and modular approach to modifying an object's behavior, making the code easier to maintain.                                  | Can lead to confusion and difficulty in understanding the code when used excessively, reducing its readability.     |
| Follows the Open-Closed Principle, which states that classes should be open for extension but closed for modification, promoting code stability. | Can be overused, leading to unnecessary complexity and decreased maintainability, making the code harder to modify. |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/decorator-pattern/StarbuzzCofe),
`BeverageInterface class` is a **component interface**,
`Espresso class` and others are **concrete components**, `CondimentDecorator
class` is a **decorator** and `Whip class` and other are **concrete decorators**

[Here is a more real world example](https://github.com/some404day)

### Factory pattern

#### Small factory pattern (not really a pattern, but oh well...)

Provides a way to create objects without exposing the underlying
instantiation logic. In simple terms, the simple factory pattern is a way of
creating objects in which a factory method is responsible for creating
objects of a specific class. This method takes in some input, which it uses
to determine which class to instantiate, and returns an object of that class.

The main components of the small factory pattern are:

- **Factory:** This is the class responsible for creating the objects.
  It has a factory method that takes in some input, which it uses to
  determine which object to create. The factory method then returns an
  object of the appropriate type.
- **Product:** This is the object being created by the factory. It can
  be an abstract class or an interface that defines the common properties
  and behaviors of the objects that the factory creates.
- **Concrete Products:** These are the concrete implementations of the
  product interface. They define the specific properties and behaviors of
  the objects that the factory creates.

| Pros                                                                                                                                                   | Cons                                                                                                                                                   |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------|
| Encapsulates the object creation process in a single location, making it easier to maintain and modify the code when new products are added.           | Violates the Open-Closed Principle since adding new concrete products to the factory requires modifying the factory code.                              |
| Provides a simple interface for creating objects, which makes it easy to use and understand by clients.                                                | Limited in extensibility because the factory method is responsible for creating all objects of a particular type.                                      |
| Reduces the coupling between classes by allowing clients to request objects without knowing the details of how they are created, promoting modularity. | As the number of concrete products increases, the factory class can become large and complex, making it difficult to maintain and understand the code. |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/factory-pattern/SimpleFactory),
`PizzaInterface class` is a **product**,`VeggiePizza class` and others are
**concrete products**, `SimplePizzaFactory class` is a **factory**

[Here is a more real world example](https://github.com/some404day)

