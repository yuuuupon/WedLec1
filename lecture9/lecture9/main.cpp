#include<stdio.h>

////////////////////////////////
//                            //
// 課題内容は164行目からです。//
//                            //
////////////////////////////////

/*
オブジェクトの生成と破棄
C++ではメモリ確保をnew/deleteを使うことで行うことができる。
まずはメモリ確保のやり方以前に、
なぜメモリ確保を必要とするのか話していきます。
*/

/*
なぜメモリ確保が必要なのか
ゲームに限らず、すべてのアプリケーションにおいて、
膨大なデータを扱うアプリケーションはそのすべてのデータを
メモリ上に展開することはできない。
ねぜなら、メモリは有限だからです。
メモリが無限であれば、メモリ確保を行う必要はありません。
しかし、現実的にメモリが無限ということはないので、
メモリ確保の機能を利用し、
メモリをそのタイミングに必要な量だけ使う、
ということができるので
メモリ確保はメモリが無限になるまでは
必要な技術になります。

メリット：
有限なメモリを、その時々に必要の量だけを使うことができる。

デメリット：
確保したメモリの解放を忘れると、メモリリークして
バグの原因になる。
そもそもメモリの確保の処理は重たい。
*/

/*
new
newの処理はメモリを必要量確保し、
その確保したメモリがどこにあるか示す
先頭のアドレスを返してくれる処理です。

//newIntの指す先(メモリ確保された箇所)は未初期化
int * newInt = new int;

//newIntの指す先(メモリ確保された箇所)は0で初期化
int * newInt = new int();

//newIntの指す先(メモリ確保された箇所)は10で初期化
int * newInt = new int(10);

上記のように、
メモリ確保のやり方は複数あります。

配列を確保する場合
int * newArray = new int[100];

//メモリ確保に失敗したかどうかの判定もする場合
int * newArray2 = new(std::nothrow) int[100];
if(newArray2 == nullptr)
{
	//メモリ不足
}

既存の型(charやintやfloatなど)だけでなく、
自分で作ったclassも、もちろんメモリ確保できる。
class Vector3D
{
public:
    Vector3D()
    {
        x = y = z = 0;  // 一括で同じ値で初期化するならこういう書き方も可能
    }
private:
    float x;
    float y;
    float z;
};

Vector3D * pVec3d = new Vector3D();
*/

/*
int main()
{
    // newIntの指す先(メモリ確保された箇所)は未初期化
    int* newInt = new int;

    // newIntの指す先(メモリ確保された個所)は0で初期化
    int* newInt2 = new int();

    // newIntの指す先(メモリ確保された箇所)は10で初期化
    int* newInt3 = new int(10);

    printf("newInt1 = %d\n", *newInt);
    printf("newInt2 = %d\n", *newInt2);
    printf("newInt3 = %d\n", *newInt3);

    delete newInt3;
    newInt3 = nullptr;  // この後処理はないので必要ないが癖付けの意味で書く
    delete newInt2;
    newInt2 = nullptr;
    delete newInt;
    newInt = nullptr;
}
*/

/*
delete
deleteはnewと対になる処理で、
確保しておいたメモリを解放します。
newでメモリを確保していた場合、必ずdeleteで解放する
必要があります。

int * newInt = new int();
int * newArray = new int[100];

delete[] = new Array;
newArray = nullptr;

delete newInt;
newInt = nullptr;

newはいろいろな確保のやり方がありましたが、
deleteは配列かそうでないかの2パターンになります。
deleteをした後のポインタ変数にnullptrを入れておいて、
現在どのアドレスも指していない = 使用していない変数
ということを明示しておきましょう。
*/

/*
メモリ確保を使用し、
1000個の配列を確保して、
その配列に0～999を設定するプログラムの作成
*/

/*
int main()
{
    int* pArray = new int[1000];

    for (int i = 0; i < 1000; i++)
    {
        pArray[i] = i;
    }

    for (int i = 0; i < 1000; i++)
    {
        printf("num = %d\n", pArray[i]);
    }

    delete[] pArray;
    pArray = nullptr;
}
*/

/*
newとdeleteで配列を確保する処理を、
クラスにしてデストラクタで自動でdeleteが呼ばれるようにしてください
*/

class Array
{
//1しか出てこない
public:
    int num;
    void Create(int num)
    {
        Array1 = new int[num];
        Array1Size = num;
    };

    ~Array()
    {
        delete[] Array1;
        Array1 = nullptr;
    };

    void Set(int num,int numnum)
    {
        if (0 <= num && num < Array1Size)
        {
            Array1[num] = numnum;
        }

        else
        {
            printf("banana");
        }
    };

    int Get(int num)
    {
        if (0 <= num && num < Array1Size)
        {
            return Array1[num];
        }

        else
        {
            printf("banana");
            return 0;
        }
    }
private:
    //int Array1;
    int* Array1 = nullptr;
    int Array1Size;
};

int main()
{
    Array array;

    array.Create(1000);

    for (int i = 0; i < 1000; i++)
    {
        array.Set(1);
        printf("num = %d\n", array.Get(1));
    }

    //配列外を参照しようとした際の確認
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}

/*
class Array
{
public:
    Array()
    {
        // コンストラクタで初期化する
        pArray = nullptr;

        // C++では自動で解放してくれないので最初に解放しなければならない
        //delete[] pArray;
    }

private:
    int* pArray;
    //int* pArray = nullptr;   // <-ここに初期化は入れなくていい。
    //int* pArray = new int[0]; // <-もしこう書くなら
};

int main()
{
    int* array = new int[0]; // <- 要素0だがメモリ確保は行われている。空っぽではない。
    delete[] array;
}
*/

/*
メモリを確保している状態
例えば、
int * newInt = new int();
とメモリ確保をした場合、
4バイト分のメモリを確保したことになります。
(この4バイトはintのサイズ分になります)
メモリを確保している状態がどういう状態かというと、
4バイト分のメモリをロック状態にしていることになります。
このロック状態というのは、
他にnewをしようとしたときに、
この部分は今使っているので、
確保できませんと占領している状態になります。
newIntで値を自在に変更できるように、
メモリ自体へのアクセスはメモリ確保されていても、
自由ですが、
メモリ確保中の場所をもう一度メモリ確保しようとしても、
メモリ確保させないという意味で、
ロック状態と呼んでいます。

このロック状態を解除して、
別のnewがこのロックしていた場所を
自由に使える状態に戻すのがdeleteです。

メモリリークというのは、
このdeleteすることを忘れて、
メモリのロック状態をそのままにしていくことです。
4バイト分忘れたくらいで、
メモリ確保ができなくなることはありませんが、
これを続けていくと、
ほとんどのメモリがロック状態になり、
新しくメモリが確保できなくなり、
メモリ確保に失敗する状態を、
メモリリークと呼びます。

全くdeleteをしていないと、
メモリリークしますので、
必ずdeleteはセットで使うようにしましょう。
*/

/*
TIPS:
Javaなどではメモリは、
ガベージコレクションというシステムで管理され、
メモリ解放を忘れることがないように、
システムで担保されています。

このようにメモリの便利な使い方の技法に、
・メモリプール
あらかじめchar memory_pool[1024*1024*64];    // 64MB分メモリを確保。
newを自作して、memory_poolからメモリを確保するようにする。

・ガベージコレクション
参照カウントを持ったポインタ型に値をアドレスを保存しておいて、
参照カウントが0になれば、誰も使っていないので、
自動でメモリを解放する。
なので、MemoryManagerクラスで一元管理のような形になる。

など様々な方法がありますので、
調べてみてください。

C++ではそのようなシステムは用意されていないのが、
デメリット(メモリリークを起こせる)ですが、
逆にどの手法を洗濯するか場合に応じて選べるメリットもあります。
(処理を軽くすることに重きを置くのか、安全性に重きを置くのか等々)

*/