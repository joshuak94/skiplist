#include <vector>
#include <limits>

#include "SkipList.h"

struct Node
{
  int64_t value{};
  std::vector<Node &> pointers;

  void changePointer(Node & node, uint64_t level)
  {
    if (level <= pointers.size() - 1)
    {
      pointers.at(level) = node;
    }
    else
    {
      while (pointers.size() - 1 != level)
      {
        pointers.push_back(node);
      }
    }
  }

  Node & getNext(uint64_t level)
  {
    return pointers.at(level);
  }

  int64_t getValue()
  {
    return value;
  }
};

Node nodeH{};
Node nodeT{};
uint64_t maxLevel{0};

Node & makeNode(int64_t value, std::vector<Node &> pointers)
{
  Node node = {value, pointers};
  return & node;
}

SkipList::SkipList(std::vector<int64_t> const & init)
{
  nodeT = makeNode(std::numeric_limits<int64_t>::infinity, std::vector<int64_t>);
  nodeH = makeNode(NULL, std::vector<int64_t>{& nodeT});
  // for each element in init, create temporary node instance,
  // randomly get its level height, create pointers for this node at each level,
  // update pointers for previous elements at each level.
  // we can't add a new level if we are maxLevel + 1
  for (int64_t element : init)
  {
    uint64_t levels = std::rand() % maxLevel + 1;
    Node & tempNode = makeNode(element, std::vector<Node &> pointers(levels));
    for (i = 0; i <= levels; i++)
    {

    }
  }
}

Node & search(int64_t value)
{
  Node temp = nodeH;
  for (int i = maxLevel; i > 0; i--)
  {
    while (temp.getValue() <= value)
    {
      temp = temp.getNext(i - 1);
    }
  }
  return temp;
}
