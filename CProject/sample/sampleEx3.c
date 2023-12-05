//ここでは動的なメモリの確保の仕方に関する内容を記述します。//

#include<stdio.h>
#include<stdlib.h>

int main()
{
/*
    //malloc
    stdlib.h を include すると利用できます。

    こちらの機能は入力した値文のbyteを動的に確保します。
*/

    int *i_pointer = (int*)malloc(sizeof(int) * 1000);

/*
    //free
    stdlib.h を include すると利用できます。

    こちらはmalloc等で動的に確保したメモリを開放します。

    malloc等を利用していた場合は必ず開放を行うようにしてください。
    解放しなかった場合はメモリリークと呼ばれるバグを埋め込むことになります。
*/
    free(i_pointer);

}
