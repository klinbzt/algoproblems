#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        int nrElem, nrMaxElem;
        int *heap;
        int (*cmp)(int, int);

        static int minCmp(int child, int parent) {
            return child > parent;
        }

        static int maxCmp(int child, int parent) {
            return child < parent;
        }
    public:
        Heap(int nrMaxElem, int type = 0) {
            this->nrMaxElem = nrMaxElem;
            this->nrElem = 0;
            this->cmp = (type == 0) ? minCmp : maxCmp;
            this->heap = new int[nrMaxElem];
        }

        ~Heap() {
            delete this->heap;
        }

        void push(int elem);
        int pop();
        void heapifyUp(int pos);
        void heapifyDown(int pos);
};

void Heap::push(int elem) {
    if (nrElem < nrMaxElem) {
        heap[nrElem++] = elem;
        heapifyUp(nrElem - 1);
    } else if (elem > heap[0]) {
        pop();
        push(elem);
    }
}

void Heap::heapifyUp(int start) {
    int aux = start;

    while (aux > 0) {
        if (!cmp(heap[aux], heap[(aux - 1)/ 2])) {
            swap(heap[aux], heap[(aux - 1)/ 2]);
        } else {
            break;
        }
        aux = (aux - 1)/ 2;
    }
}

void Heap::heapifyDown(int start) {
    int aux = start;

    while (aux < nrElem) {
        int maximum = aux;

        if (aux * 2 + 1 < nrElem && cmp(heap[maximum], heap[aux * 2 + 1])) {
            maximum = aux * 2 + 1;
        } 
        if (aux * 2 + 2 < nrElem && cmp(heap[maximum], heap[aux * 2 + 2])) {
            maximum = aux * 2 + 2;
        } 

        if (maximum == aux) {
            break;
        }
        
        swap(heap[aux], heap[maximum]);
        aux = maximum;
    }
}

int Heap::pop() {
    if (nrElem == 0) {
        return -1;
    }

    swap(heap[0], heap[--nrElem]);
    heapifyDown(0);

    return heap[nrElem];
}

int main() {
    int n, k, A, B, C, D;

    cin >> n >> k >> A >> B >> C >> D;
        if (k > n) {
        k = n;
    }
    
    Heap heap(k);
    heap.push(A);

    for (int i = 0; i < n; i++) {
        A = (1ll * B * A + C) % D;
        heap.push(A);
    }



    while (k--) {
        cout << heap.pop() << ' ';
    }
}