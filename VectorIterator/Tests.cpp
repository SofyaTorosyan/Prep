#include "Tests.h"
#include <cassert>

void testDefaultConstr()
{
    vector<int> vec;
    assert(vec.size() == 0);
    assert(vec.capacity() == 0);  
}

void testValueConstr()
{
    const int size = 10;
    const int val = 2;
    vector<int> vec(10, 2);
    assert(vec.size() == size);
    assert(vec.capacity() == size); 
    for (int i = 0; i < vec.size(); ++i)
    {
        assert(vec[i] == val);
    }
}

void testAccessOperator()
{
    // general vector
    vector<int> vec1(3, 2);
    assert(vec1[2] == 2);

    // empty vector
    vector<int> vec2;
    bool exceptionThrown = false;

    try
    {
       assert(vec2[0] == 1); // empty vector => should throw
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
}

// void testCopyConstructor()
// {
//     int size = 3;
//     int val = 2;
//     vector<int> vec(size, val);
//     vector<int> vecCopy(vec);
//     for (int i = 0; i < vecCopy.size(); ++i)
//     {
//         assert(vecCopy[i] == val);
//     }

//     vector<int> vec1;
//     vector<int> vecCopy1(vec1);
//     assert(vecCopy1.size() == 0);
//     assert(vecCopy1.capacity() == 0);
// }
