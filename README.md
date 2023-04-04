# oop patterns

Here stored some examples for patterns, that where given in the most brilliant book ever
(I'll add it here some day. Right?)

### Strategy pattern

Defines a **family of algorithms**, encapsulates each one, and makes them interchangeable.
Strategy lets the algorithm vary independently of clients that use it.

| Pros                                                                                                    |                         Cons                         |
|:--------------------------------------------------------------------------------------------------------|:----------------------------------------------------:|
| Algorithms are encapsulated in objects and can be exchanged during run time                             |   Clients must know and choose the right strategy    |
| Adding new strategies is easy. You only have to implement a new strategy.                               | The number of objects (strategies) increases heavily |
| The Strategy Pattern replaces conditional execution based on `if/else `statements or `switch`statements |                                                      |
| Callables are often lightweight implementations for strategies in C++                                   |                                                      |

In [our example](https://github.com/PrincesaPypka/oop-patterns/tree/main/strategy-pattern), 
`FlyBehavior class` and `QuackBehavior class` are **interfaces of algorithm families** which providing different quack and fly behaviors.

[Here is a more real world example]()

