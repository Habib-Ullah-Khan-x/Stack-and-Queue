#include <iostream>
#include <cstring>
using namespace std;
class Stack_array {
		int* A;
		int top;
		int capacity;

	public:
		Stack_array(int size) {
			A = new int[size];
			top = -1;
			capacity = size;
		}
		~Stack_array() {
			delete[] A;
		}
		void push(int x) {
			if (isFull()) {
				cout << " Stack overflow\n";
				return;
			}
			top++;
			A[top] = x;
		}

		int pop() {
			if (isEmpty()) {
				cout << " Stack underflow\n";
				return -1;
			}
			int x = A[top];
			top--;
			return x;
		}

		bool isFull() {
			return top == capacity - 1;
		}

		bool isEmpty() {
			return top == -1;
		}

		int peek() {
			if (isEmpty()) {
				cout << " tStack is empty\n";
				return -1;
			}
			return A[top];
		}

		int size() {
			return top + 1;
		}
		bool isBalanced(char *exp) {
			Stack_array s(strlen(exp) + 1);
			int i=0;
			while(exp[i]!='\0') {
				if (exp[i] == '(' || exp[i] == '[' || exp[i] ==
				        '{')  {
					s.push(exp[i]);
				} else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
					if (s.isEmpty())   {
						return false;
					}
					char temp = s.pop();
					if ((exp[i] == ')' && temp != '(') ||
					        (exp[i] == ']' && temp != '[') ||
					        (exp[i] == '}' && temp != '{'))   {
						return false;
					}
				}

				i++;
			}
			return s.isEmpty();
		}
		//
		int pre(char x) {
			if (x == '+' || x == '-')
				return 1;
			else if (x == '*' || x == '/') return 2;
			return 0;
		}

		bool isOperand(char x) {
			if (x == '+' || x == '-' || x == '*' || x == '/') return false;
			else
				return true;
		}
		char *InToPost(char *infix) {
			Stack_array obj(strlen(infix));
			int i = 0, j = 0;
			int len = strlen(infix);
			char *postfix = new char[len + 1];
			while (infix[i] != '\0') {
				if (isOperand(infix[i])) postfix[j++] = infix[i++];
				else {

					if (pre(infix[i]) > pre(obj.peek())) obj.push(infix[i++]);
					else
						postfix[j++] = obj.pop();
				}
			}
			while (!obj.isEmpty()) postfix[j++] = obj.pop();
			postfix[j] = '\0';
			return postfix;
		}
		void array_display_stack() {
			if (isEmpty()) {
				cout << " Stack is empty" << endl;
				return;
			}
			cout << " Stack elements: ";
			for (int i = top; i >= 0; i--) {
				cout << A[i] << " ";
			}
			cout << endl;
		}
};

class Queue_array {
		int* A;
		int front, rear, capacity;

	public:
		Queue_array(int size) {
			A = new int[size];
			front = rear = -1;
			capacity = size;
		}

		~Queue_array() {
			delete[] A;
		}

		bool isEmpty() {
			return front == -1;
		}

		bool isFull() {
			return (rear + 1) % capacity == front;
		}

		void enque(int val) {
			if (isFull()) {
				cout << "\t\t\t\tQueue is full\n";
				return;
			}
			if (isEmpty()) {
				front = rear = 0;
			} else {
				rear = (rear + 1) % capacity;
			}
			A[rear] = val;
		}

		int dequeue() {
			if (isEmpty()) {
				cout << " Queue is empty\n";
				return -1;
			}
			int val = A[front];
			if (front == rear) {
				front = rear = -1;
			} else {
				front = (front + 1) % capacity;
			}
			return val;
		}

		int getFront() {
			if (isEmpty()) {
				cout << "Queue is empty\n";
				return -1;
			}
			return A[front];
		}

		int getRear() {
			if (isEmpty()) {
				cout << "Queue is empty\n";
				return -1;
			}
			return A[rear];
		}

		int sizeOfQueue() {
			if (isEmpty()) return 0;
			return (rear - front + capacity) % capacity + 1;
		}
		void array_display_queue() {
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
				return;
			}
			int i = front;
			cout << "Queue elements: ";
			while (i != rear) {
				cout << A[i] << " ";
				i = (i + 1) % capacity;
			}
			cout << A[rear] << endl;
		}
		void reverseQueueUsingStack(Queue_array &q) {
			Stack_array s(q.sizeOfQueue());
			while (!q.isEmpty()) {
				s.push(q.dequeue());
			}
			while (!s.isEmpty()) {
				q.enque(s.pop());
			}
		}
};
class Node {
	public:
		int data;
		Node* next;
		Node(int val) {
			data=val;
			next=NULL;
		}
};
class Stack_linkedlist {
	private:
		Node *top;
		int size;
	public:
		Stack_linkedlist() {
			top = NULL;
			size = 0;
		} void push(int data) {
			Node *newNode = new Node(data);
			newNode->next = top;
			top = newNode;
			size++;
		} int pop() {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
				return -1;
			}
			int data = top->data;
			Node *temp = top;
			top = top->next;
			delete temp;
			size--;
			return data;
		}
		int peek() {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
				return -1;
			}
			return top->data;
		} // in stack linked list is never full
		bool isFull() {
			return false;
		} bool isEmpty() {
			return top == NULL;
		} int getSize() {
			return size;
		}
		void linkedlist_display_stack() {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
				return;
			}
			Node* temp = top;
			cout << "Stack elements: ";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		bool isBalanced(char *exp) {
			Node *top = NULL;
			for (int i = 0; exp[i] != '\0'; i++) {
				if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
					Node *newNode = new Node(exp[i]);
					newNode->next = top;
					top = newNode;
				} else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
					if (top == NULL) {
						return false;
					} else if ((exp[i] == ')' && top->data != '(') ||
					           (exp[i] == ']' && top->data != '[') ||
					           (exp[i] == '}' && top->data != '{')) {
						return false;
					} else {
						Node *temp = top;
						top = top->next;
						delete temp;
					}
				}
			}
			return top == NULL;
		}
		bool isOperand(char x) {
			return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
		}

		int pre(char x) {
			if (x == '+' || x == '-')
				return 1;
			else if (x == '*' || x == '/') return 2;
			return 0;
		}
		char* infixToPostfix(char* infix) {
			Stack_linkedlist stack;
			int i = 0, j = 0;
			int len = strlen(infix);
			char* postfix = new char[len + 1];

			while (infix[i] != '\0') {
				if (isOperand(infix[i])) {
					postfix[j++] = infix[i++];
				} else {
					if (pre(infix[i]) > pre(stack.peek())) {
						stack.push(infix[i++]);
					} else {
						postfix[j++] = stack.pop();
					}
				}
			}

			while (!stack.isEmpty()) {
				postfix[j++] = stack.pop();
			}

			postfix[j] = '\0';
			return postfix;
		}

};
class Queue_linkedlist {
		Node* front;
		Node* rear;
		int size;
	public:
		Queue_linkedlist() {
			front=NULL;
			rear=NULL;
			size=0;
		}
		~Queue_linkedlist() {
			while (!isEmpty()) {
				dequeue();
			}
		}

		void enque(int val) {
			Node* newNode = new Node(val);
			if (isEmpty()) {
				front = rear = newNode;
			} else {
				rear->next = newNode;
				rear = newNode;
			}
			size++;
		}

		int dequeue() {
			if (isEmpty()) {
				cout << "Queue is empty\n";
				return -1;
			}

			int x = front->data;
			Node* temp = front;
			front = front->next;
			delete temp;

			if (front == NULL) {
				rear = NULL;
			}
			size--;

			return x;
		}
		bool isEmpty() {
			return front == NULL;
		}
		int getFront() {
			if (isEmpty()) {
				cout << "Queue is empty\n";
				return -1;
			}
			return front->data;
		}

		int getRear() {
			if (isEmpty()) {
				cout << "Queue is empty\n";
				return -1;
			}
			return rear->data;
		}

		int sizeOfQueue() {
			return size;
		}

		void linkedlist_display_queue() {
			if (isEmpty()) {
				cout << "tQueue is empty" << endl;
				return;
			}
			Node* temp = front;
			cout << "Queue elements: ";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};
int main() {
	int main_choice;
	do {
		cout << "****************************************************" << endl;
		cout << "                      Menu                          " << endl;
		cout << "****************************************************" << endl;
		cout << "* Use Array (Stack and Queue)" << endl;
		cout << "* Use Singly Linked List (Stack and Queue)" << endl;
		cout << "* Exit" << endl;
		
		cin >> main_choice;
		switch (main_choice) {
			case 1: {
				int array_choices;
				int stackSize, queueSize;
				cout << "Enter size for Stack and Queue: ";
				cin >> stackSize >> queueSize;
				Stack_array stackArray(stackSize);
				Queue_array queueArray(queueSize);
				do {
					cout << "Array :" << endl;
					cout << "Stack functions" << endl;
					cout << "Queue functions" << endl;
					cout << "Go back to main menu" << endl;
					cout << "Enter your choice: ";
					cin >> array_choices;

					switch (array_choices) {
						case 1: {
							int stack_functions;
							do {
								cout << " Array Stack Functions:" << endl;
								cout << " Push" << endl;
								cout << " Pop" << endl;
								cout << " Peek" << endl;
								cout << " Check if stack is empty" << endl;
								cout << " Check if stack is full" << endl;
								cout << " Get stack size" << endl;
								cout << " To display"<<endl;
								cout << " To Check balancedParenthesis" << endl;
								cout << " To Convert infix To Postfix" << endl;
								cout << " Go back to Array Functions" << endl;
								cout << " Enter your choice: ";
								cin >> stack_functions;
								switch (stack_functions) {
									case 1: {
										int val;
										cout << "Enter value to push: ";
										cin >> val;
										stackArray.push(val);
										break;
									}
									case 2: {
										int poppedVal = stackArray.pop();
										if (poppedVal != -1) {
											cout << "Popped value: " << poppedVal << endl;
										}
										break;
									}
									case 3: {
										int peekVal = stackArray.peek();
										if (peekVal != -1) {
											cout << "Top of stack: " << peekVal << endl;
										}
										break;
									}
									case 4: {
										if (stackArray.isEmpty()) {
											cout << "Stack is empty\n";
										} else {
											cout << "Stack is not empty\n";
										}
										break;
									}
									case 5: {
										if (stackArray.isFull()) {
											cout << "Stack is full\n";
										} else {
											cout << "Stack is not full\n";
										}
										break;
									}
									case 6: {
										cout << "Stack size: " << stackArray.size() << endl;
										break;
									}
									case 7: {
										stackArray.array_display_stack();
										break;
									}
									case 8: {
										char exp[100];
										cout << "Enter an expression: ";
										cin.ignore();
										cin.getline(exp, 100);
										if (stackArray.isBalanced(exp)) {
											cout << "The expression " << exp << " has balanced parentheses.\n";
										} else {
											cout << "The expression " << exp << " does not have balanced parentheses.\n";
										}
										break;
									}
									case 9: {
										char infix[100];
										cout << "Enter an expression: ";
										cin.ignore();
										cin.getline(infix, 100);
										cout << "Infix: " << infix << endl;
										cout << "Postfix: " << stackArray.InToPost(infix) << endl;
										break;
									}
									case 10:
										break;
									default:
										cout << "\t\t\t\tInvalid choice!" << endl;
								}
							} while (stack_functions != 10);
							break;
						}
						case 2: {
							int queue_choices;
							do {
								cout << "\n\t\t\t\tArray Queue Functions:" << endl;
								cout << "1. Enqueue" << endl;
								cout << "2. Dequeue" << endl;
								cout << "3. Get front element" << endl;
								cout << "4. Get rear element" << endl;
								cout << "5. Check if queue is empty" << endl;
								cout << "6. Check if queue is full" << endl;
								cout << "7. Get queue size" << endl;
								cout << "8. To display"<<endl;
								cout << "9. To Reverse Queue using stack"<<endl;
								cout << "10. Go back to array functions menu" << endl;
								cout << "Enter your choice: ";
								cin >> queue_choices;

								switch (queue_choices) {
									case 1: {
										int val;
										cout << "Enter value to enqueue: ";
										cin >> val;
										queueArray.enque(val);
										break;
									}
									case 2: {
										int dequeuedVal = queueArray.dequeue();
										if (dequeuedVal != -1) {
											cout << "Dequeued value: " << dequeuedVal << endl;
										}
										break;
									}
									case 3: {
										int frontVal = queueArray.getFront();
										if (frontVal != -1) {
											cout << "Front of queue: " << frontVal << endl;
										}
										break;
									}
									case 4: {
										int rearVal = queueArray.getRear();
										if (rearVal != -1) {
											cout << "Rear of queue: " << rearVal << endl;
										}
										break;
									}
									case 5: {
										if (queueArray.isEmpty()) {
											cout << "Queue is empty\n";
										} else {
											cout << "Queue is not empty\n";
										}
										break;
									}
									case 6: {
										if (queueArray.isFull()) {
											cout << "Queue is full\n";
										} else {
											cout << "Queue is not full\n";
										}
										break;
									}
									case 7: {
										cout << "Queue size: " << queueArray.sizeOfQueue() << endl;
										break;
									}
									case 8: {
										queueArray.array_display_queue();
										break;
									}
									case 9: {
										queueArray.array_display_queue();
										cout << "Reversing the queue using a stack...\n";
										queueArray.reverseQueueUsingStack(queueArray);
										queueArray.array_display_queue();
										cout << "Queue reversed successfully!\n";
										break;
									}
									case 10:
										break;
									default:
										cout << "Invalid choice!" << endl;
								}
							} while (queue_choices != 10);
							break;
						}
						case 3:
							break;
						default:
							cout << "Invalid choice!" << endl;
					}
				} while (array_choices != 3);
				break;
			}
			case 2: {
				int linkedlist_choices;
				Stack_linkedlist stack_linkedlist;
				Queue_linkedlist queue_linkedlist;
				do {
					cout << "\nSingly LinkedList Functions:" << endl;
					cout << "1. Stack Functions" << endl;
					cout << "2. Queue Functions" << endl;
					cout << "3. Go back to main menu" << endl;
					cout << "Enter your choice: ";
					cin >> linkedlist_choices;

					switch (linkedlist_choices) {
						case 1: {
							int stack_functions;
							do {
								cout << "\nSingly LinkedList Stack Functions:" << endl;
								cout << "1. Push" << endl;
								cout << "2. Pop" << endl;
								cout << "3. Peek" << endl;
								cout << "4. Check if stack is empty" << endl;
								cout << "5. Get stack size" << endl;
								cout << "6. To display"<<endl;
								cout << "7. To balancedParenthesis"<<endl;
								cout << "8. To infixToPostfix()"<<endl;
								cout << "9. Go back to Singly LinkedList Functions" << endl;
								cout << "Enter your choice: ";
								cin >> stack_functions;

								switch (stack_functions) {
									case 1: {
										int val;
										cout << "Enter value to push: ";
										cin >> val;
										stack_linkedlist.push(val);
										break;
									}
									case 2: {
										int x = stack_linkedlist.pop();
										if (x != -1) {
											cout << "Popped value: " << x << endl;
										}
										break;
									}
									case 3: {
										int x = stack_linkedlist.peek();
										if (x != -1) {
											cout << "Top of stack: " << x << endl;
										}
										break;
									}
									case 4: {
										if (stack_linkedlist.isEmpty()) {
											cout << "Stack is empty\n";
										} else {
											cout << "Stack is not empty\n";
										}
										break;
									}
									case 5: {
										cout << "Stack size: " << stack_linkedlist.getSize() << endl;
										break;
									}
									case 6: {
										stack_linkedlist.linkedlist_display_stack();
										break;
									}
									case 7: {
										char exp[100];
										cout << "Enter an expression: ";
										cin.ignore();
										cin.getline(exp, 100);
										if (stack_linkedlist.isBalanced(exp)) {
											cout << "The expression " << exp << " has balanced parentheses.\n";
										} else {
											cout << "The expression " << exp << " does not have balanced parentheses.\n";
										}
										break;
									}
									case 8: {
										char infix[100];
										cout << "Enter an infix expression: ";
										cin.ignore();
										cin.getline(infix, 100);

										char* postfix = stack_linkedlist.infixToPostfix(infix);

										cout << "Infix: " << infix << endl;
										cout << "Postfix: " << postfix << endl;
										break;
									}
									case 9:
										break;
									default:
										cout << "Invalid choice!" << endl;
								}
							} while (stack_functions!= 9);
							break;
						}
						case 2: {
							int queue_functions;
							do {
								cout << "\nSingly LinkedList Queue Functions:" << endl;
								cout << "1. Enqueue" << endl;
								cout << "2. Dequeue" << endl;
								cout << "3. Get front element" << endl;
								cout << "4. Get rear element" << endl;
								cout << "5. Check if queue is empty" << endl;
								cout << "6. Get queue size" << endl;
								cout << "7. To display"<<endl;
								cout << "8. Go back to Singly LinkedList Functions" << endl;
								cout << "Enter your choice: ";
								cin >> queue_functions;

								switch (queue_functions) {
									case 1: {
										int val;
										cout << "Enter value to enqueue: ";
										cin >> val;
										queue_linkedlist.enque(val);
										break;
									}
									case 2: {
										int dequeued_value = queue_linkedlist.dequeue();
										if (dequeued_value != -1) {
											cout << "Dequeued value: " << dequeued_value << endl;
										}
										break;
									}
									case 3: {
										int first_value = queue_linkedlist.getFront();
										if (first_value != -1) {
											cout << "Front of queue: " << first_value << endl;
										}
										break;
									}
									case 4: {
										int last_value = queue_linkedlist.getRear();
										if (last_value != -1) {
											cout << "Rear of queue: " << last_value << endl;
										}
										break;
									}
									case 5: {
										if (queue_linkedlist.isEmpty()) {
											cout << "Queue is empty\n";
										} else {
											cout << "Queue is not empty\n";
										}
										break;
									}
									case 6: {
										cout << "Queue size: " << queue_linkedlist.sizeOfQueue() << endl;
										break;
									}
									case 7: {
										queue_linkedlist.linkedlist_display_queue();
										break;
									}
									case 8:
										break;
									default:
										cout << "Invalid choice!" << endl;
								}
							} while (queue_functions!= 8);
							break;
						}
						case 3:
							break;
						default:
							cout << "Invalid choice!" << endl;
					}
				} while (linkedlist_choices != 3);
				break;
			}
			case 3:
				cout << "Exiting the program. Allah_Hafiz!";
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
	} while (main_choice != 3);
	return 0;
}