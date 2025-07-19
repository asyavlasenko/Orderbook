#ifndef ORDER_H
#define ORDER_H

#include <cstdint>
#include <string>

enum class Side { BUY, SELL };

class Order {
public:
    Order(int64_t id, int64_t user_id, int64_t amount, int64_t price, Side side);

    int64_t getID() const;
    int64_t getUserID() const;
    int64_t getAmount() const;
    int64_t getPrice() const;
    Side getSide() const;

    void reduceAmount(int64_t qty);
    bool isFilled() const;

private:
    int64_t id;
    int64_t user_id;
    int64_t amount;
    int64_t price;
    Side side;
};

#endif
