import java.util.*;

public class sssp
{
    static boolean isVisited(boolean a[])
    {
        for(int i=0;i<a.length;i++)
        {
            if(a[i]==false)
            return false;
        }
        return true;
    }

    static void print_arr(int a[])
    {
        int i;
        for(i=0;i<a.length;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println("");
    }

    static void shortest_path(int cost[][],int dist[],boolean visited[],int start,int calc[][],int j)
    {
        int s=start-1;
        
        int min_d=99999,min_v=s;

        for(int i=0;i<dist.length;i++)
        {
            if(cost[s][i]!=-1 && dist[s]+cost[s][i]<dist[i] && !visited[i])
            {
                dist[i]=dist[s]+cost[s][i];
                if(min_d>dist[i])
                {
                    min_d=dist[i];
                    min_v=i+1;
                }
            }      
        }
        // print_arr(dist);
        calc[j][0]=start;
        for(int i=1;i<dist.length+1;i++)
            calc[j][i]=dist[i-1];

        visited[s]=true;
        if(isVisited(visited))
            return;
        else
            shortest_path(cost,dist,visited,min_v,calc,++j);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of nodes = ");
        int no_of_nodes = sc.nextInt();

        int cost_arr[][] = new int[no_of_nodes][no_of_nodes];
        int dist_arr[] = new int[no_of_nodes];
        boolean visited_arr[] = new boolean[no_of_nodes];
        int calc[][] = new int[no_of_nodes][no_of_nodes+1];

        System.out.print("Enter no. of edges = ");
        int no_of_edges=sc.nextInt();
        for(int i=0;i<no_of_nodes;i++)
        {
            for(int j=0;j<no_of_nodes;j++)
                cost_arr[i][j]=-1;
            dist_arr[i] = 9999;
            visited_arr[i] = false;
        }

        System.out.println("Enter Edge Details = ");
        for(int i=0;i<no_of_edges;i++)
        {
            int st = sc.nextInt();
            int dest = sc.nextInt();
            int cst = sc.nextInt();
            cost_arr[st-1][dest-1] = cst;
        }

        System.out.print("\nStart Vertex =  ");
        int st=sc.nextInt();
        System.out.println();

        dist_arr[st-1]=0;
        long start_time=System.nanoTime();
        shortest_path(cost_arr, dist_arr,visited_arr, st, calc, 0);
        long end_time=System.nanoTime();

        System.out.print("Vertex selected ");
        for(int i=1;i<=no_of_nodes;i++)
            System.out.print("["+i+"]  ");
        System.out.println("");
        for(int i=0;i<no_of_nodes;i++)
        {
            System.out.print(String.format("%-16d",calc[i][0]));
            for(int j=1;j<no_of_nodes+1;j++)
                System.out.print(String.format("%-5d",calc[i][j]));
            System.out.println("");
        }

        System.out.print("\n\nPath transversed = ");
        for(int i=0;i<no_of_nodes-1;i++)
            System.out.print(calc[i][0]+"->");
        System.out.print(calc[no_of_nodes-1][0]);

        System.out.println("\n\nExecution time = "+(end_time-start_time)+" ns");
    }
}