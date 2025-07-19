# 💱 UAH/USD Orderbook CLI App

## About the Project

This is a simple command-line application written in **C++**, designed to simulate a basic **digital order book** for trading between two currencies: **UAH (Ukrainian Hryvnia)** and **USD (US Dollar)**.

The program automatically generates random buy/sell orders for different users and processes them through a matching algorithm. The result is a set of balance changes printed to the console.

---

## Description

Welcome to **UAH/USD Orderbook CLI App**!  
This exchange simulation randomly creates a set of 10 orders to buy or sell **UAH** at various prices in **USD**. The system matches orders automatically when prices align and prints the trades and updated balances.

---

## Behavior (Random Test Run)

- 🔁 Automatically generates:
  - 10 random orders
  - User IDs between 1–5
  - Prices between 30–50 USD per 1 UAH
  - Amounts between 10–100 UAH
  - Sides: `BUY` or `SELL`

- 📤 Output:  
  - Matched trades and balance changes in the terminal

---

## How to Run

```bash
g++ -Iinclude src/main.cpp src/Order.cpp src/Orderbook.cpp -o orderbook
./orderbook
```

### Time Complexity (Big O):

- Inserting an order: `O(log N)`  
- Matching check: `O(1)` (only compares front prices)  
- Matching and removing: `O(1)` amortized per order

This approach ensures that the orderbook operates efficiently even with a large number of incoming orders.

---

📦 Ideal for testing matching algorithms and simulating currency trades!
