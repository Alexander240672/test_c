//最小生成树-普利姆（prim）
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
void prim(mat_grph* g)
{
    int i,j,k;
    int min;
    int weight[maxsize];//候选边
    int vex_index[maxsize];//值表示出发点，下标表示到达点
    //先从顶点A开始
    weight[0] = 0;//vex_index某点与下标对应点的权重
    vex_index[0] = 0;
    for(i = 1;i < g->vertex_num;i++)
    {
        weight[i] = g->arc[0][i];
        vex_index[i] = 0;
    }
    for(int i = 1;i < g->vertex_num;i++)
    {
        min = max;
        j = 0;
        k = 0;
        //找到最小的点与之连接
        while(j < g->vertex_num)
        {
            if(weight[j] != 0 && weight[j] < min)
            {
                min = weight[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)\n",vex_index[k],k);
        printf("(%c,%c)\n",g->vertex[vex_index[k]],g->vertex[k]);
        weight[k] = 0;
        //找新连接结点的待选路径
        for(j = 0;j < g->vertex_num;j++)
        {
            //与新结点可连接的边进行比较，有比weight小的就替换
            if(weight[j] != 0 && g->arc[k][j] < weight[j])
            {
                weight[j] = g->arc[k][j];
                vex_index[j] = k;
            }
        }
    }
}
int main()
{
    mat_grph g;
    create_graph(&g);
    prim(&g);
    return 0;
}