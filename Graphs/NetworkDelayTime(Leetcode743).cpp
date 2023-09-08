/*
You are given a network of n nodes, labeled from 1 to n.
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, 
and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.
*/


//Use Dijkstra algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(n==1) return 0;

        //Distance of each node is initialized to 1e9
        vector<int> distance(n+1,1e9);
        //Distance from source is set as 0
        distance[k]=0;
        //Dist[0]=0, considering numbering of node starts from 1
        distance[0]=0;

        //Initialize a vector of vector of pairs 
        //Pair contains the destination edge and weight
        vector<vector<pair<int,int>>> graph(n+1);

        //Mark directions and weight
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v= times[i][1];
            int edgeweight= times[i][2];

            graph[u].push_back(make_pair(edgeweight,v));
        }

        //Priority queue initialized
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        //Push source node into the queue 
        pq.push({0,k});

        while(!pq.empty()){
            auto cur= pq.top();
            pq.pop();
            
            //distance to the source
            int distancetosource= cur.first;
            //source node 
            int source= cur.second;

            for(int i=0;i<graph[source].size();i++){
                int dest= graph[source][i].second;
                int edgeweight= graph[source][i].first;
                //Update the distances 
                if(distance[dest] > distancetosource + edgeweight){
                    distance[dest] = distancetosource + edgeweight;
                    pq.push(make_pair(distance[dest],dest));
                }
            }
        }

        for(int i=0;i<distance.size();i++){
            //If any of the node remains unvisited return -1
            if(distance[i]==1e9) return -1;
        }

        return *max_element(distance.begin(),distance.end());
    }
};


