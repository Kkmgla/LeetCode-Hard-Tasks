#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*ЭТО АБСОЛЮТНО ПРАВИЛЬНОЕ РЕШЕНИЕ, НО УВЫ У НАС В ТЕСТ КЕЙСЕ LISTS.SIZE() == 500, 
* КАК ИТОГ TIME LIMIT EXCEEDED
* 
* 
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        for (int i = 0; i < lists.size() - 1; i++)
        {
            lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);

            // Выводим значения узлов
            ListNode* hh = lists[i + 1];
            while (hh != nullptr) {
                std::cout << hh->val << " ";
                hh = hh->next;
            }
            cout << endl;
        }
        // 0 1 2 3 4 5
        // 1 2 3 4 5
        // 2 3 4 5
        // 3 4 5
        // 4 5
        // 5
        return lists[lists.size() - 1];
    }
};
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    struct CompareListNode {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        /*Создается приоритетная очередь (priority_queue) типа указателей на ListNode,
        используя собственный компаратор CompareListNode.
        Это означает, что priority_queue будет автоматически сортировать элементы в порядке убывания,
        основываясь на значении val каждого узла.*/
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq;
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }

        /*Создается фиктивный узел dummy, который служит началом объединенного списка.
        Переменная tail указывает на текущий конец объединенного списка*/
        ListNode dummy(0);
        ListNode* tail = &dummy;

        /*Мы извлекаем минимальный узел из приоритетной очереди,
        добавляем его в конец объединенного списка через переменную tail, а затем проверяем,
        есть ли следующий узел в извлеченном списке. Если есть, мы добавляем его в приоритетную очередь.
        Таким образом, при каждой итерации цикла мы извлекаем наименьший узел из всех текущих списков
        и добавляем его в объединенный список.*/
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();
            tail->next = minNode;
            tail = tail->next;
            if (minNode->next != nullptr) pq.push(minNode->next);
        }

        return dummy.next;
    }
};


int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(6);
    ListNode* node4 = new ListNode(9);
    ListNode* node5 = new ListNode(10);

    ListNode* node6 = new ListNode(3);
    ListNode* node7 = new ListNode(5);
    ListNode* node8 = new ListNode(7);

    ListNode* node9 = new ListNode(1);
    ListNode* node10 = new ListNode(8);
    ListNode* node11 = new ListNode(9);

    ListNode* node12 = new ListNode(4);
    ListNode* node13 = new ListNode(7);
    ListNode* node14 = new ListNode(8);

    ListNode* node15 = new ListNode(2);
    ListNode* node16 = new ListNode(3);
    ListNode* node17 = new ListNode(4);

    ListNode* node18 = new ListNode(3);
    ListNode* node19 = new ListNode(7);
    ListNode* node20 = new ListNode(10);


    // Устанавливаем связи между узлами
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node6->next = node7;
    node7->next = node8;

    node9->next = node10;
    node10->next = node11;

    node12->next = node13;
    node13->next = node14;

    node15->next = node16;
    node16->next = node17;

    node18->next = node19;
    node19->next = node20;
    vector<ListNode*> vec{ node1, node6, node9, node12, node15, node18 };
    Solution s;
    ListNode* hh = s.mergeKLists(vec);

    // Выводим значения узлов
    while (hh != nullptr) {
        std::cout << hh->val << " ";
        hh = hh->next;
    }
}