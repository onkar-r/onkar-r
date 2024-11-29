


evenOdd(vector<int> v)
{
    int evenIdx = 0, oddIdx = v.size() - 1;
    while (evenIdx < oddIdx) {
        if (v[evenIdx] % 2 == 0) {
           ++evenIdx;
        } else {
            swap(v[evenIdx], v[--oddIdx])
        }
    }
}

