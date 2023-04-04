# oop patterns

Here stored some examples for patterns, that where given in the most brilliant book ever
(I'll add it here some day. Right?)

### Strategy pattern

Defines a **family of algorithms**, encapsulates each one, and makes them interchangeable.
Strategy lets the algorithm vary independently of clients that use it.

In other words the Strategy pattern is a design pattern that allows you to encapsulate
a group of related algorithms and make them interchangeable. It helps to promote loose
coupling between objects and enables you to vary behavior at runtime by choosing among
different strategies.

In the Strategy pattern, you have three main components:

- context
- set of concrete strategies,
- interface or abstract class that defines the behavior of the strategies.

The context is the object responsible for invoking the algorithms,
while the strategies are the encapsulated algorithms that can be exchanged at runtime.
The interface or abstract class defines the common behavior of the strategies and allows
them to be interchanged.

|                                                  Pros                                                   |                         Cons                         |
|:-------------------------------------------------------------------------------------------------------:|:----------------------------------------------------:|
|               Algorithms are encapsulated in objects and can be exchanged during run time               |   Clients must know and choose the right strategy    |
|                Adding new strategies is easy. You only have to implement a new strategy.                | The number of objects (strategies) increases heavily |
| The Strategy Pattern replaces conditional execution based on `if/else `statements or `switch`statements |                                                      |
|                  Callables are often lightweight implementations for strategies in C++                  |                                                      |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/strategy-pattern),
`FlyBehavior class` and `QuackBehavior class` are **interfaces of algorithm families**
which providing different QuackStd and Fly behaviors.

[Here is a more real world example]()

