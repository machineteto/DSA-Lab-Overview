#include <iostream>

using namespace std;

struct	Node {

	int	data;
	Node* next;
public:
	int	demNut(Node* head) {
		if (head == nullptr)
			return 0;
		return 1 + demNut(head->next);
	}

	void inNguoc(Node* head) {
		if (head == nullptr)
			return;

		inNguoc(head->next);

		cout << head->data << " " << endl;
	}

	void giaiPhong(Node* head) {
		if (head == nullptr)
			return;

		giaiPhong(head->next);

		cout << "giai phong: " << head->data << endl;
		delete head;
	}
};

int main() {
	Node* n1 = new Node{ 70, new Node{90, new Node{30, nullptr} } };

	cout << "so nut: " << n1->demNut(n1) << endl;

	cout << "reverse: " << endl;
	n1->inNguoc(n1);

	n1->giaiPhong(n1);
	n1 = nullptr;
}