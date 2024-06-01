#include<iostream>
#include<string>
using namespace std;
//item is the data type for task it contain name ,id and check flag
class item
{
    int id;
    string name;
    bool done;
public:
    item(){}
    // constructor which take component of the task
    item(int id,string name,bool done=0)
    {
        this->id=id;
        this->name=name;
        this->done=done;
    }
    //setter
    void setName(string name)
    {
        this->name=name;
    }
    void setFinsh(bool done)
    {
        this->done=done;
    }
    void setId(int id)
    {
        this->id=id;
    }
    //getter
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    bool isDone()
    {
        return done;
    }
};