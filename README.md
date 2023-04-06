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

- context
- set of concrete strategies,
- interface or abstract class that defines the behavior of the strategies.

The context is the object responsible for invoking the algorithms,
while the strategies are the encapsulated algorithms that can be exchanged at
runtime. The interface or abstract class defines the common behavior of the
strategies and allows them to be interchanged.

| Pros                                                                                                    | Cons                                                 |
|:--------------------------------------------------------------------------------------------------------|:-----------------------------------------------------|
| Algorithms are encapsulated in objects and can be exchanged during run time                             | Clients must know and choose the right strategy      |
| Adding new strategies is easy. You only have to implement a new strategy.                               | The number of objects (strategies) increases heavily |
| The Strategy Pattern replaces conditional execution based on `if/else` statements or `switch`statements |                                                      |
| Callables are often lightweight implementations for strategies in C++                                   |                                                      |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/strategy-pattern/SimUDuck),
`FlyBehavior class` and `QuackBehavior class` are **interfaces of algorithm
families** which providing different Quack and Fly behaviors.

[Here is a more real world example](https://github.com/some404day)

### observe pattern

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

| Pros                                                                                                                                                                                                  | Cons                                                                                                                                                                             |
|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Loose coupling:** The Observer pattern promotes loose coupling between objects, since the subject doesn't need to know anything about its observers except that they implement a certain interface. | **Complexity:** Implementing the Observer pattern can add complexity to your code,since you need to maintain the list of observers and make sure they get notifiedappropriately. |
| **Flexibility:** The Observer pattern makes it easy to add or remove observers dynamically at runtime, which gives you more flexibility in how you design your system.                                | **Overhead:** The Observer pattern can add some overhead to your system, since the subject needs to notify its observers every time its state changes.                           |
| **Separation of concerns:** By separating the concerns of the subject and its observers, you can make your code more modular and easier to maintain.                                                  | **Memory leaks:** If you're not careful, the Observer pattern can lead to memory leaks if observers aren't properly removed when they're no longer needed.                       |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/observer-pattern/WeatherStation),
`CurrentConditionDisplay class` is a **concrete observer**, `DisplayInterface
class` is a **observer** and `WeatherData class` is a **concrete subject**
and a **subject** in the same time. It may be not the very best idea, but oh
well...

[Here is a more real world example](https://github.com/some404day)