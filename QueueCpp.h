
#ifndef QueueCpp_h
#define QueueCpp_h

struct Node
{
    Node* lchild;
    Node* rchild;
    int data;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node** Q;
public:
    Queue(int size)
    {
        this->size = size;
        front = rear = 0;
        Q = new Node*[this->size];
    }
    void enqueue(Node* value);
    Node* dequeue();
    bool isEmpty();
    void display();
};

void Queue::enqueue(Node* value)
{
    if((rear+1)%size == front)
        std::cout<<"Queue is full \n";
    else
    {
        rear = (rear+1)%size;
        Q[rear] = value;
    }
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if(rear == front)
        std::cout<<"Queue is empty \n";
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

bool Queue::isEmpty()
{
    return front == rear;
}

void Queue::display()
{
    int i = front+1;
    do
    {
        std::cout<<Q[i]<<" ";
        i = (i+1)%size;
    }while((i!=rear+1)%size);
    std::cout<<"\n";
}


#endif /* QueueCpp_h */
