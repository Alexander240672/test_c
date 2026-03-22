//广度优先-bfs
#include <stdio.h>
#define maxsize 100
typedef char vertextype;
typedef int edgetype;
typedef struct 
{
    vertextype vertex[maxsize];
    edgetype arc[maxsize][maxsize];
    int vertex_num;
    int edge_num;
}mat_grph;
int visited[maxsize];
int front = 0;
int rear = 0;
int queue[maxsize];
//造图
void create_graph(mat_grph* g)
{
    g->vertex_num = 9;
    g->edge_num = 15;
    g->vertex[0] = 'A';
    g->vertex[1] = 'B';
    g->vertex[2] = 'C';
    g->vertex[3] = 'D';
    g->vertex[4] = 'E';
    g->vertex[5] = 'F';
    g->vertex[6] = 'G';
    g->vertex[7] = 'H';
    g->vertex[8] = 'I';
    for(int i = 0;i < g->vertex_num;i++)
    {
        for(int j = 0;j < g->vertex_num;j++)
        {
            g->arc[i][j] = 0;
        }
    }
    //A-B A-F
    g->arc[0][1] = 1;
    g->arc[0][5] = 1;
    //B-C B-G B-I
    g->arc[1][2] = 1;
    g->arc[1][6] = 1;
    g->arc[1][8] = 1;
    //C-D C-I
    g->arc[2][3] = 1;
    g->arc[2][8] = 1;
    //D-E D-G D-H D-I
    g->arc[3][4] = 1;
    g->arc[3][6] = 1;
    g->arc[3][7] = 1;
    g->arc[3][8] = 1;
    //E-F E-H
    g->arc[4][5] = 1;
    g->arc[4][7] = 1;
    //F-G
    g->arc[5][6] = 1;
    //G-H
    g->arc[6][7] = 1;
    for(int i = 0;i < g->vertex_num;i++)
    {
        for(int j = 0;j < g->vertex_num;j++)
        {
            g->arc[j][i] = g->arc[i][j];
        }
    }
}
void bfs(mat_grph g)
{
    int i = 0;
    visited[i] = 1;
    printf("%c\n",g.vertex[i]);
    queue[rear] = i;
    rear++;
    while(front != rear)
    {
        i = queue[front];
        front++;
        for(int j = 0;j < g.vertex_num;j++)
        {
            if(g.arc[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                printf("%c\n",g.vertex[j]);
                queue[rear] = j;
                rear++;
            }
        }
    }
}
int main()
{
    mat_grph g;
    create_graph(&g);
    for(int i = 0;i < g.vertex_num;i++)
    {
        visited[i] = 0;
    }
    bfs(g);
    return 0;
}