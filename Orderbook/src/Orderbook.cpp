#include "../inc/Orderbook.h"

void Orderbook::addOrder(const Order& incomingOrder) {
    Order order = incomingOrder;

    if (order.getSide() == Side::BUY) {
        buyOrders[order.getPrice()].push_back(order);
    } else {
        sellOrders[order.getPrice()].push_back(order);
    }

    match();
}

void Orderbook::match() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto buyIt = buyOrders.begin();
        auto sellIt = sellOrders.begin();

        if (buyIt->first < sellIt->first)
            break;

        Order& buyOrder = buyIt->second.front();
        Order& sellOrder = sellIt->second.front();

        int64_t tradeAmount = std::min(buyOrder.getAmount(), sellOrder.getAmount());
        int64_t price = sellIt->first;

        printBalanceChange(buyOrder.getUserID(), -tradeAmount * price, "USD");
        printBalanceChange(buyOrder.getUserID(), tradeAmount, "UAH");

        printBalanceChange(sellOrder.getUserID(), -tradeAmount, "UAH");
        printBalanceChange(sellOrder.getUserID(), tradeAmount * price, "USD");

        buyOrder.reduceAmount(tradeAmount);
        sellOrder.reduceAmount(tradeAmount);

        if (buyOrder.isFilled()) buyIt->second.pop_front();
        if (sellOrder.isFilled()) sellIt->second.pop_front();

        if (buyIt->second.empty()) buyOrders.erase(buyIt);
        if (sellIt->second.empty()) sellOrders.erase(sellIt);
    }
}

void Orderbook::printBalanceChange(int64_t user_id, int64_t value, const std::string& currency) const {
    std::cout << "User " << user_id << " | "
              << (value >= 0 ? "+" : "") << value << " " << currency << "\n";
}

void Orderbook::printState() const {
    std::cout << "=== ORDERBOOK STATE ===\n";
    std::cout << "-- Buy Orders --\n";
    for (const auto& [price, orders] : buyOrders) {
        for (const auto& order : orders) {
            std::cout << "Buy " << order.getAmount() << " @ " << price << "\n";
        }
    }
    std::cout << "-- Sell Orders --\n";
    for (const auto& [price, orders] : sellOrders) {
        for (const auto& order : orders) {
            std::cout << "Sell " << order.getAmount() << " @ " << price << "\n";
        }
    }
    std::cout << "========================\n";
}
