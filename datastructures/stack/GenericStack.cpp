#include<algorithm>
#include<string>
#include<cstdio>
#include<cassert>
#include<stdexcept>

template<typename T>
class GenericStack{
    private: T * data = 0;
    private: int topIndex = -1;
    private: int capacity;

    public: 
    ~GenericStack() { delete[] data; }
    public: 
    GenericStack(const int capacity) {
        this->data = new T[capacity];
	this->capacity = capacity;
    }

    private:
    inline bool hasSpace() { return this->topIndex < this->capacity - 1; } 

    private:
    inline bool hasData() { return this->topIndex > -1; }

    public:
    bool isEmpty() { return this->topIndex < 0; }

    public: 
    bool push(T data){
        if(this->hasSpace()) {
	    this->data[++this->topIndex] = data;
	    return true;
	}
	return false;
    }

    public: T pop(){ 
	if(hasData()) return this->data[this->topIndex--]; 

        throw std::underflow_error("Stack is empty");
    }

    public: 
    void forEach(void (* consume)(const T)){
        int startIndex = this->topIndex;
	while(startIndex > -1) consume(this->data[startIndex--]);

    }

    public:
    int size(){ return this->topIndex + 1; }

};

int main(int argc, char ** argv){
    printf("We have created a generic stack.\n");    
    std::string myName("Anurag Anand");
    GenericStack<char> stack(10);
    int index = 0;
    for_each(myName.begin(), myName.end(), [&](const char ch) { stack.push(ch); });
    //while(stack.push(myName.at(index++)));
    printf("Size of stack %d.\n", stack.size());
    stack.forEach([](const char ch) { printf("%c ", ch); });

    
    GenericStack<int> stackOfInt(10);
    int value = 1;
    while(stackOfInt.push(value++));
    printf("Size of int stack %d.\n", stackOfInt.size());
     
    auto consumer = [](const int value) { printf("%d ", value); };
    stackOfInt.forEach(consumer);
    stackOfInt.pop();
    printf("Size of int stack %d.\n", stackOfInt.size());
//    stackOfInt.forEach(consumer);
    printf("\n");
    while(!stackOfInt.isEmpty()){
        consumer(stackOfInt.pop());
    }
}


