
#include <stdexcept>
#include <string> 
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

	friend istream& operator>> (istream& in, Order& order) {
		cout << "Enter Order arrival time: " << flush;
		cin >> order.startTime;
		if (order.startTime < 0 || order.startTime > 24 ) {
			throw invalid_argument("Order 'startTime' should be in range [0; 24]");
		}

		cout << "Enter Order duration: " << flush;
		cin >> order.duration;
		if (order.duration < 1 || order.duration > 24) {
			throw invalid_argument("Order 'duration' should be in range [1; 24]");
		}

		return in;
	}
};

class Restaurant {

private:
	int limit;
	queue<Order> ordersQueue;

	string convertTime(int time) {
		if (time <= 24) {
			return to_string(time);
		}

		int days = time / 24;
		int hours = time % 24;

		return to_string(days) + " days " + to_string(hours) + " hours";
	}

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

				printf("Order %d: expected completion time = %s, actual completion time = %s;\n", 
					orderId, 
					convertTime(curOrder.getExpectedEndTime()).c_str(), 
					convertTime(curTime).c_str());
			}

			++orderId;
		}

		printf("maxOrderDuration: %d\n", maxOrderDuration);

	}

};

int main(){

	/*
	int N = 6;
	int T = 20;

	Restaurant r(T);

	r.addOrder(Order(0, 5));
	r.addOrder(Order(1, 3));
	r.addOrder(Order(10, 3));
	r.addOrder(Order(11, 2));
	r.addOrder(Order(12, 4));
	r.addOrder(Order(18, 10));
	r.addOrder(Order(20, 4));

	r.execute();
	*/

	try {
		cout << "Specify number of orders (a.k.a 'N'): " << flush;
		int N;
		cin >> N;
		if (N < 0 || N > 100) {
			throw invalid_argument("'N' should be in range [0; 100]");
		}

		cout << "Specify UPPER time limit for restaurant(a.k.a T): " << flush;
		int T;
		cin >> T;
		if (T < 0 || T > 24) {
			throw invalid_argument("'T' should be in range [0; 24]");
		}

		Restaurant r(T);

		for (int i = 0; i < N; ++i) {
			// read Order from cin
			cout << "Order " << i << ":" << endl;
			Order cur(0, 0);
			cin >> cur;
			r.addOrder(cur);
		}

		r.execute();
	}
	catch (const exception& ex) {
		cerr << ex.what() << endl;
	}

	cout << "homework_1_queue completed" << endl;
	return 0;

}


