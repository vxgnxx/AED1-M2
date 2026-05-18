/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int arr[10000];
    int n = 0;


    while (head) {
        arr[n] = head->val;
        n++;
        head = head->next;
    }


    int* ans = calloc(n, sizeof(int));


    for (int i = 0; i < n; i++) {


        for (int j = i + 1; j < n; j++) {


            if (arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }


    *returnSize = n;
    return ans;
}