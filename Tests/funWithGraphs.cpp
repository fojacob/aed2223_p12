// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#include "funWithGraphs.h"

// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(12, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,8);
    g.addEdge(2,8);
    g.addEdge(3,8);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(10,11);
    g.addEdge(11,12);
    g.addEdge(11,5);
    g.addEdge(11,6);
    g.addEdge(12,5);
    g.addEdge(12,6);
    g.addEdge(5,6);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(10, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,6);
    g.addEdge(5,10);
    g.addEdge(2,6);
    g.addEdge(4,10);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(9,10);
    return g;
}

// ----------------------------------------------------------
// Exercicio 2: Um labirinto 2D
// ----------------------------------------------------------
// TODO
int FunWithGraphs::maze(int rows, int cols, string m[]) {
    bool visited[rows][cols];
    int distance[rows][cols];
    queue<pair<int,int>> q;
    int ty, tx;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            visited[i][j] = false;
            if(m[i][j] == 'P'){
                visited[i][j] = true;
                distance[i][j] = 0;
                q.emplace(i,j);
            }
            else if (m[i][j] == 'T'){
                ty = i;
                tx = j;
            }
        }
    }
    int ndirs = 4, incx[] = {0,0,-1,+1}, incy[] = {-1, 1,0,0};
    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(int i=0; i<ndirs; i++){
            int ny = u.first + incy[i];
            int nx = u.second + incx[i];
            if(ny>=0 && ny<rows && nx>=0 && nx<cols && !visited[ny][nx] && m[ny][nx]!='#'){
                q.emplace(ny,nx);
                visited[ny][nx] = true;
                distance[ny][nx] = distance[u.first][u.second] + 1;
            }
        }
    }
    return distance[ty][tx];
}

// ----------------------------------------------------------
// Exercicio 3: Nuvem de Cinzas
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithGraphs::volcano(int rows, int cols, string m[]) {
    return {0, 0};
}

// ----------------------------------------------------------
// Exercicio 4: Quadrados Mágicos
// ----------------------------------------------------------
// TODO
pair<int, string> FunWithGraphs::game(const vector<int> & target) {
    return {0, ""};
}
