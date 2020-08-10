#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "support.h"

using std::string;
using std::vector;
using std::stringstream;

int stringToInteger(string input)
{
    return stoi(input);
}

double stringToDouble(string input)
{
    return stod(input);
}

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(const string &input) {
    vector<int> output;
    string copied(input);
    trimLeftTrailingSpaces(copied);
    trimRightTrailingSpaces(copied);
    copied = copied.substr(1, copied.length() - 2);
    stringstream ss;
    ss.str(copied);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

void printList(ListNode* l)
{
    while (l)
    {
        std::cout << l-> val;
        if (l->next)
            std::cout << "->";
        l = l->next;
    }
}

ListNode* stringToListNode(const string &input)
{
    vector<int> list = stringToIntegerVector(input);

    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }

    ptr = dummyRoot->next;
    delete dummyRoot;

    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += std::to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

void freeList(ListNode* root)
{
    ListNode* tmp;
    while (root)
    {
        tmp = root;
        root = root->next;
        delete tmp;
    }
}

bool compare_fn(std::vector<int> &v1, std::vector<int> &v2)
{
  for (unsigned i = 0; i < v1.size() && i < v2.size(); i++)
  {
    if (v1[i] < v2[i])
      return true;
    if (v1[i] > v2[i])
      return false;
  }
  return v1.size() < v2.size();
}
