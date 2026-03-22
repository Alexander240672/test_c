//最小生成树-克鲁斯卡尔(kruskal)->针对边，边数少时效率高
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
#define max 0x7fffffff
typedef char vertextype;
typedef int edgetype;
typedef struct 
{
    vertextype vertex[maxsize];
    edgetype arc[maxsize][maxsize];
    int vertex_num;
    int edge_num;
}mat_grph;
typedef struct 
{
    int begin;
    int end;
    int weight;
}edge;
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
            if(i == j)
            {
                g->arc[i][j] = 0;
            }
            else
            {
                g->arc[i][j] = max;
            }
        }
    }
    //A-B A-F
    g->arc[0][1] = 10;               
    g->arc[0][5] = 11;
    //B-C B-G B-I              
    g->arc[1][2] = 18;            
    g->arc[1][6] = 16;               
    g->arc[1][8] = 12;
    //C-D C-I              
    g->arc[2][3] = 22;              
    g->arc[2][8] = 8;
    //D-E D-G D-H D-I              
    g->arc[3][4] = 20;              
    g->arc[3][6] = 24;              
    g->arc[3][7] = 16;              
    g->arc[3][8] = 21;
    //E-F E-H              
    g->arc[4][5] = 26;              
    g->arc[4][7] = 7;
    //F-G              
    g->arc[5][6] = 17;
    //G-H              
    g->arc[6][7] = 19;
    for(int i = 0;i < g->vertex_num;i++)
    {
        for(int j = 0;j < g->vertex_num;j++)
        {
            g->arc[j][i] = g->arc[i][j];
        }
    }              
}
void swap(edge* edges,int i,int j)
{
    int temp;
    temp = edges[i].begin;
    edges[i].begin = edges[j].begin;
    edges[j].begin = temp;
    temp = edges[i].end;
    edges[i].end = edges[j].end;
    edges[j].end = temp;
    temp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = temp;
}
void sortedges(edge edges[],int edge_num)
{
    for(int i = 0;i < edge_num;i++)
    {
        for(int j = i + 1;j < edge_num;j++)
        {
            if(edges[i].weight > edges[j].weight)
            {
                swap(edges,i,j);
            }
        }
    }
}
int find(int* parent,int index)
{
    while(parent[index] > 0)
    {
        index = parent[index];
    }
    return index;
}
void kruskal(mat_grph g)
{
    edge edges[maxsize];
    int k = 0;
    for(int i = 0;i < g.vertex_num;i++)
    {
        for(int j = i + 1;j < g.vertex_num;j++)
        {
            if(g.arc[i][j] < max)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = g.arc[i][j];
                k++;
            }
        }
    }
    sortedges(edges,g.edge_num);
    int parent[maxsize];
    for(int i = 0;i < g.vertex_num;i++)
    {
        parent[i] = 0;
    }
    int n,m;
    for(int i = 0;i < g.edge_num;i++)
    {
        n = find(parent,edges[i].begin);
        m = find(parent,edges[i].end);
        if(n != m)
        {
            parent[n] = m;
            printf("(%d,%d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);
            printf("(%c,%c) %d\n",g.vertex[edges[i].begin],g.vertex[edges[i].end],edges[i].weight);
        }
    }
}
int main()
{
    mat_grph g;
    create_graph(&g);
    kruskal(g);
    return 0;
}