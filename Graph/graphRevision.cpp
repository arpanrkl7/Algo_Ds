#include<iostream>
#include<vector>
#include<climits>
#include<queue>
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

void addEdge(vector<vector<Edge>>& graph, int v1, int v2, int wt){
    graph[v1].push_back(Edge(v2,wt));
    graph[v2].push_back(Edge(v1,wt));
}

void display(vector<vector<Edge>>& graph){
    for(int i=0; i<graph.size(); i++){
        cout << i << "-> ";
        for(int j=0; j<graph[i].size(); j++){
            Edge ed = graph[i][j];
            cout << "[" << ed.n << "@" << ed.w << "] ";
        }
        cout << endl;
    }
}

bool hasPath(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited){
    if(src == dest){
        return true;
    }
    visited[src] = true;
    for(int i=0; i<graph[src].size(); i++){
        if(visited[graph[src][i].n] == false){
        bool res = hasPath(graph, graph[src][i].n, dest,visited);
        if(res){
            return true;
        }
        }

    }

    return false;
}

int minres = INT_MAX;
string minPath;
int maxres = INT_MIN;
string maxPath;
int ceilres = INT_MAX;
string ceilPath;
int floorres = INT_MIN;
string floorPath;
int kthlargestres = INT_MAX;
string kthlargestPath;
void printAllPaths(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited, string psf, int sum, int factor){

    if(src == dest){
        cout << psf << "@" << sum << endl;

        if(sum < minres){
            minres = sum;
            minPath = psf;
        
        }

        if(sum > maxres){
            maxres = sum;
            maxPath = psf;
        }

        if(sum > factor && sum < ceilres){
            ceilres = sum;
            ceilPath = psf;

        }

        if(sum < factor && sum > floorres){
            floorres = sum;
            floorPath = psf;
        }

        

    }

    

    for(int i=0; i<graph[src].size(); i++){
        if(visited[graph[src][i].n] == false){
            visited[graph[src][i].n] = true;
            printAllPaths(graph, graph[src][i].n, dest, visited, psf + to_string(graph[src][i].n), sum + graph[src][i].w, factor);
            visited[graph[src][i].n] = false;
        }
    }
}

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

bool bfs(vector<vector<Edge>>& graph, int src, int dest, vector<bool>& visited){
    list<THelper> queue;
    queue.push_back(THelper(src, "" + to_string(src), 0));

    while(queue.size()>0){
        THelper rem = queue.front();
        queue.pop_front();
        cout << rem.v << " via " << rem.path << "@" << rem.d << endl;
        if(visited[rem.v] == true){
            continue;
        }
        else
            visited[rem.v] = true;

        if(rem.v == dest){
            return true;
        }
        for(int i=0; i<graph[rem.v].size(); i++){
            Edge th = graph[rem.v][i];
            if(visited[th.n] == false){
                queue.push_back(THelper(th.n, rem.path + to_string(th.n), rem.d + th.w));
            }
        }
    }
    return false;
}

string getconnectedcomponent(vector<vector<Edge>>& graph, int src, vector<bool>& visited){
    string res = "";
    list<int> queue;
    queue.push_back(src);

    while(queue.size()>0){
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true){
            continue;
        }
        else
            visited[rem] = true;
        res+= to_string(rem);

        for(int i=0; i<graph[rem].size(); i++){
            if(visited[graph[rem][i].n] == false){
                queue.push_back(graph[rem][i].n);
            }
        }

    }

    return res;
}

vector<string> getconnectedcomponents(vector<vector<Edge>>& graph, int src, int dest){
    vector<string> res;
    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == false){
            string myres = getconnectedcomponent(graph, i, visited);
            res.push_back(myres);
        }
    }
    return res;
}

class FHelper{
    public:
    int i;
    int j;
    int t;

    FHelper(int i, int j, int t){
        this->i = i;
        this->j = j;
        this->t = t;
    }
};

bool isValid(vector<vector<int>>& mat, int i, int j){
    if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size()){
        return false;
    }

    else if(mat[i][j] == -1){
        return false;
    }

    else if(mat[i][j] > 0){
        return false;
    }

    else{
        return true;
    }


}

void fireBreak(vector<vector<int>>& mat){
    list<FHelper> queue;

    for(int i=0; i<mat.size(); i++){
        for(int j = 0; j<mat[0].size(); j++){
            if(mat[i][j] == 0){
                queue.push_back(FHelper(i, j, 0));
            }
        }
    }

    while(queue.size()>0 && queue.front().t<=3){
        FHelper rem = queue.front();
        queue.pop_front();

        if(mat[rem.i][rem.j] != 0){
            mat[rem.i][rem.j] = rem.t;
        }

        if(isValid(mat, rem.i - 1, rem.j))
            queue.push_back(FHelper(rem.i-1, rem.j, rem.t + 1));

        if(isValid(mat, rem.i + 1, rem.j))
            queue.push_back(FHelper(rem.i+1, rem.j, rem.t + 1));

        if(isValid(mat, rem.i, rem.j-1))
            queue.push_back(FHelper(rem.i, rem.j-1, rem.t + 1));

        if(isValid(mat, rem.i, rem.j+1))
            queue.push_back(FHelper(rem.i, rem.j+1, rem.t + 1));            
    }
}

class IHelper{
    public:
    int i;
    int j;

    IHelper(int i, int j){
        this->i = i;
        this->j = j;
    }
};

bool isValidIsland(vector<vector<int>>& mat, int i, int j){
    if(i<0 || i>= mat.size() || j<0 || j>=mat[0].size()){
        return false;
    }

    else if(mat[i][j] == 1){
        return false;
    }

    else if(mat[i][j] == 2){
        return false;
    }

    else{
        return true;
    }
}

void getconnectedislandcomponent(vector<vector<int>>& mat, int src, int dest){

    list<IHelper> queue;
    queue.push_back(IHelper(src, dest));

    while(queue.size() > 0){
        IHelper rem = queue.front();
        queue.pop_front();

        if(mat[rem.i][rem.j] > 0){
            return;
        }

        else
        {
            mat[rem.i][rem.j] = 2;            
        }

        if(isValid(mat, rem.i-1, rem.j))
            queue.push_back(IHelper(rem.i-1, rem.j)); 

        if(isValid(mat, rem.i+1, rem.j))
            queue.push_back(IHelper(rem.i+1, rem.j));

        if(isValid(mat, rem.i, rem.j-1))
            queue.push_back(IHelper(rem.i, rem.j-1));

        if(isValid(mat, rem.i, rem.j+1))
            queue.push_back(IHelper(rem.i, rem.j+1));        
    }

    return;
}


int getconnectedislandcomponents(vector<vector<int>> mat){
    int count = 0;

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j] == 0){
                getconnectedislandcomponent(mat, i, j);
                count++;
            }
        }
    }
    return count;
}

bool isCyclicComponent(vector<vector<Edge>>& graph, int src, vector<bool>& visited){

    list<Edge> queue;
    queue.push_back(Edge(src, 5));

    while(queue.size() > 0){
        Edge rem = queue.front();
        queue.pop_front();

        if(visited[rem.n] == true){
            return true;
        }
        else
            visited[rem.n] = true;

        for(int i=0; i<graph[rem.n].size(); i++){
            Edge ed = graph[rem.n][i];
            if(visited[ed.n] == false){
                queue.push_back(Edge(ed.n, 5));
            }
        }    
    }
    return false;
}

bool isCyclicComponents(vector<vector<Edge>>& graph){
    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == false){
           bool res = isCyclicComponent(graph, i, visited);
           if(res == true){
               return true;
           } 
        }
    }
    return false;
}

class AHelper{
    public:
    int i;

    AHelper(int i){
        this->i = i;
    }
};

string astronautscomponent(vector<vector<Edge>>& graph, int src, vector<bool>& visited){
    string res = "";
    list<AHelper> queue;
    queue.push_back(AHelper(src));

    while(queue.size()>0){
        AHelper rem = queue.front();
        queue.pop_front();

        if(visited[rem.i] == true){
            return res;
        }
        else{
            visited[rem.i] = true;
        }

        res+=to_string(rem.i);

        for(int j=0; j<graph[rem.i].size(); j++){
            Edge ed = graph[rem.i][j];
            if(visited[ed.n] == false){
                queue.push_back(AHelper(ed.n));
            }
        }
       // return rem.path;
    }
    return res;
}

int astronautscomponents(vector<vector<Edge>>& graph){
    vector<string> res;
    vector<bool> visited(graph.size(), false);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == false){
          string myres = astronautscomponent(graph, i, visited);
          res.push_back(myres);
        }
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    cout << endl;
}

int astronauts(vector<int> arr1, vector<int> arr2){
    vector<vector<Edge>> graph(12);

    for(int i=0; i<arr1.size(); i++){
        addEdge(graph,arr1[i], arr2[i], 5);
    }

    return astronautscomponents(graph);

}

class BHelper{
    public:
    int n;
    int level;

    BHelper(int n, int level){
        this->n = n;
        this->level = level;
    }
};

bool isBipartiteComponents(vector<vector<Edge>>& graph, int src, vector<int>& visited){
    list<BHelper> queue;
    queue.push_back(BHelper(src, 0));

    while(queue.size()>0){
        BHelper rem = queue.front();
        queue.pop_front();

        if(visited[rem.n] != -1){
            if(visited[rem.n]%2 != rem.level%2){
                return false;
            }
            else{
                continue;
            }
        }
        else{
            visited[rem.n] = rem.level;
        }

        for(int i=0; i<graph[rem.n].size(); i++){
            Edge ed = graph[rem.n][i];
            if(visited[ed.n] == -1){
                queue.push_back(BHelper(ed.n, rem.level+1));
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<Edge>>& graph){
    vector<int> visited(graph.size(), -1);
    for(int i=0; i<graph.size(); i++){
        if(visited[i] == -1){
            bool res = isBipartiteComponents(graph, i, visited);
            if(res == false){
                return false;
            }
        }
    }
    return true;
}




int main(int argc, char** argv){

    vector<vector<Edge>> graph(7);
    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);
    addEdge(graph,2,3,10);
    addEdge(graph,0,3,40);
    addEdge(graph,3,4,2);
    addEdge(graph,4,5,3);
    addEdge(graph,5,6,3);
    addEdge(graph,4,6,8);
   // display(graph);
    vector<bool> visited(7,false);
    //  cout << hasPath(graph, 0, 6, visited) << endl;
   // visited[0] = true;
    // printAllPaths(graph, 0, 6, visited, "0",0,49);
    // cout << "Min_Path" << "-->" << minPath << "@" << minres << endl;
    // cout << "Max_Path" << "-->" << maxPath << "@" << maxres << endl;
    // cout << "Ceil_Path" << "-->" << ceilPath << "@" << ceilres << endl;
    // cout << "Floor_Path" << "-->" << floorPath << "@" << floorres << endl;
    // cout << "KthLargest_Path" << "-->" << kthlargestPath << "@" << kthlargestres << endl;
    //bfs(graph, 0, 6, visited);
    // vector<string> result = getconnectedcomponents(graph, 0, 6);
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << endl;
    // }

    // vector<vector<int>> mat{
    //     {-2,-1,-2,-1,-1,-2},
    //     {-2,-1,-2,-2,-1,-2},
    //     {-2,-2,-2,-1,-2,0},
    //     {-2,-1,-2,-1,-2,-1},
    //     {0,-2,-1,-1,-2,-2}
    // };
    // vector<vector<int>> mat{
    //     {-2,-2,0,-2,-2,-2},
    //     {-2,-1,-1,-2,-1,-1},
    //     {-2,-2,-1,-2,-2,-2},
    //     {-2,-2,-2,-2,-1,-2},
    //     {-2,-1,-1,0,-2,-2}

    // };
    // fireBreak(mat);
    // for(int i=0; i<mat.size(); i++){
    //     for(int j=0; j<mat[0].size(); j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // vector<vector<int>> mat{
    //     {0,0,1,0,0},
    //     {0,1,1,1,1},
    //     {1,0,0,0,0},
    //     {0,1,0,1,0},
    //     {0,1,1,1,0}
    // };
    // cout << getconnectedislandcomponents(mat) << endl;

  //  cout << isCyclicComponents(graph) << endl;
    // vector<int> arr1{1,6,8,2,9,10,0};
    // vector<int> arr2{2,9,3,5,5,3,11};
    // astronauts(arr1,arr2);

    vector<vector<Edge>> graph2(6);
    addEdge(graph2,0,1,5);
    addEdge(graph2,0,3,5);
    addEdge(graph2,1,2,5);
    addEdge(graph2,2,3,5);
    addEdge(graph2,2,5,5);
    addEdge(graph2,3,4,5);
    addEdge(graph2,4,5,5);
    addEdge(graph2,2,5,5);

    cout << isBipartite(graph2) << endl;

    
}