strcpy和memcpy的区别
strcpy和memcpy都是标准C库函数，它们有下面的特点。
strcpy提供了字符串的复制。即strcpy只用于字符串复制，并且它不仅复制字符串内容之外，还会复制字符串的结束符。

已知strcpy函数的原型是：char* strcpy(char* dest, const char* src);
memcpy提供了一般内存的复制。即memcpy对于需要复制的内容没有限制，因此用途更广。
void *memcpy( void *dest, const void *src, size_t count );

char * strcpy(char * dest, const char * src) // 实现src到dest的复制
{
　　if ((src == NULL) || (dest == NULL)) //判断参数src和dest的有效性
　　{
 
　　　　　　return NULL;
　　}
　　char *strdest = dest;        //保存目标字符串的首地址
　　while ((*strDest++ = *strSrc++)!='\0'); //把src字符串的内容复制到dest下
　　return strdest;
}
void *memcpy(void *memTo, const void *memFrom, size_t size)
{
　　if((memTo == NULL) || (memFrom == NULL)) //memTo和memFrom必须有效
         return NULL;
　　char *tempFrom = (char *)memFrom;             //保存memFrom首地址
　　char *tempTo = (char *)memTo;                  //保存memTo首地址      
　　while(size -- > 0)                //循环size次，复制memFrom的值到memTo中
       　　*tempTo++ = *tempFrom++ ;  
　　return memTo;
}
strcpy和memcpy主要有以下3方面的区别。
1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy