#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

static void testSubjectExample() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "copied stack size: " << s.size() << std::endl;
}

static void testAgainstList() {
    MutantStack<int> mstack;
    std::list<int>   list;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::cout << "mutant stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "list:" << std::endl;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

static void testReverseAndConstIterators() {
    MutantStack<int> values;

    values.push(4);
    values.push(5);
    values.push(6);

    const MutantStack<int>& constValues = values;

    std::cout << "const forward:" << std::endl;
    for (MutantStack<int>::const_iterator it = constValues.begin(); it != constValues.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "reverse:" << std::endl;
    for (MutantStack<int>::reverse_iterator it = values.rbegin(); it != values.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    testSubjectExample();
    testAgainstList();
    testReverseAndConstIterators();
    return 0;
}
