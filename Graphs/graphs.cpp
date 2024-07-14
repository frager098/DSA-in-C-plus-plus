#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void enqueue(node*& rear, node*& front, int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL && front == NULL) {
        rear = new_node;
        front = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(node*& rear, node*& front) {
    node* current = front;
    front = current->next;
    delete current;
    return;
}

struct edge {
    int data;
    edge* next;
};

struct vertex {
    int data;
    vertex* next;
    edge* edgeList;
};

void insertVertex(vertex*& head_refer, int data) {
    vertex* new_node = new vertex();
    new_node->data = data;
    new_node->next = NULL;
    new_node->edgeList = NULL;

    if (head_refer == NULL) {
        head_refer = new_node;
    }
    else {
        vertex* current = head_refer;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insertEdge(vertex*& head_refer, int vertexData, int data) {
    edge* new_node = new edge();
    new_node->data = data;
    new_node->next = NULL;

    vertex* current = head_refer;
    while (current != NULL) {
        if (current->data == vertexData) {
            if (current->edgeList == NULL) {
                current->edgeList = new_node;
            }
            else {
                edge* temp = current->edgeList;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
            return;
        }
        else {
            current = current->next;
        }
    }
}

int length(vertex* head_refer) {
    vertex* current = head_refer;
    int len = 0;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}

void BFS(vertex*& head_refer, node*& rear, node*& front) {
    if (head_refer == NULL) {
        cout << "Graph is empty!" << endl;
        return;
    }

    int len = length(head_refer);
    bool* visited = new bool[len];
    for (int a = 0; a < len; a++) {
        visited[a] = false;
    }

    vertex* current = head_refer;
    while (current != NULL) {
        if (!visited[current->data]) {
            enqueue(rear, front, current->data);
            visited[current->data] = true;

            while (front != NULL) {
                int currentVertex = front->data;
                dequeue(rear, front);

                cout << currentVertex << " ";

                vertex* ptr = head_refer;
                while (ptr != NULL && ptr->data != currentVertex) {
                    ptr = ptr->next;
                }
                if (ptr != NULL && ptr->data == currentVertex) {
                    edge* ptr2 = ptr->edgeList;
                    while (ptr2 != NULL) {
                        int temp = ptr2->data;
                        if (!visited[temp]) {
                            enqueue(rear, front, temp);
                            visited[temp] = true;
                        }
                        ptr2 = ptr2->next;
                    }
                }
            }
        }
        current = current->next;
    }

    delete[] visited;
}

int main() {
    node* rear = NULL;
    node* front = NULL;

    vertex* head = NULL;

    // Adding vertices
    insertVertex(head, 0);
    insertVertex(head, 1);
    insertVertex(head, 2);
    insertVertex(head, 3);
    insertVertex(head, 4);

    // Adding edges
    insertEdge(head, 0, 1);
    insertEdge(head, 0, 2);
    insertEdge(head, 1, 2);
    insertEdge(head, 2, 0);
    insertEdge(head, 2, 3);
    insertEdge(head, 3, 3);

    BFS(head, rear, front);

    return 0;
}
