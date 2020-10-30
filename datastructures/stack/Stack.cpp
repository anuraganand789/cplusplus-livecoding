#include<stdexcept>
#include<cassert>
#include<cstdio>

class Stack{
  private: int * data = nullptr;
  private: int capacity;
  private: int lastIndex;
  private: int topIndex = -1;

  public: Stack(const int capacity){
      assert(capacity > 0);
      this->data = new int[capacity];
      this->capacity = capacity;
      this->lastIndex = capacity - 1;
  }
  public: ~Stack() { delete[] this->data; }

  public: bool isEmpty() { return this->topIndex == -1; }

  private: bool hasSpace(){ return this->topIndex < this->lastIndex; }

  public: bool push(const int data){
     if(hasSpace()){
         this->data[++this->topIndex] = data;
         return true;
     }
     return false;
  }

  public: int pop(){
      if(this->hasNext()) return this->data[this->topIndex--];

      throw std::invalid_argument("Stack Is Empty!!!");
  }

  public: void forEach(void (* consume)(const int)){
      int startIndex = 0;
      int endIndex   = capacity;
      while(startIndex < endIndex){ consume(this->data[startIndex++]); }
  }

  public: bool hasNext() { return !isEmpty(); }
  public: int size() { return topIndex + 1; }

};

int main(int argc, char ** argv){
    const int size = 10;
    Stack stack(size);

    int data = 11;
    while(stack.push(data++));
    
    printf("Current Size %d.\n", stack.size());
    auto consume = [](const int intValue) { printf("%d ", intValue); };
    stack.forEach(consume);

    printf("\n");
    while(stack.hasNext()) consume(stack.pop());
    printf("\n");
    printf("Current Size %d.\n", stack.size());
}
