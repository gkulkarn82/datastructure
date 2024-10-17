#include "OrderCache.h"

void OrderCache::addOrder(const Order& order) {
    orderMap[order.orderId] = order;
    ordersBySecurity[order.securityId].push_back(std::make_unique<Order>(&orderMap[order.orderId]));
    companyOrders[order.companyId].insert(order.orderId);
}

void OrderCache::cancelOrder(const std::string& orderId) {
    auto it = orderMap.find(orderId);
    if (it != orderMap.end()) {
        const Order& order = it->second;
        // Remove order from security orders
        auto& orders = ordersBySecurity[order.securityId];
        for (auto orderIt = orders.begin(); orderIt != orders.end();) {
            if((*orderIt)->orderId == orderId)
            {
                orders.erase(orderIt);
            }
            else
                orderIt++;
        }

        //orders.erase(std::remove(orders.begin(), orders.end(), &order, orders.end());
        // Remove order from company orders
        companyOrders[order.companyId].erase(orderId);
        // Remove from the order map
        orderMap.erase(it);
    }
}

void OrderCache::cancelOrdersForUser(const std::string& userId) {
    for (auto it = orderMap.begin(); it != orderMap.end();) {
        if (it->second.userId == userId) {
            cancelOrder(it->first);
            it = orderMap.begin(); // Restart iteration as the map size is changing
        } else {
            ++it;
        }
    }
}

void OrderCache::cancelOrdersForSecIdWithMinimumQty(const std::string& securityId, int minimumQty) {
    auto it = ordersBySecurity.find(securityId);
    if (it != ordersBySecurity.end()) {
        auto& orders = it->second;
        for (auto orderIt = orders.begin(); orderIt != orders.end();) {
            if ((*orderIt)->quantity < minimumQty) {
                cancelOrder((*orderIt)->orderId);
                orderIt = orders.begin(); // Restart iteration as the vector size is changing
            } else {
                ++orderIt;
            }
        }
    }
}

int OrderCache::getMatchingSizeForSecurity(const std::string& securityId) {
    auto it = ordersBySecurity.find(securityId);
    if (it == ordersBySecurity.end()) return 0;

    const auto& orders = it->second;
    int totalMatched = 0;

    std::vector<std::unique_ptr<Order>> buyOrders;
    std::vector<std::unique_ptr<Order>> sellOrders;

    for (const auto& order : orders) {
        if (order->side == OrderSide::Buy) {
            buyOrders.push_back(order);
        } else {
            sellOrders.push_back(order);
        }
    }

    for (auto& buyOrder : buyOrders) {
        int remainingBuyQty = buyOrder->quantity;

        for (auto& sellOrder : sellOrders) {
            if (sellOrder->quantity > 0 && buyOrder->companyId != sellOrder->companyId) {
                int matchQty = std::min(remainingBuyQty, sellOrder->quantity);
                totalMatched += matchQty;
                remainingBuyQty -= matchQty;
                sellOrder->quantity -= matchQty;

                if (remainingBuyQty == 0) break;
            }
        }
    }

    return totalMatched; 
}

std::vector<Order> OrderCache::getAllOrders() {
    std::vector<Order> orders;
    for (const auto& entry : orderMap) {
        orders.push_back(entry.second);
    }
    return orders;
}
