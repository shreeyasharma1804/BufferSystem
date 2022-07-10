#include <iostream>
#include<array>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// tasks[0] -> enqueue time
// tasks[1] -> CPU burst time`

vector<int> shortest_job_first(vector<vector<int>> tasks){

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextTask;
        
        vector<array<int, 3>> sorted_tasks;
        
        for(int i=0; i<tasks.size(); i++){
            sorted_tasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        vector<int> result_sequence;
        
        sort(sorted_tasks.begin(), sorted_tasks.end());
        
        
        long long int currTime = 0;
        int taskIndex = 0;
        
        while(taskIndex < sorted_tasks.size() or !nextTask.empty()){
            
            if(nextTask.empty() and currTime < sorted_tasks[taskIndex][0]){
                currTime = sorted_tasks[taskIndex][0];
            }
            
            while(taskIndex < sorted_tasks.size() and sorted_tasks[taskIndex][0] <= currTime){
                nextTask.push({sorted_tasks[taskIndex][1], sorted_tasks[taskIndex][2]});
                taskIndex++;
            }
            
            pair<int, int> process = nextTask.top();
            nextTask.pop();
            currTime += process.first;
            result_sequence.push_back(process.second);
            
        }
        
        return result_sequence;

}
