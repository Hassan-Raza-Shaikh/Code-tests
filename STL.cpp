#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<deque>
#include<list>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    cout<<"Size of vector: "<<v.size()<<endl;
    cout<<"Capacity of vector: "<<v.capacity()<<endl;
    cout<<"Elements in vector: ";
    for(auto it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";                 // can also be accessed by indexing
    }
    cout<<endl;
    for(auto it : v)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    sort(v.begin(), v.end());
    cout<<"Sorted elements in vector: ";
    for(auto it : v)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    sort(v.begin(), v.end(), greater<int>());
    cout<<"Sorted elements in vector in descending order: ";
    for(auto it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    v.pop_back(); // remove last element
    cout<<"Elements in vector after pop_back: ";
    for(auto it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";                 // can also be accessed by
    }
    cout<<endl;
    v.clear(); // remove all elements


    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);                    // values can also be stored 
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);
    cout<<"Size of deque: "<<d.size()<<endl;
    cout<<"Elements in deque: ";
    for(auto it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";                 // can also be accessed by
    }
    cout<<endl;
    d.pop_back(); // remove last element
    cout<<"Elements in deque after pop_back: ";
    for(auto it : d)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    d.pop_front(); // remove first element
    cout<<"Elements in deque after pop_front: ";
    for(auto it : d)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    cout<<"Element at index 1: "<<d.at(1)<<endl;
    cout<<"Element at index 0: "<<d[0]<<endl;
    

    list<int> l={1,4,3,2,5};
    cout<<"Elements in list: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    l.push_back(6);
    cout<<"Elements in list after push_back: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    l.push_front(0);
    cout<<"Elements in list after push_front: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    l.pop_back(); // remove last element
    cout<<"Elements in list after pop_back: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    l.pop_front(); // remove first element
    cout<<"Elements in list after pop_front: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    l.sort(); // sort the list
    cout<<"Elements in list after sort: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    l.reverse(); // reverse the list
    cout<<"Elements in list after reverse: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";                 
    }
    cout<<endl;
    auto it=l.begin();
    advance(it, 2); // move iterator to index 2
    l.insert(it, 10); // insert 10 at index 2           // indexing not possible in list
    cout<<"Elements in list after insert: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    l.erase(it); // remove element at index 2
    cout<<"Elements in list after erase: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    list<int> l2={7,8,9};
    l.merge(l2); // merge two lists
    cout<<"Elements in list after merge: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    l.remove(5); // remove element 5 from list
    cout<<"Elements in list after remove: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    l.splice(it, l2); // insert elements of l2 at index 2
    cout<<"Elements in list after splice: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    l.unique(); // remove duplicate elements
    cout<<endl;
    cout<<"Elements in list after unique: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    l.sort(); // sort the list
    cout<<"Elements in list after sort: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
    l.clear(); // remove all elements
    cout<<"Elements in list after clear: ";
    for(auto it : l)
    {
        cout<<it<<" ";                 
    }
    cout<<endl;
 
    return 0;
}