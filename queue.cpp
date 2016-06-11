#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

template <class T>
/**
 * @brief Queue class implementation.
 */
class Queue {
  /**
   * @brief Node in the queue. Each Node
   * element holds some data and the pointer
   * to the next Node.
   */
  class Node {
    public:
      T data;
      Node* next;
      Node(T d) : data(d), next(NULL) {}
  };
  public:
    /**
     * @brief Queue constructor initializes
     * a queue. It is upto the client to allocate
     * and dellocate memory for the Queue elements.
     */ 
    Queue() {
      head = NULL;
      tail = NULL;
      s = 0;
    }
    /**
     * @brief Enqueue method adds a new Node to the 
     * end of the Queue.
     *
     * @param data - Element to be enqueued.
     */
    void enqueue(T data)
    {
      Node* temp = new Node(data);
      s++;
      if(tail == NULL) {
        head = temp;
        tail = temp;
      } else {
        tail->next = temp;
        tail = temp;
      }
    }
    /**
     * @brief insertAtHead method inserts a new Node
     * to the head of the Queue.
     *
     * @param data - Element to be inserted at the head.
     */
    void insertAtHead(T data)
    {
      Node *temp = new Node(data);
      s++;
      if(tail == NULL)
      {
        head = temp;
        tail = temp;
      } else {
        temp->next = head;
        head = temp;
      }
    }
    /**
     * @brief dequeue method removes the first element 
     * in the Queue and returns the element.
     *
     * @param None
     * @return Data at the head of the Queue.
     */
    T dequeue()
    {
      T temp = head->data;
      Node *tempNode = head;
      head = head->next;
      free(tempNode);
      s--;
      return temp;
    }
    /**
     * @brief isEmpty method checks if the Queue is empty
     * or not.
     *
     * @param None
     * @return True if Queue is empty, False otherwise.
     */
    bool isEmpty()
    {
      return (s == 0);
    }
    /**
     * @brief size method returns the current size of the
     * Queue.
     *
     * @param None.
     * @return int - Size of the Queue
     */
    int size()
    {
      return s;
    }

  private:
    Node* head; /**< Head of the Queue */
    Node* tail; /**< Tail of the Queue */
    int s;   /**< Size of the Queue */
};

/**
 * Elements in the Queue use this structure.
 */
typedef struct {
  int queueValue1;
  int queueValue2;
}QueueElement;

int main(int argc, char *argv[])
{
  if(argc == 2)
  {
    Queue<QueueElement *> q;
    srand(time(NULL));
    /* Enqueuing n elements in the Queue */
    for(int i = 0; i < atoi(argv[1]); i++)
    {
      /** Allocate memory in heap for the QueueElement */
      QueueElement *temp = (QueueElement *) calloc(1, sizeof(QueueElement));
      temp->queueValue1 = rand()%100; 
      temp->queueValue2 = rand()%100; 
      q.enqueue(temp);
      cout << "Enqueuing " << temp->queueValue1 << ' ' << temp->queueValue2 << endl;
    }
    /* Insert a new element to the head of Queue */
    QueueElement *temp = (QueueElement *) calloc(1, sizeof(QueueElement));
    temp->queueValue1 = rand()%100; 
    temp->queueValue2 = rand()%100; 
    q.insertAtHead(temp);
    cout << "insertAtHead " << temp->queueValue1 << ' ' << temp->queueValue2 << endl;
    while(!q.isEmpty())
    {
      QueueElement *temp = q.dequeue();
      cout << "Dequeuing " << temp->queueValue1 << ' ' << temp->queueValue2 << endl;
      /** Free the QueueElement after dequeuing */
      free(temp);
    }
  }
  else
  {
    cout << "Usage: ./a.out n" << endl << "enqueues and dequeues n+1 elements into the queue" << endl;
  }
  return 0;
}
