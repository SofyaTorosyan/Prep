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

void testCopyConstructor()
{
    // general vector
    vector<int> vec1(4, 100);
    int size = vec1.size();
    int capacity = vec1.capacity();
    vector<int> vecCopy1(vec1);
    for (int i = 0; i < vecCopy1.size(); ++i)
    {
        assert(vecCopy1[i] == 100);
    }
    assert(vec1.size() == size);
    assert(vec1.capacity() == capacity);
    assert(vecCopy1.size() == size);
    assert(vecCopy1.capacity() == capacity);

    // empty vector
    vector<int> vec2;
    vector<int> vecCopy2(vec2);
    assert(vecCopy2.size() == 0);
    assert(vecCopy2.capacity() == 0);
}

void testInitializerListConstr()
{
    // general vector
    vector<int> vec1 = {1, 2, 3};
    assert(vec1.size() == 3);
    assert(vec1.capacity() == 3);

    // empty vector
    vector<int> vec2 = {};
    assert(vec2.size() == 0);
    assert(vec2.capacity() == 0);
}
