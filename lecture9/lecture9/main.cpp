#include<stdio.h>

////////////////////////////////
//                            //
// �ۑ���e��164�s�ڂ���ł��B//
//                            //
////////////////////////////////

/*
�I�u�W�F�N�g�̐����Ɣj��
C++�ł̓������m�ۂ�new/delete���g�����Ƃōs�����Ƃ��ł���B
�܂��̓������m�ۂ̂����ȑO�ɁA
�Ȃ��������m�ۂ�K�v�Ƃ���̂��b���Ă����܂��B
*/

/*
�Ȃ��������m�ۂ��K�v�Ȃ̂�
�Q�[���Ɍ��炸�A���ׂẴA�v���P�[�V�����ɂ����āA
�c��ȃf�[�^�������A�v���P�[�V�����͂��̂��ׂẴf�[�^��
��������ɓW�J���邱�Ƃ͂ł��Ȃ��B
�˂��Ȃ�A�������͗L��������ł��B
�������������ł���΁A�������m�ۂ��s���K�v�͂���܂���B
�������A�����I�Ƀ������������Ƃ������Ƃ͂Ȃ��̂ŁA
�������m�ۂ̋@�\�𗘗p���A
�����������̃^�C�~���O�ɕK�v�ȗʂ����g���A
�Ƃ������Ƃ��ł���̂�
�������m�ۂ̓������������ɂȂ�܂ł�
�K�v�ȋZ�p�ɂȂ�܂��B

�����b�g�F
�L���ȃ��������A���̎��X�ɕK�v�̗ʂ������g�����Ƃ��ł���B

�f�����b�g�F
�m�ۂ����������̉����Y���ƁA���������[�N����
�o�O�̌����ɂȂ�B
���������������̊m�ۂ̏����͏d�����B
*/

/*
new
new�̏����̓�������K�v�ʊm�ۂ��A
���̊m�ۂ������������ǂ��ɂ��邩����
�擪�̃A�h���X��Ԃ��Ă���鏈���ł��B

//newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)�͖�������
int * newInt = new int;

//newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��0�ŏ�����
int * newInt = new int();

//newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��10�ŏ�����
int * newInt = new int(10);

��L�̂悤�ɁA
�������m�ۂ̂����͕�������܂��B

�z����m�ۂ���ꍇ
int * newArray = new int[100];

//�������m�ۂɎ��s�������ǂ����̔��������ꍇ
int * newArray2 = new(std::nothrow) int[100];
if(newArray2 == nullptr)
{
	//�������s��
}

�����̌^(char��int��float�Ȃ�)�����łȂ��A
�����ō����class���A������񃁃����m�ۂł���B
class Vector3D
{
public:
    Vector3D()
    {
        x = y = z = 0;  // �ꊇ�œ����l�ŏ���������Ȃ炱���������������\
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
    // newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)�͖�������
    int* newInt = new int;

    // newInt�̎w����(�������m�ۂ��ꂽ��)��0�ŏ�����
    int* newInt2 = new int();

    // newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��10�ŏ�����
    int* newInt3 = new int(10);

    printf("newInt1 = %d\n", *newInt);
    printf("newInt2 = %d\n", *newInt2);
    printf("newInt3 = %d\n", *newInt3);

    delete newInt3;
    newInt3 = nullptr;  // ���̌㏈���͂Ȃ��̂ŕK�v�Ȃ����ȕt���̈Ӗ��ŏ���
    delete newInt2;
    newInt2 = nullptr;
    delete newInt;
    newInt = nullptr;
}
*/

/*
delete
delete��new�Ƒ΂ɂȂ鏈���ŁA
�m�ۂ��Ă�������������������܂��B
new�Ń��������m�ۂ��Ă����ꍇ�A�K��delete�ŉ������
�K�v������܂��B

int * newInt = new int();
int * newArray = new int[100];

delete[] = new Array;
newArray = nullptr;

delete newInt;
newInt = nullptr;

new�͂��낢��Ȋm�ۂ̂���������܂������A
delete�͔z�񂩂����łȂ�����2�p�^�[���ɂȂ�܂��B
delete��������̃|�C���^�ϐ���nullptr�����Ă����āA
���݂ǂ̃A�h���X���w���Ă��Ȃ� = �g�p���Ă��Ȃ��ϐ�
�Ƃ������Ƃ𖾎����Ă����܂��傤�B
*/

/*
�������m�ۂ��g�p���A
1000�̔z����m�ۂ��āA
���̔z���0�`999��ݒ肷��v���O�����̍쐬
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
new��delete�Ŕz����m�ۂ��鏈�����A
�N���X�ɂ��ăf�X�g���N�^�Ŏ�����delete���Ă΂��悤�ɂ��Ă�������
*/

class Array
{
//1�����o�Ă��Ȃ�
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

    //�z��O���Q�Ƃ��悤�Ƃ����ۂ̊m�F
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}

/*
class Array
{
public:
    Array()
    {
        // �R���X�g���N�^�ŏ���������
        pArray = nullptr;

        // C++�ł͎����ŉ�����Ă���Ȃ��̂ōŏ��ɉ�����Ȃ���΂Ȃ�Ȃ�
        //delete[] pArray;
    }

private:
    int* pArray;
    //int* pArray = nullptr;   // <-�����ɏ������͓���Ȃ��Ă����B
    //int* pArray = new int[0]; // <-�������������Ȃ�
};

int main()
{
    int* array = new int[0]; // <- �v�f0�����������m�ۂ͍s���Ă���B����ۂł͂Ȃ��B
    delete[] array;
}
*/

/*
���������m�ۂ��Ă�����
�Ⴆ�΁A
int * newInt = new int();
�ƃ������m�ۂ������ꍇ�A
4�o�C�g���̃��������m�ۂ������ƂɂȂ�܂��B
(����4�o�C�g��int�̃T�C�Y���ɂȂ�܂�)
���������m�ۂ��Ă����Ԃ��ǂ�������Ԃ��Ƃ����ƁA
4�o�C�g���̃����������b�N��Ԃɂ��Ă��邱�ƂɂȂ�܂��B
���̃��b�N��ԂƂ����̂́A
����new�����悤�Ƃ����Ƃ��ɁA
���̕����͍��g���Ă���̂ŁA
�m�ۂł��܂���Ɛ�̂��Ă����ԂɂȂ�܂��B
newInt�Œl�����݂ɕύX�ł���悤�ɁA
���������̂ւ̃A�N�Z�X�̓������m�ۂ���Ă��Ă��A
���R�ł����A
�������m�ے��̏ꏊ��������x�������m�ۂ��悤�Ƃ��Ă��A
�������m�ۂ����Ȃ��Ƃ����Ӗ��ŁA
���b�N��ԂƌĂ�ł��܂��B

���̃��b�N��Ԃ��������āA
�ʂ�new�����̃��b�N���Ă����ꏊ��
���R�Ɏg�����Ԃɖ߂��̂�delete�ł��B

���������[�N�Ƃ����̂́A
����delete���邱�Ƃ�Y��āA
�������̃��b�N��Ԃ����̂܂܂ɂ��Ă������Ƃł��B
4�o�C�g���Y�ꂽ���炢�ŁA
�������m�ۂ��ł��Ȃ��Ȃ邱�Ƃ͂���܂��񂪁A
����𑱂��Ă����ƁA
�قƂ�ǂ̃����������b�N��ԂɂȂ�A
�V�������������m�ۂł��Ȃ��Ȃ�A
�������m�ۂɎ��s�����Ԃ��A
���������[�N�ƌĂт܂��B

�S��delete�����Ă��Ȃ��ƁA
���������[�N���܂��̂ŁA
�K��delete�̓Z�b�g�Ŏg���悤�ɂ��܂��傤�B
*/

/*
TIPS:
Java�Ȃǂł̓������́A
�K�x�[�W�R���N�V�����Ƃ����V�X�e���ŊǗ�����A
�����������Y��邱�Ƃ��Ȃ��悤�ɁA
�V�X�e���ŒS�ۂ���Ă��܂��B

���̂悤�Ƀ������֗̕��Ȏg�����̋Z�@�ɁA
�E�������v�[��
���炩����char memory_pool[1024*1024*64];    // 64MB�����������m�ہB
new�����삵�āAmemory_pool���烁�������m�ۂ���悤�ɂ���B

�E�K�x�[�W�R���N�V����
�Q�ƃJ�E���g���������|�C���^�^�ɒl���A�h���X��ۑ����Ă����āA
�Q�ƃJ�E���g��0�ɂȂ�΁A�N���g���Ă��Ȃ��̂ŁA
�����Ń��������������B
�Ȃ̂ŁAMemoryManager�N���X�ňꌳ�Ǘ��̂悤�Ȍ`�ɂȂ�B

�ȂǗl�X�ȕ��@������܂��̂ŁA
���ׂĂ݂Ă��������B

C++�ł͂��̂悤�ȃV�X�e���͗p�ӂ���Ă��Ȃ��̂��A
�f�����b�g(���������[�N���N������)�ł����A
�t�ɂǂ̎�@����󂷂邩�ꍇ�ɉ����đI�ׂ郁���b�g������܂��B
(�������y�����邱�Ƃɏd����u���̂��A���S���ɏd����u���̂����X)

*/