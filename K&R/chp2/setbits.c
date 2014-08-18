#include <stdio.h>
#define MAXCHAR 100
 
void itob(unsigned x,char s[]);
unsigned setbits(unsigned x,int p,int n,unsigned y);
int main()
{
    int x=0,p=0,n=0,i=0;
    unsigned int m=0;
    unsigned int y=0;
    char binary_unit[MAXCHAR];
    for (i=0;i<MAXCHAR-1;i++)
    {
        binary_unit[i]=0;
    }
    
    x=170;                                    //10101010b;
    y=15;                                     //00001111b;
 
    /* test 1 */
    p=1;
    n=3;
 
    printf ("test 1:\n"); 
    itob(x,binary_unit);
    printf ("x=%u=%sb\t",x,binary_unit); 
    itob(y,binary_unit);
    printf ("y=%u=%sb\t",y,binary_unit);   
    printf ("p=%d\tn=%d\n",p,n);
 
    m=setbits(x,p,n,y);                       //10101110b;174
    itob(m,binary_unit);
    printf ("changed x=%d=%sb\n\n",m,binary_unit);
 
    /* test 2 */
    p=4;
    n=2;
    printf ("test 2:\n"); 
    itob(x,binary_unit);
    printf ("x=%u=%sb\t",x,binary_unit); 
    itob(y,binary_unit);
    printf ("y=%u=%sb\t",y,binary_unit);   
    printf ("p=%d\tn=%d\n",p,n);
 
    m=setbits(x,p,n,y);                       //10111010b;186
    itob(m,binary_unit);
    printf ("changed x=%d=%sb\n\n",m,binary_unit);
 
    return 0;
}
/* setbits函数: 返回对x做如下处理得到的值:x从第p位开始的n位被置为y的最右边n位的值，其余各位保持不变*/
unsigned setbits(unsigned x,int p,int n,unsigned y)
{
    return (x & ~((~(~0 << n)) << p) | ((y<<p) & ((~(~0 << n)) << p)));
}
/* itob函数: 将无符号整数转化为二进制,将二进制位存放到数组,注意:要检查数组是否足够大 */
void itob(unsigned x,char s[])
{
    int i=0,n=0;
    char temp[MAXCHAR];
    
    while ((x/2)!=0)
    {
        temp[n]=((x%2)+'0');
        x /= 2;
        n++;
    }
    temp[n]=((x%2)+'0');
    temp[n+1]='\0';
     
    /* 逆序存放 */
    i=0;
    while (n>=0)
    {
        s[i]=temp[n--];
        i++;
    }
    s[i]='\0';
}
