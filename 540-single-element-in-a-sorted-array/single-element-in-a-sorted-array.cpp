class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int low = 0, high = a.size() - 1;

        // chking edge cases which might fail in  bs
        
         if (a.size() == 1)
            return a[0];
        if (a[0] != a[1])
            return a[0];
        else if (a[high] != a[high - 1])
            return a[high];
        while (low <= high) {
            int mid = (low + high) / 2;

            if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1])
                return a[mid];
            else if ((mid % 2 == 0 && a[mid] == a[mid - 1]) ||
                     (mid % 2 == 1 && a[mid] == a[mid + 1])) {
                high = mid - 1;
            } else if ((mid % 2 == 0 && a[mid] == a[mid + 1]) ||
                       (mid % 2 == 1 && a[mid] == a[mid - 1]))
                low = mid + 1;
        }

        return -1;
    }
};