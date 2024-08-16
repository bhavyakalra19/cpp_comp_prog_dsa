#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    public:
        double med;
        priority_queue<int> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        
        MedianFinder() {

        }
        
        void addNum(int num1) {
            double num = (double)num1;
            if(leftHeap.size() == rightHeap.size()){
                if(num > med){
                    rightHeap.push(num);
                    med = rightHeap.top();
                }else{
                    leftHeap.push(num);
                    med = leftHeap.top();
                }
            }else if(leftHeap.size() > rightHeap.size()){
                if(num > med){
                    rightHeap.push(num);
                }else{
                    rightHeap.push(leftHeap.top());
                    leftHeap.pop();
                    leftHeap.push(num);
                }
                med = (leftHeap.top() + rightHeap.top())/(double)2;
            }else{
                if(num < med){
                    leftHeap.push(num);
                }else{
                    leftHeap.push(rightHeap.top());
                    rightHeap.pop();
                    rightHeap.push(num);
                }
                med = (leftHeap.top() + rightHeap.top())/(double)2;
            }
        }
        
        double findMedian() {
            return med;
        }
};

int main(){
    MedianFinder m;
    m.addNum(-1);
    m.addNum(-2);
    cout << m.findMedian() << endl;
    m.addNum(-3);
    cout << m.findMedian() << endl;
    m.addNum(-4);
    cout << m.findMedian() << endl;
    m.addNum(-5);
    cout << m.findMedian() << endl;
    return 0;
}