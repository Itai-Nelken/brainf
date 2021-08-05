#include <iostream>

using namespace std;

class stack {
	char *data;
	int sp, max_size;

	uint strlen(char *str) {
		uint size=0;
		for(int i=0; str[i]!='\0'; ++i) {
			++size;
		}
		return size;
	}
public:
	stack(size_t size) {
		this->data=new char[size];
		this->max_size=size;
		this->sp=0;
	}
	~stack() {
		delete[] data;
	}
	
	bool isFull() {
		if(sp==max_size) return true;
		else return false;
	}
	bool isEmpty() {
		if(sp<0) return true;
		else return false;
	}
	bool push(char a) {
    	if(isFull()) {
    	    cout << "Stack is full.\n";
    	    return false;
    	} else {
    	    data[sp]=a;
    	    sp++;
    	    return true;
    	}
	}
	char pop() {
		sp--;
		return data[sp+1];
	}
	char peek() {
		if(isEmpty()) {
			cout << "Stack is empty.\n";
			return false;
		}
		return data[sp-1];
	}
	void dump() {
		for(int i=0; i<strlen(data); i++) {
			cout << "[" << i << "] " << data[i] << endl;
		}
	}
};

int main(void) {
	stack s(10);
	s.push('a');
	s.push('b');
	cout << s.peek() << endl;
	s.dump();
	return 0;
}
