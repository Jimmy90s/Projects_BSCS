# hash table class creation
# Source: WGU code repository W-2_ChainingHashTable_zyBooks_Key-Value_CSV_Greedy.py
class hash_table:
    def __init__(self, cap=40):
        # initialize table with an empty list
        self.list = []
        for j in range(cap):
            self.list.append([])

    # put new items into hast table
    def add_item(self, k, v):
        # list for v to go.
        temp = hash(k) % len(self.list)
        temp_list = self.list[temp]

        # update if already exist
        for kv in temp_list:
            if not kv[0] != k:
                kv[1] = v
                return True

        # add_item v at the end if not already in
        key_value = [k, v]
        temp_list.append(key_value)
        return True

    # lookup_id
    def lookup_id(self, k):
        temp = hash(k) % len(self.list)
        temp_list = self.list[temp]
        for p in temp_list:
            if not k != p[0]:
                return p[1]
        return None  # no pair[0] matches k 0

    # remove_item from hash table
    def remove_item(self, k):
        s = hash(k) % len(self.list)
        des = self.list[s]

        # remove_item the v if k is found
        if k in des:
            des.remove(k)
