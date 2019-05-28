#include<iostream>
#include<vector>
#include<climits>
#include<list>

using namespace std;

class Edge{
    public:
    int n;
    int w;

    Edge(int n, int w){
        this->n = n;
        this->w = w;
    }
};

class THelper{
    public:
    int v;
    string path;
    int d;

    THelper(int v, string path, int d){
        this->v = v;
        this->path = path;
        this->d = d;
    }
};

class THelper2{
    public:
    int i;
    int j;
    int t;

    THelper2(int i, int j, int t){
        this->i = i;
        this->j = j;
        this->t = t;
    }
};

bool bfs(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited){

    list<THelper> queue;
    queue.push_back(THelper(src, "" + to_string(src), 0));
    while(queue.size()>0){
        THelper th = queue.front();
        queue.pop_front();

        cout << th.v << "via" << th.path << "@" << th.d << endl;
        if(visited[th.v] == false){
            visited[th.v] = true;
        }
        else
        continue;

        if(th.v == dest){
            return true;
        }

        for(int i=0; i<graph[th.v].size(); i++){
            if(visited[graph[th.v][i].n] == false){
                Edge th1 = graph[th.v][i];
                queue.push_back(THelper(th1.n, th.path + to_string(th1.n), th.d + th1.w));
            }
        }
    }
    return false;

}

void addEdge(vector<vector<Edge>>& graph, int v1, int v2, int wt){
    graph[v1].push_back(Edge(v2,wt));
    graph[v2].push_back(Edge(v1,wt));
}

void display(vector<vector<Edge>>& graph){
    cout << "------------------------------" << endl;
    for(int i=0; i<graph.size(); i++){
        cout << i << "--> ";
      //  vector<Edge> ed = graph[i];
        for(int j=0; j<graph[i].size(); j++){
            Edge ed = graph[i][j];
            cout << "[ " << ed.n << "@" << ed.w << "]";

        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}

bool hasPath(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited){
    if(src == dest){
        return true;
    }
    
    visited[src] = true;
    for(int i=0; i<graph[src].size(); i++){
        Edge ed = graph[src][i];
        if(visited[ed.n] == false){
            if(hasPath(graph,ed.n, dest, visited) == true){
                return true;
            }
        }
    }

    return false;

}

void printAllPaths(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited, string psf){
    if(src == dest){
        cout << psf << dest << endl;
        return;
    }
    visited[src] = true;
    for(int i=0; i<graph[src].size(); i++){
        Edge ed = graph[src][i];
        if(visited[ed.n] == false){
            printAllPaths(graph,ed.n, dest, visited, psf + to_string(src));
            
                
            
        }
    }
    visited[src] = false;

   
}

void printAllPathsInc(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited, string psf){
    if(src == dest){
        cout << psf << endl;
        return;
    }
    
    for(int i=0; i<graph[src].size(); i++){
        Edge ed = graph[src][i];
        if(visited[ed.n] == false){
            visited[ed.n] == true;
            printAllPathsInc(graph,ed.n, dest, visited, psf + to_string(ed.n));
            visited[ed.n] == false;
            
        }
    }
       
}

int small = INT_MAX;
string smallpath = "";
void printSmallestPaths(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited, string psf, int sum){
    if(src == dest){
        if(sum < small){
            small = sum;
            smallpath = psf + to_string(dest) + "@" + to_string(small);
        }
        return;
    }
    visited[src] = true;
    for(int i=0; i<graph[src].size(); i++){
        Edge ed = graph[src][i];
        if(visited[ed.n] == false){
            printSmallestPaths(graph,ed.n, dest, visited, psf + to_string(src), sum+ed.w);
            
                
            
        }
    }
    visited[src] = false;

   
}

int largest = INT_MIN;
string largestpath = "";
void printLargestPaths(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited, string psf, int sum){
    if(src == dest){
        if(sum > largest){
            largest = sum;
            largestpath = psf + to_string(dest) + "@" + to_string(largest);
        }
        return;
    }
    visited[src] = true;
    for(int i=0; i<graph[src].size(); i++){
        Edge ed = graph[src][i];
        if(visited[ed.n] == false){
            printLargestPaths(graph,ed.n, dest, visited, psf + to_string(src), sum+ed.w);
            
                
            
        }
    }
    visited[src] = false;

   
}

void printCeilPathsInc(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited, string psf){
    if(src == dest){
        cout << psf << endl;
        return;
    }
    
    for(int i=0; i<graph[src].size(); i++){
        Edge ed = graph[src][i];
        if(visited[ed.n] == false){
            visited[ed.n] == true;
            printAllPathsInc(graph,ed.n, dest, visited, psf + to_string(ed.n));
            visited[ed.n] == false;
            
        }
    }
       
}

bool isValid(vector<vector<int>>& mat, int i, int j){
    if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size()){
        return false;
    }

    else if(mat[i][j] == -1){
        return false;
    }

    else if(mat[i][j] >= 0){
        return false;
    }

    else{
        return true;
    }
}

void firebreak(vector<vector<int>>& mat){
    // for(int i=0; i<mat.size(); i++){
    //     for(int j=0; j<mat[i].size(); j++){
    //         if(mat[i][j] == 2){
    //             list<THelper2> queue;
    //             queue.push_back(THelper2(i,j,0));
    //             while(queue.size()>0){
    //                 THelper2 th = queue.front();
    //                 queue.pop_front();

    //                 if(visited[th.i][th.j] = false)
    //                 visited[th.i][th.j] = true;
    //                 else
    //                 continue;

    //                 if(th.d == 3){
    //                     return
    //                 }

    //                 int up = (i-1 >= 0) ? mat[i-1][j] : 3;
    //                 int down = (i+1 < mat.size()) ? mat[i+1][j] : 3;
    //                 int left = (j-1 >= 0) ? mat[i][j-1] : 3;
    //                 int right = (j+1 < mat[0].size()) ? mat[i][j+1] : 3;
    //                 if(up != 1 && up != 3){
    //                     if(visited[i-1][j] == false)
    //                     queue.push_back(THelper(i-1,j,th.d+1));
    //                     mat[i-1][j] = 2;
    //                 }
    //             }
    //         }
    //     }
    // }
}

void firebox(vector<vector<int>>& mat){

    list<THelper2> queue;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j] == 0){
                queue.push_back(THelper2(i,j,0));
            }
        }
    }

    while(queue.size()>0){
        THelper2 rem = queue.front();
        queue.pop_front();

        if(mat[rem.i][rem.j] >0){
           continue;
        }
        
         mat[rem.i][rem.j] = rem.t;
        

        cout << rem.i << rem.j << "burnt at " << rem.t << endl;

        if(isValid(mat, rem.i-1, rem.j))
            queue.push_back(THelper2(rem.i-1, rem.j, rem.t + 1));
        if(isValid(mat, rem.i+1, rem.j))
            queue.push_back(THelper2(rem.i+1, rem.j, rem.t + 1));
        if(isValid(mat, rem.i, rem.j-1))
            queue.push_back(THelper2(rem.i, rem.j-1, rem.t + 1));
        if(isValid(mat, rem.i, rem.j+1))
            queue.push_back(THelper2(rem.i, rem.j+1, rem.t + 1));            
    }
}

string getconnectedcomponent(vector<vector<Edge>>& graph, int src, vector<bool>& visited){
    string comp;

    list<int> queue;
    queue.push_back(src);
    while(queue.size() > 0){
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true)
            continue;
        else
            visited[rem] = true;

        comp+= to_string(rem);
        for(int n=0; n<graph[rem].size(); n++){
            Edge ne = graph[rem][n];
            if(visited[ne.n] == false){
                queue.push_back(ne.n);
            }
        }
    }

    return comp;


}

vector<string> getconnectedcomponents(vector<vector<Edge>>& graph){
    vector<string> res;
    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == false){
            string res1 = getconnectedcomponent(graph, i, visited);
            res.push_back(res1);

        }
    }

    return res;
    
}

class IHelper{
    int i;
    int j;

    IHelper(int i, int j){
        this->i = i;
        this->j = j;
    }

};

//bool isValidIsland()

// int getconnectedisland(vector<vector<int>>& mat, int i, int j){
//     int res;
//     list<IHelper> queue;
//     queue.push_back(IHelper(i,j));

//     while(queue.size() > 0){
//         IHelper ih = queue.front();
//         queue.pop_front();

//         if(mat[ih.i][ih.j] == 1)
//             continue;
//         else
//             mat[ih.i][ih.j] = 1;

//         if(isValid(mat, rem.i-1, rem.j))
//             queue.push_back(THelper2(rem.i-1, rem.j, rem.t + 1));
//         if(isValid(mat, rem.i+1, rem.j))
//             queue.push_back(THelper2(rem.i+1, rem.j, rem.t + 1));
//         if(isValid(mat, rem.i, rem.j-1))
//             queue.push_back(THelper2(rem.i, rem.j-1, rem.t + 1));
//         if(isValid(mat, rem.i, rem.j+1))
//             queue.push_back(THelper2(rem.i, rem.j+1, rem.t + 1));     


        
//     }

//     return res + 1;


// }

// int getconnectedislands(vector<vector<int>>& mat){
//     int res;
//     vector<bool> visited(mat.size(), false);
//     for(int i=0; i<mat.size(); i++){
//         for(int j=0; j<mat[0].size(); j++){
//             if(mat[i][j] == 0){
//                 int myres = getconnectedisland(mat, i, j);
//                 res+= myres;
//             }
//         }
//     }

//     return res;
    
// }

bool isCycle(vector<vector<Edge>>& graph, int src, vector<bool>& visited){

    list<int> queue;
    queue.push_back(src);

    while(queue.size() > 0){
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true){
            return true;
        }

        else
            visited[rem] = true;

        for(int i=0; i<graph[rem].size(); i++){
            int r = graph[rem][i].n;
            if(visited[r] == false){
                queue.push_back(r);
            }
        }
    
    }

    return false;

}

bool isCyclicGraph(vector<vector<Edge>>& graph, int src){

    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == false){
            bool myres = isCycle(graph, i, visited);
            if(myres == true){
                return true;
            }
        }
    }

    return false;
}

int getAstronotsCommponents(vector<vector<Edge>>& graph, int src, vector<bool>& visited){
    list<int> queue;
    queue.push_back(src);
    int count = 0;

    while(queue.size() > 0){
        int rem = queue.front();
        queue.pop_front();
        if(graph[rem].size()!=0)
        count++;

        if(visited[rem] == true){
            return count;
        }

        else
            visited[rem] = true;

        for(int i=0; i<graph[rem].size(); i++){
            Edge ed = graph[rem][i];
            if(visited[ed.n] == false){
               // count++;
                queue.push_back(ed.n);
            }
        }

    }
    return count;
}

vector<int> getAstronots(vector<vector<Edge>>& graph){
    vector<int> res;
    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == false){
            int count = getAstronotsCommponents(graph, i, visited);
            if(count!=0)
            res.push_back(count);

        }
    }
    return res;
}

int astronots(vector<int> arr1, vector<int> arr2, int n){
    int res1 = 0;
    vector<vector<Edge>> graph(n);
    for(int i=0; i<arr1.size(); i++){
        addEdge(graph,arr1[i],arr2[i],0);
    }

    vector<int> res = getAstronots(graph);

    for(int i=0; i<res.size()-1; i++){
        for(int j = i+1; j<res.size(); j++){
            res1+= res[i]*res[j];
        }
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return res1;
}

class BHelper{
    public:
    int v;
    int level;

    BHelper(int v,int level){
        this->v = v;
        this->level = level;
    }
};

bool biPartite(vector<vector<Edge>>& graph, int src, vector<int> visited){
    list<BHelper> queue;
    queue.push_back(BHelper(src, 0));

    while(queue.size() > 0){
        BHelper rem = queue.front();
        queue.pop_front();

        if(visited[rem.v] != -1){
        if((visited[rem.v]%2) == (rem.level%2)){
            continue;
        }
        else
            return false;
        }
        else
            visited[rem.v] = rem.level;

        for(int i=0; i<graph[rem.v].size(); i++){
            Edge ed = graph[rem.v][i];
            if(visited[ed.n] == -1){
                queue.push_back(BHelper(ed.n, rem.level+1));
            }
        }


    }
    return true;
}





int main(int argc, char** argv){

    vector<vector<Edge>> graph(7);
    // addEdge(graph,0,1,10);
    // addEdge(graph,1,2,10);
    // addEdge(graph,2,3,10);
    // addEdge(graph,0,3,40);
    // addEdge(graph,3,4,2);
    addEdge(graph,4,5,3);
    addEdge(graph,5,6,3);
    addEdge(graph,4,6,8);
    // display(graph);
    vector<bool> visited(7,false);
     // cout << hasPath(graph, 0,6,visited) << endl;
    string psf = "";
    //  printAllPaths(graph, 0,6,visited,psf);
    // visited[0] = true;
    //printAllPathsInc(graph,0,6,visited,psf + "0");
    //   printSmallestPaths(graph, 0,6,visited,psf,0);
    //   cout << smallpath << endl;
    //   printLargestPaths(graph, 0,6,visited,psf,0);
    //   cout << largestpath << endl;
 //   bfs(graph,0,6,visited);
    vector<vector<int>> mat{
        {-2,-2,0,-2,-2,-2},
        {-2,-1,-1,-2,-1,-1},
        {-2,-2,-1,-2,-2,-2},
        {-2,-2,-2,-2,-1,-2},
        {-2,-1,-1,0,-2,-2}

    };
   // firebox(mat);
    // vector<string> res;
    // res = getconnectedcomponents(graph);
    // for(int i=0; i<res.size(); i++){
    //     cout << res[i] << endl;
    // }

    //cout << isCyclicGraph(graph, 0) << endl;
    vector<int> arr1{1,6,8,2,9,10,0};
    vector<int> arr2{2,9,3,5,5,3,11};
  //  cout << astronots(arr1, arr2, 12) << endl;

    vector<vector<Edge>> graph1(4);
    addEdge(graph1,0,1,5);
    addEdge(graph1,1,2,5);
    addEdge(graph1,2,3,5);
    addEdge(graph1,0,3,5);

    vector<vector<Edge>> graph2(6);
    addEdge(graph2,0,1,5);
    addEdge(graph2,0,3,5);
    addEdge(graph2,1,2,5);
    addEdge(graph2,2,3,5);
    addEdge(graph2,2,5,5);
    addEdge(graph2,3,4,5);
    addEdge(graph2,4,5,5);
    addEdge(graph2,2,5,5);

    vector<int> visited1(3,-1);
    cout << biPartite(graph, 4, visited1) << endl;

}