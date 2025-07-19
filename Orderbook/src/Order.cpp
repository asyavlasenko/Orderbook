#include <cstdint>
#include "../inc/Order.h"

Order::Order(int64_t id, int64_t user_id, int64_t amount, int64_t price, Side side)
    : id(id), user_id(user_id), amount(amount), price(price), side(side) {}

int64_t Order::getID() const { return id; }
int64_t Order::getUserID() const { return user_id; }
int64_t Order::getAmount() const { return amount; }
int64_t Order::getPrice() const { return price; }
Side Order::getSide() const { return side; }

void Order::reduceAmount(int64_t qty) {
    amount -= qty;
    if (amount < 0) amount = 0;
}

bool Order::isFilled() const {
    return amount == 0;
}
