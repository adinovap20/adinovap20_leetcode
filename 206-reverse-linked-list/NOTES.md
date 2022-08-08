Reversing a linked list just requires three pointers. Reversing a linked list is equivalent to reversing the connections in between the two points.

Consider three pointers. prev, curr and next.

```
While curr!=NULL:
	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
```

Thus, the new linked list will eventually be in the prev node;
