#ifndef _STACK_H
#define _STACK_H

#include <stack>

template<class T>
class Stack{
public:
	void Pop()        { delete Top();
		                  _stack.pop(); }

	void Push(T t)    { _stack.push(t); }

	void Replace(T t) { Pop();
	                    Push(t); }

	T    Top()        { return _stack.top(); }
	void Clear()      { for( unsigned int x = 0; x < _stack.size(); ++x){ Pop(); }}
private:
	std::stack<T> _stack;
};

#endif