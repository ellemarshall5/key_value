#include <iostream>
#include <array>
#include "key_value.h"
#include "carton.h"
using namespace std;

int main() {

    //create KeyValue object
    KeyValue<int, string, 4> one;

    //add keys/values to KeyValue object
    one.Add(1, "cat");
    one.Add(2, "dog");
    one.Add(3, "lobster");
    one.Add(4, "spider");

    //a way to catch if key doesn't exist. tests for key and if not there throws exception
    try{
        cout << "The value at key 2 is: " << one.ValueAt(2) << endl;
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }

    //call RemoveOne Function to remove key/value
    one.RemoveOne(2);
    //print out object
    cout << one;

    //create second KeyValue object
    KeyValue<int, Carton, 6> two;

    //add keys/values to KeyValue object
    two.Add(9, Carton(34,65,24));
    two.Add(4, Carton(9,22,54));
    two.Add(9, Carton(5,2,7));
    two.Add(84, Carton(3,2,5));
    two.Add(3,Carton(3,2,6));
    two.Add(10, Carton(3,6,3));

    //a way to catch if key doesn't exist. tests for key and if not there throws exception
    try{
        cout << "The value at key 84 is: " << one.ValueAt(84) << endl;
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }

    //remove key/value at specified key
    two.RemoveOne(3);
    //print out KeyValue object
    cout << two;

    return 0;
}