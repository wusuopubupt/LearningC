strcpy��memcpy������
strcpy��memcpy���Ǳ�׼C�⺯����������������ص㡣
strcpy�ṩ���ַ����ĸ��ơ���strcpyֻ�����ַ������ƣ����������������ַ�������֮�⣬���Ḵ���ַ����Ľ�������

��֪strcpy������ԭ���ǣ�char* strcpy(char* dest, const char* src);
memcpy�ṩ��һ���ڴ�ĸ��ơ���memcpy������Ҫ���Ƶ�����û�����ƣ������;���㡣
void *memcpy( void *dest, const void *src, size_t count );

char * strcpy(char * dest, const char * src) // ʵ��src��dest�ĸ���
{
����if ((src == NULL) || (dest == NULL)) //�жϲ���src��dest����Ч��
����{
 
������������return NULL;
����}
����char *strdest = dest;        //����Ŀ���ַ������׵�ַ
����while ((*strDest++ = *strSrc++)!='\0'); //��src�ַ��������ݸ��Ƶ�dest��
����return strdest;
}
void *memcpy(void *memTo, const void *memFrom, size_t size)
{
����if((memTo == NULL) || (memFrom == NULL)) //memTo��memFrom������Ч
         return NULL;
����char *tempFrom = (char *)memFrom;             //����memFrom�׵�ַ
����char *tempTo = (char *)memTo;                  //����memTo�׵�ַ      
����while(size -- > 0)                //ѭ��size�Σ�����memFrom��ֵ��memTo��
       ����*tempTo++ = *tempFrom++ ;  
����return memTo;
}
strcpy��memcpy��Ҫ������3���������
1�����Ƶ����ݲ�ͬ��strcpyֻ�ܸ����ַ�������memcpy���Ը����������ݣ������ַ����顢���͡��ṹ�塢��ȡ�
2�����Ƶķ�����ͬ��strcpy����Ҫָ�����ȣ��������������ַ��Ĵ�������"\0"�Ž������������������memcpy���Ǹ������3�������������Ƶĳ��ȡ�
3����;��ͬ��ͨ���ڸ����ַ���ʱ��strcpy������Ҫ����������������ʱ��һ����memcpy