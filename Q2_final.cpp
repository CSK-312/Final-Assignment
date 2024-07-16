class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int time=0;
        for(int i=0;i<courses.size();i++){
            if(time+courses[i][0]<=courses[i][1]){
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }else if(!pq.empty()&&pq.top()>courses[i][0]){
                time+=courses[i][0]-pq.top();
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        return pq.size();
    }
};
