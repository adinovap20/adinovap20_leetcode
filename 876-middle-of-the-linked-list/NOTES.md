Middle of the linked list can be calculated just by using the slow, fast pointer concept. Move the slow pointer by 1 units and fast pointer by 2 units.

The iteration stops when fast points to NULL or fast->next points to NULL. Note that slow will always point to middle of the linked list.

```
ListNode *slow, *fast; 
        slow = head; fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
```
