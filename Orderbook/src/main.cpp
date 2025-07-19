#include <random>
#include "../inc/Orderbook.h"
#include "../inc/Order.h"

int main() {
    Orderbook ob;
    std::default_random_engine rng;
    std::uniform_int_distribution<int64_t> price(30, 50);
    std::uniform_int_distribution<int64_t> amount(10, 100);
    std::uniform_int_distribution<int64_t> user(1, 5);
    std::uniform_int_distribution<int64_t> side(0, 1);

    for (int i = 0; i < 10; ++i) {
        ob.addOrder(Order(
            i + 1,
            user(rng),
            amount(rng),
            price(rng),
            side(rng) == 0 ? Side::BUY : Side::SELL
        ));
    }

    ob.printState();
    return 0;
}
