#define	_CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
typedef int elemtype;
typedef int keytype;
typedef struct {
	elemtype* elem;//数组
	int length;//顺序表长度
}SSTable;
void CreateSSTable(SSTable& ST, int n) {
	ST.elem = (elemtype*)malloc(n * sizeof(elemtype));
	if (!ST.elem) {
		cout << "储存分配失败" << endl;
		exit(-1);
	}
	ST.length = n;
	cout << "请输入您要建立顺序表的元素：";
	for (int i = 1; i <= n; i++) {
		cin >> ST.elem[i];
	}
}

//顺序查找
int Search_Seq(SSTable ST, keytype key) {
	//在顺序表中查找值为key的数据元素，若找到返回其下标，否则返回0-监视哨
	int i;
	ST.elem[0] = key;//监视哨
	for (i = ST.length; ST.elem[i] != key; i--);
	return i;
}
//折半查找-必须是有序表
int Search_Bin(SSTable ST, keytype key) {
	int low = 1, high = ST.length, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ST.elem[mid] < key)
			low = mid + 1;
		else if (ST.elem[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return 0;
}

int main() {
	SSTable ST;
	int n, input;
	keytype key;
	cout << "**************************************************************" << endl;
	cout << "  1.顺序查找          2.折半查找（有序表）        3.退出程序  " << endl;
	cout << "**************************************************************" << endl;
	while (1) {
		cout << "请输入您要进行的操作：";
		cin >> input;
		switch (input) {
		case 1: {
			cout << "请输入您创建顺序表的长度：";
			cin >> n;
			CreateSSTable(ST, n);
			cout << "请输入您要查找的值：";
			cin >> key;
			cout<<key<<"所在位置为（若为0，则没找到）：" << Search_Seq(ST, key) << endl;
			break;
		}
		case 2: {
			cout << "请输入您创建顺序表（有序表）的长度：";
			cin >> n;
			CreateSSTable(ST, n);
			cout << "请输入您要查找的值：";
			cin >> key;
			cout<<key<<"所在位置为（若为0，则没找到）：" << Search_Bin(ST, key) << endl;
			break;
		}
		case 3: {
			cout << "退出程序" << endl;
			exit(0);
		}
		default: {
			cout << "输入错误，请重新输入" << endl;
			break;
		}
		}
	}
}
