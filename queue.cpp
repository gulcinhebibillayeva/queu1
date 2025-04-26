#include <iostream>
using namespace std;

template<typename T, int MAX = 10>
class Deque
{
	T arr[MAX]{};
	int frontvar = -1;
	int rearvar = -1;
public:
	Deque() = default;
	void push_front(T item) {
		if (isFull()) {
			cout << "deque is full\n";
			return;
			
		}
		if (isEmpty()) {
			frontvar = rearvar = 0;
		}
		else if (frontvar== 0) {
			frontvar = MAX - 1;
		}
		else {
			--frontvar;
		}
		arr[frontvar] = item;
	}
	void push_rear(T item) {
		if (isFull())
		{
			cout << "deque is full\n";
			return;
		}
		if (isEmpty()) {
			frontvar = rearvar = 0;
		}
		else if (rearvar == MAX - 1) {
			rearvar = 0;
		}
		else {
			++rearvar;
		}
		arr[rearvar] = item;
		
	}
	void pop_front() {
		if (isEmpty()) {
			cout << "Dequeu is empty\n";
			return;
			
		}
		if (frontvar == rearvar) {
			frontvar = rearvar = -1;
		}
		else if (frontvar == MAX - 1) {
			frontvar = 0;
		}
		else {
			++frontvar;
		}
	
	}
	void pop_rear() {
		if (isEmpty()) {
			cout << "deque is empty\n";
			return;
		
		}
		if (frontvar == rearvar) {
			frontvar = rearvar = -1;
		}
		else if (rearvar == 0) {
			rearvar = MAX - 1;
		}
		else {
			--rearvar;
		}
		
	}
	bool isFull() {
		return  (frontvar == 0 && rearvar == MAX - 1) || (frontvar == rearvar + 1); 
	}
	bool isEmpty() {
		return frontvar == -1;
	}
	T front() {
		if (isEmpty()) {
			cout << "deque is empty\n";
			return T();
		}
		return arr[frontvar];
	}
	T rear() {
		if (isEmpty()) {
			cout << "deque is empty\n";
			return T();
		}
		return arr[rearvar];
	}

};

int main() {
	Deque<int,5>dq;
	dq.push_rear(10);
	dq.push_rear(20);
	dq.push_front(5);
	dq.push_front(2);
	cout << "Front element: " << dq.front() << endl; 
	cout << "Rear element: " << dq.rear() << endl;   
	dq.pop_front();
	dq.pop_rear();
	dq.pop_front();
	dq.pop_front();
	dq.pop_front();
	
	if (!dq.isEmpty())
		cout << "Rear element after empty: " << dq.rear() << endl;
	else
		cout << "Deque is empty.\n";
	return 0;


}
//Qeydlər
//1) Method - ları tamamlamaq.
//2) Big O Notation - dan kənara çıxmamaq.
//3) Const method, Reference, Overloading,
//Exception lazım olan yerlərdə istifadə
//etmək.
//4) Yuxarda yazılan kodlar nümunə üçündür,
//bəzi çatışmamazliqlari var, onları
//tamamlamaq.
//5) Diger keçdiyimiz mövzulardan yerinə görə
//istifadə etmək.
//UGURLAR 😊
