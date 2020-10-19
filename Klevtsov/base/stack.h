#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  bool empty() const inline
  {
	  return top == -1;
  }
  bool full() const inline
  {
	  return top == size - 1;
  }
  void push(const T& value)
  {
	  if (this->full()) throw std::exception("Stack is full");
	  pMem[++top] = value;
  }
  T pop()
  {
	  if (this->empty()) throw std::exception("Stack is empty");
	  return pMem[top--];
  }
};

#endif
