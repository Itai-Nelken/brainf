#include <iostream>

class stack {
	char *data;
	int sp, max_size;

	uint stringlen(const char *s) {
		uint length=0;
		while(*s++) {
			length++;
		}
		return length;
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
		//if(sp==max_size) return true;
		//else return false;
		return sp==max_size ? true : false;
	}
	bool isEmpty() {
		//if(sp<0) return true;
		//else return false;
		return sp<0 ? true : false;
	}
	bool push(char a) {
    	if(isFull()) {
    	    std::cerr << "Stack is full.\n";
    	    return false;
    	} else {
    	    data[sp]=a;
    	    sp++;
    	    return true;
    	}
	}
	char pop() {
		if(isEmpty()) {
			std::cerr << "Stack is empty.\n";
			return false;
		}
		sp--;
		return data[sp+1];
	}
	char peek() {
		if(isEmpty()) {
			std::cerr << "Stack is empty.\n";
			return false;
		}
		return data[sp-1];
	}
	void dump() {
		for(int i=0; i<stringlen(data); i++) {
			std::cout << "[" << i << "] " << data[i] << std::endl;
		}
	}
};

int main(void) {
	stack s(10);
	s.push('a');
	s.push('b');
	std::cout << s.peek() << std::endl;
	s.dump();
	return 0;
}
