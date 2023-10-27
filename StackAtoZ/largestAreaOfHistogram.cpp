#include<iostream>
#include<vector>
using namespace std;

class Stack{

    public:
    int top;
    int size;
    int *arr;

    // constructor
    Stack(int size) {
        this->top = -1;
        this->size = size;
        arr = new int[size];
    }

    // behaviours
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "underflow " << endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout << "empty" << endl;
            return -1;
        }
    }

    bool empty() {
        if(top < 0) {
            return true;
        }
        else {
            return false;
        }
    }

};

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    Stack st(n);
    vector<int> ans(n,-1);
    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        while(!st.empty() && arr[st.peek()] >= curr) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.peek();
        }
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr, int n) {
    Stack st(n);
    vector<int> ans(n,-1);

    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        while(!st.empty() && arr[st.peek()] >= curr) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.peek();
        }
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next;
    next = nextSmallerElement(heights,n);

    vector<int> prev;
    prev = prevSmallerElement(heights,n);

    int area = INT32_MIN;
        
    for(int i = 0; i < n; i++) {
        int l = heights[i];
        if(next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;

}

int main() {

    vector<int> heights = {2,1,5,6,2,3};

    cout << largestRectangleArea(heights) << endl;

    return 0;
}