#include<iostream>
#include <queue>

using namespace std;


class  PrintRequest {
protected:
	string user;
	string text;
	string time;
public:
	PrintRequest(string user, string text, string time) : user(user), text(text), time(time) {

	}

	PrintRequest() {};

	string getUser() const {
		return user;
	}

	string getText() const {
		return text;
	}

	string getTime() const {
		return time;
	}
};

class Queue {

private:
	PrintRequest  client;
	queue<PrintRequest> queue;
public:
	Queue(string user, string text, string time) : client(PrintRequest(user, text, time)) {};

	Queue() {};

	void printStatistics(PrintRequest& request) {
		cout << "Printing for: " << request.getUser() << endl;
		cout << "Text: " << request.getText() << endl;
		cout << "Time: " << request.getTime() << endl;
		cout << endl;
	}


	void enqueue(const PrintRequest& request) {
		queue.push(request);
	}

	bool isEmpty() const {
		return queue.empty();
	}

	void dequeue() {
		if (!queue.empty()) {
			PrintRequest request = queue.front();
			queue.pop();
			printStatistics(request);
		}
	}

};

int main() {
	Queue printQueue;

	printQueue.enqueue(PrintRequest("Atilla", "Lalalalallalalalallala", "12:12"));
	printQueue.enqueue(PrintRequest("Ne", "LLALLALALALLALA", "10:11"));
	printQueue.enqueue(PrintRequest("For", "ALALlLAlalALlLAllALlaLALLAlA", "14:02"));

	while (!printQueue.isEmpty()) {
		printQueue.dequeue();
	}
	return 0;
}
