#include<iostream>

namespace LL {
    class LinkedList {
        struct Node{
	    int data;
	    struct Node * next;
	    struct Node * prev;

	    Node(struct Node * prev, int const data, struct Node * next){
	        this->prev = prev;
		this->data = data;
		this->next = next;
	    }
	};

	struct Node * head;
	struct Node * tail;
	int noOfTimesModified;
	int totalNodes;

	public: int size() const { return totalNodes; }

	public: void add(int const data){
	    addAtTheEnd(data);
	}

	public: void forEach(void (* intConsumer) (int const)){
	    struct Node * _head = this->head;

	    while(_head){
		intConsumer(_head->data);
	        _head = _head->next;
	    }
	}

	private: void addAtTheEnd(int const data){
	    struct Node * _tail = this->tail;
	    struct Node * newNode = new Node(_tail, data, NULL);
	    this->tail = newNode;

	    if(!this->head){
	        this->head = newNode;
	    } else {
	        _tail->next = this->tail;
	    }

	    ++totalNodes;
	    ++noOfTimesModified;
	}
    };

}

int main(){
    LL::LinkedList * linkedList = new LL::LinkedList();
    
    linkedList->add(12);
    linkedList->add(8);
    linkedList->add(22);
    linkedList->add(19);
    linkedList->add(15);

    std::cout << "List Size Is " << linkedList->size() << std::endl;

    linkedList->forEach([](int const data) { std::cout << data << std::endl; });

    delete linkedList;
    return 0;
}


