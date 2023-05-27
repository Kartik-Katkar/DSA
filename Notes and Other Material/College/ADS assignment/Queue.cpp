#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

int cqueue[5];
int front = -1, rear = -1, n=5;


void insertCQ(int val) {
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   cqueue[rear] = val ;
}
void deleteCQ() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<cqueue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}
void displayCQ() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (f <= r) {
      while (f <= r){
         cout<<cqueue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<cqueue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<cqueue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}


int circularqueue()
{
    int ch, val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         insertCQ(val);
         break;

         case 2:
         deleteCQ();
         break;

         case 3:
         displayCQ();
         break;

         case 4:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 4);

    return 0;
}
int reversestack()
{ 
   int n;   //Number of elements to take as input from the user.

    cout<<"\nEnter the Number of Elements : \n";
    cin>>n;

    stack<int> s;
    queue<int> q;
    int data;
    //Enter the elements.
    for(int i=0;i<n;i++){
        cout<<"\nEnter Element at index "<<i<<" : \n";
        cin>>data;
        s.push(data);
    }

    //Push the element into the queue from the stack and print the element to denote how they are being stored in the stack.

    cout<<"Elements before reversing the stack:"<<endl;
    while(s.size()!=0){
        int ele=s.top();
        cout<<ele<<" ";
        q.push(ele);
        s.pop();
     }
     cout<<endl;

     //Push the element into the stack from the queue.

     while(q.size()!=0){
         int ele=q.front();
         s.push(ele);
         q.pop();
     }

     cout<<"Elements after reversing the stack:"<<endl;
     while(s.size()!=0){
         cout<<s.top()<<" ";
         s.pop();
     }
     cout<<endl;
    return 0;
}
int main()
{

    int choice, n;

    do
    {
        cout << "\n Menu \n 1.Circular Queue \n 2.Reverse stack using queue \n 3.Exit \n";
        cout << "\n Enter Your Choice : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            circularqueue();
            break;

        case 2:
            reversestack();
            break;

        case 3:
            cout << "\n Successfully Exited  \n";
            break;

        default:
            cout << "\n Invalid Choice \n";
            break;
        }
    } while (choice != 3);
}
