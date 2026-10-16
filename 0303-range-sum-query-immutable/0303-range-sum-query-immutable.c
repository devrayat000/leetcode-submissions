

typedef struct {
    int* sums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* arr = malloc(sizeof(NumArray));
    if (arr == NULL) {
        return NULL;
    }

    arr->sums = malloc(sizeof(int) * (numsSize + 1));
    if (arr->sums == NULL) {
        return NULL;
    }
    arr->sums[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        arr->sums[i + 1] = arr->sums[i] + nums[i];
    }

    return arr;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->sums[right + 1] - obj->sums[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->sums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/