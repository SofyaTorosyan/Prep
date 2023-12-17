#include "vector.h"
#include "Tests.h"

using namespace std;

int main()
{
    testDefaultConstr();
    testValueConstr();
    testAccessOperator();
    testCopyConstructor();

    vector<int> vec(4, 5);
    vector<int> vec1 = vec;
    vec1.push_back(2);
    vec1.push_back(2);
    vec1.push_back(2);
    std::cout << vec1[2] << std::endl;
    vec1.print();
    vector<int>::Iterator it = vec1.begin();
    vec1[1] = 100;
    vec1.print();
    std::cout << "*it: " << *it  << std::endl;
    std::cout << "*it: " << *(++it)  << std::endl;
    it = ++vec1.begin();
    std::cout << "*(--it): " << *(--it)  << std::endl;
    it = vec1.begin() + 2;
    std::cout << "*it: " << *it  << std::endl;
    
    vector<int> vec2 = {1,2,3};
    std::cout << *vec2.begin();
    std::cout << "empty ? " << vec2.empty() << std::endl;
    vec1 = vec1;
    vector<int> vec2 = {1,2,3};
    vec.print();
    vec2.print();
    vec = vec2;
    vec.print();
    vec2.print();
    vec2.resize(2);
    vec2.print();
    vec2.clear();
    std::cout << vec2.size() << " " << vec2.capacity() << std::endl;
    vec2.insert(vec2.begin() + 10, 10);
    return 0;
}
