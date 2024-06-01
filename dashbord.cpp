#include<iostream>
#include<string>
#include "item.h"
#include "linkedList.h"
using namespace std;
int main()
{
    // creat object of linkedlist which has the data type item
    LinkedList<item>list;
    // counter to id task
    int taskid=1;
    // show list of the provided functions to choose from 
    while(1)
    {
        cout
        <<"1-Adding a task\n"
        <<"2-Removing a task\n"
        <<"3-Displaying the to-do list\n"
        <<"4-check if the task is done\n"
        <<"5-Finsh task\n"
        <<"6-count tasks\n"
        <<"7-Exit\n";
        int x;cin>>x;
        if(x==1)
        {
            cout<<"Enter the task name: \n";
            string name; 
            cin.ignore();
            getline(cin,name);
            // intialize the task with the provied information
            item task(taskid,name);
            // store the task in list
            list.insert(task);
            taskid++;
        }else if(x==2)
        {
            cout<<"Enter the task number: \n";
            int index;cin>>index;
            // list is zero based so we work in position-1
            list.remove(index-1);
            // when removing a task we must shift the id for the below tasks
            for(int i=index-1; i<list.getSize(); i++)
            {
                item temp=list.retrive(i);
                temp.setId(i+1);
                list.update(i,temp);
            }
            taskid--;
        }else if(x==3)
        {
            for(int i=0; i<list.getSize(); i++)
            {
                item temp=list.retrive(i);
                // provide the id and the statu for each task
                cout<<temp.getId()<<"-"<<temp.getName()<<" | "<<temp.isDone()<<endl;

            }
        }else if(x==4)
        {
            cout<<"Enter the task number\n";
            int index;cin>>index;
            if(list.retrive(index-1).isDone())
                 cout<<"Done\n";
            else
                 cout<<"Not yet\n";
        }else if(x==5)
        {
            cout<<"Enter the task number\n";
            int index;cin>>index;
            //return the task -> update it -> set it back
            item temp=list.retrive(index-1);
            temp.setFinsh(1);
            list.update(index-1,temp);
        //we can use the taskid to know the number of tasks
        }else if(x==6)
        {
            //taskid-1 becuse it is initialized to 1 
            cout<<"the number of tasks is: "<<taskid-1<<endl;
        }else
            break;
        cout<<"===========================================\n";
    }
}