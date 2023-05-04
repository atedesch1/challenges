from collections import deque


def remove_dups(llist: deque):
    idx = 0

    while (len(llist) > idx):
        element = llist[idx]
        count = llist.count(element)
        for i in range(count - 1):
            llist.remove(element)
        idx += 1


llist = deque([1, 2, 2, 3, 2, 4, 5, 2, 3])
print(llist)
remove_dups(llist)
print(llist)
