//https://zh.wikipedia.org/wiki/%E5%8E%9F%E6%A0%B9
inline fpw(int x,int y,int mod)

int calc(int x)   //求原根
{
    if (x==2) return 1;
    for (int i=2;i;i++)
    {
        bool pp=1;
        for (int j=2;j*j<x;j++)
            if (fpw(i,(x-1)/j,x)==1)   
            {
                pp=0;
                break;
            }
        if (pp) return i;
    }
} 
