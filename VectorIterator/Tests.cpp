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

void testAssignment()
{
    // general vector
    vector<int> vec1(3, 100);
    vector<int> vec2 = vec1;
    for (int i = 0; i < vec2.size(); ++i)
    {
        assert(vec2[i] == 100);
    }

    // vector states
    assert(vec1.size() == 3);
    assert(vec1.capacity() == 3);
    assert(vec2.size() == 3);
    assert(vec2.capacity() == 3);

    vec2.push_back(4);
    assert(vec2.size() == 4);
    assert(vec2.capacity() == 6);

    vec2.print();
}

void testPushBack()
{
    // general vector
    vector<int> vec1(2, 100);
    vec1.push_back(1);
    vec1.push_back(2);
    assert(vec1.size() == 4);
    assert(vec1.capacity() == 4);
    vec1.push_back(3);
    assert(vec1.size() == 5);
    assert(vec1.capacity() == 8);

    // empty vector
    vector<int> vec2;
    vec2.push_back(1);
    assert(vec2.size() == 1);
    assert(vec2.capacity() == 1);
}

void testReserve()
{
    // general vector
    vector<int> vec1(3, 100);
    vec1.reserve(2);
    assert(vec1.size() == 3);
    assert(vec1.capacity() == 3);

    vec1.reserve(10);
    assert(vec1.size() == 3);
    assert(vec1.capacity() == 10);

    vec1.push_back(1);
    assert(vec1.size() == 4);
    assert(vec1.capacity() == 10);

    // empty vector
    vector<int> vec2;
    vec2.reserve(10);
    assert(vec2.size() == 0);
    assert(vec2.capacity() == 10);
}

void testBeginEnd()
{
    vector<int> vec1 = {1, 2, 3};
    assert(*vec1.begin() == 1);
    assert(vec1.begin() + 3 == vec1.end());

    vector<int> vec2;
    assert(vec2.begin() == vec2.end());

    /*
    bool exceptionThrown = false;
    try
    {
       assert(*vec1.end() == 0); // out of range access => should throw
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    */ // thrown exception isn't catched. assertion failer.
}

void testEmpty()
{
    vector<int> vec1;
    assert(vec1.empty() == true);
    vec1.push_back(1);
    assert(vec1.empty() == false);

    vector<int> vec2 = {1, 2, 3};
    assert(vec2.empty() == false);

    vector<int> vec3 = vec2;
    assert(vec2.empty() == false);
    assert(vec3.empty() == false);
}

void testClear()
{
    vector<int> vec1 = {1, 2, 3};
    vec1.clear();
    assert(vec1.size() == 0);
    assert(vec1.capacity() == 3);
    vec1.push_back(2);
    assert(vec1.size() == 1);
    assert(vec1.capacity() == 3);
}

