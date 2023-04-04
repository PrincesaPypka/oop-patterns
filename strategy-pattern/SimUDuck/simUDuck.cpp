#include "ducks/decoy.hpp"
#include "ducks/mallard.hpp"
#include "ducks/model.hpp"
#include "ducks/rubber.hpp"

int main() {
    DuckInterface *model = new DecoyDuck();
    model->Display();
    delete model;

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
