#include<iostream>
#include<vector>
using namespace std;

class Stack {

    public:
    int size;
    int top;
    int *arr;

    // constructor
    Stack(int size) {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    // behaviours
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        } 
        else {
            cout << "overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "underflow" << endl;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout << "Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top < 0) {
            return true;
        }
        else {
            return false;
        }
    }

};

// solution function

vector<int> solve(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n,-1);
    Stack st(n);
    for(int i = n-1; i >= 0; i--) {
        int num = nums[i];
        while(!st.isEmpty() && st.peek() <= num) {
            st.pop();
        }
        // either stack is empty or we found the element greater than num
        if(!st.isEmpty()) {
            ans[i] = st.peek();
        }
        st.push(num);
    }
    return ans;
}

int main() {

    vector<int> nums = {1,3,2,4};

    vector<int> ans = solve(nums);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " " ;
    }

    return 0;
}