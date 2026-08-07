// Define the macros
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int area = 0;
    int l = 0, r = heightSize - 1;
    while (l < r) {
        area = max(min(height[l], height[r]) * (r - l), area);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return area;
}