class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(tickets[i] != 0){
                if(k == i && tickets[i] == 0){
                    return 0;
                }
                if(tickets[i] > 0){
                    q.push(i);
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            tickets[idx] -= 1;
            time++;
            if(tickets[idx] != 0){
                q.push(idx);
            }else if(k == idx){
                return time;
            }
        }
        return time;       
    }
};