#include "linkedlist.h"

LinkedList::~LinkedList()
{
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext /* prepare the next in the row */) {
    auto elem = tmp; /* save the element to be deleted */
    delete elem;
  }
}

bool LinkedList::insert_tail(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }

  LinkedList::m_tail->pNext = node;
  LinkedList::m_tail = node;

  // insert your code here....
  return ret;
}

bool LinkedList::insert_head(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }

  node->pNext = LinkedList::m_head;
  LinkedList::m_head = node;

  // insert your code here....
  return ret;
}

bool LinkedList::insert_after(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }

  node->pNext = loc->pNext;
  loc->pNext = node;

  // insert your code here ....
  return ret;
}

bool LinkedList::insert_before(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }
  LinkedListNode *locnode = LinkedList::m_head;

  while(locnode->pNext != loc){

  }

  node->pNext = loc;
  // Insert your code here....
  return ret;
}

bool LinkedList::remove(LinkedListNode *node)
{
  bool ret = false;
irgendwass->pNext = node->pNext;
  node->pNext = nullptr;
  // insert your code here ...
  return ret;
}

size_t LinkedList::size()
{
  size_t count = 0;
  /* using a lambda to count objects in the list*/
  traverse([&count](LinkedListNode *node) { count++; });
  return count;
}


void LinkedList::traverse(std::function<void(const std::string &)> func)
{
  traverse([&](LinkedListNode *node) { func(node->m_name); });
}

void LinkedList::traverse(std::function<void(LinkedListNode *node)> func)
{
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext) {
    func(tmp);
  }
}