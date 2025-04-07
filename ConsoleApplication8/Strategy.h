#include <iostream>
using namespace std;

class DeliveryStrategy {
public:
    virtual double calculateCost() = 0;
    virtual ~DeliveryStrategy() {}
};

class FlatRateDelivery : public DeliveryStrategy {
public:
    double calculateCost() override {
        return 50.0; // Фиксированная цена
    }
};

class WeightBasedDelivery : public DeliveryStrategy {
    double weight;
public:
    WeightBasedDelivery(double w) : weight(w) {}
    double calculateCost() override {
        return weight * 10; // 10 руб/кг
    }
};

class DistanceBasedDelivery : public DeliveryStrategy {
    double distance;
public:
    DistanceBasedDelivery(double d) : distance(d) {}
    double calculateCost() override {
        return distance * 2; // 2 руб/км
    }
};

class Order {
    DeliveryStrategy* strategy;
public:
    void setStrategy(DeliveryStrategy* s) {
        strategy = s;
    }
    double calculateDelivery() {
        return strategy->calculateCost();
    }
};
