#include "Customer.h"
#include "Queue.h"

#include <stdlib.h>  
#include <iostream>

using namespace std;

// g++ --std=c++17 q7.cpp Customer.cpp Queue.cpp -o ./output.out && ./output.out


int main(){
    Queue *q = new Queue;
    srand(time(0)); 

    int n, total, c = -1;
    cout << "Enter number of simulation: ";
    cin >> n;

    for (int i = 0; i <= n; i++){
        c++;
        if (!q->isEmpty()){
            Customer customer;
            q->dequeue(customer);
            int qn = c - customer.getQueueNum();
            total += qn;
            cout << "Customer " << customer.getName() << " was served in " << qn << " min(s)" << endl;
        }
        
        if (i < n){
            int random = rand() % 3;
            if (random == 0)
                cout << "No customer will be picked up this round." << endl;
            while (random--){
                Customer cust;
                string name;
                cout << "Enter Customer name: ";
                cin >> name;
                cust.setName(name);
                cust.setQueueNum(c);
                q->enqueue(cust);
            }
        }
    }

    cout << "In this " << n << "-min period, the average time to be served = " << total/double(n) << " mins" << endl;

    return 0;
}