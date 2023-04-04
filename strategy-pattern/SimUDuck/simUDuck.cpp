#include "ducks/decoy.hpp"
#include "ducks/mallard.hpp"
#include "ducks/model.hpp"
#include "ducks/rubber.hpp"

int main() {
    DuckInterface *model = new DecoyDuck();
    model->display();
    delete model;

    model = new RubberDuck();
    model->display();
    delete model;

    model = new ModelDuck();
    model->display();
    model->setQuackBehavior(std::make_unique<Squeak>());
    model->performQuack();
    delete model;

    model = new MallardDuck();
    model->display();
    delete model;

    return 0;
}
