#include <stdio.h>
    2	
    3	/* GPU用strcpy */
    4	__device__ void
    5	dev_strcpy(char *dst, const char *src)
    6	{
    7	    while (*dst++ = *src++);
    8	}
    9	
   10	/* GPU側エントリ */
   11	__global__ void gen_hello(char *A)
   12	{
   13	    dev_strcpy(A, "Hello, World!");
   14	}
   15	
   16	int main()
   17	{
   18	    char *d_hello;
   19	
   20	    /* ホストのメモリを確保 */
   21	    char hello[128];
   22	
   23	    /* GPU側のメモリ(デバイスメモリ)確保 */
   24	    cudaMalloc((void**)&d_hello, 128);
   25	
   26	    /* gen_hello 呼び出し */
   27	    gen_hello<<<1,1>>>(d_hello);
   28	
   29	    /* GPU側のデータを取得 */
   30	    cudaMemcpy(hello, d_hello, 128, cudaMemcpyDeviceToHost);
   31	
   32	    /* 確保したメモリを解放 */
   33	    cudaFree(d_hello);
   34	
   35	    /* 出力 */
   36	    puts(hello);
   37	}