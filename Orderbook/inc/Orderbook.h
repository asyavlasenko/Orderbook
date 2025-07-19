#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <map>
#include <list>
#include <iostream>

class Orderbook {
public:
    void addOrder(const Order& order);
    void printState() const;

private:
    std::map<int64_t, std::list<Order>> sellOrders;
    std::map<int64_t, std::list<Order>, std::greater<>> buyOrders;
    int64_t nextOrderID = 1;

    void match();
    void printBalanceChange(int64_t user_id, int64_t value, const std::string& currency) const;
};

#endif
