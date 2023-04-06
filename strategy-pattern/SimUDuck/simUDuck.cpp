#include "ducks/decoy.hpp"
#include "ducks/mallard.hpp"
#include "ducks/model.hpp"
#include "ducks/rubber.hpp"

int main() {
    DuckInterface *model = new DecoyDuck();
    model->Display();
    delete model;

    DecoyDuck duck1;

    DecoyDuck duck2 = duck1;
    duck2.PerformQuack();
    duck2.SetQuackBehavior(std::make_unique<Squeak>());
    duck2.PerformQuack();
    duck1 = duck2;
    duck1.PerformQuack();
    {
        DecoyDuck duck3;
        duck3.SetFlyBehavior(std::make_unique<FlyWithWings>());
        duck3.SetQuackBehavior(std::make_unique<Squeak>());
        duck1 = std::move(duck3);
    }
    duck1.Display();
    model = new RubberDuck();
    model->Display();
    delete model;

    model = new ModelDuck();
    model->Display();
    model->SetQuackBehavior(std::make_unique<Squeak>());
    model->PerformQuack();
    delete model;

    model = new MallardDuck();
    model->Display();
    delete model;

    return 0;
}
