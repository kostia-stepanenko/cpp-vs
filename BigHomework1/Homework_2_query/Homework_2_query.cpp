
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

class Order {
private:
	int startTime;
	int duration;

public:
	Order(int startTime, int duration) {
		this->startTime = startTime;
		this->duration = duration;
	}

	int getStartTime() {
		return this->startTime;
	}

	int getDuration() {
		return this->duration;
	}

	int getExpectedEndTime() {
		return this->startTime + duration;
	}
};

class Restaurant {

private:
	int limit;
	queue<Order> ordersQueue;

public:
	Restaurant(int upperLimit) : limit(upperLimit) {}

	void addOrder(Order order) {
		ordersQueue.push(order);
	}

	void execute() {

		int curTime = 0;

		int maxOrderDuration = 0;

		int orderId = 1;

		while (! ordersQueue.empty()) {
			Order curOrder = ordersQueue.front();
			ordersQueue.pop();

			int startTime = curOrder.getStartTime();

			// check if Chef has a break
			if (curTime != limit && curTime < startTime) {
				printf("The chef takes a break (the queue is empty) between the times %d and %d\n", 
					curTime, min(startTime, limit));

				curTime = startTime;
			}

			if (curTime >= limit) {
				// skipping orders, not workign hours
				printf("Order % d: will be skipped\n", orderId);
			}
			else {
				// processing order
				curTime += curOrder.getDuration();

				maxOrderDuration = max(maxOrderDuration, curOrder.getDuration());

				printf("Order %d: expected completion time = %d, actual completion time = %d;\n", 
					orderId, curOrder.getExpectedEndTime(), curTime);
			}

			++orderId;
		}

		printf("maxOrderDuration: %d\n", maxOrderDuration);

	}

};

int main(){
	int N = 6;
	int T = 20;

	Restaurant r(T);

	r.addOrder(Order(0, 5));
	r.addOrder(Order(1, 3));
	r.addOrder(Order(10, 3));
	r.addOrder(Order(11, 2));
	r.addOrder(Order(12, 4));
	r.addOrder(Order(18, 5));
	r.addOrder(Order(20, 4));

	r.execute();

	cout << "homework_1_queue completed" << endl;
	return 0;

}


