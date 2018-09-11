/**
 * Definition for singly-linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1= l1;
        for(;l1->next !=NULL && l2->next!=NULL; l1=l1->next,l2=l2->next)
        {
            l1->val = l1->val + l2->val;
            if(l1->val >= 10)
            {
                l1->next->val++;
                l1->val = l1->val-10;
            }
        }

        int tmp_end = l1->val + l2->val;
        ListNode* tmp_node = l1;

        if(l1->next==NULL && l2->next !=NULL)
        {
            l1->next = l2->next;
        }

        tmp_node->val = tmp_end;

        for(; tmp_node->next!=NULL && tmp_node->val>=10; tmp_node= tmp_node->next )
        {
            tmp_node->next->val++;
            tmp_node->val = l1->val-10;
        }

        if(tmp_node->val>=10){
            tmp_node->next=(ListNode*)malloc(sizeof(ListNode));
            tmp_node->next->val=0;
            tmp_node->next->val++;
            tmp_node->val = l1->val-10;
        }
        return head1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
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
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
